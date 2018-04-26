#pragma once

#include <cstddef>

class Serial
{
public:
	Serial();
	size_t getSerialNumber() const;

private:
	static size_t sNextSerial;
	size_t mSerialNumber;
};

