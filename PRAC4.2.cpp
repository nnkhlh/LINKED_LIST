#include <iostream>

using namespace std;

void bubbleSort(int a[], int n);
void selectionSort(int a[], int n);
void insertionSort(int a[], int n);
void mergeSort(int a[], int n);
void quickSort(int a[], int n);
void printArray(int arr[], int n);

/*void bubbleSort(int a[], int n){
    bool check = false;
    int i = n - 1;
    while(i > 0 && !check){
        check = false;
        for (int j = 0; j < i; j++){
            if(a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                check = true;
            }
        }
        i--;
    }
}*/
void bubbleSort(int *a, int n) {
    for (bool isswap = true; isswap; --n) {
        isswap = false;
        for (int i = 0; i < n - 1; i++) {
            if(a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                isswap = true;
            }
        }
    }
}
void comb_sort(int *a, int n){
    int gap = n;
    float ratio = 1.3f;

    for (bool isswap = true; isswap; ) {
        gap /= ratio;
        if (gap < 1) {
            gap = 1;
            isswap = false;
        } else if(gap == 9 || gap == 10) {
            gap = 11;
        }
        for (int i = 0; i + gap < n; i++) {
            if(a[i] > a[i + gap]) {
                swap(a[i], a[i + gap]);
                isswap = true;
            }
        }

    }
}

void selectionSort(int *a, int n) {
    for(int i = 0; i < n - 1; i++) {
        int temp = i;
        for (int j = i + 1; j < n; j++) {
            if(a[j] < a[temp]) {
                temp = j;
            }
        }
        swap(a[i], a[temp]);
    }
}

void insertionSort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int x = a[i];
        int temp = i - 1;
        while (temp >= 0 && x < a[temp]) {
            a[temp + 1] = a[temp];
            temp--;
        }
        a[temp + 1] = x;
    }
}

void mergeArray(int na, int *a, int nb, int *b, int *c) {
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb) {
        if(a[i] <= b[j]) c[k++] = a[i++];
        else if(a[i] > b[j]) c[k++] = b[j++];
    }
     while (i < na) {
        c[k++] = a[i++];
     }
     while (j < nb) {
        c[k++] = b[j++];
     }
}
void mergeSort(int *a, int n, int *buff, int cutoff) {
    if (n <= cutoff) {
        insertionSort(a, n);
        return;
    }
    int half = n / 2;
    mergeSort(buff, half, a, cutoff);
    mergeSort(buff + half, n - half, a + half, cutoff);
    mergeArray(half, buff, n - half, buff + half, a);
}

void printArray(int *a, int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
int main() {
    int n;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int choice;
    cout << "Chon thuat toan sap xep:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Comb Sort\n";
    cout << "Nhap lua chon cua ban: ";
    cin >> choice;

    int *buff = new int[n]; // Bộ đệm cho Merge Sort

    switch(choice) {
        case 1:
            bubbleSort(arr, n);
            cout << "Mang sau khi sap xep (Bubble Sort): ";
            break;
        case 2:
            selectionSort(arr, n);
            cout << "Mang sau khi sap xep (Selection Sort): ";
            break;
        case 3:
            insertionSort(arr, n);
            cout << "Mang sau khi sap xep (Insertion Sort): ";
            break;
        case 4:
            copy(arr, arr + n, buff);
            mergeSort(buff, n, arr, 4);
            copy(buff, buff + n, arr);
            cout << "Mang sau khi sap xep (Merge Sort): ";
            break;
        case 5:
            comb_sort(arr, n);
            cout << "Mang sau khi sap xep (Comb Sort): ";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
            delete[] buff;
            delete[] arr;
            return 1;
    }

    printArray(arr, n);
    delete[] buff;
    delete[] arr;
    return 0;
}
