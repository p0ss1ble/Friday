#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


void stat_tolstoy(string name) {
    map<char, int> alphabet{};
    char c;

    for (int i = 0, c = 'A'; i < 32; ++i,++c){
        alphabet[c] = 0;
    }  

    string s;
    ifstream file(name);

    while(getline(file, s)){ 
        for(const auto& i : s) {
            if ('A' <= i && i <= 'Z'){
                alphabet[i]++;
            }
            else if ('a' <= i && i <= 'z'){
                alphabet[char(toupper(i))]++;
            }
        }

    }
    file.close();
    for (auto it = alphabet.begin(); it != alphabet.end(); ++it){
        cout << (*it).first << " : " << (*it).second << endl;
    }
    cout << endl << endl;
}


int main(){
    stat_tolstoy("volume_1.txt");
    return 0;
}