#include <stdio.h>

void g14_1(void);  void e14_1(void);  void e14_2(void);
void m14_1(void);  void m14_2(void);  void m14_3(void);
void c14_1(void);  void c14_2(void);

void read_marks(int a[], int n);
double average(const int a[], int n);
void report(const int a[], int n);
void bump(int *cellp);
int doubled(int value);
void print_array(const int a[], int n);
int total(const int a[], int n);

int main(void)
{
    int choice;

    printf("1 G14.1  2 E14.1  3 E14.2  4 M14.1\n");
    printf("5 M14.2  6 M14.3  7 C14.1  8 C14.2\n");
    printf("Choose: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: g14_1(); break;
    case 2: e14_1(); break;
    case 3: e14_2(); break;
    case 4: m14_1(); break;
    case 5: m14_2(); break;
    case 6: m14_3(); break;
    case 7: c14_1(); break;
    case 8: c14_2(); break;
    default: printf("No such task\n");
    }
    return 0;
}

//G14.1
#define SIZE 6
void g14_1(void)
{
    int marks[SIZE];
    int i, small;

    printf("Enter %d marks: ", SIZE);
    for (i = 0; i < SIZE; i++)
        scanf("%d", &marks[i]);

    small = marks[0];
    for (i = 1; i < SIZE; i++)
        if (marks[i] < small) small = marks[i];
    printf("smallest %d\n", small);
}
#undef SIZE

//E14.1
#define SIZE 6
void e14_1(void)
{
    int a[SIZE];
    int i;

    printf("Enter %d integers: ", SIZE);
    for (i = 0; i < SIZE; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < SIZE; i++)
        printf("%d ", a[i]);
    printf("\n");

    for (i = SIZE - 1; i >= 0; i--)
        printf("%d ", a[i]);
    printf("\n");
}
#undef SIZE

//E14.2
#define SIZE 4
void e14_2(void)
{
    int digit[SIZE];
    int n, i, sum = 0;

    printf("Enter your N (digits 4 to 7 of your ID): ");
    scanf("%d", &n);

    for (i = SIZE - 1; i >= 0; i--) {
        digit[i] = n % 10;
        n = n / 10;
    }

    for (i = 0; i < SIZE; i++) {
        printf("%d ", digit[i]);
        sum = sum + digit[i];
    }
    printf("\nsum of digits %d\n", sum);
}
#undef SIZE

//M14.1
/* Two passes: the average is unknown until every mark has been read,
   so the marks must be kept to compare against it afterwards. */
#define SIZE 8
void m14_1(void)
{
    int marks[SIZE];
    int i, sum = 0;
    double avg;

    printf("Enter %d marks: ", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &marks[i]);
        sum = sum + marks[i];
    }
    avg = (double) sum / SIZE;
    printf("average %.2f\n", avg);

    for (i = 0; i < SIZE; i++) {
        if (marks[i] > avg)
            printf("%d ABOVE\n", marks[i]);
        else
            printf("%d BELOW\n", marks[i]);
    }
}

//M14.2
void m14_2(void)
{
    int marks[SIZE];

    read_marks(marks, SIZE);
    report(marks, SIZE);
}
#undef SIZE

void read_marks(int a[], int n)
{
    int i;

    printf("Enter %d marks: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

double average(const int a[], int n)
{
    int i, s = 0;

    for (i = 0; i < n; i++)
        s = s + a[i];
    return (double) s / n;
}

void report(const int a[], int n)
{
    int i;
    double avg = average(a, n);

    printf("average %.2f\n", avg);
    for (i = 0; i < n; i++) {
        if (a[i] > avg)
            printf("%d ABOVE\n", a[i]);
        else
            printf("%d BELOW\n", a[i]);
    }
}

//M14.3
/* sizeof is fixed at compile time: it is the capacity, not the count. */
#define SIZE 20
void m14_3(void)
{
    int marks[SIZE];
    int count = 0, value, i, sum = 0;

    printf("Enter marks (negative to stop, max %d): ", SIZE);
    while (count < SIZE && scanf("%d", &value) == 1 && value >= 0) {
        marks[count] = value;
        count++;
    }

    for (i = 0; i < count; i++)
        sum = sum + marks[i];

    printf("count %d\n", count);
    if (count > 0)
        printf("average %.2f\n", (double) sum / count);
    else
        printf("average undefined (no marks)\n");
    printf("sizeof array %d bytes\n", (int) sizeof(marks));
}
#undef SIZE

//C14.1
/* bump got the address of the cell, so *cellp is the caller's cell.
   doubled got a copy of the value, so the cell is untouched. */
#define SIZE 5
void bump(int *cellp)
{
    *cellp = *cellp + 1;
}

int doubled(int value)
{
    return 2 * value;
}

void print_array(const int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void c14_1(void)
{
    int a[SIZE] = {10, 20, 30, 40, 50};

    printf("start: ");
    print_array(a, SIZE);

    bump(&a[2]);
    printf("after bump(&a[2]): ");
    print_array(a, SIZE);

    printf("doubled(a[2]) returns %d\n", doubled(a[2]));
    printf("after doubled(a[2]): ");
    print_array(a, SIZE);
}
#undef SIZE

//C14.2
/* Faults fixed: total(values) -> total(values, SIZE) [build stopped];
   loop 1..SIZE -> 0..SIZE-1 [nothing]; a[0] = 0 removed [nothing];
   const added to the parameter [would stop the build if a[0] = 0 stayed]. */
#define SIZE 5
int total(const int a[], int n)
{
    int i, s = 0;

    for (i = 0; i < n; i++)
        s = s + a[i];
    return s;
}

void c14_2(void)
{
    int values[SIZE] = {10, 20, 30, 40, 50};
    int i;

    for (i = 0; i < SIZE; i++)
        printf("%d ", values[i]);
    printf("\n");

    printf("total %d\n", total(values, SIZE));
}
#undef SIZE
