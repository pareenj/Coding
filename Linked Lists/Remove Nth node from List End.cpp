/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode *dummy = new ListNode(-1);
    dummy->next = A;

    ListNode *first = dummy, *second = dummy;

    // Advance first pointer so that the gap between first and second is B nodes apart
    for(int i = 0; i <= B; i++) 
    {
    	if(first == NULL) break;
    	
    	first = first->next;
    }

    // Move first to the end, maintaining the gap
    while(first != NULL)
    {
    	first = first->next;
    	second = second->next;
    }
    second->next = second->next->next;

    return dummy->next;
}

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/solution/