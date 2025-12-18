#include <stdio.h>
#include "point.h"

int main() {
    Point3D A, B;

    printf("Введите координаты точки A (x y z): ");
    scanf("%lf %lf %lf", &A.x, &A.y, &A.z);

    printf("Введите координаты точки B (x y z): ");
    scanf("%lf %lf %lf", &B.x, &B.y, &B.z);

    double d = distance(A, B);

    printf("Расстояние между точками A и B: %.2lf\n", d);

    return 0;
}
