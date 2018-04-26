#pragma once

#include "CherryTree.h"
#include "BingCherry.h"

class BingCherryTree : public CherryTree
{
public:
	virtual BingCherry* pick() override;
};
