//
// Created by PRINCE NDHLOVU on 4/18/20.
//

#ifndef CS2341_SEARCHENGINE_ALGORITHMS98_QUERYPARSER_H
#define CS2341_SEARCHENGINE_ALGORITHMS98_QUERYPARSER_H

#include "AVLTree.h"
#include "StopWords.h"
#include "Words.h"
#include <queue>
#include <stringstream>


class QueryParser {

private:
    AVLTree<string> stopWordsTree;
    queue<string> userInput;
    StopWords swords;

public:

    QueryParser();
    queue<string>& getUserInput();
    void clearQ(queue<string> &);


};


#endif //CS2341_SEARCHENGINE_ALGORITHMS98_QUERYPARSER_H
