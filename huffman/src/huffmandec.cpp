/*
Stephen Chew
Last Edited: 12-25-2019
*/

#include <iostream>
#include <stdlib.h> // this is where exist() lives
#include <stdio.h> // this is where the standard i/o library is
#include "huffmanNode.h"
#include <map>
#include <iterator>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;


/** @brief This function builds a huffman tree using characters and their prefix codes
@param hn is a pointer to the root of the tree
@param character is the character that is being inserted into the tree
@param prefix is the prefix code that is associated with the character
*/
void huffTree(huffmanNode *hn, string character, string prefix){
	if(prefix.length() == 0){
		hn -> value = character[0];
	}
	if(prefix[0] == '0'){
		if(hn -> left == NULL){
			hn -> left = new huffmanNode(0, '\0');
		}
		huffTree(hn -> left, character, prefix.substr(1));
	}
	if(prefix[0] == '1'){
		if(hn -> right == NULL){
			hn -> right = new huffmanNode(0, '\0');
		}
		huffTree(hn -> right, character, prefix.substr(1));
	}
}

/** @brief This function prints out the encoded message using the prefix code
@param hn is a pointer to the root of the tree
@param bits is the prefix code
*/
void decodingTree(huffmanNode *hn, string bits){
	if(hn -> left == NULL && hn -> right == NULL){
		cout << hn -> getValue();
	}
	if(bits[0] == '0'){
		decodingTree(hn -> left, bits.substr(1));
	}
	if(bits[0] == '1'){
		decodingTree(hn -> right, bits.substr(1));
	}
}


int main (int argc, char **argv) {

    // creating the root node of a huffman tree
	huffmanNode *hn = new huffmanNode(0, '\0');

    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    while ( true ) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        // breaks if we hit the separator
        if ( (character[0] == '-') && (character.length() > 1)){
            break;
        }
        // check for space
        if ( character == "space"){
            character = " ";
        }
        // read in the prefix code
        file >> prefix;

        // insert the character and prefix code into the huffman tree
        huffTree(hn, character, prefix);
    }

    // creating a huffmanNode pointer to the huffman tree 
    huffmanNode *savingNode = hn;
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true){
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-'){
        	break;
        }
        decodingTree(savingNode, bits);
        savingNode = hn; // bringing the pointer back to the root
        // add it to the stringstream
        sstm << bits;
    }

    cout << endl;
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string, print with:
    // cout << endl << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();
}






