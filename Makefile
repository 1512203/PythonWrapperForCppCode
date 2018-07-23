all: libsum.so


libsum.so: src/sum.cpp
	g++ -g -fPIC -Wall -Werror -shared src/sum.cpp -o build/libsum.so

clean:
	rm -f build/*.o build/*.so
