//
// Created by PRINCE NDHLOVU on 4/19/20.
//

#include "SearchEngine.h"

SearchEngine::SearchEngine() {

}

SearchEngine::SearchEngine(IndexInterface * handle, int num) {

    index = handle;
    numOfArticles = num;

}

void SearchEngine::andLogic() {
    vector<pair<string, int>> initial;
    vector<pair<string, int>> final;

    while (!userQuery.empty()){
        if(userQuery.front() == "not"){
            userQuery.pop();
            if(hasWord(userQuery.front())){
                initial =pullRequests(userQuery.front());
                if(!final.empty()){
                    final = notSearch(final, initial);
                }
            }
        } else {
            if(hasWord(userQuery.front())){
                initial = pullRequests(userQuery.front());
                if(final.empty()){
                    final = initial;
                } else {
                    final = andSearch(final, initial);
                }
            }
        }
        userQuery.pop();
    }
    display(final);

}

void SearchEngine::PrinceRank(vector < string, int > < pair > articles) {
    for(pair<string, int> doc : articles ){

        int termFreq = doc.second;
       // double documentFreq = articles.size() / numOfArticles;
        double rank = termFreq * (articles.size() / numOfArticles);
        rankedArticles.push_back(pair<string, int>(doc.first, rank));
    }

   //sort(rankedArticles.begin(), rankedArticles.end())

}

void SearchEngine::orLogic() {

    vector<pair<string, int>> initial;
    vector<pair<string, int>> final;

    while (!userQuery.empty()){
        if(userQuery.front() == "or"){
            userQuery.pop();
            if(hasWord(userQuery.front())){
                initial =pullRequests(userQuery.front());
                if(!final.empty()){
                    final = notSearch(final, initial);
                }
            }
        } else {
            if(hasWord(userQuery.front())){
                initial = pullRequests(userQuery.front());
                if(final.empty()){
                    final = initial;
                } else {
                    final = orSearch(final, initial);
                }
            }
        }
        userQuery.pop();
    }
    display(final);

}

void SearchEngine::notLogic() {

    vector<pair<string, int>> initial;
    vector<pair<string, int>> final;

    while (!userQuery.empty()){
        if(userQuery.front() == "not"){
            userQuery.pop();
            if(hasWord(userQuery.front())){
                initial =pullRequests(userQuery.front());
                if(!final.empty()){
                    final = notSearch(final, initial);
                }
            }
        } else {
            if(hasWord(userQuery.front())){
                initial = pullRequests(userQuery.front());
                if(final.empty()){
                    final = initial;
                } else {
                    final = orSearch(final, initial);
                }
            } else{
                //
            }
        }
        userQuery.pop();
    }
    display(final);

}

bool SearchEngine::hasWord(string article) {

    if(index->hasElement(article)){
        return true;
    }

    return false;

}

void SearchEngine::getQuery() {
    QueryParser qp;
    userQuery = qp.getUserInput();

    if(userQuery.size() == 1){
        vector<pair<string, int>> v;
        if(hasWord(userQuery.front())){
            v = getQuery(userQuery.front());
        }
        userQuery.pop();
        display(v);
    }
    else if(userQuery.front() == "not"){
        notLogic();

    } else if(userQuery.front() == "and") {
        andLogic();

    } else{
        orLogic();
    }

}

void SearchEngine::display(vector < string, int > < pair > ) {

}

vector<string, int><pair> SearchEngine::pullRequests(string article) {

    Words file = index->find(article);

    return file.getFiles();

}

void SearchEngine::displayResults(vector < string, int > < pair > info ) {

    if(!info.empty()){

        cout << "Search results: " << endl;
        cout << info.size() << " articles were indexed." << endl;
        PrinceRank(info);

        for(int i = 0; i < rankedArticles.size() && i < 15; i++ ){

            cout << i + 1 << ". " << rankedArticles[i].first << " \n";
            cout << rankedArticles[i].second << " Appearances \n";
            cout << endl;
            cout << endl;
        }

        rankedArticles.clear();

//        for(int j = 0; j < rankedArticles.size(); j ++) {
//            rankedArticles.pop_back();
//        }

    }
    else {
        cout << "The search Engine / indexer could not find any articles \n";
    }

}

void SearchEngine::simpleSearch(string article) {
    vector<pair<string, int>> info;

    if(hasWord(article)){
        info = pullRequests(article);

    }
    displayResults(info);

}

vector<string, int><pair> SearchEngine::andSearch(vector < string, int > < pair > & final, vector < string,
                                                  int > < pair > & initial) {

    vector<pair<string, int>> andVector;
    for(int i = 0; i < final.size(); i++){
        for(int j = 0; j < initial.size(); j ++){
            if(final[i].first == initial[j].first){
                final[i].second = initial[j].second + final[i].second;
                andVector.push_back(make_pair(final[i].first, final[i].second))
            }
        }
    }

    return andVector;
}

vector<string, int><pair> SearchEngine::orSearch(vector < string, int > < pair > & final, vector < string, int > < pair > & initial) {

    for(int i = 0; i < final.size(); i++){
        for(int j = 0; j < initial.size(); j ++){
            if(final[i].first == initial[j].first) {
                final[i].second = initial[j].second + final[i].second;
                initial.erase(initial.begin() + j);
            }
        }
    }

    for(pair<string, int> orPair: initial){
        final.push_back(orPair);
    }

    return final;

}

vector<string, int><pair> SearchEngine::notSearch(vector < string, int > < pair >& final , vector < string,
                                                  int > < pair > & initial) {

    for(int i = 0; i < final.size(); i++){
        for(int j = 0; j < initial.size(); j ++){
            if(final[i].first == initial[j].first){
                final.erase(final.begin() +i);
                initial.erase(initial.begin() + j);
            }

        }
    }

    return final;
}
