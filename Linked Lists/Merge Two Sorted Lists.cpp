/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode *dummy, *tail = new ListNode(INT_MIN);
    dummy = tail;

    while((A != NULL) && (B != NULL))
    {
    	if(A->val < B->val)
    	{
    		tail->next = A;
    		A = A->next;
    	}
    	else
    	{
    		tail->next = B;
    		B = B->next;
    	}

    	tail = tail->next;
    }

    tail->next = (A != NULL) ? A : B; 

    return dummy->next;
}

// https://leetcode.com/problems/merge-two-sorted-lists/discuss/
// http://www.geeksforgeeks.org/merge-two-sorted-linked-lists/