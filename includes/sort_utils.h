#ifndef __SORT_UTILS_H__
#define __SORT_UTILS_H__

# define ORDER_NOT_DEFINED 100
# define ORDER_DESCEND (-1)
# define ORDER_ASCEND 1
# define ORDER_NOT 2

# define STACK_A 1
# define STACK_B 0
# define DESCENDING_ORDER 1
# define ASCENDING_ORDER 0

int is_sorted(int* array, int size);
void merge(int* array, int lo, int mid, int hi, int* aux);
void merge_sort_impl(int* array, int lo, int hi, int* aux);
void merge_sort(int* array, int size);
int middle_val(int* array, int size);

#endif