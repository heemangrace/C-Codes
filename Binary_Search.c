/* 이분 검색 알고리즘 */

// include 헤더파일
#include <stdio.h>

// define 매크로

// 전역 변수

// 함수 선언
int *binary_search(int *list, int list_len, int target);

// Main 함수
int main(void)
{
    int list_len; // 리스트의 길이를 정한다.
    printf("Enter number of array elements: "); scanf("%d", &list_len);

    int list[list_len]; // 리스트를 구성한다. 
    for (int i = 0; i < list_len; i++) {
        printf("Enter data %d: ", i + 1); scanf("%d", &list[i]);
    }

    int target; // 찾고자 하는 정수를 정한다. 
    printf("Enter number you want to search: "); scanf("%d", &target);

    if (binary_search(list, list_len, target) != NULL) { // 검색 결과를 반환한다.
        printf("Yes! We've found %d located in position %d",
        target, (binary_search(list, list_len, target) - list) + 1);
        return 0;
    }

    printf("Sorry;; No match!"); return 0;

}

// 함수 정의
/**************************************************************
 binary_search: '정렬된!' list와 그 길이 list_len 그리고 찾고자 하는 정수
                'target'을 받아서 'target'이 존재한다면 그 'target'을 가리키는
                포인터를 반환한다. 없으면 NULL을 반환한다.
***************************************************************/
int *binary_search(int list[], int list_len, int target)
{
    int *low = list, *high = list + (list_len - 1); // 시작과 끝 pointer

    if (target < *low || target > *high) { // 리스트에 없는 값: NULL 포인터
        return NULL;
    }

    while ((high - low) > 1) {
        if (target > *(low + ((high - low) / 2))) {
            low += (high - low) / 2;
        }
        else {
            high -= (high - low) / 2;
        }
    }

    return *low == target ? low : high;
}
