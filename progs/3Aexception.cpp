#include <iostream>
#include <exception>
using namespace std;
class DivideByZeroException : public exception {
 public:
    const char* what() const throw() {
        return "Division by zero exception";
    }
};

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    try {
        if (b == 0) {
            throw DivideByZeroException();
        } else {
            cout << "Result: " << (double)a/b << endl;
        }
    } catch (DivideByZeroException& e) {
        cout << e.what() << endl;
    }
    return 0;
}