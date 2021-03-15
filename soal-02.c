#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mahasiswa {
    char nama[20];
    int NIM;
    int nilai;
};

struct mahasiswa *ptr;

void printhasilcari(int index[], int n){
    printf("\nHasil pencarian:\n");
    for (int i = 0; i < n; ++i){
        printf("%s\t%d\t%d\n", (ptr + index[i])->nama, (ptr + index[i])->NIM, (ptr + index[i])->nilai);
    }
}

void printdata(struct mahasiswa *ptr, int n, int kategori){
    printf("\nHasil sorting berdasarkan ");
    if(kategori==0){
        printf("nama:\n");
    } else if(kategori==1){
        printf("NIM:\n");
    } else if(kategori==2){
        printf("nilai:\n");
    }
    for (int i = 0; i < n; ++i){
        printf("%s\t%d\t%d\n", (ptr + i)->nama, (ptr + i)->NIM, (ptr + i)->nilai);
    }
}

void cari(struct mahasiswa *ptr, int n, char find[20]){
    struct mahasiswa temp;
    int found = 0, arrfound[n];
    char str[9];

    for(int i=0; i<n; i++){
        if(strstr(ptr[i].nama, find)){
            arrfound[found] = i;
            found++;
        }
        sprintf(str, "%d", ptr[i].NIM);
        if(strstr(str, find)){
            arrfound[found] = i;
            found++;
        }
    }
    if(found>0){
        printhasilcari(arrfound, found);
    } else{
        printf("\nData tidak ditemukan!\n");
    }
}

int sortStrings(struct mahasiswa *ptr, int n) { 
    struct mahasiswa temp;
    // Sorting strings using bubble sort 
    for (int j=0; j<n-1; j++) { 
        for (int i=j+1; i<n; i++) {
            if (strcmp(ptr[j].nama, ptr[i].nama) > 0) {
                temp = ptr[j]; 
                ptr[j] = ptr[i]; 
                ptr[i] = temp; 
            } 
        } 
    }
    printdata(ptr, n, 0);

    for (int j=0; j<n-1; j++) { 
        for (int i=j+1; i<n; i++) {
            if(ptr[j].NIM > ptr[i].NIM) {
                temp = ptr[j]; 
                ptr[j] = ptr[i]; 
                ptr[i] = temp; 
            } 
        } 
    }
    printdata(ptr, n, 1);
    
    for (int j=0; j<n-1; j++) { 
        for (int i=j+1; i<n; i++) {
            if (ptr[j].nilai < ptr[i].nilai) {
                temp = ptr[j]; 
                ptr[j] = ptr[i]; 
                ptr[i] = temp; 
            } 
        } 
    }
    printdata(ptr, n, 2);
}

int main() {
    int i, n;
    char find[20];
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);

    // Memory allocation for n structures
    ptr = (struct mahasiswa *)malloc(n * sizeof(struct mahasiswa));
    
    printf("Masukkan nama, NIM, dan nilai:\n");
    for (i = 0; i < n; ++i) {
        scanf("%s %d %d", (ptr + i)->nama, &(ptr + i)->NIM, &(ptr + i)->nilai);
    }
    
    printf("\nMasukkan Nama atau NIM yang ingin dicari:\n");
    scanf("%s", &find);

    cari(ptr, n, find);

    sortStrings(ptr, n);

    return 0;
}
