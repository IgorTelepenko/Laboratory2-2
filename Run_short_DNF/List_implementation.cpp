#include"lib_list.h"
#include<iostream>
using namespace std;

/*### CHECK THE HEADER TO KNOW HOW TO USE ###*/

//inserting new node to the beginning of the list
void push(struct list_node** head, char* node_data)
{
	struct list_node* new_node = new list_node;
	new_node->data = node_data;
	new_node->next = *head;
	(*head) = new_node;
	
}

//insert a new node after a given node
void insert_after(struct list_node* prev_node, char* node_data)
{
	if (prev_node == NULL)
	{
		cout << "the given previous node is required"; return;
	}
	
	struct list_node* new_node = new list_node;
	new_node->data = node_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

//insert a new node in the end of the list
void append(struct list_node** head, char* node_data)
{
	struct list_node* new_node = new list_node;
	new_node->data = node_data;
	new_node->next = NULL;
	struct list_node* last = *head;

	if((*head) == NULL)
	{
		(*head) = new_node;
		return;
	}

	while(last->next != NULL)
	{
		last = last->next;
	}

	last->next = new_node;
	return;
}

//return a node by given index
list_node* find_by_ind(struct list_node** head, int n_ind)
{
	if(head == NULL)
	{
		cout << "List is empty "; return NULL;
	}

	struct list_node* res_node = new list_node;
	res_node = (*head);
	
	for(int i=1;i<=n_ind;i++)
	{
		res_node = res_node->next;
	}

	return res_node;
}

//deleteing a list node by given index
void delete_node_by_ind(struct list_node** head, int n_ind)
{
	struct list_node* the_deleted = find_by_ind(head, n_ind);
	struct list_node* the_prev = find_by_ind(head, n_ind-1);

	if (n_ind == 0)
	{
		(*head) = (*head)->next;
		return;
	}

	the_prev->next = the_deleted->next;
	delete the_deleted;
}


void displayList(struct list_node* head)
{
	
	while (head != NULL)
	{
		cout << head->data[0] << " ";
		head = head->next;
	}

	if (head == NULL)
		cout << "null";
}