void reverseWord(string &A, int i, int j)
{
	while(i < j)
	{
		char temp = A[i];
		A[i++] = A[j];
		A[j--] = temp;
	}
}

void Solution::reverseWords(string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int wordsCount = 0, wordStart = 0, wordEnd = 0;
	int len = A.length();

	for(int i = 0; i < len; wordsCount++)
	{
		while(i < len && A[i] == ' ') i++;
		if(wordsCount != 0) A[wordEnd++] = ' ';
		wordStart = wordEnd;
		while(i < len && A[i] != ' ') A[wordEnd++] = A[i++];
		reverseWord(A, wordStart, wordEnd - 1);
	}
	
	A.resize(wordEnd);
	reverseWord(A, 0, wordEnd-1);
}

// https://discuss.leetcode.com/topic/5319/c-solution-in-place-runtime-o-n-memory-o-1
// http://www.geeksforgeeks.org/reverse-words-in-a-given-string/


Longest Palindromic Substring
// http://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
// http://www.geeksforgeeks.org/longest-palindromic-substring-set-2/
// http://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/
// http://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-2/
// https://leetcode.com/articles/longest-palindromic-substring/
// https://www.youtube.com/watch?v=V-sEwsca1ak

Integer to Roman
// https://discuss.leetcode.com/topic/12384/simple-solution
// http://www.geeksforgeeks.org/converting-decimal-number-lying-between-1-to-3999-to-roman-numerals/

Add Binary Strings
// https://discuss.leetcode.com/topic/8981/short-code-by-c
// http://www.geeksforgeeks.org/program-to-add-two-binary-strings/

ZigZag String
// https://discuss.leetcode.com/topic/21196/a-10-lines-one-pass-o-n-time-o-1-space-accepted-solution-with-detailed-explantation
// https://leetcode.com/problems/zigzag-conversion/#/solutions
// https://discuss.leetcode.com/topic/4502/share-simple-c-solution
// http://www.geeksforgeeks.org/print-concatenation-of-zig-zag-string-form-in-n-rows/
// http://qa.geeksforgeeks.org/3713/return-the-zig-zag-string

Justify the Text
// http://qa.geeksforgeeks.org/3710/justify-the-text
// https://discuss.leetcode.com/topic/4189/share-my-concise-c-solution-less-than-20-lines
// https://www.youtube.com/watch?v=RORuwHiblPc

Pretty JSON
// http://qa.geeksforgeeks.org/3734/print-the-pretty-json-strings-facebook-microsoft