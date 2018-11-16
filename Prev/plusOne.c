/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */
int* plusOne(int* A, int n1, int *length_of_array) {
	// SAMPLE CODE
        /*
         * *length_of_array = n1 + 1; // length of result array
         * int *result = (int *) malloc(*length_of_array * sizeof(int));
         * // DO STUFF HERE. NOTE : length_of_array can be n1 OR n1 + 1. 
         * return result;
         */
    int i, carry, size;
    *length_of_array = n1;
    int *ans = (int *) malloc(*length_of_array * sizeof(int));
    int *head = (int *) malloc(*length_of_array * sizeof(int));
    head = ans;

    carry = 1;
    size = n1;

    for(i = n1 - 1; i >= 0; i--)
    {
    	int sum;
    	sum = A[i] + carry;
    	carry = sum/10;
    	*(ans++) = (sum % 10);
    }

    if(carry != 0)
    {
    	*(ans++) = carry;
    	size++;
    	(*length_of_array)++;
    }

    int *result = (int *) malloc(*length_of_array * sizeof(int));

    for(i = 0; i < size; i++)
    {
    	result[size - 1 - i] = head[i];	
    }
    
    i = 0;
    while(result[i] == 0)
    {
    	*(result++);
    	size--;
    }
    *length_of_array = size;

    return result;
}

int* plusOne(int* A, int n1, int *len1) {
    int i,dig,carry=1,len=0;
    int *out = (int *)malloc(sizeof(int)*(n1+1));
    int oind = n1;
    for(i=n1-1;i>=0;i--){
        out[oind--] = (A[i]+carry)%10;
        carry = (A[i]+carry)/10;
    }
    out[oind] = carry;
    for(i=0;i<n1+1&&out[i]==0;i++)
        len++;
    out = out+len;
    *len1=n1+1-len;
    return out;
}