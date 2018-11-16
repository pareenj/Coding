bool Solution::isPower(int A) {
    
    if(A == 1) return true;
    
    for(int i = 2; i <= sqrt(A); i++)
    {
        for(int j = 2; pow(i, j) <= A; j++)
        {
            if(pow(i, j) == A) return true;
        }
    }
    return false;
}