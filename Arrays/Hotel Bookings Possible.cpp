bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {

    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    int n1 = arrive.size(), n2 = depart.size();
    int n = min(n1, n2);

    // i - Arrive Index
    // j - Depart Index
    // k - No. of rooms required
    // K - No. of rooms available

    int k = 0;

    for(int i = 0, j = 0; i < n && j < n;)
    {
        if(arrive[i] < depart[j])
        {
            k++;
            i++;

            if(k > K) 
            {
                return false;
            }
        }

        if(depart[j] <= arrive[i])
        {
            k--;
            j++;
        }
    }

    return true;
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());

    // i - Arrive Index
    // j - Depart Index
    // k - No. of rooms required
    // K - No. of rooms available
    
    int i, j, k, n;
    n = arrive.size();
    i = j = k = 0;
    while(i < n && j < n)
    {
        if(arrive[i] < depart[j])
        {
          k++;
          i++;
          if(k > K) return 0;
        }
        else
        {
            k--;
            j++;
        }
    }
    return 1;
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
        
    int i = 0, j = 0, n = arrive.size();
    int start = arrive[0], end = depart[n - 1];
    while(start <= end)
    {
        while((j < n) && (start == depart[j]))
        {
            K++;
            j++;
        }
        while((i < n) && (start == arrive[i]))
        {
            if(K > 0) K--;
            else return false;
            i++;
        }
        start++;
    }
    return true;
}

// http://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/