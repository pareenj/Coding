// Rearrange array in alternating positive & negative numbers (Order not important)

#include<bits/stdc++.h>
using namespace std;

vector<int> rearrange(vector<int> &A)
{
	int n = A.size();

	int partitionIndex = 0;

	for(int i = 0; i < n; i++)
	{
		if(A[i] < 0)
		{
			swap(A[i], A[partitionIndex++]);
		}
	}
	
	for(int i = partitionIndex, j = n-1; i < n && i < j; i++)
	{
		if(A[i] == 0)
		{
			swap(A[i], A[j]);
			j--;
		}
	}

	for(int i = 0, j = partitionIndex; i < j && j < n && A[i] < 0; i += 2)
	{
		swap(A[i], A[j++]);
	}

	return A;
}

int main()
{
	vector<int> A = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
	int n = A.size();
	A = rearrange(A);

	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Rearrange array in alternating positive & negative numbers (Maintaining relative order of elements)

#include<bits/stdc++.h>
using namespace std;

void rightRotate(vector<int> &A, int start, int end)
{
	int n = A.size();

	int temp = A[end];
	for(int i = end; i > start; i--)
	{
		A[i] = A[i-1];
	}
	A[start] = temp;
}

vector<int> rearrange(vector<int> &A)
{
	int n = A.size();

	int outOfPlace = 0, j;

	while(outOfPlace < n-1)
	{
		if(outOfPlace % 2 == 0)
		{
			if(A[outOfPlace] >= 0)
			{
				// if(outOfPlace == n-1)
				// {
				// 	break;
				// }
				
				j = outOfPlace + 1;
				if(j == n-1 && A[j] >= 0)
				{
					break;
				}
				
				while(A[j] >= 0 && j < n)
				{
					j++;
					if(j == n-1 && A[j] >= 0)
					{
						goto endOfLoop;
					}
				}
				rightRotate(A, outOfPlace, j);
				outOfPlace++;
			}
		}
		else // if(outOfPlace % 2 != 0)
		{
			if(A[outOfPlace] <= 0)
			{
				// if(outOfPlace == n-1)
				// {
				// 	break;
				// }
				
				j = outOfPlace + 1;
				if(j == n-1 && A[j] <= 0)
				{
					break;
				}
				
				while(A[j] <= 0 && j < n)
				{
					j++;
					if(j == n-1 && A[j] <= 0)
					{
						goto endOfLoop;
					}
				}
				rightRotate(A, outOfPlace, j);
				outOfPlace++;
			}
		}

		outOfPlace++;
	}

	endOfLoop: return A;
}

int main()
{
	vector<int> A = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
	int n = A.size();
	A = rearrange(A);

	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Positive elements at even and negative at odd positions
#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangePN(vector<int> A)
{
	int n = A.size();

	int positive = 0, negative = 1;

	while(true)
	{
		while(positive < n && A[positive] >= 0)
		{
			positive += 2;
		}

		while(negative < n && A[negative] <= 0)
		{
			negative += 2;
		}

		if(positive < n && negative < n)
		{
			swap(A[negative], A[positive]);
		}
		else
		{
			break;
		}
	}

	return A;
}

int main()
{
	vector<int> A = { 1, -3, 5, 6, -3, 6, 7, -4, 9, 10 };
	int n = A.size();
	A = rearrange(A);

	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Rearrange positive and negative numbers
#include<bits/stdc++.h>
using namespace std;

bool comparator(int a, int b)
{
	if(a >= 0 && b < 0)
		return false;

	if((a >= 0 && b >= 0) || (a < 0 && b < 0))
		return false;
}

vector<int> rearrangePN(vector<int> &A)
{
	int n = A.size();

	sort(A.begin(), A.end(), comparator);

	return A;
}

int main()
{
	vector<int> arr = { -12, 11, -13, -5, 6, -7, 5, -3, -6 };
	arr = rearrangePN(arr);

	for(int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}