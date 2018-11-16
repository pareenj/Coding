/**
 * @input A : Integer
 * 
 * @Output string. Make sure the string ends with null character
 */
char* findDigitsInBinary(int A) {
	// SAMPLE CODE
	/*
	 * char* result = (char *)malloc(100 * sizeof(char));
	 * // DO STUFF HERE
	 * return result; 
	 */

	//Taking care of integer 0
	 if(A == 0)
	 {
	     char* result = (char *)malloc(2 * sizeof(char));
	     result[0] = '0';
	     result[1] = '\0';
	     return result;
	 }
	 
	 //storing the reverse of binary rep. in copy
	 char* copy = (char *)malloc(100 * sizeof(char));
	 int rem, j, i = 0;
	 char rem_c;
	 while(A > 0)
	 {
	     rem = A % 2;
	     rem_c = (char)rem;
	     copy[i++] = rem_c;
	     A = A/2;
	 }

	 ////storing the  binary rep. in result
	 char* result = (char *)malloc((i+1)* sizeof(char));
	 for(j = 0; j < i; j++)
	 {
	     result[j] = copy[i - j - 1];
	 }
	 result[i] = '\0';
	 return result;
}