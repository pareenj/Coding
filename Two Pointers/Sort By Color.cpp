void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void Solution::sortColors(vector<int> &A) {

	int n = A.size();
	int low = 0, mid = 0, high = n-1;

	while(mid <= high)
	{
		if(A[mid] == 0)
		{
			swap(A[low], A[mid]);
			low++; mid++;
		}
		else if(A[mid] == 1) mid++;
		else if(A[mid] == 2)
		{
			swap(A[mid], A[high]);
			high--;
		}
	}
}

// https://leetcode.com/problems/sort-colors/discuss/