#include <iostream>

using namespace std;
 
typedef struct Node {
	double data;
	struct Node* next;
	struct Node* prev;
};

class DoubleLinkedList {
private:
	Node* head;
	Node* tail;
public:
	DoubleLinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	//struct Node* head = NULL;
	void insert(int newdata) {
		Node* newnode = new Node();
		newnode->data = newdata;
		newnode->prev = nullptr;
		newnode->next = head;
		if (head != nullptr) {
			head->prev = newnode;
			head = newnode;
			return;
		}
		head = newnode;
		tail = newnode;
	}

	void displayr() {
		struct Node* ptr;
		ptr = head;
		while (ptr != NULL) {
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
	}
	void display() {
		struct Node* ptr;
		ptr = tail;
		while (ptr != NULL) {
			cout << ptr->data << " ";
			ptr = ptr->prev;
		}
	}

	void deleteValue(double data) {
		for (Node* temp = head; temp != nullptr; temp = temp->next) {
			if (temp->data == data) {
				if (temp->prev == nullptr) { //if first
					head = temp->next;
				}
				else
					temp->prev->next = temp->next;
				
				
				if (temp->next == nullptr) { // if last
					tail = tail->prev;
				}


				else
					temp->next->prev = temp->prev;

				delete temp;
				return;
			}
		}
	}
};


int main() {
	DoubleLinkedList list;
	int choice = 0;
	for (; 1 == 1; ) {
		cout << "Please enter: \n 1. Add Value \n 2. Delete Value \n 3. Display List (forward) \n 4. Display List (backward) \n 5. Quit \n";
		cin >> choice;
		int data;
		if (choice == 1) {
			cout << "Add value: ";
			cin >> data;
			list.insert(data);
		}
		else if (choice == 2) {
			cout << "Delete value: ";
			cin >> data;
			list.deleteValue(data);
		}
		else if (choice == 3) {
			cout << "Display forward: " << endl;
			list.display();
			cout << endl << endl;
		}
		else if (choice == 4) {
			cout << "Display Revers: " << endl;
			list.displayr();
			cout << endl << endl;
		}
		else if (choice == 5) {
			goto Check1;
		}
		else {}
	}
Check1:
	return 0;
}
