int factorial(int n)
{
	if(n > 12) return INT_MAX;

	int fact = 1;
	for(int i = 2; i <= n; i++) fact *= i;

	return fact;
}

string getPermutationSequence(int k, vector<int> &candidateSet)
{
	int n = candidateSet.length();
	if(n == 0) return "";
	if(k > factorial(n)) return "";

	int f = factorial(n-1);
	int position = k/f;
	k = k % f;

	string ch = to_string(candidateSet[position]);
	// Now remove the character ch from candidateSet
	candidateSet.erase(candidateSet.begin() + position);

	return ch + getPermutationSequence(k, candidateSet);

}

string Solution::getPermutation(int n, int k) {

	vector<int> candidateSet;
	for(int i = 1; i <= n; i++) candidateSet.push_back(i);
	return getPermutationSequence(k - 1, candidateSet);
}

// https://github.com/karajrish/InterviewBit/blob/master/Backtracking/kth%20permutation%20sequence/main.cpp
// https://discuss.leetcode.com/topic/5081/an-iterative-solution-for-reference
// https://discuss.leetcode.com/topic/17348/explain-like-i-m-five-java-solution-in-o-n