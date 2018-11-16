bool isPalindrome(string A, int low, int high)
{
	while(low < high)
	{
		if(A[low] != A[high]) return false;
		low++;
		high--;
	}
	return true;
}

// Recursive function to find all palindromic partitions of str[start..n-1]
// palPart --> A vector of vector of strings. Every vector inside it stores
//           a partition
// currPart --> A vector of strings to store current partition 
void palPartition(vector<vector<string> > &palPart, vector<string> &currPart, int start, int n, string A)
{
	// If 'start' has reached length
	if(start >= n)
	{
		palPart.push_back(currPart);
		return;
	}

	// Pick all possible ending points for substrings
	for(int i = start; i < n; i++)
	{
		// If substring A[start...i] is a palindrome
		if(isPalindrome(A, start, i))
		{
			// Add the substring to result
			currPart.push_back(A.substr(start, i - start + 1));

			// Recur for remaining substrings
			palPartition(palPart, currPart, i + 1, n, A);

			// Remove substring A[start...i] from current partition
			currPart.pop_back();
		}
	}
}

vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	int n = A.length();

	// To Store all palindromic partitions
	vector<vector<string> > palPart;

	// To store current palindromic partition
	vector<string> currPart;

	// Call recursive function to generate all partiions and store in allPart
	palPartition(palPart, currPart, 0, n, A);

	return palPart;
}

// http://www.geeksforgeeks.org/given-a-string-print-all-possible-palindromic-partition/
// https://discuss.leetcode.com/topic/6186/java-backtracking-solution