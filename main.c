#include <stdio.h>

#define MAX_P 30

// ������� ��� ���������� ������� ����� �� p �������
int count_numbers(int p) {
    // ������ ��� ��������� ���������� ���������� �������������
    long long dp[MAX_P + 1][4] = {0};

    // ����� �������
    dp[1][0] = 1; // "5"
    dp[1][1] = 1; // "9"

    // ���������� dp[i] ��� ������� i �� 2 �� p
    for (int i = 2; i <= p; ++i) {
        dp[i][0] = dp[i-1][1] + dp[i-1][3];
        dp[i][1] = dp[i-1][0] + dp[i-1][2];
        dp[i][2] = dp[i-1][0];
        dp[i][3] = dp[i-1][1];
    }

    // ʳ������ ����� ������� p - ���� ��� �������� ������� �����
    return dp[p][0] + dp[p][1] + dp[p][2] + dp[p][3];
}

int main() {
    int p;
    printf("\nEnter kilkist rozryadiv (p <= 30): ");
    scanf("%d", &p);

    // �������� �� ����������� �������� p
    if (p < 1 || p > 30) {
        printf("\nWrong p. It must be 1 <= p <= 30.\n");
        return 1;
    }

    // ���������� �� ��������� ����������
    int result = count_numbers(p);
    printf("\nCount of numbers: %d rozryadiv: %d\n", p, result);

    return 0;
}






