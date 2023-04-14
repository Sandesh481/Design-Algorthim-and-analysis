//code in c
#include <stdio.h>
int a[9] = {65, 70, 75, 80, 85, 60, 55, 50, 45};

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void quicksort(int a[], int low, int high)
{
    int pivot, i, j;
    if (low < high)
    {
        int temp;
        i = low;
        j = high;
        pivot = low;

        while (i < j)
        {
            while ((a[i] <= a[pivot]) && i < high)
                i++;

            while ((a[j] > a[pivot]))
                j--;

            if (i < j)
            { // swap(&a[i], &a[j]);
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                // swap(&a[i], &a[j]);
            }
        }

        // a[m]=a[j];////// ????
        // swap(&a[j], &a[pivot]);
        int temp1;
        temp1 = a[pivot];
        a[pivot] = a[j];
        a[j] = temp1;
        // return j;
        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}

// void quicksort(int a[], int low, int high)
// {
//     int j;
//     if (low < high)
//     {
//         j = partition(a, low, high);
//     }
// }

int main()
{
    quicksort(a, 0, 8);
    int i;
    for (i = 0; i < 9; i++)
        printf("%d\t", a[i]);
    return 0;
}
