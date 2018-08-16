#include <iostream>
#include <string>
#include <math.h>
using namespace std;


void getUserInput(double& price, double& downPayment, int& score);
//precondition: Takes in empty variables that will hold the price of the house, downpayment, and the credit score.
//postcondition: Stores the price of the house, downpayment, and the credit score into the variables that were passed in.

double calculateInterestRate(int score);
//precondition: Take in the user's credit score.
//postcondition: Returns the interest rate determined by that credit score.

void printResults(double price, double down, double rate, int score);
//precondition: Takes in the price of the house, downpayment, interest rate, and the credit score.
//postcondition: Calculates the monthly payment for years 10-25 and prints the result.



void main() {
	double housePrice, downPayment = 0, interestRate;
	int creditScore;

	getUserInput(housePrice, downPayment, creditScore);

	interestRate = calculateInterestRate(creditScore);

	cout << endl << "House Price:" << housePrice << "  Down Payment:" << downPayment << "  Credit Score:" << creditScore << "  Interest Rate:" << interestRate << endl << endl;

	printResults(housePrice, downPayment, interestRate, creditScore);

	system("pause");
}

void getUserInput(double& price, double& down, int& score) {
	char hasDownPayment;

	cout << "Hello and welcome to the Interest Calculator" << endl << endl;

	// Get house of price
	cout << endl << "-Please enter the price of your dream home: ";
	cin >> price;

	// Checks if user is having a down payment
	cout << endl << "-Are you making any down payments? [Y: yes | N: no] ";
	cin >> hasDownPayment;

	// If there is a downpayment, get the amount
	if (hasDownPayment == 'Y' || hasDownPayment == 'y') {
		bool isValidDownPayment = false;
		while (!isValidDownPayment) {
			cout << endl << "-How much is your down payment? ";
			cin >> down;
			
			// Verify the downpament is a valid number
			if (down > price)
				cout <<  "-Please enter a down payment less than the price of your house." << endl;
			else if (down < 0)
				cout << "-Please enter a down payment greater than 0." << endl;
			else
				isValidDownPayment = true;
		}
	}

	// Get user credit score
	cout << endl << "-Please enter your CREDIT SCORE: ";
	cin >> score;
}

double calculateInterestRate(int score) {
	if (score > 0 && score <= 500)
		return 0.05;
	else if (score > 500 && score <= 700)
		return 0.02;
	else if (score > 700)
		return 0.01;
}

void printResults(double price, double down, double rate, int score) {
	double monthlyPayment, totalInterest;

	for (int i = 10; i <= 25; i++) {
		// Calculate the monthly payment 
		monthlyPayment = ((price - down) * pow((1 + rate), i)) / (12 * i);

		// Calculate the total interest
		totalInterest = (monthlyPayment*i * 12) - (price - down);

		// Print those values out
		cout.precision(2);
		cout << "Pay in " << i << " years, monthly payment is $" <<fixed << monthlyPayment << "\t" << " Total interest is $" << fixed << totalInterest << endl;

		// reset
		monthlyPayment = totalInterest = 0;
	}
}