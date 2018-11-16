/* Dynamic Programming C/C++ implementation of LCS problem */
#include<bits/stdc++.h>

int lengthOfLCS(string A, string B) 
{
	int m = A.length();
	int n = B.length();

	int lcs[m+1][n+1];
	int i, j;

	/* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	for(int i = 0; i <=m; i++)
	{
		for(int j = 0; j <=n; j++)
		{
			if(i == 0 || j == 0) lcs[i][j] = 0;

			else if(A[i-1] == B[j-1]) lcs[i][j] = 1 + lcs[i-1][j-1];

			else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
		}
	}

	return lcs[m][n];
}

// Space Optimized
int lengthOfLCS(string A, string B) 
{
	int m = A.length();
	int n = B.length();

	int lcs[m+1][n+1];
	int i, j;
	bool bi; // Binary index to store index of current and previous row

	/* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	for(int i = 0; i <=m; i++)
	{
		bi = i&1;

		for(int j = 0; j <=n; j++)
		{
			if(i == 0 || j == 0) lcs[i][j] = 0;

			else if(A[i-1] == B[j-1]) lcs[i][j] = 1 + lcs[i-1][j-1];

			else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
		}
	}
	return lcs[m][n];
}

string strLCS(string A, string B)
{
	int m = A.length();
	int n = B.length();

	int lcs[m+1][n+1];
	int i, j;

	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j <=n; j++)
		{
			if(i == 0 || j == 0) lcs[i][j] = 0;

			else if(A[i-1] == B[j-1]) lcs[i][j] = 1 + lcs[i-1][j-1];

			else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
		}
	}

	// int lengthLCS = lcs[m][n];
	int i = m, j = n;
	string str = "";
	while(i > 0 && j > 0)
	{
		if(lcs[i][j] == lcs[i-1][j])
		{
			i--;
		}

		else if(lcs[i][j] == lcs[i][j-1])
		{
			j--;
		}

		else
		{
			str += A[i-1];
			i--;
			j--;
		}
	}
	reverse(str.begin(), str.end());

	int i = m, j = n;
	int lengthLCS = lcs[m][n];
	char str[lengthLCS + 1];
	str[lengthLCS] = '\0';
	while(i > 0 && j > 0)
	{
		if(A[i-1] == B[j-1])
		{
			str[lengthLCS-1] = A[i-1];
			i--; j--; lengthLCS--;
		}

		else if(lcs[i-1][j] > lcs[i][j-1]) i--;

		else j--;
	}

	return str;
}

// http://www.geeksforgeeks.org/longest-common-subsequence/
// http://www.geeksforgeeks.org/printing-longest-common-subsequence/
// http://www.geeksforgeeks.org/space-optimized-solution-lcs/