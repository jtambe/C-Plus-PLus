
/**
 * @file trie.h Trie class for Huffman encoding.
 **
  * @file trie.h   Contains declarations and definitions of
  * some functions   
  *
  * @author Jayesh Tambe
  * @date 9 May 2016
  */


#ifndef TRIE_H
#define TRIE_H

#include<iostream>
#include<string>
#include<map>
#include"node.h"
//#include"dlist.h"
#include"priority_queue.h"
using namespace std;

//template <typename T>
class Trie{
    private:
        Node<char> *root;
        int priority;

    public:
        string huffmanCode;
        Trie(): root(NULL), priority(0) {};
        //~Trie(Node<char> * n);
        void eraseMemory(Node<char> * node);
        Trie(Node<char> * n, int pr): root(n), priority(pr){};
        Trie(const Trie &acopy):root(acopy.root),priority(acopy.priority){};
        int getTriePriority() {return this->priority;}
        Node<char> * getRoot() {return this->root;}
        Node<char> * copy(Node<char> * r);
        //Trie* mergeTries(Trie* t1, Trie* t2);
        Trie operator=(const Trie &acopy);
        void traverseTrie(Node<char> *node, map<char,string> &huffmanCodes,
        string prefixCode);

};
#endif
