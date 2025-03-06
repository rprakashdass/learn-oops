#include <iostream>
#include <string>
#include <sstream>
using namespace std;

static int unique_id = 1;

// errrors & success
const string SUCCESS_WITHDRAW = "Successfully withdrawned";
const string SUCCESS_DEPOSIT = "Successfully deposited";
const string SUCCESS_ACTIVATION = "Successfully activated";
const string ERROR_INVALID_AMOUNT = "Invalid amount";
const string ERROR_INSUFFICIENT_AMOUNT = "Insufficient amount";


void printCommand(int statusCode, string message) {
	string design(message.size()+10, '=');
	cout << design << endl;
	if(statusCode) cout << "Error : ";
	else cout << "SUCCESS : ";
	cout << message << endl;
	cout << design << endl;
}

class BankAccount {
private:
	string customerName;
	long long accountNumber;
	int balance;
public:
	BankAccount(string name) : customerName(name), balance(0) {
		setAccountNumber();
	}
	void setAccountNumber() {
		this->accountNumber = unique_id;
		unique_id++;
		printCommand(1, SUCCESS_ACTIVATION);
	}
	int verifAmount(int amount) {
		return (amount > 0);
	}
	void withdraw(int amount) {
		if(balance <= 0 || balance < amount) {
			printCommand(1, ERROR_INSUFFICIENT_AMOUNT);
			return;
		}
		if(!verifAmount(amount)) {
			printCommand(1, ERROR_INVALID_AMOUNT);
			return;
		}
		this->balance -= amount;
		printCommand(1, SUCCESS_WITHDRAW);
	}
	void deposit(int amount) {
		if(!verifAmount(amount)) {
			printCommand(1, ERROR_INVALID_AMOUNT);
			return;
		}
		this->balance += amount;
		printCommand(1, SUCCESS_DEPOSIT);
	}
	void getBalance () const {
		cout << "Current Balance is " << this->balance << endl;
	}
	void showDetails () const {
		cout << "Customer Name : " << customerName << endl;
		cout << "Account Number : " << accountNumber << endl;
		cout << "Current Balance : " << balance << endl;
	}
};

int main()
{
	BankAccount account1("Prakash");
	account1.deposit(5000);
	account1.withdraw(1000);
	account1.getBalance();
	account1.showDetails();

	cout << endl;
	BankAccount account2("Raja");
	account2.showDetails();
	account2.deposit(500);
	account2.withdraw(1000);
	account2.getBalance();
	account2.showDetails();
	return 0;
}
