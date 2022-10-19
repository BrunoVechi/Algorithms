#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void swap(long *a, long *b)
{
    long t = *a;
    *a = *b;
    *b = t;
}
//----------------BubbleSort--------------------
void BubbleSort(long arr[], long n)
{
    long i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
//----------------BubbleSort--------------------

//----------------InsertionSort-----------------
void InsertionSort(long *arr, long size)
{
    long key, j;
    for (long i = 1; i < size; i++)
    {
        key = arr[i];
        j = i;
        while (j > 0 && arr[j - 1] > key)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}
//----------------InsertionSort-----------------

//----------------SelectionSort-----------------
void SelectionSort(long *vetor, long max)
{
    long i, j, min, aux;

    for (i = 0; i < (max - 1); i++)
    {

        min = i;
        for (j = i + 1; j < max; j++)
        {

            if (vetor[j] < vetor[min])
            {
                min = j;
            }
        }

        if (i != min)
        {
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }
}
//----------------SelectionSort-----------------

//----------------QuickSort---------------------
long partition(long array[], long low, long high)
{

    long pivot = array[high];

    long i = (low - 1);

    for (long j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);

    return (i + 1);
}
void quickSort(long array[], long low, long high)
{
    if (low < high)
    {
        long pi = partition(array, low, high);

        quickSort(array, low, pi - 1);

        quickSort(array, pi + 1, high);
    }
}
//----------------QuickSort---------------------

//----------------BinarySearch------------------
long BinarySearch(long arr[], long l, long r, long x)
{
    if (r >= l)
    {
        long mid = l + (r - l) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }

        if (arr[mid] > x)
        {
            return BinarySearch(arr, l, mid - 1, x);
        }
        else
        {
            return BinarySearch(arr, mid + 1, r, x);
        }
    }
    return -1;
}
//----------------BinarySearch------------------

//----------------LinearSearch------------------
long LinearSearch(long arr[], long qtd, long x)
{
    long r = 0;
    while (r <= qtd)
    {
        if (arr[r] == x)
        {
            return r;
        }
        else
        {
            r++;
        }
    }
    return -1;
}
//----------------LinearSearch------------------

//----------------Random------------------------
void Random(long *arr, long qtd)
{
    for (long i = 0; i <= qtd; i++)
    {
        arr[i] = rand() % (qtd + 1);
    }
}
//----------------Random------------------------

long main()
{
    long optO = 0, optS = 0, loop = 1, seachResult = -1;

    while (loop == 1)
    {
        long qtd = 0;
        long find = 0;

        double timeSort = 0.0;
        double timeSearch = 0.0;

        printf("Quantidade de numeros aleatorios: ");
        scanf("%d", &qtd);

        long arr[qtd];

        printf("Gerando numeros...\n");
        Random(arr, qtd);

        printf("Escolha um algoritimo de Ordenacao:");
        printf("(1)Bubble Sort   (2)Insertion Sort   (3)Selection Sort   (4)Quick Sort\n");
        scanf("%d", &optO);

        printf("Escolha um algoritimo de Busca:");
        printf("(1)Binary Search   (2)Linear Search\n");
        scanf("%d", &optS);

        printf("Numero a ser pesquisado: ");
        scanf("%d", &find);

        printf("Ordenando numeros...\n");
        clock_t beginSort = clock();
        switch (optO)
        {
        case 1:
            BubbleSort(arr, qtd);
        case 2:
            InsertionSort(arr, qtd);
        case 3:
            SelectionSort(arr, qtd);
        case 4:
            quickSort(arr, 0, qtd);
        }
        clock_t endSort = clock();
        timeSort += (double)(endSort - beginSort) / CLOCKS_PER_SEC;

        printf("Pesquisando numeros...\n");
        clock_t beginSearch = clock();
        switch (optS)
        {
        case 1:

            seachResult = BinarySearch(arr, 0, qtd, find);

        case 2:
            seachResult = LinearSearch(arr, qtd, find);
        }
        clock_t endSearch = clock();
        timeSearch += (double)(endSearch - beginSearch) / CLOCKS_PER_SEC;

        if (seachResult < 0)
            printf("\nNumero %d encontrado nao encontrado!\n");
        else
            printf("\nNumero %d encontrado na posicao %d!\n", find, seachResult);
        printf("Tempo de ordenacao: %f segundos\n", timeSort);
        printf("Tempo de busca: %f segundos\n", timeSearch);
        printf("Tempo TOTAL: %f segundos\n\n", timeSearch + timeSort);

        getchar();
    }

    return 0;
}
