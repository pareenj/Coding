int Solution::findMedian(vector<vector<int> > &A) {
    
    int n = A.size(), m = A[0].size();
    int min = A[0][0], max = A[n-1][m-1];
    
    for(int i = 0; i < n; i++)
    {
        if(A[i][0] < min) min = A[i][0];
        if(A[i][m-1] > max) max = A[i][m-1];
    }
    
    int elements_count = (1 + n*m)/2;
    
    while(min < max)
    {
        int mid = (min + max)/2;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            // int low = 0, high = n-1;
            // int midi;
            // while(low <= high)
            // {
            //     midi = (low + high)/2;
            //     if(mid == A[i][midi]) 
            //     {
            //         while(A[i][midi] == mid) midi--;
            //         count += midi+1;
            //         break;
            //     }
            //     else if (mid < A[i][midi]) high = midi-1;
            //     else low = midi+1;
            // }
            // if(A[i][midi] != mid) count += midi+1;
            
            count += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        }
        if(count < elements_count) min = mid + 1;
        else max = mid;
    }
    return min;
}

//http://www.geeksforgeeks.org/median-of-two-sorted-arrays/

// Painter's Partition Problem
//https://www.youtube.com/watch?v=GdnpQY2j064
//https://www.youtube.com/watch?v=QQsyiNNEp1g
//https://jackygao.wordpress.com/2014/09/04/the-painters-partition-problem-part-i/
//https://jackygao.wordpress.com/2014/09/04/the-painters-partition-problem-part-ii/

// Allocate Books
// http://www.geeksforgeeks.org/allocate-minimum-number-pages/

// Median of Array
// https://discuss.leetcode.com/topic/4996/share-my-o-log-min-m-n-solution-with-explanation
// https://discuss.leetcode.com/topic/16797/very-concise-o-log-min-m-n-iterative-solution-with-detailed-explanation/2
// http://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/
// https://www.youtube.com/watch?v=MHNTl_NvOj0
// https://www.youtube.com/watch?v=_H50Ir-Tves
