#pragma once

#include "MilesEstimator.h"

class EfficientCarMilesEstimator : public MilesEstimator
{
private:
	virtual int getMilesPerGallon() const override;
};
