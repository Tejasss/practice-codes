/* Find minimum number of swaps to get an array sorted in ascending order (elements in array are distinct) */
/* Algorithm: https://www.youtube.com/watch?v=f7IIW0HVUcQ */
#include<stdio.h>
/* For qsort(), bsearch() functions */
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int compare(const void* x, const void* y)
{
	int a = *((int*) x);
	int b = *((int*) y);
	/* Return negative if a should be before b, 0 if equal, positive if a should be after b */
	/* Ascending order */
	if(a < b)
		return -1; 
	if(a > b)
		return 1;
	else
		return 0;
	/* OR */
	/*
	return (a > b) - (a < b);
	*/
}

int find_cycle(int startIndex, int* arr, int* sorted_arr, bool* visited, int nItems)
{
	int noElements = 0;
	int nextEleIndex = startIndex;
	do
	{
		visited[nextEleIndex] = true;
		nextEleIndex = (int)((int*)bsearch(&arr[nextEleIndex], sorted_arr, nItems, sizeof(*arr), compare) - sorted_arr);
		noElements++;
	}while(arr[nextEleIndex] != arr[startIndex]);
	return noElements;
}

int main()
{
	int arr[] = {5, 7, 12, 6, 9, 2};
	int nItems = sizeof(arr)/sizeof(*arr);
	printf("Entered array is ");
	for(int i = 0; i<nItems; i++)
		printf("%d ", arr[i]);
	printf("\n");
	int* sorted_arr = (int*) malloc(sizeof(arr));
	memcpy(sorted_arr, arr, sizeof(arr));	
	qsort(sorted_arr, nItems, sizeof(*arr), compare);
	bool* visited = (bool*) calloc(nItems, sizeof(bool));
	int noSwaps = 0, noElements = 0;
	for(int i = 0; i<nItems; i++)
	{
		if(visited[i] == true)
			continue;
		noElements = find_cycle(i, arr, sorted_arr, visited, nItems);
		noSwaps += (noElements - 1);
	}
	printf("Minimum number of swaps to sort the array = %d\n", noSwaps);
	return 0;
}
