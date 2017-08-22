// heap sort 알고리즘을 구현한다.

// include 헤더
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// define 헤더

// 함수 선언
int left(int i);
int right(int i);
void max_heapify(int list[], int list_len, int i);
void build_max_heap(int list[], int list_len);
void heap_sort(int list[], int list_len);

// Main 함수
int main(void)
{
    srand(time(NULL)); // seed값 사용
    
    // 랜덤 리스트를 만듦.
    int list_len; 
    printf("Enter length of list: "); scanf("%d", &list_len);

    int list[list_len];
    for (int i = 0; i < list_len; i++) {
        list[i] = rand();
        printf("%d\n", list[i]);
    }

    // heap_sort 수행
    heap_sort(list, list_len);

    // 결과 출력
    for (int i = 0; i< list_len; i++) {
        printf("%d\n", list[i]);
    }

    return 0;
}

// 함수 정의

// left
// input: 위치 i
// return: 위치 i의 child node 중 왼쪽의 위치
int left(int i)
{
    return 2 * i;
}

// right
// input: 위치 i
// return 위치 i의 child node 중 오른쪽의 위치
int right(int i)
{
    return 2*i + 1;
}

// max_heapify
// input: 리스트 list, 위치 i
// return: 위치 i부터 시작하는 sub-tree를 max_heap property를 만족하게 함.
void max_heapify(int list[], int list_len, int i)
{
    
    int l = left(i), r = right(i); // 왼쪽, 오른쪽 child node를 지칭할 변수 정의
    int largest = i; // child nodes, parent node중 최대값이 담긴 node의 위치

    while (l <= list_len || r <= list_len) {
        int prev_largest = largest;
        // 왼쪽 child가 largest보다 큰 경우
        if (l <= list_len && list[l - 1] > list[largest - 1]) {
            largest = l;
        }
        // 오른쪽 child가 largest보다 큰 경우
        if (r <= list_len && list[r - 1] > list[largest - 1]) {
            largest = r;
        }
        // largest가 바뀐 경우
        if (largest != prev_largest) {
            int temp = list[prev_largest - 1];
            list[prev_largest - 1] = list[largest - 1];
            list[largest - 1] = temp;
            
            // l, r 업데이트
            l = left(largest);
            r = right(largest);
        }
        else {
            break;
        }
    }
}

// build_max_heap
// input: 리스트 list
// return: 리스트의 전체 tree가 max_heap property를 만족하게 함
void build_max_heap(int list[], int list_len)
{
    for (int i = list_len / 2; i >= 1; i--) {
        max_heapify(list, list_len, i);
    }
}

// heap_sort
// input: 리스트 list
// return: heap_sort를 이용해 list를 정렬함
void heap_sort(int list[], int list_len)
{
    // 먼저 전체 tree가 max_heap property를 만족하게 한다.
    build_max_heap(list, list_len);
    
    // 그렇게 되면 맨 위에는 tree에서 가장 큰 원소가 있을 것이기에 이를 맨 아래로 보내고, 그것을 제외한 sub-list에 대해 다시 수행한다. 
    for (int i = list_len; i >= 2; i--) {
        // 맨 아래와 맨 위 원소를 서로 바꿈
        int temp = list[0];
        list[0] = list[i - 1];
        list[i - 1] = temp;
        
        // A[0 : i - 1] 에 대해 max_heapify 수행 
        max_heapify(list, i - 1, 1);
    }
}