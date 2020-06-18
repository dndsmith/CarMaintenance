#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

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
	//for(vector<pair<string, int>>::iterator it = records->begin(); it != records->end(); it++) {
	//	cout << it->first << "\t" << it->second << endl;
	//}
	//ofstream recordsOut("records.list");
	//recordsOut.close();
	mainMenu(records);
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
        cout << "Main Menu" << endl << "Choose one of the options below" << endl;
        cout << "1. Upcoming Maintenance Required" << endl;
        cout << "2. All Maintenance Records" << endl;
        cout << "3. Update Maintenance Record" << endl;
        cout << "4. Add Maintenance Record" << endl;
        cout << "5. Delete Maintenance Record" << endl << endl;
        cin >> choice;
    } while(choice < 1 || choice > 5);
	options[choice-1](records);
}

void upcomingMaintenance(vector<pair<string,int>> *records) {
	cout << "upcoming" << endl;
}
void allRecords(vector<pair<string,int>> *records) {
	cout << "all" << endl;
}
void updateRecord(vector<pair<string,int>> *records) {
	cout << "update" << endl;
}
void addRecord(vector<pair<string,int>> *records) {
	cout << "add" << endl;
}
void deleteRecord(vector<pair<string,int>> *records) {
	cout << "delete" << endl;
}
