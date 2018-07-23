#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <new>

const int ARRAY_BLOCK_SIZE = 256;

class BinaryHeap {
private:
    int m_numberOfElements;
    int m_actualSize;
    int* m_elements;

    void upHeap(int i);
public:
    BinaryHeap();
    void pushHeap(int x);
    int getTop();
    ~BinaryHeap();
};



/* ----- Implementations ----- */

void BinaryHeap::upHeap(int i) {
    int x = this->m_elements[i];
    while (i > 0 && this->m_elements[i >> 1] < x) {
        this->m_elements[i] = this->m_elements[i >> 1];
        i >>= 1;
    }
    this->m_elements[i] = x;
}

BinaryHeap::BinaryHeap() {
    this->m_numberOfElements = 0;
    this->m_elements = NULL;
    this->m_actualSize = 0;
}

void BinaryHeap::pushHeap(int x) {
    if (this->m_numberOfElements == this->m_actualSize) {
        this->m_elements = (int*)calloc(this->m_actualSize + ARRAY_BLOCK_SIZE, sizeof(int));
        this->m_actualSize += ARRAY_BLOCK_SIZE;
    }

    this->m_elements[this->m_numberOfElements] = x;
    this->upHeap(this->m_numberOfElements++);
}

int BinaryHeap::getTop() {
    return this->m_numberOfElements == 0 ? -1 : this->m_elements[0];
}

BinaryHeap::~BinaryHeap() {
    free(this->m_elements);
}

/* --------------------------- */


extern "C" {
    BinaryHeap* createNewHeap() {
        BinaryHeap* heapPointer = new BinaryHeap();
        return heapPointer;
    }

    void insertToHeap(BinaryHeap* heapPointer, int value) {
        heapPointer->pushHeap(value);
    }

    int getTopOfHeap(BinaryHeap* heapPointer) {
        return heapPointer->getTop();
    }

    void disposeHeap(BinaryHeap* heapPointer) {
        delete heapPointer;
    }
}
