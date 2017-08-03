/* Selection Sort 알고리즘
 * 리스트의 최댓값을 찾아서 앞으로 보내고, 그 값을 제외한 리스트에서 다시 최솟값을 찾아
 * 앞으로 보내는 것을 반복한다. 
 ********************************************************************************/

// include 헤더
#include <stdio.h>
#include <stdlib.h>

// define 매크로

// 함수 선언
int *max_elem_pointer(int list[], int list_len);
void selection_sort(int list[], int list_len);

// Main 함수
int main(int argc, char *argv[])
{
    int list[argc - 1]; // list를 구성한다.
    for (int i = 0; i < argc - 1; i++) {
        list[i] = atoi(argv[i + 1]);
    }

    selection_sort(list, argc - 1); // selection sort를 실행한다.

    for (int *p = list; p < list + (argc - 1); p++) { // sorted list를 출력한다.
        printf("%10d\n", *p);
    }

    return 0;
}

// 함수 정의
/*************************************************************
 max_elem_pointer: list내의 list_len개의 원소들을 비교해 최댓값을 가리키는
                   포인터를 반환한다.
*************************************************************/
int *max_elem_pointer(int list[], int list_len)
{
    int *max = list;
    for (int *p = list; p < list + list_len; p++) {
        if (*max < *p) {
            max = &(*p);
        }
    }

    return max;
}

void selection_sort(int list[], int list_len)
{
    while (list_len != 0) {
        int *max_el_ind = max_elem_pointer(list, list_len);
        int temp = *max_el_ind;
        
        *max_el_ind = *(list + (list_len - 1));
        *(list + (list_len - 1)) = temp;

        list_len--;
    }
}