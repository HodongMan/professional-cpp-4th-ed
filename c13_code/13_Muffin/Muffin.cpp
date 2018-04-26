#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

using namespace std;

class Muffin
{
public:
	virtual ~Muffin() = default;

	string_view getDescription() const;
	void setDescription(string_view description);

	int getSize() const;
	void setSize(int size);

	bool hasChocolateChips() const;
	void setHasChocolateChips(bool hasChips);

	void output() const;

private:
	string mDescription;
	int mSize = 0;
	bool mHasChocolateChips = false;
};

string_view Muffin::getDescription() const { return mDescription; }
void Muffin::setDescription(string_view description) { mDescription = description; }

int Muffin::getSize() const { return mSize; }
void Muffin::setSize(int size) { mSize = size; }

bool Muffin::hasChocolateChips() const { return mHasChocolateChips; }
void Muffin::setHasChocolateChips(bool hasChips) { mHasChocolateChips = hasChips; }

void Muffin::output() const
{
	printf("%s, Size is %d, %s\n", getDescription().data(), getSize(),
		(hasChocolateChips() ? "has chips" : "no chips"));
}

Muffin createMuffin(istringstream& inStream);

int main()
{
	cout << "First, let's create a muffin in code and output it." << endl;

	Muffin myMuffin;
	myMuffin.setDescription("Giant_Blueberry_Muffin");
	myMuffin.setSize(42);
	myMuffin.setHasChocolateChips(false);

	printf("The muffin is ");
	myMuffin.output();
	printf(" -- yummy!\n");


	cout << "Now we'll create a muffin from a string stream" << endl;

	istringstream instream("My_Muffin 2 true");
	Muffin m2 = createMuffin(instream);
	m2.output();

	return 0;
}

Muffin createMuffin(istringstream& stream)
{
	Muffin muffin;
	// Assume data is properly formatted:
	// Description size chips

	string description;
	int size;
	bool hasChips;

	// Read all three values. Note that chips is represented
	// by the strings "true" and "false"
	stream >> description >> size >> boolalpha >> hasChips;
	if (stream) { // Reading was successful.
		muffin.setSize(size);
		muffin.setDescription(description);
		muffin.setHasChocolateChips(hasChips);
	}

	return muffin;
}
