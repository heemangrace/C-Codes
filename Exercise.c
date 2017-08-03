// include directives
#include <stdio.h>
#include <stdlib.h>

// 외부 변수
    struct NODE {
        struct NODE *next;
        int data;
    };

// 함수 선언
struct NODE *add_in_list(struct NODE *target, int data);
struct NODE *search_list(struct NODE *list, int n);
int data_input(void);
void delete_in_list(struct NODE *list, int n);

int main(void)
{
    // linked list 구성하기
    struct NODE *head = malloc(sizeof(struct NODE));
    head -> next = NULL;

    int n; // 추가할 노드 개수를 입력받음
    printf("Enter number of nodes to add: ");
    scanf("%d", &n);

    struct NODE *curr = head; // 순회용 포인터를 선언
    int m;
    for (int i = 0; i < n; i++) {
        printf("Enter data: "); 
        scanf("%d", &m);

        curr = add_in_list(curr, m);
    }

    // linked list에서 검색하기
    int l = data_input(); // 검색하고 싶은 자료값 입력을 받음

    search_list(head -> next, l);

    // linked list에서 특정 값 삭제하기
    int k;
    printf("Enter what you want to delete: ");
    scanf("%d", &k);

    delete_in_list(head -> next, k);

    // 최종 linked list 출력
    curr = head -> next;
    while (curr != NULL) {
        printf("%d\n", curr -> data);
        curr = curr -> next;
    }

    // 메모리 해제
    curr = head -> next; // 첫번째 노드의 주소 저장
    while (curr != NULL) {
        struct NODE *next = curr -> next; //임시로 저장
        free(curr); // 메모리 해제
        curr = next;
    }

    free(head); // 머리 노드 메모리 해제

    return 0;


}

// 함수 정의
/**************
 add_in_list: target 포인터가 가리키는 포인터를 반환한다. 
 **************/
struct NODE *add_in_list(struct NODE *target, int data) 
{
    struct NODE *newNode = malloc(sizeof(struct NODE));
    newNode -> next = target -> next;
    newNode -> data = data;

    target -> next = newNode;

    return newNode;
}

/****************************************************
 search_list: 내가 원하는 자료값이 나올 때까지 linked list를 검색하는 함수
 ***************************************************/
struct NODE *search_list(struct NODE *list, int n)
{
    struct NODE *p;

    for (p = list; p != NULL; p = p -> next) {
        if (p -> data == n) {
            printf("Yes! We've found it!\n");
            return p;
        }
    }
    
    printf("Sorry;; nothing found. \n");
    return NULL;
}

 /******************************************************
  data_input: 찾고자 하는 정수를 반환하는 함수
******************************************************/
int data_input(void)
{
    int n;
    printf("Enter number you want to search: ");
    scanf("%d", &n);

    return n;
}

/******************************************************
 delete_in_list: 내가 원하는 값을 linked list에서 삭제한다. 
 *****************************************************/
void delete_in_list(struct NODE *list, int n)
{
    struct NODE *prev, *curr;

    for (prev = list, curr = list -> next; curr != NULL; ) {
        if (curr -> data == n) {
            prev -> next = curr -> next;
            free(curr);
            printf("Delted!\n");
            return;
        }
        prev = prev -> next;
        curr = curr -> next;
    }

    printf("No such data found. Don't fool me motherfucker!\n");
    return;    
}