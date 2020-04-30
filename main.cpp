//
// Created by PRINCE NDHLOVU on 4/15/20.
//
#include <iostream>
#include "SearchEngine.h"
#include "IndexHandler.h"
#include "DocumentParser.h"
#include "QueryParser.h"
#include "UserInterface.h"
using namespace std;

int main(int argc, char* argv[])
{

    UserInterface ui;

    ui.searchEngine();

    return 0;
}
