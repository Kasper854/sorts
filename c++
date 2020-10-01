#include <iostream>
#include <algorithm>
#include <time.h>
#include <random>
#include <cmath>

using namespace std;

void bubbleSort(int* arr, int size)
{   
    int temp = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-i-1; j++)
		{
			if (arr[j]>arr[j+1])
			{

              temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
			}
		}

	}

}
void countSort(int* arr, int size)
{

    int* output = new int[size];
    int maxElem = *max_element(arr, arr + size);
    int* count = new int[maxElem + 1];
    for (int i = 0; i <= maxElem; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }
    for (int i = 1; i <= maxElem; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;

    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }

}

void merge(int* arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* left = new int[n1];
    int* right = new int[n2];


    for (i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }


    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int* arr, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
//void printArr(int* arr, int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        cout << arr[i] << " ";
//    }
//}
int main()
{
	srand(time(NULL));
	double startTime;
	double finishTime;
	int* arr0;
	int* arr1;
    const int minNum = 0;
    const int maxNum = 100000;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(minNum, maxNum);
	int min = 10000;
	int max = 2000000;
	int step = 10000;
	for (min; min <= max; min+=step)
	{
		arr0 = new int[min];
		arr1 = new int[min];
		for (int i = 0; i < min; i++)
		{
			arr0[i]=arr1[i]= distribution(generator);
		}
		startTime = clock();
		bubbleSort(arr0, min);
        //printArr(arr0, min);
		finishTime = clock();
		cout << min << " Elements in bubble sort is finished by " << (finishTime - startTime) / CLOCKS_PER_SEC << " sec" << endl;
        for (int i = 0; i < min; i++)
        {
            arr0[i] = arr1[i];
        }
        startTime = clock();
        mergeSort(arr0, 0, min - 1);
        //printArr(arr0, min);
        finishTime = clock();
        cout << min << " Elements in merge sort is finished by " << (finishTime - startTime) / CLOCKS_PER_SEC << " sec" << endl;;
        for (int i = 0; i < min; i++)
        {
            arr0[i] = arr1[i];
        }
        startTime = clock();
        countSort(arr0, min);
        //printArr(arr0, min);
        finishTime = clock();
        cout << min << " Elements in counting sort is finished by " << (finishTime - startTime) / CLOCKS_PER_SEC << " sec" << endl;
        delete[] arr0;
        delete[] arr1;
	}
	return 0;
