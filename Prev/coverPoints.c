/**
 * @input X : Integer array corresponding to the X co-ordinate
 * @input n1 : Integer array's ( X ) length
 * @input Y : Integer array corresponding to the Y co-ordinate
 * @input n2 : Integer array's ( Y ) length
 *
 * Points are represented by (X[i], Y[i])
 * 
 * @Output Integer
 *
 */
int coverPoints(int* X, int n1, int* Y, int n2) {

	int i, steps, n;

	n = (n1 < n2) ? n1 : n2;
	if(n == 1) return 0;
	
	steps = 0;

	for(i = 0; i < n - 1; i++)
	{
		steps = steps + ((abs(X[i+1] - X[i]) >= abs(Y[i+1] - Y[i])) ? abs(X[i+1] - X[i]) : abs(Y[i+1] - Y[i]));

	}
	
	return steps;
    
}