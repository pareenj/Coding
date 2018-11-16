// https://www.interviewbit.com/problems/substring-concatenation/
vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    vector <int> ans;
    map <string, int> M;
    int countr=0;
 
    for(int j=0; j<B.size();j++){
        M[B[j]]+=1;
        countr++;
    }
    
    for(int i=0;i<A.size();i++){
        int index = i;
        map <string, int> F;
        int count =0;
        
        for(int j=i; j+B[0].length()<=A.size() && count<countr; j+=B[0].length()){
            F[A.substr(j,B[0].length())]+=1;
            count++;
        }
        
        if(F==M)
            ans.push_back(index);
                
    }

    return ans;
}

// https://discuss.leetcode.com/topic/6617/an-o-n-solution-with-detailed-explanation
// http://www.geeksforgeeks.org/concatenated-string-uncommon-characters-two-strings/
// http://qa.geeksforgeeks.org/3916/qa.geeksforgeeks.org/3916/find-starting-indices-substring-that-concatenation-each-word
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/discuss/