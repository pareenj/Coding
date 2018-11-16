/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(B == 0) return A;

    ListNode* current = A;

    // After the below loop, current will either point to kth or NULL.
    int count = 1;
    while(count < B && current != NULL)
    {
    	current = current->next;
    	count++;
    }

    // If current is NULL, k is greater than or equal to count of nodes in linked list. 
    // Don't change the list in this case
    if(current == NULL) return A;

    // current points to kth node. Store it in a variable.
    ListNode* kthNode = current;

    // current will point to last node after this loop
    while(current->next != NULL) current = current->next;

    // Change next of last node to previous head
    current->next = A;

    // Change head to (k+1)th node
    A = kthNode->next;

    // change next of kth node to NULL
    kthNode->next = NULL;

    return A;
}

// http://www.geeksforgeeks.org/rotate-a-linked-list/

ListNode* Solution::rotateRight(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A == NULL || A->next == NULL) return A;

    ListNode* dummy = new ListNode(-1);
    dummy->next = A;

    ListNode *fast = dummy, *slow = dummy;

    // Get the total length
    int len;
    for(len = 0; fast->next != NULL; len++) fast = fast->next;

    // Get the (len - (n % len))th node
    for(int j = len - (B % len); j > 0; j--)	slow = slow->next;

    fast->next = dummy->next // Do the rotation
	dummy->next = slow->next;
	slow->next = NULL;

	return dummy->next;
}

// https://discuss.leetcode.com/topic/2861/share-my-java-solution-with-explanation/2