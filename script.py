from __future__ import print_function
import random
from ctypes import *

libc = CDLL("./build/libbinaryheap.so")


class BinaryHeapWrapper(object):
    def __init__(self):
        libc.createNewHeap.argtypes = []
        libc.createNewHeap.restype = c_void_p

        libc.insertToHeap.argtypes = [c_void_p, c_int]
        libc.insertToHeap.restype = c_void_p

        libc.getTopOfHeap.argtypes = [c_void_p]
        libc.getTopOfHeap.restype = c_int

        libc.disposeHeap.argtypes = [c_void_p]
        libc.disposeHeap.restype = c_void_p

        self.obj = libc.createNewHeap()


    def insert_to_heap(self, x):
        if self.obj:
            libc.insertToHeap(self.obj, x)


    def get_top(self):
        if self.obj:
            return libc.getTopOfHeap(self.obj)
        return 0


    def destroy(self):
        if self.obj:
            libc.disposeHeap(self.obj)
            self.obj = None



h = BinaryHeapWrapper()
for i in range(10):
    val = random.randint(0, 1000)
    print("value to be inserted is %d" % val)
    h.insert_to_heap(val)
    print("Maximum value of heap is %d" % h.get_top())
h.destroy()
