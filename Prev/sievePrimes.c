/**
 * @input A : Integer
 * 
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */
int* sieve(int A, int *length_of_array) {
	// SAMPLE CODE
        /*
         * *length_of_array = A; // length of result array
         * int *result = (int *) malloc(*length_of_array * sizeof(int));
         * // DO STUFF HERE. NOTE : length_of_array is inaccurate here. 
         * return result;
         */
    
    int *copy;
    copy = malloc((A + 1) * sizeof(int));
    int i, j, count = 0;
    
    //storing isPrimes in copy
    for(i = 0; i <= A; i++)
    {
        copy[i] = 1;
    }
    copy[0] = 0; copy[1] = 0;
    
    for(i = 2; i <= sqrt(A); i++)
    {
        if(copy[i] == 1)
        {
            for(j = 2; i*j <= A; j++)
            {
                copy[i*j] = 0;
            }
        }
    }

    //number of primes in count
    for(i = 2; i <= A; i++)
    {
        if(copy[i] == 1) count++;
    }

    *length_of_array = A;
    //storing prime numbers in result
    int *result;
    result = malloc(count * sizeof(int));
    //int result[count];
    j = 0;
    for(i = 2; i <= A; i++)
    {
        if(copy[i] == 1) result[j++] = i;
    }
    return result;
}