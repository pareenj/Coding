string Solution::countAndSay(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A == 1) return "1";
    if(A == 2) return "11";

    string str = "11";

    for(int i = 3; i <= A; i++)
    {
    	int len = str.length();
    	int count = 1;
    	string temp = "";

    	for(int j = 0; j < len; j++)
    	{
    		if(str[j] != str[j+1])
    		{
    			temp += count + '0';
    			temp += str[j];
    			count = 1;
    		}
    		else count++;
    	}
    	
    	str = temp;
    }
    
    return str;
}
