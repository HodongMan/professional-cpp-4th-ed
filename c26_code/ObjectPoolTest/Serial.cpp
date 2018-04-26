#include "stdafx.h"
#include "Serial.h"

size_t Serial::sNextSerial = 0;  // The first serial number is 0.

Serial::Serial()
	: mSerialNumber(sNextSerial++) // A new object gets the next serial number.
{
}

size_t Serial::getSerialNumber() const
{
	return mSerialNumber;
}
