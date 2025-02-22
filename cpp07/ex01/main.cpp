#include "iter.hpp"

template <typename anyType>
void printElem(anyType& elem)
{
	std::cout << elem << " ";
}

void doubleElem(int& elem)
{
	if (elem < (INT_MAX / 2) && elem > (INT_MIN / 2))
		elem *= 2;
}

void	toUpElem(char& elem)
{
	elem = toupper(elem);
}
	
int main()
{
	{
		int arr[5] = {5, -5, 8, 22, 0};

		::iter(arr, 5, doubleElem);
		::iter(arr, 5, printElem);
	}
	std::cout << "\n=========================\n";
	{
		std::string str = "abCd123";

		::iter((char*)(str.c_str()), str.length(), toUpElem);
		::iter(str.c_str(), str.length(), printElem);
	}
}