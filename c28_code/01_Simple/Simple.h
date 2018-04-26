#pragma once

// A simple class that illustrates class definition syntax.
class Simple
{
public:
	Simple();                       // Constructor
	virtual ~Simple() = default;    // Defaulted virtual destructor

	// Disallow assignment and pass-by-value.
	Simple(const Simple& src) = delete;
	Simple& operator=(const Simple& rhs) = delete;

	// Explicitly default move constructor and move assignment operator.
	Simple(Simple&& src) = default;
	Simple& operator=(Simple&& rhs) = default;

	virtual void publicMethod();    // Public method
	int mPublicInteger;             // Public data member

protected:
	virtual void protectedMethod(); // Protected method
	int mProtectedInteger = 41;     // Protected data member

private:
	virtual void privateMethod();   // Private method
	int mPrivateInteger = 42;       // Private data member
	static const int kConstant = 2; // Private constant
	static int sStaticInt;          // Private static data member
};
