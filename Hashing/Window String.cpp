string Solution::minWindow(string S, string T) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	int len1 = S.length();
	int len2 = T.length();

	if(len1 < len2) return "";

	vector<int> hashSet(128, 0);

	for(auto it: T) hashSet[it]++;

	int count = len2;
	int start = 0, end = 0, window = INT_MAX, copyStart = 0;
	int flag = 0;

	while(end < len1)
	{
		if(hashSet[S[end++]] --> 0) count--; // in T
		while(count == 0)
		{
			if(end - copyStart < window)
			{
				flag = 1;
				window = end - (start = copyStart);
			}

			if(hashSet[S[copyStart++]]++ == 0) count++;
		}
	}

	if(flag == 0)
	{
		return "";
	}
	else return S.substr(start, window);
}

// https://discuss.leetcode.com/topic/30941/here-is-a-10-line-template-that-can-solve-most-substring-problems
// http://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
// http://www.geeksforgeeks.org/smallest-window-contains-characters-string/

string Solution::minWindow(string S, string T) {

	int len1 = S.length();
	int len2 = T.length();

	if(len1 < len2) return "";

	// store occurrence of characters of T
	unordered_set<char> hashSet;
	for(int i = 0; i < len2; i++) hashSet.insert(T[i]);

	// start traversing the string S
	int count = 0;
	int start, end, window;
	for(int i = 0; i < len1; i++)
	{
		unordered_set<char> copySet = hashSet;
		if(!copySet.empty())
		{
			if(copySet.find(S[i]) != copySet.end())
			{
				start = i;
				copySet.erase(copySet.find(S[i]));
			}
		}

		else
		{
			end = i;
			window = end - start + 1;		
		}

		if(count == len2)
		{

		}
	}


}