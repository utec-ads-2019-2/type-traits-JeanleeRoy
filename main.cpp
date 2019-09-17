#include <iostream>

#include "test/tester.h"

using namespace std;

int main(int argc, char const *argv[]) {
    Tester::execute();
    /*SelfList<int> list(SelfList<int>::Move);
    cout << list.insert(2) << endl;
    list.print();
    cout << list.find(2) << endl;
    cout << list.insert(1) << endl;
    list.print();
    cout << list.insert(3) << endl;
    cout << list.insert(3) << endl;
    list.print();
    cout << list.find(2) << endl;
    cout << list.find(1) << endl;
    cout << list.find(3) << endl;
    list.print();
    cout << list.find(8) << endl;
    cout << list.remove(3) << endl;
    list.print();
    cout << list.insert(4) << endl;
    list.print();
    cout << list.size() << endl;
    */
    return EXIT_SUCCESS;
}

