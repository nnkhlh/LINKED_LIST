#include <iostream>
using namespace std;

void selectionSort1(int a[], int n) {
    int vitrimin;
    for (int i = 0; i < n - 1; i++){
        vitrimin = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[vitrimin]) {
                vitrimin = j;
            }
        }
        swap(a[i], a[vitrimin]);
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {-20, 34, -8, 21, 237};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort1(arr, n);
    printArray(arr, n);

    return 0;
}
