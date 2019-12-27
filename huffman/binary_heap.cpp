/*
Stephen Chew
Last Edited: 12-25-2019
*/

#include <iostream>
#include "binary_heap.h"
using namespace std;

// default constructor
binary_heap::binary_heap() : heap_size(0) {
    heap.push_back(0);
}

// destructor
binary_heap::~binary_heap() {
}

/** @brief This function inserts a huffman node into the min heap
@param x is the huffmanNode that is being inserted
*/
void binary_heap::insert(huffmanNode *x) {
    // a vector push_back will resize as necessary
    heap.push_back(x);
    // move it up into the right position
    percolateUp(++heap_size);
}

/** @brief This function rebalances the tree
@param hole is the location of the hole
*/
void binary_heap::percolateUp(int hole) {
    // get the value just inserted
    huffmanNode *x = heap[hole];					// create new huffmanNode
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (*x < *heap[hole/2]); hole /= 2 )
        heap[hole] = heap[hole/2]; // move the parent down
    // correct position found!  insert at that spot
    heap[hole] = x;
}

/** @brief This function deletes the root node
@return returns a pointer to a huffmanNode
*/
huffmanNode* binary_heap::deleteMin() { // return type should be pointer to huffmannode
    // make sure the heap is not empty
    if ( heap_size == 0 )
        throw "deleteMin() called on empty heap";
    // save the value to be returned
    huffmanNode *ret = heap[1];
    // move the last inserted position into the root
    heap[1] = heap[heap_size--];
    // make sure the vector knows that there is one less element
    heap.pop_back();
    // percolate the root down to the proper position
    percolateDown(1);
    // return the old root node
    return ret;
}

/** @brief This function rebalances the tree
@param hole is the location of the hole
*/
void binary_heap::percolateDown(int hole) {
    // get the value to percolate down
    huffmanNode *x = heap[hole];
    // while there is a left child...
    while ( hole*2 <= heap_size ) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ( (child+1 <= heap_size) && (*heap[child+1] < *heap[child]) )
            child++;
        // if the child is greater than the node...
        if ( *x > *heap[child] ) {
            heap[hole] = heap[child]; // move child up
            hole = child;             // move hole down
        } else
            break;
    }
    // correct position found!  insert at that spot
    heap[hole] = x;
}

/** @brief This function finds the min value of the min heap
@return returns a pointer to a huffmanNode
*/
huffmanNode* binary_heap::findMin() {
    if ( heap_size == 0 )
        throw "findMin() called on empty heap";
    return heap[1];
}

unsigned int binary_heap::size() {
    return heap_size;
}

void binary_heap::makeEmpty() {
    heap_size = 0;
    heap.resize(1);
}

bool binary_heap::isEmpty() {
    return heap_size == 0;
}

void binary_heap::print() {
    cout << "(" << heap[0] << ") ";
    for ( int i = 1; i <= heap_size; i++ ) {
        cout << heap[i] << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if ( isPow2 )
            cout << endl << "\t";
    }
    cout << endl;
}


