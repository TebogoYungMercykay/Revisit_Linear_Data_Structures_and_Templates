main:
	g++ -g *.cpp -std=c++98 -pedantic -o main

clean:
	rm -f *.o *.tar.gz main
	reset
	clear

run:
	./main

v_run:
	valgrind --leak-check=full ./main

test:
	g++ --coverage *.cpp -o main
	gcov -f -m -r -j CLinkedList  List  Queue  Stack
	./main
	lcov -c -d . -o coverage.info
	genhtml coverage.info -o coverage_report

tar:
	tar -cvz skeleton_code.cpp makefile -f SkeletonCode.tar.gz

untar:
	tar -zxvf *.tar.gz