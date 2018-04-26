#include "BuddyList.h"

using namespace std;

void BuddyList::addBuddy(const string& name, const string& buddy)
{
	// Make sure this buddy isn't already there. We don't want
	// to insert an identical copy of the key/value pair.
	if (!isBuddy(name, buddy)) {
		mBuddies.insert({ name, buddy }); // Using initializer_list
	}
}

void BuddyList::removeBuddy(const string& name, const string& buddy)
{
	// Obtain the beginning and end of the range of elements with
	// key 'name'. Use both lower_bound() and upper_bound() to demonstrate
	// their use. Otherwise, it�s more efficient to call equal_range().
	auto begin = mBuddies.lower_bound(name);  // Start of the range
	auto end = mBuddies.upper_bound(name);    // End of the range

	// Iterate through the elements with key 'name' looking
	// for a value 'buddy'. If there are no elements with key 'name',
	// begin equals end, so the loop body doesn't execute.
	for (auto iter = begin; iter != end; ++iter) {
		if (iter->second == buddy) {
			// We found a match! Remove it from the map.
			mBuddies.erase(iter);
			break;
		}
	}
}

bool BuddyList::isBuddy(const string& name, const string& buddy) const
{
	// Obtain the beginning and end of the range of elements with
	// key 'name' using equal_range(), and C++17 structured bindings.
	auto [begin, end] = mBuddies.equal_range(name);
	
	// If your compiler does not support C++17 structured bindings:
	//auto range = mBuddies.equal_range(name);
	//auto begin = range.first;  // Start of the range
	//auto end = range.second;   // End of the range

	// Iterate through the elements with key 'name' looking
	// for a value 'buddy'.
	for (auto iter = begin; iter != end; ++iter) {
		if (iter->second == buddy) {
			// We found a match!
			return true;
		}
	}
	// No matches
	return false;
}

vector<string> BuddyList::getBuddies(const string& name) const
{
	// Obtain the beginning and end of the range of elements with
	// key 'name' using equal_range(), and C++17 structured bindings.
	auto [begin, end] = mBuddies.equal_range(name);

	// If your compiler does not support C++17 structured bindings:
	//auto range = mBuddies.equal_range(name);
	//auto begin = range.first;  // Start of the range
	//auto end = range.second;   // End of the range

	// Create a vector with all names in the range (all buddies of name).
	vector<string> buddies;
	for (auto iter = begin; iter != end; ++iter) {
		buddies.push_back(iter->second);
	}

	return buddies;
}
