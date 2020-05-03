//
// Created by PRINCE NDHLOVU on 4/16/20.
//

#ifndef CS2341_SEARCHENGINE_ALGORITHMS98_INDEXHANDLER_H
#define CS2341_SEARCHENGINE_ALGORITHMS98_INDEXHANDLER_H

#include <vector>
#include <fstream>
#include "AVLTree.h"
#include "IndexInterface.h"
#include "AVLIndex.h"
#include "Words.h"
#include "HashTable.h"
#include "DocumentParser.h"


class IndexHandler {
private:
    int numOfArtArticles;
    int numOfIndexedWords;
    int numOfWordsTotal;
    fstream filename;
    IndexInterface* index;
    vector<string> articleFiles;
    AVLTree<Words> words;
    DocumentParser parse;

public:
    IndexHandler();
    IndexInterface*& getIndexPtr();
    void cleanIndex();
    void readIndex();
    void writeToIndex(AVLTree<Words>&);
    vector<string>  getArticleFiles();
    void getTopWords();
    int getNumOfArticles();
    void displayStatistics();
    void addToIndex();


};


#endif //CS2341_SEARCHENGINE_ALGORITHMS98_INDEXHANDLER_H
