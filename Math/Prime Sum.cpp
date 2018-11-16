vector<int> Solution::primesum(int A) {
    
	vector<bool> isPrime(A+1);
	fill(isPrime.begin(), isPrime.end(), true);
	isPrime[0] = isPrime[1] = false;

	vector<int> ans;

	for(int i = 2; i <= sqrt(A); i++)
	{
		if(isPrime[i])
		{
			for(int j = 2; i*j <= A; j++) isPrime[i*j] = false;
		}
	}

	for(int i = 2; i <= A/2; i++)
	{
		if(isPrime[i])
		{
			if(isPrime[A-i])
			{
				ans.push_back(i);
				ans.push_back(A-i);
				return ans;
			}
		}
	}    
}
