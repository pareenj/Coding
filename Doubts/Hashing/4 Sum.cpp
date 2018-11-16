void twoSum(vector<int> &A, int B, int start, int end, vector<vector<int> > &ans, int first, int second)
{
	if(start >= end) return;

	int maxElement = A[end];
	int minElement = A[start];

	if(2 * minElement > B || 2 * maxElement < B) return;

	int i = start, j = end;
	while(i < j)
	{
		int sum = A[i] + A[j];
		if(sum == B)
		{
			vector<int> row;
			row.push_back(first);
			row.push_back(second);
    		row.push_back(A[i]);
    		row.push_back(A[j]);
			ans.push_back(row);

			int ithElement = A[i];
			int jthElement = A[j];

			// Avoid Duplicates
			while(i < j && ithElement == A[i]) i++;
			while(j > i && jthElement == A[j]) j--;
		}

		if(sum < B) i++;
		if(sum > B) j--;
	}
	return;
}

void threeSum(vector<int> &A, int B, int start, int end, vector<vector<int> > &ans, int first)
{
	// Corner case
	if(start + 1 >= end) return;

	int maxElement = A[end];
	int minElement = A[start];
	if(3*minElement > B || 3*maxElement < B) return;

	for(int i = start; i < end; i++)
	{
		int ithElement = A[i];

		// Avoid duplicates
    	if(i > start && ithElement == A[i-1]) continue;

    	// ithElement is very small
    	if(ithElement + (2*maxElement) < B) continue;

    	// ithElement is very large
    	if(3*ithElement > B) break;

    	// if ithElement is the boundary
    	if(3*ithElement == B)
    	{
    		if(i + 2 < end && A[i+2] == ithElement)
    		{
    			vector<int> row;
    			row.push_back(first);
    			row.push_back(ithElement);
    			row.push_back(ithElement);
    			row.push_back(ithElement);
    			ans.push_back(row);
    		}
    		break;
    	}

    	twoSum(A, B - ithElement, i + 1, end, ans, first, ithElement);
	}
}

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int> >ans;
    int n = A.size();
    if(n < 4) return ans;

    sort(A.begin(), A.end());

    int maxElement = A[n-1];
    int minElement = A[0];
    if(4*minElement > B || 4*maxElement < B) return ans;

    for(int i = 0; i < n; i++)
    {
    	int ithElement = A[i];

    	// Avoid duplicates
    	if(i > 0 && ithElement == A[i-1]) continue;

    	// ithElement is very small
    	if(ithElement + (3*maxElement) < B) continue;

    	// ithElement is very large
    	if(4*ithElement > B) break;

    	// if ithElement is the boundary
    	if(4*ithElement == B)
    	{
    		if(i + 3 < n && A[i+3] == ithElement)
    		{
    			vector<int> row;
    			row.push_back(ithElement);
    			row.push_back(ithElement);
    			row.push_back(ithElement);
    			row.push_back(ithElement);
    			ans.push_back(row);
    		}
    		break;
    	}

    	threeSum(A, B - ithElement, i + 1, n - 1, ans, ithElement);
    }

    return ans;
}

// https://discuss.leetcode.com/topic/29585/7ms-java-code-win-over-100
// http://www.geeksforgeeks.org/find-four-numbers-with-sum-equal-to-given-sum/
// http://www.geeksforgeeks.org/find-four-elements-that-sum-to-a-given-value-set-2/
// http://www.geeksforgeeks.org/find-four-elements-sum-given-value-set-3-hashmap/