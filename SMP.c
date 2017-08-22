/* Gale-Shapley 알고리즘을 구현한다.
 * 남자와 여자는 모두 0 부터 n-1 까지의 정수로 표현된다.
 * 만약 남자가 청혼한 여자에게 거절당하면 해당 index를 -1(free)
 * 로 채운다. */

// include 헤더
#include <stdio.h>
#include <stdbool.h>

// define 매크로

// 외부 변수
    enum {
        free = -1,


    };

// 함수 선언
int index_finder(int n, int list[n], int i);
void gale_shapley(int n, int man_pref[][n], int woman_pref[][n], int pair_man[n], int pair_woman[n], bool is_man_married[n]);

// Main 함수
int main(void)
{


    int n = 4; // 짝의 수
    int man_pref[n][n]; // [i][j]: i 번째 남자의 j번째 선호 여자
    int woman_pref[n][n]; // [i][j]: i 번째 여자의 j번째 선호 남자

    int pair_man[n]; // [i]: i 번째 남자와 약혼한 여자
    int pair_woman[n]; // [i]: i 번째 여자와 약혼한 남자

    bool is_man_married[n]; // [i]: i 번째 남자가 최종 결혼한 경우 true


    for (int i = 0; i < n; i++) {
        printf("Enter preference list of man %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            int k;
            scanf("%d", &k);
            man_pref[i][j] = k - 1;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("Enter preference list of woman %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            int k;
            scanf("%d", &k);
            woman_pref[i][j] = k - 1;
        }
    }

    gale_shapley(n, man_pref, woman_pref, pair_man, pair_woman, is_man_married);

    printf("Man        Woman\n");
    for (int i = 0; i < n; i++) {
        printf("%3d       %3d\n", i + 1, pair_man[i] + 1);
    }

    return 0;
}

// 함수 정의
void gale_shapley(int n, int man_pref[][n], int woman_pref[][n], int pair_man[n], int pair_woman[n], bool is_man_married[n])
{
    // pair 초기화
    for (int i = 0; i < n; i++) {
        pair_man[i] = free; pair_woman[i] = free; is_man_married[i] = false;
    }

    while (1) {
        // 짝을 못찾은 남성이 있는지 확인
        int i;
        for (i = 0; i < n; i++) {
            if (!is_man_married[i]) {
                break;
            }
        }
        if (i == n) {
            break;
        }
        /* i번째 남성이 짝을 못찾았을 경우 */
        // i번째 남성이 청혼하지 않은 여자들 중 가장 상위에 있는 여자 검색
        int j;
        for (j = 0; j < n; j++) {
            if (man_pref[i][j] != free) {
                break;
            }
        }

        int curr_fiance = pair_woman[man_pref[i][j]];

        // man_pref[i][j] (여자) 의 상태 분석
        if (man_pref[i][j] == free) { // man_pref[i][j] 가 현재 약혼하지 않은 경우
            pair_man[i] = man_pref[i][j]; // 약혼시킴
            pair_woman[man_pref[i][j]] = i;
            is_man_married[i] = true;
            man_pref[i][j] = free;
        }
        else {
            /* i 와 curr_fiance (현재 약혼자) 를 man_pref[i][j]의 리스트에서 비교 */
            // 만약 i가 리스트에 먼저 나오는 경우
            if (index_finder(n, woman_pref[man_pref[i][j]], i) < index_finder(n, woman_pref[man_pref[i][j]], curr_fiance)) {
                pair_man[i] = man_pref[i][j]; // i를 man_pref[i][j] 와 약혼시킴
                pair_woman[man_pref[i][j]] = i;
                is_man_married[i] = true;
                is_man_married[curr_fiance] = false; // 기존 약혼자 curr_fiance 를 파혼시킴
                man_pref[curr_fiance][index_finder(n, man_pref[curr_fiance], man_pref[i][j])] = free; // 기존 약혼자 curr_fiance 의 man_pref 리스트에서 여자 삭제
            }
            // 반대로 기존 약혼자가 i보다 우선순위에 있는 경우
            else {
                man_pref[i][j] = free; // 청혼한 여자를 리스트에서 삭제
            }
        }
    }

}

/***********************************************************************************
 index_finder: 길이 n인 1차원 리스트에서 i라는 원소가 존재하면 그 i라는 원소가 존재하는
               곳의 index를 return, 만약 그 원소가
************************************************************************************/
int index_finder(int n, int list[n], int i)
{
    int j;
    for (j = 0; j < n; j++) {
        if (list[j] == i) {
            return j;
        }
    }
    return -1;
}
