#include <iostream>
#include <fstream>
#include <ctime>
#include <string.h>
using namespace std;


void filebug(int id)
{
	cout<<"\n********** FILING A BUG ***********\n";

	
	time_t CurrentTime;
	time(&CurrentTime);

	char name[20];
	string bugtype, bugpriority, bugdescription;
	int j;


	cout<<"Enter your name:\n";
	cin>>name;
	cin.ignore();
	char ids[10];
	itoa(id, ids, 10);
	strcat(name, ids);
	char ex[] = ".txt";
	strcat(name, ex);


	cout<<"Filename : "<<name<<endl;
	ofstream fout(name);   //vishal.txt

	
	fout<<"DATE AND TIME: "<<ctime(&CurrentTime);

	
	fout<<"BUG ID : "<< id<<endl<<endl;

	
	cout<<"BUG ID: "<<id<<endl;

	fout<<"BUG FILED BY: "<<name<<endl<<endl;

	cout<<"Enter bug type:\n";
	getline(cin, bugtype);
	cin.ignore();
	

	
	fout<<"TYPE OF BUG: "<<bugtype<<endl<<endl;

	
	cout<<"Enter bug priority:\n";
	getline(cin, bugpriority);
	cin.ignore();
	

	cout<<"Enter the bug description:"<<endl;
	getline(cin,bugdescription);
	cin.ignore();

	fout<<"BUG PRIORITY: "<<bugpriority<<endl<<endl; 
	fout<<"BUG DESCRIPTION: "<<bugdescription<<endl<<endl;
	
	
	fout<<"DATE AND TIME: "<<ctime(&CurrentTime);
	fout<<"BUG STATUS: ";


	cout<<"\nStatus of bug:\n";
	cout<<" 1.NOT YET ASSIGNED\n";
	cout<<" 2.IN PROCESS\n 3.FIXED\n";
	cout<<" 4.DELIVERED\n ENTER YOUR CHOICE : ";

	cin>>j; 

	// change Status of the Bug
	switch (j) {
	case 1:
		fout<<"NOT YET ASSIGNED\n";
		break;
	case 2:
		fout<<"IN PROCESS\n";
		break;
	case 3:
		fout<<"FIXED\n";
		break;
	case 4:
		fout<<"DELIVERED\n";
		break;
	default:
		cout<<" invalid choice\n";
		break;
	}

	fout.close();
}



// Function to Change the status of the Bug
void changestatus()
{
	int k;
	cout<<"************* Change status **************\n";

	
	time_t CurrentTime;
	time(&CurrentTime);

	char name[50];

	
	cout<<"Enter file name:\n";
	cin>>name;
	char ex[] = ".txt";
	strcat(name, ex);

	
	ofstream fout(name, ios_base::app);


	// Change the Status
	cout<<"\n 1.NOT YET ASSIGNED\n";
	cout<<" 2.IN PROCESS\n 3.FIXED\n";
	cout<<" 4.DELIVERED\n ENTER YOUR CHOICE:";
	
	cin>>k;

	fout<<"\nDATE AND TIME : "<<ctime(&CurrentTime);
	fout<<"BUG STATUS: ";

	// Changing the status on the basis of the user input

	switch (k) {
	case 1:
		fout<<"NOT YET ASSIGNED\n";
		break;
	case 2:
		fout<<"IN PROCESS\n";
		break;
	case 3:
		fout<<"FIXED\n";
		break;
	case 4:
		fout<<"DELIVERED\n";
		break;
	default:
		cout<<" invalid choice\n";
		break;
	}
	fout.close();
}


void report()
{
	cout<<"********** REPORT **********\n";
	char name[50];

	cout<<"Enter file name:\n";
	cin>>name;
	char ex[] = ".txt";
	strcat(name, ex);


	cout<<endl;

	ifstream fin(name);

	string line;

	fin.seekg(0, ios::beg);
	while(fin){
		getline(fin,line);
		cout<<line<<endl;
	}

	fin.close();
	
}


int main()
{
	int number, i = 1;

	int id = 0;


	while (i != 0) {
		cout<<"\n*************** BUG TRACKING SYSTEM ***************\n";
		cout<<"\n 1. FILE A NEW BUG\n";
		cout<<" 2. CHANGE THE STATUS OF THE BUG\n";
		cout<<" 3. GET BUG REPORT\n 4. EXIT";
		cout<<"\n\n ENTER YOUR CHOICE : ";

		cin>>number;

		switch (number) {
		case 1:
			id++;

			filebug(id);
			break;
		case 2:

			changestatus();
			break;
		case 3:

			report();
			break;
		case 4:
			i = 0;
			break;
		default:
			cout<<"\n invalid entry..";
			break;
		}
	}
	return 0;
}
