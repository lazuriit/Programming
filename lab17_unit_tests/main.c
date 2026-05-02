#include <stdio.h>
#include "math.h"

int main() {
    int a = 15;
    int b = 4;

    printf("Числа: a = %d, b = %d\n", a, b);
    printf("Сумма: %d\n", sum(a, b));
    printf("Разность: %d\n", difference(a, b));
    printf("Произведение: %d\n", multiplication(a, b));
    printf("Вещественное деление: %.2f\n", real_division(a, b));
    printf("Остаток от деления: %d\n", remainder_of_division(a, b));

    return 0;
}
