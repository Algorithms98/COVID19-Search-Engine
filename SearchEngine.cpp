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

/*
 * AND keyword querry processor
 */
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
    displayResults(final);

}

/*
 * Rank the articles
 */
void SearchEngine::PrinceRank(vector < pair <string, int > > articles) {
    for(pair<string, int> doc : articles ){

        int termFreq = doc.second;
       // double documentFreq = articles.size() / numOfArticles;
        double rank = termFreq * (articles.size() / numOfArticles);
        rankedArticles.push_back(pair<string, int>(doc.first, rank));
    }

   //sort(rankedArticles.begin(), rankedArticles.end())

}

/*
 * OR keyword querry processor
 */
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
    displayResults(final);

}

/*
 * NOT keyword querry processor
 */
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
    displayResults(final);

}

/*
 * Checks if the string has been indexed or exists in the corpus
 */
bool SearchEngine::hasWord(string& article) {

    if(index->hasElement(article)){
        return true;
    }

    return false;
}

void SearchEngine::getQuery() {
    QueryParser qp;
    userQuery = qp.getUserInput();
    bool found = qp.hasAuthor();
    HashTable<string,string> scientists = parse.getAuthors();

    //if there is one word in the Q or the search querry is just one word
    if(userQuery.size() == 1){
        vector<pair<string, int>> v;
        if(hasWord(userQuery.front())){         //check if the word has been indexed
            v = pullRequests(userQuery.front());
        }
        userQuery.pop();
        displayResults(v);
        v.clear();
    }
    else if(userQuery.front() == "not"){
        notLogic();

    } else if(userQuery.front() == "and") {
        andLogic();

    } else if(userQuery.front() == "or"){
        orLogic();
    } else if(found == true){

        vector<pair<string, int>> v;
        vector<pair<string, int>> arr[userQuery.size()];        //array of a vector of pairs

        for(int i = 0; i < userQuery.size(); i++){

            if(userQuery.front() != "author"){

                if(hasWord(userQuery.front())){

                    v = pullRequests(userQuery.front());
                    arr[i ] = v;
                    userQuery.pop();
                    v.clear();
                }
            } else{
                userQuery.pop();
               // scientists.getIndexKey(userQuery.front());
               // scientists.getIndexValue(userQuery.front());
            }

        }

    }

}

/*
 *Look for the word in the file Index
 */
vector<pair <string, int>> SearchEngine::pullRequests(string article) {

    Words file = index->wordLocation(article);

    return file.getFiles();

}

void SearchEngine::displayResults(vector <pair< string, int > > info ) {

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

        cout << "Would you like to open the files? Y / N \n";
        char choice;
        cin >> choice;

        locale fix;
        choice = toupper(choice, fix );

        if(choice == 'Y'){

            viewArticles();

        }else if(choice == 'N'){

            cout << "Thank you \n";

        }else{

            cout << "Please enter the option Y / N \n";

        }

       // viewArticles();

        rankedArticles.clear();

    }
    else {
        cout << "The search Engine / indexer could not find any articles \n";
    }

}

/*
 * Opens and displays the selected file
 */
void SearchEngine::viewArticles() {

    cout << "Which article would you like to view \n";
    string article;
    getline(cin, article);

    article = article.substr(0, article.length() - 4);

    ifstream rFile(article);

    if(!rFile.is_open()){
        cout << "Could not open file, but it exists \n";
    }
    else{
        string row;
        getline(rFile, row);
        while(!rFile.eof()){
            cout << row << endl;
            getline(rFile, row);
        }
    }

    rFile.close();

}
vector< pair <string, int>> SearchEngine::andSearch(vector < pair <string, int >  > & final, vector < pair <string,
                                                  int > > & initial) {

    vector<pair<string, int>> andVector;
    for(int i = 0; i < final.size(); i++){
        for(int j = 0; j < initial.size(); j ++){
            if(final[i].first == initial[j].first){
                final[i].second = initial[j].second + final[i].second;
                andVector.push_back(make_pair(final[i].first, final[i].second));
            }
        }
    }

    return andVector;
}

vector<pair <string, int>> SearchEngine::orSearch(vector < pair <string, int >  > & final, vector < pair <string, int >  > & initial) {

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

vector<pair <string, int>> SearchEngine::notSearch(vector < pair <string, int >  >& final , vector < pair< string,
                                                  int > > & initial) {

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
