#include <stdio.h>

#define MAX_P 30

// Функція для обчислення кількості чисел із p розрядів
int count_numbers(int p) {
    // Массив для зберігання результатів динамічного програмування
    long long dp[MAX_P + 1][4] = {0};

    // Базові випадки
    dp[1][0] = 1; // "5"
    dp[1][1] = 1; // "9"

    // Обчислюємо dp[i] для кожного i від 2 до p
    for (int i = 2; i <= p; ++i) {
        dp[i][0] = dp[i-1][1] + dp[i-1][3];
        dp[i][1] = dp[i-1][0] + dp[i-1][2];
        dp[i][2] = dp[i-1][0];
        dp[i][3] = dp[i-1][1];
    }

    // Кількість чисел довжини p - сума всіх можливих кінцевих станів
    return dp[p][0] + dp[p][1] + dp[p][2] + dp[p][3];
}

int main() {
    int p;
    printf("\nEnter kilkist rozryadiv (p <= 30): ");
    scanf("%d", &p);

    // Перевірка на допустимість значення p
    if (p < 1 || p > 30) {
        printf("\nWrong p. It must be 1 <= p <= 30.\n");
        return 1;
    }

    // Обчислення та виведення результату
    int result = count_numbers(p);
    printf("\nCount of numbers: %d rozryadiv: %d\n", p, result);

    return 0;
}






