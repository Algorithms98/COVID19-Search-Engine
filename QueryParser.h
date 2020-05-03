//
// Created by PRINCE NDHLOVU on 4/18/20.
//

#ifndef CS2341_SEARCHENGINE_ALGORITHMS98_QUERYPARSER_H
#define CS2341_SEARCHENGINE_ALGORITHMS98_QUERYPARSER_H

#include "AVLTree.h"
#include "StopWords.h"
#include "Words.h"
#include <queue>
#include <sstream>
#include <iostream>


class QueryParser {

private:
    AVLTree<string> stopWordsTree;
    queue<string> userInput;
    StopWords swords;
    bool author = false;

public:

    QueryParser();
    queue<string>& getUserInput();
    void clearQ(queue<string> &);
    bool hasAuthor();



};


#endif //CS2341_SEARCHENGINE_ALGORITHMS98_QUERYPARSER_H
