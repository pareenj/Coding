#include <bits/stdc++.h>

using namespace std;

bool myComp(pair<int,int> a, pair<int,int> b)
{
    return (a.second < b.second);
}

long buyMaximumProducts(int n, long k, vector <int> a) {
    // Complete this function
    vector<pair<int,int> > b;
    // cout << "enter" << endl;
    for(int i = 0; i < n; i++) 
    {
        b.push_back(make_pair(i+1, a[i]));
    }
    sort(b.begin(), b.end(), myComp);
    
    long count = 0;
    for(int i = 0; i < n; i++)
    {
        if((long)b[i].second * b[i].first <= k)
        {
            count += b[i].first;
            k -= (long)b[i].second * b[i].first;      
        }
        else
        {
            long c = k/(b[i].second);
            count += c;
            k -= c*b[i].second;
            // break;
        }
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    long k;
    cin >> k;
    long result = buyMaximumProducts(n, k, arr);
    cout << result << endl;
    return 0;
}