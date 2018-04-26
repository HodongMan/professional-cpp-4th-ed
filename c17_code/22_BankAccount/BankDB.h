#pragma once

#include <map>
#include <string>
#include <string_view>

class BankAccount final
{
public:
	BankAccount(int acctNum, std::string_view name) : mAcctNum(acctNum), mClientName(name) {}

	void setAcctNum(int acctNum) { mAcctNum = acctNum; }
	int getAcctNum() const { return mAcctNum; }

	void setClientName(std::string_view name) { mClientName = name; }
	std::string_view getClientName() const { return mClientName; }

private:
	int mAcctNum;
	std::string mClientName;
};

class BankDB final
{
public:
	// Adds account to the bank database. If an account exists already
	// with that number, the new account is not added. Returns true
	// if the account is added, false if it's not.
	bool addAccount(const BankAccount& account);

	// Removes the account acctNum from the database.
	void deleteAccount(int acctNum);

	// Returns a reference to the account represented
	// by its number or the client name.
	// Throws out_of_range if the account is not found.
	BankAccount& findAccount(int acctNum);
	BankAccount& findAccount(std::string_view name);

	// Adds all the accounts from db to this database.
	// Deletes all the accounts from db.
	void mergeDatabase(BankDB& db);

private:
	std::map<int, BankAccount> mAccounts;
};

