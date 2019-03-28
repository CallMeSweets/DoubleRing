#ifndef MERGEMETHOD_H
#define MERGEMETHOD_H

#include "DoublyRing.h"

template<typename Key, typename Info>
Ring<Key, Info> merge(const Ring<Key, Info> &r1, const Ring<Key, Info> &r2){
    Ring<Key, Info> returnRing(r1);

    typename Ring<Key, Info>::Iterator iterR2 = r2.begin();

    do{
       returnRing.push(iterR2.showKey(), iterR2.showInfo());
       iterR2++;
    }while(iterR2 != r2.begin());

    return returnRing;
}

#endif // MERGEMETHOD_H
