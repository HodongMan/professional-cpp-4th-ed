#include <algorithm>
#include <functional>
#include <map>
#include <vector>
#include <iostream>
#include <utility>
#include <string>
#include <set>

using namespace std;

using VotersMap = map<string, vector<string>>;
using DistrictPair = pair<const string, vector<string>>;

// Returns a set of all names that appear in more than one vector in
// the map.
//
// The implementation generates one large vector of all the names from
// all the vectors in the map, sorts it, then finds all duplicates
// in the sorted vector with adjacent_find().
set<string> getDuplicates(const VotersMap& votersByDistrict)
{
	// Collect all the names from all the vectors into one big vector.
	vector<string> allNames;
	for (auto& district : votersByDistrict) {
		allNames.insert(end(allNames), begin(district.second), end(district.second));
	}

	// Sort the vector.
	sort(begin(allNames), end(allNames));

	// Now it's sorted, all duplicate names will be next to each other.
	// Use adjacent_find() to find instances of two or more identical names
	// next to each other.
	// Loop until adjacent_find() returns the end iterator.
	set<string> duplicates;
	for (auto lit = cbegin(allNames); lit != cend(allNames); ++lit) {
		lit = adjacent_find(lit, cend(allNames));
		if (lit == cend(allNames)) {
			break;
		}
		duplicates.insert(*lit);
	}

	return duplicates;

	/*
	set<string> allNames;
	set<string> duplicates;
	for (auto&[district, voters] : votersByDistrict) {
		for (auto& name : voters) {
			if (!allNames.insert(name).second) {
				duplicates.insert(name);
			}
		}
	}
	return duplicates;
	*/
}

// Expects a map of string/vector<string> pairs keyed on district names
// and containing vectors of all the registered voters in those districts.
//
// Removes from each vector any name on the convictedFelons vector and
// any name that is found on any other vector.
void auditVoterRolls(VotersMap& votersByDistrict,
	const vector<string>& convictedFelons)
{
	// Get all the duplicate names.
	set<string> toRemove = getDuplicates(votersByDistrict);

	// Combine the duplicates and convicted felons -- we want
	// to remove names on both vectors from all voter rolls.
	toRemove.insert(cbegin(convictedFelons), cend(convictedFelons));

	// Now remove all the names we need to remove using
	// nested lambda expressions and the remove-erase-idiom.
	for_each(begin(votersByDistrict), end(votersByDistrict),
		[&toRemove](DistrictPair& district) {
			auto it = remove_if(begin(district.second),
				end(district.second), [&toRemove](const string& name) {
					return (toRemove.count(name) > 0);
				}
			);
			district.second.erase(it, end(district.second));
		}
	);

	/*
	for (auto&[district, voters] : votersByDistrict) {
		auto it = remove_if(begin(voters), end(voters),
			[&toRemove](const string& name) {
				return (toRemove.count(name) > 0);
			}
		);
		voters.erase(it, end(voters));
	}
	*/
}

int main()
{
	// Initialize map using uniform initialization
	VotersMap voters = {
		{ "Orange", { "Amy Aardvark", "Bob Buffalo", "Charles Cat", "Dwayne Dog" } },
		{ "Los Angeles", { "Elizabeth Elephant", "Fred Flamingo", "Amy Aardvark" } },
		{ "San Diego", { "George Goose", "Heidi Hen", "Fred Flamingo" } }
	};

	vector<string> felons = { "Bob Buffalo", "Charles Cat" };

	// Local lambda expression to print a district
	auto printDistrict = [](const DistrictPair& district) {
		cout << district.first << ":";
		for (auto& str : district.second) {
			cout << " {" << str << "}";
		}
		cout << endl;
	};

	cout << "Before Audit:" << endl;
	for (const auto& district : voters) { printDistrict(district); }
	cout << endl;

	auditVoterRolls(voters, felons);
	
	cout << "After Audit:" << endl;
	for (const auto& district : voters) { printDistrict(district); }
	cout << endl;

	return 0;
}
