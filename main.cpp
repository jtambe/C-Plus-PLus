
/**
 * @file main.cpp for generating trie for huffmanCode
 **
  * @file main.cpp
  * other than hf
  *
  * @author Jayesh Tambe
  * @date 9 May 2016
  */


#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include "priority_queue.h"
#include "node.h"
#include "dlist.h"
#include "trie.h"
using namespace std;

// function to build a trie using PriorityQueue
// input
// 1. priority_queue<Trie*> pointer
// returns non pointer Trie
Trie createFinalTrie(PriorityQueue<Trie*> * que){

  Trie  finalTrie;
  while( que->size() != 0 ){
    Trie t1 = que->front();
    Trie t1New = t1;
    que->dequeue();
    // cout << "t1New.getTriePriority(): "
    // << t1New.getRoot()->value << ": "<< t1New.getTriePriority() << endl;
    if(que->size() != 0){
      Trie t2 = que->front();
      Trie t2New = t2;
      que->dequeue();
      Node<char> * n = new Node<char>('$', t1New.getRoot(), t2New.getRoot(),
      t1New.getTriePriority()+ t2New.getTriePriority());
      Trie * insert = new Trie(n,t1New.getTriePriority()+
       t2New.getTriePriority());
      //  cout << "insert->getTriePriority(): "
      //  << insert->getTriePriority() << endl << endl;
      que->enqueue(insert, t1New.getTriePriority()+
        t2New.getTriePriority());
    }
    else{
      Trie finalTrie = t1New;
      // cout << "t1New.getTriePriority(): "
      // << t1New.getRoot()->value << ": "<< t1New.getTriePriority() << endl;
      // cout << "finalTrie.getTriePriority(): "
      // << finalTrie.getRoot()->value << ": "
      // << finalTrie.getTriePriority() << endl;
      return finalTrie;
    }
  }
  return finalTrie;
}

int main(int argc, char * argv[]){
  // check if the input file is provided in command line
  if(argc == 2){

    string inputFile = argv[1];
    ifstream myfile (inputFile);
    int inputLength= 0;

    // map to read and store input characters and frequencies
    map <char, int> myMap;
    // map to store huffmancodes
    map <char, string> huffmanCodes;
    PriorityQueue <Trie*> * pq = new PriorityQueue<Trie*>();

    if (myfile.is_open()){
      string inputText;
      getline (myfile,inputText);
      //cout << "inputText: " << inputText << endl;
      inputLength  = inputText.length();

      for(int i = 0 ; i < inputLength-1 ; i++){
        string current = inputText.substr(i,1);
        //cout << "current: " << current << endl;
        char c = toupper(current[0]);
        //cout << "c: " << c << endl;
        if(myMap.count(c) > 0){
          myMap.find(c)->second = myMap.find(c)->second +1;
        }
        else{
          myMap.insert(pair<char,int>(c,1));
        }
      }

    }
    myfile.close();

    for(std::map<char,int>::iterator it= myMap.begin(); it!= myMap.end(); ++it){
      //std::cout << it->first << " => " << it->second << endl;
      Node<char> * ptr = new Node<char>(it->first,
         nullptr, nullptr,it->second );
      //cout << ptr->value << endl;
      Trie * t = new Trie(ptr,ptr->priority);
      //cout << "t->getTriePriority(): " << t->getTriePriority() << endl;
      pq->enqueue(t, t->getTriePriority());
    }

    // create a trie of all characters
    Trie final = createFinalTrie(pq);
    // traverse the trie to create huffman codes
    final.traverseTrie(final.getRoot(),huffmanCodes,"");

    // to find no of bits needed after huffman encoding
    int newNoofBits = 0;
    for(std::map<char,string>::iterator it=huffmanCodes.begin();
    it!=huffmanCodes.end(); ++it){
      std::cout << it->first << " " << it->second << endl;
      if(myMap.count(it->first) > 0){
        newNoofBits = newNoofBits +
        ((myMap.find(it->first)->second)*((it->second).length()));
      }
    }
    cout << newNoofBits << endl;

    // to find no of bits needed before huffman encoding
    int oldNoofBits = 0;
    for(std::map<char,int>::iterator it=myMap.begin(); it!=myMap.end(); ++it){
      //std::cout << it->first << " => " << it->second << endl;
      oldNoofBits = oldNoofBits + ((it->second)*8);
    }
    cout << oldNoofBits << endl;

    // release newly created memory
    //cout << "final.getTriePriority(): "<<final.getTriePriority()<< endl;
    final.eraseMemory(final.getRoot());
    delete pq;

    return 0;
  }
  else{
    cerr << "Unable to open file";
    return 1;
  }

}
