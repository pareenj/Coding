/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */ 

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {

    int n = intervals.size();
    if(n == 0)
    {
        vector<Interval> ans;
        ans.push_back(newInterval);
        return ans;
    }

    int i = 0;
    while(intervals[i].start <= newInterval.start && i < n)
    {
        if(intervals[i].start == newInterval.start)
        {
            if(intervals[i].end < newInterval.end)
            {
                i++;
            }
            break;
        }

        else
        {
            i++;
        }
    }
    intervals.insert(intervals.begin() + i, newInterval);
    
    vector<Interval> ans;
    n = n + 1;
    ans.push_back(intervals[0]);
    
    for(int i = 0; i < n-1; i++)
    {
        if(intervals[i+1].start <= intervals[i].end)
        {
            int ansSize = ans.size();
            // ans[ansSize-1].start = intervals[i+1].start = intervals[i].start;
            ans[ansSize-1].end = intervals[i+1].end = max(intervals[i].end, intervals[i+1].end);
        }
        else
        {
            Interval x;
            x.start = intervals[i+1].start;
            x.end = intervals[i+1].end;
            ans.push_back(x);
        }
    }
    
    return ans;
}



vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {

    vector<Interval> ans;
    vector<Interval> toMerge;

    int n = intervals.size();
    if(n == 0)
    {
        ans.push_back(newInterval);
        return ans;
    }

    int i = 0;
    while(intervals[i].start <= newInterval.start && i < n)
    {
        if(intervals[i].start == newInterval.start)
        {
            if(intervals[i].end < newInterval.end)
            {
                toMerge.push_back(intervals[i++]);
            }
            break;
        }
        else
        {
            toMerge.push_back(intervals[i++]);
        }
    }
    
    toMerge.push_back(newInterval);

    while(i < n)
    {
        toMerge.push_back(intervals[i++]);
    }
    n = toMerge.size();

    ans.push_back(toMerge[0]);
    for(int i = 0; i < n-1; i++)
    {
        if(toMerge[i+1].start <= toMerge[i].end)
        {
            int ansSize = ans.size();
            ans[ansSize-1].start = toMerge[i+1].start = toMerge[i].start;
            ans[ansSize-1].end = toMerge[i+1].end = max(toMerge[i].end, toMerge[i+1].end);
        }
        else
        {
            Interval x;
            x.start = toMerge[i+1].start;
            x.end = toMerge[i+1].end;
            ans.push_back(x);
        }
    }

    return ans;
}

// /**
//  * Definition for an interval.
//  * struct Interval {
//  *     int start;
//  *     int end;
//  *     Interval() : start(0), end(0) {}
//  *     Interval(int s, int e) : start(s), end(e) {}
//  * };
//  */ 

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
  int startNew = newInterval.start, endNew = newInterval.end;
  vector<Interval> toMerge;
  int i = 0, size = intervals.size();
   
  if(size == 0)
  {
      toMerge.push_back(newInterval);
      return toMerge;
  }
   
  while(startNew >= intervals[i].start && i < size)
  {
    //   if(startNew == intervals[i].start)
    //   {
    //       if(endNew < intervals[i].end)
    //       {
    //           break;
    //       }
    //   }
      toMerge.push_back(intervals[i++]);
  }
   
  toMerge.push_back(newInterval);
   
  while(i < size)
  {
      toMerge.push_back(intervals[i++]);
  }
   
  vector<Interval> ans;
  //ans = toMerge;
  int sz = toMerge.size();
   
  ans.push_back(toMerge[0]);
   
  for(int i = 0; i < sz - 1; i++)
  {
      //if(toMerge[i+1].start >= toMerge[i].start && toMerge[i+1].start <= toMerge[i].end)
      if(toMerge[i+1].start <= toMerge[i].end)
      {
          int len = ans.size();
          ans[len - 1].start = toMerge[i+1].start = min(toMerge[i].start, toMerge[i+1].start);
          ans[len - 1].end = toMerge[i+1].end = max(toMerge[i].end, toMerge[i+1].end);
      }
      else
      {
          Interval x;
          x.start = toMerge[i+1].start;
          x.end = toMerge[i+1].end;
          ans.push_back(x);
      }
  }
   
  return ans;
   
}
