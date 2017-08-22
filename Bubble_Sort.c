/* Bubble Sort 알고리즘
 * 한번 list을 순회할때마다 반드시 하나의 원소가 제 위치에 정렬되므로
 * list의 원소개수만큼 순회하면 완료된다.
 ****************************************************************/

// include 헤더
 #include <stdio.h>
 #include <stdbool.h>

// define 매크로

// 함수 선언
void bubble_sort(int list[], int list_len);

// Main 함수
int main(void)
{
    int list_len; // 리스트의 길이를 정한다.
    printf("Enter number of array elements: "); scanf("%d", &list_len);

    int list[list_len]; // 리스트를 구성한다. 
    for (int i = 0; i < list_len; i++) {
        printf("Enter data %d: ", i + 1); scanf("%d", &list[i]);
    }

    bubble_sort(list, list_len); // bubble sort를 실행한다. 

    for (int *p = list; p < list + list_len; p++) { // sorted list 출력한다
        printf("%d ", *p);
    }

    return 0;
}

// 함수 정의
/***********************************************************
 bubble_sort: list를 정렬한다.
***********************************************************/
void bubble_sort(int list[], int list_len)
{
    int p = list_len;
    bool swap;

    for (int *i = list; i < list + list_len; i++) {
        swap = false;
        for (int *j = list; j < list + (p - 1); j++) {
            if (*j > *(j + 1)) {
                int temp = *j;
                *j= *(j + 1);
                *(j + 1) = temp;
                swap = true;
            }
        }

        if (!swap) {
            break;
        }
        
        p--;
    }

}