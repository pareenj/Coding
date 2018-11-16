vector<int> Solution::sieve(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> ans;
    if(A < 2) return ans;
    
    vector<bool> isPrime(A + 1);
    fill(isPrime.begin(), isPrime.end(), true);
    isPrime[0] = isPrime[1] = false;
    
    for(int i = 2; i*i <= A; i++)
    {
        if(isPrime[i] == true)
        {
            for(int j = 2; i*j <= A; j++) isPrime[i*j] = false;
        }
    }
    
    for(int i = 2; i <= A; i++)
    {
        if(isPrime[i] == true) ans.push_back(i);
    }
    
    return ans;
}

vector<int> Solution::sieve(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> ans;
    if(A < 2) return ans;
    
    int arr[A + 1];
    memset(arr, 0, sizeof(arr));
    
    for (int i = 2; i <= A; i++) {
        if (arr[i] == 0) {
            ans.push_back(i);
            for (int j = 2 * i; j <= A; j += i) arr[j] = 1;
        }
    }
    return ans; 
}

vector<int> Solution::sieve(int A) {
    
   vector <bool> v ( sqrt(A)+1 );
   fill(v.begin(), v.end(), true);
   v[0]=v[1]=false;
   
   vector <int> ans;
   
   for(int i=2; i*i<=A; i++ ){
       if(!v[i])
            continue;
        
        ans.push_back(i);
        
       for(int j=i*i ; j*j<=A; j=i+j){
           v[j]=false;
       }
   }
   
   for(int i=sqrt(A)+1;i<=A;i++){
       bool prime = true;
       
       for(int j=0; j<ans.size() && ans[j]*ans[j]<=i ;j++){
           if(i%ans[j]==0){
               prime = false;
               break;
               
           }
       }
       
       if(prime){
                ans.push_back(i);
        }
            
   }
   return ans;
   
}