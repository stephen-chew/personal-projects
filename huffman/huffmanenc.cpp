/*
Stephen Chew (ssc6ae)
pre-lab 10, 11:00am
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


map<char, string> mapOutputs;

string prefixCode(huffmanNode *node, string prefix){
	string space;
	if(node -> left == NULL && node -> right == NULL){

		string ugh;
		ugh.push_back(node -> value);
		if(ugh == " "){
			mapOutputs[' '] = prefix;
			return "space " + prefix + "\n";
		}
		mapOutputs[node -> value] = prefix;
		return ugh + " " + prefix + "\n";
	}
	// if(node -> right != NULL && node -> left != NULL){
	// 	return prefixCode(node -> right, prefix + "1") + prefixCode(node -> left, prefix + "0");
	// }
	string save;
	if(node -> left != NULL){
		// return prefixCode(node -> left, prefix + "0");
		save += prefixCode(node -> left, prefix + "0");
	}
	if(node -> right != NULL){
		// return prefixCode(node -> right, prefix + "1");
		save += prefixCode(node -> right, prefix + "1");
	}

	return save;
	cout << "done" << endl;
	return "f\n";

}


int main(int argc, char **argv){

	if (argc != 2){
		cout << "Must supply the input file name as the one and only parameter" << endl;
		exit(1);
	}

	// attempts to open the supplied file
	FILE *fp = fopen(argv[1], "r");
    if ( fp == NULL ) {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }

    
    // create minHeap

    map<char, int> mapInputs;
    map<char, int>::iterator itr;
    char charIn;
    mapInputs[fgetc(fp)] = 1;

    while ( (charIn = fgetc(fp)) != EOF ){
    	if(mapInputs.find(charIn) == mapInputs.end() && charIn != '\t' && charIn != '\n'){
    		mapInputs[charIn] = 1; 										// creates a new maping, charIn is the key, 1 is the value
    	}
    	else if(charIn != '\t' && charIn != '\n'){
    		mapInputs[charIn] = (mapInputs[charIn] + 1); 				// adding 1 to the value
    	}
    }
    // PRINTS OUT MAP'S KEY VALUE PAIR
    // for (itr = mapInputs.begin(); itr != mapInputs.end(); ++itr) { 		// for each key-value pair
    //     cout << itr->first << '\t' << itr->second << '\n'; 				// printing out the key and the value
    // }


    binary_heap aHeap;
    for(itr = mapInputs.begin(); itr != mapInputs.end(); ++itr){
    	huffmanNode *n = new huffmanNode(itr -> second, itr -> first);	// creates a new huffmanNode for each element in map
    	aHeap.insert(n);
   	}


   	while(aHeap.size() > 1){ // while not empty
   		// create a huffmanNode, left is min, right is min, frequency is sum of frequencies
   		huffmanNode *a;
   		huffmanNode *b; // this is pointer, not a huffman node
   		a = aHeap.deleteMin();
   		b = aHeap.deleteMin();

   		// before, calling getFrequency on a pointer; need to call it on the actual huffmanNode
   		// (*a).getFrequency() same thing as a -> getFrequency()

   		int sumFreq = (a -> getFrequency()) + (b -> getFrequency());
   		
   		huffmanNode *n = new huffmanNode(sumFreq, '\0');
   		n -> left = a;
   		n -> right = b;
   		n -> freq = sumFreq;
   		// cout << n -> freq; AT THE END OF THE LOOP, THIS IS THE TOTAL CHAR IN THE TEXT FILE
   		aHeap.insert(n);
   	}

   	string abc = prefixCode(aHeap.findMin(), "");
   	cout << abc;
   	cout << "----------------------------------------" << endl;

   	rewind(fp);
   	char charOut;
    int count = 0;
    int compressed;
   	while((charOut = fgetc(fp)) != EOF){
      if(charOut != '\t' && charOut != '\n'){
        count++;
        compressed += mapOutputs[charOut].length();
        cout << mapOutputs[charOut] << " ";
      }
   	}

    cout << endl << "----------------------------------------" << endl;

    cout << "There are a total of " << count << " symbols that are encoded." << endl;
   	
    cout << "There are " << mapInputs.size() << " distinct symbols used." << endl;

    int bits = count * 8;
    cout << "There were " << bits << " bits in the original file." << endl;

    

    cout << "There were " << compressed << " bits in the compressed file." << endl;

    double ratio = double(bits) / compressed;
    cout << "This gives a compression ratio of " << ratio << "." << endl;

    double cost = double(compressed) / count;
    cout << "The cost of the Huffman tree is " << cost << " bits per character." << endl;
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



    	// for(itr = mapInputs.begin(); itr != mapInputs.end(); ++itr){
    	// 	// if char in map, increment int by 1
    	// 	if(itr -> first == charIn){
    	// 		mapInputs[charIn] = (mapInputs[charIn] + 1);
    	// 	}
    	// 	// else, insert into map
    	// 	else{
    	// 		mapInputs[charIn] = 1;

    	// 	}
    	// }
}