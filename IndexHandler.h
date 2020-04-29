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

public:
    IndexHandler();
    IndexInterface* getIndexPtr();
    void cleanIndex();
    void readIndex();
    void writeToIndex(AVLTree<Words>&);
    vector<string>  getArticleFiles();
    void getTopWords();
    int getNumOfArticles();
   // void getIndex();
    void displayStatistics();


    void chooseIndex(DocumentProcessor,string);

    void addToIndex();


    /*
    bool doesIndexExist();
    void writeToIndex();
    void readFromIndex(IndexInterface*index);
    void chooseIndex();
    bool doesIndexExist(); */













};


#endif //CS2341_SEARCHENGINE_ALGORITHMS98_INDEXHANDLER_H
