#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <cstring>
using namespace std;

int find(vector<string> s, string f){
    for(int i = 0;i < s.size() ; ++i){
        if(s[i].compare(f) == 0){
            return i;
        }
    }
    return -1;
}

int main() {
    int n,m;
    vector<string> query;
    vector<string> value;
    vector<string> input;
    cin >> n >> m;
    string current = "";
    string tag = "";
    string te;
    //cin.ignore();
    while (getline(cin, te)) {

        //cout << te.size() << endl;
        if(te.size() !=0 )
            input.push_back(te);
    }
    for(int i = 0;i < n ; ++i){
        string t  = input[i];
        cout << t << endl;
        vector<string> temp;
        if( t.substr(1,1).compare("/")  == 0 ){
            int m = t.find(">");

            if(tag.find(".") != string::npos )
                tag.erase(tag.end() - (m - 1), tag.end());//</hi>
            else{
                tag.erase(tag.end() - (m - 2), tag.end());//</hi>
            }
                continue;
        }
        else{
            istringstream iss(t);
            copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(temp));
            if(tag == ""){
                tag = temp[0].substr(1);
            }else
                tag += "." + temp[0].substr(1);
             bool isKey = true;
             int j = 1;
            while(j < temp.size()){
                if(isKey){
                    query.push_back(tag + "~" + temp[j]);
                    isKey = false;
                }else{
                    if(temp[j].compare("=")) {
                        ++j;
                        continue;
                    }
                    value.push_back(temp[j]);
                    isKey = true;
                }
                ++j;
            }
            temp.clear();
        }

    }
    for(int i = 0 ; i < query.size() ; ++i){
        cout << query[i] << "--" << value[i] << endl;
    }
    for(int i = n;i < n + m ; ++i){
        string t = input[i];
        cout << "hi" << endl;
    //int j = find(query,t);
    //cout << value[j] << endl;
    }
    return 0;
}


