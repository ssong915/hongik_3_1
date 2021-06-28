#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;
int s_ndata[3];
int r_ndata[3];
double s_time[2][3];
double q_time[3][3];
double m_time[3][3];
void quicksort(int* arr, int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[left];
    do {
        while (arr[i] < pivot) {
            i++;
        } while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            i++; j--;
        }
    } while (i <= j);
    if (left < j) {
        quicksort(arr, left, j);
    } if (i < right) {
        quicksort(arr, i, right);
    }
}

void merge(int* arr, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;
    int* temp = new int[high + 1];
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i];
    }
    delete[] temp;
}
void mergesort(int* arr, int m, int n) {
    if (m < n) {
        int middle = (m + n) / 2;
        mergesort(arr, m, middle);
        mergesort(arr, middle + 1, n);
        merge(arr, m, middle, n);
    }
}
int main() {
    ifstream fin;
    fin.open("input.txt");
    int n;
    for (int i = 0; i < 3; i++) {
        fin >> n;
        s_ndata[i] = n;
        int* q_arr = new int[n];
        int* m_arr = new int[n];
        for (int j = 0; j < n; j++) {
            q_arr[j] = m_arr[j] = j;
        }
        clock_t t1 = clock();
        mergesort(m_arr, 0, n - 1);
        t1 = clock() - t1;
        s_time[0][i] = (double)t1 / CLOCKS_PER_SEC;
        clock_t t2 = clock();
        quicksort(q_arr, 0, n - 1);
        t2 = clock() - t2;
        s_time[1][i] = (double)t2 / CLOCKS_PER_SEC;
    }
    for (int i = 0; i < 3; i++) {
        fin >> n;
        r_ndata[i] = n;
        for (int k = 0; k < 3; k++) {
            int* q_arr = new int[n];
            int* m_arr = new int[n];
            for (int j = 0; j < n; j++) {
                q_arr[j] = m_arr[j] = j;
            }
            clock_t t1 = clock();
            mergesort(m_arr, 0, n - 1);
            t1 = clock() - t1;
            m_time[0][k] = (double)t1 / CLOCKS_PER_SEC;
            clock_t t2 = clock();
            quicksort(q_arr, 0, n - 1);
            t2 = clock() - t2;
            s_time[1][k] = (double)t2 / CLOCKS_PER_SEC;
        }
    }
    cout << "  sorted  " << "   " << s_ndata[0] << "   " << s_ndata[1] << "   " << s_ndata[2] << "\n";
    cout << "Merge Sort" << "   " << s_time[0][0] << "   " << s_time[0][1] << "   " << s_time[0][2] << "\n";
    cout << "Quick Sort" << "   " << s_time[1][0] << "   " << s_time[1][1] << "   " << s_time[1][2] << "\n";

    cout << "  random  " << "      " << r_ndata[0] << "   " << r_ndata[1] << "   " << r_ndata[2] << "\n";
    cout << "Merge Sort" << "data1" << m_time[0][0] << "   " << m_time[1][0] << "   " << m_time[2][0] << "\n";
    cout << "Merge Sort" << "data2" << m_time[0][1] << "   " << m_time[1][1] << "   " << m_time[2][1] << "\n";
    cout << "Merge Sort" << "data3" << m_time[0][2] << "   " << m_time[1][2] << "   " << m_time[2][2] << "\n";
    cout << "Quick Sort" << "data1" << q_time[0][0] << "   " << q_time[1][0] << "   " << q_time[2][0] << "\n";
    cout << "Quick Sort" << "data2" << q_time[0][1] << "   " << q_time[1][1] << "   " << q_time[2][1] << "\n";
    cout << "Quick Sort" << "data3" << q_time[0][2] << "   " << q_time[1][2] << "   " << q_time[2][2] << "\n";
    fin.close();
    return 0;

}