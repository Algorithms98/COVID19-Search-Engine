//
// Created by PRINCE NDHLOVU on 4/16/20.
//

#ifndef CS2341_SEARCHENGINE_ALGORITHMS98_STOPWORDS_H
#define CS2341_SEARCHENGINE_ALGORITHMS98_STOPWORDS_H

#include "AVLTree.h"
#include<fstream>


class StopWords {
private:
    AVLTree<string> stopTree;
public:
    StopWords();
    AVLTree<string>& getStopTree();
    void insertStopWords();

};


#endif //CS2341_SEARCHENGINE_ALGORITHMS98_STOPWORDS_H
