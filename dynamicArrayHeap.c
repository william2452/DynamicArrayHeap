/*
William McClean
CS 260
Assignment 8
11 November 2022
*/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "dynamicArray.h"

/*
    compare: compare two tasks by priority
    param: left - first task
    param: right - second task
    pre: left is not NULL
    pre: right is not NULL
    post: none
	return: return scheme is below
        -1 if priority of left < priority of right
        1 if priority of left > priority of right
        0 if priority of left = priority of right
    HINT - left and right are structs and have members
    HINT - you are comparing the priority of the tasks
    HINT - left and right are not pointers, you don't need ->
*/
int compare(TYPE left, TYPE right) {
	/* FIX ME */
	/*
	assert(left != NULL);
	assert(right != NULL);
	*/

    if(left.priority < right.priority) {
        return -1;
    } else if(left.priority > right.priority) {
        return 1;
    } else {
        return 0;
    }
}

/*
	initDynArr: Initialize (including allocation of data array) dynamic array.
	param1: d - pointer to the dynamic array
	param2 : capacity - capacity of the dynamic array
	pre: d is not null
	pre: capacity > 0
	post: memory is dynamically allocated for the data array
	post: size is set to 0
	post: capacity is set
*/
void initDynArr(struct DynArr *d, int capacity) {
	assert(capacity > 0);
	assert(d != NULL);

	d->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
	d->size = 0;
	d->capacity = capacity;
}

/*
	createDynArr: Allocate and initialize dynamic array.
	param: cap desired capacity for the dynamic array
	ret: a pointer to an empty dynArr of cap capacity
	pre: cap is greater than 0
	post: memory has been allocated to the dynamic array

*/
struct DynArr *createDynArr(int cap) {
	assert(cap > 0);

	struct DynArr *dyn;
	dyn = malloc(sizeof(struct DynArr));
	if(!dyn) {
		printf("Failed to allocate memory \n");
	}
	initDynArr(dyn,cap);
	return dyn;
}

/*
	freeDynArr: Deallocate data array in dynamic array.
	param: d - pointer to the dynamic array
	pre: d is not NULL
	post: the memory used by d->data is freed
*/
void freeDynArr(struct DynArr *d) {
	if(d->data != NULL) {
		free(d->data); /* free the space on the heap */
		d->data = NULL; /* make it point to null */
	}
}

/*
	deleteDynArr: Deallocate data array and the dynamic array.
	param: d - pointer to the dynamic array
	pre: d is not NULL
	post: the memory used by d is freed
	freeDynArr is called to free the data array
*/
void deleteDynArr(struct DynArr *d) {
	assert(d != NULL);

	freeDynArr(d);
	free(d);
	d = 0;
}

/*
	sizeDynArr: Get the size of the dynamic array
	param: d - pointer to the dynamic array
    ret: the size of the dynamic array
	pre: d is not null
	post: none
*/
int sizeDynArr(struct DynArr *d) {
	assert(d != NULL);

	return d->size;
}

/*
	getDynArr: Get an element from the dynamic array from a specified position
	param1: d - pointer to the dynamic array
	param2: pos - integer index to get the element from
    return: value stored at index position, pos
	pre: d is not null
	pre: d is not empty
	pre: pos < size
	pre: pos >= 0
	post: no changes to the dynamic array
*/
TYPE getDynArr(struct DynArr *d, int pos) {
	assert(d != NULL);
	assert(pos < d->size);
	assert(pos >= 0);

	return d->data[pos];
}

/*
    resizeDynArr: resizes the old array to the size of capacity
    param1: d - pointer to the dynamic array
	param2: newCap - the new desired capacity
	pre: d is not null
	pre: newCap > d->size
	post: old d->data has been freed
	post: d->data points to a new, larger chunk of memory
	post: old data has been copied into new data
*/
void resizeDynArr(struct DynArr *d, int newCap) {
    /* FIX ME */
    assert(d != NULL);
    assert(newCap > d -> size);

    struct DynArr *newDynArr = malloc(sizeof(struct DynArr) * newCap);
    int i = 0;

    while(i < d -> size-1) {
        newDynArr -> data[i] = d -> data[i];
        i++;
    }
    free(d -> data);
    d -> data = 0;
}

/*
	addDynArr: Adds an element to the end of the dynamic array
	param: d - pointer to the dynamic array
	param: val - the value to add to the end of the dynamic array
	pre: d is not NULL
	post: size increases by 1
	post: if reached capacity, capacity is doubled
	post: val is in the last utilized position in the array
*/
void addDynArr(struct DynArr *d, TYPE val) {
	assert(d != NULL);

	/* If full, then re-size */
	if(d->size >= d->capacity) {
		resizeDynArr(d, d->capacity * 2);
	}
	d->data[d->size] = val;
	d->size++;
}

/*
	putDynArr: Put an item into the dynamic array at the specified location, overwriting the element that was there
	param1: d - pointer to the dynamic array
	param2: pos - the index to put the value into
	param3: val	- the value to insert
	pre: d is not null
	pre: pos >= 0 and pos
	pre: pos < capacity
	post: index (pos) contains new value (val)
*/
void putDynArr(struct DynArr *d, int pos, TYPE val) {
	assert(d != NULL);
    assert(pos >= 0);
	assert(pos < d->capacity);

	d->data[pos] = val;
}

/*
	swapDynArr: Swap two specified elements in the dynamic array
	param1: d - pointer to the dynamic array
	param2: i - one of the elements to be swapped
	param3: j - one of the elements to be swapped
	pre: d is not null
	pre: d is not empty
	pre: i >= to 0
	pre: j >= to 0
	pre: i < size of the dynamic array
	pre: j < size of the dynamic array
	post: index i now holds the value at j and index j now holds the value at i
*/
void swapDynArr(struct DynArr *d, int i, int  j) {
	TYPE  temp;
	assert(d != NULL);
	assert(i <= d->size);
	assert(j <= d->size);
	assert(i >= 0);
	assert(j >= 0);

	temp = d->data[i];
	d->data[i] = d->data[j];
	d->data[j] = temp;
}

/*
	removeAtDynArr: Remove the element at the specified location from the array, shifts other elements back one to fill the gap
	param1: d - pointer to the dynamic array
	param2: pos - location of element to remove
	pre: d is not null
	pre: d is not empty
    pre: pos >= 0
	pre: pos < size
	post: the element at pos is removed
	post: the elements past pos are shifted back one
*/
void removeAtDynArr(struct DynArr *d, int idx) {
	int i;
	assert(d != NULL);
	assert(idx < d->size);
	assert(idx >= 0);

   /* Shift all elements up */
   for(i = idx; i < d->size-1; i++){
      d->data[i] = d->data[i+1];
   }
   d->size--;
}

/*
	isEmptyDynArr: returns boolean based on whether the array is empty
	param: d - pointer to the dynamic array
	pre: d is not null
	post: none
	ret: 1 if empty, otherwise return 0
*/
int isEmptyDynArr(struct DynArr *d) {
	assert(d != NULL);

	if(d->size == 0) {
		return 1;
	}
	return 0;
}


/*
	Min-heap-based priority queue implementation ----------------------------------- Starts here --------------------------------------
*/


/*
	addHeap: Add a node to the min-heap in last position
	param1: heap - pointer to the heap
	param2: val - task to be added to the heap
	pre: heap is not null
	post: node is added to the heap
    post: heap properties are maintained
	HINT: dereference the pointer as you pass it to the dynamic array function
	HINT: call siftUp() to get the node in place
	HINT: _siftUp is where most of the work happens
*/
void addHeap(struct DynArr *heap, TYPE *val) {
	/* FIXME */
    assert(heap != NULL);

    addDynArr(heap, *val);
    _siftUp(heap, heap -> size-1);
}


/*
	_siftUp: Compare node to it's parent and swap it up the min-heap until it is in place
	param1: heap - pointer to the heap
	param2: index - the index of the child node (to be swapped)
	pre: heap is not null
	pre: index < heap->size
	pre: index >= 0
	post: heap properties are maintained
	HINT: This is what the compare function is for
*/
void _siftUp(struct DynArr *heap, int index) {
	/* FIXME */
    assert(heap != NULL);
    assert(index < heap -> size);
    assert(index >= 0);

    int child = index; /*redeclare to make it easier to follow in my mind*/
    int parent = (index-1)/2;

    while(child > 0) {
        int node = compare(heap->data[child], heap->data[parent]);

        if(node == -1) { /*parent > child*/
            swapDynArr(heap, child, parent);
            child = parent;
            parent = (child-1)/2;
        } else { /*child > parent OR child == parent*/
            return;
        }/*end if/else*/
    }/*end while*/
}


/*
	getMinHeap: Get the first node in the min-heap (root)
	param: heap - pointer to the heap
	return: value of first node in the min-heap
	pre: heap is not empty
	post: no changes to the heap

*/
TYPE getMinHeap(struct DynArr *heap) {
	/* FIXME */
	assert(heap -> size > 0);

	return heap->data[0];
}





/*
	removeMinHeap: Remove the first node from the min-heap -  call siftDown() to get the node in place
	param: heap - pointer to the heap
	pre: heap is not empty
	post: the minimum node is removed from the min-heap
	post: the last node is copied into the first position in the dynamic array
	post: dynamic array size has been decremented
	HINT: use _siftDown to sift elements down
    HINT: _siftDown is where most of the work happens
*/
void removeMinHeap(struct DynArr *heap) {
	/* FIXME */

    swapDynArr(heap, 0, heap->size-1);
    removeAtDynArr(heap, heap->size-1);
    _siftDown(heap, 0);
}


/*
	_smallerIndexHeap: Get the index of the smaller node between two nodes in a min-heap - this is an auxiliary function
	param1: heap - pointer to the heap
	param2: i - index of one node
	param3: j - index of the other node
	return: the index of the smaller node
	pre: i < size
	pre: j < size
	pre: j <= 0
	pre: j <= 0
	post: no changes to the min-heap
	used by siftDown()
	HINT: This is what the compare function is for
*/
int _smallerIndexHeap(struct DynArr *heap, int i, int j) {
	/* FIXME */
    assert(i < heap->size);
    assert(j < heap->size);
    assert(i >= 0);
    assert(j >= 0);

    int node = compare(heap->data[i], heap->data[j]);
    if(node == -1) {
        return i;
    } else if(node == 1) {
        return j;
    } else {
        return i; /*if they are the same, or if right node doesn't exist, return left node*/
    }
}



/*
	_siftDown: Compare index to it's children and swap with the smaller element
	param1: heap - pointer to the heap
	param2: index - the index of the parent node to be potentially swapped
	pre: heap is not null
	post: heap properties have been preserved - this function gets a heap where the root is (probably) out of order
    HINT: use the _smallerIndexHeap to find the smaller child node of the current node
	HINT: - if there is only an lChild, then that is a specific case
	HINT: - This is the most difficult function
*/
void _siftDown(struct DynArr *heap, int index) {
	/* FIXME */

	int parent = index; /*redeclaring so I can picture better*/
	int smallerChild = 0;
	int leftChild = 0;
	int rightChild = 0;

	while((parent*2)+1 < heap->size) {
        leftChild = (parent*2)+1;
        rightChild = (parent*2)+2;

        if(rightChild >= heap -> size) {
            smallerChild = leftChild;
        } else if (_smallerIndexHeap(heap, leftChild, rightChild) == rightChild) {
            smallerChild = rightChild;
        } else {
            smallerChild = leftChild;
        }/*end if/else*/

        if(_smallerIndexHeap(heap, parent, smallerChild) == smallerChild) {
            swapDynArr(heap, parent, smallerChild);
        }/*end if/else*/

        parent = smallerChild;
	}/*end while*/
}


/*
	sortHeapHeap: Print the heap in sorted order. Each node is removed from the heap - print the information about each task as each is removed
	param: heap - the heap full of tasks to print
	pre: heap is not empty
	post: every node is removed from the min-heap
	format: "Priority: XX - Description: Ipsum Lorem" - use the printTask function
	HINT: Use getMinHeap to get each task
    HINT: Use printTask to print each task - Written in main
	HINT: Use removeMinHeap to remove each task
*/
void sortHeap(struct DynArr *heap) {
	/* FIXME */
    assert(heap->size > 0);

    while(heap->size > 0) {
        printTask(getMinHeap(heap));
        removeMinHeap(heap);
    }
}




/*///////////////  ************PART 2****************  ///////////////*/

/*
#1: What is the big-O complexity of getMinHeap?
O(1)

#2: What is the big-O complexity of addHeap?
O(1)+

#3: Describe the worst-case performance of addHeap?
Worst case performance of addHeap is adding the value to the array
and needing to resize the array and swap values in the array. You
don't always need to do those things though.

#4: What is the big-O complexity of removeMinHeap?
O(logn)

#5: What is the big-O complexity of processHeap?
O(n)

#6: How many potential swaps will happen in the worst-case when inserting into a heap with 127 nodes?
2^7 = 128. Tree height = 7, so 7 swaps is the worst case.


*/

