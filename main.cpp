#include <iostream>
#include <chrono>
#include <thread>

#include "environment.h"
#include "console_handle.h"


int main() {

	/*
	int x = 5;
	char* chars = new char[10];
	chars[2] = 5;
	int* ptr = &x;
	int** ptrptr = &ptr;
	float x1 = 0.00014444;
	std::cout << x1 << std::endl;
	std::cout << std::scientific << x1 << std::endl;*/

	std::string s = "**-**";
	std::cout << s[1] << "    " << s[2] << "     " << s[3];

	/*
	for (int y = 10; y < 60; y++) {
		//system("cls");
		//std::cout << "\r";
		//std::cout.flush();
		std::cout << "RUNNING PROGRAM" << std::endl;
		Environment square_1(20, y, "square");
		square_1.display_environment();
		std::this_thread::sleep_for(std::chrono::milliseconds(30));
		clear_console();		
	}*/

	std::cin.get();
	return 0;
}