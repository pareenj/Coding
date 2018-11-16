// Implementation in C
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};
struct Node* top = NULL;

void Push(int x)
{
    struct Node* NewNode = (struct Node*) malloc(sizeof(struct Node));
    NewNode->data = x;
    NewNode->link = top;
    top = NewNode;
}

void Pop()
{
    struct Node* temp = top;
    if (top == NULL) return;
    top = top->link;    
    free(temp);
}

void Print()
{
    struct Node* temp = top;
    while(temp != NULL)
    {
        printf("%d",temp->data);
        temp = temp->link;        
    }
    printf("\n");

}

int IsEmpty()
{
    if(top==NULL) return 1;
    else return 0;
}

int Top()
{
    return (top->data);

}

int main()
{
    Push(5); Print();
    Push(6); Print();
    Push(7); Print();
    Push(8); Print();
    Pop(); Print();
    Pop(); Print();
    Pop(); Print();
    printf("%d",Top());
    if(IsEmpty()) printf("Empty!!");
    else printf("Nope");
    
    return 0;
}﻿

// Implementation in C++
#include <iostream>
using namespace std;

class Stack
{
    private:
        struct Node
        {
            int data;
            Node* link;
        };
        struct Node* top;

    public:
        Stack()
        {
            top=NULL;
        }

        void Push(int x)
        {
            Node* NewNode = new Node();
            NewNode->data = x;
            NewNode->link = top;
            top = NewNode;
        }

        void Pop()
        {
            Node* temp= top;
            if (top==NULL) return;
            top = top->link;
            delete (temp);
        }

        void Print()
        {
            Node* temp = top;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->link;
            }
            cout<<endl;
        }

        int IsEmpty()
        {
            if (top==NULL) return 1;
            return 0;
        }
};

int main()
{
    Stack S;
    S.Push(5); S.Print();
    S.Push(6); S.Print();
    S.Push(8); S.Print();
    S.Push(9); S.Print();
    S.Pop();   S.Print();
    S.Pop();   S.Print();
    S.Top();

    return 0;
}﻿