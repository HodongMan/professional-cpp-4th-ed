#include <iostream>
#include <vector>
#include <algorithm>

class IObserver
{
public:
	virtual ~IObserver() = default;  // Always a virtual destructor!
	virtual void notify() = 0;
};

class ConcreteObserver1 : public IObserver
{
public:
	void notify() override { std::cout << "ConcreteObserver1::notify()" << std::endl; }
};

class ConcreteObserver2 : public IObserver
{
public:
	void notify() override { std::cout << "ConcreteObserver2::notify()" << std::endl; }
};



class Observable
{
public:
	virtual ~Observable() = default;  // Always a virtual destructor!

	// Add an observer. Ownership is not transferred.
	void addObserver(IObserver* observer)
	{
		mObservers.push_back(observer);
	}

	// Remove the given observer.
	void removeObserver(IObserver* observer)
	{
		mObservers.erase(
			std::remove(begin(mObservers), end(mObservers), observer),
			end(mObservers));
	}

protected:
	void notifyAllObservers()
	{
		for (auto* observer : mObservers)
			observer->notify();
	}

private:
	std::vector<IObserver*> mObservers;
};



class ObservableSubject : public Observable
{
public:
	void modifyData()
	{
		// ...
		notifyAllObservers();
	}
};



int main()
{
	ObservableSubject subject;

	ConcreteObserver1 observer1;
	subject.addObserver(&observer1);

	subject.modifyData();

	std::cout << std::endl;

	ConcreteObserver2 observer2;
	subject.addObserver(&observer2);

	subject.modifyData();

	return 0;
}