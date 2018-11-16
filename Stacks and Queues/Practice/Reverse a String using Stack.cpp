#include <iostream>
#include <stack> // Stack from Standard Template Library (STL)
using namespace std;

void Reverse(char *C, int n)
{
	stack<char> S;

	// Loop for Push
	for(int i = 0; i < n; i++) S.push(C[i]);

	// Loop for Pop
	for(int i = 0; i < n; i++)
	{
		C[i] = S.top();
		S.pop();
	}
}

int main()
{
	char C[51];
	printf("Enter a string\n");
	gets(C);
	Reverse(C, strlen(C));
	printf("Output = %s\n", C);
}