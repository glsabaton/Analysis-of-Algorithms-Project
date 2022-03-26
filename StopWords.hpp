#ifndef StopWords_hpp
#define StopWords_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

string a[15] = {"a","about","above","after","again","against","all","am","an","and","any","are","aren't","as","at"};
string b[10] = {"be","because","been","before","being","below","between","both","but","by"};
string c[4] = {"can't","cannot","could","couldn't"};
string d[9] = {"did","didn't","do","does","doesn't","doing","don't","down","during"};
string e[1] = {"each"};
string f[4] = {"few","for","from","further"};
string h[21] = {"had","hadn't","has","hasn't","have","haven't","having","he","he'd","he'll","he's","her","here","here's","hers","herself","him","himself","his","how","how's"};
string i[14] = {"i","i'd","i'll","i'm","i've","if","in","into","is","isn't","it","it's","its","itself"};
string l[1] = {"let's"};
string m[6] = {"me","more","most","mustn't","my","myself"};
string n[3] = {"no","nor","not"};
string o[14] = {"of","off","on","once","only","or","other","ought","our","ours","ourselves","out","over","own"};
string s[11] = {"same","shan't","she","she'd","she'll","she's","should","shouldn't","so","some","such"};
string t[22] = {"than","that","that's","the","their","theirs","them","themselves","then","there","there's","these","they","they'd","they'll","they're","they've","this","those","through","to","too"};
string u[3] = {"under","until","up"};
string v[1] = {"very"};
string w[26] = {"was","wasn't","we","we'd","we'll","we're","we've","were","weren't","what","what's","when","when's","where","where's","which","while","who","who's","whom","why","why's","with","won't","would","wouldn't"};
string y[9] = {"you","you'd","you'll","you're","you've","your","yours","yourself","yourselves"};

bool check(string str){
        
        if (str[0] == 'a'){
            for(int i = 0; i < sizeof(a)/sizeof(string); i++){
                if (a[i] == str){
                    return true;
                }
            }
        }
        else if (str[0] == 'b'){
            for(int i = 0; i < sizeof(b)/sizeof(string); i++){
                if (b[i] == str){
                    return true;
                }
            }
        }
        else if (str[0] == 'c'){
                    for(int i = 0; i < sizeof(c)/sizeof(string); i++){
                        if (c[i] == str){
                            return true;
                        }
                    }
                }
        else if (str[0] == 'd'){
                    for(int i = 0; i < sizeof(d)/sizeof(string); i++){
                        if (d[i] == str){
                            return true;
                        }
                    }
                }
        else if (str[0] == 'e'){
                    for(int i = 0; i < sizeof(e)/sizeof(string); i++){
                        if (e[i] == str){
                            return true;
                        }
                    }
                }
        else if (str[0] == 'f'){
                    for(int i = 0; i < sizeof(f)/sizeof(string); i++){
                        if (f[i] == str){
                            return true;
                        }
                    }
                }
        else if (str[0] == 'h'){
                    for(int i = 0; i < sizeof(h)/sizeof(string); i++){
                        if (h[i] == str){
                            return true;
                        }
                    }
                }
        else if (str[0] == 'i'){
                    for(int m = 0; m < sizeof(i)/sizeof(string); m++){
                        if (i[m] == str){
                            return true;
                        }
                    }
                }
        else if (str[0] == 'l'){
                    for(int i = 0; i < sizeof(l)/sizeof(string); i++){
                        if (l[i] == str){
                            return true;
                        }
                    }}
        else if (str[0] == 'm'){
                    for(int i = 0; i < sizeof(m)/sizeof(string); i++){
                        if (m[i] == str){
                            return true;
                        }
                    }
                }
        else if (str[0] == 'n'){
                    for(int i = 0; i < sizeof(n)/sizeof(string); i++){
                        if (n[i] == str){
                            return true;
                        }
                    }
                }
        else if (str[0] == 'o'){
                    for(int i = 0; i < sizeof(o)/sizeof(string); i++){
                        if (o[i] == str){
                            return true;
                        }
                    }
                }
        else if (str[0] == 's'){
                    for(int i = 0; i < sizeof(s)/sizeof(string); i++){
                        if (s[i] == str){
                            return true;
                        }
                    }
                }
        else if (str[0] == 't'){
                    for(int i = 0; i < sizeof(t)/sizeof(string); i++){
                        if (t[i] == str){
                            return true;
                        }
                    }
                }
        else if (str[0] == 'u'){
                    for(int i = 0; i < sizeof(u)/sizeof(string); i++){
                        if (u[i] == str){
                            return true;
                        }
                    }
                }
        else if (str[0] == 'v'){
                    for(int i = 0; i < sizeof(v)/sizeof(string); i++){
                        if (v[i] == str){
                            return true;
                        }
                    }
                }
        else if (str[0] == 'w'){
                    for(int i = 0; i < sizeof(w)/sizeof(string); i++){
                        if (w[i] == str){
                            return true;
                        }
                    }
                }
        else if (str[0] == 'y'){
                    for(int i = 0; i < sizeof(y)/sizeof(string); i++){
                        if (y[i] == str){
                            return true;
                        }
                    }
                }        
        return false;
    }
  
    
    
#endif /* StopWords_hpp */
