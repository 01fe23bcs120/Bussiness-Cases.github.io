#include <iostream>
#include <vector>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(vector<pair<int, string>> &patients, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // Check if left child exists and is greater
    if (left < n && patients[left].first > patients[largest].first)
        largest = left;

    // Check if right child exists and is greater
    if (right < n && patients[right].first > patients[largest].first)
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        swap(patients[i], patients[largest]);
        heapify(patients, n, largest);
    }
}

// Function to perform heap sort
void heapSort(vector<pair<int, string>> &patients) {
    int n = patients.size();

    // Build the heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(patients, n, i);

    // Extract elements from the heap
    for (int i = n - 1; i > 0; i--) {
        swap(patients[0], patients[i]); // Move current root to end
        heapify(patients, i, 0); // Call heapify on reduced heap
    }
}

int main() {
    // List of patients with (priority, name), higher priority indicates more urgent
    vector<pair<int, string>> patients = {
        {5, "Patient A"}, {1, "Patient B"}, {8, "Patient C"},
        {3, "Patient D"}, {7, "Patient E"}
    };

    cout << "Before sorting (Priority, Name):\n";
    for (const auto &p : patients)
        cout << p.first << " - " << p.second << endl;

    // Sort patients by priority
    heapSort(patients);

    cout << "\nAfter sorting (Priority, Name):\n";
    for (const auto &p : patients)
        cout << p.first << " - " << p.second << endl;

    return 0;
}
