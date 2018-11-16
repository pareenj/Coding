long long int fact(int n) {
	return(n <= 1) ? 1 : n*fact(n-1);
}

// A utility function to count smaller characters on right of arr[low]
int findSmallerinRight(string s, int low, int high) {
	int countRight = 0;

	for(int i = low+1; i <= high; i++)
	{
		if(s[i] < s[low]) countRight++;
	}

	return countRight;
}

int Solution::findRank(string A) {
    
    int len = A.length();
	long long int mul = fact(len);
	long long int rank = 1, countRight;

	for(int i = 0; i < len; i++)
	{
		mul = mul/(len - i);

		// count number of chars smaller than str[i] fron str[i+1] to str[len-1]
		countRight = findSmallerinRight(A, i, len-1);

		rank += countRight * mul;
	}
	
	rank %= 1000003;

	return (int) rank;
}

// http://www.geeksforgeeks.org/lexicographic-rank-of-a-string/
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

long long int fact(int n) {
	return(n <= 1) ? 1 : n*fact(n-1);
}

// Construct a count array where value at every index contains count of smaller characters in whole string
void populateAndIncreaseCount(int* count, string A)
{
	for(int i = 0; A[i]; i++) ++count[A[i]];
	for(int i = 1; i < 256; i++) count[i] += count[i-1];
}

// Removes a character ch from count[] array constructed by populateAndIncreaseCount()
void updateCount(int* count, char c)
{
	for(int i = c; i < 256; i++) --count[i];
}

// A function to find rank of a string in all permutations of characters
int Solution::findRank(string A) {

	int len = A.length();
	long long int mul = fact(len);
	long long int rank = 1;

	int count[256] = {0}; // all elements of count[] are initialized with 0

	// Populate the count array such that count[i] contains count of characters which are present in str and are smaller than i
	populateAndIncreaseCount(count, A);

	for(int i = 0; i < len; i++)
	{
		mul = mul/(len-1);

		// count number of chars smaller than str[i] fron str[i+1] to str[len-1]
		rank += count[A[i] - 1]*mul;

		// Reduce count of characters greater than str[i]
		updateCount(count, A[i]);
	}

	return rank;
}