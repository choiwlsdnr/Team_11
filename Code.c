#include <stdio.h>
#include <math.h>

int main(void) {
    double a1;
    double r;
    int p, q;
    int N;
    double Sn;
    double S_inf;
    int menu;

    while (1) {
        printf("\n===== 무한 등비급수 프로그램 =====\n");
        printf("1. 무한 등비급수 수렴/발산 판정 및 부분합 계산\n");
        printf("0. 프로그램 종료\n");
        printf("메뉴를 선택하세요: ");

        /* 정수를 제외한 값 입력 시 오류 발생 */
        if (scanf("%d", &menu) != 1) {
            printf("입력 오류입니다.\n");
            return 1;
        }

        if (menu == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        } 
        else if (menu == 1) {
            printf("\n=== 무한 등비급수: Σ a1 * r^(n-1), n = 1, 2, 3, ... ===\n");

            printf("a1(첫째항)을 입력하세요: ");
            if (scanf("%lf", &a1) != 1) {
                printf("a1 입력 오류입니다.\n");
                return 1;
            }

            /* 공비를 분수 형태로만 입력받기 */
            printf("r(공비)를 분수 p/q 형태로 입력하세요 : ");
            if (scanf("%d/%d", &p, &q) != 2) {
                printf("공비는 반드시 a/b 형태의 분수로 입력해야 합니다.\n");
                return 1;
            }
            if (q == 0) {
                printf("분모는 0이 될 수 없습니다.\n");
                return 1;
            }

            r = (double)p / (double)q;

            printf("N(부분합에 사용할 항의 개수)을 입력하세요: ");
            if (scanf("%d", &N) != 1 || N <= 0) {
                printf("N은 양의 정수여야 합니다.\n");
                return 1;
            }

            /* 무한 등비급수 수렴/발산 판정 */
            if (fabs(r) < 1.0) {
                S_inf = a1 / (1.0 - r);
                printf("\n[수렴]\n");
                printf("무한 등비급수는 수렴합니다.\n");
                printf("무한급수의 합 S = %.6f\n", S_inf);
            } else {
                printf("\n[발산]\n");
                printf("무한 등비급수는 발산합니다.\n");
            }

            if (r == 1.0) {
                Sn = a1 * N;
            } else {
                Sn = a1 * (1.0 - pow(r, (double)N)) / (1.0 - r);
            }

            printf("\n[부분합]\n");
            printf("N번째 부분합 S_N = %.6f\n", Sn);

            /* 수렴하는 경우 오차 출력 */
            if (fabs(r) < 1.0) {
                double error = fabs(S_inf - Sn);
                printf("무한급수의 합 S와 S_N의 오차 |S - S_N| = %.6f\n", error);
            }

        } 
        else {
            printf("잘못된 메뉴입니다. 0 또는 1을 입력하세요.\n");
        }
    }

    return 0;
}
