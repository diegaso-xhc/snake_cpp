#pragma once
#include <vector>
#include <string>

extern constexpr int environment_clearence = 2;

class Environment {
	public:
		std::string outter_shape;
		std::vector<std::string> environment;
		std::vector<std::string> static_environment;
		int x_length;
		int y_length;
		
	public:
		Environment(int x_length, int y_length, std::string outter_shape);
		void display_environment();

	private:
		int resolution;
};