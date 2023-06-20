//Declare variables to store input
float initInv, monDep, AnuInt, months, years;
//Declare variables to store year end total amount, interest, and year end interest
float totalAm, intAmt, yearTotInt;


//Function to Display form to user
void displayForm()
{
	cout << "********************************\n";
	cout << "********** Data Input **********\n";
	cout << "Initial Investment Amount: \n";
	cout << "Monthly Deposit: \n";
	cout << "Annual Interest: \n";
	cout << "Number of years: \n";

}

//Function to get data from user
void userData()
{
	cout << "********************************\n";
	cout << "********** Data Input **********\n";
	cout << "Initial Investment Amount: $";
	cin >> initInv;
	cout << "Monthly Deposit: $";
	cin >> monDep;
	cout << "Annual Interest: %";
	cin >> AnuInt;
	cout << "Number of years: ";
	cin >> years;
	months = years * 12;
}

//function to display and calculate year data with only initial deposit.
void yearDataWithoutDeposits()
{
	//Displays year data without monthly deposits
	cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
	cout << "==============================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "--------------------------------------------------------------\n";


	for (int i = 0; i < years; i++) {

		//Calculates yearly interest
		intAmt = (totalAm) * ((AnuInt / 100));

		//Calculates year end total
		totalAm = totalAm + intAmt;

		//Prints results to table showcasing only two decimal points
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAm << "\t\t\t$" << intAmt << "\n";

	}
}

//Function to display and calculate year data with inital deposit and additional monthly deposits
void yearDataWithDeposits()
{
	//Display year data with monthly deposits
	cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
	cout << "==============================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "--------------------------------------------------------------\n";

	for (int i = 0; i < years; i++) {

		//Set yearly interest to zero at the start of the year
		yearTotInt = 0;

		for (int j = 0; j < 12; j++) {

			//Calculate monthly interest
			intAmt = (totalAm + monDep) * ((AnuInt / 100) / 12);

			//Calculate month end interest
			yearTotInt = yearTotInt + intAmt;

			//Calculate month end total
			totalAm = totalAm + monDep + intAmt;

		}

		//Print results to table showcasing only two decimal points
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAm << "\t\t\t$" << yearTotInt << "\n";


	}
}
