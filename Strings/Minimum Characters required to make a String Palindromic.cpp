vector<int> computeLPSArray(string A)
{
	int m = A.length();
	vector<int> lps(m);

	int len = 0;
	lps[0] = 0;

	int i = 1;
	while(i < m)
	{
		if(A[i] == A[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len != 0) len = lps[len-1];
			else lps[i++] = 0;
		}
	}
	return lps;
}


int Solution::solve(string A) {
    
    string reverseString = A;
	reverse(reverseString.begin(), reverseString.end());

	string concat = A + "$" + reverseString;

	vector<int> lps = computeLPSArray(concat);

	return(A.length() - lps.back());
}

// http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/
// http://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/