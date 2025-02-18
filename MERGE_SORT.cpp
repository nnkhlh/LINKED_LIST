#include <iostream>
using namespace std;

// Hàm trộn (merge) hai mảng con đã được sắp xếp
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    // Copy dữ liệu vào hai mảng tạm
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Hàm đệ quy Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left >= right) return; // Điều kiện dừng đệ quy

    int mid = left + (right - left) / 2; // Tìm phần tử giữa

    mergeSort(arr, left, mid);     // Đệ quy sắp xếp nửa trái
    mergeSort(arr, mid + 1, right); // Đệ quy sắp xếp nửa phải

    merge(arr, left, mid, right); // Gộp hai nửa lại với nhau
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int arr[] = {5, 2, 4, 7, 1, 3, 6, 8};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size - 1);
    printArray(arr, arr_size);

    return 0;
}
