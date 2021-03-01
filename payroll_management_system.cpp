
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cctype>
#include <conio.h>
#include <sstream>
#include <iomanip>
#include <algorithm>


using namespace std;

const int SIZE = 50;
int totalemployees;
int m;
int count, count1;
double extrabonus, totaldeduct, deduct;
string employeearray[SIZE][3];
double dataarray[SIZE][6];
void append();
void find();
void readarray();
void employeedel();
void whattodo();
void loop();
void addData();
void mainfind();

int main() {

	system("Color 2F");
	cout << "\t\t\t --------------------------" << endl;
	cout << "\t\t\t Bella Terra Payroll System " << endl;
	cout << "\t\t	 --------------------------" << endl;
	whattodo();
	getch();
	return 0;
}

void whattodo() {

	int choice;
	loop:
		
	cout << "Select A Number From The Menu Below:" << endl;
	cout << endl;
	cout << "[1] Add Employee" << endl;
	cout << "[2] Delete An Employee" << endl;
	cout << "[3] Add Data" << endl;
	cout << "[4] Exit" << endl;
	
	cout << "" << endl;
	cin >> choice;
	cout << "" << endl;
	if (choice == 1) {
		system("cls");
		append();
		loop();
	}
	else if (choice == 2) {
		employeedel();
	}

	else if (choice == 3) {
		system("cls");
		cout << "Enter Month: (i.e 1,5,11): "; //date
		cin >> m;
		while (1) {
		cin.clear();
		cin.ignore(10000, '\n');
		if ((m > 0) && (m < 13)) {
			m = m;
			break;
		}
		else {
			system("cls");
			cout << "Month Must Be Between 1-12. " << endl;
			cout << "\nEnter Month: (i.e 1,5,11): ";
			cin >> m;
		}
	
	}
	addData();
	}
	
	else if (choice == 4) {
		
	
		cout << "Copyright " << (char)184 << " 2019 Shaun Peretz. All Rights Reserved.";
		exit(0);
	}
	
	else {
		cout << "Invalid Key." << endl;
		goto loop;
		system("cls");
	}
	
	

}

	
void append()
{
	int id;
	ofstream fout;
	fout.open("myRecord.txt",ios::app);// open file for appending
	readarray();
	
	id = totalemployees;
	string emp_first;
	string entry, entry2, entry3;
	system("cls");
	cout << "Employee #" << id << ":" << endl;
	
	cout << "\nEnter Employee First and Last Name: ";
	cin.ignore();
	getline(cin, emp_first);
	emp_first.erase(emp_first.find_last_not_of(" \n\r\t")+1);


	cout << "\n30% From 0: (y/n) ";
	cin >> entry;
	
	while(1) {
		if ((entry == "y") || (entry == "Y")) {
	  		entry = "1";
	  		break;
	 	}
	 	else if ((entry == "n") || (entry == "N")) {
	 		entry = "0";
			break;
	 	}
	 	else {
	 		cout << "Invalid key" << endl;
	 		cout << "30% From 0 (y/n) ";
	 		cin >> entry;
	 	}
 	}
 	
 	fout << setiosflags(ios::fixed | ios :: showpoint)
	<< setprecision(2);
	fout << id << ", " << emp_first
   	 << ", " << entry  << "," << endl;
	fout << fixed;
 	fout.close( ); //close file
	;
	
	system("cls");
	cout << "\nWould You Like to Enter Another Employee (y/n): ";
	cin >> entry3;
 	while(1) 
 	{
 	 if ((entry3 == "y") || (entry3 == "Y")) {
	  	append();
		}
	 else if ((entry3 == "n") || (entry3 == "N")) {
	 	whattodo();
	 	}
	 else {
	 	cout << "Invalid key" << endl;
	 	cout << "\nWould You Like to Enter Another Employee (y/n): ";
	 	cin >> entry3;
	 }
 	
 }
}

void readarray() {
	
	ifstream data("myRecord.txt");
	string item,line;
	
	int x = 0;
	int y = 1;
	
	cout << endl;
	cout << "" << endl;
	
	while(!data.eof()) {
		getline(data,line);
		stringstream stream(line);
		while(getline(stream,item,',')) {
			
	
			employeearray[x][y] = item;
		
			y++;
		}
		y=1;
		x++;
	}

	data.close();
	totalemployees = x;
}

void employeedel() { 						//Del employee from list.
	
	int id;
	string entry, emp_name;
	readarray();
	
	cout<<"Employee List: " << endl; //Show employee list.
	cout << endl;
	
	for (int i =0; i<totalemployees-1; i++) {
		for (int j=1; j<2; j++) {
			int z;
			z = (i+1)%2;
		
			if (z == 0) {
				if (i == 1) {
					cout << "\t\t" << employeearray[i][j] << ". " << employeearray[i][j+1] <<endl;
					break;
				}
				cout << "\t\t" << employeearray[i][j] << ". " << employeearray[i][j+1] << endl;
				i++;  
			}
			if (i+1 == totalemployees) {
				break;
			}
			else {
				cout << employeearray[i][j] << ". " << employeearray[i][j+1];
			}	
		}
	}
	
	cout << " " << endl;
	cout << "\nWhich Employee Would You Like To Delete? ";
	cout << " " << endl;
	cout << "\nEmployee ID #: "; //Select an employee.
	cin >> id;
	cout << " " << endl;
	cout << "Deleting Employee... " << employeearray[id-1][2] << endl;
	string idstring = to_string(id);


	ofstream fout;
	int numberpage = 1;
	fout.open("myRecord.txt",ios::out);// open file for rewriting
	for (int q = 0; q < totalemployees-1; q++) {
		emp_name = employeearray[q][2];
		entry = employeearray[q][3];
		if (employeearray[q][1] == idstring) {
		}
		else {
			
			fout << setiosflags(ios::fixed | ios :: showpoint)
			<< setprecision(2);
			fout << numberpage << ", " << emp_name
   	 		<< ", " << entry  << "," << endl;
			fout << fixed;
			numberpage++;
		}
		
	}
	cout << "Done." << endl;

	fout.close( ); //close file
	;
}

void find() {

	ifstream data("myRecord.txt");
	string item,line;
	int x=0;
	int y=0;
	string id;
	cout<<endl;
	cout << "Enter Employee Id: ";
	cin >> id;
 	cout << "" << endl;

	while(!data.eof()) {
		getline(data,line);
		string item_array[10];
		stringstream stream(line);
		x=0,y=0;
		while(getline(stream,item,',')) {
			item_array[x]=item;
			x++;
			item_array[y]=item;
			y++;
		}
		if(item_array[0]==id) {
			cout << setfill('-') << left << setw(10) << "\t\t\tID:" << right << " " << item_array[0] << endl;
			cout << setfill('-') << left << setw(10) << "\t\t\tName: " << right << " " << item_array[1] << endl;
			cout << setfill('-') << left << setw(10) << "\t\t\tRate: " << right << " " << item_array[2] << endl;
			cout << "" << endl;
		}
	}
	data.close();
}

void loop() {
	string choice;
	cout << "" << endl;
	cout << "Do you want to make another choice?(yes/no)";
	cin >> choice;
	system("cls");
	cout << "" << endl;
	if ((choice == "y") || (choice == "Y")) {
		whattodo();
	}
	else if ((choice == "n") || (choice == "N")) {
		cout << "Goodbye.";
	}
}
void addData() //enter data
{
	int d;
	int p;
	int d1; //Day to fix
	string note1, note2;
	double commission;
	double dtotal, totalsales, totalbonus, total, totalcommission;
	string loopit;
	double dbonus;
	double damount;
	string yorn;
	
	cout << endl;
	totaldeduct = 0;
	readarray();
	
	string item_array[10];
	ifstream data("myRecord.txt");
	string item,line;
	
	int x=0;
	int y=0;
	int id;
	
	int count = 0;
	
	employee:
		
	cout<<"Employee List: " << endl; //Show employee list.
	cout << endl;
	for (int i =0; i<totalemployees-1; i++) {
		for (int j=1; j<2; j++)
		{
			int z;
			z = (i+1)%2;
		
			if (z == 0) {
				if (i == 1) {
					cout << "\t\t" << employeearray[i][j] << ". " << employeearray[i][j+1] <<endl;
					break;
				}
				cout << "\t\t" << employeearray[i][j] << ". " << employeearray[i][j+1] << endl;
				i++;  
			}
			if (i+1 == totalemployees) {
				break;
			}
			else {
				cout << employeearray[i][j] << ". " << employeearray[i][j+1];
			}
		
	
		
			
		}
	}
	cout << " " << endl;
	cout << "\nEmployee ID #: "; //Select an employee.
	cin >> id;
	cout << "" << endl;
	system("cls");
	
	loop: //LOOP STARTS BACK HERE
											
	cout << "\nEntering Data For: " << employeearray[id-1][2] << endl; // Employee Name.
	cout << "\nEnter Day (i.e 1,12,31) ";
	cout << "or Press 0 to End: ";
	cin >> d;	

	while (1) {
		cin.clear();
		cin.ignore(10000, '\n');
		if ((d > 0) && (d < 32)) {
			for (int q = 0; q < count; q++) {					//Cant enter same day twice
				if (dataarray[q][2] == d) {			
					cout << "\nYou Already Inserted Data For: " << m << "/" << d << "/19" << endl;
					cout << "Please Select A Different Day." << endl;
					goto loop;
				}
			}
			d = d;
			break;
		}
		else if (d == 0) {			//end data session
			break;
		}
		else {
			cout << "Day Must Be Between 1-31. " << endl;
			cout << "\nEnter Day: (i.e 1,5,11): ";
			cin >> d;
		}
	}
	dtotal = 0;
	
	if (d == 0) {
	}
	else {
		cout << "\nDate: " << m << "/" << d << "/19" << endl; //Date.
		cout << "\nEnter Daily Sales: "; // Daily sales.
		cin >> damount;
		while (1) {						//Daily Sales.
			cin.clear();
			cin.ignore(10000, '\n');
			if (damount > 0) {
				damount = damount;
				break;
			}
			else  {
				cout << "Sales Must Greater Than 0." << endl; 
				cout << "\nEnter Daily Sales: ";
				cin >> damount;
				}
		}
	}
	
	string c1 = employeearray[id-1][3]; //Compare value 1
	string c2 = "  0"; //Compare Employee type 
	string c3 = "  1";

	if (d != 0) {
	

		if ((c1.compare(c2)) == 0) {  //IF EMPLOYEE TYPE 0
			if ((damount > 0) && (damount < 600)) {
				commission = 0.25 * damount;
				dbonus = 0;
			}
			else if ((damount > 599) && (damount < 1000))  {
				commission = 0.28 * damount;
				dbonus = 0;
			}
			else if (damount > 999) {
				commission = 0.30 * damount;
				dbonus = 0;
				if ((damount > 1599) && (damount < 2000)) {
					dbonus = dbonus + 100;
				}
				else if ((damount > 1999) && (damount < 3000)) {
					dbonus = dbonus + 200;
					}
				else if (damount > 2999) {
					dbonus = dbonus + 300;
					}
				else {
				}
			}
		else {
		}
		}
		else if ((c1.compare(c3)) == 0) { 									//If employee type 1
			commission = 0.30 * damount;
			dbonus = 0;
			if ((damount > 1599) && (damount < 2000)) {
				dbonus = dbonus + 100;
			}
			else if ((damount > 1999) && (damount < 3000)) {
				dbonus = dbonus + 200;
			}
			else if (damount > 2999) {
				dbonus = dbonus + 300;
				}
			else {
			}
		}
		else {	
		}
		dtotal = (commission + dbonus);
	
		dataarray[p][1] = m;
		dataarray[p][2] = d;
		dataarray[p][3] = damount;
		dataarray[p][4] = dbonus;
		dataarray[p][5] = commission;
		dataarray[p][6] = dtotal;
	
		p++;
		count++;
	}
	else {
	}

	if (d != 0) {
		system("cls");
		cout << "Lastest Day Entered:  " << m << "/" << d << "/19" << endl;
		goto loop;
	}
	else {
	}
	
	cout << "Enter Bonuses or Deductions (y/n): ";
	cin >> yorn;
	
	if ((yorn == "y") || (yorn == "Y"))  //Add another day for same employee
	{
	 	cout << "\nBonus: ";
		cin >> dbonus;
		while (1) {
			if (dbonus > 0) {
				extrabonus = dbonus;
				cout << "Note: ";
				cin.ignore();
				getline(cin, note1);
				break;
				}
			else {
				break;
			}
		}
			
		cout << "\nDeductions: ";
		cin >> deduct;
		while (1) {
			if (deduct > 0) {
				totaldeduct = deduct;
				cout << "\nNote: ";
				cin.ignore();
				getline(cin, note2);
				break;
			}
			else {
				break;
			}
		}
		
	}
	else {		
	}
	
	yorn = "n";
	while (1) {
		if ((yorn == "y") || (yorn == "Y"))  //Add another day for same employee
	 	{
	 	
			
		}
		else if ((yorn == "n") || (yorn == "N")) //No more data for the employee in this session.
		{	
			system("cls");
 			revise:	
			cout << "\nReport for: " << employeearray[id-1][2] << endl; //Data generated for employee
			cout << "\nDate" << "\t\tSales" << "\t\tBonus"  << "\t\tCommis." << "\t\tTotal" << endl;  //Report title 
			cout << endl;
			int num_of_lines = 0;
			int sortloop = 1;
			while (sortloop < 32) {									//Sort inputs
				for (int q = 0; q < count; q++) {
					if (dataarray[q][2] == sortloop) {
						if ((dataarray[q][2] < 10) && (dataarray[q][1] < 10)) { //month < 10, day < 10
							cout << dataarray[q][1] << "/" << dataarray[q][2] << "/19" << setw(14)  << dataarray[q][3] << "\t\t" << dataarray[q][4]
							<< "\t\t" << dataarray[q][5] << "\t\t" << dataarray[q][6] << endl;
						}
						else if ((dataarray[q][2] < 10) && (dataarray[q][1] > 9)) { // month > 9, day < 10
							cout << dataarray[q][1] << "/" << dataarray[q][2] << "/19" << setw(13)  << dataarray[q][3] << "\t\t" << dataarray[q][4]
							<< "\t\t" << dataarray[q][5] << "\t\t" << dataarray[q][6] << endl;
						}
						else if ((dataarray[q][2] > 9) && (dataarray[q][1] > 9)) { //month > 9, day > 9
							cout << dataarray[q][1] << "/" << dataarray[q][2] << "/19" << setw(12)  << dataarray[q][3] << "\t\t" << dataarray[q][4]
							<< "\t\t" << dataarray[q][5] << "\t\t" << dataarray[q][6] << endl;
						}
						else if ((dataarray[q][2] > 9) && (dataarray[q][1] < 10)) { //month < 10, day > 9 
							cout << dataarray[q][1] << "/" << dataarray[q][2] << "/19" << setw(13)  << dataarray[q][3] << "\t\t" << dataarray[q][4]
							<< "\t\t" << dataarray[q][5] << "\t\t" << dataarray[q][6] << endl;
						}
						else{
						}
					}
				}
				sortloop++;
			
			}
		
			cout << "\nReport correct? (y/n) "; 									//Report correct y/n?
			cin >> yorn;
			if ((yorn == "y") || (yorn == "Y")) {
			
				ofstream fout;
				fout.open("myData.txt",ios::app); // open file for appending
				fout << "Report for: " << employeearray[id-1][2] << endl; //Data generated for employee	
				fout << endl;				
				fout << "\nDate" << "\t\tSales" << "\t\tBonus"  << "\t\tCommis." << "\t\tTotal" << endl;  //Report title
				fout << endl;
				sortloop = 1;
				while (sortloop < 32) {									//Sort inputs
					for (int q = 0; q < count; q++) {
						if (dataarray[q][2] == sortloop) {
							if ((dataarray[q][2] < 10) && (dataarray[q][1] < 10)) { //month < 10, day < 10
								fout << dataarray[q][1] << "/" << dataarray[q][2] << "/19" << setw(14)  << dataarray[q][3] << "\t\t" << dataarray[q][4]
								<< "\t\t" << dataarray[q][5] << "\t\t" << dataarray[q][6] << endl;
							}
							else if ((dataarray[q][2] < 10) && (dataarray[q][1] > 9)) { // month > 9, day < 10
								fout << dataarray[q][1] << "/" << dataarray[q][2] << "/19" << setw(13)  << dataarray[q][3] << "\t\t" << dataarray[q][4]
								<< "\t\t" << dataarray[q][5] << "\t\t" << dataarray[q][6] << endl;
							}
							else if ((dataarray[q][2] > 9) && (dataarray[q][1] > 9)) { //month > 9, day > 9
								fout << dataarray[q][1] << "/" << dataarray[q][2] << "/19" << setw(12)  << dataarray[q][3] << "\t\t" << dataarray[q][4]
								<< "\t\t" << dataarray[q][5] << "\t\t" << dataarray[q][6] << endl;
							}
							else if ((dataarray[q][2] > 9) && (dataarray[q][1] < 10)) { //month < 10, day > 9 
								fout << dataarray[q][1] << "/" << dataarray[q][2] << "/19" << setw(13)  << dataarray[q][3] << "\t\t" << dataarray[q][4]
								<< "\t\t" << dataarray[q][5] << "\t\t" << dataarray[q][6] << endl;
							}
							else{
							}
						}
					}
					sortloop++;
				}
	
				count1 = count + 10;
			
				for (int q =0; q <count; q++) {
					total += dataarray[q][6];
					totalsales += dataarray[q][3];
					totalbonus += dataarray[q][4];
					totalcommission += dataarray[q][5];
				}
			
				fout << endl;
				if (extrabonus > 0) {
					fout << "* $" << extrabonus << " "<< note1 << endl;
					count1++;
				}
				if (totaldeduct > 0) {
					fout << "* - $" << totaldeduct << " " << note2 << endl;
					count1++;
				}
				fout << "* Rent - $250" << endl;
				totaldeduct = totaldeduct + 250;
				totalbonus = totalbonus + extrabonus;
				total = totalcommission - totaldeduct + totalbonus;
				fout << "\nTotal Sales: " << totalsales << "\t\tTotal Commissions: " << totalcommission << endl;
				fout << "\nTotal Bonuses: " << totalbonus << "\t\tDeductions: " << totaldeduct << endl;
				fout << "\nTotal: " << total << endl;  //Report title 
				while (count1 < 51 ) {
					fout << endl;
					count1++;
				}
				fout.close( ); //close file
				;								
				cout << "\nReport sent to file MyData.txt successfully" << endl;
				
				cout << "\nTo Enter Another Employee Data Press Y, N to End Program: ";
				cin >> yorn;
				if ((yorn == "Y") || (yorn == "y")) {
					extrabonus = 0;
					totaldeduct = 0;
					totalsales = 0;
					totalcommission = 0;
					totalbonus = 0;
					total = 0;
					for (int q = 0; q < count; q++) {
						dataarray[q][2] = 0;
						dataarray[q][3] = 0;
						dataarray[q][4] = 0;
						dataarray[q][5] = 0;
						dataarray[q][6] = 0;
	
					}
					goto employee;
				}
				else if ((yorn == "n") || (yorn == "N")) {
					exit(0);
				}
			}
			else if ((yorn == "n") || (yorn == "N")) { 						// If report is not correct.
				cout << "\nEnter day you would like to revise: ";
				cin >> d1;
				
				for (int q=0; q < count; q++) {
					if (dataarray[q][2] == d1) {
						cout << "\nDate: " << dataarray[q][1] << "/" << dataarray[q][2] << "/19" << endl; 	//Date.
						cout << "\nEnter Daily Sales: "; // Daily sales.										//Daily sales revision
						cin >> damount;
						while (1) {						//Daily Sales.
							cin.clear();
							cin.ignore(10000, '\n');
							if (damount > 0) {
								dataarray[q][3] = damount;
								break;
							}
							else  {
								cout << "Sales Must Greater Than 0." << endl; 
								cout << "\nEnter Daily Sales: ";
								cin >> damount;
							} 
						} // end while sales
						
						if ((c1.compare(c2)) == 0) {  //IF EMPLOYEE TYPE 0
							if ((dataarray[q][3] > 0) && (dataarray[q][3] < 600)) { //damount 25%
								dataarray[q][5] = 0.25 * dataarray[q][3];
							}
							else if ((dataarray[q][3] > 599) && (dataarray[q][3] < 1000))  { //damount 28%
								dataarray[q][5] = 0.28 * dataarray[q][3];
							}
							else if (dataarray[q][3] > 999) { 				//damount 30%
								dataarray[q][5] = 0.30 * dataarray[q][3];
								dataarray[q][4] = 0;
								if ((dataarray[q][3] > 1599) && (dataarray[q][3] < 2000)) { //dbonus #1
									dataarray[q][4] = dataarray[q][4] + 100;
								}
								else if ((dataarray[q][3] > 1999) && (dataarray[q][3] < 3000)) { //dbonus #2
									dataarray[q][4] = dataarray[q][4] + 200;
								}
								else if (dataarray[q][3] > 2999) {								//dbonus #3
								dataarray[q][4] = dataarray[q][4] + 300;
								}
								else {
								}
							}
							else {
							}
						}
						else if ((c1.compare(c3)) == 0) { 									//If employee type 1
							dataarray[q][5] = 0.30 * damount;
							dataarray[q][4] = 0;
							if ((dataarray[q][3] > 1599) && (dataarray[q][3] < 2000)) { 		//dbonus #1
								dataarray[q][4] = dataarray[q][4] + 100;
							}
							else if ((dataarray[q][3] > 1999) && (dataarray[q][3] < 3000)) { //dbonus #2
								dataarray[q][4] = dataarray[q][4] + 200;
							}
							else if (dataarray[q][3] > 2999) {									//dbonus #3
								dataarray[q][4] = dataarray[q][4] + 300;
							}
							else {
							}
						}
						else {	
						}
						dataarray[q][6] = dataarray[q][5] + dataarray[q][4];

						goto revise;
					} // end Big if
				}
			}
		}
		
		
	 }


	data.close();
}

void mainfind() {
	find();
	string id;
	cout << "Type back to go to main menu." << endl;
	cout << "Press any key to find another profile." << endl;
	cin >> id;
	system("cls");
	
	if (id == "back") {
		whattodo(); 
	}
	else {
		mainfind();
		find();
	}
}

