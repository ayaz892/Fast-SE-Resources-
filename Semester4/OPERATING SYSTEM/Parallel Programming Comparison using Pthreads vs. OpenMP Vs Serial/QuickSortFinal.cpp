#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>
#include <stdbool.h>
#include <omp.h>


#define N 100000
#define THRESHOLD (N / 12)

#define swap(x, y) \
    int _t = x;    \
    x = y;         \
    y = _t;

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

int partition(int *arr, int lo, int hi)
{
    int pivot = arr[hi];
    int i = lo - 1;
    for (int j = lo; j < hi; ++j)
    {
       
        if (arr[j] < pivot)
        {
            ++i;
            swap(arr[i], arr[j]);
            
        }
    }
    swap(arr[i + 1], arr[hi]);
    return i + 1;
}

void *quickSortThreadFunc(void *arg);

//function for pthread
void quickSortHelper(int *arr, int lo, int hi)
{
    if (lo < hi)
    {
        int pi = partition(arr, lo, hi);
        pthread_t id = 0;
        ThreadArg arg = {arr, lo, pi - 1};
        
        if (arg.hi - arg.lo > THRESHOLD)
        {
            pthread_create(&id, NULL, quickSortThreadFunc, &arg); 
        }
        else
        { 
            quickSortHelper(arr, lo, pi - 1); 
        }
        quickSortHelper(arr, pi + 1, hi); 
        if (id != 0)
        {
            pthread_join(id, NULL);
        }
    }
}

void *quickSortThreadFunc(void *arg)
{
    ThreadArg *qarg = (ThreadArg *)arg;
    //printf("\n~Thread created~\n");
    quickSortHelper(qarg->arr, qarg->lo, qarg->hi);
    return NULL;
}

void quickSort(int *arr, int size)
{
    
    quickSortHelper(arr, 0, size - 1);
}

//quicksort real function
void quickSortNormal(int *arr, int lo, int hi)
{
    if (lo < hi)
    {
//parallel section for openmp
        int pi = partition(arr, lo, hi);
         //executing left half
        quickSortNormal(arr, lo, pi - 1); 
        //executing right half
        quickSortNormal(arr, pi + 1, hi); 
        
    }
}


int main()
{
 	FILE *obj;
	obj = fopen("OuickSort.txt", "w");
	 
	 
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
    quickSortNormal(arr,0,N-1);
    end_time = read_timer(); 
	
	
    printf("\n");
    printf("The execution serial time was:  %lf secs\n", end_time - start_time);
    free(arr);
    
    fprintf(obj,"%lf\n",end_time - start_time);

	
	//pthread
	start_time = read_timer(); 
    quickSort(arr2, N);
    end_time = read_timer(); 

    printf("\n");
    printf("The execution time Pthread was:  %lf secs\n", end_time - start_time);
    free(arr2);
	
	fprintf(obj,"%lf\n",end_time - start_time);
	
	//OpenMp    
    #pragma omp parallel
	 
	{
//calling quicksort parallel
	quickSortNormal(arr3, 0, N-1);
	}
    end_time = read_timer(); 

    printf("\n");
    printf("The execution time OpenMp was:  %lf secs\n", end_time - start_time);
  // for(int i=0;i<N;i++)
//{
///	printf("\n%d",arr3[i]);
//	}
    free(arr3);

    fprintf(obj,"%lf\n",end_time - start_time);
    
    fclose(obj);
}
