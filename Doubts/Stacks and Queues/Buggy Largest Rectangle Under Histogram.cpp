#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

long largestRectangle(vector<int> h)
{
    int n = h.size();
    
    stack<int> s;
    
    long maxArea = INT_MIN;
    int i, top;
    for(i = 0; i < n; i++)
    {
        if(i == 0)
        {
            s.push(0);
            continue;
        }
        top = s.top();
        int curr = h[i];
        if(curr >= h[top])
        {
            s.push(i);
        }
        else
        {
            while(h[i] <= curr)
            {
                s.pop();
                i++;
            }
        }
    }
    
    while(!s.empty())
    {
        long area;
        s.pop();
        if(s.empty())
        {
            area = h[top] * i;
        }
        else
        {
            area = h[top] * (i - top - 1);
            top = s.top();
        }
        maxArea = max(area, maxArea);
    }
    return maxArea;
}

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    long result = largestRectangle(h);
    cout << result << endl;
    return 0;
}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

long largestRectangle(vector<int> h)
{
    int n = h.size();
    
    stack<int> s;
    
    long maxArea = INT_MIN;
    int i = 0, top;
    long area;
    
    while(i < n)
    {
        if(s.empty() || h[i] >= h[s.top()]) s.push(i++);
        else
        {
            top = s.top();
            s.pop();
            
            if(s.empty())
            {
                area = h[top]*i;
            }
            else
            {
                area = h[top]*(i - s.top() - 1);
            }
            
            maxArea = max(area, maxArea);
        }
    }
    
    while(!s.empty())
    {
        top = s.top();
        s.pop();
        if(s.empty())
        {
            area = h[top]*i;
        }
        else
        {
            area = h[top]*(i - s.top() - 1);
        }
        
        maxArea = max(area, maxArea);
    }
    
    return maxArea;
}

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    long result = largestRectangle(h);
    cout << result << endl;
    return 0;
}