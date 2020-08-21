/* Find minimum number of swaps to get an array sorted in ascending order */

#include<stdio.h>
/* For qsort(), bsearch() functions */
#include<stdlib.h>

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

int main()
{
	int arr[] = {5, 6, 8, 2, 9, 1, 0, 12};
	qsort(arr, sizeof(arr)/sizeof(*arr), sizeof(*arr), compare);	
	for(int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
		printf("%d ", arr[i]);
	printf("\n");
	int item = 6;
	int *pItem = NULL;
	pItem = (int*) bsearch(&item, arr, sizeof(arr)/sizeof(*arr), sizeof(*arr), compare);
	if(pItem)
		printf("Found\n");
	else
		printf("Not found\n");
	
	return 0;
}
