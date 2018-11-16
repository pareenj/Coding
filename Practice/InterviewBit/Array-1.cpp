ARRAYS INTERVIEWBIT 

int Solution::coverPoints(vector<int> &X, vector<int> &Y) {

	int total_steps = 0;
	int length = X.size();

	for(int i = 0; i < length - 1; i++)
	{
		x_diff = abs(X[i] - X[i+1]);
		y_diff = abs(Y[i] - Y[i+1]);
		higher_diff = max(x_diff, y_diff);

		total_steps += higher_diff;
	}

	return total_steps;
}

vector<int> Solution::plusOne(vector<int> &A) {

    A.push_back(0);
    int n = A.size();
    for(int i = n-1; i > 0; i--)
    {
    	A[i] = A[i-1];
    }
    A[0] = 0;

    int sum = 0, carry = 1;
    for(int i = n-1; i >= 0; i--)
    {
    	sum = A[i] + carry;
    	A[i] = (sum % 10);
    	carry = sum/10;
    	if(carry == 0)
    		break;
    }

    while(A[0] == 0)
    	A.erase(A.begin());

    return A;
}

int Solution::maxSubArray(const vector<int> &A) {

	int currentSum = 0, maxSum = INT_MIN;

	for(int i = 0; i < A.size(); i++)
	{
		currentSum += A[i];
		maxSum = max(maxSum, currentSum);
		if(currentSum < 0) currentSum = 0;
	}

	return maxSum;
}

int Solution::maxArr(vector<int> &A) {

	int n = A.size();

	int max1 = INT_MIN, max2 = INT_MIN;
	int min1 = INT_MAX, min2 = INT_MAX;

	for(int i = 0; i < n; i++)
	{
		max1 = max(max1, i + A[i]);
		max2 = max(max2, i - A[i]);
		min1 = min(min1, i + A[i]);
		min2 = min(min2, i - A[i]);
	}

	return max(max1 - min1, max2 - min2);
}

vector<int> Solution::repeatedNumber(const vector<int> &A) {

    int n = A.size();
    vector<int> ans(2);
    vector<int> copy = A;

    for(int i = 0; i < n; i++)
    {
    	x = abs(copy[i]);

    	if(copy[x-1] > 0) copy[x-1] *= -1;
    	else ans.push_back(x);
    }

    for(int i = 0; i < n; i++)
    {
    	if(copy[i] > 0)
    		ans.push_back(i + 1);
    }

    return ans;
}

vector<int> Solution::flip(string A) {

	vector<int> ans;
	int n = A.length();

	int currentSum = 0, maxSum = INT_MIN;
	int leftIndex = 0, rightIndex = 0, leftCheck = 0;

	for(int i = 0; i < n; i++)
	{
		int val;
		if(A[i] == '1')
			val = -1;
		else
			val = 1;

		currentSum += val;

		if(currentSum > maxSum)
		{
			leftIndex = leftCheck;
			rightIndex = i;
			maxSum = currentSum;
		}

		if(currentSum < 0)
		{
			currentSum = 0;
			leftCheck = i + 1;
		}
	}

	if(maxSum <= 0)
	{
		return ans;
	}

	ans.push_back(leftIndex + 1);
	ans.push_back(rightIndex + 1);

	return ans;
}

vector<int> Solution::flip(string A) {

    int n = A.length();

    vector<int> ans;

    // int origZerosCount = 0;
    int currMaxDiff = 0, maxDiff = INT_MIN;
    int startIndex = 0, endIndex = 0, left = 0;

    for(int i = 0; i < n; i++)
    {
        int val = (A[i] == '1') ? -1 : 1;

        currMaxDiff += val;

        if(currMaxDiff > maxDiff)
        {
            maxDiff = currMaxDiff;
            startIndex = left;
            endIndex = i;
        }

        if(currMaxDiff < 0)
        {
            left = i + 1;
            currMaxDiff = 0;
        }
    }

    if(maxDiff <= 0)
        return ans;
    else
    {
        ans.push_back(startIndex + 1);
        ans.push_back(endIndex + 1);
    }

    return ans;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<vector<int> > Solution::solve(int A) {

	vector<vector<int> > ans;

	if(A == 0)
		return ans;

	vector<int> row1;
	row1.push_back(1);
	ans.push_back(row1);

	if(A == 1)
		return ans;

	for(int i = 2; i <= A; i++)
	{
		int current_size = ans.size();
		
		vector<int> row, prevRow;
		prevRow = ans[current_size-1]
		row.push_back(1);

		for(int j = 0; j < current_size-1; j++)
		{
			row.push_back(prevRow[j] + prevRow[j+1]);
		}

		row.push_back(1);
		ans.push_back(row);
	}

	return ans;
}

vector<int> Solution::getRow(int A) {

	vector<int> ans;

	int ith = 1;
	ans.push_back(ith);

	if(A == 0)
		return ans;

	for(int i = 1; i <= A; i++)
	{
		ith *= (A-i+1)/i;
		ans.push_back(ith);
	}

	return ans;
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {

	int size = arrive.size();
	int n = 0, maxRooms = INT_MIN;

	sort(arrive.begin(), arrive.end());
	sort(depart.begin(), depart.end());

	int i = 0, j = 0;

	for(; i < size || j < size;)
	{
		if(arrive[i] < depart[j])
		{
			n++;
			i++;
			maxRooms = max(n, maxRooms);
		}
		else
		{
			n--;
			j++;
		}
	}

	if(maxRooms < K)
	{
		return 1;
	}
	else
		return 0;
}

vector<int> Solution::subUnsort(vector<int> &A) {

	int n = A.size();

    int left = n-1, right = 0;

    for(int i = 0; i < n-1; i++)
    {
        if(A[i] > A[i+1])
        {
            left = i;
            break;
        }
    }
    
    vector<int> ans;
    if(left == n-1)
    {
        ans.push_back(-1);
        return ans;
    }

    for(int i = n-1; i > 0; i--)
    {
        if(A[i] <= A[i-1])
        {
            right = i;
            break;
        }
    }

    int minValue = A[left], maxValue = A[right];
    for(int i = left; i <= right; i++)
    {
        minValue = min(minValue, A[i]);
        maxValue = max(maxValue, A[i]);
    }

    int leftIndex = left, rightIndex = right;
    for(int i = 0; i < left; i++)
    {
        if(A[i] > minValue)
        {
            leftIndex = i;
            break;
        }
    }

    for(int i = n-1; i > right; i--)
    {
        if(A[i] < maxValue)
        {
            rightIndex = i;
            break;
        }
    }

    ans.push_back(leftIndex);
    ans.push_back(rightIndex);

    return ans;
}

int Solution::maximumGap(const vector<int> &A) {

	int n = A.size();

	vector<int> leftMin(n);
	vector<int> rightMax(n);

	int lMin = INT_MAX, rMax = INT_MIN;
	for(int i = 0; i < n; i++)
	{
		lMin = min(lMin, A[i]);
		leftMin[i] = lMin;
	}

	for(int i = n-1; i >= 0; i--)
	{
		rMax = max(rMax, A[i]);
		rightMax[i] = rMax;
	}

	int maxGap = -1;

	int i = 0, j = 0;

	while(i < n && j < n)
	{
		if(leftMin[i] <= rightMax[j])
		{
			maxGap = max(maxGap, j-i);
			j++;
		}
		else
		{
			i++;
		}
	}

	return maxGap;
}

int Solution::repeatedNumber(const vector<int> &A) {

	int n = A.size();
	vector<int> copy(n/2 + 1, 0);

	for(int i = 0; i < n; i = i + 2)
	{
		if(copy[(A[i])] )
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Solution::setZeroes(vector<vector<int> > &A) {

	int rows = A.size();
	int cols = A[0].size();

	bool firstRowHasZeros = false, firstColHasZeros = false;

	for(int i = 0; i < cols; i++)
	{
		if(A[0][i] == 0)
		{
			firstRowHasZeros = true;
			break;
		}
	}

	for(int i = 0; i < rows; i++)
	{
		if(A[i][0] ==  0)
		{
			firstColHasZeros = true;
		}
	}

	for(int i = 1; i < rows; i++)
	{
		for(int j = 1; j < cols; j++)
		{
			if(A[i][j] == 0)
			{
				A[i][0] = 0;
				A[0][j] = 0;
			}
		}
	}

	for(int i = 1; i < rows; i++)
	{
		for(int j = 1; j < cols; j++)
		{
			if(A[i][0] == 0 || A[0][j] == 0)
			{
				A[i][j] = 0;
			}
		}
	}

	if(firstRowHasZeros)
	{
		for(int i = 0; i < cols; i++)
			A[0][i] = 0;
	}

	if(firstColHasZeros)
	{
		for(int i = 0; i < rows; i++)
			A[i][0] = 0;
	}
}

int Solution::firstMissingPositive(vector<int> &A) {

	int n = A.size();
	int shiftIndex = 0;

	for(int i = 0; i < n; i++)
	{
		if(A[i] <= 0)
			swap(A[i], A[shiftIndex++]);
	}

	if(shiftIndex == n)
		return 1;

	for(int i = shiftIndex; i < n; i++)
	{
		int index = abs(A[i]) - 1 + shiftIndex;

		if(index < n && A[index] > 0)
		{
			A[index] *= -1;
		}
	}

	for(int i = shiftIndex; i < n; i++)
	{
		if(A[i] > 0)
			return (i + 1 - shiftIndex);
	}

	return n+1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Solution::nextPermutation(vector<int> &A) {

	int n = A.size();

	int i, j;

	for(i = n-2; i >= 0; i--)
	{
		if(A[i+1] > A[i])
		{
			break;
		}
	}

	if(i == -1)
	{
		reverse(A.begin(), A.end());
		return;
	}

	for(j = n-1; j > i; j--)
	{
		if(A[j] > A[i])
		{
			break;
		}
	}

	swap(A[i], A[j]);

	reverse(A.begin() + i + 1, A.end());

	return;
}

vector<int> Solution::findPerm(const string A, int B) {

	int n = A.length();

	int lowest = 1, highest = B;

	vector<int> ans(B);

	for(int i = 0; i < B-1; i++)
	{
		if(A[i] == 'D')
		{
			ans[i] = highest--;
		}

		else if(A[i] == 'I')
		{
			ans[i] = lowest++;
		}
	}

	ans[B-1] = highest;

	return ans;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
1. Find Duplicate in Array
2. Maximum Consecutive Gap
3. N/3 Repeat Number
4. MAXSPROD