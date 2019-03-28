#ifndef PRODUCE_H
#define PRODUCE_H

#include "DoublyRing.h"

template<typename Key, typename Info>
Ring<Key, Info> Produce(const Ring<Key, Info> &r1, int start1,
                        int len1, bool dir1,
                        const Ring<Key, Info> &r2, int start2,
                        int len2, bool dir2,
                        int repeat){


    Ring<Key, Info> *returnRing = new Ring<Key, Info>();
    typename Ring<Key, Info>::Iterator iterR1 = r1.begin();
    typename Ring<Key, Info>::Iterator iterR2 = r2.begin();
    int howMuchR1 = start1;
    int howMuchR2 = start2;
    int lenR1 = len1;
    int lenR2 = len2;

    while(repeat > 0){
    // setting iterR1
        if(start1 != 0){
           if(start1 < 0){
                while(howMuchR1 != 0){
                    iterR1--;
                    howMuchR1++;
                }
            }else{
                while(howMuchR1 != 0){
                    iterR1++;
                    howMuchR1--;
                }
            }
        }
    // end setting iterR1

    // setting iterR2
        if(start2 != 0){
           if(start2 < 0){
                while(howMuchR2 != 0){
                    iterR2--;
                    howMuchR2++;
                }
            }else{
                while(howMuchR2 != 0){
                    iterR2++;
                    howMuchR2--;
                }
            }
        }
    // end setting iterR2

    // adding Node from R1
        if(dir1){
            while(lenR1 > 0){
                returnRing->push(iterR1.showKey(), iterR1.showInfo());
                lenR1--;
                iterR1++;
            }
        }else{
            while(lenR1 > 0){
                returnRing->push(iterR1.showKey(), iterR1.showInfo());
                lenR1--;
                iterR1--;
            }
        }

    // end adding Node from R1

    // adding Node from R2
        if(dir2){
            while(lenR2 > 0){
                returnRing->push(iterR2.showKey(), iterR2.showInfo());
                lenR2--;
                iterR2++;
            }
        }else{
            while(lenR2 > 0){
                returnRing->push(iterR2.showKey(), iterR2.showInfo());
                lenR2--;
                iterR2--;
            }
        }
    // end adding Node from R2
        lenR1 = len1;
        lenR2 = len2;
        repeat--;
    }

    return *returnRing;



}




#endif // PRODUCE_H
