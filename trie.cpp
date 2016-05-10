/**
 * @file trie.cpp Trie class functions for Huffman encoding.
 **
  * @file trie.cpp   Contains definitions of functions from trie.h
  * other than hf
  *
  * @author Jayesh Tambe
  * @date 9 May 2016
  */

#include<iostream>
#include<string>
#include<map>
#include"trie.h"
#include"dlist.h"
#include"priority_queue.h"
#include"node.h"
using namespace std;

// Trie* Trie::mergeTries(Trie* t1, Trie* t2){
//
//   Node<char> * ptr = new Node<char>('$',
//      NULL, NULL, t1->priority + t2->priority );
//   Trie * t = new Trie(ptr,ptr->priority);
//   return t;
// }

// function to erase memory created in program
// input
// 1. Node<char> pointer
// returns void
void Trie::eraseMemory(Node<char> * node){

  if(node == NULL){
    return;
  }
  else{
    delete node;
  }
  eraseMemory(node->prev);
  eraseMemory(node->next);
}


// function to traveser trie and create huffman codes
// input
// 1. Node<char> pointer
// 2. map<char, string> reference
// 3. string
// returns void
void Trie::traverseTrie(Node<char>* node,map<char,string> &huffmanCodes,
  string prefixCode){

  if(node == NULL){
    return;
  }
  if(node->value != '$'){
    char c = node->value;
    //cout << "character : " << c << " huffmanCode : " << prefixCode << endl;
    huffmanCodes.insert(pair<char,string>(c,prefixCode));
  }
  traverseTrie(node->prev, huffmanCodes, prefixCode+"1");
  traverseTrie(node->next, huffmanCodes, prefixCode+"0");

}

// Copy fucntion used in copy constructor for Trie
// input
// 1. Node<char> pointer
// returns Node<char> pointer
Node<char>* Trie::copy(Node<char> * r){

  if(r != NULL){
    Node<char> * ptr = new Node<char>(r->value, NULL,NULL, r->priority);
    ptr->prev = copy(r->prev);
    ptr->next = copy(r->next);
    return ptr;
  }
  else{
    return NULL;
  }
}

// copy constructor for Trie
// input
// 1. trie object reference
// returns trie non pointer object
Trie Trie::operator=(const Trie &rhs){

  Trie t;
  if(rhs.root != NULL){
    t.root = copy(rhs.root);
  }
  return t;
}
