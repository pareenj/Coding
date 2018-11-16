int Solution::maxp3(vector<int> &A) {

	int n = A.size();

	if(n < 3) return -1;

	int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
	int min1 = INT_MAX, min2 = INT_MAX;

	for(int i = 0; i < n; i++)
	{
		if(A[i] > max1)
		{
			max3 = max2;
			max2 = max1;
			max1 = A[i];
		}

		else if(A[i] > max2)
		{
			max3 = max2;
			max2 = max1;
		}

		else if(A[i] > max1)
		{
			max1 = A[i];
		}

		if(A[i] < min1)
		{
			min2 = min1;
			min1 = A[i];
		}

		else if(A[i] < min2)
		{
			min2 = A[i];
		}
	}

	return max(min1*min2*max1, max1*max2*max3);
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int Solution::bulbs(vector<int> &A) {

	int count = 0;
	int n = A.size();

	bool zeroSwitch = true;

	for(int i = 0; i < n; i++)
	{
		if(A[i] == 0)
		{
			if(zeroSwitch)
			{
				count++;
				zeroSwitch = false;
			}
		}

		else if(A[i] == 1)
		{
			if(!zeroSwitch)
			{
				count++;
				zeroSwitch = true;
			}
		}
	}

	return count;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#define MOD 10000003
int Solution::seats(string A) {

	int n = A.length();
	int count = 0;

	for(int i = 0; i < n; i++)
	{
		if(A[i] == 'x') count++;
	}

	if(count == 0 || count == 1) return 0;

	int medianIndex = 0;
	for(int i = 0; i < n; i++)
	{
		if(A[i] == 'x')
		{
			medianIndex++;
			if(medianIndex == (count/2)+1)
			{
				medianIndex = i;
				break;
			}
		}
	}

	long long left = medianIndex - 1, right = medianIndex + 1;
	long long hops = 0;

	while(A[left] == 'x')
	{
		left--;
		if(A[left] == '.') break;
	}

	while(A[right] == 'x')
	{
		right++;
		if(A[right] == '.') break;
	}

	for(long long i = left; i >= 0; i--)
	{
		if(A[i] == 'x')
		{
			hops += left - i;
			left--;
		}
	}

	for(long long i = right; i < n; i++)
	{
		if(A[i] == 'x')
		{
			hops += i - right;
			right++;
		}
	}

	return (int) (hops % MOD);
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int Solution::majorityElement(const vector<int> &A) {

	int n = A.size();
	int ans = A[0];
	int count = 1;

	for(int i = 1; i < n; i++)
	{
		if(A[i] == ans) count++;
		else count--;

		if(count == 0)
		{
			ans = A[i];
			count = 1;
		}
	}

	count = 0;
	for(int i = 0; i < n; i++)
	{
		if(A[i] == ans) count++;
	}

	if(count < n/2) return 0;
	else return ans;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int Solution::maxRepeating(vector<int> &A, int k) {

	int n = A.size();
	for(int i = 0; i < n; i++)
	{
		A[A[i] % k] += k;
	}

	int max = A[0], ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(A[i] > max)
		{
			max = A[i];
			ans = i;
		}
	}

	return ans;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int Solution::majorityElement(const vector<int> &A) {

	int count1 = 0, count2 = 0;
	int n = A.size();
	int candidate1 = 0, candidate2 = 1;

	for(int i = 0; i < n; i++)
	{
		if(A[i] == candidate1) count1++;
		else if(A[i] == candidate2) count2++;
		else if(count1 == 0)
		{
			candidate1 = A[i];
			count1 = 1;
		}
		else if(count2 == 0)
		{
			candidate2 = A[i];
			count2 = 1;
		}
		else
		{
			count1--;
			count2--;
		}
	}

	count1 = 0, count2 = 0;
	for(int i = 0; i < n; i++)
	{
		if(A[i] == candidate1) count1++;
		else if(A[i] == candidate2) count2++;
	}

	if(count1 > n/3) return candidate1;
	else if(count2 > n/3) return candidate2;
	else return -1;

}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int Solution::candy(vector<int> &ratings) {

	int n = ratings.size();
	vector<int> candy(n, 1);

	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			if(ratings[i] > ratings[i+1])
			{
				candy[i] = candy[i+1] + 1;
			}
		}

		else if(i == n-1)
		{
			if(ratings[i] > ratings[i-1])
			{
				candy[i] = candy[i-1] + 1;
			}
		}

		else
		{
			if(ratings[i] > ratings[i-1] && ratings[i] > ratings[i+1])
			{
				candy[i] = max(candy[i-1], candy[i+1]) + 1;
			}

			else if(ratings[i] > ratings[i-1])
			{
				candy[i] = ratings[i-1] + 1;
			}

			else if(ratings[i] > ratings[i+1])
			{
				candy[i] = ratings[i+1] + 1;
			}
		}
	}

	for(int i = n-1; i >= 0; i--)
	{
		if(i == 0)
		{
			if(ratings[i] > ratings[i+1])
			{
				candy[i] = candy[i+1] + 1;
			}
		}

		else if(i == n-1)
		{
			if(ratings[i] > ratings[i-1])
			{
				candy[i] = candy[i-1] + 1;
			}
		}

		else
		{
			if(ratings[i] > ratings[i-1] && ratings[i] > ratings[i+1])
			{
				candy[i] = max(candy[i-1], candy[i+1]) + 1;
			}

			else if(ratings[i] > ratings[i-1])
			{
				candy[i] = ratings[i-1] + 1;
			}

			else if(ratings[i] > ratings[i+1])
			{
				candy[i] = ratings[i+1] + 1;
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		ans += candy[i];
	}

	return ans;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int Solution::mice(vector<int> &A, vector<int> &B) {

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int ans = INT_MIN;
	int n = A.size();

	for(int i = 0; i < n; i++)
	{
		ans = max(ans, abs(A[i] - B[i]));
	}

	return ans;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {

	int tankFuel = 0, total = 0;
	int startIndex = 0;

	int n = gas.size();

	for(int i = 0; i < n; i++)
	{
		total += gas[i] - cost[i];
		tankFuel += gas[i] - cost[i];

		if(tankFuel < 0)
		{
			tankFuel = 0;
			startIndex = i+1;
		}
	}

	if(total >= 0) return startIndex % n;
	return -1;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int Solution::nchoc(int A, vector<int> &B) {

	priority_queue<int> q;

	int n = B.size();
	if(n == 0) return 0;

	for(int i = 0; i < n; i++) q.push(B[i]);

	int ans = 0;
	while(A != 0)
	{
		int max = q.top();
		ans += max;

		q.pop();
		q.push(max/2);

		A--;
	}

	return ans;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
struct compare
{
	bool operator()(struct ListNode* a, struct ListNode* b) {
		return a->val > b-val;
	}
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {

	int k = A.size();

	ListNode* head = NULL;
	ListNode* last;

	priority_queue<ListNode*, vector<ListNode*>, compare > pq;

	for(int i = 0; i < k; i++) pq.push(A[i]);

	while(!pq.empty())
	{
		ListNode* min = pq.top();
		pq.pop();

		if(min->next != NULL)
		{
			pq.push(min->next);
		}

		if(head = NULL)
		{
			head = min;
			last = min;
		}
		else
		{
			last->next = min;
			last = min;
		}
	}

	return head;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
vector<int> Solution::dNums(vector<int> &A, int B) {

	vector<int> ans;

	int n = A.size();
	if(B > n) return ans;

	map<int, int> hashMap;

	int distinct = 0;

	for(int i = 0; i < B; i++)
	{
		if(hashMap.find(A[i]) == hashMap.end())
		{
			hashMap[A[i]] = 1;
			distinct++;
		}

		else
		{
			hashMap[A[i]]++;
		}
	}

	ans.push_back(distinct);

	for(int i = B; i < n; i++)
	{
		if(hashMap[A[i-B]] == 1)
		{
			hashMap.erase(hashMap[A[i-B]]);
			distinct--;
		}
		else
		{
			hashMap[A[i-B]]--;
		}

		if(hashMap.find(A[i]) == hashMap.end())
		{
			hashMap[A[i]] = 1;
			distinct++;
		}

		else
		{
			hashMap[A[i]]++;
		}

		ans.push_back(distinct);
	}

	return ans;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int Solution::colorful(int A) {

	if(A == NULL) return 0;

	vector<int> seq;

	while(A != 0)
	{
		seq.push_back(A % 10);
		A = A/10;
	}
	int n = seq.size();

	unordered_map<long long, long long> hashMap;
	for(int i = 0; i < n; i++)
	{
		long long value = 1;
		for(int j = i; j < n; j++)
		{
			value = value * seq[j];
			if(hashMap.find(value) != hashMap.end()) return 0;
			else hashMap.insert({value, value});
		}
	}

	return 1;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
vector<int> Solution::lszero(vector<int> &A) {

	vector<int> sum;
	int n = A.size();

	if(n == 0) return sum;

	sum.push_back(A[0]);
	for(int i = 0; i < n-1; i++) sum.push_back(sum[i] + A[i+1]);

	int start = 0, end = 0;
	map<int, int> hashMap;

	for(int i = 0; i < n; i++)
	{
		if(sum[i] == 0)
		{
			int temp_start = 0, temp_end = i+1;
			if(temp_end - temp_start >= end - start)
			{
				start = temp_start;
				end = temp_end;
			}
		}

		else
		{
			if(hashMap.find(sum[i]) != hashMap.end())
			{
				int temp_start = hashMap[sum[i]] + 1;
				int temp_end = i+1;

				if(temp_end - temp_start > end - start)
    			{
    				start = temp_start;
    				end = temp_end;
    			}
    			else if(temp_end - temp_start == end - start && temp_start < start)
    			{
    				start = temp_start;
    				end = temp_end;
    			}
			}

			else hashMap[sum[i]] = i;
		}
	}

	vector<int> ans;
	for(int i = start; i < end; i++) ans.push_back(A[i]);

	return ans;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
vector<int> Solution::twoSum(const vector<int> &A, int B) {

	int n = A.size();
	vector<int> ans;

	if(n == 0) return ans;

	unordered_map<int, int> hashMap;

	int index1 = 0, index2 = INT_MAX;
	int flag = 0;

	for(int i = 0; i < n; i++)
	{
		int complement =  B - A[i];

		if(hashMap.find(complement) == hashMap.end())
			hashMap.insert({A[i], i});

		else
		{
			flag = 1;
			int tempIndex1 = hashMap[complement];
			int tempIndex2 = i;

			if(tempIndex2 < index2)
			{
				index2 = tempIndex2;
				index1 = tempIndex1;
			}

			else if(tempIndex2 == tempIndex1 && tempIndex1 < index1)
			{
				index1 = tempIndex1;
			}
		}
	}

	if(flag)
	{
		ans.push_back(index1 + 1);
		ans.push_back(index2 + 1);
	}

	return ans;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {

	sort(A.begin(), A.end());
	vector<vector<int> > ans;
	int n = A.size();

	if(n == 0) return ans;
	int sum = 0;

	for(int i = 0; i < n-3; i++)
	{
		if(i > 0 && A[i] == A[i-1])
			continue;

		for(int j = i+1 && j < n-2; j++)
		{
			if(j > i+1 && A[j] == A[j-1])
				continue;

			int left = j+1, right = n-1;
			while(left < right)
			{
				sum = A[i] + A[j] + A[left] + A[right];
				if(sum == B)
				{
					vector<int> row;
					row.push_back(A[i]);
					row.push_back(A[j]);
					row.push_back(A[left]);
					row.push_back(A[right]);
					ans.push_back(row);
				}
				if(sum > B) right--;
				else if(sum < B) left++;
				else if(sum == B)
				{
					left++;
					while(left < right && A[left] == A[left-1])
						left++;
				}
			}
		}
	}
	return ans;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int Solution::isValidSudoku(const vector<string> &A) {

	for(int i = 0; i < 9; i++)
	{
		unordered_set<char> rows;
		unordered_set<char> cols;
		unordered_set<char> cube;

		for(int j = 0; j < 9; j++)
		{
			if(A[i][j] != '.')
			{
				if(rows.find(A[i][j]) != rows.end()) return 0;
				else rows.insert(A[i][j]);
			}

			if(A[j][i] != '.')
			{
				if(cols.find(A[i][j]) != cols.end()) return 0;
				else cols.insert(A[i][j]);
			}

			int rowIndex = (3 * (i / 3)) + (j / 3);
			int colIndex = (3 * (i % 3)) + (j % 3);
			if(A[rowIndex][colIndex] != '.')
			{
				if(cube.find(A[rowIndex][colIndex]) != cube.end()) return 0;
				else cube.insert(A[rowIndex][colIndex]);
			}
		}
	}
	return 1;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int Solution::diffPossible(const vector<int> &A, int B) {

	int n = A.size();
	if(n < 2 || B < 0) return 0;
	unordered_set<int> hashSet;

	for(int i = 0; i < n; i++)
	{
		int a_j = A[i] + B;
		int a_k = A[i] - B;

		if(hashSet.find(a_j) != hashSet.end()) return 1;
		if(hashSet.find(a_k) != hashSet.end()) return 1;

		hashSet.insert(A[i]);
	}

	return 0;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int Solution::maxPoints(vector <int> &A, vector <int> &B) {

	int n = A.size();
	if(n < 2) return n;

	int maxPoint = 1;

	for(int i = 0; i < n; i++)
	{
		unordered_map<double, int> hashMap;
		int duplicatePoints = 1, verticalPoints = 0;

		for(int j = i+1; j < n; j++)
		{
			if(A[i] == A[j])
			{
				if(B[i] == B[j]) duplicatePoints++;
				else verticalPoints++;
			}
			else
			{
				double slope, dx = A[j] - A[i], dy = B[j] - B[i];
				if(B[j] == B[i]) slope = 0.0;
				else slope = (1.0 * (dy/dx));

				if(hashMap.find(slope) != hashMap.end()) hashMap[slope]++;
				else hashMap[slope] = 1;
			}
		}

		auto it = hashMap.begin();
		while(it != hashMap.end())
		{
			int currMax = (it->second) + duplicatePoints;
			maxPoint = max(maxPoint, currMax);
			it++;
		}

		maxPoint = max(maxPoint, verticalPoints + duplicatePoints);
	}

	return maxPoint;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
vector<vector<int> > Solution::anagrams(const vector<string> &A) {

	vector<vector<int> > ans;
	map<string, vector<int> > groups;

	int n = A.size();
	for(int i = 0; i < n; i++)
	{
		string x = A[i];
		sort(x.begin(), x.end());
		groups[x].push_back(i+1);
	}

	for(map<string, vector<int> >::iterator it = groups.begin(); it != groups.end(); it++)
	{
		ans.push_back(it->second);
	}

	return ans;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
vector<int> Solution::equal(vector<int> &A) {

	int n = A.size();
	unordered_map<int, pair<int, int> > hashMap;

	vector<int> ans;
	int count = 0;

	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			int sum = A[i] + A[j];

			if(hashMap.find(sum) == hashMap.end())
				hashMap[sum] = make_pair(i, j);
			else
			{
				vector<int> temp;
				if(i == hashMap[sum].first || i == hashMap[sum].second || j == hashMap[sum].first || j == hashMap[sum].second)
					continue;
				else
				{
					temp.push_back(hashMap[sum].first);
					temp.push_back(hashMap[sum].second);
					temp.push_back(i);
					temp.push_back(j);
				}

				count++;
				if(count == 1) ans = temp;
				else
				{
					for(int k = 0; k < ans.size(); k++)
					{
						if(ans[k] > temp[k])
						{
							ans = temp;
							break;
						}
						else if(ans[k] == temp[k]) continue;
						break;
					}
				}
			}
		}
	}

	return ans;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
struct RandomListNode
{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}	
};

RandomListNode* Solution::copyRandomList(RandomListNode* A) {

	RandomListNode* nodeOriginal = A;
	RandomListNode* nodeCloned;

	unordered_map<RandomListNode*, RandomListNode*> hashMap;

	while(nodeOriginal != NULL)
	{
		nodeCloned = new RandomListNode(nodeOriginal->label);
		hashMap[nodeOriginal] = nodeCloned;
		nodeOriginal = nodeOriginal->next;
	}

	nodeOriginal = A;

	while(nodeOriginal != NULL)
	{
		nodeCloned = hashMap[nodeOriginal];
		nodeCloned->next = hashMap[nodeOriginal->next];
		nodeCloned->random = hashMap[nodeCloned->random];
		nodeOriginal = nodeOriginal->next;
	}

	return new RandomListNode(hashMap[A]);
}

RandomListNode* Solution::copyRandomList(RandomListNode* A) {

	RandomListNode* node = A;
	RandomListNode* copyNode;

	while(node != NULL)
	{
		copyNode = node->next;

		node->next = new RandomListNode(node->label);
		node->next->next = copyNode;
		node = copyNode;
	}

	node = A;
	copyNode = node->next;

	RandomListNode* copyHead = copyNode;

	while(node != NULL && copyNode != NULL)
	{
		if(node->next != NULL)
		{
			node->next = node->next->next;
		}
		else node->next = node->next;

		if(copyNode->next != NULL)
		{
			copyNode->next = copyNode->next->next;
		}
		else copyNode->next = copyNode->next;

		node = node->next;
		copyNode = copyNode->next;
	}

	return copyHead;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int Solution::lengthOfLongestSubstring(string A) {

	int n = A.length(), ans = 0;

	unordered_map<char, int> hashMap;

	for(int left = 0, right = 0; right < n; right++)
	{
		if(hashMap.find(A[right]) == hashMap.end())
		{
			hashMap[A[right]] = 0;
		}
		hashMap[A[right]]++;

		if(hashMap[A[right]] > 1)
		{
			while(left <= right && (hashMap[A[right]] > 1))
			{
				hashMap[A[left]]--;
				left++;
			}
		}

		ans = max(ans, right - left + 1);
	}
	return ans;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int Solution::Mod(int A, int B, int C) {

	if(A == 0) return 0;
	if(B == 0) return 1;
	else if(B % 2 == 0)
	{
		long long y = Mod(A, B/2, C);
		long long z = (y * y) % C;
		return (int) z;
	}
	else
	{
		long long z = ((A % C) * Mod(A, B-1, C)) % C;
		if(z < 0) z = C + z;
		return (int) z;
	}
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* Solution::reverseList(ListNode* A) {

	if(A->next == NULL || A = NULL) return A;

	ListNode* head = reverseList(A->next);
	A->next->next = A;
	A->next = NULL;

	return head;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void generateSubsets(vector<int> &A, int start, vector<int> &subset, vector<vector<int> > &setOfSubsets)
{
	setOfSubsets.push_back(subset);
	int n = A.size();
	for(int i = start; i < n; i++)
	{
		subset.push_back(A[i]);
		generateSubsets(A, i+1, subset, setOfSubsets);
		subset.pop_back();
	}
}

vector<vector<int> > Solution::subsets(vector<int> &A)
{
	sort(A.begin(), A.end());

	vector<vector<int> > setOfSubsets;
	vector<int> subset;

	generateSubsets(A, 0, subset, setOfSubsets);

	return setOfSubsets;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void generateSubsets(vector<int> &A, int start, vector<int> &subset, vector<vector<int> > &setOfSubsets)
{
	setOfSubsets.push_back(subset);
	int n = A.size();
	for(int i = start; i < n; i++)
	{
		if(i > start && A[i] == A[i-1]) continue;
		subset.push_back(A[i]);
		generateSubsets(A, i+1, subset, setOfSubsets);
		subset.pop_back();
	}
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {

	sort(A.begin(), A.end());

	vector<vector<int> > setOfSubsets;
	vector<int> subset;
	generateSubsets(A, 0, subset, setOfSubsets);

	return setOfSubsets;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void combinations(vector<int> &row, vector<vector<int> > &ans, int i, int n, int k)
{
	if(k == 0)
	{
		ans.push_back(row);
		return;
	}

	if(i == n) return;

	for(int j = i; j < n; j++)
	{
		row.push_back(j+1);
		combinations(row, ans, j+1, n, k-1);
		row.pop_back();
	}
}

vector<vector<int> > Solution::combine(int n, int k) {

	vector<vector<int> > ans;
	vector<int> row;
	combinations(row, ans, 0, n, k);
	return ans;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void combSum(vector<vector<int> > &ans, vector<int> row, vector<int> &A, int B, int start)
{
	int n = A.size();
	if(B < 0 || start == n) return;
	else if(B == 0)
	{
		ans.push_back(row);
		return;
	}
	else
	{
		for(int i = start; i < n; i++)
		{
			row.push_back(A[i]);
			combSum(ans, row, A, B-A[i], i);
			row.pop_back();
		}
	}
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B)
{
	sort(A.begin(), A.end());
	vector<vector<int> > ans;
	vector<int> row;

	vector<int> a;
	a.push_back(A[0]);
	for(int i = 1; i < A.size(); i++)
	{
		if(A[i] != a[a.size()-1]) a.push_back(A[i]);
	}

	combSum(ans, row, a, B, 0);
	return ans;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void combSum(vector<vector<int> > &ans, vector<int> &row, vector<int> &A, int B, int start)
{
	int n = A.size();
	if(B == 0)
	{
		ans.push_back(row);
		return;
	}
	else
	{
		for(int i = start; i < n; i++)
		{
			if(A[i] > B) return;
			if(i && i > start && A[i] = A[i-1]) continue;
			row.push_back(A[i]);
			combSum(ans, row, A, B-A[i], i+1);
			row.pop_back();
		}
	}
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B)
{
	sort(A.begin(), A.end());
	vector<vector<int> > ans;
	vector<int> row;

	combSum(ans, row, A, B, 0);
	return ans;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void swap(int *A, int *B)
{
	int temp = *B;
	*B = *A;
	*A = temp;
}

void permuteRecursive(vector<int> &A, int start, vector<vector<int> > &permutations)
{
	int n = A.size();
	if(start >= n)
	{
		permutations.push_back(A);
		return;
	}

	for(int i = start; i < n; i++)
	{
		swap(A[start], A[i]);
		permuteRecursive(A, start + 1, permutations);

		swap(A[start]. A[i]);
	}
}

vector<vector<int> > Solution::permute(vector<int> &A)
{
	vector<vector<int> > permutations;
	permuteRecursive(A, 0, permutations);
	return permutations;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int factorial(int n)
{
	if(n > 12) return INT_MAX;

	int fact = 1;
	for(int i = 2; i <= n; i++) fact *= i;

	return fact;
}

string getPermutationSequence(int k, vector<int> &candidateSet)
{
	int n = candidateSet.size();
	if(n == 0) return "";
	if(k > factorial(n)) return "";

	int f = factorial(n-1);
	int position = k/f;
	k = k % f;

	string ch = to_string(candidateSet[position]);
	candidateSet.erase(candidateSet.begin() + position);

	return ch + getPermutationSequence(k, candidateSet);
}

string Solution::getPermutation(int n, int k)
{
	vector<int> candidateSet;
	for(int i = 1; i <= n; i++) candidateSet.push_back(i);
	return getPermutationSequence(k-1, candidateSet);
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
vector<int> Solution::grayCode(int A) {

	vector<int> ans;
	for(int i = 0; i < (1<<A); i++)
		ans.push_back(i ^ i>>1);
	return ans;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
bool isSafe(vector<string> &nQueens, int row, int col, int &A)
{
	for(int i = 0; i != row; i++)
	{
		if(nQueens[i][col] == 'Q') return false;
	}

	for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
	{
		if(nQueens[i][j] == 'Q') return false;
	}

	for(int i = row - 1, j = col + 1; i >= 0 && j < A; i--, j++)
	{
		if(nQueens[i][j] == 'Q') return false;
	}

	return true;
}

void solveNQueen(vector<vector<string> > &ans, vector<string> &nQueens, int row, int &A)
{
	if(row == A)
	{
		ans.push_back(nQueens);
		return;
	}

	for(int col = 0; col != A; col++)
	{
		if(isSafe(nQueens, row, col, A))
		{
			nQueens[row][col] = 'Q';
			solveNQueen(ans, nQueens, row + 1, A);
			nQueens[row][col] = '.';
		}
	}
}

vector<vector<string> > Solution::solveNQueens(int A) {

	vector<vector<string> > ans;
	vector<string> nQueens(A, string(A, '.'));
	solveNQueen(ans, nQueens, 0, A);
	return ans;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
bool usedInRow(vector<vector<char> > &A, int row, int num)
{
	for(int col = 0; col < 9; col++)
	{
		if(A[row][col] == num + '0') return true;
	}
	return false;
}

bool usedInCol(vector<vector<char> > &A, int col, int num)
{
	for(int row = 0; row < 9; row++)
	{
		if(A[row][col] == num + '0') return true;
	}
	return false;
}

bool usedInBox(vector<vector<char> > &A, int boxStartRow, int boxStartCol, int num)
{
	for(int row = 0; row < 3; row++)
	{
		for(int col = 0; col < 3; col++)
		{
			if(A[row + boxStartRow][col + boxStartCol] == num + '0') return true;
		}
	}
	return false;
}

bool findEmpty(vector<vector<char> > &A, int &row, int &col)
{
	for(row = 0; row < 9; row++)
	{
		for(col = 0; col < 9; col++)
		{
			if(A[row][col] == '.') return true;
		}
	}
	return false;
}

bool isValid(vector<vector<char> > &A, int row, int col, int num)
{
	return (!usedInRow(A, row, num) && !usedInCol(A, col, num) && !usedInBox(A, row - row % 3, col - col % 3, num));
}

bool solve(vector<vector<char> > &A)
{
	int row, col;

	if(!findEmpty(A, row, col)) return true;

	for(int num = 1; num <= 9; num++)
	{
		if(isValid(A, row, col, num))
		{
			A[row][col] = num + '0';
			if(solve(A)) return true;
			A[row][col] = '.';
		}
	}

	return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
	solve(A);
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
bool isPalindrome(string A, int low, int high)
{
	while(low < high)
	{
		if(A[low] != A[high]) return false;
		low++;
		high--;
	}
	return true;
}

void palPartition(vector<vector<string> > &allPalPart, vector<string> &currPalPart, int start, int n, string A)
{
	if(start >= n)
	{
		allPalPart.push_back(currPalPart);
		return;	
	}

	for(int i = start; i < n; i++)
	{
		if(isPalindrome(A, start, i))
		{
			currPalPart.push_back(A.substr(start, i - start + 1));

			palPartition(allPalPart, currPalPart, i + 1, n, A);

			currPalPart.pop_back();
		}
	}
}

vector<vector<string> > Solution::partition(string A) {
	int n = A.length();
	vector<vector<string> > allPalPart;
	vector<string> currPalPart;

	palPartition(allPalPart, currPalPart, 0, n, A);

	return allPalPart;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void paranthesis(vector<string> &ans, string x, int open, int close, int A)
{
	if(open == A && close == A) ans.push_back(x);
	else
	{
		if(open < A) paranthesis(ans, x + "(", open + 1, close, A);
		if(close < open) paranthesis(ans, x + ")", open, close + 1, A);
	}
}

vector<string> Solution::generateParanthesis(int A)
{
	vector<string> ans;
	paranthesis(ans, "", 0, 0, A);

	return ans;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
bool ArePair(char opening, char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}

int Solution::isValid(string A) {

	stack<char> S;
	int n = A.length();
	for(int i = 0; i < n; i++)
	{
		if(A[i] == '(' || A[i] == '{' || A[i] == '[') S.push(A[i]);
		else if(A[i] == ')' || A[i] == '}' || A[i] == ']')
		{
			if(S.empty() || !ArePair(S.top(), A[i])) return 0;
			else S.pop();
		}
	}

	return (S.empty() ? 1 : 0);
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
string Solution::reverseString(string A) {

	stack<char> S;
	int n = A.length();

	for(int i = 0; i < n; i++) S.push(A[i]);

	for(int i = 0; i < n; i++)
	{
		A[i]= S.top();
		S.pop();
	}
	return A;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int Solution::evalRPN(vector<string> &A) {
	
	stack <int> s;
	int n = A.size();
	for(int i = 0; i < n; i++)
	{
		if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/")
		{
			int operand2 = s.top();
			s.pop();
			int operand1 = s.top();
			s.pop();

			if(A[i] == "+") s.push(operand1 + operand2);
			else if(A[i] == "-") s.push(operand1 - operand2);
			else if(A[i] == "*") s.push(operand1 * operand2);
			else if(A[i] == "/") s.push(operand1 / operand2);
		}

		else s.push(atoi(A[i].c_str()));
	}

	return s.top();
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int Solution::braces(string A) {

	stack<char> S;
	int n = A.length();

	for(int i = 0; i < n; i++)
	{
		while((i < n) && (A[i] == '(' || A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/'))
		{
			S.push(A[i]);
			i++;
		}

		if(A[i] == ')')
		{
			if(!S.empty() && (S.top() == '(')) return 1;
			else
			{
				while(S.top() != '(') S.pop();
				S.pop();
			}
		}
	}
	return 0;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
