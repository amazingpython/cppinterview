/**
 * This function reverse a singly linked list with below node defination.
 *
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverseList(ListNode* head) {

	if (head == NULL || head->next == NULL) return head;

	ListNode *permanent = head, *fast = head->next, *temp;

	while(fast) {
    	temp = fast->next;
	    fast->next = head;
    	head = fast;
	    permanent->next = temp;
    	fast = temp;
	}

	return head;
}
