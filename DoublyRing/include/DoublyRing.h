#ifndef SEQUENCE_H
#define SEQUENCE_H


#include<iostream>

using namespace std;

template<typename Key, typename Info>
class Ring
{

    private:
        struct Node{
            Node *next;
            Node *prev;
            Info info;
            Key key;
            Node():next(nullptr), prev(nullptr){}
            Node(Key newKey, Info newInfo):next(nullptr), prev(nullptr), info(newInfo), key(newKey){}
            Node(Key newKey,Info newInfo, Node *next, Node *prev): next(next), prev(prev), info(newInfo), key(newKey){}

        };

    protected:

    private:
        Node *any;
        int length;

    public:

        // constructors
        Ring(): any(nullptr), length(0){}
        Ring(const Ring<Key, Info> &ring): any(nullptr), length(0){*this = ring;}  // to short body to create under the class

        // destructor
        ~Ring(){clear();}

        // operators
        bool operator>=(const Ring<Key, Info> & ring) const{if(this->length >= ring.length) return true; return false;}
        bool operator>(const Ring<Key, Info> & ring) const{if(this->length > ring.length) return true; return false;}
        bool operator<(const Ring<Key, Info> & ring) const{if(this->length < ring.length) return true; return false;}
        bool operator<=(const Ring<Key, Info> & ring) const{if(this->length <= ring.length) return true; return false;}
        bool operator==(const Ring<Key, Info> & ring) const noexcept;
        bool operator!=(const Ring<Key, Info>& ring)const noexcept{return !(*this == ring);}  // to short body to create under the class
        Ring<Key, Info> & operator=(const Ring<Key, Info> &ring);
        template<typename Keyy, typename Infoo>
        friend ostream& operator<<(ostream& os, const Ring<Keyy, Infoo>& ring);
        Ring<Key, Info> operator+(const Ring<Key, Info> & ring) const{return merge(*this, ring);}   // to short body to create under the class
        Ring<Key, Info> &operator+=(const Ring<Key, Info> ring){*this = *this + ring;return *this;} // to short body to create under the class

        //capacity
        bool isEmpty() const;
        int size() const;
        int contain(const Key &key);

        //modifiers
        void push(const Key &key, const Info &info);
      //  Ring<Key, Info> merge(const Ring<Key, Info> &ring) const;
        void clear();
        void remove(const Key &key);


        //access
        void getInfoElement(const Key &key);
        void print();

        public:
        class Iterator;

        Iterator begin() const
        {
            Iterator it(any);
            return it;
        }
        const Iterator constBegin() const
        {
            Iterator it(any);
            return it;
        }


};

template<typename Key, typename Info>
class Ring<Key, Info>::Iterator{

private:
    Node *curr;

public:
    Iterator():curr(nullptr){};
    Iterator(Node *node):curr(node){};
    ~Iterator(){};
    Iterator(const Iterator &temp){
        this->curr = temp.curr;
    }

    Iterator & operator=(const Iterator &temp){
    this->curr = temp.curr;
    }

    bool operator==(const Iterator &temp) const{
        if(this->curr == temp.curr)
            return true;

        return false;
    }

    bool operator!=(const Iterator &temp) const{
        return !(*this == temp);
    }

    Iterator operator++(int){
    if(curr) curr = curr->next;
        return *this;
    }

    Iterator operator--(int){
    if(curr) curr = curr->prev;
        return *this;
    }

    Info showInfo() const{
        if(curr)
            return curr->info;

        throw "Empty Iterator showInfo";
        return 0;
    }

    Key showKey() const{
        if(curr)
            return curr->key;

        throw "Empty Iterator showKey";
        return 0;
    }


};
//
//
//operators
template<typename Key, typename Info>
Ring<Key, Info> & Ring<Key, Info>::operator=(const Ring<Key, Info> &ring){
    if(this == &ring)
        return *this;

        clear();
        Node *curr = ring.any;

        if(!curr)
            return *this;

        do{
            this->push(curr->key, curr->info);
            curr = curr->next;
        }while(curr != ring.any);

    return *this;

}

template<typename Key, typename Info>
ostream& operator<<(ostream& os, const Ring<Key, Info>& ring){
    typename Ring<Key, Info>::Node *curr = ring.any;

    if(curr == nullptr)
        return os;

    do{
        os << curr->key << " " << curr->info << "\n";
        curr = curr->next;
    }while(curr != ring.any);

    return os;
}

template<typename Key, typename Info>
bool Ring<Key, Info>::operator==(const Ring<
                                 Key, Info> & ring) const noexcept{
    if(length != ring.length){
        return false;
    }

    Node *anyNew = ring.any;
    Node *anyBasic = any;
    do{
        if(anyBasic->key != anyNew->key || anyBasic->info != anyNew->info){
            return false;
        }
        anyBasic = anyBasic->next;
        anyNew = anyNew->next;
    }while(anyBasic != anyBasic);
    return true;
}

//capacity
template<typename Key, typename Info>
bool Ring<Key, Info>::isEmpty() const{return length == 0;}

template<typename Key, typename Info>
int Ring<Key, Info>::size() const {return length;}

template<typename Key, typename Info>
int Ring<Key, Info>::contain(const Key &key){
    int howMuch = 0;
    Node *curr = any;
    do{
        if(curr->key == key)
            howMuch++;
        curr = curr->next;
    }while(curr != any);

    return howMuch;
}


//modifiers

template<typename Key, typename Info>
void Ring<Key, Info>::push(const Key &key, const Info &info){

        if(isEmpty()){
            any = new Node(key, info);
            any->next = any;
            any->prev = any;
            length++;
            return;
        }

        Node *newElement = new Node(key, info, any, any->prev);
        any->prev->next = newElement;
        any->prev = newElement;
        length++;


}

template<typename Key, typename Info>
void Ring<Key, Info>::remove(const Key &key){

    if(isEmpty())
        return;

    if(size() == 1 && key == any->key){
        delete any;
        any = nullptr;
        length = 0;
        return;
    }

    Node *curr = any;
    do{
        if(curr->key == key){
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            if(curr ==  any)
                any = any->next;
            delete curr;
            length--;
            return;
        }
        curr = curr->next;
    }while(curr != any);
    cout << "any: " << any->key << endl;
    throw "Element not removed!";


}


template<typename Key, typename Info>
void Ring<Key, Info>::clear(){


    if(any == nullptr)
        return;

    Node *curr = any->next;
    while(curr != any){
        Node *curr_del = curr;
        curr = curr->next;
        delete curr_del;
    }
    delete any;

    any = nullptr;
    length = 0;

}

//access

template<typename Key, typename Info>
void Ring<Key, Info>::getInfoElement(const Key &key){

    Node *curr = any;

    do{
        if(curr->key == key){
            cout << curr->info << endl;
        }
    curr = curr->next;
    }while(curr != any);



}

template<typename Key, typename Info>
void Ring<Key, Info>::print(){
    cout << *this;
}

//operations
//template<typename Key, typename Info>
//Ring<Key, Info> Ring<Key, Info>::merge(const Ring<Key, Info> &ring) const {
//    Ring<Key, Info> returnRing(*this);
//
//    Node *curr = ring.any;
//    do{
//        returnRing.push(curr->key, curr->info);
//        curr = curr->next;
//    }while(curr != ring.any);
//    return returnRing;
//}

#include "MergeMethod.h"
#endif // SEQUENCE_H
