#include <bits/stdc++.h>
using namespace std;

// Employee structure
struct Employee {
    int id;
    string name;
    double salary;
};

// Merge function for Employee array based on id
void merge(Employee arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    Employee L[n1 + 1], R[n2 + 1];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[q + 1 + j];
    }

    // Sentinel value (high ID) to avoid array out-of-bound
    L[n1].id = R[n2].id = INT_MAX;

    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        if (L[i].id <= R[j].id) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
    }
}

// Recursive merge sort
void mergeSort(Employee arr[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

// Binary search for employee by ID
int binarySearch(Employee arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].id == key) {
            return mid;
        } else if (arr[mid].id < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

// Display all employees
void display(Employee arr[], int n) {
    cout << "\nID\tName\tSalary\n";
    cout << "--------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].id << "\t" << arr[i].name << "\t" << arr[i].salary << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    Employee emp[n];
    cout << "Enter employee details (ID Name Salary):\n";
    for (int i = 0; i < n; i++) {
        cin >> emp[i].id >> emp[i].name >> emp[i].salary;
    }

    cout << "\nUnsorted Employee Records:";
    display(emp, n);

    mergeSort(emp, 0, n - 1);

    cout << "\nSorted Employee Records (by ID):";
    display(emp, n);

    int key;
    cout << "\nEnter Employee ID to search: ";
    cin >> key;

    int index = binarySearch(emp, n, key);
    if (index != -1) {
        cout << "\nEmployee Found:\n";
        cout << "ID: " << emp[index].id << ", Name: " << emp[index].name << ", Salary: " << emp[index].salary << endl;
    } else {
        cout << "\nEmployee with ID " << key << " not found.\n";
    }

    return 0;
}

