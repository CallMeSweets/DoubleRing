#include <iostream>
#include <exception>

#include "DoublyRing.h"
#include "Tests.h"
#include "produce.h"



using namespace std;

int main()
{



    Ring<int, int> *ring1 = new Ring<int, int>();
    Ring<int, int> *ring2 = new Ring<int, int>();
    Ring<int, int> *ring3 = new Ring<int, int>();


    ring1->push(1, 100);
    ring1->push(2, 200);
    ring1->push(3, 300);
    ring1->push(4, 400);
    ring1->push(5, 500);
    ring1->push(6, 600);

    ring2->push(1, 100);
    ring2->push(2, 200);
    ring2->push(3, 300);
    ring2->push(4, 400);
    ring2->push(5, 500);
    ring2->push(6, 600);
    ring2->push(7, 700);

    *ring3 = Produce(*ring1, 2, 1, false,
                    *ring2, 2, 1, true, 3);

  //  *ring3 += *ring2;
   // *ring3 += *ring1;
    cout << *ring3 << endl;

    tests::constructors_test();
    tests::push_test();
    tests::clear_test();
    tests::contain_test();//
    tests::isEmpty_test();
    tests::size_test();
    tests::remove_test();
    tests::produce_test();
    tests::showReport(cout);

    return 0;
}
