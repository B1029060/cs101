#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ReplaceMyString {
    private:
        string str;
    public:
        ReplaceMyString() {
            str = "IU";
        }
        replaceString(string origin, string alter) {
            cout << "Old one : " << str ;
            if (origin == str) str = alter;
            cout << " -> New one : " << str << endl;
        }
};

int main() {
    ReplaceMyString my;
    my.replaceString("IU", "IU is best");
    my.replaceString("IU is best", "IU is best is best");
    return 0;
}
