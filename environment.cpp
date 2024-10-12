#include <string>
#include <iostream>
#include "environment.h"

Environment::Environment(int x, int y, std::string out_shape) {

	outter_shape = out_shape;
	x_length = x;
	y_length = y;
	x_coor = new int[x_length];
	y_coor = new int[y_length];
	for (int i = 0; i < x; i++) { x_coor[i] = 0; }
	for (int i = 0; i < y; i++) { y_coor[i] = 0; }
};

void Environment::display_environment() {

	for (int i = 0; i < x_length; i++) {
		for (int j = 0; j < y_length; j++) {
			if (i == 0 || i == x_length - 1 || j == 0 || j == y_length - 1)
				std::cout << "*";
			else
				std::cout << " ";
		}			
		std::cout << "\n";
	}
};