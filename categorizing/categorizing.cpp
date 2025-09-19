#include <iostream>
using namespace std;

const int MAX = 100;

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    int temp[MAX];

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= m) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];

    for (int p = 0; p < k; p++) arr[l + p] = temp[p];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

// Print Array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[MAX], n, choice, key;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Selection Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Linear Search\n";
        cout << "4. Binary Search (on sorted array)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int copyArr[MAX];
        for (int i = 0; i < n; i++) copyArr[i] = arr[i]; // original safe

        switch (choice) {
            case 1:
                selectionSort(copyArr, n);
                cout << "After Selection Sort: ";
                printArray(copyArr, n);
                break;

            case 2:
                mergeSort(copyArr, 0, n - 1);
                cout << "After Merge Sort: ";
                printArray(copyArr, n);
                break;

            case 3:
                cout << "Enter element to search: ";
                cin >> key;
                {
                    int idx = linearSearch(arr, n, key);
                    if (idx != -1) 
                        cout << key << " found at index " << idx << ".\n";
                    else 
                        cout << key << " not found.\n";
                }
                break;

            case 4:
                cout << "Enter element to search: ";
                cin >> key;
                {
                    mergeSort(copyArr, 0, n - 1); // ensure sorted
                    cout << "Sorted Array: ";
                    printArray(copyArr, n);
                    int idx = binarySearch(copyArr, n, key);
                    if (idx != -1) 
                        cout << key << " found at index (sorted array) " << idx << ".\n";
                    else 
                        cout << key << " not found.\n";
                }
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
