#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct sort_second {
	bool operator()(const pair<string,int> &left, const pair<string,int> &right) {
        return left.second < right.second;
    }
};

void readCsv(ifstream &inFile, vector<pair<string,int>> *records);

void mainMenu(vector<pair<string,int>> *records);

void upcomingMaintenance(vector<pair<string,int>> *records);
void allRecords(vector<pair<string,int>> *records);
void updateRecord(vector<pair<string,int>> *records);
void addRecord(vector<pair<string,int>> *records);
void deleteRecord(vector<pair<string,int>> *records);

int main() {
	ifstream recordsIn;
	recordsIn.open("records.list");
	vector<pair<string, int>> *records = new vector<pair<string,int>>();
	readCsv(recordsIn, records);

	recordsIn.close();
	ofstream recordsOut("records.list");

	mainMenu(records);

	for(vector<pair<string, int>>::iterator it = records->begin(); it != records->end(); it++) {
		recordsOut << it->first << "," << it->second << endl;
	}
	recordsOut.close();
	return 0;
}

void readCsv(ifstream &inFile, vector<pair<string,int>> *records) {
	string line;
    while(getline(inFile, line)) {
        size_t pos = line.find(",");
		records->push_back(make_pair(line.substr(0,pos), atoi(line.substr(pos+1).c_str())));
    }
}

void mainMenu(vector<pair<string,int>> *records) {
    int choice;
	void (*options[5])(vector<pair<string,int>> *records);
	
	options[0] = upcomingMaintenance;
	options[1] = allRecords;
	options[2] = updateRecord;
	options[3] = addRecord;
	options[4] = deleteRecord;

    do {
        cout << "Main Menu" << endl << "Choose one of the options below and then hit ENTER. Or press 0 + ENTER to exit" << endl;
        cout << "1. Upcoming Maintenance Required" << endl;
        cout << "2. All Maintenance Records" << endl;
        cout << "3. Update Maintenance Record" << endl;
        cout << "4. Add Maintenance Record" << endl;
        cout << "5. Delete Maintenance Record" << endl << endl;
        cin >> choice;
    } while(choice < 0 || choice > 5);
	if(choice > 0 && choice < 6) options[choice-1](records);
}

void upcomingMaintenance(vector<pair<string,int>> *records) {
	sort(records->begin(), records->end(), sort_second());
	if(records->size() >= 5) {
		for(int i = 0; i < 5; i++) {
			cout << endl << records->at(i).second << "\t" << records->at(i).first;
		}
	}
	else {
		for(vector<pair<string, int>>::iterator it = records->begin(); it != records->end(); it++) {
			cout << endl << it->second << "\t" << it->first;
		}
	}
	cout << endl << endl << "Press 1 to go back to Main Menu. Press any other key + ENTER to exit." << endl;	
	int choice;
	cin >> choice;
	if(choice == 1) mainMenu(records);
}
void allRecords(vector<pair<string,int>> *records) {
	sort(records->begin(), records->end());
	if(records->size() >= 5) {
		for(int i = 0; i < 5; i++) {
			cout << endl << records->at(i).second << "\t" << records->at(i).first;
		}
	}
	else {
		for(vector<pair<string, int>>::iterator it = records->begin(); it != records->end(); it++) {
			cout << endl << it->second << "\t" << it->first;
		}
	}
	cout << endl << endl << "Press 1 to go back to Main Menu. Press any other key + ENTER to exit." << endl;	
	int choice;
	cin >> choice;
	if(choice == 1) mainMenu(records);
}
void updateRecord(vector<pair<string,int>> *records) {
	cout << "update" << endl;
	cout << endl << "Press 1 to go back to Main Menu. Press any other key + ENTER to exit." << endl;	
	int choice;
	cin >> choice;
	if(choice == 1) mainMenu(records);
}
void addRecord(vector<pair<string,int>> *records) {
	string name;
	int miles;
	cout << "Type the name of the maintenance being performed and then hit ENTER" << endl;
	getline(cin.ignore(), name);
	cout << "Type the number of miles at which the maintenance needs to be performed next and then hit ENTER" << endl;
	cin >> miles;
	records->push_back(make_pair(name, miles));
	cout << "Maintenance record successfully added..." << endl;
	cout << endl << "Press 1 to go back to Main Menu. Press any other key + ENTER to exit." << endl;	
	int choice;
	cin >> choice;
	if(choice == 1) mainMenu(records);
}
void deleteRecord(vector<pair<string,int>> *records) {
	cout << "delete" << endl;
	cout << endl << "Press 1 to go back to Main Menu. Press any other key + ENTER to exit." << endl;	
	int choice;
	cin >> choice;
	if(choice == 1) mainMenu(records);
}
