#include<iostream>
#include<vector>
using namespace std;

class TriNode{
public:
    char value;
    TriNode* children[26];
    bool isTerminal;

    TriNode(char val){
        this->value = val;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

// insertion
void insertWord(TriNode* root, string word){
    // cout << "recieved word: " << word << endl;
    if(word.size() == 0){
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    int indx = ch - 'a';
    TriNode* child;
    if(root->children[indx] != NULL){
        child = root->children[indx];
    }
    else{
        child = new TriNode(ch);
        root->children[indx] = child;
    }
    // recursion
    insertWord(child, word.substr(1));
}

// searching word
bool searchWord(TriNode* root, string word){
    if(word.size() == 0){
        return root->isTerminal;
    }
    char ch = word[0];
    int indx = ch - 'a';
    TriNode* child;
    if(root->children[indx] != NULL){
        child = root->children[indx];
    }
    else{
        return false;
    }
    return searchWord(child, word.substr(1));
}

// deletion
void deleteWord(TriNode* root, string word){
    if(word.size() == 0){
        root->isTerminal = false;
        return;
    }
    char ch = word[0];
    int indx = ch - 'a';
    TriNode* child;
    if(root->children[indx] != NULL){
        // present
        child = root->children[indx];
    }
    else{
        // not present
        return;
    }
    deleteWord(child, word.substr(1));
}

void storeString(TriNode* root, vector<string>&ans, string &input, string &prefix){
    // base case:
    if(root->isTerminal == true){
        // ans store
        ans.push_back(prefix + input);
    }
    for(char ch='a'; ch<='z'; ch++){
        int indx = ch - 'a';
        TriNode* next = root->children[indx];
        if(next != NULL){
            // child exist
            input.push_back(ch);
            // recursion
            storeString(next, ans, input, prefix);
            // backtracking
            input.pop_back();
        }
    }
}
void findPrefixString(TriNode* root, string input, vector<string> &ans, string &prefix){
    // base case
    if(input.size() == 0){
        TriNode* lastchar = root;
        storeString(lastchar, ans, input, prefix);
        return;
    }
    char ch = input[0];
    int indx = ch - 'a';
    TriNode* child;
    if(root->children[indx] != NULL){
        child = root->children[indx];
    }
    else{
        // not found
        return;
    }
    // recursion
    findPrefixString(child, input.substr(1), ans, prefix);
}

vector<vector<string>> getSuggestions(TriNode* root, string input){
    vector<vector<string>> output;
    TriNode* prev = root;
    string inputHepler = "";
    for(int i=0; i<input.size(); i++){
        char lastChar = input[i];
        int indx = lastChar-'a';
        TriNode* curr = prev->children[indx];
        if(curr == NULL){
            break;
        }
        else{
            vector<string> nichekeans;
            inputHepler.push_back(lastChar);
            string dummy = "";
            storeString(curr, nichekeans, inputHepler, dummy);
            output.push_back(nichekeans);
            // imp
            prev = curr;
        }
    }
    return output;
}
int main(){
    TriNode *root = new TriNode('-');
    // insertWord(root, "donation");

    insertWord(root, "cater"); 
    insertWord(root, "care");
    insertWord(root, "com");
    insertWord(root, "lover");
    insertWord(root, "loved");
    insertWord(root, "load");
    insertWord(root, "lov");
    insertWord(root, "bat"); 
    insertWord(root, "cat");
    insertWord(root, "car");
    insertWord(root, "jokar");
    insertWord(root, "joke");
    insertWord(root, "joking");
    insertWord(root, "jokra");
    insertWord(root, "jokre");
    insertWord(root, "jokes");

    cout << "insertion done" <<endl; 

    // string input = "c"; // output: cat, car, cater, care, com
    // string prefix = input; 
    // vector<string> ans;
    // findPrefixString(root, input, ans, prefix);
    // for(auto i : ans){
    //     cout << i << " ";
    // }cout << endl;

    vector<vector<string>> ans = getSuggestions(root, "loa");
    // printing ans:
    for(int i=0; i<ans.size(); i++){
        cout << i <<" -> " ;
        for(auto st: ans[i]){
            cout << st << " ";
        } cout << endl; 
    }

    return 0;
}