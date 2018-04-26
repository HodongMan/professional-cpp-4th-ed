#include <thread>
#include <iostream>

using namespace std;

class Request
{
public:
	Request(int id) : mId(id) { }

	void process()
	{
		cout << "Processing request " << mId << endl;
	}

private:
	int mId;
};

int main()
{
	Request req(100);
	thread t{ &Request::process, &req };

	t.join();

	return 0;
}
