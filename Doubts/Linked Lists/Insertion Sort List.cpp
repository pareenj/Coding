/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::insertionSortList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A == NULL) return A;
    
    ListNode* start = new ListNode(-1); //new starter of the sorted list
    ListNode* current = A; // the node will be inserted
    ListNode* prev = start; // insert node between prev and prev->next
    ListNode* next = NULL; // the next node will be inserted

    // not the end of input list
    while(current != NULL)
    {
    	next = current->next;

    	// find the right place to insert
    	while(prev->next != NULL && prev->next->val < current->val) prev = prev->next;

    	// insert between prev and prev->next
    	current->next = prev->next;
    	prev->next = current;
    	prev = start;
    	current = next;
    }

    return start->next;
}

// https://discuss.leetcode.com/topic/8570/an-easy-and-clear-way-to-sort-o-1-space
// http://www.geeksforgeeks.org/insertion-sort-for-singly-linked-list/