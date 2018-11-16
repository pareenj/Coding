vector<int> Solution::maxone(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> ans;
    int n = A.size();

    // Left and right indexes of current window
    int wL = 0, wR = 0;

    // Left index and size of the widest window
    int bestL = 0, bestWindow = 0;

    // Count of zeroes in current window
    int zeroCount = 0;

    // While right boundary of current window doesn't cross right end
    while(wR < n)
    {
    	// If zero count of current window is less than m, widen the window toward right
    	if(zeroCount <= B)
    	{
    		if(A[wR] == 0) zeroCount++;
    		wR++;
    	}

    	// If zero count of current window is more than m, reduce the window from left
    	if(zeroCount > B)
    	{
    		if(A[wL] == 0) zeroCount--;
    		wL--;
    	}

    	// Updqate widest window if this window size is more
    	if(wR - wL > bestWindow)
    	{
    		bestWindow = wR - wL;
    		bestL = wL;
    	}
    }

    for(int i = 0; i < bestWindow; i++)
    {
    	if(A[bestL + i] == 0) ans.push_back(bestL + i);
    }

    return ans;
}

// http://www.geeksforgeeks.org/find-zeroes-to-be-flipped-so-that-number-of-consecutive-1s-is-maximized/
// http://www.geeksforgeeks.org/length-longest-consecutive-1s-binary-representation/
-----------------------------------------------------------------------------------------------------------------------------------

vector<int> Solution::maxone(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> sol;    
    
    int i = 0, j = 0, temp_st = -1, temp_end = -1, temp_count = 0;
    int ov_st = -1, ov_end = -1, ov_count = 0;
    
    int temp = B;
    
    while(j < A.size()){
        if(A[j] == 1){
            temp_count++;
            if(temp_count == 1){
                temp_st = j;
            }
            temp_end = j;
            j++;
        }    
        else{
            temp--;
            if(temp < 0){
                int t_c = 1;
                while(A[i] == 1){
                    i++;
                    t_c++;
                }
                i++;
                temp_count = temp_count - t_c + 1;
                temp = 0;
                temp_st = i;
                temp_end = j;
            }
            else{
                temp_count++;
                if(temp_count == 1){
                    temp_st = j;
                }
                temp_end = j;
            }
            j++;
        }
        if(ov_count == 0){
            ov_count = temp_count;
            ov_st = temp_st;
            ov_end = temp_end;
        }
        else{
            if(ov_count < temp_count){
                ov_count = temp_count;
                ov_st = temp_st;
                ov_end = temp_end;
            }
        }
    }
    
    if(ov_count != 0){
       for(int t = ov_st; t <= ov_end; t++){
           sol.push_back(t);
       }
    }
    
    return sol;
}
