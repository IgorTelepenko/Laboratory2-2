#pragma once
#include"lib_list.h"

void display_dnf(list_node** list_dnf, int n_el, int n_var);
bool absorption(struct list_node** head, int ind_which, int ind_by, int quant_variables, int &n_total);
bool gluing(struct list_node** head, int ind_1, int ind_2, int quant_variables, int& n_total);