int Solution::evalRPN(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    stack<int> s;

    int n = A.size();
    for(int i = 0; i < n; i++)
    {
    	if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/")
    	{
    		int operand2 = s.top();
    		s.pop();
    		int operand1 = s.top();
    		s.pop();

    		if(A[i] == "+") s.push(operand1 + operand2);
    		else if(A[i] == "-") s.push(operand1 - operand2);
    		else if(A[i] == "*") s.push(operand1 * operand2);
    		else s.push(operand1 / operand2);
    	}

    	else s.push(atoi(A[i].c_str()));
    }

    return s.top();
}

// http://www.geeksforgeeks.org/expression-evaluation/
// http://qa.geeksforgeeks.org/3856/qa.geeksforgeeks.org/3856/evaluate-the-arithmetic-expression-in-rpn
// https://discuss.leetcode.com/topic/1941/java-accepted-code-stack-implementation