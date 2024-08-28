/*
	file: main_heap.c
	Heap test file
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "dynamicArray.h"

/*
	printTestResult: function to print the result of a test function
	param1: predicate - the result of the test
	param2: nameTestFunction - name of the function being tested
	param3: message - message passed to the test function
	post: result is printed to standard output
*/
void printTestResult(int predicate, char *nameTestFunction, char *message) {
	if (predicate) {
	   printf("%s() - %s: PASS\n",nameTestFunction, message);
	} else {
	   printf("%s() - %s: FAIL\n",nameTestFunction, message);
	}
}

/*
	createTask: create a task from the description and the priority
	param: priority - priority of the task
	param: desc - pointer to the description string
	pre: none
	post: none
	return: a task with description and priority
*/
struct task *createTask(int priority, char *desc) {
	struct task *newTask = malloc(sizeof(struct task));
	newTask->priority = priority;
	strcpy(newTask->description, desc);
	return newTask;
}

/*
	printTask: Display the information about the first node in the heap (root)
	param: task - the task to print
	pre: heap is not empty
	post: no changes to the heap
	return: the task priority and description are printed to standard output
	format: "Priority: XX - Description: Ipsum Lorem"
*/
void printTask(TYPE task) {
	printf("Priority: %d - Description: %s \n",task.priority, task.description);
}


int main() {
	/* Create task list */
	struct DynArr *taskList = createDynArr(16);

	/* Create tasks */
	struct task *task1 = createTask(10, "Clean house");
	struct task *task2 = createTask(6, "Eat dinner");
	struct task *task3 = createTask(2, "Do laundry");
	struct task *task4 = createTask(4, "Do dishes");
	struct task *task5 = createTask(5, "Grocery shopping");
	struct task *task6 = createTask(7, "Change oil");
	struct task *task7 = createTask(13, "Do taxes");
	struct task *task8 = createTask(8, "Sleep");
	struct task *task9 = createTask(1, "Do other homework");
	struct task *task10 = createTask(0, "Finish heap homework");

    printf("Beginning testing... \n");

    printf("------------------Testing addHeap------------------ \n");
	/* add tasks to the dynamic array - first three inserts are tested*/
	printf("Add task with priority 10 to min-heap\n");
	addHeap(taskList, task1);
	printTestResult(taskList->data[0].priority == 10, "getDynArr", "Priority of index(0) == 10");

	printf("Add task with priority 6 to min-heap\n");
	addHeap(taskList, task2);
	printTestResult(taskList->data[0].priority == 6, "getDynArr", "Priority of index(0) == 6");
	printTestResult(taskList->data[1].priority == 10, "getDynArr", "Priority of index(1) == 10");

	printf("Add task with priority 2 to min-heap\n");
	addHeap(taskList, task3);
	printTestResult(taskList->data[0].priority == 2, "getDynArr", "Priority of index(0) == 2");
	printTestResult(taskList->data[1].priority == 10, "getDynArr", "Priority of index(1) == 10");
	printTestResult(taskList->data[2].priority == 6, "getDynArr", "Priority of index(2) == 6");

	printf("Add task with priority 4 to min-heap\n");
	addHeap(taskList, task4);
	printTestResult(taskList->data[0].priority == 2, "getDynArr", "Priority of index(0) == 2");
	printTestResult(taskList->data[1].priority == 4, "getDynArr", "Priority of index(1) == 4");
	printTestResult(taskList->data[2].priority == 6, "getDynArr", "Priority of index(2) == 6");
	printTestResult(taskList->data[3].priority == 10, "getDynArr", "Priority of index(3) == 10");

	printf("Add task with priority 5 to min-heap\n");
	addHeap(taskList, task5);
	printTestResult(taskList->data[0].priority == 2, "getDynArr", "Priority of index(0) == 2");
	printTestResult(taskList->data[1].priority == 4, "getDynArr", "Priority of index(1) == 4");
	printTestResult(taskList->data[2].priority == 6, "getDynArr", "Priority of index(2) == 6");
	printTestResult(taskList->data[3].priority == 10, "getDynArr", "Priority of index(3) == 10");
	printTestResult(taskList->data[4].priority == 5, "getDynArr", "Priority of index(4) == 5");

    /* It is your job to test past this point */
	printf("Add task with priority 7 to min-heap\n");
	addHeap(taskList, task6);
	printf("Add task with priority 13 to min-heap\n");
	addHeap(taskList, task7);
	printf("Add task with priority 8 to min-heap\n");
	addHeap(taskList, task8);
    printf("Add task with priority 1 to min-heap\n");
	addHeap(taskList, task9);
    printf("Add task with priority 0 to min-heap\n");
	addHeap(taskList, task10);

	printf("--------------------Printing getDynArr() Test Results--------------------\n");
	/*  This will fail assertions until you actually build the insert */
	printTestResult(getDynArr(taskList, 0).priority == 0, "getDynArr", "Priority of index(0) == 0");
	printTestResult(getDynArr(taskList, 1).priority == 1, "getDynArr", "Priority of index(1) == 1");
	printTestResult(getDynArr(taskList, 2).priority == 6, "getDynArr", "Priority of index(2) == 6");
	printTestResult(getDynArr(taskList, 3).priority == 4, "getDynArr", "Priority of index(3) == 4");
	printTestResult(getDynArr(taskList, 4).priority == 2, "getDynArr", "Priority of index(4) == 2");
	printTestResult(getDynArr(taskList, 5).priority == 7, "getDynArr", "Priority of index(5) == 7");
	printTestResult(getDynArr(taskList, 6).priority == 13, "getDynArr", "Priority of index(6) == 13");
	printTestResult(getDynArr(taskList, 7).priority == 10, "getDynArr", "Priority of index(7) == 10");
	printTestResult(getDynArr(taskList, 8).priority == 8, "getDynArr", "Priority of index(8) == 8");
	printTestResult(getDynArr(taskList, 9).priority == 5, "getDynArr", "Priority of index(9) == 5");

	printf("------------------Testing getMinHeap------------------ \n");
	printTestResult(getMinHeap(taskList).priority == 0, "getMinHeap", "Priority == 0");

	printf("------------------Testing removeMinHeap------------------ \n");
	removeMinHeap(taskList);
	printf("Remove min task with priority 0 from min-heap\n");
	printf("------------------Testing getMinHeap------------------ \n");
	printTestResult(getMinHeap(taskList).priority == 1, "getMinHeap", "Priority == 1");
	printf("--------------------Printing getDynArr() Test Results--------------------\n");
	printTestResult(getDynArr(taskList, 0).priority == 1, "getDynArr", "Priority == 1");
	printTestResult(getDynArr(taskList, 1).priority == 2, "getDynArr", "Priority == 2");
	printTestResult(getDynArr(taskList, 2).priority == 6, "getDynArr", "Priority == 6");
	printTestResult(getDynArr(taskList, 3).priority == 4, "getDynArr", "Priority == 4");
	printTestResult(getDynArr(taskList, 4).priority == 5, "getDynArr", "Priority == 5");
	printTestResult(getDynArr(taskList, 5).priority == 7, "getDynArr", "Priority == 7");
	printTestResult(getDynArr(taskList, 6).priority == 13, "getDynArr", "Priority == 13");
	printTestResult(getDynArr(taskList, 7).priority == 10, "getDynArr", "Priority == 10");
	printTestResult(getDynArr(taskList, 8).priority == 8, "getDynArr", "Priority == 8");


	printf("--------------testing sortHeap-------------- \n");
	/* Should print - 1 2 4 5 6 7 8 10 13 (with descriptions) */
	sortHeap(taskList);

	printf("------------------Initial testing complete------------------ \n");

	return 0;
}
