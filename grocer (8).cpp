#include <iostream> 
#include <fstream>
#include <unordered_map> 
#include <string> 
#include <iomanip> 

using namespace std;

class CornerGrocer {

public: // Constructor 
	
	CornerGrocer() {
	LoadDataFromFile("CS210_Project_Three_Input_File.txt");
	}
	// Load data from file into an unordered_map 
	void LoadDataFromFile(const string& fileName) {
	
		ifstream inFile(fileName);
		if (inFile.is_open()) {
			string item;
			while (inFile >> item) {
				itemFrequency[item]++;
			}
			inFile.close();
		}
		else {
			cerr << "Error: Unable to open file " << " " << endl;
	}
}

void GetFrequencyOfItem() const {
		string item;
		cout << "Enter item to search: ";
		cin >> item;
		auto it = itemFrequency.find(item);
		if (it != itemFrequency.end()) {
			cout << "The item '" << item << "' appears " << it->second << " times." << endl;
		}
		else {
			cout << "The item '" << item << "' was not found." << endl;
		}
	}

void PrintAllItemsFrequency() const {
		for (const auto& pair: itemFrequency) { 
			cout << pair.first << " " << pair.second << endl; 
		 
	}
}
void PrintHistogram() const {
	for (const auto& pair : itemFrequency) {
		cout << setw(15) << left << pair.first << " ";
		for (int i = 0; i < pair.second; ++i) {
			cout << "*";
		}
		cout << endl;
	}
}
private: 
	unordered_map<string, int> itemFrequency;
	}; 
	int main() {
		CornerGrocer grocer;
		int choice;

		do {
			cout << "\nMenu:\n";
			cout << "1. Search for an item\n";
			cout << "2. Print all item frequencies\n";
			cout << "3. Print histogram of all items\n";
			cout << "4. Exit\n"; cout << "Enter your choice: ";
			cin >> choice;

			switch (choice) {
			case 1:
				grocer.GetFrequencyOfItem();
				break;
			case 2:
				grocer.PrintAllItemsFrequency();
				break;
			case 3:
				grocer.PrintHistogram();
				break;
			case 4:
				cout << "Exiting the program." << endl;
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
			}
		} while (choice != 4);

		return 0;
	}