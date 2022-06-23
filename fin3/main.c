#include <iostream>
using namespace std;

class myArray {
    public:
    int max = 0;
    int Array[128];
        myArray(size) {
            return Array[size];
        }
        void recInput(int array, int size) {
            if (size == 0) break;
            size--;
            Array[size] = array[size];
            recInput(array, size);
        }
        int recMax(int size) {
            size--;
            if (size > 0) {
                if (Array[size] >= Array[size-1]) {
                    max = Array[size];
                } else {
                    max = Array[size-1];
                }
            } else {
                return max;
            }
            recMax(size);
        }
};
int main() {
    int size = 5;
    int array[] = {500, 1, 2, 3, 4};
    myArray A(size);
    A.recInput(array, size);
    cout << "The max is: " << A.recMax(size) << endl;

    return 0;
}
