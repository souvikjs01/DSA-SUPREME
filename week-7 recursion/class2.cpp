#include<iostream>
#include<vector>
#include<limits>
using namespace std;

// store even no in an array using recursion:
void storeEven(int *arr, int size,int index, vector<int> &v){
    if(index >= size){
        return;
    }
    int element = arr[index];
    if(element%2 == 0){
        v.push_back(element);
    }
    // recursive call:
    storeEven(arr, size, index+1, v);
}

// find maximum element of an array using recursion:
void maxElement(int *arr, int size, int &maxi, int index){
    if(index >= size){
        return;
    }
    int element = arr[index];
    maxi = max(maxi, element);
    maxElement(arr, size, maxi, index+1);
}

// find minimum element of an array using recursion:
void minElement(int *arr, int size, int &mini, int index){
    if(index >= size){
        return;
    }
    int element = arr[index];
    mini = min(mini, element);
    minElement(arr, size, mini, index+1);
}

// search key element in the array:-
bool searchArray(int arr[], int size, int key, int index){
    if(index >= size){
        return false;
    }
    int element = arr[index];
    if(element == key){
        return true;
    }
    searchArray(arr, size, key, index+1);
}

// reverse the array
void printingRevArray(int arr[], int size, int index){
    if(index >= size){
        return;
    }
    printingRevArray(arr, size, index+1);
    cout << arr[index] << " ";
}

// printing the array using recursion:
void printingArray(int arr[], int size, int index){
    if(index >= size){
        return;
    }
    cout << arr[index] << " ";
    printingArray(arr, size, ++index);
}

// printing digits of a number using recursion:
void printDigits(int num, vector<int> &v){
    if(num == 0){
        return;
    }
    int temp = num%10;
    num = num/10;
    printDigits(num, v);

    v.push_back(temp);
}
int main(){
    // -------------------------------------------------------------------------
    // int num = 4217;
    // vector<int> ans;
    // printDigits(num, ans);
    // for(auto n: ans){
    //     cout << n << " ";
    // } cout << endl;

    // ----------------------------------------------------------------------------
    // int arr[] = {11,20,31,40,51};
    // int size = 5;
    // int index = 0;
    // printingArray(arr, size, index);
    // cout << endl;
    // printingRevArray(arr, size, index);
    // cout << endl;
    // int key1 = 31;
    // int key2 = 90;
    // cout << searchArray(arr, size, key1, index) << endl;
    // cout << searchArray(arr, size, key2, index) << endl;

    // --------------------------------------------------------------------------------
    int arr[] = {24, 18, 10, 67, 10, 80};
    int size = sizeof(arr)/sizeof(int);
    int index = 0;
    // int mini = INT16_MAX;
    // int maxi = INT64_MIN;
    // minElement(arr, size, mini, index);
    // cout << mini << endl;
    // maxElement(arr, size, maxi, index);
    // cout << maxi << endl;
    // store even element:
    vector<int> ans;
    storeEven(arr, size, index, ans);
    for(auto n: ans){
        cout << n << " ";
    }cout << endl;


    return 0;
}