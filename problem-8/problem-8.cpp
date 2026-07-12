#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class String {
private:
    char* str;

public:

    // Constructor
    String(const char* s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Copy Constructor
    String(const String& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Assignment Operator
    String& operator=(const String& other) {

        if (this != &other) {

            delete[] str;

            str = new char[strlen(other.str) + 1];

            strcpy(str, other.str);
        }

        return *this;
    }

    // Concatenation
    String operator+(const String& other) {

        char* temp = new char[strlen(str) + strlen(other.str) + 1];

        strcpy(temp, str);
        strcat(temp, other.str);

        String result(temp);

        delete[] temp;

        return result;
    }

    // Comparison
    bool operator==(const String& other) {
        return strcmp(str, other.str) == 0;
    }

    // Reverse
    void reverse() {

        int n = strlen(str);

        for (int i = 0; i < n / 2; i++) {

            char temp = str[i];
            str[i] = str[n - i - 1];
            str[n - i - 1] = temp;
        }
    }

    // Vowel Count
    void countVowels() {

        int count = 0;

        for (int i = 0; str[i] != '\0'; i++) {

            char ch = tolower(str[i]);

            if (ch == 'a' || ch == 'e' ||
                ch == 'i' || ch == 'o' ||
                ch == 'u')
                count++;
        }

        cout << "Vowels = " << count << endl;
    }

    // Uppercase
    void toUpperCase() {

        for (int i = 0; str[i] != '\0'; i++) {

            str[i] = toupper(str[i]);
        }
    }

    void display() {
        cout << str << endl;
    }
};

int main() {

    char s1[100], s2[100];

    cout << "Enter First String: ";
    cin.getline(s1, 100);

    cout << "Enter Second String: ";
    cin.getline(s2, 100);

    String A(s1);
    String B(s2);

    String C;

    // Assignment Operator
    C = A;

    cout << "\nAssignment:\n";
    C.display();

    // Concatenation
    C = A + B;

    cout << "\nConcatenation:\n";
    C.display();

    // Comparison
    if (A == B)
        cout << "\nStrings are Equal\n";
    else
        cout << "\nStrings are Not Equal\n";

    // Reverse
    A.reverse();

    cout << "\nReverse First String:\n";
    A.display();

    // Vowel Count
    cout << "\n";
    B.countVowels();

    // Uppercase
    B.toUpperCase();

    cout << "\nUppercase Second String:\n";
    B.display();

    return 0;
}
