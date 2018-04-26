class X {};
class Y {};

int main()
{
	X x;
	Y y;

	X* xp = &x;
	Y* yp = &y;

	// Need reinterpret cast for pointer conversion from unrelated classes
	// static_cast doesn't work.
	xp = reinterpret_cast<X*>(yp);

    // No cast required for conversion from pointer to void*
    void* p = xp;
    // Need reinterpret cast for pointer conversion from void*
    xp = reinterpret_cast<X*>(p);

	// Need reinterpret cast for reference conversion from unrelated classes
	// static_cast doesn't work.
	X& xr = x;
	Y& yr = reinterpret_cast<Y&>(x);

	return 0;
}
