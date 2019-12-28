# Stephen Chew
# Last Edited: 12-25-2019

CXX=clang++


.SUFFIXES: .o .cpp
all: encoder decoder

encoder: huffmanenc.o huffmanNode.o binary_heap.o
	$(CXX) huffmanenc.o huffmanNode.o binary_heap.o -o encoder

decoder: huffmandec.o huffmanNode.o 
	$(CXX) huffmandec.o huffmanNode.o -o decoder

huffmanenc.o: huffmanenc.cpp
	$(CXX) -c huffmanenc.cpp

huffmanNode.o: huffmanNode.cpp huffmanNode.h
	$(CXX) -c huffmanNode.cpp

binary_heap.o: binary_heap.cpp binary_heap.h
	$(CXX) -c binary_heap.cpp

huffmandec.o: huffmandec.cpp
	$(CXX) -c huffmandec.cpp

clean:
	-rm -f *.o *~ a.out *encoder *decoder