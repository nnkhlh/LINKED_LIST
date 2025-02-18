#include <iostream>
using namespace std;

int partition(int arr[], int left, int right) {
    int pivot = arr[right]; // Chọn pivot là phần tử cuối
    int i = left - 1; // i là vị trí cuối cùng của phần nhỏ hơn pivot

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) { // Nếu phần tử nhỏ hơn pivot
            i++;
            swap(arr[i], arr[j]); // Hoán đổi để đưa vào phần bên trái
        }
    }
    swap(arr[i + 1], arr[right]); // Đưa pivot về đúng vị trí
    return i + 1; // Trả về vị trí của pivot
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right); // Phân hoạch mảng
        quickSort(arr, left, pivotIndex - 1); // Sắp xếp phần trái
        quickSort(arr, pivotIndex + 1, right); // Sắp xếp phần phải
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int arr[] = {8, 4, 3, 7, 6, 5, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}
