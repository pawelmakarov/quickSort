#include <stdio.h>

int arraySize(FILE *in) {
    int number;
    
    fscanf(in, "%d", &number);
    return number;
}

void arrayScan(FILE *in, FILE *out, int array[], int size) {
    for ( int i = 0; fscanf(in, "%d", &array[i]) != EOF; i++ );
}

int partition(int array[], int start, int end) {
    int avg = (start + end) / 2;
    int pivot = array[avg];
    int tail = start;
    
    printf("avg %d\n", avg);

    array[avg] = array[end];
    array[end] = pivot;
    
    for ( ; array[tail] < array[end]; tail++ );
    for ( int i = tail + 1; i <= end; i++ ) {
        if ( array[i] < array[end] ) {
            pivot = array[i];
            array[i] = array[tail];
            array[tail] = pivot;
            tail += 1;
        }
    }
    pivot = array[end];
    array[end] = array[tail];
    array[tail] = pivot;
    return tail;
}

void quickSort(int array[], int lo, int hi) {
    int pivot;
    
    if ( hi - lo < 1 ) {
        return;
    }

    pivot = partition(array, lo, hi);
    printf("pivot %d\n", pivot);
    
    quickSort(array, lo, pivot-1);
    quickSort(array, pivot+1, hi);
}

void arrayPrint(FILE *out, int array[], int size) {
    for ( int i = 1; i < size; i++ ) {
        fprintf(out, "%d ", array[i-1]);
    }
    fprintf(out, "%d\n", array[size-1]);
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size = arraySize(in);
    int array[size];
    
    arrayScan(in, out, array, size);
    fclose(in);
    
    quickSort(array, 0, size-1);
    
    arrayPrint(out, array, size);
    fclose(out);

    return 0;
}
