//
// Created by PRINCE NDHLOVU on 4/15/20.
//

#ifndef CS2341_SEARCHENGINE_ALGORITHMS98_HASHTABLE_H
#define CS2341_SEARCHENGINE_ALGORITHMS98_HASHTABLE_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <functional>



template <class T, class P>
class HashTable {

private:

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
        dataList[i] = obj.dataList
    }
    return *this;
}

// destructor
template <class T, class P>
HashTable<T, P> ::~HashTable() {
    delete [] dataList;
    dataList= nullptr;
}

template <class T, class P>
P& HashTable::find(T keyNum) {

    int num = hash<K>()(keyNum) % size;
    for(int i = 0; i < dataList[num].size(); i++){

        if(dataList[num][i].getKey() == keyNum){
            return dataList[num][i].getValue();
        }
    }

}

template <class T, class P>
void HashTable::insert(T newKey, P newVal){

    int num = hash<T>()(newKey) % size;
    data obj(newKey);
    obj.addValue(newVal);
    dataList[num].push_back(obj);

}

template <class T, class P>
bool HashTable::contains(T keyVal) {

    int num = hash<T>()(keyVal) % size;
    for(int i = 0; i < dataList[num].size(); i++){
        if(dataList[num][i].getKey() == keyVal){
            return true;
        }
    }
    return false;
}

template <class T, class P>
int HashTable::getSize() {

    return size;
}
template <class T, class P>
bool HashTable::isEmpty() {

    for(int i = 0; i < size; i++){
        if(dataList[i].size() != 0){
            return false;
        }
    }
    return true;

}
template <class T, class P>
void HashTable::display() {

    for(int i = 0; i < size; i ++){
        for(int j = 0; j < dataList[i].size(); j++){
            cout << dataList[i][j].getValue() << endl;
        }
    }

}
template <class T, class P>
int HashTable::getIndexValue(T keyVal) {

    int num = hash<T>()(keyVal) % size;
    return num;

}

template <class T, class P>
int HashTable::getIndexKey(T keyNum) {

    int num = hash<T>()(keyNum) % size;
    for(int i = 0; i < dataList[num].size(); i++){
        if(dataList[num][i].getKey() == keyNum){
            return i;
        }
    }

}



#endif //CS2341_SEARCHENGINE_ALGORITHMS98_HASHTABLE_H
