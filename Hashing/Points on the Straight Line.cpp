int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    if(n < 2) return n;

    int maxPoint = 1;
    int currentMax = 1;

    // map to store slope
    unordered_map<double, int> hashMap;
    int ans = 1;

    for(int i = 0; i < n; i++)
    {
    	int duplicatePoints = 1;
    	int verticalPoints = 0;

    	for(int j = i + 1; j < n; j++)
    	{
    		if(A[i] == A[j])
    		{
    			if(B[i] == B[j]) duplicatePoints++;
    			else verticalPoints++;
    		}
    		else
    		{
    			double slope;
    			double dx = A[j] - A[i];
    			double dy = B[j] - B[i];
    			if(B[j] == B[i]) slope = 0.0;
    			else slope = (1.0 * (dy/dx));
    			hashMap[slope]++;

    			currentMax = max(currentMax, hashMap[slope] + duplicatePoints);
    		}

    		currentMax = max(currentMax, verticalPoints + duplicatePoints);
    	}

    	maxPoint = max(maxPoint, currentMax);
    	hashMap.clear();
    }

    return maxPoint;
}

// http://www.geeksforgeeks.org/count-maximum-points-on-same-line/


int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    if(n < 2) return n;

    int maxPoint = 1;
    
    // map to store slope
    unordered_map<double, int> hashMap;
    int ans = 1;

    for(int i = 0; i < n; i++)
    {
    	int duplicatePoints = 1;
    	int verticalPoints = 0;

    	for(int j = i + 1; j < n; j++)
    	{
    		if(A[i] == A[j])
    		{
    			if(B[i] == B[j]) duplicatePoints++;
    			else verticalPoints++;
    		}
    		else
    		{
    			double slope;
    			double dx = A[j] - A[i];
    			double dy = B[j] - B[i];
    			if(B[j] == B[i]) slope = 0.0;
    			else slope = (1.0 * (dy/dx));
    			
    			if(hashMap.find(slope) != hashMap.end()) hashMap[slope]++;
    			else hashMap[slope] = 1;
    		}
    	}

    	auto it = hashMap.begin();
    	while(it != hashMap.end())
    	{
    		int currentMax = (it->second) + duplicatePoints;
    		maxPoint = max(currentMax, maxPoint);
    		it++;
    	}

    	maxPoint = max(maxPoint, verticalPoints + duplicatePoints);

    	hashMap.clear();
    }

    return maxPoint;
}