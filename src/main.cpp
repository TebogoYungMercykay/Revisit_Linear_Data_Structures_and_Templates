#include <iostream>
#include <sstream>
#include <string>

#include "Node.h"
#include "List.h"
#include "CLinkedList.h"
#include "CLinkedList.cpp"
#include "List.cpp"
#include "Stack.h"
#include "Stack.cpp"
#include "Queue.h"
#include "Queue.cpp"

using namespace std;

void t1();
// void t2();
// void t3();
// void t4();
// void t5();
// void t6();

int main(){
    t1();
    // t2();
    // t3();
    // t4();
    // t5();
    // t6();
    return 0;
}

void t1(){
    CLinkedList<int> list;
    cout << "-------------------------------" << endl;
    cout << "----- Testing ClinkedList -----" << endl;
    list.append(1);
    list.append(2);
    list.prepend(3);
    list.insert(4, 3);
    list.print();// Output should be "3 -> 1 -> 2 -> 4\n"
    list.remove(0);//remember remove works based of index
    list.remove(0);
    list.remove(100);//test for invalid
    list.remove(1);
    list.removeElements(2);
    list.print();// Output should be "Empty\n
    list.append(1);
    list.append(1);
    list.print();// Output should be "1 -> 1\n"
    list.removeElements(1);
    list.print();// Output should be "Empty\n
}

// void t2(){
//     CLinkedList<int> list;
//     cout << "----- Testing rotations -----" << endl;
//     list.append(1);
//     list.append(2);
//     list.append(3);
//     list.append(4);
//     list.append(5);
//     list.RRotate(2);
//     list.print();// Output should be "4 -> 5 -> 1 -> 2 -> 3\n"
//     list.LRotate(7);
//     list.print();// Output should be "1 -> 2 -> 3 -> 4 -> 5\n"
//     cout << "----- Testing Assignment operator and rotation -----" << endl;
//     CLinkedList<int> list2;
//     list2= list;
//     list2.print();// Output should be "1 -> 2 -> 3 -> 4 -> 5\n"
//     list2.RRotate(2);
//     list2.print();// Output should be "4 -> 5 -> 1 -> 2 -> 3\n"
// }

// void t3(){
//     CLinkedList<int> list;
//     cout << "----- Append, Prepend and Print -----" << endl;
//     list.append(1);
//     list.clear();
//     cout << list.get(0) << endl;
//     cout << list.length() << endl;
//     list.append(1);
//     cout << list.get(0) << endl;
//     cout << list.length() << endl;
//     list.append(2);
//     list.print();
//     list.remove(list.length() - 1);
//     list.print();
//     list.remove(list.length() - 1);
//     list.print();
//     list.remove(list.length() - 1);
//     list.print();
//     list.clear();
//     list.prepend(1);
//     cout << list.get(0) << endl;
//     cout << list.length() << endl;
//     list.prepend(2);
//     list.print();

//     list.append(2);
//     list.append(3);
//     list.append(4);
//     list.append(5);
//     cout << list.get(0) << endl;
//     cout << list.get(1) << endl;
//     cout << list.get(-1) << endl;
//     cout << list.get(6) << endl;
//     list.print();
//     list.prepend(3);
//     list.prepend(8);
//     list.prepend(2);
//     list.prepend(7);
//     list.print();

//     cout << "----- Removing -----" << endl;
//     list.remove(0);
//     list.print();
//     list.remove(0);
//     list.print();
//     list.remove(4);
//     list.print();
//     list.remove(0);
//     list.print();
//     list.remove(100);
//     list.print();
//     list.remove(1);
//     list.print();
//     cout << "----- Start -----" << endl;
//     list.print();
//     list.remove(list.length() - 1);
//     list.print();
//     cout << list.length() << endl;
//     list.remove(2);
//     list.print();
//     cout << list.length() << endl;
//     list.remove(1);
//     list.print();
//     cout << list.length() << endl;
//     list.remove(list.length() - 1);
//     list.print();
//     cout << list.length() << endl;
//     list.remove(list.length() - 1);
//     list.print();
//     cout << list.length() << endl;
//     list.remove(list.length() - 1);
//     list.print();
//     cout << list.length() << endl;
//     list.remove(list.length() - 1);
//     list.print();
//     cout << list.length() << endl;

//     cout << "----- Inserting -----" << endl;
//     list.insert(3, 0);
//     list.print();
//     cout << list.length() << endl;
//     list.insert(4, list.length() - 1);
//     list.print();
//     cout << list.length() << endl;
//     list.insert(6, list.length());
//     list.print();
//     cout << list.length() << endl;
//     list.insert(2, 1);
//     list.print();
//     cout << list.length() << endl;
//     list.insert(5, 1);
//     list.print();
//     cout << list.length() << endl;
//     list.insert(8, 2);
//     list.print();
//     cout << list.length() << endl;
//     list.insert(9, list.length() - 2);
//     list.print();
//     cout << list.length() << endl;
//     list.insert(2, 1);
//     list.print();
//     cout << list.length() << endl;
//     list.insert(5, 1);
//     list.print();
//     cout << list.length() << endl;
//     list.insert(8, 2);
//     list.print();
//     cout << list.length() << endl;
//     list.insert(9, list.length() - 2);
//     list.print();
//     cout << list.length() << endl;

//     cout << "----- Remove Elements -----" << endl;
//     list.removeElements(9);
//     list.print();
//     cout << list.length() << endl;
//     list.removeElements(8);
//     list.print();
//     cout << list.length() << endl;
//     list.removeElements(4);
//     list.print();
//     cout << list.length() << endl;
//     list.removeElements(5);
//     list.print();
//     cout << list.length() << endl;
//     list.removeElements(2);
//     list.print();
//     cout << list.length() << endl;
//     list.removeElements(6);
//     list.print();
//     cout << list.length() << endl;
//     list.removeElements(3);
//     list.print();
//     cout << list.length() << endl;
//     list.removeElements(6);
//     list.print();
//     cout << list.length() << endl;

//     cout << "----- reverse -----" << endl;
//     list.append(5);
//     // list.reverse();
//     // list.print();
//     list.append(4);
//     // list.reverse();
//     // list.print();
//     list.append(3);
//     list.append(2);
//     list.append(1);
//     list.append(0);
//     // list.reverse();
//     // list.print();
//     list.append(-1);
//     list.append(-2);
//     list.append(-3);
//     list.append(-4);
//     list.append(-5);
//     list.reverse();
//     list.print();

//     cout << "----- Subscript -----" << endl;
//     cout << list[0] << endl;
//     cout << list[1] << endl;
//     cout << list[list.length() - 1] << endl;
//     cout << list[list.length()] << endl;

//     cout << "----- filter -----" << endl;
//     list.filter(">", -4);
//     list.print();
//     list.filter(">", -3);
//     list.print();
//     list.filter(">", -1);
//     list.print();
//     list.filter(">=", 1);
//     list.print();
//     list.filter("<=", 4);
//     list.print();
//     list.filter("!=", 3);
//     list.print();
//     list.filter("==", 1);
//     list.print();
//     list.filter("==", 2);
//     list.print();
//     cout << "----- slice -----" << endl;
//     list.append(1);
//     list.append(6);
//     list.append(3);
//     list.append(4);
//     list.append(23);
//     list.append(2);
//     list.append(6);
//     list.append(3);
//     list.append(0);
//     list.append(51);
//     list.append(9);
//     // list.slice(1, 6);
//     list.print();
//     list.slice(2, 5);
//     list.print();
//     list.slice(0, 1);
//     list.print();
//     list.slice(2, 2);
//     list.print();
//     list.slice(1, 1);
//     list.print();
//     list.clear();
//     cout << "----- swap -----" << endl;
//     list.append(1);
//     list.append(6);
//     list.append(3);
//     list.append(4);
//     list.append(23);
//     list.print();
//     list.swap(0, 1);
//     list.print();
//     list.swap(1, 2);
//     list.print();
//     list.swap(0, 1);
//     list.print();
//     list.swap(0, 3);
//     list.print();
//     list.swap(0, 4);
//     list.print();
//     list.swap(-1, 4);
//     list.print();
//     list.swap(0, 6);
//     list.print();
// }

// void t4(){
//     CLinkedList<int> list;
//     cout << "----- Testing rotations -----" << endl;
//     list.append(1);
//     list.append(2);
//     list.append(3);
//     list.append(4);
//     list.append(5);
//     list.append(6);
//     list.append(7);
//     list.append(8);
//     list.append(9);
//     list.append(10);
//     list.append(11);
//     cout << "----- RRotate -----" << endl;
//     list.print();
//     list.RRotate(1);
//     list.print();
//     list.RRotate(1);
//     list.print();
//     list.RRotate(1);
//     list.print();
//     cout << "----- LRotate -----" << endl;
//     list.print();
//     list.LRotate(1);
//     list.print();
//     list.LRotate(1);
//     list.print();
//     list.LRotate(1);
//     list.print();
//     list.LRotate(1);
//     list.print();
//     list.LRotate(1);
//     list.print();
//     list.LRotate(1);
//     list.print();

//     cout << "----- Assignment Operator -----" << endl;
//     CLinkedList<int> list2;
//     list2 = list;
//     list.print();
//     list.clear();
//     list2.print();
//     list2.clear();
//     cout << "----- Equals Operator -----" << endl;
//     list2.append(1);
//     list2.append(2);
//     list2.append(2);
//     list.append(1);
//     list.append(1);
//     list.append(2);

//     cout << ((list == list2) ? "True" : "False") << endl;
//     list.clear();
//     list.append(1);
//     list.append(2);
//     list.append(2);
//     cout << ((list == list2) ? "True" : "False") << endl;

//     CLinkedList<int> list3;
//     CLinkedList<int> list4;
//     list3.append(3);
//     list3.append(4);
//     list3.append(5);
//     list4.append(5);
//     list4.append(3);
//     list4.append(4);
//     cout << ((list3 == list4) ? "True" : "False") << endl;

//     CLinkedList<int> list5;
//     CLinkedList<int> list6;
//     list5.append(6);
//     list5.append(7);
//     list5.append(8);
//     list6.append(8);
//     list6.append(6);
//     list6.append(7);
//     cout << ((list5 == list6) ? "True" : "False") << endl;

//     CLinkedList<int> list7;
//     CLinkedList<int> list8;
//     list7.append(9);
//     list7.append(10);
//     list7.append(11);
//     list8.append(11);
//     list8.append(9);
//     list8.append(10);
//     cout << ((list7 == list8) ? "True" : "False") << endl;

//     CLinkedList<int> list9;
//     CLinkedList<int> list10;
//     cout << ((list9 == list10) ? "True" : "False") << endl;
//     list9.append(9);
//     list9.append(1);
//     list9.append(1);
//     list9.append(1);
//     list10.append(1);
//     list10.append(9);
//     list10.append(1);
//     cout << ((list9 == list10) ? "True" : "False") << endl;
//     cout << ((list10 == list10) ? "True" : "False") << endl;

//     cout << "----- Plus-Equals Operator -----" << endl;
//     list9.print();
//     list8.print();
//     list7 = list9;
//     list7.print();
//     list9 += list8;
//     list9.print();
//     list8.print();
//     list7.print();
//     list7.clear();
//     list7.append(1);
//     list7.append(4);
//     list7.append(2);
//     list7.append(4);
//     list7.append(3);
//     list7.append(5);
//     list7.append(90);
//     list7.append(12);

//     list8.clear();
//     list8.append(12);
//     list8.append(4);
//     cout << "----- Minus-Equals Operator -----" << endl;
//     list9.clear();
//     CLinkedList<int>* myList = (list7 - list8);
//     list8.print();
//     list7.print();
//     myList->print();
//     delete myList;
//     myList = NULL;
//     myList = (list8 - list8);
//     myList->print();
//     delete myList;
//     myList = NULL;
//     cout << "----- Consume -----" << endl;
//     list8.print();
//     list7.print();
//     list8.consume(list7);
//     list8.print();
//     list7.print();
// }

// void t5(){
//     cout << "-------------------------" << endl;
//     cout << "----- Testing Stack -----" << endl;
//     Stack<int> stack;
//     stack.push(1);
//     stack.push(2);
//     stack.push(3);
//     stack.push(4);
//     cout << stack.pop() << endl;// Output should be "4\n"
//     cout << stack.peek() << endl;// Output should be "3\n"
//     cout << stack.pop() << endl;// Output should be "3\n"
//     cout << stack.pop() << endl;// Output should be "2\n"
//     cout << stack.pop() << endl;// Output should be "1\n"
//     cout << stack.pop() << endl;// Output should be "0\n" since we are returning the default val
//     stack.push(1);
//     stack.push(2);
//     stack.push(3);
//     cout << "----- Testing copy constructor -----" << endl;
//     Stack<int> stack2(stack);
//     cout << stack2.pop() << endl;// Output should be "3\n"
//     cout << stack2.pop() << endl;// Output should be "2\n"
//     cout << stack2.pop() << endl;// Output should be "1\n"
//     cout << stack2.pop() << endl;// Output should be "0\n" since we are returning the default val
//     cout << stack.pop() << endl;// Output should be "3\n"
//     cout << stack.pop() << endl;// Output should be "2\n"
//     cout << stack.pop() << endl;// Output should be "1\n"
//     cout << stack.pop() << endl;// Output should be "0\n" since we are returning the default val
//     //loading up items to test destructor
//     stack.push(1);
//     stack.push(2);
//     stack.push(3);
//     cout << stack.peek() << endl;// Output should be "3\n"

//     cout << ((stack.isEmpty() == false) ? "True" : "False") << endl;
//     cout << ((stack2.isEmpty() == false) ? "True" : "False") << endl;
// }

// void t6(){
//     cout << "-------------------------" << endl;
//     cout << "----- Testing Queue -----" << endl;
//     Queue<int> queue;
//     queue.enqueue(1);
//     queue.enqueue(2);
//     queue.enqueue(3);
//     queue.enqueue(4);
//     cout << queue.dequeue() << endl;// Output should be "1\n"
//     cout << queue.peek() << endl;// Output should be "2\n"
//     cout << queue.dequeue() << endl;// Output should be "2\n"
//     cout << queue.dequeue() << endl;// Output should be "3\n"
//     cout << queue.dequeue() << endl;// Output should be "4\n"
//     cout << queue.dequeue() << endl;// Output should be "0\n" since we are returning the default val
//     queue.enqueue(1);
//     queue.enqueue(2);
//     queue.enqueue(3);
//     cout << "----- Testing copy constructor -----" << endl;
//     Queue<int> queue2(queue);
//     cout << queue2.dequeue() << endl;// Output should be "1\n"
//     cout << queue2.dequeue() << endl;// Output should be "2\n"
//     cout << queue2.dequeue() << endl;// Output should be "3\n"
//     cout << queue2.dequeue() << endl;// Output should be "0\n" since we are returning the default val
//     cout << queue.dequeue() << endl;// Output should be "1\n"
//     cout << queue.dequeue() << endl;// Output should be "2\n"
//     cout << queue.dequeue() << endl;// Output should be "3\n"
//     cout << queue.dequeue() << endl;// Output should be "0\n" since we are returning the default val
//     //loading up items to test destructor
//     queue.enqueue(1);
//     queue.enqueue(2);
//     queue.enqueue(3);

//     cout << queue.peek() << endl;// Output should be "1\n"

//     cout << ((queue.isEmpty() == false) ? "True" : "False") << endl;
//     cout << ((queue2.isEmpty() == false) ? "True" : "False") << endl;
// }
