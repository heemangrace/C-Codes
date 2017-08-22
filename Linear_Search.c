/* 선형 검색 알고리즘 */

// include 헤더파일
#include <stdio.h>

// define 매크로

// 전역 변수

// 함수 선언
int max_linear_search(int *list, int list_len);

// Main 함수
int main(void)
{
    int num;
    printf("Enter number of array elements: "); scanf("%d", &num);

    int list[num];
    for (int i = 0; i < num; i++) {
        printf("Enter data %d: ", i + 1); scanf("%d", &list[i]);
    }

    printf("Maximum element is %d", max_linear_search(list, num));

    return 0;
}

// 함수 정의
int max_linear_search(int list[], int list_len)
{
    int *max_element = list;

    for (int *p = list; p < list + list_len; p++) {
        if (*max_element < *p) {
            max_element = p;
        }
    }

    return *max_element;
}