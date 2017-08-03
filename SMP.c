/* Gale-Shapley 알고리즘을 구현한다.
 * 남자와 여자는 모두 0 부터 n-1 까지의 정수로 표현된다. 
 * 만약 남자가 청혼한 여자에게 거절당하면 해당 index를 -1(free)
 * 로 채운다. */

// include 헤더
#include <stdio.h>

// define 매크로

// 함수 선언


// Main 함수
int main(void)
{
    enum {
        free = -1,
    };

    int n = 5; // 짝의 수
    int man_pref[n][n]; // [i][j]: i 번째 남자의 j번째 선호 여자
    int woman_pref[n][n]; // [i][j]: i 번째 여자의 j번째 선호 남자

    int pair_man[n]; // [i]: i 번째 남자와 약혼한 여자
    int pair_woman[n]; // [i]: i 번째 여자와 약혼한 남자

    bool is_married[n]; // [i]: i 번째 남자가 최종 결혼한 경우 true



}

// 함수 정의
void gale_shapley(int man_pref[][], int woman_pref[][], int pair[], int n)
{
    // pair 초기화
    for (int i = 0; i < n; i++) {
        pair_man[i] = free; pair_woman[i] = free;
    }

    while (1) {
        // 짝을 못찾은 남성이 있는지 확인
        int i;
        for (i = 0; i < n; i++) {
            if (!is_married[i]) {
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
            if (man_pref[i][j] != -1) {
                break;
            }
        }

        // man_pref[i][j]의 상태 분석
        if (pair_woman[man_pref[i][j]] == free) {
            pair_man[i] = man_pref[i][j]; // 약혼시킴
            pair_woman[man_pref[i][j]] = i;
            is_married[i] = true;
            man_pref[i][j] = -1;
        }
        else {
            // i 와 pair_woman[man_pref[i][j]] 를 man_pref[i][j]
            // 의 리스트에서 비교
            int k;
            for (k = 0; k < n; k++) {
                if (woman_pref[man_pref[i][j]][k] == i) {
                    is_married[pair_woman[man_pref[i][j]]] = false;
                    
                    pair_man[i] = man_pref[i][j];
                    pair_woman[man_pref[i][j]] = i;
                    break;                    
                }
                if (woman_pref[man_pref[i][j]][k] == pair_woman[man_pref[i][j]]) {
                    
                    break;
                } 
            }

        }
    }

}

