// Array Rotation: One by One

#include<bits/stdc++.h>
using namespace std;

vector<int> leftRotateByOne(vector<int> A)
{
	int n = A.size();
	int temp = A[0];
	vector<int> ans = A;

	for(int i = 0; i < n-1; i++)
	{
		ans[i] = ans[i+1];
	}

	ans[n-1] = temp;

	return ans;
}

vector<int> leftRotate(vector<int> A, int B)
{
	vector<int> ans = A;
	for(int i = 0; i < B; i++)
	{
		ans = leftRotateByOne(ans);
	}

	return ans;
}

void printArray(vector<int> A)
{
	int n = A.size();
	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> A = {1, 2, 3, 4, 5, 6, 7};
	vector<int> ans = leftRotate(A, 2);
	printArray(ans);

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Array Rotation: Reversal Algorithm

#include<bits/stdc++.h>
using namespace std;

vector<int> leftRotate(vector<int> &A, int B)
{
	int n = A.size();

	reverse(A.begin(), A.begin() + B);
	reverse(A.begin() + B, A.end());
	reverse(A.begin(), A.end());

	return A;
}

void printArray(vector<int> A)
{
	int n = A.size();
	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> A = {1, 2, 3, 4, 5, 6, 7};
	vector<int> ans = leftRotate(A, 2);
	printArray(ans);

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Array Rotation: Juggling Algorithm

#include<bits/stdc++.h>
using namespace std;

int gcd(int m, int n)
{
	if(m < n)
	{
		swap(m, n);
	}

	if(n == 0)
	{
		return m;
	}

	return gcd(m % n, n);
}

vector<int> leftRotate(vector<int> A, int B)
{
	int n = A.size();
	int sets = gcd(n, B);
	int size = n/sets;

	vector<int> ans = A;

	for(int i = 0; i < sets; i++)
	{
		// int temp = ans[i];
		for(int j = size-1; j >= 0; j--)
		{
			int flag = 1;
			int from = i + (j * sets);
			int to = from - B;
			if(to < 0)
			{
				to += n;
			}

			if(flag)
			{
				ans[to] = ans[from];
				flag = 0;
			}
			else
			{
				ans[to] = temp;
			}

			int temp = ans[to];
		}
	}

	return ans;
}

void printArray(vector<int> A)
{
	int n = A.size();
	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> A = {1, 2, 3, 4, 5, 6, 7};
	vector<int> ans = leftRotate(A, 2);
	printArray(ans);

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Array Rotation: Updating index
#include<bits/stdc++.h>
using namespace std;

vector<int> leftRotate(vector<int> &A, int B)
{
	int n = A.size();

	int from = 0, to = 0;
	int backupValue = A[from], nextValue = A[to];

	int i = 0;

	while(i < n)
	{
		from = to;
		to = (from - B + n) % n;
		backupValue = A[to];

		A[to] = nextValue;

		nextValue = backupValue;

		i++;
	}

	return A;
}

void printArray(vector<int> A)
{
	int n = A.size();
	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> A = {1, 2, 3, 4, 5, 6, 7};
	vector<int> ans = leftRotate(A, 2);
	printArray(ans);

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Array Rotation: Print Multiple Left Rotations

#include<bits/stdc++.h>
using namespace std;

void leftRotate(vector<int> A, int B)
{
	int n = A.size();
	int mod = B % n;

	for(int i = 0; i < n; i++)
	{
		cout << A[(mod + i) % n] << " ";
	}

	cout << endl;
}

int main()
{
	vector<int> arr = {1, 3, 5, 7, 9};

	vector<int> k = {1, 3, 4, 6};

	for(int i = 0; i < k.size(); i++)
	{
		leftRotate(arr, k[i]);
	}

	return 0;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Split the array and add the first part to the end

#include<bits/stdc++.h>
using namespace std;

void myReverse(vector<int> &A, int start, int end)
{
	while(start < end)
	{
		int temp = A[end];
		A[end] = A[start];
		A[start] = temp;

		start++;
		end--;
	}
}

vector<int> splitAdd(vector<int> &A, int B)
{
	int n = A.size();

	reverse(A.begin(), A.begin() + B);
	reverse(A.begin() + B, A.end());
	reverse(A.begin(), A.end());

	return A;
}

int main()
{
	vector<int> A = {12, 10, 5, 6, 52, 36};
	int k = 2;

	vector<int> ans = splitAdd(A, k);

	for(int i = 0; i < A.size(); i++)
	{
		cout << A[i] << " ";
	}
	
	cout << endl;

	return 0;
}