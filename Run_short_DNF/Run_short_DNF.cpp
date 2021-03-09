#include <iostream>
#include "Lib.h"
#include"lib_list.h"

using namespace std;

int main()
{
	list_node* dnf_list = NULL;
	int n_elements = 0;
	int n_variables = 0;

	cout << "enter the length of DNF: ";
	cin >> n_elements;
	cout << "enter quantity of the variables: ";
	cin >> n_variables;

	
	for(int i=0;i<n_elements;i++)
	{
		cout << "enter the first disjunction: " << endl;
		cout << "(instead of the variable print '1', instead of the negation print '0', if the variable is absent, print '-')" << endl;

		char* elements = new char[n_variables];
		for(int j=0;j<n_variables;j++)
		{
			cin >> elements[j];
		}
		append(&dnf_list, elements);
		cout << endl;
	}

	cout << "The DNF is: ";
	display_dnf(&dnf_list, n_elements, n_variables);


	for(int i=0;i<n_elements;i++)
	{
		for(int j=i+1;j<n_elements;j++)
		{
			absorption(&dnf_list, i, j, n_variables, n_elements);
			absorption(&dnf_list, j, i, n_variables, n_elements);
		}
	}

	if(n_elements > 1)
	{
		for(int i = 1; i < n_elements; i++)
		{
			for(int j = 0; j < i; j++)
			{
				if (gluing(&dnf_list, i, j, n_variables, n_elements))
				{
					bool glued_is_deleted = false;
					for (int k=0;k<n_elements-1;k++)
					{
						if(absorption(&dnf_list, n_elements - 1, k, n_variables, n_elements))
						{
							glued_is_deleted = true;
							break;
						}
					}

					if(glued_is_deleted == false)
					{
						for(int k=0;k<n_elements-1;k++)
						{
							if(absorption(&dnf_list, k, n_elements - 1, n_variables, n_elements))
							{
								if (k < i)
								{
									i--;
								}
								if (k==i)
								{
									j = -1;
								}
								k--;
							}
						}
					}
				}
				
			}
		}
	}
	
	cout << endl << "the result is: ";
	display_dnf(&dnf_list, n_elements, n_variables);
	
	return 0;
}
