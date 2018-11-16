long long int CallMod(int A, int B, int C) 
{
    if(B == 0) return 1;
    else if(B % 2 == 0)
    {
    	long long int y = CallMod(A, B/2, C);
    	long long int z = ((y * y) % C);
    	if(z < 0) z = C + z;
    	return z;
    }
    else 
    {
        long long int z = (((A % C) * CallMod(A, B-1, C)) % C);
        if(z < 0) z = C + z;
    	return z;
    }
}

int Solution::Mod(int A, int B, int C) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A == 0) return 0;
    
    return (int)CallMod(A, B, C);
}