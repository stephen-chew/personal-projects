# personal-projects

This file contains the Huffman Code Project

---

### Huffman Code
The Huffman Code is an algorithm for performing data compression and decompression. The purpose of the code is to convert characters in a text file into binary, or to convert binary in a text file into characters. 

The advantage of converting from a character into binary is to reduce the quantity of memory required to represent the characters contained within the file. 

### Encoding

The encoding phase first starts by reading in each character in a text file. Each character and the frequency of its occurance is stored into a map. 


### Decoding



---

### Contributors

- Stephen S Chew <ssc6ae@virginia.edu>

The encoding phase works by reading in a text file, creating a unique prefix code for each character based off of the frequency of the character, and converting the text file from strings to bits. This will reduce the total quantity of memory necessary to represent the text file. The decoding phase works by creating a huffman tree using the characters and their respective prefix codes. The program will then read in prefix codes to 