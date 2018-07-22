//	LinkedBag340.cpp
//	Created by: CSC340 Student

/*
	===>					<===
	===>  PLEASE ADD CODE	<===
	===>					<===
*/

// getCurrentSize340Recursive() 
// Friendly reminder:
// - This function must be a recursive function of immediate recursion type.
// - Or (if needed) it can call one recursive function of immediate recursion type.
// - In either case, recursive call(s) must be used to accomplish the main task of the function. 

// getFrequencyOf340Recursive()
// Friendly reminder:
// - This function must be a recursive function of immediate recursion type.
// - Or (if needed) it can call one recursive function of immediate recursion type.
// - In either case, recursive call(s) must be used to accomplish the main task of the function. 

// A recursive function of immediate recursion type is a function which calls itself.


#include <cstddef>
#include "LinkedBag.h"
#include "Node.h"
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;



template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& newEntry){
    
    Node<ItemType> * nextNodePtr = new Node<ItemType>(newEntry);
    Node<ItemType> * temp =  headPtr;
    while(temp->getNext() != nullptr){
        temp = temp->getNext();
    }
    temp->setNext(nextNodePtr);
    itemCount++;
    
    return true;
}


template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340(){
    ItemType item;
    
    if(itemCount >0){
        srand((unsigned)time(0));
        int randNum = (rand()%itemCount)+1;
        cout << "Random number: "<< randNum << ", itemCount:" << itemCount << "------    ";
        
      
        Node<ItemType> * curPtr = headPtr;
        
        if(randNum == 1 ){
            headPtr = curPtr->getNext();
            //cout << "HeadPtr: " << headPtr->getItem() << endl;
            
            item = headPtr->getItem();
            
        }else{
            
            Node<ItemType> * prevPtr = nullptr;
            
            for(int i=1; i < randNum; i++){
                prevPtr = curPtr;
                curPtr = curPtr->getNext();
                // cout << "Preptr: " << prevPtr->getItem()<< ", nextPtr: " << curPtr->getItem() << endl;
            }
            
            prevPtr->setNext(curPtr->getNext());
            //cout << "Updated Preptr: " << (prevPtr->getNext())->getItem() << endl;
            prevPtr = nullptr;
        }
        item = curPtr->getItem();
        delete curPtr;
        curPtr = nullptr;
        itemCount --;
        
    }else{
        
        cout << "Bag is empty";
    }
    
    return item;
    
}

template <typename  ItemType>
bool LinkedBag<ItemType>::removeSecondNode340(){
    if(itemCount > 1){
        Node<ItemType> * temp = headPtr->getNext();
        headPtr->setNext(temp->getNext());
        delete temp;
        temp = nullptr;
        itemCount--;
        return true;
    }
    return false;
}


template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const{
    int count =1;
    if(headPtr->getNext() == nullptr){
        return 0;
    }
    else{
        Node<ItemType> * temp =  headPtr;
        while(temp->getNext() != nullptr){
            temp = temp->getNext();
            count++;
        }
        temp = nullptr;
    }
    return count;
}


template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
    
    if(headPtr == nullptr){
        return 0;
    }
    else{
        return  1+ getCurrentSize340RecursiveHelper(headPtr);
    }
    
}


template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* node) const{
    
    int count;
    Node<ItemType>* curPtr = node->getNext();
    
    if(curPtr==nullptr) {
        return 0;
    }else{
        count = 1 + getCurrentSize340RecursiveHelper(curPtr);
    }
    
    curPtr = nullptr;
    return count;
}



template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& item) const {
    
    if(headPtr == nullptr){
        return 0;
    }
    else{
        return getFrequencyOf340RecursiveHelper(headPtr, item);
    }
}


template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* node, const ItemType& item) const{
    
    int count = 0;
    
    if(node != nullptr) {
        if(node->getItem()==item) {
            count=1;
        }
        count = count + getFrequencyOf340RecursiveHelper(node->getNext(), item);
    }
    
    return count;
}












