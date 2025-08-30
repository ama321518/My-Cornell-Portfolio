#include <iostream>
#include "BankAccount.h"

int main() {
	try {
		BankAccount account("Alice", 100.0);
		account.deposit(50.0);
		account.withdraw(30.0);
		account.displayAccountInfo(std::cout);
		std::cout << "Current balance: $" << account.getBalance() << "\n";
	} catch (const std::exception &ex) {
		std::cerr << "Error: " << ex.what() << "\n";
		return 1;
	}
	return 0;
}

