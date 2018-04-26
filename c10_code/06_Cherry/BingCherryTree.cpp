#include "BingCherryTree.h"
#include <memory>

BingCherry* BingCherryTree::pick()
{
	auto theCherry = std::make_unique<BingCherry>();
	theCherry->polish();
	return theCherry.release();
}
