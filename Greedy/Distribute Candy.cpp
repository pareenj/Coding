int Solution::candy(vector<int> &ratings) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = ratings.size();
    vector<int> candy(n, 1);

    for(int i = 0; i < n; i++)
    {
    	if(i == 0)
    	{
    		if(ratings[i] > ratings[i+1])
    		{
    			candy[i] = candy[i+1] + 1;
    		}
    	}

    	else if(i == n-1)
    	{
    		if(ratings[i] > ratings[i-1])
    		{
    			candy[i] = candy[i-1] + 1;
    		}
    	}

    	else
    	{
    		if(ratings[i] > ratings[i-1] && ratings[i] > ratings[i+1])
    		{
    			candy[i] = max(candy[i-1], candy[i+1]) + 1;
    		}

    		else if(ratings[i] > ratings[i+1])
    		{
    			candy[i] = candy[i+1] + 1;
    		}

    		else if(ratings[i] > ratings[i-1])
    		{
    			candy[i] = candy[i-1] + 1;
    		}
    	}
    }

    for(int i = n-1; i >= 0; i--)
    {
    	if(i == 0)
    	{
    		if(ratings[i] > ratings[i+1])
    		{
    			candy[i] = candy[i+1] + 1;
    		}
    	}

    	else if(i == n-1)
    	{
    		if(ratings[i] > ratings[i-1])
    		{
    			candy[i] = candy[i-1] + 1;
    		}
    	}

    	else
    	{
    		if(ratings[i] > ratings[i-1] && ratings[i] > ratings[i+1])
    		{
    			candy[i] = max(candy[i-1], candy[i+1]) + 1;
    		}

    		else if(ratings[i] > ratings[i+1])
    		{
    			candy[i] = candy[i+1] + 1;
    		}

    		else if(ratings[i] > ratings[i-1])
    		{
    			candy[i] = candy[i-1] + 1;
    		}
    	}
    }

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
    	ans += candy[i];
    }

    return ans;

}

// https://leetcode.com/problems/candy/solution/
// https://leetcode.com/problems/distribute-candies/solution/
// http://www.geeksforgeeks.org/chocolate-distribution-problem/
// http://www.geeksforgeeks.org/find-minimum-maximum-amount-buy-n-candies/