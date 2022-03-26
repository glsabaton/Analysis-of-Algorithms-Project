//
//  main.cpp
//  proje1
//
//  Created by Mehmet Ali Kısacık on 20.12.2021.
//

#include <fstream>
#include "include/olestem/stemming/english_stem.h"
#include <list>
#include "StopWords.hpp"
#include <chrono>

using namespace std;

struct sentenceNode {
    int num;
    int point;
    };

sentenceNode createSentence(int num){
    sentenceNode* a;
    a  = new sentenceNode();
    a->num = num;
    a->point = 1;
    return *a;
}

struct Node
{
    string word;
    Node *left = nullptr;
    Node *right = nullptr;
    list<int> sentenceList;
};

Node* CreateNode(string word,int sentenceNum)
{
    Node* node = new Node();
    node->word = word;
    node->left = nullptr;
    node->right = nullptr;
    node->sentenceList.insert(node->sentenceList.end(), sentenceNum);
    return(node);
}

Node* insertWord(Node* node, string word, int sentenceNum)
{
    if (node == NULL){
        return(CreateNode(word,sentenceNum));
    }
    else if (word[2] < node->word[2])
        node->left = insertWord(node->left, word, sentenceNum);
    else if (word[2] > node->word[2])
        node->right = insertWord(node->right, word , sentenceNum);
    else if ( word[2] == node->word[2] && word != node->word)
        node->right = insertWord(node->right,word , sentenceNum);
    else if ( word == node->word){
        node->sentenceList.insert(node->sentenceList.end(), sentenceNum);
    }

    return node;
}

list<int> searchWord(Node* node,string word){
    if(node == NULL){
        list<int> list;
        return list;
    }
    else if(word[2] < node->word[2])
        return searchWord(node->left, word);
    else if(word[2] > node->word[2])
        return searchWord(node->right, word);
    else if ( word[2] == node->word[2] && word != node->word)
        return searchWord(node->right, word);
    else if (word == node->word)
        return node->sentenceList;
    else{
        list<int> list;
        return list;
    }
}

struct WordStruct{
    Node* wordArr[26][26];
    
    void insert(string word,int sentenceNum){
        if(word.length() == 1 || word.length() == 2 ){
            return;
        }
        else if (word[0]<123 && 96<word[0] == false){
            return;
        }
        else if (word[1]<123 && 96<word[1] == false){
            return;
        }
        wordArr[word[0]-97][word[1]-97] = insertWord(wordArr[word[0]-97][word[1]-97], word,sentenceNum);
        }
    
    list<int> search(string word){
        if(word.length() == 1 || word.length() == 2){
            list<int> a;
            return a;
        }
        else if (word[0]<123 && 96<word[0] == false){
            list<int> a;
            return a;
        }
        
        return searchWord(wordArr[word[0]-97][word[1]-97], word);
    }
};


stemming::english_stem<> StemEnglish;
string stem(string word){
    wstring w(word.begin(),word.end());
    StemEnglish(w);
    string str(w.begin(),w.end());
    return str;
}

list<string> originalSentenceList;
list<string> findSentence(int num){
    originalSentenceList.clear();
    list<string> sentenceWordsList;
    ifstream file;
    string fileName = "the_truman_show_script.txt";
    file.open(fileName);
    
    string word;
    int sentenceNum = 0;
    bool newSentence = false;
    
    if (file.is_open() == true){
        while(file >> word){
            int size = word.length();
            // make all letters lowercase
            for(int i = 0;i<word.length();i++){
                if(word[i] > 64 && word[i] < 91){
                    word[i] = word[i] + 32;
                }
            }
            if (size >1 && (word[size-1] == '.'  || word[size-1] == '!' || word[size-1] == '?')  ){
                string modifiedWord(word.begin(),word.end()-1);
                word = modifiedWord;
                newSentence = true;
            }
            else if(size >1 && word[size-1] == 34 && (word[size-2] == '.' || word[size-2] == '!' || word[size-2] == '?') ){
                string modifiedWord(word.begin(),word.end()-2);
                word = modifiedWord;
                newSentence = true;
            }

            string originalWord = word;
            word = stem(word);

            if (check(word)) {
                if(newSentence){
                    sentenceNum++;
                    newSentence = false;
                }
                continue;
            }

            if (sentenceNum == num) {
                originalSentenceList.push_back(originalWord);
                sentenceWordsList.push_back(word);
            }
            else if (sentenceNum == num+1){
                return sentenceWordsList;
            }

            if (newSentence){
                sentenceNum++;
                newSentence = false;
            }

            
        }
        
        file.close();
    }
    else{
        cout << "file not open" << endl;
    }
    
    return sentenceWordsList;
}

void getQuestion(string question,WordStruct *w){

    string qWord = "";
    list<sentenceNode> sentenceList;
    list<string> questionWords;
    for ( char ch : question){
        if (ch == ' ' || ch == '?'){
            // make lower case
            for(int i = 0;i< int(qWord.length());i++){
                if(qWord[i] > 64 && qWord[i] < 91){
                    qWord[i] = qWord[i] + 32;
                }
            }
            // if it is not stop word get the list of sentences that it was used
            if (!check(qWord)){
                qWord = stem(qWord);
                list<int> liste = w->search(qWord);
                questionWords.insert(questionWords.end(), qWord);
                list<int>::iterator it;
                for (it = liste.begin(); it != liste.end(); it++) {
                    list<sentenceNode>::iterator i;
                    bool exists = false;
                    //check whether exists
                    for(i = sentenceList.begin(); i != sentenceList.end(); i++){
                        if(i->num == *it){
                            exists = true;
                            i->point++;
                        }
                    }
                    if(!exists){
                        sentenceList.insert(sentenceList.end(), createSentence(*it));
                    }
                }
            }
            qWord = "";
        }
        else{
            qWord = qWord + ch;
        }
    }
    // get biggest number
    list<sentenceNode>::iterator it;
    int biggestPoint = 0;
    int relatedSentence = 0;
    for(it = sentenceList.begin(); it != sentenceList.end(); it++){
        if (it->point > biggestPoint) {
            biggestPoint = it->point;
            relatedSentence = it->num;
        }
    }
    list<string> sentenceWords = findSentence(relatedSentence);
    // original sentence as list
    
    // find answer stemmed
    list<string>::iterator z;
    string answerStemmed;
    for(z = sentenceWords.begin(); z != sentenceWords.end(); z++){
        if (*z != *find(questionWords.begin(), questionWords.end(), *z)) {
            answerStemmed = *z;
        }
    }
    
    list<string>::iterator m;
    string answer;
    int biggestMatch = -1;
    int stemmedSize = int(answerStemmed.length());
    for(m = originalSentenceList.begin(); m != originalSentenceList.end(); m++){
        string nonStemmed= *m;
        int matchCount = 0;
        int iterationCount;
        if(stemmedSize < int(nonStemmed.length()) ){
            iterationCount = stemmedSize;
        }
        else{
            iterationCount = int(nonStemmed.length());
        }
        
        for(int i=0;i<iterationCount;i++){
            if(answerStemmed[i] == nonStemmed[i]){
                matchCount++;
            }
        }
        if (matchCount > biggestMatch){
            answer = nonStemmed;
            biggestMatch = matchCount;
        }
    }
    cout << answer << endl << endl;
    
}
int main() {

    WordStruct *w;
    w = new WordStruct();
    
    ifstream file;
    string fileName = "the_truman_show_script.txt";
    file.open(fileName);
    
    string word;
    int sentenceNum = 0;
    bool newSentence = false;
    if (file.is_open() == true){
        while(file >> word){
            int size = int(word.length());
            // make all letters lowercase
            for(int i = 0;i<word.length();i++){
                if(word[i] > 64 && word[i] < 91){
                    word[i] = word[i] + 32;
                }
            }
            
            if ((word[size-1] == '.'  || word[size-1] == '!' || word[size-1] == '?')  ){
                string modifiedWord(word.begin() ,word.end()-1);
                word = modifiedWord;
                newSentence = true;
            }
            else if(size >1 && word[size-1] == 34 && (word[size-2] == '.' || word[size-2] == '!' || word[size-2] == '?') ){
                string modifiedWord(word.begin(),word.end()-2);
                word = modifiedWord;
                newSentence = true;
            }
            if (check(word)) {
                if(newSentence){
                    sentenceNum++;
                    newSentence = false;
                }
                continue;
            }
            word = stem(word);
            w->insert(word, sentenceNum);
            if (newSentence){
                sentenceNum++;
                newSentence = false;
            }
        }
        
        file.close();
    }
    else{
        cout << "file is not open" << endl;
    }
    
    ifstream questionFile;
    string questionFileName = "questions.txt";
    questionFile.open(questionFileName);
    // get question
    
    int questionNum = 0;
    if(questionFile.is_open()){
        string q;
        while (getline(questionFile,q)) {
            questionNum++;
            cout << questionNum << ") ";
            cout << q << endl;
            getQuestion(q, w);
        }
        questionFile.close();
    }
    else{
        cout << "file is not open" << endl;
    }

    return 0;
}

