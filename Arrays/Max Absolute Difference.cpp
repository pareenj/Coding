int Solution::maxArr(vector<int> &A) {

    int n = A.size();
    int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
    int res = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        max1 = max(max1, A[i] + i); // A[i] + i
        max2 = max(max2, A[i] - i); // A[i] - i
        min1 = min(min1, A[i] + i); // A[i] + i
        min2 = min(min2, A[i] - i); // A[i] - i
    }

    res = max(res, max1 - min1);
    res = max(res, max2 - min2);

    return res;
}