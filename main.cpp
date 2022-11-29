#include <iostream>

// Taken from leetcode
struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode* next, ListNode* prev) : val(x), next(next), prev(prev) {}
};

class DoubleLinkedList {
	
public:

	ListNode* head{ nullptr };
	ListNode* tail{ nullptr };

    void AppendNode(ListNode* node);
	void PrependNode(ListNode* node);
	void InsertAfterNode(ListNode* curr, ListNode* node);
	void RemoveNode(ListNode* node);
};

void DoubleLinkedList::AppendNode(ListNode* node) {
	
	// No head or tail yet
	if (this->head == nullptr) {
		this->head = node;
		this->tail = node;
	}
	else { 
		tail->next = node;

		node->prev = tail; // Point backwards
		tail = node; // Update the tail
	}
	
}

void DoubleLinkedList::PrependNode(ListNode* node) {

	// No head or tail yet
	if (this->head == nullptr) {
		this->head = node;
		this->tail = node;
	}
	else {

		node->next = this->head; // The new node's next point to the current head node.
		this->head->prev = node; // THe current head's previous should point backwards to our node.
		
		this->head = node; // Make our node the new head

	}

}

void DoubleLinkedList::InsertAfterNode(ListNode* curr, ListNode* node) {

	// No head or tail yet
	if (this->head == nullptr) {
		this->head = node;
		this->tail = node;
	}
	else if (curr == this->tail) { // Inserting after tail
		this->tail->next = node;
		node->prev = this->tail;	
		this->tail = node;
	}
	else {

		ListNode* temp = curr->next; 
		node->next = temp;
		node->prev = curr;

		curr->next = node;

		temp->prev = node;

	}

}

void DoubleLinkedList::RemoveNode(ListNode* node) {

	ListNode* succ_node = node->next;
	ListNode* pred_node = node->prev;

	if (succ_node) {
		succ_node->prev = pred_node;
	}

	if (pred_node) {
		pred_node->next = succ_node;
	}

	if (node == this->head) { // Removing head
		this->head = succ_node;
	}

	if (node == this->tail) {
		this->tail = pred_node;
	}

}

int main() {

	DoubleLinkedList* List = new DoubleLinkedList;
	printf("Head is initially null %p\n", List->head);
	printf("Tail is initially null %p\n", List->tail);

	ListNode* a = new ListNode;
	ListNode* b = new ListNode;
	ListNode* c = new ListNode;
	ListNode* d = new ListNode;
	ListNode* e = new ListNode;

	a->val = 1;
	b->val = 2;
	c->val = 3;
	d->val = 0;
	e->val = 4;

	List->AppendNode(a);
	List->AppendNode(b);
	List->AppendNode(c);
	List->PrependNode(d);
	List->InsertAfterNode(c, e);
	List->RemoveNode(e);

	ListNode* curr = List->head;
	while (curr) {
		printf("Val :%i\n", curr->val);
		curr = curr->next;
	}


	system("pause");
    return 0;
}