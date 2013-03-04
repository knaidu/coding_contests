// Given a linked list, delete a node given the pointer to that node.

// Returns 0/1 - SUCCESS/FAILURE
int deleteNode(Node head, Node toDelete) {
	if(toDelete == NULL) return FAILURE;

	// If this is the last node
	if(toDetele->next = null) {
		Node prev = head;
		while(prev->next != toDelete) prev = prev->next;
		prev->next = NULL;
		delete(toDelete);
		return SUCCESS;
	}


	toDelete->data = toDelete->next->data;
	Node temp = toDelete->next;
	toDelete->next = toDelete->next->next;
	delete(toDelete);
	return SUCCESS;
}