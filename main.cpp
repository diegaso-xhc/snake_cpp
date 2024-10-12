#include <iostream>
#include "environment.h"

int main() {


	int x = 5;
	char* chars = new char[10];
	chars[2] = 5;
	int* ptr = &x;
	int** ptrptr = &ptr;
	float x1 = 0.00014444;
	std::cout << x1 << std::endl;
	std::cout << std::scientific << x1 << std::endl;


	std::cout << "RUNNING PROGRAM" << std::endl;
	Environment square_1(20, 140, "square");
	square_1.display_environment();

	std::cin.get();


	return 0;
}