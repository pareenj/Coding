/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* rotateArray(int* A, int n1, int B, int *len) {
	int *ret = (int *)malloc(n1 * sizeof(int));
	*len = n1;
	B = B % n1;
	int i;
	for (i = 0; i < n1 - B; i++) ret[i] = A[i + B];
	for(i = n1 - B; i < n1; i++) ret[i] = A[i - n1 + B];
	return ret;
}

int* rotateArray(int* A, int n1, int B, int *len) {
	int *ret = (int *)malloc(n1 * sizeof(int));
	*len = n1;
	//B = B % n1;
	int i;
	for (i = 0; i < n1; i++) ret[i] = A[(i + B) % n1];
	//for(i = n1 - B; i < n1; i++) ret[i] = A[i - n1 + B];
	return ret;
}

vector<int> Solution::rotateArray(vector<int> &A, int B) {
    vector<int> ret; 
    for (int i = 0; i < A.size(); i++) {
        ret.push_back(A[(i + B) % A.size()]);
    }
    return ret; 
}