/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::partition(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    /* Let us initialize first and last nodes of
      three linked lists as NULL
        1) Linked list of values smaller than x.
        2) Linked list of values equal to x.
        3) Linked list of values greater than x.*/
    ListNode *lesserHead = NULL, *lesserLast = NULL;
    ListNode *equalHead = NULL, *equalLast = NULL;
    ListNode *greaterLast = NULL, *greaterHead = NULL;

    // Now iterate original list and connect nodes
    // of appropriate linked lists.
    while(A != NULL)
    {
    	// If current node is equal to x, append it
        // to the list of x values
        if(A->val == B)
        {
        	if(equalHead == NULL) equalHead = equalLast = A;
        	else
        	{
        		equalLast->next = A;
        		equalLast = equalLast->next;
        	}
        }

        // If current node is less than X, append
        // it to the list of smaller values
        else if(A->val < B)
        {
        	if(lesserHead == NULL) lesserHead = lesserLast = A;
        	else
        	{
        		lesserLast->next = A;
        		lesserLast = A;
        	}
        }

        else
        {
        	if(greaterHead == NULL) greaterHead = greaterLast = A;
        	else
        	{
        		greaterLast->next = A;
        		greaterLast = A;
        	}
        }

        A = A->next;
    }

    // Fix end of greater linked list to NULL if this
    // list has some nodes
    if(greaterLast != NULL) greaterLast->next = NULL;

    // Connect the 3 lists

    // If smaller list is empty
    if(lesserHead == NULL)
    {
    	if(equalHead == NULL) return greaterHead;
    	equalLast->next = greaterHead;
    	return equalHead;
    }

    // If smaller list is not empty and equal list is empty
    if(equalHead == NULL)
    {
    	lesserLast->next = greaterHead;
    	return lesserHead;
    }

    // If both smaller and equal list are non-empty
    lesserLast->next = equalHead;
    equalLast->next = greaterHead;
    return lesserHead;
}