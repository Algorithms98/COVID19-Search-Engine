//
// Created by PRINCE NDHLOVU on 4/15/20.
//
#include <iostream>
#include "UserInterface.h"
#include <set>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
    cout << "Welcome to my Search Engine \n";
    cout << "You have can load data into this search engine by selecting option 1 \n";
    cout << "Or you can search for data by selecting option 2 \n";


    UserInterface ui;

    ui.searchEngine();

    return 0;
}
