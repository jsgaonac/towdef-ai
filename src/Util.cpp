#include "Util.hpp"

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<int> dis(1, 10);

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

int getRandomInteger(int low, int high)
{
	std::uniform_int_distribution<int> unDis(low, high);

	return unDis(mt);
}

double getRandomReal(double low, double high)
{
	std::uniform_real_distribution<double> unRDis(low, high);

	return unRDis(mt);
}