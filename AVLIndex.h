//
// Created by PRINCE NDHLOVU on 4/16/20.
//

#ifndef CS2341_SEARCHENGINE_ALGORITHMS98_AVLINDEX_H
#define CS2341_SEARCHENGINE_ALGORITHMS98_AVLINDEX_H

#include "IndexInterface.h"
#include "AVLTree.h"
#include "Words.h"


//Child class that inherits IndexInterface and links AVLTree with IndexInterface
class AVLIndex : public IndexInterface  {

private:
    AVLTree<Words> words;

public:

    ~AVLIndex() = default;
    void addWord(Words);
    Words& wordLocation(string);
    bool hasElement(string);
    void parseWords();
    void displayWords();
    virtual setPersistent();










};


#endif //CS2341_SEARCHENGINE_ALGORITHMS98_AVLINDEX_H
