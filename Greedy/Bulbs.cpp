int Solution::bulbs(vector<int> &A) {

	int count = 0;
	int init = 1;

	int n = A.size();

	for(int i = 0; i < n; i++)
	{
		if(A[i] == 0)
		{
			if(init == 1)
			{
				count++;
				init = 0;
			}
		}
		else
		{
			if(init == 0)
			{
				count++;
				init = 1;
			}
		}
	}

	return count;
}

int Solution::bulbs(vector<int> &A) {

	int stateLookingFor = 0;
	int count = 0;

	int n = A.size();

	for(int i = 0; i < n; i++)
	{
		if(A[i] == stateLookingFor)
		{
			count++;
			stateLookingFor = 1 - stateLookingFor;
		}
	}

	return count;
}

// http://www.geeksforgeeks.org/count-minimum-right-flips-to-set-all-values-in-an-array/
// https://leetcode.com/problems/bulb-switcher/description/