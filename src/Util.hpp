#ifndef _UTIL_HPP_
#define _UTIL_HPP_

#include <random>

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<short> dis(0, 9);


void generateRandomCrom(std::vector<bool> &crom, std::size_t length)
{
	for (std::size_t i = 0; i < length; ++i)
	{
		int j = dis(mt);

		if( j <= 7)
		{
			crom.push_back(0);
		}
		else
		{
			crom.push_back(1);
		}
	}
}

#endif