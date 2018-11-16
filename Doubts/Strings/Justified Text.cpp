vector<string> Solution::fullJustify(vector<string> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<string> res;
    
    for(int i = 0, k, l; i < A.size(); i += k) {
        for(k = l = 0; i + k < A.size() and l + A[i+k].size() <= B - k; k++) {
            l += A[i+k].size();
        }
        string tmp = A[i];
        for(int j = 0; j < k - 1; j++) {
            if(i + k >= A.size()) tmp += " ";
            else tmp += string((B - l) / (k - 1) + (j < (B - l) % (k - 1)), ' ');
            tmp += A[i+j+1];
        }
        tmp += string(B - tmp.size(), ' ');
        res.push_back(tmp);
    }
    return res;
}
