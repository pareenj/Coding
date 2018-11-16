/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {

	if(A == NULL) return NULL;

	// Hash map which contains node to node mapping of original and copy linked list.
	unordered_map<RandomListNode*, RandomListNode*> hashMap;

	// Initialize two references, one with original list's head.
	RandomListNode* node = A;
	RandomListNode* copyNode = NULL;

	// Traverse the original list and make a copy of that in the copy list
	while(node != NULL)
	{
		copyNode = new RandomListNode(node->label);
		hashMap.insert({node, copyNode});
		node = node->next;
	}

	// Adjusting the original list reference again
	node = A;

	// Traversal of original list again to adjust the next
    // and random references of copy list using hash map.
    while(node != NULL)
    {
    	copyNode = hashMap[node];
    	copyNode->next = hashMap[node->next];
    	copyNode->random = hashMap[node->random];
    	node = node->next;
    }

    // Return the head reference to the copy list
    node = hashMap[A];
    return node;
}

// http://www.geeksforgeeks.org/clone-linked-list-next-arbit-pointer-set-2/
// http://www.geeksforgeeks.org/clone-linked-list-next-random-pointer-o1-space/
// http://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
// https://discuss.leetcode.com/topic/7594/a-solution-with-constant-space-complexity-o-1-and-linear-time-complexity-o-n

RandomListNode* Solution::copyRandomList(RandomListNode* A) {

	RandomListNode* node = A;
	RandomListNode* copyNode;

	// Insert additional node after every node of original list
	while(node != NULL)
	{
		copyNode = node->next;

		// Inserting node
		node->next = new RandomListNode(node->label);
		node->next->next = copyNode;
		node = copyNode;
	}

	node = A;

	// This works because original->next is nothing but copy of original and Original->random->next is nothing but copy of random.

	// Adjust the random pointers of the newly added nodes
	while(node != NULL)
	{
		if(node->random != NULL)
		{
			node->next->random = node->random->next;
		}

		// Move to the next newly added node by skipping an original node
		node = node->next->next;
	}

	node = A;
	copyNode = node->next;

	// Save the start of the copied linked list
	RandomListNode* copyHead = copyNode;

	// Now separate the original and copied lists
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