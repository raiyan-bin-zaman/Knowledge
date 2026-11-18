#include <stdio.h>

/* Each section is self-contained: copy one block (from its //tag line to its
   closing brace) into your own main(). Helper functions are nested inside the
   block (GCC extension - works in Code::Blocks/MinGW). Change N to digits 4-7
   of your own student ID wherever it appears. */

int main(void)
{
    //E12.1
    {
        int N = 1234;                      /* CHANGE: your ID digits 4-7 */
        int *p = &N;

        printf("value of N         : %d\n", N);
        printf("address of N       : %p\n", (void *) &N);
        printf("value through *p   : %d\n", *p);
        printf("address of p       : %p\n", (void *) &p);
        *p = *p + 1;                       /* changed through the pointer only */
        printf("N after change     : %d\n\n", N);
    }

    //E12.2
    {
        int N = 1234;                      /* CHANGE: your ID digits 4-7 */
        double h1, h2;

        void half_of(double x, double *resultp)
        {
            *resultp = x / 2.0;
        }

        half_of(N, &h1);
        half_of(7.0, &h2);
        printf("half of %d   = %.2f\n", N, h1);
        printf("half of 7.0 = %.2f\n\n", h2);
    }

    //M12.1
    {
        int N = 1234;                      /* CHANGE: your ID digits 4-7 */
        double area, circ;

        void circle_facts(double r, double *areap, double *circump)
        {
            const double PI = 3.14159;
            *areap = PI * r * r;
            *circump = 2 * PI * r;
        }

        circle_facts(2.0, &area, &circ);
        printf("r = 2.00: area = %.2f, circumference = %.2f\n", area, circ);
        circle_facts(N / 1000.0, &area, &circ);
        printf("r = %.3f: area = %.2f, circumference = %.2f\n\n", N / 1000.0, area, circ);
    }

    //M12.2
    {
        double mark = 71.0;

        void add_bonus(double *markp)
        {
            *markp = *markp + 5.0;
        }

        add_bonus(&mark);
        printf("%.1f\n\n", mark);
    }

    //M12.3
    {
        int num = 0;

        void read_positive(int *np)
        {
            int c;

            do {
                printf("Enter a number greater than zero: ");
                if (scanf("%d", np) != 1) {
                    *np = 0;               /* bad input: ask again */
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    if (c == EOF)
                        return;
                }
            } while (*np <= 0);
        }

        read_positive(&num);
        printf("You entered %d\n\n", num);
    }

    //C12.1
    {
        double n1 = 7.5, n2 = 9.6, n3 = 5.5;

        void order(double *smp, double *lgp)
        {
            double t;

            if (*smp > *lgp) {
                t = *smp;
                *smp = *lgp;
                *lgp = t;
            }
        }

        printf("start       : %.1f %.1f %.1f\n", n1, n2, n3);
        order(&n1, &n2);
        printf("order(n1,n2): %.1f %.1f %.1f\n", n1, n2, n3);
        order(&n1, &n3);
        printf("order(n1,n3): %.1f %.1f %.1f\n", n1, n2, n3);
        order(&n2, &n3);
        printf("order(n2,n3): %.1f %.1f %.1f\n\n", n1, n2, n3);
    }

    //C12.2 (all four defects fixed)
    {
        double cgpa = 3.21;
        int marks = 0;
        double hall = 0.0, tuition = 0.0;

        void bump_cgpa(double *cgpap)
        {
            *cgpap = *cgpap + 0.10;
        }

        void read_marks(int *markp)
        {
            *markp = 88;
        }

        void split_fee(double fee, double *hallp, double *tuitionp)
        {
            *hallp = fee * 0.30;
            *tuitionp = fee * 0.70;
        }

        bump_cgpa(&cgpa);
        printf("cgpa %.2f\n", cgpa);

        read_marks(&marks);
        printf("marks %d\n", marks);

        split_fee(45000.0, &hall, &tuition);
        printf("hall %.2f\n", hall);

        printf("address %p\n", (void *) &marks);
    }

    return 0;
}
