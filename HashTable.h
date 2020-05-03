//
// Created by PRINCE NDHLOVU on 4/15/20.
//

#ifndef CS2341_SEARCHENGINE_ALGORITHMS98_HASHTABLE_H
#define CS2341_SEARCHENGINE_ALGORITHMS98_HASHTABLE_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <functional>
using namespace std;


template <class T, class P>
class HashTable {

private:

    /*
     * Struct to hold the key value pairs
     */
    struct data{
        T key;
        P value;

        vector<P> values;
        data(T keyVal){
            key = keyVal;
        }
        data(T keyVal, P newVal){
            key = keyVal;
            values.push_back(newVal);
        }

        void addValue(P newVal){
            value = newVal;
            for(int i = 0; i < values.size(); i++){
                if(!(newVal == values[i])){
                    values.push_back(newVal);
                }
            }
        }

        T getKey(){
            return key;
        }
        P& getValue(){
            return value;
        }

    };

    int size;
    vector<data>* dataList;

public:
    HashTable();
    HashTable(int);
    HashTable(HashTable &);
    HashTable<T, P>& operator=( HashTable &);
    ~HashTable();
    void insert(T, P);
    P& find(T);
    bool contains(T);
    int getSize();
    bool isEmpty();
    void display();
    int getIndexValue(T);
    int getIndexKey(T);


};

// Constructor
template <class T, class P>
HashTable<T, P>::HashTable() {
    size = 1000000;
    dataList = new vector<data>[size];
}

template <class T, class P>
HashTable<T,P>::HashTable(int num) {

    if(num < 30){
        size = 30;
    } else{
        size = num;
    }

    dataList = new vector<data>[size];

}

//deep copy constructor
template <class T, class P>
HashTable<T, P>::HashTable(HashTable &obj) {

    size = obj.size;
    dataList = new vector<data>[size];
    for(int i = 0; i < size; i ++){
        dataList[i] = obj.dataList[i];
    }
}

//deep copy assignment operator
template <class T, class P>
HashTable<T, P>& HashTable<T, P>::operator=(HashTable &obj) {

    size = obj.size;
    if(dataList != nullptr){
        delete [] dataList;
    }

    dataList = new vector<P>[size];
    for(int i = 0; i < size; i++){
        dataList[i] = obj.dataList;
    }
    return *this;
}

// destructor
template <class T, class P>
HashTable<T, P> ::~HashTable() {
    delete [] dataList;
    dataList= nullptr;
}

//find the value using the hash of the key
template <class T, class P>
P& HashTable<T, P>::find(T keyNum) {

    int num = hash<T>()(keyNum) % size;
    for(int i = 0; i < dataList[num].size(); i++){

        if(dataList[num][i].getKey() == keyNum){
            return dataList[num][i].getValue();
        }
    }

}

//insert a value using the key
template <class T, class P>
void HashTable<T, P>::insert(T newKey, P newVal){

    int num = hash<T>()(newKey) % size;
    data obj(newKey);
    obj.addValue(newVal);
    dataList[num].push_back(obj);

}

//check if the value is present in the table using the key
template <class T, class P>
bool HashTable<T, P>::contains(T keyVal) {

    int num = hash<T>()(keyVal) % size;
    for(int i = 0; i < dataList[num].size(); i++){
        if(dataList[num][i].getKey() == keyVal){
            return true;
        }
    }
    return false;
}

//get the size of the hash table
template <class T, class P>
int HashTable<T, P>::getSize() {

    return size;
}

//check if the hash table has elements in it
template <class T, class P>
bool HashTable<T, P>::isEmpty() {

    for(int i = 0; i < size; i++){
        if(dataList[i].size() != 0){
            return false;
        }
    }
    return true;

}
//print all the elements in the hash table
template <class T, class P>
void HashTable<T,P>::display() {

    for(int i = 0; i < size; i ++){
        for(int j = 0; j < dataList[i].size(); j++){
            cout << dataList[i][j].getValue() << endl;
        }
    }

}

//get the index value of an element in the hash table
template <class T, class P>
int HashTable<T,P>::getIndexValue(T keyVal) {

    int num = hash<T>()(keyVal) % size;
    return num;

}

//get the index location of a key in the hash table
template <class T, class P>
int HashTable<T,P>::getIndexKey(T keyNum) {

    int num = hash<T>()(keyNum) % size;
    for(int i = 0; i < dataList[num].size(); i++){
        if(dataList[num][i].getKey() == keyNum){
            return i;
        }
    }

}



#endif //CS2341_SEARCHENGINE_ALGORITHMS98_HASHTABLE_H
