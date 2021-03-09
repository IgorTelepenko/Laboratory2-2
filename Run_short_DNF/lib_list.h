#pragma once
#include<iostream>
struct list_node
{
	char* data; //the array
	struct list_node* next;

	list_node()
	{
		next = NULL;
	}
};

void push(struct list_node** head, char* node_data);
void insert_after(struct list_node* prev_node, char* node_data);
void append(struct list_node** head, char* node_data);
list_node* find_by_ind(struct list_node** head, int n_ind);
void delete_node_by_ind(struct list_node** head, int n_ind);

void displayList(struct list_node* head); //mostly for tests

/*### EXAMPLE OF USAGE ###*/
 /*//#include"lib_list.h"
 // (IN "int main"):
	list_node* node1 = new list_node;
	char arr[3] = { '1', '9', '9'};
	node1->data = arr;

	char arr1[1] = {'2'};
	append(&node1, arr1);

	char arr3[1] = { '0' };
	push(&node1, arr3);

	delete_node_by_ind(&node1, 1);
	
	insert_after(find_by_ind(&node1, 0), arr2);
	
	displayList(node1);

	cout << find_by_ind(&node1, 1)->data[0];
	//not to forget about additional changing of the number of elements
 */