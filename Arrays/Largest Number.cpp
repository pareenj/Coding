bool isLarger(int a, int b)
{
    string ab = to_string(a) + to_string(b);
    string ba = to_string(b) + to_string(a);
    
    return ab > ba;
}

string Solution::largestNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    vector <int> copy = A;
    sort(copy.begin(), copy.end(), isLarger);
    
    string ans = "";
    for(int i = 0; i < n; i++)
    {
        ans += to_string(copy[i]);
    }
    
    if(ans[0] == '0') return "0";
    
    return ans;
}
