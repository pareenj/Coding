string Solution::simplifyPath(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	stack<char> S;

	int n = A.length();
	for(int i = 0; i < n; i++)
	{
		string ans = "";

		// Overwriting ans with words between the /'s.
		while(i < n && A[i] != '/')
		{
			ans += A[i];
			i++;
		}

		// ans = '.'
		if(ans.size() == 1 && ans[0] == '.')
		{
			while(!S.empty() && S.top() != '/') S.pop();
		}

		// ans = '..'
		else if(ans.size() > 1 && ans == "..")
		{
			int slashCount = 0;

			while(!S.empty() && slashCount != 2)
			{
				if(S.top() == '/') slashCount++;
				S.pop();
			}

			S.push('/');
		}

		else
		{
			for(int j = 0; j < ans.size(); j++) S.push(ans[j]);

			if(!S.empty() && S.top() != '/') S.push('/');
		}
	}

	string answer = "";

	while(!S.empty())
	{
		answer += S.top();
		S.pop();
	}

	reverse(answer.begin(), answer.end());

	if(answer[answer.size()-1] == '/') answer.pop_back();

	if(answer.size() == 0) answer = '/';

	if(answer[0] == '/') return answer;

	return '/' + answer;
}

// https://github.com/sidgupta234/InterviewBit/blob/master/Level-4/Stacks-And-Queues/simplifyDirectoryPath.cpp
// https://discuss.leetcode.com/topic/7675/java-10-lines-solution-with-stack
// https://discuss.leetcode.com/topic/8678/c-10-lines-solution
// http://qa.geeksforgeeks.org/3859/simply-the-given-unix-style-path-for-a-file

string simplifyPath(string path) {
    string res, tmp;
    vector<string> stk;
    stringstream ss(path);
    while(getline(ss,tmp,'/')) {
        if (tmp == "" or tmp == ".") continue;
        if (tmp == ".." and !stk.empty()) stk.pop_back();
        else if (tmp != "..") stk.push_back(tmp);
    }
    for(auto str : stk) res += "/"+str;
    return res.empty() ? "/" : res;
}

// no need to check for .. two times, you need to put checking for empty inside the if
class Solution {
public:
    string simplifyPath(string path) {
        string result="", token;
        stringstream ss(path);
        vector<string> tokens;
        while(getline(ss, token, '/')){
            if(token=="." || token=="") continue;
            else if(token==".."){
                if(tokens.size()!=0)  tokens.pop_back();
            }
            else tokens.push_back(token);
        }
        if(tokens.size()==0) return "/";
        for(int i=0; i<tokens.size(); ++i)
            result=result+'/'+tokens[i];
        return result;
    }
};