/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode* newHead = new ListNode(-1);
    newHead->next = head;

    ListNode* prev = newHead;
    for(int i = 0; i < m-1; i++) prev = prev->next;
    //prev is now (m-1)th position of the list
    
    ListNode* reversedPrev = prev;

	//position m
	prev = prev->next;

	ListNode* current = prev->next;

	for(int i = m; i < n; i++)
	{
		prev->next = current->next;
		current->next = reversedPrev->next;
		reversedPrev->next = current;
		current = prev->next;
	}

	return newHead->next;
}

ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A == NULL) return A;

    ListNode *dummy = new ListNode(0); // create a dummy node to mark the head of this list
    dummy->next = A;

    ListNode *prev = dummy; // make a pointer prev as a marker for the node before reversing
    for(int i = 0; i < m-1; i++) prev = prev->next;

    ListNode *start = prev->next; // a pointer to the beginning of a sub-list that will be reversed
	ListNode *current = start->next; // a pointer to a node that will be reversed

	// 1 - 2 -3 - 4 - 5 ; m = 2; n = 4 ---> pre = 1, start = 2, then = 3
    // dummy-> 1 -> 2 -> 3 -> 4 -> 5

	for(int i = 0; i < n-m; i++)
	{
		start->next = current->next;
		current->next = prev->next;
		prev->next = current;
		current = start->next;
	}

	// first reversing : dummy->1 - 3 - 2 - 4 - 5; pre = 1, start = 2, then = 4
    // second reversing: dummy->1 - 4 - 3 - 2 - 5; pre = 1, start = 2, then = 5 (finish)

    return dummy->next;

}