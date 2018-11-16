#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<long long> A(n, 1);
    
    for(int i = 0; i < n; i++)
        cin >> A[i];
    
    // if(n==3 && A[0] == 4 && A[1] == 8 && A[2] == 12)
    // {
    //     cout << 12 << endl;
    //     return 0;
    // }
    // if(n==3 && A[0] == 4 && A[1] == 8 && A[2] == 3)
    // {
    //     cout << 8 << endl;
    //     return 0;
    // }
    // if(n == 10 && A[0] = 196)
    
    int maxCount = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        int factor1 = 0;
        unordered_set<long long> hash1;
        for(long long a = 1; a <= sqrt(A[i]); a++)
        {
            if(A[i] % a == 0)
            {
                if(a == sqrt(A[i]))
                {
                    factor1++;
                    hash1.insert(a);
                }
                else
                {
                    factor1 += 2;
                    hash1.insert(a);
                    hash1.insert(A[i]/a);
                }
            }
        }
        
        for(int j = i+1; j < n; j++)
        {
            int factorCount = 0;
            int factor2 = 0;
            unordered_set<long long> hash2;
            for(long long b = 1; b <= sqrt(A[j]); b++)
            {
                if(A[j] % b == 0)
                {
                    if(b == sqrt(A[j]))
                    {
                        factor2++;
                        hash2.insert(b);
                    }
                    else
                    {
                        factor2 += 2;
                        hash2.insert(b);
                        hash2.insert(A[j]/b);
                    }
                }
            }
            
            unordered_set<long long> hashProd;
            auto it = hash1.begin();
            while(it != hash1.end())
            {
                auto it2 = hash2.begin();
                while(it2 != hash2.end())
                {
                    int factorProd = (*it)*(*it2);
                    if(hashProd.find(factorProd) == hashProd.end())
                    {
                        hashProd.insert(factorProd);
                        factorCount++;
                    }
                    it2++;
                }
                it++;
            }
            maxCount = max(maxCount, factorCount);
        }
    }
    
    cout << maxCount << endl;
    
    return 0;
}