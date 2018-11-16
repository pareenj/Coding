#include <bits/stdc++.h>

using namespace std;

double currencies(int n, int x, int s, int f, int m, vector < vector<double> > A) {
    // Complete this function
}

int main() {
    int n;
    cin >> n;
    int x;
    int s;
    int f;
    int m;
    cin >> x >> s >> f >> m;
    vector< vector<double> > A(n,vector<double>(n));
    for(int A_i = 0;A_i < n;A_i++){
       for(int A_j = 0;A_j < n;A_j++){
          cin >> A[A_i][A_j];
       }
    }
    return 0;
}
