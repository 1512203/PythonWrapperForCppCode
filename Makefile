all: libbinaryheap.so


libbinaryheap.so: src/binaryheap.cpp
	g++ -g -fPIC -Wall -Werror -shared src/binaryheap.cpp -o build/libbinaryheap.so

clean:
	rm -f build/*.o build/*.so
