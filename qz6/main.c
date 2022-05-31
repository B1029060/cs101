#include <iostream>
#include <string>

using namespace std;


class Clock {
    protected:
        int hr;
        int min;
        int sec;
        string meridiem;
    public:
        Clock(int h, int m, int s, string mrd) {
            hr = h;
            min = m;
            sec = s;
            meridiem = mrd;
        }
        void display() {
            cout << hr << ':' << min << ':' << sec << ' ' << meridiem << endl;
        }
};
class Standard {
    public:
        int hr;
        int min;
        int sec;
        string meridiem;
        Standard(int h, int m, int s, string mrd) {
            hr = h;
            min = m;
            sec = s;
            meridiem = mrd;
        }
        void display() {
            if (meridiem == "AM") {
                cout << "早上" << ' ' << hr << ':' << min << ':' << sec << endl;
            } else if (meridiem == "PM") {
                cout << "下午" << ' ' << hr << ':' << min << ':' << sec << endl;
            }
        }
};
class Military {
    public:
        int hr;
        int min;
        int sec;
        string meridiem;
        Military(int h, int m, int s, string mrd) {
            hr = h;
            min = m;
            sec = s;
            meridiem = mrd;
        }
        void display() {
            if (meridiem == "AM") {
                cout << hr << ':' << min << ':' << sec << endl;
            } else if (meridiem == "PM") {
                hr+=12;
                cout << hr << ':' << min << ':' << sec << endl;
            }
        }
};

int main() {
    Clock cc(10, 25, 43, "AM");
    Standard sc(10, 25, 43, "AM");
    Military mc(10, 25, 43, "PM");
    cc.display();
    sc.display();
    mc.display();

    return 0;
}
