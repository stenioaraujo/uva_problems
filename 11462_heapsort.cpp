#include <stdio.h>
int array[2000100];
int size = 0, j, temp, temp2;

void swap(int i, int j) {
     temp = array[i];
     array[i] = array[j];
     array[j] = temp;
}

int parent(int i) {
    return (i-1)/2;
}

int left(int i) {
    return 2*i + 1;
}

int right(int i) {
    return 2*i + 2;
}

void insert(int x) {
     array[size] = x;
     
     j = size++;
     while (parent(j) >= 0) {
         if(array[parent(j)] < array[j]) {
             swap(parent(j), j);
             j = parent(j);
         } else {
             break;
         }
     }
}

void heapfy(int i) {
     // temp -> largest
     temp = i;
     if (left(i) < size && array[i] < array[left(i)])
         temp = left(i);
     if (right(i) < size && array[temp] < array[right(i)])
         temp = right(i);
     
     if (temp != i) {
         swap(i, temp);
         heapfy(temp);
     }
}

void heapSort(void) {
     temp2 = size;
     for (j = size - 1; j > 0; j--) {
         swap(j, 0);
         size--;
         heapfy(0);
     }     
     size = temp2;
}

int main(void) {
    int q, i;
    
    do {
        scanf("%d", &q);
        if (q == 0) break;
        
        while(q--) {
            scanf("%d", &i);
            insert(i);
        }
        heapSort();
        
        if (size > 0)
            printf("%d", array[0]);        
        for (j = 1; j < size; j++)
            printf(" %d", array[j]);
        printf("\n");
        
        size = 0;
    } while(1);
    
    return 0;
}
