#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

class ItemTracker {
    private:
        map<string, int> frequency;

    public:
        ItemTracker() {
            ifstream infile("CS210_Project_Three_Input_File.txt");
            string item;
            while (infile >> item) {
                frequency[item]++;
            }
        }

        int getFrequency(string item) {
            return frequency[item];
        }

        void printList() {
            for (auto const& [item, count] : frequency) {
                cout << item << " " << count << endl;
            }
        }

        void printHistogram() {
            for (auto const& [item, count] : frequency) {
                cout << item << " ";
                for (int i = 0; i < count; i++) {
                    cout << "*";
                }
                cout << endl;
            }
        }

        void backupData() {
            ofstream outfile("frequency.dat");
            for (auto const& [item, count] : frequency) {
                outfile << item << " " << count << endl;
            }
        }
};

int main() {
    ItemTracker tracker;

    while (true) {
        cout << "Menu Options:" << endl;
        cout << "1. Look up item frequency" << endl;
        cout << "2. Print list of item frequencies" << endl;
        cout << "3. Print histogram of item frequencies" << endl;
        cout << "4. Exit program" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string item;
                cout << "Enter item to look up frequency: ";
                cin >> item; // Read item from user
                cout << "Frequency of " << item << ": " << tracker.getFrequency(item) << endl;
                break;
            }
            case 2: {
                tracker.printList();
                tracker.backupData();
                break;
            }
            case 3: {
                tracker.printHistogram();
                tracker.backupData();
                break;
            }
            case 4: {
                tracker.backupData();
                return 0;
            }
            default: {
                cout << "Invalid choice, please try again." << endl;
                break;
            }
        }
    }

    return 0;
}
