#pragma once

#include <set>
#include <string>
#include <string_view>
#include <vector>
#include <initializer_list>

class AccessList final
{
public:
	// Default constructor
	AccessList() = default;

	// Constructor to support uniform initialization.
	AccessList(std::initializer_list<std::string_view> initlist);

	// Adds the user to the permissions list.
	void addUser(std::string_view user);

	// Removes the user from the permissions list.
	void removeUser(std::string_view user);

	// Returns true if the user is in the permissions list.
	bool isAllowed(std::string_view user) const;

	// Returns a vector of all the users who have permissions.
	std::vector<std::string> getAllUsers() const;

private:
	std::set<std::string> mAllowed;
};
