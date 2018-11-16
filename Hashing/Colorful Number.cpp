int Solution::colorful(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A == NULL) return 0;

    vector<int> vec;

    // long long int product = 1;
    while(A != 0)
    {
    	// product = product * (A % 10);
    	vec.insert(vec.begin(), A % 10);
    	A = A/10;
    }
    int n = vec.size();

    unordered_map<long long int, long long int> hashMap;
    for(int i = 0; i < n; i++)
    {
    	long long int value = 1;
    	for(int j = i; j < n; j++)
    	{
    		value = value * vec[j];
    		if(hashMap.find(value) != hashMap.end()) return 0;
    		hashMap.insert({value, value});
    	}
    }

    return 1;
}