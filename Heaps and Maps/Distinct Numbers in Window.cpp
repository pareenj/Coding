vector<int> Solution::dNums(vector<int> &A, int B) {

	vector<int> ans;

	int n = A.size();
	if(B > n) return ans;

	// Create an empty hash map
	map<int, int> hashMap;

	// Initialize distinct elements count for current window
	int distinctCount = 0;

	// Traverse the first window and store count of every element in hash map
	for(int i = 0; i < B; i++)
	{
		if(hashMap.find(A[i]) == hashMap.end())
		{
			hashMap[A[i]] = 1;
			distinctCount++;
		}
		else
		{
			hashMap[A[i]]++;
		}
	}

	ans.push_back(distinctCount);

	// Traverse through the remaining array
	for(int i = B; i < n; i++)
	{
		// Remove first element of previous window

		// If there was only one occurrence, then reduce distinct count
		if(hashMap[A[i-B]] == 1)
		{
			hashMap.erase(A[i-B]);
			distinctCount--;
		}
		else // Reduce count of the removed element
		{
			hashMap[A[i-B]]--;
		}


		// Add new element of current window

		// If this element appears for the first time, increment distinct elements count
		if(hashMap.find(A[i]) == hashMap.end())
		{
			hashMap[A[i]] = 1;
			distinctCount++;
		}
		else // Increment count of the element
		{
			hashMap[A[i]]++;
		}

		ans.push_back(distinctCount);
	}

	return ans;
}

// http://www.geeksforgeeks.org/count-distinct-elements-in-every-window-of-size-k/
// https://leetcode.com/problems/sliding-window-maximum/description/