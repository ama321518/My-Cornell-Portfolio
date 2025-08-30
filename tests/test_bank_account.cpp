#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <functional>

#include "../src/BankAccount.h"

static int testsPassed = 0;
static int testsFailed = 0;

void expectTrue(bool condition, const std::string &message) {
	if (condition) {
		++testsPassed;
	} else {
		++testsFailed;
		std::cerr << "FAIL: " << message << "\n";
	}
}

void expectThrowsInvalidArg(const std::function<void()> &fn, const std::string &message) {
	try {
		fn();
		++testsFailed;
		std::cerr << "FAIL (no exception): " << message << "\n";
	} catch (const std::invalid_argument &) {
		++testsPassed;
	} catch (...) {
		++testsFailed;
		std::cerr << "FAIL (wrong exception type): " << message << "\n";
	}
}

int main() {
	// Core functionality tests
	{
		BankAccount a("Alice", 100.0);
		a.deposit(50.0);
		expectTrue(a.getBalance() == 150.0, "Deposit increases balance");
	}

	{
		BankAccount a("Bob", 200.0);
		a.withdraw(40.0);
		expectTrue(a.getBalance() == 160.0, "Withdraw decreases balance");
	}

	{
		BankAccount a("Carol", 0.0);
		expectTrue(a.getBalance() == 0.0, "Check balance returns current balance");
	}

	{
		BankAccount a("Dave", 75.0);
		std::ostringstream oss;
		a.displayAccountInfo(oss);
		std::string out = oss.str();
		expectTrue(out.find("Dave") != std::string::npos, "Display includes account holder name");
		expectTrue(out.find("Balance: $") != std::string::npos, "Display includes balance label");
	}

	// Validation tests (three key validations)
	// 1) Negative initial balance is not allowed
	expectThrowsInvalidArg([](){ BankAccount x("Eve", -1.0); }, "Negative initial balance throws");

	// 2) Deposit must be positive
	{
		BankAccount a("Frank", 10.0);
		expectThrowsInvalidArg([&](){ a.deposit(-5.0); }, "Negative deposit throws");
	}

	// 3) Withdrawal must not exceed balance
	{
		BankAccount a("Grace", 20.0);
		expectThrowsInvalidArg([&](){ a.withdraw(25.0); }, "Excessive withdrawal throws");
	}

	std::cout << "Tests passed: " << testsPassed << "\n";
	std::cout << "Tests failed: " << testsFailed << "\n";
	return testsFailed == 0 ? 0 : 1;
}

