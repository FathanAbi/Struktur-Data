/*
    1. selection input elemen
    2. sort
    3. print genap
    4. print ganjil
*/

#include <stdio.h>
#include <stdlib.h>

// Struktur ADT DynamicArray

typedef struct dynamicarr_t {
    int *_arr; // address base elemen
    unsigned _size; // ukuran (size) array
    unsigned _capacity; // kapasitas array
} DynamicArray;

// Prototipe fungsi

void dArray_init(DynamicArray *darray);
int dArray_isEmpty(DynamicArray *darray);
void dArray_pushBack(DynamicArray *darray, int value);
void dArray_popBack(DynamicArray *darray);
int  dArray_back(DynamicArray *darray);
int  dArray_front(DynamicArray *darray);
void dArray_setAt(DynamicArray *darray, unsigned index, int value);
int  dArray_getAt(DynamicArray *darray, unsigned index);

// Definisi fungsi


// deklarasi dynamic array (d array)
void dArray_init(DynamicArray *darray)
{
    darray->_capacity = 2u; // kapasitas awal = 2
    darray->_size = 0u;  // size awal = 0, untuk track size array
    darray->_arr = (int*) malloc(sizeof(int) * 2);  // alokasi memori untuk base elemen
}


// cek apakah d array kosong atau tidak
// kosong akan return 1, jika ada isinya akan return 0
int dArray_isEmpty(DynamicArray *darray) {
    return (darray->_size == 0);
}

// menambahkan elemen dari belakang
void dArray_pushBack(DynamicArray *darray, int value)
{
    // cek apakah array penuh atau tidak
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;  // double kapasitas array
        int *newArr = (int*) malloc(sizeof(int) * darray->_capacity); // buat array baru dan alokasikan memori
        
        // copy array lama ke array baru
        for (it=0; it < darray->_size; ++it)
            newArr[it] = darray->_arr[it];
        
        //ganti address d array
        int *oldArray = darray->_arr; 
        darray->_arr = newArr;

        // release memori array lama
        free(oldArray);
    }

    // masukkan value
    darray->_arr[darray->_size++] = value;
}

// hapus elemen paling belakang
void dArray_popBack(DynamicArray *darray) {
    if (!dArray_isEmpty(darray)) darray->_size--; // jika aray berisi maka ukuran array -1 (akan membuat elemen paling akhir tidak dapat diakses)
    else return;
}

// mendapatkan elemen array paling belakang
int dArray_back(DynamicArray *darray) {
    // jika array berisi
    if (!dArray_isEmpty(darray))
        return darray->_arr[darray->_size-1];
    // jika array kosong
    else return 0;
}

// mendapatkan elemen array paling depan
int dArray_front(DynamicArray *darray) {
    // jika array berisi
    if (!dArray_isEmpty(darray))
        return darray->_arr[0];
    //jika array kosong
    else return 0;
}

// mengisi elemen pada array dengan indeks tertentu
void dArray_setAt(
    DynamicArray *darray, unsigned index, int value)
{
    // case jika array berisi
    if (!dArray_isEmpty(darray)) {
        // jika indeks lebih dari atau sama dengan size array maka elemen diletakkan di paling belakang
        if (index >= darray->_size)
            darray->_arr[darray->_size-1] = value;
        else
            darray->_arr[index] = value;
    }
}

// mendapatkan elemen dari indeks tertentu
int dArray_getAt(DynamicArray *darray, unsigned index)
{
    // jika array berisi
    if (!dArray_isEmpty(darray)) {
        // jika indeks lebih dari atau sama dengan size maka ambil elemen paling belakang
        if (index >= darray->_size)
            return darray->_arr[darray->_size-1];
        else
            return darray->_arr[index];
    }
    return 0;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    /* create temp arrays */
    int L[n1], R[n2];
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
  
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}

int main()
{
    DynamicArray genap;
    DynamicArray ganjil;

    dArray_init(&genap);
    dArray_init(&ganjil);

    int n, i, temp;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &temp);
        if(temp%2 == 0) dArray_pushBack(&genap, temp);
        else dArray_pushBack(&ganjil, temp);
    }
    
    int sgenap = genap._size;
    int sganjil = ganjil._size;
    int agenap[sgenap];
    int aganjil[sganjil];

    for(i=0;i<sgenap;i++){
        agenap[i] = dArray_getAt(&genap, i);
    }
    for(i=0;i<sganjil;i++){
        aganjil[i] = dArray_getAt(&ganjil, i);
    }
    
    /* 
        printf("genap: ");
            for(i=0;i<sgenap;i++){
                printf("%d ", agenap[i]);
            }
        printf("\nganjil: ");
            for(i=0;i<sganjil;i++){
                printf("%d ", aganjil[i]);
            }
    */
    
    mergeSort(agenap, 0, sgenap-1);
    mergeSort(aganjil, 0, sganjil-1);

        for(i=0;i<sgenap;i++){
            printf("%d\n", agenap[i]);
        }
    
        for(i=sganjil-1;i>=0;i--){
            printf("%d\n", aganjil[i]);
        }

    /*
        printf("genap: ");
        for(i=0;i<genap._size;i++){
            printf("%d ", dArray_getAt(&genap, i));
        }
        printf("\nganjil: ");
        for(i=0;i<ganjil._size;i++){
            printf("%d ", dArray_getAt(&ganjil, i));
        }
    */
}