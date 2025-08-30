#include "BankAccount.h"

BankAccount::BankAccount()
	: accountHolderName(""), balance(0.0) {}

BankAccount::BankAccount(const std::string &name, double initialBalance)
	: accountHolderName(name), balance(0.0) {
	// Validation 1: Initial balance cannot be negative
	if (initialBalance < 0.0) {
		throw std::invalid_argument("Initial balance cannot be negative");
	}
	balance = initialBalance;
}

void BankAccount::deposit(double amount) {
	// Validation 2: Deposit must be positive
	if (amount <= 0.0) {
		throw std::invalid_argument("Deposit amount must be positive");
	}
	balance += amount;
}

void BankAccount::withdraw(double amount) {
	// Validation 3: Withdraw must be positive and not exceed balance
	if (amount <= 0.0) {
		throw std::invalid_argument("Withdrawal amount must be positive");
	}
	if (amount > balance) {
		throw std::invalid_argument("Insufficient funds for withdrawal");
	}
	balance -= amount;
}

double BankAccount::getBalance() const {
	return balance;
}

void BankAccount::displayAccountInfo(std::ostream &os) const {
	os << "Account Holder: " << accountHolderName << "\n"
	   << "Balance: $" << balance << "\n";
}

const std::string & BankAccount::getAccountHolderName() const {
	return accountHolderName;
}

