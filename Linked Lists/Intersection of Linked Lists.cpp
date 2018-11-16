/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int length(struct ListNode* head)
{
	int len = 0;
	while(head != NULL)
	{
		len++;
		head = head->next;
	}
	return len;
}

ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int a = length(A);
    int b = length(B);
    int diff = b - a;
    if(a > b)
    {
    	ListNode *temp = A;
    	A = B;
    	B = temp;
    	diff = a - b;
    }

    for (int i = 0; i < diff; i++) B = B->next;

    while(A != NULL && B != NULL)
    {
    	if(A == B) return A;

    	A = A->next;
    	B = B->next;
    }
    return NULL;
}
