#include <iostream>

class Handler
{
public:
	virtual ~Handler() = default;

	Handler(Handler* nextHandler) : mNextHandler(nextHandler) { }

	virtual void handleMessage(int message)
	{
		if (mNextHandler)
			mNextHandler->handleMessage(message);
	}
private:
	Handler * mNextHandler;
};

class ConcreteHandler1 : public Handler
{
public:
	ConcreteHandler1(Handler* nextHandler) : Handler(nextHandler) {}

	void handleMessage(int message) override
	{
		std::cout << "ConcreteHandler1::handleMessage()" << std::endl;
		if (message == 1)
			std::cout << "Handling message " << message << std::endl;
		else {
			std::cout << "Not handling message " << message << std::endl;
			Handler::handleMessage(message);
		}
	}
};

class ConcreteHandler2 : public Handler
{
public:
	ConcreteHandler2(Handler* nextHandler) : Handler(nextHandler) {}

	void handleMessage(int message) override
	{
		std::cout << "ConcreteHandler2::handleMessage()" << std::endl;
		if (message == 2)
			std::cout << "Handling message " << message << std::endl;
		else {
			std::cout << "Not handling message " << message << std::endl;
			Handler::handleMessage(message);
		}
	}
};

int main()
{
	ConcreteHandler2 handler2(nullptr);
	ConcreteHandler1 handler1(&handler2);

	handler1.handleMessage(1);
	std::cout << std::endl;

	handler1.handleMessage(2);
	std::cout << std::endl;

	handler1.handleMessage(3);
}