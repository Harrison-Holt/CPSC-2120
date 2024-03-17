#include "doublyLinkedSwap.h"

// Implement the following function:
// p and afterp are pointers to the nodes to be swapped.
//required method
void swapWithNext(Node * p) {

	//if p is NULL or if it is the dummy head node, or tail node or 
	//the node before tail, then doing nothing & exiting method
	if(p==NULL || p->prev==NULL || p->next==NULL || p->next->next==NULL){
		return;
	}
	//taking a backup of prev and next nodes of p
	Node* old_prev=p->prev;
	Node* old_next=p->next;

	//setting next of next as the new next of p
	p->next=p->next->next;

	//setting p as the prev node of the new next node of p
	p->next->prev=p;

	//setting old_next as the next of old_prev
	old_prev->next=old_next;

	//setting old_prev as the prev of old_next
	old_next->prev=old_prev;

	//setting old_next as the new prev of p
	p->prev=old_next;

	//finally, setting p as the next of old_next.
	old_next->next=p;
}

//Be sure to comment out the main() function when submitting to codePost
/* int main()
{
    int array[] = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55};
    Node * head = arrayToList(array, 10);
    printForwards(head);
    printBackwards(getTail(head));
    
    cout << "Swap [0],[1]" << endl;
    Node * p = getNode(head, 0);
    swapWithNext(p);
    printForwards(head);
    printBackwards(getTail(head));
    
    cout << "Swap [4],[5]" << endl;
    p = getNode(head, 4);
    swapWithNext(p);
    printForwards(head);
    printBackwards(getTail(head));
    
    cout << "Swap [8],[9]" << endl;
    p = getNode(head, 8);
    swapWithNext(p);
    printForwards(head);
    printBackwards(getTail(head));
} */ 

//Do not modify any functions below this line
Node * arrayToList(int array[], int size)
{
    Node * head;
    Node * p;
    int pos = 0;
    if (size > 0)
    {
        head = new Node();
        head->prev = nullptr;
        head->value = 0;
        p = head;
        while (pos < size)
        {
            p->next = new Node();
            p->next->prev = p;
            p = p->next;
            p->value = array[pos];
            pos++;
        }
        p->next = new Node();
        p->next->prev = p;
        p = p->next;
        p->value = 0;
        p->next = nullptr;
    }
    else
    {
        return nullptr;
    }
    return head;
}

//Return pointer to end of the list
Node * getTail(Node * head)
{
    Node * p = head;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    return p;
}

//Return pointer to node with "index"
//First node "index" 0, second node "index" 1, ...
Node * getNode(Node * head, int index)
{
    int pos = 0;
    Node * p = head->next;
    if (pos == index)
    {
        return p;
    }
    else if (index < 0)
    {
        return head;
    }
    else
    {
        while (pos < index && p->next != nullptr)
        {
            p = p->next;
            pos++;
        }
    }
    return p;
}

//Print list forwards from start
void printForwards(Node * head)
{
    Node * p = head->next;
    while (p->next != nullptr)
    {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

//Print list backwards from end
void printBackwards(Node * tail)
{
    Node * p = tail->prev;
    while (p->prev != nullptr)
    {
        cout << p->value << " ";
        p = p->prev;
    }
    cout << endl;
}
