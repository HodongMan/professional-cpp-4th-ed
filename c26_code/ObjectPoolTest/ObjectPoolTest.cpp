#include "stdafx.h"
#include "ObjectPoolTest.h"
#include <stdexcept>
#include "ObjectPool.h" 
#include "Serial.h"
#include <cstddef>
#include <vector>
#include <set>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void ObjectPoolTest::setUp() { }
void ObjectPoolTest::tearDown() { }

void ObjectPoolTest::testSimple()
{
	Assert::IsTrue(0 < 1);
}

void ObjectPoolTest::testException()
{
	Assert::ExpectException<std::invalid_argument>(
		[]{throw std::invalid_argument("Error"); },
		L"Unknown exception caught.");
}

void ObjectPoolTest::testCreation()
{
	ObjectPool<Serial> myPool;
}

void ObjectPoolTest::testAcquire()
{
	ObjectPool<Serial> myPool;
	auto serial = myPool.acquireObject();
	Assert::IsTrue(serial->getSerialNumber() >= 0);
}

void ObjectPoolTest::testExclusivity()
{
	ObjectPool<Serial> myPool;
	const size_t numberOfObjectsToRetrieve = 10;
	std::vector<ObjectPool<Serial>::Object> retrievedSerials;
	std::set<size_t> seenSerialNumbers;

	for (size_t i = 0; i < numberOfObjectsToRetrieve; i++) {
		auto nextSerial = myPool.acquireObject();

		// Add the retrieved Serial to the vector to keep it 'alive',
		// and add the serial number to the set.
		retrievedSerials.push_back(nextSerial);
		seenSerialNumbers.insert(nextSerial->getSerialNumber());
	}

	// Assert that all retrieved serial numbers are different.
	Assert::AreEqual(numberOfObjectsToRetrieve, seenSerialNumbers.size());
}

void ObjectPoolTest::testRelease()
{
	ObjectPool<Serial> myPool;
	const size_t numberOfObjectsToRetrieve = 10;

	std::vector<ObjectPool<Serial>::Object> retrievedSerials;
	for (size_t i = 0; i < numberOfObjectsToRetrieve; i++) {
		// Add the retrieved Serial to the vector to keep it 'alive'.
		retrievedSerials.push_back(myPool.acquireObject());
	}
	size_t lastSerialNumber = retrievedSerials.back()->getSerialNumber();
	// Release all objects back to the pool.
	retrievedSerials.clear();

	// The above loop has created ten Serial objects, with serial
	// numbers 0-9, and released all ten Serial objects back to the pool.

	// The next loop first again retrieves ten Serial objects. The serial
	// numbers of these should all be <= lastSerialNumber.
	// The Serial object acquired after that should have a new serial number.

	bool wronglyNewObjectCreated = false;
	for (size_t i = 0; i < numberOfObjectsToRetrieve; i++) {
		auto nextSerial = myPool.acquireObject();
		if (nextSerial->getSerialNumber() > lastSerialNumber) {
			wronglyNewObjectCreated = true;
			break;
		}
		retrievedSerials.push_back(nextSerial);
	}

	// Acquire one more Serial object, which should have a serial
	// number > lastSerialNumber.
	auto anotherSerial = myPool.acquireObject();
	bool newObjectCreated = (anotherSerial->getSerialNumber() > lastSerialNumber);

	Assert::IsFalse(wronglyNewObjectCreated);
	Assert::IsTrue(newObjectCreated);
}
