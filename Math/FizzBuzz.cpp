vector<string> Solution::fizzBuzz(int A) {
    
    vector <string> ans;
    
    for(int i = 1; i <= A; i++)
    {
        string stringi = "";
        if(i % 3 == 0) 
        {
            if(i % 5 == 0)
            {
                stringi += "FizzBuzz";
            }
            else stringi += "Fizz";
        }
        else if(i % 5 == 0) 
        {
            stringi += "Buzz";
        }
        else stringi = to_string(i);
        
        ans.push_back(stringi);
    }
    return ans;
}
