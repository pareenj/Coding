#include <bits/stdc++.h>

using namespace std;

string feeOrUpfront(int n, int k, int x, long long int d, vector <int> p) {
    // Complete this function
    double sum = 0;
    for(int i = 0; i < n; i++)
    {
        double feei = (p[i]/100.0)*x;
        double maxi = max(double(k), feei);
        sum += maxi;
        if(sum > d) return "upfront";
    }
    return "fee";
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int k;
        int x;
        long long int d;
        cin >> n >> k >> x >> d;
        vector<int> p(n);
        for(int p_i = 0; p_i < n; p_i++){
           cin >> p[p_i];
        }
        string result = feeOrUpfront(n, k, x, d, p);
        cout << result << endl;
    }
    return 0;
}