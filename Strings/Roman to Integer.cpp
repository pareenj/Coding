int value(char c)
{
	if(c == 'I') return 1;
	if(c == 'V') return 5;
	if(c == 'X') return 10;
	if(c == 'L') return 50;
	if(c == 'C') return 100;
	if(c == 'D') return 500;
	if(c == 'M') return 1000;

	return 0;
}

int Solution::romanToInt(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.length();
	int ans = value(A[n-1]);

	for(int i = n-2; i >= 0; i--)
	{
		int prev = value(A[i]), next = value(A[i+1]);
		if(prev < next) ans -= prev;
		else ans += prev;
	}
	return ans;
}
