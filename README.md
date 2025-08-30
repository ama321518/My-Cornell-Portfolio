# Bank Account (C++)

A small C++ project that provides a `BankAccount` class with essential banking functions and validation.

## Features
- Deposit, withdraw, check balance, display account info
- 3 validation checks:
  - Initial balance cannot be negative
  - Deposit amount must be positive
  - Withdrawal amount must be positive and cannot exceed current balance

## Build

Requires `g++` with C++17.

```bash
make
```

## Run Demo
```bash
make run
```

## Run Tests
```bash
make test
```
You should see all tests passing.

## Example Output
```text
Account Holder: Alice
Balance: $120
Current balance: $120
```

## Project Structure
- `src/BankAccount.h`, `src/BankAccount.cpp`: Class implementation
- `src/main.cpp`: Simple demo
- `tests/test_bank_account.cpp`: Lightweight unit tests
- `Makefile`: Build targets (`run`, `test`)
