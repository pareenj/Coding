// https://www.interviewbit.com/problems/partition-list/

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
    
    /* Let us initialize first and last nodes of 2 linked lists as NULL
        1) Linked list of values smaller than x.
        2) Linked list of values greater or equal to x.
    */
    ListNode *lesserHead = NULL, *lesserLast = NULL;
    ListNode *greaterLast = NULL, *greaterHead = NULL;

    // Now iterate original list and connect nodes
    // of appropriate linked lists.
    while(A != NULL)
    {
    	// If current node is less than X, append
        // it to the list of smaller values
        if(A->val < B)
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
    if(lesserHead == NULL) return greaterHead;

    // If both smaller is non-empty
    lesserLast->next = greaterHead;
    return lesserHead;
}

// http://www.geeksforgeeks.org/partitioning-a-linked-list-around-a-given-value-and-keeping-the-original-order/

ListNode* Solution::partition(ListNode* A, int B) {

	if(A == NULL || A->next == NULL) return A;

	ListNode *traverseHead = new ListNode(0), *temp = A, *last = A;
	
	traverseHead->next = A;
	A = traverseHead;

	int n = 0;
	while(temp != NULL)
	{
		temp = temp->next;
		n++;
	}

	while(last->next) last = last->next;

	while(n != 0)
	{
		if(traverseHead->next->val < B) traverseHead = traverseHead->next;
		else
		{
			last->next = new ListNode(traverseHead->next->val);
			last = last->next;
			traverseHead->next = traverseHead->next->next;
		}
		n--;
	}

	return A->next;

}