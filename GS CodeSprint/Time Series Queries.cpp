#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int q;
    cin >> n >> q;
    vector<int> t(n);
    for(int t_i = 0; t_i < n; t_i++){
       cin >> t[t_i];
    }
    vector<int> p(n);
    for(int p_i = 0; p_i < n; p_i++){
       cin >> p[p_i];
    }
    for(int a0 = 0; a0 < q; a0++){
        int _type;
        int v;
        cin >> _type >> v;
    }
    return 0;
}
