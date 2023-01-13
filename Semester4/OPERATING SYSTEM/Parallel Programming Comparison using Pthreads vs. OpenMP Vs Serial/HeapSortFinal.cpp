#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>
#include <stdbool.h>
#include<omp.h>


#define N 1000001
#define THRESHOLD (N / 12)

#define swap(x, y) \
    int _t = x;    \
    x = y;         \
    y = _t;
    
    
typedef struct
{
    int *arr;
    int size;
} ThreadArg;    
    
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


// Actual Min Heap Function
void MaxHeapify(int Arr[], int Position, int Size)
{
	int LeftChild = (Position * 2);
	int RightChild = (Position * 2) + 1;
	int Largest = Position;
	if(LeftChild < Size)
	{
		if(Arr[LeftChild] > Arr[Largest])
		{
			Largest = LeftChild;
		}
	}
	if(RightChild < Size)
	{
		if(Arr[RightChild] > Arr[Largest])
		{
			Largest = RightChild;
		}
	}
	if(Largest != Position)
	{
		swap(Arr[Position], Arr[Largest]);
		MaxHeapify(Arr, Largest, Size);
	}
}
// Heapify used when inserting nodes/building Heap
void Heapify(int Arr[], int Position, int Size)
{
	int Parent = Position / 2;
	if(Parent >= 1 && Position > 1)
	{
		if(Arr[Position] > Arr[Parent])
		{
			swap(Arr[Position], Arr[Parent]);
			Heapify(Arr, Parent, Size);
		}
	}
}
// Loop for Heap Sort
void* HeapSort(void* args)
{	
	
	ThreadArg *qarg = (ThreadArg *)args;

	int* arr = qarg->arr;
	int size = qarg->size;
	
	for(int i = size; i > 1; i--)
	{
		swap(arr[i], arr[1]);
		MaxHeapify(arr, 1, i);
	}
}
// Loop to get Max Heap
// Insert Node Function
void InsertNode(int Arr[], int C, int &Size)
{
	Size = Size + 1;
	Arr[Size] = C;
	Heapify(Arr, Size, Size);
}

void Display(int Arr[], int Size)
{
	for(int i = 1; i <= Size; i++)
	{
		printf("%d ",Arr[i]);
	}
	printf("\n");
}

int main()
{	
	
	FILE *obj;
	obj = fopen("HeapSort.txt", "w");

	int* Arr = (int*)malloc(100000 * sizeof(long));
	int* Arr2 =(int*)malloc(1000001 * sizeof(long));
	int* Arr3 =(int*)malloc(1000001 * sizeof(long));
	int Size = 0;
	int Size2 = 0;
	int Size3 = 0;	
	
	int i = 0;
	for(i = 0; i<100000; i++)
	{	
		int temp = rand() % 1000001;
		InsertNode(Arr, temp , Size);
		InsertNode(Arr2, temp , Size2);
		InsertNode(Arr3, temp , Size3);
	}
	
	ThreadArg args;
	args.arr = Arr;
	args.size = Size;
	
	pthread_t id = 0;
	
	
	start_time = read_timer(); 
    HeapSort(&args);
    end_time = read_timer(); 
	
    printf("\n");
    printf("The execution time of Normal Call was:  %lf secs\n", end_time - start_time);
    free(Arr);
	
	fprintf(obj,"%lf\n",end_time - start_time);
	
	
	//Pthread
	args.arr = Arr2;
	args.size = Size2;
	
	start_time = 0;
	end_time = 0;
	
	start_time = read_timer(); 
	pthread_create(&id, NULL, HeapSort, &args); 
    end_time = read_timer();    
	
	printf("\n");
    printf("The execution time of Pthread Call was:  %lf secs\n", end_time - start_time);
        fprintf(obj,"%lf\n",end_time - start_time);
	free(Arr2);
       

	//segmentation Error
	
	args.arr = Arr3;
	args.size = Size3;
	start_time = 0;
	end_time = 0;
	//OpenMP
	start_time = read_timer(); 
	#pragma omp parallel
	{
	pthread_create(&id, NULL, HeapSort, &args); 
	}
	end_time = read_timer();    
	printf("\n");
    printf("The execution time of OpenMp Call was:  %lf secs\n", end_time - start_time);
        fprintf(obj,"%lf\n",end_time - start_time);
        fclose(obj);
	free(Arr3);
	
	
	
	
}
