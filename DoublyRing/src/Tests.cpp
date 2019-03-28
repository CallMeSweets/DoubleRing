#include "Tests.h"

#include "produce.h"

using namespace std;

void tests::constructors_test(){
    Ring<int, int> testedRing;
    if(!testedRing.isEmpty())
        tests::errorInformation.addError("isEmpty() error constructor test");

    if(testedRing.size())
        tests::errorInformation.addError("size() error constructor test");

}

void tests::showReport(ostream &os){
    tests::errorInformation.showReport(os);
}

void tests::push_test(){
        Ring<int, int> testedRing;

        testedRing.push(3, 100);
        testedRing.push(4, 200);
        testedRing.push(5, 300);

        if(testedRing.isEmpty()){
            tests::errorInformation.addError("incorrect adding elements, list is Empty, push method");
        }

        if(testedRing.size() != 3){
            tests::errorInformation.addError("incorrect adding elements, wrong size, push method");
        }

        testedRing.push(2, 200);
        testedRing.push(1, 300);

        if(testedRing.size() != 5){
            tests::errorInformation.addError("incorrect adding elements, wrong size, push method");
        }

        stringstream os;
        stringstream osOutPut("3 100\n4 200\n5 300\n2 200\n1 300\n");
        os << testedRing;
        if(osOutPut.str() != os.str()){
           tests::errorInformation.addError("incorrect operator << ");
        }

}

void tests::clear_test(){

    Ring<int, int> testedRing;

        testedRing.push(1, 100);
        testedRing.push(2, 200);
        testedRing.push(3, 300);
        testedRing.push(4, 400);
        testedRing.push(5, 500);

        testedRing.clear();

        if(testedRing.size() != 0){
            tests::errorInformation.addError("incorrect clearing lists, clear method");
        }

        stringstream os;
        os << testedRing;
        string outPut = os.str();
        if(outPut != ""){
            tests::errorInformation.addError("incorrect clearing lists, clear method operator <<");
        }

}

void tests::contain_test(){

    Ring<int, int> testedRing;
        testedRing.push(1, 100);
        testedRing.push(2, 200);
        testedRing.push(2, 300);
        testedRing.push(3, 300);
        testedRing.push(3, 400);
        testedRing.push(3, 500);

        int numOfElements = 0;
        numOfElements = testedRing.contain(1);
        if(numOfElements != 1){
            tests::errorInformation.addError("test 1, contain method");  // test 1
        }

        numOfElements = 0;
        numOfElements = testedRing.contain(2);
        if(numOfElements != 2){
            tests::errorInformation.addError("test 2, contain method");  // test 1
        }

        numOfElements = 0;
        numOfElements = testedRing.contain(3);
        if(numOfElements != 3){
            tests::errorInformation.addError("test 3, contain method");  // test 1
        }

        numOfElements = 0;
        numOfElements = testedRing.contain(4);
        if(numOfElements != 0){
            tests::errorInformation.addError("test 4, contain method");  // test 1
        }

}

void tests::isEmpty_test(){

     Ring<int, int> testedRing;
        testedRing.push(1, 100);
        testedRing.push(2, 200);
        testedRing.push(2, 300);
        testedRing.push(3, 300);
        testedRing.push(3, 400);
        testedRing.push(3, 500);

    if(testedRing.isEmpty() == true){
       tests::errorInformation.addError("test 1, isEmpty method");  // test 1
    }

    testedRing.clear();

    if(testedRing.isEmpty() != true){
       tests::errorInformation.addError("test 2, isEmpty method");  // test 2
    }

}

void tests::size_test(){

    Ring<int, int> testedRing;
        testedRing.push(1, 100);
        testedRing.push(2, 200);
        testedRing.push(3, 300);
        testedRing.push(4, 400);
        testedRing.push(5, 500);


    if(testedRing.size() != 5){
       tests::errorInformation.addError("test 1, size method");  // test 1
    }

    testedRing.push(6, 600);
    if(testedRing.size() != 6){
       tests::errorInformation.addError("test 2, size method");  // test 2
    }

    testedRing.remove(6);
    testedRing.remove(5);
    testedRing.remove(4);
    if(testedRing.size() != 3){
       tests::errorInformation.addError("test 3, size method");  // test 3
    }


}

void tests::remove_test(){
    Ring<int, int> testedRing;
        testedRing.push(1, 100);
        testedRing.push(2, 200);
        testedRing.push(2, 300);
        testedRing.push(2, 400);
        testedRing.push(3, 300);
        testedRing.push(4, 400);
        testedRing.push(5, 500);


        testedRing.remove(2);
        if(testedRing.size() != 6){
            tests::errorInformation.addError("test 1, remove method, removing element with index < 1");  // test 1
        }

        if(testedRing.contain(2) != 2){
            tests::errorInformation.addError("test 2, remove method, number of containing elements with specific key");  // test 2
        }

        stringstream os2;
        stringstream osOutPut2("1 100\n2 300\n2 400\n3 300\n4 400\n5 500\n");
        os2 << testedRing;
        if(osOutPut2.str() != os2.str()){
           tests::errorInformation.addError("incorrect popFront method");
        }

        // check outPut

}

void tests::produce_test(){
    Ring<int,int> *ring1 = new Ring<int, int>();
    Ring<int,int> *ring2 = new Ring<int, int>();

    ring1->push(1, 100);
    ring1->push(2, 200);
    ring1->push(3, 300);
    ring1->push(4, 400);
    ring1->push(5, 500);
    ring1->push(6, 600);
    ring1->push(7, 700);
    ring1->push(8, 800);
    ring1->push(9, 900);


    ring2->push(9, 900);
    ring2->push(8, 800);
    ring2->push(7, 700);
    ring2->push(6, 600);
    ring2->push(5, 500);
    ring2->push(4, 400);
    ring2->push(3, 300);
    ring2->push(2, 200);
    ring2->push(1, 100);


    Ring<int,int> *ring3 = new Ring<int, int>();
    *ring3 = Produce(*ring1, 0, 0, true,
                     *ring2, 0, 0, true, 2);



    if(ring3->size() != 0){
        tests::errorInformation.addError("test 1, produce function, start = 0, length = 0, true, true");  // test 1
    }
    delete ring3;

    *ring3 = Produce(*ring1, 1, 0, true,
                     *ring2, 1, 0, true, 2);

    if(ring3->size() != 0){
        tests::errorInformation.addError("test 2, produce function, start != 0, length = 0, true, true");  // test 2
    }
    delete ring3;

    *ring3 = Produce(*ring1, 0, 1, true,
                     *ring2, 0, 1, true, 2);

    stringstream os;
    stringstream osOutPut("1 100\n9 900\n2 200\n8 800\n");
    os << *ring3;
    if(osOutPut.str() != os.str()){
       tests::errorInformation.addError("test 3, produce function, start == 0, length != 0, true, true"); // test 3
    }
    delete ring3;

    *ring3 = Produce(*ring1, 0, 1, true,
                     *ring2, 0, 1, false, 2);

    stringstream os2;
    stringstream osOutPut2("1 100\n9 900\n2 200\n1 100\n");
    os2 << *ring3;
    if(osOutPut2.str() != os2.str()){
       tests::errorInformation.addError("test 4, produce function, start == 0, length != 0, true, false"); // test 4
    }
    delete ring3;

     *ring3 = Produce(*ring1, 0, 1, false,
                     *ring2, 0, 1, false, 2);

    stringstream os3;
    stringstream osOutPut3("1 100\n9 900\n9 900\n1 100\n");
    os3 << *ring3;
    if(osOutPut3.str() != os3.str()){
       tests::errorInformation.addError("test 5, produce function, start == 0, length != 0, false, false"); // test 5
    }
    delete ring3;

    *ring3 = Produce(*ring1, 0, 1, false,
                     *ring2, 0, 1, true, 2);

    stringstream os4;
    stringstream osOutPut4("1 100\n9 900\n9 900\n8 800\n");
    os4 << *ring3;
    if(osOutPut4.str() != os4.str()){
       tests::errorInformation.addError("test 6, produce function, start == 0, length != 0, false, true"); // test 6
    }
    delete ring3;

     *ring3 = Produce(*ring1, 3, 2, false,
                     *ring2, 4, 3, true, 3);

    stringstream os5;
    stringstream osOutPut5("4 400\n3 300\n5 500\n4 400\n3 300\n2 200\n1 100\n2 200\n1 100\n9 900\n9 900\n8 800\n8 800\n7 700\n6 600\n");
    os5 << *ring3;
    if(osOutPut5.str() != os5.str()){
       tests::errorInformation.addError("test 7, produce function, start != 0, length != 0, false, true"); // test 7
    }
    delete ring3;




}
