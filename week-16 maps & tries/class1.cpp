#include<iostream>
#include<unordered_map>
using namespace std;

void countChar(unordered_map<char, int> &mapping, string str){
    for(int i : str){
        if(i != ' ')
            mapping[i]++;
    }
}
int main(){
    // creation:
    unordered_map<string, int> mapping;

    // insertion:
    pair<string, int> p = make_pair("souvik", 85); 
    pair<string, int> q = make_pair("gaurav", 22);
    pair<string, int> r = make_pair("deepak", 18);

    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);
    mapping["joseph"] = 29;
    mapping["babbar"] = 2;

    cout<< "size of mapping "<< mapping.size() << endl;
    cout << mapping["souvik"] << endl;
    cout << mapping.at("deepak") << endl;
    cout << mapping["joseph"]<< endl;

    cout << mapping.count("souvik") << endl;  // if present then 1 else 0
    // traversal:
    if(mapping.find("joseph") != mapping.end()){
        cout<< "found" << endl;
    }else{
        cout << "not found"<< endl;
    }

    cout << mapping.size() << endl;
    cout << mapping["pranab"] << endl;  // it was not present in the past but now it will be included
    cout << mapping.size() << endl;


    // love babbar : count number of letter
    string str = "love babbar";
    unordered_map<char, int> letterToInt;
    countChar(letterToInt, str);
    for(auto i:letterToInt){
        cout << i.first << " -> " << i.second << endl;
    }
    return 0;
}