from __future__ import print_function
import random
from ctypes import *

libc = CDLL("/home/nguyenquochuy/Documents/FirstSharedLibrary/build/libsum.so")

for i in range(10):
    x = random.randint(0, 1000)
    print("Inserted value is:", x)
    libc.insertToHeap(x)
    print("Largest value of the heap is:", libc.printTop())
