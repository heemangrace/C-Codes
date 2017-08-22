/* Bidirectional Bubble Sort 알고리즘
 * 리스트를 처음에는 앞에서 뒤 그리고 그 다음 번에는 뒤에서 앞으로 번갈아가면서
 * 훑는다. 물론 기존의 bubble sort와는 이론적으로 동일하다. 
 ************************************************************************/

// include 헤더
#include <stdio.h>
#include <stdbool.h>

// define 매크로

// 함수 선언
void bidir_bubble_sort(int list[], int list_len);

// Main 함수
int main(void)
{
    int list_len; // 리스트의 길이를 정한다.
    printf("Enter number of array elements: "); scanf("%d", &list_len);

    int list[list_len]; // 리스트를 구성한다.
    printf("Enter %d elements with space separated format: ");
    for (int i = 0; i < list_len; i++) {
        scanf(" %d", &list[i]);
    }

    bidir_bubble_sort(list, list_len);

    for (int *p = list; p < list + list_len; p++) {
        printf("%d  ", *p);
    }

    return 0;
}

// 함수 정의
/******************************************************************
 bidir_bubble_sort: list를 정렬한다. swap 을 이용해 리스트를 훑을 때
                    바꿔치기가 일어나지 않았으면 그대로 종료시킨다.
******************************************************************/
void bidir_bubble_sort(int list[], int list_len)
{
    bool forward_dir = true;
    bool swap;
    int *low = list, *high = list + (list_len - 1);

    // 순방향, 역방향 통틀어 (list_len - 1)번의 순회를 관장한다.
    while (low < high) {
        swap = false;
        if (forward_dir) { // 순방향
            for (int *p = low; p < high; p++) {
                if (*p > *(p + 1)) {
                    int temp = *p;
                    *p = *(p + 1);
                    *(p + 1) = temp;
                    swap = true;
                }
            }

            if (!swap) {
                break;
            }
            
            high -= 1;
            forward_dir = false;
        }
        else { // 역방향
            for (int *p = high; p > low; p--) {
                if (*p < *(p - 1)) {
                    int temp = *p;
                    *p = *(p - 1);
                    *(p - 1) = temp;
                    swap = true;
                }
            }       
            
            if (!swap) {
                break;
            }
                
            low += 1;
            forward_dir = true;
        }
    }
}