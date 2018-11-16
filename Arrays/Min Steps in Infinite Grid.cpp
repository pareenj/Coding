// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])
int Solution::coverPoints(vector<int> &X, vector<int> &Y) {

	int steps = 0, n = (X.size() < Y.size()) ? X.size() : Y.size();

	if(n == 1) return 0;
    
    for(int i = 0; i < n-1; i++)
    {
    	int dX = abs(X[i+1] - X[i]), dY = abs(Y[i+1] - Y[i]);
    	steps = steps + ((dX >= dY) ? dX : dY);
    }

    return steps;
}