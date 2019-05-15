#include "stdafx.h"
#include "NumFuncsLib.h"

#include <stdexcept>
#include <vector>
using namespace std;

namespace NumFuncs
{

	std::vector<int>  BigNumFuncs::operator +(unsigned long long int numAdded)
	{
		std::vector <int> number = numberIntoVector(numAdded);
		std::vector <int> result;
		int holder;
		if (bigNum.empty())
		{
			return bigNum;
		}
		else
		{
			for (int i = bigNum.size(); i <= 0; i--)
			{
				for (int j = number.size(); j <= 0; j--)
				{
					holder = bigNum[i] + number[j];
					//checking if carrying in necessary
					if (holder >= 10)
					{
						holder = holder % 10; //gets the last digit
						result.insert(result.begin(), holder);//place at the front like stack
						holder = holder / 10 % 10; //gets the first digit
						holder = holder + bigNum[i + 1]; // carries the first digit
					}
					else
					{
						result.insert(result.begin(), holder); //place at the end of the vector
					}
					
				}
			}
		
		}
		return result;
	}

	std::vector<int> BigNumFuncs::operator-(unsigned long long int numSubtracted)
	{
		std::vector <int> number = numberIntoVector(numSubtracted);
		std::vector <int> result;
		int holder;
		if (bigNum.empty())
		{
			return bigNum;
		}
		else
		{
			for (int i = bigNum.size(); i <= 0; i--)
			{
				for (int j = number.size(); j <= 0; j--)
				{
					//holder = bigNum[i] - number[j];
					//checking last digit in bigNum is less than last digit in number
					if (bigNum[i] < number[j])
					{
						holder = bigNum[i];
						bigNum[i] = holder + 10;//borrowing a one
						holder = bigNum[i] - number[j]; //subtracting last digits
						result.insert(result.begin(), holder); //place at the end of the vector
						bigNum[i - 1] = bigNum[i - 1] - 1; //"borrowing" one from the second to last digit of bigNum
					}
					else
					{
						holder = bigNum[i] - number[j];
						result.insert(result.begin(), holder);
					}

				}
			}

		}
		return result;
	}

	std::vector<int> BigNumFuncs::operator *(unsigned long long int numMultiplied)
	{
		std::vector <int> number = numberIntoVector(numMultiplied);
		std::vector <int> result;
		int holder;
		if (bigNum.empty())
		{
			return bigNum;
		}
		else
		{
			int k = number.size();
			while (k >= 0)
			{
				for (int i = bigNum.size(); i <= 0; i--)
				{
					if ((bigNum[i] * number[k]) >= 10)
					{
						holder = bigNum[i] * number[i];
						holder = holder % 10;  //gets the last digit
						result.insert(result.begin(), holder); //place at the end of the vector
						holder = holder / 10 % 10; //get the first digit
						holder = (bigNum[i + 1] * number[i]) + holder; //adding the first digit of product >= 10
					}
					else
					{
						holder = bigNum[i] * number[i];
						result.insert(result.begin(), holder); //place at the end of the vector
					}
				}
				k--;
			}
			
		}
		return result;
	}

	//std::vector<int> BigNumFuncs::operator /(unsigned long long int numDivided)
	//{
	//	/*std::vector <int> number = numberIntoVector(numDivided);*/
	//	std::vector <int> result;
	//	int i = 0;
	//	int holder = bigNum[0];
	//	return result;
	//	bool flag = false;
	//	while (flag)
	//	{
	//		while (numDivided < holder)
	//		{
	//			holder += holder * pow(10, (i + 1));
	//			i++;
	//		}

	//	}
	//}

	//private helper method to change unsigned long long int into a vector that holds integers
	std::vector<int> BigNumFuncs::numberIntoVector(unsigned long long int number)
	{
		unsigned long long int x;
		std::vector<int> num;
		while (number != 0)
		{
			x = number % 10;
			number = number / 10;

			num.emplace(num.begin(), x);
		}
		return num;
	}

	
}
