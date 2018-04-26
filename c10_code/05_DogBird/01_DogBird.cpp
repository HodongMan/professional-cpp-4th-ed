#include <iostream>

using namespace std;

class Dog
{
public:
	virtual void bark() { cout << "woof!" << endl; }
	virtual void eat() { cout << "The dog ate." << endl; }
};

class Bird
{
public:
	virtual void chirp() { cout << "chirp!" << endl; }
	virtual void eat() { cout << "The bird ate." << endl; }
};

class DogBird : public Dog, public Bird
{
public:
	//void eat() override;
	//using Dog::eat;       // Explicitly inherit Dog's version of eat()
};

//void DogBird::eat()
//{
//	Dog::eat();  // Explicitly call Dog's version of eat()
//}

int main()
{
	DogBird myConfusedAnimal;

	myConfusedAnimal.bark();
	myConfusedAnimal.chirp();
	//myConfusedAnimal.eat();                   // Error! Ambiguous call to method eat()
	dynamic_cast<Dog&>(myConfusedAnimal).eat(); // Calls Dog::eat()
	myConfusedAnimal.Dog::eat();                // Calls Dog::eat()

	return 0;
}
