int Solution::diffPossible(const vector<int> &A, int B) {

    int n = A.size();
    if(n < 2 || B < 0) return false;
    unordered_set <int> hashSet;
      
    for(int i = 0; i < n; i++)
    {
        int a_j = A[i] - B;
        int a_k = A[i] + B;

        if(hashSet.find(a_j) != hashSet.end()) return true;
        if(hashSet.find(a_k) != hashSet.end()) return true;

        hashSet.insert(A[i]);
    }

    return false;
}

// http://www.geeksforgeeks.org/find-a-pair-with-the-given-difference/