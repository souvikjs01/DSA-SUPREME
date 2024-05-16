
#include<iostream>
#include<vector>
using namespace std;

void lastOccur(string &str, int &lastIndx, int index, char ch){
    if(index < 0){
        return;
    }
    if(str[index] == ch){
        lastIndx = index;
        return;
    }
    lastOccur(str, lastIndx, index-1, ch);
}

void reverseString(string &s, int first, int end){
    if(first >= end){
        return;
    }
    swap(s[first], s[end]);
    
    reverseString(s, first+1, end-1);
}

void printSubArray_utils(vector<int>&v, int start, int end){
    if(end == v.size()){
        return;
    }
    for(int i=start; i<= end; i++){
        cout << v[i] << " ";
    } cout << endl;

    printSubArray_utils(v, start, end+1);
}
void printSubArray(vector<int>&v){
    for(int i=0; i<v.size(); i++){
        int end = i;
        printSubArray_utils(v, i, end);
    }
}

int main(){
    // last occurence of a char:--------
    // string str = "abcddedg";
    // int lastIndx = -1;
    // int index = str.size()-1;
    // char ch = 'd';
    // lastOccur(str,lastIndx,index,ch);
    // cout << lastIndx << endl;


    // question: reverse a string using recursion:--------2
    // string str = "brooklyn";
    // reverseString(str, 0, str.size()-1);
    // cout << str << endl;
    // string str2 = "i love brooklyn city";
    // reverseString(str2, 0, str2.size()-1);
    // cout << str2 << endl;
    
    // print all subarray:-----------
    vector<int> v = {1,2,3,4,5,6};
    printSubArray(v);
    
    return 0;
}

// reverse string


