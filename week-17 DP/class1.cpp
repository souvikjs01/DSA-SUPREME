#include<iostream>
#include<vector>
using namespace std;
int fibTopDown(int n, vector<int>&dp){
    // top down approach :
    // step-1: base case
    if(n == 0 || n == 1){
        dp[n] = n;
        return n;
    }
    // step-3: if ans is already exist then return ans
    if(dp[n] != -1){
        return dp[n];
    }
    // step-2: store ans and return ans using dp array
    dp[n] = fibTopDown(n-1, dp) + fibTopDown(n-2, dp);
    return dp[n];
}
int fibBootomUp(int n, vector<int> &dp){
    // fill initial data to dp array according to the recursion base case: 
    dp[0] = 0;
    if(n == 0){
        return dp[0];
    }
    dp[1] = 1;
    // fill the remaining dp array according to recursive formula
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    // return ans:
    return dp[n];
}
int fibSpaceOpt(int n){
    int prev = 0;
    if(n == 0){
        return prev;
    }
    int curr = 1;
    if(n == 1){
        return curr;
    }
    int ans = 0;
    for(int i=2; i<=n; i++){
        ans = prev + curr;
        prev = curr;
        curr = ans;
    }
    return ans;
}
int main(){
    // fibonacci number using dp: (top to down approach) called MEMOIZATION
    // create dp array:
    int n = 4;
    vector<int> dp(n+1, -1); 
    int ans = fibTopDown(n, dp);
    cout << ans << endl;

    // fibonacci number using dp: (bottom up approach) called TABULATION
    int ans2 = fibBootomUp(n, dp);
    cout << ans2 << endl;

    // fibonacci number using dp: (patterns approach) called SPACE OPTIMIZATION
    int ans3 = fibSpaceOpt(n);
    cout << ans3 << endl;
    return 0;
}