int Solution::nchoc(int A, vector<int> &B) {

	priority_queue<int> q;

	int n = B.size();
	if (n == 0)
	{
		return 0;
	}

	int ans = 0, divi = pow(10, 9) + 7;

	for(int i = 0; i < n; i++) q.push(B[i]);

	while(A != 0)
	{
		int top = q.top();

		ans = (ans + (top % divi)) % divi;

		q.pop();
		q.push(top/2);

		A--;
	}

	return ans;
}

// https://leetcode.com/problems/candy/solution/
// http://www.geeksforgeeks.org/chocolate-distribution-problem/