/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::reverseList(ListNode* A, int B) {

	ListNode *current = A, *prev = NULL, *next = NULL;
	int count = 0;

	/*reverse first k nodes of the linked list */
	while(current != NULL && count < B)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

	/* next is now a pointer to (k+1)th node 
       Recursively call for the list starting from current. And make rest of the list as next of first node */
	if(next != NULL) A->next = reverseList(next, B);

	/* prev is new head (A) of the input list */
	return prev;
}

// http://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/
// http://www.geeksforgeeks.org/reverse-alternate-k-nodes-in-a-singly-linked-list/

ListNode* Solution::reverseList(ListNode* A, int B) {
    if(!A || B == 1 || B == 0){
        return A;
    }
    
    ListNode* head = NULL, *curr = A, *prev = NULL, *tempHead = NULL;
    
    for(int i = 0; i < B; i++){
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        
        if(tempHead == NULL){
            tempHead = prev;
        }
    }
    
    head = prev;

    prev = NULL;
    
    while(curr){
        ListNode* t = NULL;
        
        for(int i = 0; i < B; i++){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            
            if(!t){
                t = prev;
            }
        }
        
        tempHead->next = prev;
        tempHead = t;
    }
    
    if(tempHead){
        tempHead->next = NULL;
    }
    
    return head;
}