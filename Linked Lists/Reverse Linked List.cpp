/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode *current, *prev, *next;
    current = A;
    prev = NULL;
    while(current != NULL)
    {
    	next = current->next;
    	current->next = prev;
    	prev = current;
    	current = next;
    }
    A = prev;
    return A;
}
