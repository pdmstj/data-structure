#include <stdio.h>
#include <limits.h>

#define SIZE 8
#define M INT_MAX

typedef enum { false, true } bool;

int minVertex(int D[], bool chk[]) {
    int i, minValue = M, minIndex = -1;

    for (i = 0; i < SIZE; i++) {
        if (!chk[i] && D[i] < minValue) {
            minValue = D[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void Dijkstra(int G[][SIZE], int D[], int P[], int start) {
    int i, j, cnt = 0;
    bool chk[SIZE] = { false };

    // 초기화
    D[start] = 0;
    P[start] = start;

    for (j = 0; j < SIZE; j++) {
        if (G[start][j] > 0 && G[start][j] < M) {
            D[j] = G[start][j];
            P[j] = start;
        }
    }
    chk[start] = true;
    cnt++;

    // 다익스트라 알고리즘
    while (cnt < SIZE) {
        i = minVertex(D, chk);
        if (i == -1) break;  // 연결되지 않은 정점 처리

        chk[i] = true;

        for (j = 0; j < SIZE; j++) {
            if (G[i][j] > 0 && G[i][j] < M && !chk[j]) {
                if (D[j] > D[i] + G[i][j]) {  // 더 짧은 경로 확인
                    D[j] = D[i] + G[i][j];
                    P[j] = i;
                }
            }
        }
        cnt++;
    }
}

int main(void) {
    int G[SIZE][SIZE] = { {0, 12, 15, 18, M, M, M, M}, // A의 인접 정보
                          {12, 0, M, M, 33, 26, M, M}, // B의 인접 정보
                          {15, M, 0, 7, M, 10, M, M}, // C의 인접 정보
                          {18, M, 7, 0, M, M, 11, M}, // D의 인접 정보
                          {M, 33, M, M, 0, 17, M, 15}, // E의 인접 정보
                          {M, 26, 10, M, 17, 0, M, 28}, // F의 인접 정보
                          {M, M, M, 11, M, M, 0, 20}, // G의 인접 정보
                          {M, M, M, M, 15, 28, 20, 0} }; // H의 인접 정보
    char V[SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
    char aV, bV;
    int D[SIZE], P[SIZE], i, j;

    printf("출발 정점: ");
    scanf_s(" %c", &aV, sizeof(char));
    printf("도착 정점: ");
    scanf_s(" %c", &bV, sizeof(char));

    // 배열 초기화
    for (i = 0; i < SIZE; i++) {
        D[i] = M;
        P[i] = -1;
    }

    // 출발 정점 인덱스 찾기
    for (i = 0; i < SIZE; i++) {
        if (V[i] == aV) break;
    }
    int start = i;

    // 다익스트라 알고리즘 수행
    Dijkstra(G, D, P, start);

    // 도착 정점 인덱스 찾기
    for (j = 0; j < SIZE; j++) {
        if (V[j] == bV) break;
    }
    int end = j;

    // 결과 출력
    printf("\n%c에서 %c까지 최단거리: %d\n", aV, bV, D[end]);
    printf("최단경로: %c", aV);
    while (end != start) {
        printf(" -> %c", V[end]);
        end = P[end];
    }
    printf("\n");

    return 0;
}
