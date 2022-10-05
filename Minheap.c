// A C++ program to demonstrate common Binary Heap Operations
#include<stdio.h>
#include<limits.h>

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);

// A class for Min Heap
	int *harr; // pointer to array of elements in heap
	int capacity; // maximum possible size of min heap
	int heap_size; // Current number of elements in min heap


	// to heapify a subtree with the root at given index
	void MinHeapify(int );

	int parent(int i) { return (i-1)/2; }

	// to get index of left child of node at index i
	int left(int i) { return (2*i + 1); }

	// to get index of right child of node at index i
	int right(int i) { return (2*i + 2); }

	// to extract the root which is the minimum element
	void extractMin();

	
	// Returns the minimum key (key at root) from min heap
	int getMin() { return harr[0]; }

	// Deletes a key stored at index i
	void deleteKey(int i);

	// Inserts a new key 'k'
	void insertKey(int k);



// Inserts a new key 'k'
void insertKey(int k)
{

	// First insert the new key at the end
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	// Fix the min heap property if it is violated
	while (i != 0 && harr[parent(i)] > harr[i])
	{
	swap(&harr[i], &harr[parent(i)]);
	i = parent(i);
	}
}


// Method to remove minimum element (or root) from min heap
void extractMin()
{


	// Store the minimum value, and remove it from heap
	int root = harr[0];
	harr[0] = harr[heap_size-1];
	heap_size--;
	MinHeapify(0);
}




// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
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

// Driver program to test above functions
int main()
{
    int i,a;
    printf("Enter the size of the array");
    scanf("%d",&capacity);
    for(i=0;i<capacity;i++)
    {
        printf("Enter the array element");
        scanf("%d",&a);
        insertKey(a);
    }
	
    extractMin();
    for(i=0;i<capacity;i++)
        printf("%d",harr[i]);
	return 0;
}
