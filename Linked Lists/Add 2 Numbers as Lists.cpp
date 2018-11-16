// https://www.interviewbit.com/problems/add-two-numbers-as-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode* ans = NULL; // ans is head node of resultant list
    ListNode *temp, *prev = NULL;
    int carry = 0, sum = 0;

    while(A != NULL || B != NULL) // while both lists exist
    {
    	// Calculate value of next digit in resultant list.
        // The next digit is sum of following things:
        // (i)  Carry
        // (ii) Next digit of first list (if there is a next digit)
        // (ii) Next digit of second list (if there is a next digit)
        sum = carry + ((A != NULL) ? A->val : 0) + ((B != NULL) ? B->val : 0);

        // update carry for next calulation
        carry = (sum >= 10) ? 1 : 0;

        // update sum if it is greater than 10
        sum = sum % 10;

        // Create a new node with sum as data
        temp = new ListNode(sum);
        // temp->val = sum;
        // temp->next = NULL;

        if(ans == NULL) ans = temp; // If this is the first node then set it as head of the resultant list
        else prev->next = temp; // If this is not the first node then connect it to the rest.

        // After linking prev to the result, mark the current node as prev
        prev = temp;

        // Move 1st and 2nd pointers to next node
        if(A != NULL) A = A->next;
        if(B != NULL) B = B->next;
    }

    if(carry > 0) // Save the carry in a new Node
    {
    	ListNode* temp2 = new ListNode(carry);
    	// temp2->val = carry;
    	// temp2->next = NULL;
    	temp->next = temp2;
    }

    return ans;
}

// http://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/
// http://www.geeksforgeeks.org/sum-of-two-linked-lists/