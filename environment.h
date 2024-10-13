#pragma once
#include <vector>
#include <string>

class Environment {
	public:
		std::string outter_shape;
		std::vector<std::string> environment;
		int x_length;
		int y_length;
		
	public:
		Environment(int x_length, int y_length, std::string outter_shape);
		void display_environment();

	private:
		int resolution;
};