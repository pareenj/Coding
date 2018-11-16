/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* Function to reverse the linked list.
Note that this function may change the head */
void reverse(ListNode** A)
{
	ListNode *prev = NULL, *current = *A, *next;
	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*A = prev;
}

/* Function to check if two input lists have same val*/
int compareLists(ListNode* A, ListNode* B)
{
	ListNode *temp1 = A, *temp2 = B;

	while(temp1 && temp2)
	{
		if(temp1->val == temp2->val) 
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else return 0;
	}

	/* Both are empty reurn 1*/
	if(temp1 == NULL && temp2 == NULL) return 1;

	/* Will reach here when one is NULL and other is not */
	return 0;
}

int Solution::lPalin(ListNode* A) {

	ListNode *slow_ptr = A, *prev_slow_ptr = A, *fast_ptr = A;
	ListNode *second_half;
	ListNode *mid = NULL; // To handle odd size list

	int result = 1;

	if(A == NULL) return 1; // Empty list
	if(A->next = NULL) return 1; // Single element

	/* Get the middle of the list. Move slow_ptr by 1 and fast_ptr by 2, 
	slow_ptr will have the middle node */
	while((fast_ptr != NULL) && (fast_ptr->next != NULL))
	{
		fast_ptr = fast_ptr->next->next;

		/*We need previous of the slow_ptr for linked lists  with odd elements */
		prev_slow_ptr = slow_ptr;
		slow_ptr = slow_ptr->next;
	}

	/* fast_ptr would become NULL when there are even elements in list. And not NULL for odd elements. 
	We need to skip the middle node for odd case and store it somewhere so that we can restore the original list*/
	if(fast_ptr != NULL)
	{
		mid = slow_ptr;
		slow_ptr = slow_ptr->next;
	}

	// Now reverse the second half and compare it with first half
	second_half = slow_ptr;
	prev_slow_ptr->next = NULL; // NULL terminate the first half
	reverse(&second_half); // Reverse the second half
	result = compareLists(A, second_half); // compare

	/* Construct the original list back */
    reverse(&second_half); // Reverse the second half again

    // If there was a mid node (odd size case) which was not part of either first half or second half.
    if(mid != NULL)
    {
    	prev_slow_ptr->next = mid;
    	mid->next = second_half;
    }
    else prev_slow_ptr->next = second_half;

    return result;
}

// http://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    
    ListNode *start = A, *mid = A, *prev;

    if(start == NULL) return 1;
    if(start->next == NULL) return 1;

    // Getting to the middle of the list
    while((start != NULL) && (start->next != NULL))
    {
    	start = start->next->next;
    	prev = mid;
    	mid = mid->next;
    }
    prev->next = NULL;

    // Reversing the second half
    ListNode *current, *next, *previous;
    current = mid;
    while(current != NULL)
    {
    	next = current->next;
    	if(current == mid)
    	{
    		current->next = NULL; // Required to compare the two half lists; This sets the last node (after reversing) to NULL
    		prev = current;
    		current = next;
    	}
    	else
    	{
    		current->next = prev;
    		prev = current;
    		current = next;
    	}
    }

    // Comparing the 1st half and the reversed 2nd half from the right end.
    start = A;
    while((prev != NULL) && (start != NULL))
    {
    	if(prev->val != start->val) return 0;
    	prev = prev->next;
    	start = start->next;
    }
    return 1;
}