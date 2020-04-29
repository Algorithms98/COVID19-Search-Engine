//
// Created by PRINCE NDHLOVU on 4/19/20.
//

#ifndef CS2341_SEARCHENGINE_ALGORITHMS98_SEARCHENGINE_H
#define CS2341_SEARCHENGINE_ALGORITHMS98_SEARCHENGINE_H

#include "DocumentParser.h"
#include "AVLTree.h"
#include "HashTable.h"
#include "IndexInterface.h"
#include "QueryParser.h"
#include "Words.h"
#include <queue>

class SearchEngine {

private:

    int numOfArticles;
    DocumentParser parse;
    queue<string> userQuery;
    IndexInterface* index;
    vector<pair<string, int>> rankedArticles;

public:

    SearchEngine();
    SearchEngine(IndexInterface*, int);

    void andLogic();
    void orLogic();
    void  notLogic();

    bool hasWord(string);
    void getQuery();
    void displayResults(vector<pair<string, int>>);
    vector<pair<string,int>> pullRequests(string);
    void display(vector<pair<string,int>>);
    void PrinceRank(vector<pair<string,int>>);
    void simpleSearch(string);

    vector<pair<string, int>> andSearch(vector<pair<string, int>>&, vector<pair<string, int>>&);
    vector<pair<string, int>> orSearch(vector<pair<string, int>>, vector<pair<string, int>>&);
    vector<pair<string, int>> notSearch(vector<pair<string, int>>, vector<pair<string, int>>&);




};


#endif //CS2341_SEARCHENGINE_ALGORITHMS98_SEARCHENGINE_H
