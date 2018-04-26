#include <iostream>

using namespace std;

// forward declarations
class Fish;
class Bear;
class Dinosaur;

class Animal
{
public:
	virtual bool eats(const Animal& prey) const = 0;

	virtual bool eatenBy(const Bear&) const = 0;
	virtual bool eatenBy(const Fish&) const = 0;
	virtual bool eatenBy(const Dinosaur&) const = 0;
};

class Bear : public Animal
{
public:
	virtual bool eats(const Animal& prey) const override;

	virtual bool eatenBy(const Bear&) const override;
	virtual bool eatenBy(const Fish&) const override;
	virtual bool eatenBy(const Dinosaur&) const override;
};

class Fish : public Animal
{
public:
	virtual bool eats(const Animal& prey) const override;

	virtual bool eatenBy(const Bear&) const override;
	virtual bool eatenBy(const Fish&) const override;
	virtual bool eatenBy(const Dinosaur&) const override;
};

class Dinosaur : public Animal
{
public:
	virtual bool eats(const Animal& prey) const override;

	virtual bool eatenBy(const Bear&) const override;
	virtual bool eatenBy(const Fish&) const override;
	virtual bool eatenBy(const Dinosaur&) const override;
};

bool Bear::eats(const Animal& prey) const {	return prey.eatenBy(*this); }
bool Bear::eatenBy(const Bear&) const { return false; }
bool Bear::eatenBy(const Fish&) const { return false; }
bool Bear::eatenBy(const Dinosaur&) const { return true; }

bool Fish::eats(const Animal& prey) const { return prey.eatenBy(*this); }
bool Fish::eatenBy(const Bear&) const { return true; }
bool Fish::eatenBy(const Fish&) const { return true; }
bool Fish::eatenBy(const Dinosaur&) const { return true; }

bool Dinosaur::eats(const Animal& prey) const {	return prey.eatenBy(*this); }
bool Dinosaur::eatenBy(const Bear&) const { return false; }
bool Dinosaur::eatenBy(const Fish&) const { return false; }
bool Dinosaur::eatenBy(const Dinosaur&) const { return true; }

int main()
{
	Fish myFish;
	Bear myBear;
	Dinosaur myDino;

	cout << "Fish eats bear? " << myFish.eats(myBear) << endl;
	cout << "Fish eats dino? " << myFish.eats(myDino) << endl;
	cout << "Dino eats bear? " << myDino.eats(myBear) << endl;
	cout << "Bear eats fish? " << myBear.eats(myFish) << endl;

	return 0;
}
