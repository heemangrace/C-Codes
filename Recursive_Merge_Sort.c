/* Merge Sort 알고리즘
 * 하나의 큰 리스트를 iterated bisection (계속된 이등분)을 통해 결국 하나의 원소만으로
 * 이루어진 리스트가 나오도록 한다음 인접한 리스트들 끼리 Merge 시킨다. 
 **********************************************************************************/

// include 헤더
#include <stdio.h>
#include <stdlib.h>

// define 매크로

// 함수 선언
void merge(int list[], int low, int middle, int high);
void merge_sort(int list[], int low, int high);

// Main 함수
int main(void)
{
    int list_len; // 리스트의 길이를 정한다.
    printf("Enter number of array elements: "); scanf("%d", &list_len);

    int list[list_len]; // 리스트를 구성한다.
    printf("Eneter %d elementswith space separated format: ");
    for (int i = 0; i < list_len; i++) {
        scanf(" %d", &list[i]);
    }

    merge_sort(list, 0, list_len - 1); // Merge sort 실행

    for (int *p = list; p < list + list_len; p++) {
        printf("%d ", *p);
    }

    return 0;
}

// 함수 정의
/**********************************************************************
 merge_sort: 
*****************************/
void merge_sort(int list[], int low, int high)
{
    int middle;

    if (low < high) {
    middle = low + (high - low) / 2;
    merge_sort(list, low, middle);
    merge_sort(list, middle + 1, high);

    merge(list, low, middle, high);
    }

}

/**********************************************************************
 merge: low ~ middle, 그리고 middle + 1 ~ high 두 리스트를 병합한다.
**********************************************************************/
void merge(int list[], int low, int middle, int high)
{
    // 값을 저장할 일시적인 리스트를 메모리에 할당한다.
    int *temp = malloc(sizeof(int) * (high - low + 1));

    int left_index = low, right_index = middle + 1, temp_index = 0;

    // 두 리스트를 모두 훑을 때까지 비교를 진행한다.
    while (left_index <= middle && right_index <= high) {
        // 왼쪽 리스트의 값이 오른쪽 리스트 값보다 작은 경우
        if (list[left_index] < list[right_index]) {
            temp[temp_index] = list[left_index];
            left_index++;
        }
        // 오른쪽 리스트의 값이 왼쪽 리스트 값보다 작은 경우
        else {
            temp[temp_index] = list[right_index];
            right_index++;
        }
        temp_index++;
    }

    // 만약 왼쪽 리스트가 남은 경우 뒤에다 다 가져다 붙인다.
    if (right_index > high) {
        for (int i = temp_index; i < (high - low + 1); i++) {
            temp[i] = list[left_index];
            left_index++;
        }
    }
    // 만약 오른쪽 리스트가 남은 경우 뒤에다 다 가져다 붙인다.
    else {
        for (int i = temp_index; i < (high - low + 1); i++) {
            temp[i] = list[right_index];
            right_index++;
        }
    }

    // list에 temp 값 복사
    for (int i = low; i <= high; i++) {
        list[i] = temp[i - low];
    }

    // 메모리 해제
    free(temp);
}