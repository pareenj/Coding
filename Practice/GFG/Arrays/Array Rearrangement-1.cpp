// Rearrange an array such that arr[i] = i

#include<bits/stdc++.h>
using namespace std;

vector<int> rearrange(vector<int> &A)
{
	int n = A.size();

	for(int i = 0; i < n; i++)
	{
		if(A[i] != -1 && A[i] != i)
		{
			int x = A[i];

			while(A[x] != -1 && A[x] != x)
			{
				int y = A[x];
				A[x] = x;
				x = y;
			}

			A[x] = x;
		}

		if(A[i] != i)
		{
			A[i] = -1;
		}
	}

	return A;
}

int main()
{
	vector<int> A = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
	int n = A.size();
	vector<int> ans = rearrange(A);

	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Rearrange an array such that ‘arr[j]’ becomes ‘i’ if ‘arr[i]’ is ‘j’
#include<bits/stdc++.h>
using namespace std;

vector<int> rearrange1(vector<int> A)
{
	int n = A.size();

	// Increment all values by 1, so that all elements can be made negative to mark them as visited
    for(int i = 0; i < n; i++)
	{
		A[i]++;
	}

	for(int i = 0; i < n; i++)
	{
		if(A[i] > 0)
		{
			// 'val' is the value to be stored at 'arr[i]'
			int value = -(i+1); // The next value is determined using current index
			i = A[i] - 1;		// The next index is determined using current value

			// While all elements in cycle are not processed
			while(A[i] > 0)
			{
				// Store value at index as it is going to be used as next index
				int new_i = A[i] - 1;

				// Update arr[]
				A[i] = value;

				// Update value and index for next iteration
				value = -(i+1);
				i = new_i;
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		A[i] = -A[i] - 1;
	}

	return A;
}

vector<int> rearrange2(vector<int> A)
{
	int n = A.size();

	for(int i = 0; i < n; i++)
	{
		A[A[i] % n] += i * n;
	}

	for(int i = 0; i < n; i++)
	{
		A[i] /= n;
	}

	return A;
}

int main()
{
	vector<int> A = {2, 0, 1, 4, 5, 3};
	int n = A.size();
	vector<int> ans = rearrange(A);

	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Rearrange an array so that arr[i] becomes arr[arr[i]] 
vector<int> rearrange3(vector<int> A)
{
	int n = A.size();

	for(int i = 0; i < n; i++)
	{
		A[i] += A[A[i] % n] * n;
	}

	for(int i = 0; i < n; i++)
	{
		A[i] /= n;
	}

	return A;
}

int main()
{
	vector<int> A = {2, 0, 1, 4, 5, 3};
	int n = A.size();
	vector<int> ans = rearrange3(A);

	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Rearrange an array in maximum minimum form

#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeMaxMin(vector<int> &A)
{
	int n = A.size();
	int maxElement = A[n-1] + 1;

	int maxIndex = n-1, minIndex = 0;

	for(int i = 0; i < n; i++)
	{
		if(i % 2 == 0)
		{
			A[i] += (A[maxIndex] % maxElement) * maxElement;
			maxIndex--;
		}
		else
		{
			A[i] += (A[minIndex] % maxElement) * maxElement;
			minIndex++;
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		A[i] /= maxElement;
	}

	return A;
}

int main()
{
	vector<int> A = {1, 4, 5, 6, 7, 9, 14};
	int n = A.size();
	vector<int> ans = rearrangeMaxMin(A);

	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Rearrange an array in order – smallest, largest, 2nd smallest, 2nd largest, ...
#include<bits/stdc++.h>
using namespace std;

vector<int> customSort(vector<int> &A)
{
	int n = A.size();
	sort(A.begin(), A.end());

	vector<int> copy = A;

	for(int i = 0, j = n-1, k = 0; i < j && i < n && j >= 0; i++, j--, k++)
	{
		if(k % 2 == 0)
		{
			A[k] = copy[i];
		}
		else
		{
			A[k] = copy[j];
		}
	}

	return A;
}

int main()
{
	vector<int> A = {5, 8, 1, 4, 2, 9, 3, 7, 6};
	int n = A.size();
	A = customSort(A);

	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
