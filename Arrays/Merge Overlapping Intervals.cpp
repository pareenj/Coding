/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

//using namespace std;
    
bool compare(Interval a, Interval b) 
{
    if(a.start == b.start) return a.end < b.end;
    return a.start < b.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval> ans;
    int size = A.size();
    sort(A.begin(), A.end(), compare);
    
    ans.push_back(A[0]);
    
    for(int i = 0; i < size - 1; i++)
    {
        //if(A[i+1].start >= A[i].start && A[i+1].start <= A[i].end)
        if(A[i+1].start <= A[i].end)
        {
            int sz = ans.size();
            ans[sz - 1].start = A[i+1].start = A[i].start;
            ans[sz - 1].end = A[i+1].end = max(A[i].end, A[i+1].end);
        }
        else
        {
            Interval x;
            x.start = A[i+1].start;
            x.end = A[i+1].end;
            ans.push_back(x);
        }
    }
    return ans;
}