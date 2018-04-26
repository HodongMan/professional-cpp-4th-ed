#include "MilesEstimator.h"

int MilesEstimator::getMilesLeft() const
{
	return getMilesPerGallon() * getGallonsLeft();
}

void MilesEstimator::setGallonsLeft(int gallons)
{
	mGallonsLeft = gallons;
}

int MilesEstimator::getGallonsLeft() const
{
	return mGallonsLeft;
}

int MilesEstimator::getMilesPerGallon() const
{
	return 20;
}
