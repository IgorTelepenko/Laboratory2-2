#include "Lib.h"
#include"lib_list.h"

using namespace std;

void display_dnf(list_node** list_dnf, int n_el, int n_var)
{
	for (int i = 0;i < n_el;i++)
	{
		char* disj;
		disj = find_by_ind(list_dnf, i)->data;

		for (int j = 0;j < n_var;j++)
		{
			switch (disj[j])
			{
			case '1':
				cout << "x" << j+1;
				break;
			case '0':
				cout << "!x" << j+1;
				break;
			case '-':
				break;
			default:
				cout << "WRONG SYNTAX!";
				break;
			}
		}
		if (i != n_el - 1)
			cout << "+";
	}
}

bool absorption(struct list_node** head, int ind_which, int ind_by, int quant_variables, int& n_total)
{
	struct list_node* list_which = find_by_ind(head, ind_which);
	struct list_node* list_by = find_by_ind(head, ind_by);

		if (list_which != NULL && list_by != NULL)
	{
		bool can_be_absorpted = true;

		for (int i = 0;i < quant_variables;i++)
		{
			if (list_by->data[i] != '-')
			{
				if (list_by->data[i] != list_which->data[i])
				{
					can_be_absorpted = false;
					break;
				}
			}
		}

		if (can_be_absorpted)
		{
			delete_node_by_ind(head, ind_which);
			n_total--;
			return true;
		}

	}
	return false;
}

bool gluing (struct list_node** head, int ind_1, int ind_2, int quant_variables, int &n_total)
{
	struct list_node* list_1 = find_by_ind(head, ind_1);
	struct list_node* list_2 = find_by_ind(head, ind_2);

	int numb_of_changes = 0;
	char* res = new char[quant_variables];
	
	for(int i=0; i<quant_variables; i++)
	{
		char el1 = list_1->data[i];
		char el2 = list_2->data[i];

		if (el1 == '-')
			res[i] = el2;
		else
		{
			if (el2 == '-')
				res[i] = el1;
			else
			{
				if (el1 == el2)
					res[i] = el1;
				else
				{
					if (el1 != el2)
					{
						res[i] = '-';
						numb_of_changes++;
					}
				}
			}
		}
	}

	if (numb_of_changes == 1)
	{
		append(head, res);
		n_total++;
		return true;
	}
	return false;
}