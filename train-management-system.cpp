#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX_TRAINS = 100;
const int MAX_SEATS = 100;

struct Railway {
    string tname;
    int tnumber;
    int seatf;
    int faref;
    int seats;
    int fares;
    string from;
    string to;
    int distance;
};

struct User {
	int number;
    string name;
    string contact;
    int seats;
    string from;
    string to;
    double bill;
    
};

Railway trains[MAX_TRAINS];
User passengers[MAX_TRAINS];

int userCount = 1;
int trainCount = 1; // index starting from one for convenience

void allTrains() {
	if (trains[1].tnumber != 0){
    cout << "\n\t ~~Total trains are following~~ \n" << endl;
    for (int i = 1; i <= trainCount; i++) {
        if (trains[i].tnumber != 0) {
        	cout<<"\n\t";
            cout << "| Train No." << "\t" << "| Train Name" << "\t" << "| Boarding pt." << "\t" << "| Destination " << "\t";
            cout << "| F-Class" << "\t" << "| F-Class Fare" << "\t" << "| S-Class" << "\t" << "| S-Class Fare" << "\n";

            cout << "\t|" << trains[i].tnumber << "\t\t" << "|" << trains[i].tname << "\t\t" << "|" << trains[i].from << "\t\t" << "|" << trains[i].to << "\t\t";
            cout << "|" << trains[i].seatf << "\t\t" << "|" << trains[i].faref << "\t\t" << "|" << trains[i].seats << "\t\t" << "|" << trains[i].fares << "\n";
        }
    }
} 
else{ cout<<"\n\t no trains currently Added \n\n\n"<<endl;
}
}

void deleteTrain(void){
	
	allTrains();
	cout<<endl;
	int k;
	if (trains[1].tnumber != 0){
	cout<<"enter train number you want to delete"<<endl;
	cin>>k;
	if (k!=0 && k<=trainCount){
	
	for(int i=k;i<trainCount;i++){
		trains[i].tnumber=trains[i+1].tnumber;
		
	}
	int v=0;
        trains[trainCount].tnumber=v;
		trainCount=trainCount-1;
	cout<<"\n Train number : "<<k<<" Deleted successfully \n";
}
	else{
		cout<<" \n That train is not Available\n";
	}
}
else {
	cout<<"\n No train Added currently \n";
}
}
void changeFare() {
	if (trains[1].tnumber != 0) {
    allTrains();
    
    cout << "\n\t ~~Enter train number of which you want to change fare:~~ \n";
    int k;
    cin >> k;
    if (trains[k].tnumber != 0) {
        int h, m;
        cout << "\n ~~ Old fare of first class: \n" << trains[k].faref << endl;
        cout << "\n ~~ Old fare of second class: \n" << trains[k].fares << endl;
        cout << "\n ~~ Enter new price for first class: \n";
        cin >> h;
        trains[k].faref = h;
        cout << "\n ~~ Enter new price for second class:  \n";
        cin >> m;
        trains[k].fares = m;
        cout << "\n\t ~~ Fare change successfully : ~~ \n";
        cout << "\n ~~ New fare of first class: " << trains[k].faref << endl;
        cout << "\n ~~ New fare of second class: " << trains[k].fares << endl;
    }
    else {
        cout << "\n\t sorry ! that train is not available \n" << endl;
    }
}
   	else{ cout<<" \n\t trains are not available \n\n"<<endl;
}
}

void changeSeats() {
	if (trains[1].tnumber != 0) {
    allTrains();
    int h, m;
    cout << "\n\t Enter train number of which you want to change seat: ";
    int number;
    cin >> number;
    if (trains[number].tnumber != 0) {
        cout << "\n Old seats of first class: " << trains[number].seatf << endl;
        cout << "\n Old seats of second class: " << trains[number].seats << endl;
        cout << "\n Enter new seats for first class: ";
        cin >> h;
        trains[number].seatf = h;
        cout << "\n Enter new seats for second class: ";
        cin >> m;
        trains[number].seats = m;
        cout << "\n\t Seats change successfully\n";
    }
    else {
        cout << "\n\t sorry ! that train is not available " << endl;
    }
    }
   	else{ cout<<"\n\t trains are not available\n\n"<<endl;
}
}

void addTrain() {
    allTrains();

    if (trainCount < MAX_TRAINS) {
        cout << "\n\t--Add New Train Details--\n\n";
        cout << "Train number: is " << trainCount << endl;
        trains[trainCount].tnumber = trainCount;

        cout << "Train name: ";
        cin >> trains[trainCount].tname;

        cout << "Boarding point: ";
        cin >> trains[trainCount].from;

        cout << "Destination point: ";
        cin >> trains[trainCount].to;

        cout << "No of seats in first class: ";
        cin >> trains[trainCount].seatf;

        cout << "No of seats in second class: ";
        cin >> trains[trainCount].seats;

        cout << "Fare per ticket for first class: ";
        cin >> trains[trainCount].faref;

        cout << "Fare per ticket for second class: ";
        cin >> trains[trainCount].fares;

        trainCount++;
        cout << "\n\t Train added successfully\n";
    }
    else {
        cout << "\n\t Maximum number of trains reached. Cannot add more trains.\n";
    }
}

void booking() {
	if (trains[1].tnumber != 0) {
    allTrains();
    int k, j, p;
    cout << "\n\t Welcome to the train booking menu\n";
    cout << "Enter train number: ";
    cin >> k;

    if (trains[k].tnumber != 0) {
        cout << "Enter 1 for first class  \n  enter  2 for 2nd class ";
        cin >> p;
        cout << "Enter how many seats you want to book: ";
        cin >> j;

        switch (p) {
        case 1:
            if (trains[k].seatf >= j) {
                trains[k].seatf = trains[k].seatf - j;
                cout<< " \n\t you are user number : " << userCount<< endl;
                		passengers[userCount].number=userCount;
                cout << "Enter your name: ";
                
                cin >> passengers[userCount].name;
                cout << "Enter your contact number: ";
                cin >> passengers[userCount].contact;
                passengers[userCount].seats = j;
                passengers[userCount].from = trains[k].from;
                passengers[userCount].to = trains[k].to;

                passengers[userCount].bill += j * trains[k].faref;

                cout << "\n\t Booking successful | Your total bill is: RS " << passengers[userCount].bill << endl;
                userCount++;
            }
            else {
                cout << "\n\t Sorry: " << j << " Seats not available" << endl;
                cout << "\n Only " << trains[k].seatf << " seats are available" << endl;
            }
            break;

        case 2:
            if 		(trains[k].seats >= j) {
               		 trains[k].seats = trains[k].seats - j;
                cout<< " \n\t you are user number : " << userCount<< endl;
                		passengers[userCount].number=userCount;
                cout<< "Enter your name: ";
                cin >> passengers[userCount].name;
                cout<< "Enter your contact number: ";
                cin >> passengers[userCount].contact;
                	passengers[userCount].seats = j;
                	passengers[userCount].from = trains[k].from;
                	passengers[userCount].to = trains[k].to;
                	passengers[userCount].bill += j * trains[k].fares;

                cout<< "\n\t Booking successful | Your total bill is: RS " << passengers[userCount].bill << endl;
                userCount++;
            }
            else {
                cout << "\n\t Sorry: " << j << " Seats not available ";
                cout << "\n\t Only " << trains[k].seats << " seats are available ";
            }
            break;

        default:
            cout << "\n\t Invalid class choice. Please enter 1 or 2.\n";
            break;
        }
    }
    else {
        cout << "\n\t sorry ! that train is not available" << endl;
    }
}
   	else{ cout<<"\n\t trains are not available"<<endl;
}
}
void seePassenger() {
    cout << "\n\t~~ User Details ~~\n\n";
    for (int i = 1; i < userCount; i++) {
    	cout << "\n\t user number : "<<passengers[i].number<<endl;
        
        cout << "Name: "<<passengers[i].name<<endl;
        cout << "Contact: "<<passengers[i].contact<<endl;
        cout << "Seats Booked: "<<passengers[i].seats<<endl;
        cout << "Boarding Point: " <<passengers[i].from<<endl;
        cout << "Destination Point: " <<passengers[i].to<<endl;
        cout << "Total Bill: RS " <<passengers[i].bill<<endl;
    }
}


void registerCustomer() {
    ofstream file("users.txt", ios::app);
    if (!file.is_open()) {
        cout << "\n\t Error opening file for writing.\n";
        return;
    }

    string username, password;

    cout << "Enter a username: ";
    cin >> username;

    ifstream checkFile("users.txt");
    string line;
    while (getline(checkFile, line)) {
        if (line.substr(0, line.find(',')) == username) {
            cout << "\n\t Username already exists. please choose  different username. \n";
            return;
        }
    }

    cout<<"Enter a password: ";
    cin>> password;

    file<<username<<','<<password << '\n';

    cout << "\n\t Registration successful!\n\n";
}

bool authenticateUser(const string& filename, const string & username,const string& password) {
    ifstream file("users.txt");
    if (!file.is_open()) {
        cout << "\n\t Error opening file for reading.\n";
        return false;
    }

    string line;
    while (getline(file, line)) {
        size_t pos = line.find(',');
        string storedUsername = line.substr(0, pos);
        string storedPassword = line.substr(pos + 1);

        if (storedUsername == username && storedPassword == password) {
            return true;
        }
    }

    return false;
}

bool customerLogin() {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    if (authenticateUser("users.txt",username,password)) {
        cout << "\n\t Login successful!\n";
        return true;
    } else {
        cout << "\n\t Invalid username or password. Please try again.\n";
        return false;
    }
}

void usercredentials() {
    ifstream file("users.txt");
    if (!file.is_open()) {
        cout << "\n\t Error opening the file." << endl;
    }

    string line;
    int i = 1;
    while (getline(file, line)) {
        size_t pos = line.find(',');
        string storedUsername=line.substr(0, pos);
        string storedPassword =line.substr(pos + 1);
        cout<<"user "<<i<<endl;
        i++;
        cout<<line<<endl;
    }
    file.close();
}



int main() {
    int choice1;

    do {
        cout <<"\n\n\t\t--- Train Management System ---\n";
        cout <<"\n \t 1  Admin"<<endl;
        cout <<"\n \t 2  User"<<endl;
        cout <<"\n \t 0  Exit "<<endl;
        cout <<"\n \t Enter the Choice : ";
        cin >> choice1;

        switch (choice1) {
        case 1: {
            
                cout << "\n\n\t\t ***------------------Admin-----------------***" << endl;
                int password;
                cout << "\n\t Enter the password : ";
                cin >> password;
                if (password == 123456) {
                    int choice2;
                    do {
                        cout << "1. Display all trains\n";
                        cout << "2. Add new train\n";
                        cout << "3. Change seats\n";
                        cout << "4. Change fare\n";
                        cout << "5. Delete Train \n";
                        cout << "6. display all passenger \n ";
                        cout << "7. display user credintials\n";
                        
                        
                        cout << "0. Exit\n";
                        cout << "\n\t Enter your choice: ";
                        cin >> choice2;

                        switch (choice2) {
                        case 1:
                            allTrains();
                            break;
                        case 2:
                            addTrain();
                            break;
                        case 3:
                            changeSeats();
                            break;
                        case 4:
                            changeFare();

                            break;
                        case 5:
                        	deleteTrain();
                            
                            break;
						case 6: 
							seePassenger();
							break;
						case 7:
							usercredentials();
							break;
                        case 0:
                            cout << "\n\n\t\t Exiting the program. Goodbye!\n";
                            break;
                        default:
                            cout << "\n\t Invalid choice. Please enter a valid option.\n";
                        }
                    }

                    while (choice2 != 0);
                } else {
                    cout << "\n\t INVALID PASSWORD : ";

                }
                break;
            }

        case 2:
            cout << "\n\n\t\t ***------------------USER-----------------***" << endl << endl;
            int s;
            cout << "\n\t\t 1)----------------------LOGIN-----------------\n " << endl << endl;
            cout << "\n\t\t 2)---------------------Register---------------\n" << endl;
            cin >> s;
            switch (s) {
            case 1: {
                bool loggedIn = customerLogin();
                if (loggedIn) {
                    int choice3;
                    do {
                        cout<< "1. View available trains.\n";
                        cout<< "2. Book ticket.\n";
                        cout<< "0. Exit menu.\n ";
                        cin >> choice3;

                        switch (choice3) {
                        case 1:
                            allTrains();
                            break;
                        case 2:
                            booking();
                            break;
                        case 0:
                            cout << "\n\t Exiting the program. Goodbye!\n";
                            break;
                        default:
                            cout << "\n\t Invalid choice. Please enter a valid option.\n";
                            break;
                        }
                    } while (choice3 != 0);
                    break;
                }
                break;
            }
            case 2:
                registerCustomer();
                break;
            }
            break;

        case 0: {
            break;

            cout << "\n\tExiting the program. Goodbye!\n";
            break;
        }

        default:
            cout << "\n\t Invalid choice. Please enter a valid option.\n";
        }

    } while (choice1 != 0);

    return 0;
}

