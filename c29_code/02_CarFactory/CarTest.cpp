#include "CarFactory.h"
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

using namespace std;

class LeastBusyFactory : public CarFactory
{
public:
	// Constructs a LeastBusyFactory instance, taking ownership of
	// the given factories.
	explicit LeastBusyFactory(vector<unique_ptr<CarFactory>>&& factories);

protected:
	virtual unique_ptr<Car> createCar() override;

private:
	vector<unique_ptr<CarFactory>> mFactories;
};

LeastBusyFactory::LeastBusyFactory(vector<unique_ptr<CarFactory>>&& factories)
	: mFactories(std::move(factories))
{
	if (mFactories.empty())
		throw runtime_error("No factories provided.");
}

unique_ptr<Car> LeastBusyFactory::createCar()
{
	CarFactory* bestSoFar = mFactories[0].get();

	for (auto& factory : mFactories) {
		if (factory->getNumberOfCarsProduced() <
			bestSoFar->getNumberOfCarsProduced()) {
			bestSoFar = factory.get();
		}
	}

	return bestSoFar->requestCar();
}

int main()
{
	ToyotaFactory myFactory;
	auto myCar = myFactory.requestCar();
	cout << myCar->info() << endl;    // Outputs Toyota

	cout << "------------" << endl;


	vector<unique_ptr<CarFactory>> factories;

	// Create 3 Ford factories and 1 Toyota factory. 
	factories.push_back(make_unique<FordFactory>());
	factories.push_back(make_unique<FordFactory>());
	factories.push_back(make_unique<FordFactory>());
	factories.push_back(make_unique<ToyotaFactory>());

	// To get more interesting results, preorder some cars.
	factories[0]->requestCar();
	factories[0]->requestCar();
	factories[1]->requestCar();
	factories[3]->requestCar();

	// Create a factory that automatically selects the least busy
	// factory from a list of given factories.
	LeastBusyFactory leastBusyFactory(std::move(factories));

	// Build 10 cars from the least busy factory.
	for (size_t i = 0; i < 10; i++) {
		auto theCar = leastBusyFactory.requestCar();
		cout << theCar->info() << endl;
	}

	return 0;
}
