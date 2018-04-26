#include <iostream>
#include <memory>
#include "BingCherry.h"
#include "BingCherryTree.h"

int main()
{
	BingCherryTree theTree;
	std::unique_ptr<Cherry> theCherry(theTree.pick());
	theCherry->printType();

	return 0;
}

