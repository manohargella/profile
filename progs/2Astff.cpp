#include <iostream>
#include <string>
using namespace std;
class Staff {
    protected:
        int StaffId;
        string Name;
        string Phone;
        float Salary;
    public:
        Staff() {}
        Staff(int id, string name, string phone, float salary) {
            StaffId = id;
            Name = name;
            Phone = phone;
            Salary = salary;
        }
        void display() {
            cout << "Staff ID: " << StaffId << endl;
            cout << "Name: " << Name << endl;
            cout << "Phone: " << Phone << endl;
            cout << "Salary: " << Salary << endl;
        }
};
class Teaching : public Staff {
    private:
    string domain;
    int publications;
    public:
        Teaching() {}
        Teaching(int id, string name, string phone, float salary, string d, int pub) : Staff(id, name, phone, salary) {
            domain = d;
            publications = pub;
        }
    void display() {
        Staff::display();
        cout << "Domain: " << domain << endl;
        cout << "Publications: " << publications << endl;
    }
};
class Technical : public Staff {
private:
    string skills;
    public:
        Technical() {}
        Technical(int id, string name, string phone, float salary, string s) : Staff(id, name, phone, salary) {
            skills = s;
        }
        void display() {
            Staff::display();
            cout << "Skills: " << skills << endl;
        }
};
class Contract : public Staff {
    private:
        int period;
        public:
        Contract() {}
        Contract(int id, string name, string phone, float salary, int p) : Staff(id, name, phone, salary) {
            period = p;
        }
        void display() {
            Staff::display();
            cout << "Period: " << period << endl;
        }
};

int main() {
    Teaching t1(1, "Manohar", "7981538699", 60000, "Computer Science", 20);
    Technical t2(2, "Surya", "88092347121", 55000, "C++, Java");
    Contract t3(3, "Sai Raju", "696969697", 50000, 6);
    cout << "Teaching Staff 1" << endl;
    t1.display();
    cout << endl;
    cout << "Technical Staff 2" << endl;
    t2.display();
    cout << endl;
    cout << "Contract Staff 3" << endl;
    t3.display();
    cout << endl;
    return 0;
}