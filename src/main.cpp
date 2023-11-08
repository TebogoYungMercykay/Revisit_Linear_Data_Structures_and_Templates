#include <iostream>
#include <sstream>
#include <string>

#include "Node.h"
#include "List.h"
#include "CLinkedList.h"
#include "CLinkedList.cpp"
#include "List.cpp"
// #include "Stack.h"
// #include "Stack.cpp"
// #include "Queue.h"
// #include "Queue.cpp"

using namespace std;

void t1(){
    cout << "Testing CLinkedList" << endl;
    CLinkedList<int> list;
    cout << "Testing basics" << endl;
    list.append(1);
    list.clear();
    cout << list.get(0) << endl;
    cout << list.length() << endl;
    list.append(1);
    cout << list.get(0) << endl;
    cout << list.length() << endl;
    list.append(2);
    list.print();
    list.clear();
    list.prepend(1);
    cout << list.get(0) << endl;
    cout << list.length() << endl;
    list.prepend(2);
    list.print();

    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    cout << list.get(0) << endl;
    cout << list.get(1) << endl;
    cout << list.get(-1) << endl;
    cout << list.get(6) << endl;
    list.print();
    list.prepend(3);
    list.prepend(8);
    list.prepend(2);
    list.prepend(7);
    list.print();
    // list.insert(4, 3);
    // list.insert(4, 3);
    // list.insert(4, 3);
    // cout << list.length() << endl;
    // list.print();// Output should be "3 -> 1 -> 2 -> 4\n"
    // list.remove(0);//remember remove works based of index
    // list.remove(0);
    // list.remove(100);//test for invalid
    // list.remove(1);
    // list.removeElements(2);
    // list.print();// Output should be "Empty\n
    // list.append(1);
    // list.append(1);
    // list.print();// Output should be "1 -> 1\n"
    // list.removeElements(1);
    // list.print();// Output should be "Empty\n
}

void t2(){
    cout << "Testing CLinkedList" << endl;
    CLinkedList<int> list;
    cout << "Testing rotations" << endl;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.RRotate(2);
    list.print();// Output should be "4 -> 5 -> 1 -> 2 -> 3\n"
    list.LRotate(7);
    list.print();// Output should be "1 -> 2 -> 3 -> 4 -> 5\n"
    cout << "Testing Assignment operator and rotation" << endl;
    CLinkedList<int> list2;
    list2= list;
    list2.print();// Output should be "1 -> 2 -> 3 -> 4 -> 5\n"
    list2.RRotate(2);
    list2.print();// Output should be "4 -> 5 -> 1 -> 2 -> 3\n"
}

// void t3(){
//     cout << "Testing Stack" << endl;
//     Stack<int> stack;
//     cout << "Testing basics" << endl;
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
//     cout << "Testing copy constructor" << endl;
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
// }

// void t4(){
//     cout << "Testing Queue" << endl;
//     Queue<int> queue;
//     cout << "Testing basics" << endl;
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
//     cout << "Testing copy constructor" << endl;
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

// }

int main(){
    t1();
    // t2();
    // t3();
    // t4();
    return 0;
}