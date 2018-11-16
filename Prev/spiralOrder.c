/**
 * @input A : Read only ( DON'T MODIFY ) 2D integer array ' * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */
int* spiralOrder(const int** A, int n11, int n12, int *length_of_array) {
	 *length_of_array = n11 * n12; // length of result array
	 int *result = (int *) malloc(*length_of_array * sizeof(int));
	 
	 // DO STUFF HERE
	 char dir;
	 int top, bottom, left, right;
	 int i;
	 int *copy = result;
	 dir = 'R';
	 top = 0; bottom = n11 - 1;
	 left = 0; right = n12 - 1;
	 while(left <= right && top <= bottom)
	 {
	     if(dir == 'R')
	     {
	         for(i = left; i <= right; i++)
	         {
	             //*(result++) = *(*(A + top) + i);
	             *(copy++) = A[top][i];
	         }
	         top++;
	         if(top > bottom || left > right)
	         {
	             break;
	         }
	         else
	         {
	             dir = 'D';
	         }
	         
	     }
	     else if(dir == 'D')
	     {
	         for(i = top; i <= bottom; i++)
	         {
	             //*(result++) = *(*(A + i) + right);
	             *(copy++) = A[i][right];
	         }
	         right--;
	         if(top > bottom || left > right)
	         {
	             break;
	         }
	         else
	         {
	             dir = 'L';
	         }
	     }
	     else if(dir == 'L')
	     {
	         for(i = right; i >= left; i--)
	         {
	             //*(result++) = *(*(A + bottom) + i);
	             *(copy++) = A[bottom][i];
	         }
	         bottom--;
	         if(top > bottom || left > right)
	         {
	             break;
	         }
	         else
	         {
	             dir = 'U';
	         }
	     }
	     else if(dir == 'U')
	     {
	         for(i = bottom; i >= top; i--)
	         {
	             //*(result++) = *(*(A + i) + left);
	             *(copy++) = A[i][left];
	         }
	         left++;
	         if(top > bottom || left > right)
	         {
	             break;
	         }
	         else
	         {
	             dir = 'R';
	         }
	     }
	 }
	 return result;
}

// int* spiralOrder(const int** A, int n11, int n12, int *length_of_array) {
// 	 *length_of_array = n11 * n12; // length of result array
// 	 int *result = (int *) malloc(*length_of_array * sizeof(int));
// 	 int a=0,b=n11-1,c=0,d=n12-1,j=-1,i;
// 	 while(c<=d)
// 	 {
// 	     for(i=c;i<=d;i++)
// 	     result[++j]=A[a][i];a++;if(a>b)break;
// 	     for(i=a;i<=b;i++)
// 	     result[++j]=A[i][d];d--;if(c>d)break;
// 	     for(i=d;i>=c;i--)
// 	     result[++j]=A[b][i];b--;if(a>b)break;
// 	     for(i=b;i>=a;i--)
// 	     result[++j]=A[i][c];c++;
	     
// 	 }
	 
// 	 return result;
// }
