struct node *index_find (int index, struct node *head) {
    struct node *curr = head;
    struct node *prev;
    int i = 0;
    while(curr != NULL && i < index) {
        prev = curr;
        curr = curr->next;
        i++;  
    }
    prev->next = curr->next;
    curr->next = head;
    head = curr;
    return head;
}
