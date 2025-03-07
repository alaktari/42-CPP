#include <iostream>
#include <deque>
#include <list>
#include <sstream>
#include <climits>

void	getPairsAndSort(std::deque<unsigned int>& container, std::pair<unsigned int, unsigned int>* myPairs, unsigned int pairNum)
{
	for (unsigned int i = 0, x = 0; i < pairNum; i++, x++) {
		myPairs[i].first = container[x++];
		myPairs[i].second = container[x];
		if (myPairs[i].first > myPairs[i].second)
			std::swap(myPairs[i].first, myPairs[i].second);
	}
}

void    mergeInsertAlgo(std::deque<unsigned int>& container)
{
	std::deque<unsigned int>    losers;
	std::deque<unsigned int>    winers;
	unsigned int				cSize = container.size();
	unsigned int				pairNum = cSize / 2;
	std::pair<unsigned int, unsigned int>	myPairs[pairNum];
	unsigned int							oddElement;


	getPairsAndSort(container, myPairs, pairNum);
	if (cSize % 2)
		oddElement = container[cSize - 1];


	for (int i = 0; i < pairNum; i++) {
		std::cout << "pair[" << i << "] ==> first: " << myPairs[i].first << " || second: " << myPairs[i].second << "\n";
	}
}

int main()
{
	std::deque<unsigned int> container1 = {1, 8, 0, 9, 5, 2};
	std::list<unsigned int> container2;

	mergeInsertAlgo(container1);




}