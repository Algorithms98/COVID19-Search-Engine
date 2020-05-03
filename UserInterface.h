//
// Created by PRINCE NDHLOVU on 4/27/20.
//

#ifndef CS2341_SEARCHENGINE_ALGORITHMS98_USERINTERFACE_H
#define CS2341_SEARCHENGINE_ALGORITHMS98_USERINTERFACE_H
#include "SearchEngine.h"
#include "IndexHandler.h"
#include "DocumentParser.h"
#include "QueryParser.h"
#include "AVLTree.h"
#include <stdlib.h>

class UserInterface {

public:

    int loadData();
    int searchArticles();
    int operationMode();
    void searchEngine();


};


#endif //CS2341_SEARCHENGINE_ALGORITHMS98_USERINTERFACE_H
