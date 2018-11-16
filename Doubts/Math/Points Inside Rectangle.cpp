// You are given a rectangle with co-ordinates represented by arrays A and B, 
// where the sides might not be parallel to the x-y axis.
// Given N points on x-y plane whose co-ordinates are represented by arrays C and D, 
// count the number of points that lie STRICTLY inside the rectangle.
// All the coordinates have integral values.

// Solution Idea: https://martin-thoma.com/how-to-check-if-a-point-is-inside-a-rectangle/


float traingleArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs(((x1*(y2 - y3)) + x2*(y3 - y1) + x3*(y1 - y2))/2.0);
}

// A - B
// D - C
float rectangleArea(int xA, int yA, int xB, int yB, int xC, int yC, int xD, int yD)
{
	return abs(((yA-yC)*(xD-xB) + (yB-yD)*(xA-xC))/2.0);
}


/*
Sample Case:
A[] : { 0, -2, 2, 4 }
B[] : { 0, 2, 6, 4 }
Thus, rectangle has the coordinates (0,0), (-2,2), (2,6) and (4,4).
C[] : { 1, 2, 1, 5, -3 }
D[] : { 3, 4, 2, 5, 1 }

Output : 3
*/
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
    
    float rectArea = rectangleArea(A[0], B[0], A[1], B[1], A[2], B[2], A[3], B[3]);

	int count = 0, n = C.size();
	for(int i = 0; i < n; i++)
	{
		float triArea_1 = traingleArea(A[0], B[0], A[1], B[1], C[i], D[i]);
		float triArea_2 = traingleArea(A[1], B[1], A[2], B[2], C[i], D[i]);
		float triArea_3 = traingleArea(A[2], B[2], A[3], B[3], C[i], D[i]);
		float triArea_4 = traingleArea(A[3], B[3], A[0], B[0], C[i], D[i]);
		// if(triArea_1 == 0 || triArea_2 == 0 || triArea_3 == 0 || triArea_4 == 0) continue;
		float sumArea = triArea_1 + triArea_2 + triArea_3 + triArea_4;
		if((sumArea == rectArea) && (triArea_1 != 0 && triArea_2 != 0 && triArea_3 != 0 && triArea_4 != 0))
		{
			count++;
		}
	}
	return count;
}