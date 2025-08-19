#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Customer {
    private:
        string name;
        int day, month, year;
        public:
            Customer() {}
            Customer(string n, int d, int m, int y) {
                name = n;
                day = d;
                month = m;
                year = y;
            }

    void readData() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter date of birth (dd/mm/yyyy): ";
        string dob;
        getline(cin, dob);
        stringstream ss(dob);
        char delimiter;
        ss >> day >> delimiter >> month >> delimiter >> year;
    }

    void displayData() {
        cout << "Name: " << name << endl;
        cout << "Date of birth: " << day << "/" << month << "/" << year << endl;
    }

};

int main() {
    Customer c1;
    c1.readData();
    cout << endl;
    cout << "Customer 1" << endl;
    c1.displayData();
    return 0;
}