#include <iostream>
using namespace std;

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int x = a[i];
        int chen = i - 1;
        while (chen >= 0 && x < a[chen]) {
            cout << a[chen + 1] << ' ' << a[chen] << endl;
            a[chen + 1] = a[chen];
            chen--;
        }
         cout << chen + 1 << ' ' << a[chen + 1] << endl;
        a[chen + 1] = x;
    }
}

void insertionSort1(int a[], int n) {
    for(int i = 1; i < n; i++) {
        int x = a[i];
        int chen = i - 1;
        while(chen >= 0 && x < a[chen]) {
            a[chen + 1] = a[chen];
            chen--;
        }
        a[chen + 1] = x;
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {34, -8, 21, 237};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort1(arr, n);
    printArray(arr, n);

    return 0;
}
