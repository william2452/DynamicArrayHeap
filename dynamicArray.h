/*
	file: dynamicArray.h
	Dynamic array implementation
*/

#define TYPE struct task

#define TASK_DESC_SIZE 128

struct task {
	char description[TASK_DESC_SIZE]; /* description of the task */
	int priority; /* task priority */
};

struct DynArr {
	TYPE *data;	/* pointer to the data array */
	int size; /* Number of elements in the array */
	int capacity; /* capacity of the array */
};

/* used to compare TYPEs - in this case, "tasks" */
int compare(TYPE left, TYPE right);

/* used to print task information */
void printTask(TYPE task);

/* Dynamic Array Functions */
void initDynArr(struct DynArr *d, int capacity);
struct DynArr *createDynArr(int cap);
void deleteDynArr(struct DynArr *d);
int sizeDynArr(struct DynArr *d);
void resizeDynArr(struct DynArr *d, int newCap);
void addDynArr(struct DynArr *d, TYPE val);
TYPE getDynArr(struct DynArr *d, int pos);
void addDynArr(struct DynArr *d, TYPE val);
void putDynArr(struct DynArr *d, int pos, TYPE val);
void swapDynArr(struct DynArr *d, int i, int  j);
void removeAtDynArr(struct DynArr *d, int idx);


/* Heap-based Priority Queue Interface */
TYPE getMinHeap(struct DynArr *heap);
int _smallerIndexHeap(struct DynArr *heap, int i, int j);
void _siftUp(struct DynArr *heap, int index);
void _siftDown(struct DynArr *heap, int index);
void addHeap(struct DynArr *heap, TYPE *val);
void removeMinHeap(struct DynArr *heap);
void sortHeap(struct DynArr *heap);
