/*
Stephen Chew
Last Edited: 12-25-2019
*/

#include <iostream>
#include <stdlib.h> // this is where exist() lives
#include <stdio.h> // this is where the standard i/o library is
#include "binary_heap.h"
#include "huffmanNode.h"
#include <map>
#include <iterator>
#include <string>
#include <string.h>
using namespace std;


// Declaring a map for key-value pairs of the character and the prefix code
map<char, string> charPrefix;

/** @brief This function creates prefix codes for each character by
traversing the huffman tree and appending 0 to the prefix string if 
it traverses left, and 1 to the prefix string if it traverses right

@param node is a pointer to the root of the tree or the current node
@param prefix is the partial or full prefix code 
@return each character and its respective prefix code
*/
string prefixCode(huffmanNode *node, string prefix){
  // base case
	if(node -> left == NULL && node -> right == NULL){
		string theChar;
		theChar.push_back(node -> value);         // converts character to string

		if(theChar == " "){
			charPrefix[' '] = prefix;
			return "space " + prefix + "\n";
		}
		charPrefix[node -> value] = prefix;
		return theChar + " " + prefix + "\n";
	}

  // recursively traverses the tree to obtain prefix code
	string appendingPrefix;
	if(node -> left != NULL){
		appendingPrefix += prefixCode(node -> left, prefix + "0");
	}
	if(node -> right != NULL){
		appendingPrefix += prefixCode(node -> right, prefix + "1");
	}
	return appendingPrefix;
}


int main(int argc, char **argv){

  // Error message if the user does not supply an input file
	if (argc != 2){
		cout << "Must supply the input file name as the one and only parameter" << endl;
		exit(1);
	}


	// Error message if the supplied file cannot be opened
	FILE *fp = fopen(argv[1], "r");
  if ( fp == NULL ) {
    cout << "File '" << argv[1] << "' does not exist!" << endl;
    exit(2);
  }


  // Declaring a map for key-value pairs of the character and the frequency
  map<char, int> mapInputs;
  map<char, int>::iterator itr;

  
  char charIn;
  mapInputs[fgetc(fp)] = 1;
  // Reads in each individual character; tabs and new lines are ignored
  while ( (charIn = fgetc(fp)) != EOF ){
  	if(mapInputs.find(charIn) == mapInputs.end() && charIn != '\t' && charIn != '\n'){
  		// Creates a new key-value pair if the character has not previously been read in
      mapInputs[charIn] = 1;
  	}
  	else if(charIn != '\t' && charIn != '\n'){
      // Increments the frequency/value if the character has appeared again
  		mapInputs[charIn] = (mapInputs[charIn] + 1);
  	}
  }


  binary_heap aHeap;
  // Insert each key-value pair into the min heap
  for(itr = mapInputs.begin(); itr != mapInputs.end(); ++itr){
    // Creates a new huffman node for each key-value pair in the map
  	huffmanNode *n = new huffmanNode(itr -> second, itr -> first);
    // Insert huffman node into the min heap
  	aHeap.insert(n);
 	}


 	while(aHeap.size() > 1){ // While there are still elements in the min heap
 		// Create a huffmanNode, left is min, right is min, frequency is the sum of frequencies
 		huffmanNode *leftChild;
 		huffmanNode *rightChild;
 		leftChild = aHeap.deleteMin();
 		rightChild = aHeap.deleteMin();

    // Adds the frequencies of both nodes
 		int sumFreq = (leftChild -> getFrequency()) + (rightChild -> getFrequency());
   	
    // Create an internal node with a and b as children
 		huffmanNode *n = new huffmanNode(sumFreq, '\0');
 		n -> left = leftChild;
 		n -> right = rightChild;
 		n -> freq = sumFreq;

    // Insert the internal node back into the min heap
 		aHeap.insert(n);
 	}

  // Retrieves and prints character codes 
 	string characterCodes = prefixCode(aHeap.findMin(), "");
 	cout << characterCodes;

 	cout << "----------------------------------------" << endl;

  rewind(fp);
 	char charOut;
  int count = 0;
  int numBits;

  // Count the characters in the file, number of bits, and prints out the encoded message
 	while((charOut = fgetc(fp)) != EOF){
    if(charOut != '\t' && charOut != '\n'){
      count++;
      numBits += charPrefix[charOut].length();
      cout << charPrefix[charOut] << " ";
    }
 	}

  cout << endl << "----------------------------------------" << endl;

  cout << "There are a total of " << count << " symbols that are encoded." << endl;
   	
  cout << "There are " << mapInputs.size() << " distinct symbols used." << endl;

  int bits = count * 8;
  cout << "There were " << bits << " bits in the original file." << endl;
    
  cout << "There are " << numBits << " bits in the compressed file." << endl;

  double ratio = double(bits) / numBits;
  cout << "This gives a compression ratio of " << ratio << "." << endl;

  double cost = double(numBits) / count;
  cout << "The cost of the Huffman tree is " << cost << " bits per character." << endl;

}



// GENERAL NOTES (Material Learned)
  // before, calling getFrequency on a pointer; need to call it on the actual huffmanNode
  // (*a).getFrequency() similar to a -> getFrequency()

  // int n = 26;
  // int * somePointer = &n;
  // cout << somePointer << endl; // 0x7ffeea4aaaec memory address in pointer
  // cout << *somePointer << endl; // 26

  // int x = 26;
  // int * ptr = &x;
  // * ptr = 69;
  // cout << x << endl; // 69
  // cout << ptr << endl; // address 0x7ffeea4aaaec
  // cout << *ptr << endl; // 69

  // int y = 5;
  // int &a = y;
  // cout << a << endl; // 5
  // cout << &a << endl; // address




