// http://www.geeksforgeeks.org/stock-buy-sell/
// http://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/
// http://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-k-times/
// https://www.youtube.com/watch?v=oDhu5uGq_ic

#include <bits/stdc++.h>

using namespace std;

// Function to find out maximum profit by buying &
// selling/ a share atmost k times given stock price
// of n days
int traderProfit(int k, int n, vector <int> A) {
    // Complete this function
    
    // table to store results of subproblems
    // profit[t][i] stores maximum profit using atmost
    // t transactions up to day i (including day i)
    int profit[k+1][n+1];
    
    // For day 0, you can't earn money
    // irrespective of how many times you trade
    for(int i = 0; i <= k; i++) profit[i][0] = 0;
    
    // profit is 0 if we don't do any transation
    // (i.e. k =0)
    for (int j = 0; j <= n; j++) profit[0][j] = 0;
    
    // fill the table in bottom-up fashion
    for(int i = 1; i <= k; i++)
    {
        int prevDiff = INT_MIN;
        for(int j = 1; j < n; j++)
        {
            prevDiff = max(prevDiff, profit[i-1][j-1] - A[j-1]);
            profit[i][j] = max(profit[i][j-1], A[j] + prevDiff);
        }
    }
    return profit[k][n-1];
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        int result = traderProfit(k, n, arr);
        cout << result << endl;
    }
    return 0;
}