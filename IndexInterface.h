//
// Created by PRINCE NDHLOVU on 4/16/20.
//

#ifndef CS2341_SEARCHENGINE_ALGORITHMS98_INDEXINTERFACE_H
#define CS2341_SEARCHENGINE_ALGORITHMS98_INDEXINTERFACE_H

#include "Words.h"

class IndexInterface {

public:

    virtual void addWord(Words) = 0;
    virtual void displayWords() = 0;
    virtual Words& wordLocation(string) = 0;
    virtual bool hasElement(string) = 0;
    virtual ~IndexInterface() = default;
    virtual void  parseWords() = 0;
    virtual void setPersistent() = 0;


};


#endif //CS2341_SEARCHENGINE_ALGORITHMS98_INDEXINTERFACE_H
