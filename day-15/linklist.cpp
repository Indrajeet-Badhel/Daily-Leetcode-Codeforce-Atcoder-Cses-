#include <iostream>
using namespace std;
// Define a structure for a node in the linked list
struct Node {
   int data; // Data part
   Node* next; // Pointer to the next node
};
// Function to insert a node at the beginning of the linked list
void push(Node** head, int new_data) {
   Node* newNode = new Node(); // Create a new node
   newNode->data = new_data; // Assign data to the new node
   newNode->next = *head; // Point the new node to the current head
   *head = newNode; // Update the head to the new node
}
// Function to insert a node at the end of the linked list
void append(Node** head, int new_data) {
   Node* newNode = new Node(); // Create a new node
   newNode->data = new_data; // Assign data to the new node
   newNode->next = nullptr; // Set the next pointer to null
   if (*head == nullptr) { // If the list is empty, make the new node the head
       *head = newNode;
       return;
   }
   Node* last = *head; // Traverse to the last node
   while (last->next != nullptr) {
       last = last->next;
   }
   last->next = newNode; // Link the last node to the new node
}
// Function to display the linked list
void displayList(Node* node) {
   while (node != nullptr) {
       cout << node->data << " -> ";
       node = node->next;
   }
   cout << "NULL" << endl;
}
// Main function to demonstrate the linked list
int main() {
   Node* head = nullptr; // Initialize an empty linked list
   append(&head, 10); // Insert 10 at the end
   push(&head, 20); // Insert 20 at the beginning
   push(&head, 30); // Insert 30 at the beginning
   append(&head, 40); // Insert 40 at the end
   cout << "Linked List: ";
   displayList(head); // Display the linked list
   return 0;
}