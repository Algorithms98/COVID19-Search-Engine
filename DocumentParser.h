//
// Created by PRINCE NDHLOVU on 4/18/20.
//

#ifndef CS2341_SEARCHENGINE_ALGORITHMS98_DOCUMENTPARSER_H
#define CS2341_SEARCHENGINE_ALGORITHMS98_DOCUMENTPARSER_H

#include "AVLTree.h"
#include "Words.h"
#include "AVLIndex.h"
#include "IndexInterface.h"
#include <unordered_map>
#include <unordered_set>

struct DocumentData{

    unsigned int id;
    string text;
};

class DocumentParser {

private:
    int numOfArticles;
    int numOfIndexedWords;
    int numOfTotalWords;
    string filePaths;
    unordered_set<string> stopWords;
    unordered_map<string, string> stemWordsCache;
    IndexInterface* indexes;
    AVLTree<string> wordsParsed;
    AVLTree<Words> wordsTree;
    AVLIndex wordIndexer;
    vector<int> averageWords;

public:
    DocumentParser();
    int getNumOfArticles();
    int getNumOfIndexedWords();
    int getNumOfTotalWords();
    void readDirectory();
    void parseArticles(const string, const string);
    AVLTree<Words>& getWords();
    string getFilePath();
    string& loweringString(string&) const ;
    void displayStatistics();
    void insertTreeWord(string, string);
    void setStopWords();
    unordered_set<string> getStopWords();
    void setIndex(IndexInterface*);
    string cleanWords(string &) ;
    int getAveOfIndexedWords();
    void stemmingStrings(string &) ;

};


#endif //CS2341_SEARCHENGINE_ALGORITHMS98_DOCUMENTPARSER_H
