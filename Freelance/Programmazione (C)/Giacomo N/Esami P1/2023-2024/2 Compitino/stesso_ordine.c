#include <stdio.h>

/*

 */


//PRE:
//POST:
void swap_eq(int* a, int dim, int i, int j, int n) {
    // codie qui
}


//PRE:
//POST:
void swap(int* a, int dim, int m, int n, int p) {
 // codice qui
}



int main(void) {
    int dim;
    int m;
    int n;
    int p;
    
    scanf("%d", &dim);
    int arr[dim];
    for(int i = 0; i < dim; i++){
        scanf("%d", arr+i);
    }
    
    void print_array(int *a, int d) {
    for (int i = 0; i < d; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

scanf("%d", &m);
scanf("%d", &n);
scanf("%d", &p);

swap(arr, dim, m, n, p); 
print_array(arr, dim);

}
