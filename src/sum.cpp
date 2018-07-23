#include <ctime>
#include <cstdlib>
#include <cstdio>

const int ARRAY_BLOCK_SIZE = 256;

class BinaryHeap {
private:
    int m_numberOfElements;
    int m_actualSize;
    int* m_elements;

    void upHeap(int i) {
        int x = this->m_elements[i];
        while (i > 0 && this->m_elements[i >> 1] < x) {
            this->m_elements[i] = this->m_elements[i >> 1];
            i >>= 1;
        }
        this->m_elements[i] = x;
    }

public:
    BinaryHeap() {
        this->m_numberOfElements = 0;
        this->m_elements = NULL;
        this->m_actualSize = 0;
    }

    void pushHeap(int x) {
        if (this->m_numberOfElements == this->m_actualSize) {
            this->m_elements = (int*)calloc(this->m_actualSize + ARRAY_BLOCK_SIZE, sizeof(int));
            this->m_actualSize += ARRAY_BLOCK_SIZE;
        }

        this->m_elements[this->m_numberOfElements] = x;
        this->upHeap(this->m_numberOfElements ++);
    }

    int getTop() {
        if (m_numberOfElements == 0) 
            return -1;
        return this->m_elements[0];
    }

    ~BinaryHeap() {
        free(this->m_elements);
    }
};

BinaryHeap myHeap = BinaryHeap();

extern "C" {
    void insertToHeap(int x) {
       myHeap.pushHeap(x);
    }

    int printTop() {
        return myHeap.getTop();
    }
}
