#include "AccessList.h"

using namespace std;

AccessList::AccessList(initializer_list<string_view> initlist)
{
	mAllowed.insert(begin(initlist), end(initlist));
}

void AccessList::addUser(string_view user)
{
	mAllowed.emplace(user);
}

void AccessList::removeUser(string_view user)
{
	mAllowed.erase(string(user));
}

bool AccessList::isAllowed(string_view user) const
{
	return (mAllowed.count(string(user)) != 0);
}

vector<string> AccessList::getAllUsers() const
{
	return { begin(mAllowed), end(mAllowed) };
}
