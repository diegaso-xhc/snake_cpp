#pragma once
#include <vector>

class Assorted {
	public:
		static bool find_vector_in_vector(std::vector<int> x, std::vector<std::vector<int>> y);
		static std::vector<int> random(int min_x, int max_x, int min_y, int max_y);
};