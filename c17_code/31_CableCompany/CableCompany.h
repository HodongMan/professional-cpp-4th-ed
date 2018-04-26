#pragma once

#include <cstddef>
#include <bitset>
#include <map>
#include <string>
#include <string_view>

const size_t kNumChannels = 10;

class CableCompany final
{
public:
	// Adds the package with the specified channels to the database.
	void addPackage(std::string_view packageName,
		const std::bitset<kNumChannels>& channels);

	// Removes the specified package from the database.
	void removePackage(std::string_view packageName);

	// Retrieves the channels of a given package.
	// Throws out_of_range if the package name is invalid.
	const std::bitset<kNumChannels>& getPackage(std::string_view packageName) const;

	// Adds customer to database with initial channels found in package.
	// Throws out_of_range if the package name is invalid.
	// Throws invalid_argument if the customer is already known.
	void newCustomer(std::string_view name, std::string_view package);

	// Adds customer to database with given initial channels.
	// Throws invalid_argument if the customer is already known.
	void newCustomer(std::string_view name, const std::bitset<kNumChannels>& channels);

	// Adds the channel to the customers profile.
	// Throws invalid_argument if the customer is unknown.
	void addChannel(std::string_view name, int channel);

	// Removes the channel from the customers profile.
	// Throws invalid_argument if the customer is unknown.
	void removeChannel(std::string_view name, int channel);

	// Adds the specified package to the customers profile.
	// Throws out_of_range if the package name is invalid.
	// Throws invalid_argument if the customer is unknown.
	void addPackageToCustomer(std::string_view name, std::string_view package);

	// Removes the specified customer from the database.
	void deleteCustomer(std::string_view name);

	// Retrieves the channels to which a customer subscribes.
	// Throws invalid_argument if the customer is unknown.
	const std::bitset<kNumChannels>& getCustomerChannels(std::string_view name) const;

private:
	// Retrieves the channels for a customer. (non-const)
	// Throws invalid_argument if the customer is unknown.
	std::bitset<kNumChannels>& getCustomerChannelsHelper(std::string_view name);

	using MapType = std::map<std::string, std::bitset<kNumChannels>>;
	MapType mPackages, mCustomers;
};
