#include <iostream>
using namespace std;

void bubbleSort1(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {5,3,8,4,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort1(arr, n);
    printArray(arr, n);

    return 0;
}
