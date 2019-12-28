# personal-projects

This file contains the Huffman Code Project

---

### Huffman Code Summary
The Huffman Code is an algorithm for performing data compression and decompression. The purpose of the code is to convert characters in a text file into binary, or to convert binary in a text file into characters. 

The advantage of converting the characters in a text file into binary is to reduce the quantity of memory required to represent the characters contained within the file. 

### Encoding Process

- The encoding phase first starts by reading in each character in a text file. 
- The frequency of each character is then stored into a map. 
- Each key-value pair is then used to create a Huffman node, which is then inserted into a min heap (sorted based off of frequency).
- While there are elements in the min heap, a node is retrieved and deleted from the min heap twice. An internal node is then created with its left and right children set as pointers to the two retrieved nodes.
- The internal node is then pushed back onto the min heap. The process of retrieving two nodes and pushing an internal node will create a Huffman tree.
- After the Huffman tree has been created, prefix codes are created for each character by recursively traversing through the tree and assign a 0 for each left traversal and a 1 for each right traversal. 
- Each character and its respective prefix code is then printed out. 


### Decoding Process

- The decoding phase first starts by reading in each character and its respective prefix code. A 1 represents a traversal to the right, and a 0 represents a traversal to the left. 
- A Huffman tree is created using the character-prefix information. 
- The message is decoded and printed using the created Huffman Tree. 
 
---

### Contributors

- Stephen S Chew <ssc6ae@virginia.edu>
- This project was expanded off of information presented in the Program and Data Representation course at the University of Virginia. 