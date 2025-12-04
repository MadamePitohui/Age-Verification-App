#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <vector>

void getDate (std :: vector <int> & date) {
	std :: string cTime = __DATE__;
	std :: istringstream ss(cTime);
	std :: string monthStr, day, year;
	ss >> monthStr >> day >> year;

	std :: map<std :: string, std :: string> months = {
		{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"},
		{"Apr", "04"}, {"May", "05"}, {"Jun", "06"},
		{"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"},
		{"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
	};

	int mm = std :: stoi(months [monthStr]);
	int dd = std :: stoi(day);
	int yyyy = std :: stoi(year);

	date.push_back(mm);
	date.push_back(dd);
	date.push_back(yyyy);
}

void printOptions () {
	std :: cout << "**Options**" << std :: endl;
	std :: cout << "-1 = Quit" << std :: endl;
	std :: cout << "0 = Reprint Options" << std :: endl;
	std :: cout << "1 = VerifyAge & DOB" << std :: endl;
	std :: cout << "2 = " << std :: endl;
}

/* Months
Jan = 01 Feb = 02 Mar = 03 Apr = 04
May = 05 Jun = 06 Jul = 07 Aug = 08
Sep = 09 Oct = 10 Nov = 11 Dec = 12
*/

void verifyAgeDOB (std :: vector <int> date) {
	int GivenAge;
	std :: vector <int> GivenDOB;
	int GivenDOBmm;
	int GivenDOBdd;
	int GivenDOByyyy;
	int EstiAge;

	std :: cout << "GivenAge = ";
	std :: cin >> GivenAge;
	std :: cout << "GivenDOB (MM DD YYYY) = ";
	std :: cin >> GivenDOBmm >> GivenDOBdd >> GivenDOByyyy;
	GivenDOB.push_back(GivenDOBmm);
	GivenDOB.push_back(GivenDOBdd);
	GivenDOB.push_back(GivenDOByyyy);
	std :: cout << "with age " << GivenAge << " and DOB of " << GivenDOB[0] << " " << GivenDOB[1]
	<< " " << GivenDOB[2] << "..." << std :: endl;

	int monthsNumz = (date[0] - GivenDOB[0]);
	int daysNumz = (date[1] - GivenDOB[1]);
	int yearsNumz = (date[2] - GivenDOB[2]);

	if (monthsNumz < 0) {
		EstiAge = (yearsNumz - 1);
	} else if (((monthsNumz) == 0) && ((daysNumz) < 0)) {
		EstiAge = ((yearsNumz) - 1);
	}
	else {
		EstiAge = yearsNumz;
	}
	if (EstiAge == GivenAge) {
		std :: cout << "They have been Verified" << std :: endl;
		std :: cout << "They are : "<< EstiAge << std :: endl;
		std :: cout << "Highest entry includes : " << std :: endl;
		if (! (EstiAge < 25)) {
			std :: cout << "25+" << std :: endl;
		}
		else if (! (EstiAge < 21)) {
			std :: cout << "21+" << std :: endl;
		}
		else if (! (EstiAge < 18)) {
			std :: cout << "18+" << std :: endl;
		}
		else if (! (EstiAge < 16)) {
			std :: cout << "16+" << std :: endl;
		}
		else {
			std :: cout << "None" << std :: endl;
		}
	}
	else {
		std :: cout << "They Lie Kick Their Bum!" << std :: endl;
		std :: cout << EstiAge << " != "<< GivenAge << std :: endl;
		std :: cout << "Where EstiAge was deturmined by GivenDOB" << std :: endl;
	}
}

void choicesMaker () {
}

int main () {
	int option = 0;
	std :: vector <int> date;
	getDate(date);
	std :: cout << "Current date set to " << date[0] << " " << date[1] << " " << date[2]
	<< std :: endl << "Compile for new time using <g++ filename> in terminal." << std :: endl;

	while (option != -1) {

		if (option == 0) {
			std :: cout << std :: endl;
			printOptions();
		}
		std :: cin >> option;

		if (option == 1) {
			std :: cout << "Verifing Age & DOB" << std :: endl;
			verifyAgeDOB (date);
			option = 0;
		}
		else if (option == 2) {
			std :: cout << "Helping with making choices" << std :: endl;
		}
		else {
			if (option == -1){
				std :: cout << "Program Ended. Cya!" << std :: endl;
			}
			else {
				std :: cout << "Invalid input / not avalible input" << std :: endl;
			}
		}
	}
	return 0;
}