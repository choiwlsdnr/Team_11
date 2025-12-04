/* series.c
 * 무한급수의 수렴/발산을 판정하고
 * 수렴하는 경우 부분합 S_N을 계산하는 예제 프로그램
 *
 * 1) 등비급수: sum_{n=1}^{∞} a1 * r^{n-1}
 * 2) p-급수:   sum_{n=1}^{∞} 1 / n^p
 * 3) 교대 p-급수: sum_{n=1}^{∞} (-1)^{n+1} / n^p
 */

#include <stdio.h>
#include <math.h>

int main(void) {
    int choice;
    int N;              // 부분합에서 더할 항의 개수
    double a1, r;       // 등비급수 첫째항, 공비
    double p;           // p-급수의 지수 p
    double sum = 0.0;   // 부분합 S_N
    int n;

    while (1) {
        printf("===== 무한급수 수렴/발산 판정 프로그램 =====\n");
        printf("1. 등비급수  Σ a1 * r^(n-1)\n");
        printf("2. p-급수    Σ 1 / n^p\n");
        printf("3. 교대 p-급수 Σ (-1)^(n+1) / n^p\n");
        printf("0. 종료\n");
        printf("메뉴를 선택하세요: ");
        if (scanf("%d", &choice) != 1) {
            printf("입력 오류입니다.\n");
            return 1;
        }

        if (choice == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        switch (choice) {
        case 1:
            /* 등비급수: sum_{n=1}^{∞} a1 * r^(n-1) */
            printf("\n[등비급수] Σ a1 * r^(n-1)\n");
            printf("a1 (첫째항)을 입력하세요: ");
            scanf("%lf", &a1);
            printf("r (공비)를 입력하세요: ");
            scanf("%lf", &r);
            printf("부분합에 사용할 항의 개수 N을 입력하세요: ");
            scanf("%d", &N);

            if (fabs(r) < 1.0) {
                double S_inf = a1 / (1.0 - r);
                printf("\n이론적 판정: |r| < 1 이므로 등비급수는 수렴합니다.\n");
                printf("무한급수의 합 S = a1 / (1 - r) = %.10f\n", S_inf);
            } else {
                printf("\n이론적 판정: |r| >= 1 이므로 등비급수는 발산합니다.\n");
            }

            sum = 0.0;
            for (n = 1; n <= N; n++) {
                /* n번째 항: a1 * r^(n-1) */
                sum += a1 * pow(r, n - 1);
            }
            printf("N = %d 일 때 부분합 S_N = %.10f\n\n", N, sum);
            break;

        case 2:
            /* p-급수: sum_{n=1}^{∞} 1 / n^p */
            printf("\n[p-급수] Σ 1 / n^p\n");
            printf("p 값을 입력하세요 (예: 2.0): ");
            scanf("%lf", &p);
            printf("부분합에 사용할 항의 개수 N을 입력하세요: ");
            scanf("%d", &N);

            if (p > 1.0) {
                printf("\n이론적 판정: p > 1 이므로 p-급수는 수렴합니다.\n");
            } else {
                printf("\n이론적 판정: p <= 1 이므로 p-급수는 발산합니다.\n");
            }

            sum = 0.0;
            for (n = 1; n <= N; n++) {
                sum += 1.0 / pow((double)n, p);
            }
            printf("N = %d 일 때 부분합 S_N = %.10f\n\n", N, sum);
            break;

        case 3:
            /* 교대 p-급수: sum_{n=1}^{∞} (-1)^{n+1} / n^p */
            printf("\n[교대 p-급수] Σ (-1)^(n+1) / n^p\n");
            printf("p 값을 입력하세요 (예: 1.0): ");
            scanf("%lf", &p);
            printf("부분합에 사용할 항의 개수 N을 입력하세요: ");
            scanf("%d", &N);

            if (p > 1.0) {
                printf("\n이론적 판정: p > 1 이므로 절대수렴(→ 당연히 수렴)합니다.\n");
            } else if (p > 0.0) {
                printf("\n이론적 판정: 0 < p <= 1 이므로 교대급수 판정에 의해 조건수렴합니다.\n");
            } else {
                printf("\n이론적 판정: p <= 0 이므로 급수는 발산합니다.\n");
            }

            sum = 0.0;
            for (n = 1; n <= N; n++) {
                double term = pow(-1.0, n + 1) / pow((double)n, p);
                sum += term;
            }
            printf("N = %d 일 때 부분합 S_N = %.10f\n\n", N, sum);
            break;

        default:
            printf("잘못된 선택입니다. 0~3 사이의 숫자를 입력하세요.\n\n");
            break;
        }
    }

    return 0;
}
