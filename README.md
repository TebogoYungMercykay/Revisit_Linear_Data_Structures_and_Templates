Here 

# Data Structures in C++

This repository contains my implementation of some common data structures in C++, such as linked lists, stacks, queues, and templates. The purpose of this project is to practice and demonstrate my skills in object-oriented programming, memory management, and generic programming.

## Usage

To run the project, you can execute the file `main.cpp` in the root directory. This will run some tests and examples of using the data structures implemented in this project.

You can also include the header files in this directory in your own C++ projects to use the data structures. For example, to use the linked list class, you can write:

```cpp
#include <iostream>
#include <sstream>
#include <string>

#include "CLinkedList.h"

using namespace std;

void t1();

int main(){
    std::cout << "Hello Linear Data Structures (*_*)." << std::endl;
    t1();
    return 0;
}

void t1(){
    CLinkedList<int> list;
    cout << "----- Testing ClinkedList -----" << endl;
    list.append(1);
    list.append(2);
    list.prepend(3);
    list.insert(4, 3);
    list.print(); // Output should be "3 -> 1 -> 2 -> 4\n"
    list.remove(0); //remember remove works based of index
    list.remove(0);
    list.remove(100); //test for invalid
    list.remove(1);
    list.removeElements(2);
    list.print(); // Output should be "Empty\n
    list.append(1);
    list.append(1);
    list.print(); // Output should be "1 -> 1\n"
    list.removeElements(1);
    list.print(); // Output should be "Empty\n
}
```

## Makefile

```cpp
main:
	g++ -g *.cpp -std=c++11 -pedantic -o main

clean:
	rm -f *.o *.tar.gz main
	reset
	clear

run:
	./main

valgrind:
	valgrind --leak-check=full ./main

tar:
	tar -cvz skeleton_code.cpp makefile -f SkeletonCode.tar.gz

untar:
	tar -zxvf *.tar.gz
```

## Contributing

If you want to contribute to this project, you are welcome to do so. You can fork this repository, make some changes, and create a pull request. Please make sure to follow the coding style and conventions used in this project.

## License

This project is licensed under the MIT License. See the [LICENSE](^2^) file for more details.
