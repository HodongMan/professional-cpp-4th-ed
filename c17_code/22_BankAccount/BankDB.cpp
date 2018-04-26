#include "BankDB.h"
#include <utility>
#include <stdexcept>

using namespace std;

bool BankDB::addAccount(const BankAccount& acct)
{
	// Do the actual insert, using the account number as the key
	auto res = mAccounts.emplace(acct.getAcctNum(), acct);
	// or: auto res = mAccounts.insert(make_pair(acct.getAcctNum(), acct));

	// If your compiler doesn't support C++11 'auto', you need the following:
	// Declare a variable to store the return from insert()
	//pair<map<int, BankAccount>::iterator, bool> res;
	// do the actual insert, using the account number as the key
	//res = mAccounts.insert(make_pair(acct.getAcctNum(), acct));

	// Return the bool field of the pair specifying success or failure
	return res.second;
}

void BankDB::deleteAccount(int acctNum)
{
	mAccounts.erase(acctNum);
}

BankAccount& BankDB::findAccount(int acctNum)
{
	// Finding an element via its key can be done with find()
	auto it = mAccounts.find(acctNum);
	// If your compiler doesn't support C++11 'auto', you need:
	//map<int, BankAccount>::iterator it = mAccounts.find(acctNum);

	if (it == end(mAccounts)) {
		throw out_of_range("No account with that number.");
	}

	// Remember that iterators into maps refer to pairs of key/value
	return it->second;
}

BankAccount& BankDB::findAccount(string_view name)
{
	// Finding an element by a non-key attribute requires a linear
	// search through the elements. Uses C++17 structured bindings.
	for (auto& [acctNum, account] : mAccounts) {
		if (account.getClientName() == name) {
			return account;  // found it!
		}
	}

	// If your compiler doesn't support the above C++17 structured
	// bindings yet, you can use the following implementation
	//for (auto& p : mAccounts) {
	//	if (p.second.getClientName() == name) {
	//		return p.second;  // found it!
	//	}
	//}

	// If your compiler doesn't support the above C++11 range based for
	// loop, you need the following loop
	//for (map<int, BankAccount>::iterator it = mAccounts.begin();
	//     it != mAccounts.end(); ++it) {
	//  if (it->second.getClientName() == name) {
	//    return it->second;  // found it!
	//  }
	//}
	throw out_of_range("No account with that name.");
}

void BankDB::mergeDatabase(BankDB& db)
{
	// Use C++17 merge().
	mAccounts.merge(db.mAccounts);
	// Or: mAccounts.insert(begin(db.mAccounts), end(db.mAccounts));

	// Now clear the source database.
	db.mAccounts.clear();
}
