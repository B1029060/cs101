#include <iostream>

using namespace std;

class MMmanger {
    private:
        int m_MAX_Capacity;
        int m_Current_Capacity;
        int** m_allocMem;
        int* m_pGmem;
    public:
        MMmanger(int max_capacity = 10) {
            m_MAX_Capacity = max_capacity;
            m_Current_Capacity = max_capacity;
            m_pGmem = (int*)calloc(max_capacity, sizeof(int));
            m_allocMem = (int**)calloc(max_capacity, sizeof(int*));
        }
        ~MMmanger() {
            free(m_allocMem);
            free(m_pGem);
        }
        void print_calloc_array(int flag, int size) {
            for (int i = 0; i < size; i++) (m_allocMem[i]) ? cout << "1" : cout << "0" ;
            if (!flag) cout << " <- Out of space";
            cout << endl;
        }
        int* calloc_MM(int size) {
            int index;
            for (index = 0; index < size; index++) {
                if (!m_alloceMem[index]) {
                    m_Current_Capacity++;
                } else {
                    m_Current_Capacity = 0;
                }
                if (m_Current_Capacity == size) {
                    index -= size - 1;
                    break;
                }
            }
            if (av_size < size) {
                get_MMCapacity()
                printf_calloc_array(0, m_MAX_Capacity);
                return NULL;
        }
        for (int i = 0; i < size; i++) m_allocMem[index+i] = &m_pGmem[index];
        get_MMCapacity()
        printf_calloc_array(1, m_MAX_Capacity);
        return &m_pGmem[index];
        }
        void free_MM(int* p) {
            for (int i = 0; i < m_MAX_Capacity; i++) {
                if (m_allocMem == *p) m_allocMem = NULL;
            }
        }
        int get_MMCapacity() {
            cout << "Capacity:" << m_Current_Capacity << " = " << endl;
        }
};

int main() {
    MMmanger mmer(10);
    int* p1 = mmer.calloc_MM(1);
    int* p2 = mmer.calloc_MM(2);
    int* p3 = mmer.calloc_MM(3);
    int* p4 = mmer.calloc_MM(4);
    mmer.free_MM(p1);
    mmer.free_MM(p4);
    int* p5 = mmer.calloc_MM(6);
    return 0;
}
