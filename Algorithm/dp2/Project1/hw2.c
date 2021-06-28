#include <stdio.h>
#include <time.h>

int input[6] = { 0, };
int arr[1000000] = { 0, };

float time1, time2, time3;

float time4[4][3] = { 0, };
float time5[4][3] = { 0, };

int get_input() {
    FILE* fp;
    int i = 0;
    int buf = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        return 0;
    }

    for (i = 0; i < 6; i++) {
        fscanf(fp, "%d\n", &buf);
        input[i] = buf;
    }
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;

}

void merge(int arr[], int l, int m, int r)
{
    int b[150000];
    int i, j, k;

    for (i = l; i <= r; i++) {
        b[i] = arr[i];
    }

    i = l; j = m + 1; k = l;

    while (i <= m && j <= r) {
        if (b[i] <= b[j]) {
            arr[k++] = b[i++];
        }
        else {
            arr[k++] = b[j++];
        }

    }
    if (i > m)
        while (j <= r) {
            arr[k++] = b[j++];
        }
    else
        while (i <= m) {
            arr[k++] = b[i++];
        }
}

void mergesort(int arr[], int l, int r)
{
    int m;

    if (l < r) {
        m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int l, int r)
{
    int x = arr[l];
    int i = l + 1;
    int j = r;

    while (1) {

        while (arr[i] <= x && i <= r) {
            i++;
        }
        while (arr[j] > x && j >= l) {
            j--;
        }
        if (i < j) swap(&arr[i], &arr[j]);
        else break;
    }
    swap(&arr[l], &arr[j]);
    return j;
}

void quicksort(int arr[], int l, int r)
{
    int p;

    if (l < r) {
        p = partition(arr, l, r);
        quicksort(arr, l, p - 1);
        quicksort(arr, p + 1, r);
    }
}

//

void sorted_num(int num, int arr[]) {
    int i;
    for (i = 0; i < num; i++) {
        arr[i] = i;
    }

}

void random_num(int num, int arr[])
{
    srand(time(NULL));
    int i;
    for (i = 0; i < num; i++) {
        arr[i] = rand();
    }
}

float merge_time(int num, int arr[]) {
    clock_t start, end;
    float time;
    start = clock();
    mergesort(arr, 0, num - 1);
    end = clock();
    time = (float)(end - start) / CLOCKS_PER_SEC;

    return time;
}

float quick_time(int num, int arr[]) {
    clock_t start, end;
    float time;
    start = clock();
    quicksort(arr, 0, num - 1);
    end = clock();
    time = (float)(end - start) / CLOCKS_PER_SEC;

    return time;
}
//

void print_sorted() {

    printf("**Sorted**      N=50000      N=100000      N=150000\n");

    sorted_num(input[0], arr);
    time1 = merge_time(input[0], arr);

    sorted_num(input[1], arr);
    time2 = merge_time(input[1], arr);

    sorted_num(input[2], arr);
    time3 = merge_time(input[2], arr);

    printf(" MergeSort     %f      %f       %f\n", time1, time2, time3);

    sorted_num(input[0], arr);
    time1 = quick_time(input[0], arr);

    sorted_num(input[1], arr);
    time2 = quick_time(input[1], arr);

    sorted_num(input[2], arr);
    time3 = quick_time(input[2], arr);

    printf(" QuickSort     %f      %f     %f\n\n", time1, time2, time3);

}

void print_random() {

    int i = 0;
    for (i = 0; i < 3; i++) {
        random_num(input[3], arr);
        time4[i][0] = merge_time(input[3], arr);

    }
    for (i = 0; i < 3; i++) {
        random_num(input[4], arr);
        time4[i][1] = merge_time(input[4], arr);
    }
    for (i = 0; i < 3; i++) {
        random_num(input[5], arr);
        time4[i][2] = merge_time(input[5], arr);
    }
    for (i = 0; i < 3; i++) {
        time4[3][i] = (time4[0][i] + time4[1][i] + time4[2][i]) / 3;
    }

    for (i = 0; i < 3; i++) {
        random_num(input[3], arr);
        time5[i][0] = quick_time(input[3], arr);
    }
    for (i = 0; i < 3; i++) {
        random_num(input[4], arr);
        time5[i][1] = quick_time(input[4], arr);
    }
    for (i = 0; i < 3; i++) {
        random_num(input[5], arr);
        time5[i][2] = quick_time(input[5], arr);
    }
    for (i = 0; i < 3; i++) {
        time5[3][i] = (time5[0][i] + time5[1][i] + time5[2][i]) / 3;
    }

    printf("**Random**            N=50000        N=100000      N=150000\n");
    printf("Mergesort   data1     %f       %f       %f\n", time4[0][0], time4[0][1], time4[0][2]);
    printf("            data2     %f       %f       %f\n", time4[1][0], time4[1][1], time4[1][2]);
    printf("            data3     %f       %f       %f\n", time4[2][0], time4[2][1], time4[2][2]);
    printf("            average   %f       %f       %f\n\n", time4[3][0], time4[3][1], time4[3][2]);

    printf("Quicksort   data1     %f       %f       %f\n", time5[0][0], time5[0][1], time5[0][2]);
    printf("            data2     %f       %f       %f\n", time5[1][0], time5[1][1], time5[1][2]);
    printf("            data3     %f       %f       %f\n", time5[2][0], time5[2][1], time5[2][2]);
    printf("            average   %f       %f       %f\n\n", time5[3][0], time5[3][1], time5[3][2]);
}

int main() {
    get_input();
    print_sorted();
    print_random();
}