int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int tankFuel = 0, total = 0;
    int startIndex;

    int n = gas.size();

    for(int i = 0; i < n; i++)
    {
    	total += gas[i] - cost[i];
    	tankFuel += gas[i] - cost[i];

    	if(tankFuel < 0)
    	{
    		tankFuel = 0;
    		startIndex = i+1;
    	}
    }

    if(total > 0) return startIndex % n;
    return -1;
}

// http://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/
// https://discuss.leetcode.com/topic/5088/my-ac-is-o-1-space-o-n-running-time-solution-does-anybody-have-posted-this-solution
// https://discuss.leetcode.com/topic/1344/share-some-of-my-ideas