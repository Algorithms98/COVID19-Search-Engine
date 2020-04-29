//
// Created by PRINCE NDHLOVU on 4/24/20.
//

#ifndef CS2341_SEARCHENGINE_ALGORITHMS98_HASHINDEX_H
#define CS2341_SEARCHENGINE_ALGORITHMS98_HASHINDEX_H

#include "HashTable.h"
#include "IndexInterface.h"

//Child class that inherits IndexInterface and links HashTable with IndexInterface
class HashIndex : public IndexInterface {

private:
    HashTable<string, Words> words;
public:
    void addWord(Words);
    Words& wordLocation(string);
    bool hasElement(string);
    void parseWords();
    void displayWords();
    ~HashIndex() = default;
    void setPersistent();

};


#endif //CS2341_SEARCHENGINE_ALGORITHMS98_HASHINDEX_H
