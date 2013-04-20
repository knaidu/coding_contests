// Sort a singly linked list of unknown size in without using extra space

class Node {
	int data;
	Node& next;
}

const int INVALID = -1;

int sort(Node& head) {
	if(head == NULL) return INVALID;

	Node& newHead;

	Node& temp = removeHead(head);
	while(temp != NULL) {
		insertNode(newHead, temp);
		temp = removeHead(head);
	}
	
	head = newHead;	
	return SUCCESS;
}  

Node& removeHead(Node& head) {
	Node& temp = head;
	head = nead->next;
	temp->next = NULL;
	return temp;
}

void insertNode(Node& head, Node& temp) {
	if(head == NULL) {
		head = temp;
		return;
	}
	if(head->next == NULL) {
		if(temp->data < head->data) {
			temp->next = head;
			head = temp;
			return;
		}
		else {
			head->next = temp;
			return;
		}
	}


	Node& curr = head->next;
	Node& prev = head;
	while(curr-> != NULL) {
		if(temp->data > prev->data && temp->data < curr->data) {
			prev->next = temp->next;
			prev->next = temp;
			return;
		}
		else {
			curr = curr->next;
			prev = prev->next;
		}
	}

}