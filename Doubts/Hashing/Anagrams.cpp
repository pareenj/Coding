vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int> > ans;
    map<string, vector<int>> groups;

    int n = A.size();
    for(int i = 0; i < n; i++)
    {
    	//sort every string and store groups of strings that are anagrams
    	string x = A[i];
    	sort(x.begin(), x.end());
    	groups[x].push_back(i+1);
    }

    // auto iterator = groups.begin();
    // while(iterator != groups.end())
    // {
    // 	ans.push_back(iterator->second);
    // 	iterator++;
    // }

    for(map<string, vector<int>>::iterator it = groups.begin(); it != groups.end(); it++)
    {
    	ans.push_back(it->second);
    }
    return ans;
}

// http://qa.geeksforgeeks.org/4847/qa.geeksforgeeks.org/4847/return-all-the-groups-of-anagrams
// https://leetcode.com/problems/group-anagrams/discuss/