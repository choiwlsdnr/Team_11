#include <stdio.h>
#include <math.h>

int main(void) {
    double a1, r;
    int N;
    double Sn;
    double S_inf;
    const double EPS = 1e-12;  // r가 1과 거의 같은지 판정할 때 사용

    printf("===== 무한 등비급수 수렴/발산 판정 프로그램 =====\n");
    printf("급수: Σ a1 * r^(n-1),  n = 1, 2, 3, ...\n\n");

    printf("a1 (첫째항)을 입력하세요: ");
    if (scanf("%lf", &a1) != 1) {
        printf("입력 오류입니다.\n");
        return 1;
    }

    printf("r (공비)를 입력하세요: ");
    if (scanf("%lf", &r) != 1) {
        printf("입력 오류입니다.\n");
        return 1;
    }

    printf("부분합에 사용할 항의 개수 N을 입력하세요: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("N은 양의 정수여야 합니다.\n");
        return 1;
    }

    /* 1. 수렴/발산 판정 */
    if (fabs(r) < 1.0) {
        printf("\n[수렴 판정]\n");
        printf("|r| = %.4f < 1 이므로 무한 등비급수는 수렴합니다.\n", fabs(r));
        S_inf = a1 / (1.0 - r);
        printf("무한급수의 합 S = a1 / (1 - r) = %.4f\n", S_inf);
    } else if (fabs(r - 1.0) < EPS) {
        printf("\n[발산 판정]\n");
        printf("r ≈ 1 이므로 각 항이 거의 일정하고, 급수는 발산합니다.\n");
    } else {
        printf("\n[발산 판정]\n");
        printf("|r| = %.4f >= 1 이므로 무한 등비급수는 발산합니다.\n", fabs(r));
    }

    /* 2. N번째 부분합 S_N 계산 */
    if (fabs(r - 1.0) < EPS) {
        /* r = 1 인 경우: 모든 항이 a1 이므로 S_N = N * a1 */
        Sn = N * a1;
    } else {
        /* r != 1 인 경우: S_N = a1 * (1 - r^N) / (1 - r) */
        Sn = a1 * (1.0 - pow(r, (double)N)) / (1.0 - r);
    }

    printf("\n[N번째 부분합]\n");
    printf("N = %d 일 때 부분합 S_N = %.4f\n", N, Sn);

    /* 3. 수렴하고 있을 때는 오차도 함께 출력 */
    if (fabs(r) < 1.0) {
        double error = fabs(S_inf - Sn);
        printf("무한급수의 합 S 와 S_N 사이의 오차 |S - S_N| = %.4f\n", error);
    }

    printf("\n프로그램을 종료합니다.\n");
    return 0;
}
