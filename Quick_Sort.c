/* Quick Sort 알고리즘 */

// include 헤더
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define 매크로

// 함수 선언

// Main 함수
int main(void)
{
    int list_len;
    printf("Enter number of array elements: "); scanf("%d", &list_len);

    int list[list_len];

    srand(time(NULL));
    for (int i = 0; i < list_len; i++) {
        list[i] = rand();
    }

    quicksort(list, 0, list_len -1);

    for (int *p = list; p < list + list_len; p++) {
        printf("%d\n", *p);
    }

    return 0;
}

// 함수 정의
void quick_sort(int list[], int low, int high) 
{
    int middle;

    if (low >= high) {
        return;
    }
    
    middle = split(list, low, high);
    quick_sort(list, low, middle) - 1;
    quick_sort(list, middle + 1, high);
}

/********************************************************************
 split: list[low]의 원래 위치를 찾아준다.
********************************************************************/
int split(int a[], int low, int high)
{
    int part_element = a[low]; // Step 1.

    while (1) {
        while (low < high && part_element <= a[high]) { // Move 'high' to left if the current 'a[high]' is larger.
            high--;
        }
        if (low >= high) {
            break;
        }
        a[low++] = a[high]; // Put temporary value to a[low].

        while (low < high && a[low] <= part_element) { // Same algorithm for 'low'.
            low ++;
        }
        if (low >= high) {
            break;
        }
        a[high--] = a[low];
    }

    a[low]  = part_element;
    return high; // low or high: irrelevant
}