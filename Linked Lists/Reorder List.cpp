/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::reorderList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A == NULL || A->next == NULL) return;

    // Find the middle of the list
    ListNode *slow = A, *fast = A->next;
    while((fast != NULL) && (fast->next != NULL))
    {
    	slow = slow->next;
    	fast = fast->next->next;
    }

    // Reverse the half after middle
    ListNode *preMid = slow, *preCurrent = slow->next;
    while(preCurrent->next != NULL)
    {
    	ListNode *current = preCurrent->next;
    	preCurrent->next = current->next;
    	current->next = preMid->next;
    	preMid->next = current;
    }

    // Start reorder one by one
    slow = A; fast = preMid->next;
    while(slow != preMid)
    {
    	preMid->next = fast->next;
    	fast->next = slow->next;
    	slow->next = fast;
    	slow = fast->next;
    	fast = preMid->next;
    }

    return A;
}

// https://discuss.leetcode.com/topic/13869/java-solution-with-3-steps

ListNode* Solution::reorderList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A == NULL || A->next == NULL) return;

    // 1) Find the middle point using tortoise and hare method
    ListNode *slow = A, *fast = slow->next;
    while((fast != NULL) && (fast->next != NULL))
    {
    	slow = slow->next;
    	fast = fast->next->next;
    }

    // 2) Split the linked list in two halves
    // head1, head of first half
    // head2, head of second half
    ListNode *headLeft = A, *headRight = slow->next;
    slow->next = NULL;

    // 3) Reverse the second half
    ListNode *prev = NULL, *curr = headRight, *next; 
    while(curr != NULL)
    {
    	next = curr->next;
    	curr->next = prev;
    	prev = curr;
    	curr = next;
    }
    headRight = prev;

    // 4) Merge alternate nodes
    ListNode *dummy = new ListNode(-1); // Assign dummy Node

    // current is the pointer to this dummy Node, which will be used to form the new list
    ListNode *current = dummy;
    while((headLeft != NULL) || (headRight != NULL))
    {
    	// First add the element from the first half
    	if(headLeft != NULL)
    	{
    		current->next = headLeft;
    		current = current->next;
    		headLeft = headLeft->next;
    	}

    	// Then add the element from second half
    	if(headRight != NULL)
    	{
    		current->next = headRight;
    		current = current->next;
    		headRight = headRight->next;
    	}
    }

    // Assign the head of the new list to head pointer
    return dummy->next;
}

// http://www.geeksforgeeks.org/rearrange-a-given-linked-list-in-place/