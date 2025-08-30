#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <stdexcept>
#include <iostream>

class BankAccount {
private:
	std::string accountHolderName;
	double balance;

public:
	// Constructors
	BankAccount();
	explicit BankAccount(const std::string &name, double initialBalance = 0.0);

	// Core banking functions
	void deposit(double amount);
	void withdraw(double amount);
	double getBalance() const;
	void displayAccountInfo(std::ostream &os = std::cout) const;

	// Accessors
	const std::string & getAccountHolderName() const;
};

#endif // BANK_ACCOUNT_H

