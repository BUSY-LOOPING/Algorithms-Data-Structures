#include <iostream>
#include <cstdlib>
using namespace std;

class node
{
public:
	int data;
	node *next;
	node *prev;
};

void IB(node **head, int data)
{
	node *ptr = new node();
	ptr->data = data;

	ptr->prev = NULL;
	if (head == NULL)
	{
		ptr->next = NULL;
	}
	else
	{
		ptr->next = *head;
		(*head)->prev = ptr;
		*head = ptr;
	}
}

void IE(node *head, int data)
{
	node *ptr = new node();
	ptr->data = data;

	while (head->next != NULL)
	{
		head = head->next;
	}

	head->next = ptr;
	ptr->prev = head;
	ptr->next = NULL;
}

void RB(node **head)
{
	if (*head == NULL)
		return;

	node *ptr = *head;
	*head = ptr->next;
	free(ptr);

	(*head)->prev = NULL;
}

void RP(node **head, int p)
{
	node *ptr = new node();
	ptr = *head;

	if (p == 0)
	{
		RB(head);
	}

	else
	{
		while (p--)
		{
			if (ptr->next == NULL)
			{
				cout << "\nInvalid Position\n";
				return;
			}

			ptr = ptr->next;
		}

		ptr->prev->next = ptr->next;

		if (ptr->next != NULL)
			ptr->next->prev = ptr->prev;

		free(ptr);
	}
}

void IP(node **head, int data, int p)
{
	node *ptr = new node();
	ptr = *head;
	if (p == 0)
	{
		IB(head, data);
	}
	else
	{
		p--;
		while (p--)
		{
			if (ptr == NULL)
			{
				cout << "\nInvalid Position\n";
				return;
			}

			ptr = ptr->next;
		}

		node *n = new node();
		n->data = data;

		n->prev = ptr;
		n->next = ptr->next;
		ptr->next = n;

		if (n->next != NULL)
			n->next->prev = n;
	}
}

void RE(node *head)
{
	if (head == NULL)
		return;

	node *ptr = new node();
	ptr = head;

	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}

	ptr->prev->next = NULL;

	free(ptr);
}

int search(node *head, int data)
{
	int i = 0;
	node *ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == data)
			return i;
		ptr = ptr->next;
		i++;
	}

	return -1;
}

node *concat(node *h1, node *h2)
{
	if (h1 == NULL)
		return h2;

	else if (h2 == NULL)
		return h1;

	else
	{
		node *ptr = h1;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}

		ptr->next = h2;
		h2->prev = ptr;
	}

	return h1;
}

void enter(node **head, int n)
{
	if (n != 0)
	{
		int num;
		*head = new node();
		node *ptr = new node();
		cout << "\nEnter the value for the 1 node : ";
		cin >> num;
		ptr->data = num;
		*head = ptr;
		ptr = *head;
		for (int i = 2; i <= n; i++)
		{
			node *p = new node();
			cout << "\nEnter the value for the " << i << " node : ";
			cin >> num;
			p->data = num;
			ptr->next = p;
			p->prev = ptr;
			ptr = p;
		}
	}
}

void print(node *ptr)
{
	while (ptr != NULL)
	{
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
}

int main()
{
	int num, pos, choice;
	char ch;
	node *head = NULL;
	cout << "\nEnter the number of elements to be inserted in the doubly linked list : ";
	cin >> num;
	enter(&head, num);

	do
	{
		cout << "\nThe Linked list is: ";
		print(head);

		cout << "\n\nMENU";
		cout << "\n 1. Insert at Beginning\n 2. Insert at a particular position\n 3. Insert at the end\n 4. Remove from beginning\n 5. Remove from a particular position\n 6. Remove from the end\n 7. Search for a particular element\n 8. Concatenate two lists";
		cout << "\n\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\nEnter the value to be inserted at beginning: ";
			cin >> num;
			IB(&head, num);
			print(head);
			break;

		case 2:
			cout << "\nEnter the value to be inserted: ";
			cin >> num;
			cout << "\nEnter the position where data is to be inserted: ";
			cin >> pos;
			IP(&head, num, pos);
			print(head);
			break;

		case 3:
			cout << "\nEnter the value to be inserted at the end: ";
			cin >> num;
			IE(head, num);
			print(head);
			break;

		case 4:
			RB(&head);
			cout << "\n\nAfter removing beginning element, the linked list is: ";
			print(head);
			break;

		case 5:
			cout << "\nEnter the position of the linked list to be removed: ";
			cin >> pos;
			RP(&head, pos);
			cout << "\n\nAfter removing the given node, the linked list is: ";
			print(head);
			break;

		case 6:
			RE(head);
			cout << "\n\nAfter removing element from end, the linked list is: ";
			print(head);
			break;

		case 7:
			cout << "\nEnter the value to be searched for in the linked list: ";
			cin >> num;
			if (search(head, num) == -1)
				cout << "\nThe entered value is not in the linked list.";

			else
				cout << "\nThe entered value is found at position: " << search(head, num);

			break;

		case 8:
			node *head1 = NULL;
			cout << "\nEnter the number of elements in the second linked list: ";
			cin >> num;
			enter(&head1, num);
			cout << "\n\nOn Concatenating the two linked list we get: ";
			head1 = concat(head, head1);
			print(head1);
			break;
		}

		cout << "\nWant to enter more (Y/N) : ";
		cin >> ch;

	} while (ch == 'y' || ch == 'Y');

	return 0;
}
