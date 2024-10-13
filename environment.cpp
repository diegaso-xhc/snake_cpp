#include <iostream>
#include "environment.h"

Environment::Environment(int x, int y, std::string out_shape) {

	outter_shape = out_shape;
	x_length = x;
	y_length = y;
	std::string tmp_string;
	for (int i = 0; i < x_length; i++) {
		tmp_string = "";
		for (int j = 0; j < y_length; j++) {
			if (i == 0 || i == x_length - 1 || j == 0 || j == y_length - 1)
				tmp_string = tmp_string + "*";
			else
				tmp_string = tmp_string + " ";
		}
		environment.push_back(tmp_string);
	}
	static_environment = environment;

};

void Environment::display_environment() {

	std::cout << "\r";
	for (int i = 0; i < x_length; i++) {
		std::cout << environment[i] << std::endl;
	}
};
