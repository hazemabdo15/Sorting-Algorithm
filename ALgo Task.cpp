#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define size 100000
int garray[size];

void initialize(int garray[]) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		garray[i] = rand() % 100000 + 1;
	}
}
void insertion_sort(int* array, int length) {
	for (int i = 1; i < length; i++) {
		int key = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
	printf("The array is sorted using insertion sort in %u seconds\n", clock());
}


void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


void quick_sort(int start, int end) {
	if (start >= end)return;
	int key = start, i = start + 1, j = end;
	while (i <= j) {
		while (i <= end && garray[i] <= garray[key]) i++;
		while (j > start && garray[j] >= garray[key])j--;
		if (i > j) swap(&garray[key], &garray[j]);
		else swap(&garray[i], &garray[j]);
	}
	quick_sort(start, j - 1);
	quick_sort(j + 1, end);
}


void print_array(int array[]) {
	printf("[ ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", array[i]);
	}
	printf("]");
	printf("\n");
}


int main() {
	int array[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 100000 + 1;
	}
	printf("Array initialized\n");
	insertion_sort(array, size);
	initialize(garray);
	quick_sort(0, size - 1);
	printf("The array is sorted using quick sort in %u seconds", clock());
	return 0;
}