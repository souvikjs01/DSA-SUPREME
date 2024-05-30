//navsack problem:
#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecursion(int wt[], int val[], int capacity, int ind, int n){
    if(ind >= n){
        return 0;
    }
    int include = 0;
    if(wt[ind] <= capacity){
        include = val[ind] + solveUsingRecursion(wt,val,capacity-wt[ind],ind+1,n);
    }
    int exclude = 0 + solveUsingRecursion(wt,val,capacity,ind+1,n);
    int ans = max(include, exclude);
    return ans;
}
int solveUsingMem(int capacity, int wt[], int profit[], int index, int n, vector<vector<int> >& dp) {
	//base case
	if(index >=n) {
		return 0;
	}

	//already exists
	if(dp[capacity][index] != -1){
		return dp[capacity][index];
	}

	//inc / exc
	int include = 0;
	if(wt[index] <= capacity) {
		include = profit[index] + solveUsingMem(capacity-wt[index], wt, profit, index+1, n, dp);
	}
	int exclude = 0 + solveUsingMem(capacity, wt, profit, index+1, n, dp);
	dp[capacity][index] = max(include, exclude);
	return dp[capacity][index];
}
int solveUsingTabulation(int capacity, int wt[], int profit[], int n) {
	vector<vector<int> > dp(capacity+1, vector<int>(n+1, -1));

	for(int row = 0; row<=capacity; row++) {
		dp[row][n] = 0;
	}

	for(int i=0; i<=capacity; i++) {
		for(int j=n-1; j>=0; j--) {
			int include = 0;
			if(wt[j] <= i) {
				include = profit[j] + dp[i-wt[j]][j+1];
			}
			int exclude = 0 + dp[i][j+1];
			dp[i][j] = max(include, exclude);
		}
	}

	//printdparray(dp);
	return dp[capacity][0];
	
}
int solveUsingSO(int capacity, int wt[], int profit[], int n) {
	vector<int> next(capacity+1, 0);
	vector<int> curr(capacity+1, -1);


	for(int j=n-1; j>=0; j--) {
		for(int i=0; i<=capacity; i++) {
			int include = 0;
			if(wt[j] <= i) {
				include = profit[j] + next[i-wt[j]];
			}
			int exclude = 0 + next[i];
			curr[i] = max(include, exclude);
		}
		//shifting
		next = curr;
	}
	return curr[capacity];
}
int main(){
    int weight[3] = {10,20,30};
    int value[3] = {60, 100, 120};
    int capacity = 50;
    // int ans = solveUsingRecursion(weight, value, capacity, 0, 3);
    // cout << ans << endl;

    // memoization:
    int n = 3;
    vector<vector<int> > dp(capacity+1, vector<int>(n+1, -1));
    // int ans = solveUsingMem(capacity, weight, value, 0,n,dp);
    // cout << ans <<endl;

    // tabolation:
    // int ans = solveUsingTabulation(capacity, weight, value, n);
    // cout << ans << endl;

    // space optimization:
    int ans = solveUsingSO(capacity, weight, value, n);
    cout << ans << endl;
    return 0;
}

/*
// painting fence problem:
#include<iostream>
#include<vector>
using namespace std;
int solveUsingRecursion(int n, int k){
    if(n == 1){
        return k;
    }
    if(n == 2){
        return (k + k*(k-1));
    }
    int ans = (solveUsingRecursion(n-1,k) + solveUsingRecursion(n-2,k))*(k-1);
    return ans;
}
int solveUsingMemo(int n, int k, vector<int> &dp){
    if(n == 1){
        return k;
    }
    if(n == 2){
        return (k + k*(k-1));
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = (solveUsingMemo(n-1,k,dp) + solveUsingMemo(n-2,k,dp))*(k-1);
    return dp[n];
}
int solveUsingTabulation(int n, int k){
    vector<int> dp(n+1, -1);
    dp[1] = k;
    dp[2] = k+k*(k-1);
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2])*(k-1);
    }
    return dp[n];
}
int spaceOptim(int n, int k){
    int prev2 = k, prev1 = k+k*(k-1);
    if(n == 1) return prev2;
    if(n == 2) return prev1;
    int curr;
    for(int i=3; i<=n; i++){
        curr = (prev1 + prev2)* (k-1);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main(){
    int n = 3; // number of colors
    int k = 3; // number of posts
    // vector<int> dp(n+1, -1);
    // int answer = solveUsingMemo(n,k,dp);
    // cout << answer << endl;

    // tabulation:
    // int ans = solveUsingTabulation(n,k);
    // cout << ans << endl;

    // space optimization:
    int ans = spaceOptim(n, k);
    cout << ans << endl;
    return 0;
}
*/