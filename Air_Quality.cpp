#include <iostream>
#include <string>
using namespace std;

// Node structure for the Binary Search Tree
struct TreeNode {
    string timestamp; // Key: timestamp
    double pm25;      // PM2.5 concentration
    double pm10;      // PM10 concentration
    double co2;       // CO2 concentration
    TreeNode *left, *right;

    TreeNode(string ts, double p25, double p10, double c)
        : timestamp(ts), pm25(p25), pm10(p10), co2(c), left(nullptr), right(nullptr) {}
};

// Function to insert data into the tree
TreeNode* insert(TreeNode* root, string timestamp, double pm25, double pm10, double co2) {
    if (!root) {
        return new TreeNode(timestamp, pm25, pm10, co2);
    }
    if (timestamp < root->timestamp) {
        root->left = insert(root->left, timestamp, pm25, pm10, co2);
    } else if (timestamp > root->timestamp) {
        root->right = insert(root->right, timestamp, pm25, pm10, co2);
    }
    return root;
}

// Function to search for data by timestamp
TreeNode* search(TreeNode* root, string timestamp) {
    if (!root || root->timestamp == timestamp) {
        return root;
    }
    if (timestamp < root->timestamp) {
        return search(root->left, timestamp);
    }
    return search(root->right, timestamp);
}

// In-order traversal to display all data
void inOrderTraversal(TreeNode* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << "Timestamp: " << root->timestamp << ", PM2.5: " << root->pm25
             << ", PM10: " << root->pm10 << ", CO2: " << root->co2 << "\n";
        inOrderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = nullptr;

    // Insert sample sensor data
    root = insert(root, "2024-12-21 08:00", 35.5, 50.2, 400.0);
    root = insert(root, "2024-12-21 09:00", 40.0, 55.3, 420.5);
    root = insert(root, "2024-12-21 10:00", 38.7, 52.8, 410.2);

    // Search for specific timestamp data
    string queryTimestamp = "2024-12-21 09:00";
    TreeNode* result = search(root, queryTimestamp);
    if (result) {
        cout << "Data found for " << queryTimestamp << ":\n";
        cout << "PM2.5: " << result->pm25 << ", PM10: " << result->pm10
             << ", CO2: " << result->co2 << "\n";
    } else {
        cout << "No data found for timestamp " << queryTimestamp << ".\n";
    }

    // Display all sensor data
    cout << "\nAll sensor data (sorted by timestamp):\n";
    inOrderTraversal(root);

    return 0;
}
