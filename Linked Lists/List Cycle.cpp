/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A == NULL || A->next == NULL) return NULL;

    ListNode *slow = A, *fast = A;

    // Break when slow and fast pointers collide
    while((slow != NULL) && (fast != NULL))
    {
    	slow = slow->next;

    	if(fast->next == NULL) return NULL;
    	else fast = fast->next->next;

    	if(slow == fast) break;
    }

    if(slow == NULL || fast == NULL) return NULL;

    // Current from the head pointer (A) and Slow from the colliding point meet at the start of the loop
    ListNode *current = A;
    while(current != slow)
    {
    	current = current->next;
    	slow = slow->next;
    }

    return current;
}

// https://www.youtube.com/watch?v=-YiQZi3mLq0
// http://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
// http://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/