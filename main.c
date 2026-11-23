#include <stdio.h>

void greet(void);
int e13_2(void);
int temps_summary(int append_log);
void count_marks(int mark, int *high, int *low);
int c13_1(void);
void add_one(int mark, int *total);
int c13_2(void);

/* Menu: 1=E13.1  2=E13.2  3=M13.1/M13.3  4=M13.2  5=C13.1  6=C13.2 */
int main(void)
{
    int choice = 0;

    printf("1 E13.1  2 E13.2  3 M13.1/M13.3  4 M13.2  5 C13.1  6 C13.2\n");
    printf("Choose: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        //E13.1
        greet();
        greet();
        greet();
        greet();
        break;
    case 2:
        return e13_2();
    case 3:
        return temps_summary(0);
    case 4:
        return temps_summary(1);
    case 5:
        return c13_1();
    case 6:
        return c13_2();
    default:
        printf("Invalid choice\n");
        return 1;
    }
    return 0;
}

//E13.1
void greet(void)
{
    static int calls = 0;

    calls = calls + 1;
    printf("Hello %d\n", calls);
}

//E13.2
int e13_2(void)
{
    FILE *outp;
    int n, section = 7;

    printf("Enter N (digits 4 to 7 of your ID): ");
    scanf("%d", &n);

    outp = fopen("id.txt", "w");
    if (outp == NULL) {
        printf("Cannot open id.txt\n");
        return 1;
    }
    fprintf(outp, "%04d\n", n);
    fprintf(outp, "%d\n", section);
    fclose(outp);
    return 0;
}

//M13.1 (append_log = 0), M13.2 (append_log = 1), M13.3 (NULL checks)
int temps_summary(int append_log)
{
    FILE *inp, *outp, *logp;
    double t, total = 0.0, largest = 0.0, average = 0.0;
    int count = 0;

    inp = fopen("temps.txt", "r");
    if (inp == NULL) {                       //M13.3
        printf("Cannot open temps.txt\n");
        return 1;
    }

    while (fscanf(inp, "%lf", &t) != EOF) {  //M13.1
        total = total + t;
        count = count + 1;
        if (count == 1 || t > largest)
            largest = t;
    }
    fclose(inp);

    if (count > 0)
        average = total / count;

    outp = fopen("summary.txt", "w");
    if (outp == NULL) {
        printf("Cannot open summary.txt\n");
        return 1;
    }
    fprintf(outp, "count %d\n", count);
    fprintf(outp, "total %.2f\n", total);
    fprintf(outp, "average %.2f\n", average);
    fprintf(outp, "largest %.2f\n", largest);
    fclose(outp);

    if (append_log) {                        //M13.2
        logp = fopen("log.txt", "a");
        if (logp == NULL) {
            printf("Cannot open log.txt\n");
            return 1;
        }
        fprintf(logp, "count %d total %.2f average %.2f largest %.2f\n",
                count, total, average, largest);
        fclose(logp);
    }

    printf("count %d\ntotal %.2f\naverage %.2f\nlargest %.2f\n",
           count, total, average, largest);
    return 0;
}

//C13.1
void count_marks(int mark, int *high, int *low)
{
    static int hi = 0;
    static int lo = 0;

    if (mark >= 80)
        hi = hi + 1;
    if (mark < 40)
        lo = lo + 1;

    *high = hi;
    *low = lo;
}

int c13_1(void)
{
    FILE *inp;
    int mark, high = 0, low = 0;

    inp = fopen("marks.txt", "r");
    if (inp == NULL) {
        printf("Cannot open marks.txt\n");
        return 1;
    }
    while (fscanf(inp, "%d", &mark) != EOF)
        count_marks(mark, &high, &low);
    fclose(inp);

    printf("80 or above %d\n", high);
    printf("below 40 %d\n", low);
    return 0;
}

//C13.2 (fixed version; the global is replaced by an output parameter)
void add_one(int mark, int *total)
{
    *total = *total + mark;
}

int c13_2(void)
{
    FILE *inp;
    int mark = 0;
    int count = 0;
    int total = 0;

    inp = fopen("marks.txt", "r");
    if (inp == NULL) {
        printf("Cannot open marks.txt\n");
        return 1;
    }

    while (fscanf(inp, "%d", &mark) != EOF) {
        add_one(mark, &total);
        count = count + 1;
    }

    fclose(inp);
    printf("count %d total %d\n", count, total);
    return 0;
}
