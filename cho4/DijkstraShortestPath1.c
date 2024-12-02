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

    // �ʱ�ȭ
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

    // ���ͽ�Ʈ�� �˰���
    while (cnt < SIZE) {
        i = minVertex(D, chk);
        if (i == -1) break;  // ������� ���� ���� ó��

        chk[i] = true;

        for (j = 0; j < SIZE; j++) {
            if (G[i][j] > 0 && G[i][j] < M && !chk[j]) {
                if (D[j] > D[i] + G[i][j]) {  // �� ª�� ��� Ȯ��
                    D[j] = D[i] + G[i][j];
                    P[j] = i;
                }
            }
        }
        cnt++;
    }
}

int main(void) {
    int G[SIZE][SIZE] = { {0, 12, 15, 18, M, M, M, M}, // A�� ���� ����
                          {12, 0, M, M, 33, 26, M, M}, // B�� ���� ����
                          {15, M, 0, 7, M, 10, M, M}, // C�� ���� ����
                          {18, M, 7, 0, M, M, 11, M}, // D�� ���� ����
                          {M, 33, M, M, 0, 17, M, 15}, // E�� ���� ����
                          {M, 26, 10, M, 17, 0, M, 28}, // F�� ���� ����
                          {M, M, M, 11, M, M, 0, 20}, // G�� ���� ����
                          {M, M, M, M, 15, 28, 20, 0} }; // H�� ���� ����
    char V[SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
    char aV, bV;
    int D[SIZE], P[SIZE], i, j;

    printf("��� ����: ");
    scanf_s(" %c", &aV, sizeof(char));
    printf("���� ����: ");
    scanf_s(" %c", &bV, sizeof(char));

    // �迭 �ʱ�ȭ
    for (i = 0; i < SIZE; i++) {
        D[i] = M;
        P[i] = -1;
    }

    // ��� ���� �ε��� ã��
    for (i = 0; i < SIZE; i++) {
        if (V[i] == aV) break;
    }
    int start = i;

    // ���ͽ�Ʈ�� �˰��� ����
    Dijkstra(G, D, P, start);

    // ���� ���� �ε��� ã��
    for (j = 0; j < SIZE; j++) {
        if (V[j] == bV) break;
    }
    int end = j;

    // ��� ���
    printf("\n%c���� %c���� �ִܰŸ�: %d\n", aV, bV, D[end]);
    printf("�ִܰ��: %c", aV);
    while (end != start) {
        printf(" -> %c", V[end]);
        end = P[end];
    }
    printf("\n");

    return 0;
}
