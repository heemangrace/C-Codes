/* Insertion Sort 알고리즘
 * i개의 원소가 정렬 됐다면, i+1 번째 원소는 i개 들의 원소들과 비교하여 자기 자리에 
 * 위치 시킨다.
 ********************************************************************************/

// include 헤더
#include <stdio.h>
#include <stdlib.h>

// define 매크로

// 함수 선언
void linear_insertion_sort(int list[], int list_len);
int binary_search(int list[], int list_len, int target);
void binary_insertion_sort(int list[], int list_len);

// Main 함수
int main(int argc, char *argv[]) {

    int list[argc - 1]; // list를 구성한다. 
    for (int i = 0; i < argc - 1; i++) {
        list[i] = atoi(argv[i + 1]);
    }

    binary_insertion_sort(list, argc - 1); // insertion sort를 실행한다.

    for (int *p = list; p < list + (argc - 1); p++) { // sorted list 출력한다.
        printf("%10d\n", *p);
    }
    return 0;
}

// 함수 정의
void linear_insertion_sort(int list[], int list_len)
{
    for (int i = 1; i < list_len; i++) {
        int j;
        for (j = 0; j < i; j++) { // i개의 정렬된 리스트를 훑으며 들어갈 자리를 찾는다.
            if (list[i] < list[j]) {
                break;
            }
        }

        int temp = list[i]; // 찾으면 j번째를 i번째, j+1번째 를 j번째, ... , i번째를 i-1번째로 치환한다.
        for (int k = i; k > j; k--) {
            list[k] = list[k - 1];
        }

        list[j] = temp;
    }
}

/***************************************************************************
 binary_search: '정렬된!' list와 그 길이 list_len 그리고 삽입 하고자 하는 정수
                'target'을 받아서 'target'이 들어가야 할 위치를 가르키는
                인덱스를 반환한다.
***************************************************************************/
int binary_search(int list[], int list_len, int target)
{
    int low = 0, high = list_len - 1; // 시작과 끝 index

    if (target < list[low]) {
        return low;
    }
    else if (target > list[high]) {
        return high + 1;
    }

    while ((high - low) > 1) {
        if (target > list[low + (high - low) / 2]) {
            low += (high - low) / 2;
        }
        else {
            high -= (high - low) / 2;
        }
    }

    return high;
}

void binary_insertion_sort(int list[], int list_len)
{
    for (int i = 1; i < list_len; i++) {
        int j = binary_search(list, i, list[i]); // j는 i개의 원소로 구성된 리스트 중 현재 값 list[i] 가 들어가야 할 index.

        int temp = list[i]; // 찾으면 j번째를 i번째, j+1번째 를 j번째, ... , i번째를 i-1번째로 치환한다.
        for (int k = i; k > j; k--) {
            list[k] = list[k - 1];
        }

        list[j] = temp;

    }
}