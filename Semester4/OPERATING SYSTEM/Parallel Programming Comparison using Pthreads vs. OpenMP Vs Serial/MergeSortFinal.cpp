#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>
#include <stdbool.h>
#include <omp.h>



#define N 100000
#define THRESHOLD (N / 12)


double read_timer()
{
    static bool initialized = false;
    static struct timeval start;
    struct timeval end;
    if (!initialized)
    {
        gettimeofday(&start, NULL);
        initialized = true;
    }
    gettimeofday(&end, NULL);
    return (end.tv_sec - start.tv_sec) + 1.0e-6 * (end.tv_usec - start.tv_usec);
}

double start_time, end_time; 

typedef struct
{
    int *arr;
    int lo;
    int hi;
} ThreadArg;


void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];


	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}


void* MergeSortThreadFunction(void* arg);

void MergeSortHelper(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
        pthread_t id = 0;
        pthread_t id2 = 0;

		ThreadArg arg = {arr, l, m};
        
		if (arg.hi - arg.lo > THRESHOLD)
        {
            pthread_create(&id, NULL, MergeSortThreadFunction, &arg);		
		}
		else
		{
			MergeSortHelper(arr, l, m);
		}
				
		MergeSortHelper(arr, m+1, r);
				
		if (id != 0)
        {
            pthread_join(id, NULL);
        }
                      
        merge(arr,l,m,r);
	}
}


void MergeSortNormal(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
        
	
		MergeSortHelper(arr, l, m);
			
		MergeSortHelper(arr, m+1, r);              
        merge(arr,l,m,r);
	}
}


void* MergeSortThreadFunction(void *arg)
{
    
    ThreadArg *qarg = (ThreadArg *)arg;
    //printf("\n~Thread created~\n");
    MergeSortHelper(qarg->arr, qarg->lo, qarg->hi);
    return NULL;
}

void MergeSort(int *arr, int size)
{
    
    MergeSortHelper(arr, 0, size - 1);
}


void printArray(int A[], int size)
{
	int i;
	for (i=0; i < size; i++)	
	printf("%d ", A[i]);
}



int main()
{	
	FILE *obj;
	obj = fopen("MergeSort.txt", "w");


	int *arr = (int*)malloc(N * sizeof(long));
	int* arr2 = (int*)malloc((N+1) * sizeof(long));
	int* arr3 =  (int*)malloc((N+1) * sizeof(long));
	
    
    for (int i = 0; i < N; i++)
    {	
    	int temp = rand() % 100000;
        arr[i] = temp;
        arr2[i] = temp;
        arr3[i] = temp;
    }

    

	start_time = read_timer(); 
    MergeSortNormal(arr, 0, N-1);
    end_time = read_timer(); 
	
    
    printf("\n");
    printf("The execution time Normal was:  %lf secs\n", end_time - start_time);
    free(arr);
	
	fprintf(obj,"%lf\n",end_time - start_time);

	
	//pthread
	start_time = read_timer(); 
    MergeSort(arr2, N);
    end_time = read_timer(); 
	
	
	printf("\n");
    printf("The execution time Pthread was:  %lf secs\n", end_time - start_time);
    free(arr2);
	
	
	fprintf(obj,"%lf\n",end_time - start_time);

	//OpenMp
	start_time = read_timer(); 
	#pragma omp parallel
	{
	MergeSortNormal(arr3, 0, N - 1);
	}
	end_time = read_timer(); 

    printf("\n");
    printf("The execution time OpenMp was:  %lf secs\n", end_time - start_time);
    free(arr3);
	
	fprintf(obj,"%lf\n",end_time - start_time);

	fclose(obj);

	
}
