#ifndef _SORT_H_
#define _SORT_H_

void print_array(const int *array, size_t size);
void fix_heap(int *array, size_t size, size_t root, size_t last);
void heap_sort(int *array, size_t size);

#endif
