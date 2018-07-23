from __future__ import print_function
import random
from ctypes import *

libc = CDLL("/home/nguyenquochuy/Documents/FirstSharedLibrary/build/libbinaryheap.so")

x = random.randint(0, 1000)
libc.createNewHeap.argtypes = []
libc.createNewHeap.restype = c_void_p

libc.insertToHeap.argtypes = [c_void_p, c_int]
