#include <iostream>
#include <string>
using namespace std;


class Student{
    public:
    string USN;
    string Name;
    string Programme;
    string Phone;
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    Student *s = new Student[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter USN, Name, Programme, and Phone of student " << i + 1 << ": ";
        cin >> s[i].USN >> s[i].Name >> s[i].Programme >> s[i].Phone;
    }
    cout << "\nDetails of students: \n";
    cout << "USN\t\tName\t\tProgramme\t\tPhone\n";
    for (int i = 0; i < n; i++) {
        cout << s[i].USN << "\t\t" << s[i].Name << "\t\t" << s[i].Programme << "\t\t" << s[i].Phone << endl;
    }
 return 0;
}