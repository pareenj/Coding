HEAPS

A Binary Heap is a complete tree, i.e, (All Levels are completely filled except possibly the last level,  
										& the last level has all keys as left as possible)
It is either a Min Heap or a Max Heap.

A Binary Heap is typically represented as an array.
The root element is at arr[0]
For the ith node, i.e, For arr[i]:
	- Its parent node is at index arr[(i - 1)/ 2]
	- Its left child node is at index arr[(2*i) + 1]
	- Its right child node is at index arr[(2*i) + 2]
The traversal method is Level Order Traversal.

Operations on Min Heap:
1. Return Minimum Element 	-	O(1)	- Return root element of the Heap
2. Extract Minimum Element 	- O(log(n))	- Removes minimum element; log(n) to heapify after removing the root
3. Decrease Value of Key 	- O(log(n))	- If decreased value becomes smaller than its parent, then we heapify
4. Insert a New Key 		- O(log(n)) - Add the New key at the end of the tree; If New Key > its parent, heapify
5. Delete a Key 			- O(log(n)) - Replace the key to be deleted with -∞ by decreasing the key value;
										  The -∞ value must reach the root, so that we can remove it by Extracting it

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);

class MinHeap
{
	int *heap_array; 	// Pointer to Array of elements in Heap
	int capacity; 		// Maximum possible size of Min Heap
	int heap_size; 		// Current number of elements in the Min Heap

public:

	// Constructor 
	MinHeap(int capacity);
	// ~MinHeap();

	// to Heapify a subtree with the root at given index;
	void MinHeapify(int root);

	// to get index of parent of node at given index i
	int parent(int i)
	{
		return (i-1)/2;
	}

	// to get index of left child of node at given index i
	int left(int i)
	{
		return (2*i) + 1;
	}

	// to get index of right child of node at given index i
	int right(int i)
	{
		return (2*i) + 2;
	}

	// to extract the root which is the minimum element
	int extractMin();

	// Decreases the key value of key at index i to new_val
	void decreaseKey(int i, int new_val);

	// Returns the minimum key (key at root) from Min Heap
	int getMin()
	{
		return heap_array[0];
	}

	// Deletes a key stored at index i
	void deleteKey(int i);

	// Inserts a new key 'k'
	void insertKey(int k);
};

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	heap_array = new int[cap];
}

// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
	if(heap_size == capacity)
	{
		cout << "\nOverFlow: Could not Insert Key";
		return;
	}

	// First insert the New Key at the End
	heap_size++;
	int i = heap_size - 1;
	heap_array[i] = k;

	// Fix the Min Heap property if it is violated
	while(i != 0 && heap_array[parent(i)] > heap_array[i])
	{
		swap(&heap_array[i], &heap_array[parent(i)]);
		i = parent(i);
	}
}

// Decreases value of key at index 'i' to new_val
// It is assumed that new_val is smaller than heap_array[i].
void MinHeap::decreaseKey(int i, int new_val)
{
	heap_array[i] = new_val;

	while(i != 0 && heap_array[parent(i)] > heap_array[i])
	{
		swap(&heap_array[i], &heap_array[parent(i)]);
		i = parent(i);
	}
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
	if(heap_size <= 0)
		return INT_MAX;

	if(heap_size == 1)
	{
		heap_size--;
		return heap_array[0];
	}

	// Store the minimum value, and remove it from the heap
	int root = heap_array[0];
	heap_array[0] = heap_array[heap_size - 1];
	heap_size--;
	MinHeapify(0);

	return root;
}

// This function deletes key at index i
void MinHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	extractMin();
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);

	int smallest = i;

	if(l < heap_size && heap_array[l] < heap_array[i])
	{
		smallest = l;
	}
	if(r < heap_size && heap_array[r] < heap_array[smallest])
	{
		smallest = r;
	}
	if(smallest != i)
	{
		swap(&heap_array[i], &heap_array[smallest]);
		MinHeapify(smallest);
	}
}

// A utility function to swap two elements
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// Driver program to test above function
int main()
{
	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.deleteKey(1);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	cout << h.extractMin() << " ";
	cout << h.getMin() << " ";
	h.decreaseKey(2, 1);
	cout << h.getMin();
	return 0;
}