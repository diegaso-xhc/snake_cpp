#pragma once

class Environment {
	public:
		std::string outter_shape;
		int x_length;
		int y_length;
	
	public:
		Environment(int x_length, int y_length, std::string outter_shape);
		void display_environment();

	private:
		int resolution;
		int* x_coor;
		int* y_coor;
};