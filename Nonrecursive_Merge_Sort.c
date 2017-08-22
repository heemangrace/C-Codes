/* Merge Sort 알고리즘 (재귀를 이용하지 않는 경우) */

// include 헤더
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define 매크로

// 함수 선언
void merge(int list[], int low, int middle, int high);
void merge_sort(int list[], int list_len);

// Main 함수
int main(void)
{
    int list_len;
    printf("Enter number of array elements: "); scanf("%d", &list_len);

    int list[list_len];
    
    srand(time(NULL));
    for (int i = 0; i < list_len; i++) {
        list[i] = list_len - i;
    }
    // int list_len; // 리스트의 길이를 정한다.
    // printf("Enter number of array elements: "); scanf("%d", &list_len);

    // int list[list_len]; // 리스트를 구성한다.
    // printf("Eneter %d elementswith space separated format: ");
    // for (int i = 0; i < list_len; i++) {
    //     scanf(" %d", &list[i]);
    // }

    merge_sort(list, list_len);


    for (int *p = list; p < list + list_len; p++) {
        printf("%d\n", *p);
    }

    return 0;
}

// 함수 정의
/**************************************************************************
 merge_sort: 
**************************************************************************/
void merge_sort(int list[], int list_len)
{
    if (list_len == 1) {
        return;
    }

    // 인접한 배열 2개씩 짝지어 정렬시킨다. 
    for (int i = 0; i < list_len / 2; i++) {
        if (list[2 *i] > list[2*i + 1]) {
            int temp = list[2 *i];
            list[2 *i] = list[2*i + 1];
            list[2*i + 1] = temp;
        }
    }

    // step 만큼 이루어진 sublist 들로 쪼개고 (남는 것은 그냥 그것들 끼리 리스트)
    // 그 리스트 들을 합치는 것 까지 관장한다.
    int step, i;
    for (step = 2; ; ) {
        for (i = 0; i < list_len / (2 * step); i++) {
            merge(list, i * (2 * step), i * (2 * step) + step - 1, i * (2 * step) + 2*step - 1);
        }

        merge(list, i * (2 * step) , i * (2 * step) + step - 1 , list_len - 1);
        
        // 만약 step 값이 리스트 길이보다 커질 경우 그전에 종료시킨다.
        if ((2 * step) >= list_len) {
            break;
        }
        else {
            step *= 2;
        }
    }

    // 자투리 리스트를 병합시킨다.
    merge(list, 0, step - 1, list_len - 1);    
}

void merge(int list[], int low, int middle, int high)
{
    // 값을 저장할 일시적인 리스트를 메모리에 할당한다.
    int temp[high - low + 1];

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
}