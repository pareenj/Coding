class Bucket {
public:
    bool used = false;
    int minval = INT_MAX;
    int maxval = INT_MIN;
};

int Solution::maximumGap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int sz = A.size();
    if(A.empty() || sz < 2) return 0;
    
    int mini = *min_element(A.begin(), A.end());
    int maxi = *max_element(A.begin(), A.end());
    
    int bucketSize = max(1, (maxi - mini)/((int)sz - 1));
    int bucketNum = (maxi - mini) / bucketSize + 1;
    vector<Bucket> buckets(bucketNum);
    
    for(auto&& num: A)
    {
        int bucketIndex = (num - mini)/bucketSize;
        buckets[bucketIndex].used = true;
        buckets[bucketIndex].minval = min(num, buckets[bucketIndex].minval);
        buckets[bucketIndex].maxval = max(num, buckets[bucketIndex].maxval);
    }
    
    int prevBucketMax = mini, maxGap = 0;
    for(auto&& bucket: buckets)
    {
        if(!bucket.used) continue;
        maxGap = max(maxGap, bucket.minval - prevBucketMax);
        prevBucketMax = bucket.maxval;
    }
    
    return maxGap;
}

//https://leetcode.com/articles/maximum-gap/
