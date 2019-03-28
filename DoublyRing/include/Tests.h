#ifndef TESTS_H
#define TESTS_H

#include <sstream>
#include "DoublyRing.h"
#include "ErrorInformation.h"


using namespace std;

namespace tests
{


        static ErrorInformation errorInformation;

        void constructors_test();  //
        void push_test();  //
        void clear_test();  //
        void remove_test(); //
        void isEmpty_test(); //
        void size_test(); //
        void contain_test(); //
        void produce_test(); //
        void showReport(ostream &os); //
};

#endif // TESTS_H
