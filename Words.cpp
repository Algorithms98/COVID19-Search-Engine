//
// Created by PRINCE NDHLOVU on 4/16/20.
//

#include "Words.h"
Words::Words() {
    totalWordFrequency = 0;
    text = "";

}
Words::Words(string query, pair<string, int> loc ) {

    totalWordFrequency = loc.second;
    text = query;
    file.push_back(loc);

}
Words::Words(string query, string files) {

    totalWordFrequency = 0;
    text = query;
    formatQuery();
    removePunctuation();
    stemWords();
    addFile(files);

}

Words::Words(string query) {

    totalWordFrequency = 0;
    text = query;
    formatQuery();
    removePunctuation();
    stemWords();

}

void Words::removePunctuation() {

    int varLen = text.size();
    for(int i = 0; i < varLen; i++){
        if(ispunct(text[i])){
            text.erase(i--, 1);
            varLen = text.size();
        }
    }


}
void Words::stemWords() {

    Porter2Stemmer::trim(text);
    Porter2Stemmer::stem(text);

}
string Words::getQuery() {

    return text;

}

vector<pair<string, int>>& Words::getFiles() {
    return file;

}

int Words::getTotalWordFrequency() {

    return totalWordFrequency;

}

void Words::formatQuery() {
    locale fix;
    for(int i = 0; i < text.length(); i++){
        text[i] = tolower(text[i], fix);
    }

}

bool Words::operator<(const Words & query) {

    return text < query.text;
}
bool Words::operator>(const Words & query) {

    return text > query.text;
}

ostream& operator<<(ostream & buffer, const Words & querry) {

    buffer << querry.text << querry.file.size();
    for(pair<string, int> loc: querry.file){
        buffer << loc.second << " " << loc.first << endl;
    }
    return buffer;
}

bool Words::operator==(const Words & query) {
    return text == query.text;
}
int Words::fileLocation(string fileName) {

    for(int i =0; i< file.size(); i++){
        if(file[i].first == fileName){
            return i;
        }
    }

    return -1;
}

void Words::addFileIndex(pair<string, int> files) {

    totalWordFrequency += files.second;
    file.push_back(files);
}

void Words::addFile(string fileName) {

    totalWordFrequency += 1;
    int location = fileLocation(fileName);
    if(location != -1){
        file[location].second += 1;
    }else{
        file.push_back(pair<string, int>(fileName, 1) );

    }

}

