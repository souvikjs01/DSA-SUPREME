#include<iostream>
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

    cout << "insertion done" <<endl; 
    // cout << searchWord(root, "loved") << endl;
    // cout << searchWord(root, "love") << endl;
    
    // deletion
    cout << searchWord(root, "cat") << endl;
    deleteWord(root, "cat");
    cout << searchWord(root, "cat") << endl;
    return 0;
}