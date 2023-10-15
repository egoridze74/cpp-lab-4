#include <stdio.h>

int main()
{
    unsigned int n, l = 0, k;
    unsigned long sum_gramms, p;
    printf("Insert number of bowls:\n");
    scanf_s("%d", &n);
    sum_gramms = n*(n+1) / 2;
    if (sum_gramms % 2 != 0) //сумма арифметической прогресии (сумма граммов супа)
        printf("NO");
    else {
        printf("YES\n");
        const unsigned long half_sum = sum_gramms / 2;
        p = half_sum; //половина суммы граммов (студентов двое, так что каждому достанется по половине граммов супа)
        /* подсчитаем количество чашек для Пети,
            отнимая из его половины граммов самую большую возможную миску */
        for (unsigned int i = n; i > 0; i--) {
            if (i <= p) {
                l++;
                p -= i;
            }
        }
        k = n - l; //количество мисок для Маши
        printf("%d\n", l);
        p = half_sum;
        /* посчитаем порции для Пети, беря самую большую возможную порцию,
          которая будет меньше суммы граммов супа Пети */
        for (unsigned int i = n; i > 0; i--) {
            if (i <= p) {
                printf("%d ", i);
                p -= i;
            }
        }
        printf("\n%d\n", k);
        p = half_sum;
        for (unsigned int i = n; i > 0; i--) { //посчитаем порции для Маши, беря невошедшие в сумму Пети миски
            if (i <= p)
                p -= i;
            else
                printf("%d ", i);
        }
    }
    return 0;
}
