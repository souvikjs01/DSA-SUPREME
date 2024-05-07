#include<iostream>
using namespace std;
int factorial(int n){
    // base case
    if(n==1 || n==0){
        return n;
    }
    // rec call
    return n*factorial(n-1);
}
int twoPower(int n){
    if(n == 0){
        return 1;
    }
    return 2*twoPower(n-1);
}
int fibonacciNthTerm(int n){
    if(n == 1 || n == 0){
        return n;
    }
    return fibonacciNthTerm(n-1)+fibonacciNthTerm(n-2);
}

int main(){
    // int num = 5;
    // cout << factorial(num) << endl;
    // cout << twoPower(num) << endl;
    cout << fibonacciNthTerm(7) << endl;

    return 0;
}