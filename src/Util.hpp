#ifndef _UTIL_HPP_
#define _UTIL_HPP_

#include <random>

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<short> dis(0, 1);


void generateRandomGen(std::vector<bool> &gen, std::size_t length)
{
	for (std::size_t i = 0; i < length; ++i)
	{
		gen.push_back(dis(mt));
	}
}

#endif