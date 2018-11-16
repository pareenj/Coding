int gcd(int m, int n)
{
	if(m < n)
	{
		int temp = m;
		m = n;
		n = temp;
	}

	if(n != 0 && m % n == 0) return n;

	while(n != 0)
	{
		int temp = m;
		m = n;
		n = temp % n;
	}

	return m;
}

int Solution::cpFact(int A, int B) {
    
    int x = A;

	while(gcd(x, B) != 1)
	{
		x /= gcd(x, B);
	}

	return x;
}
