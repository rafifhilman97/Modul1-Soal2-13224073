// PRAKTIKUM PMP 
// Modul 1      : DATA MANIPULATION, EXTERNAL FILES,  STRUCTURES AND DYNAMIC ARRAYS
// Nama         : Rafif Hilman Muhammad
// NIM          : 13224073
// Nomor Soal   : 2 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Paket {
    int N;
    char key[20];
    char kode[20];
    int jumlahHuruf;
    struct Paket* next;
};

struct Paket* buatPaket(int NBaru, char KeyBaru[], char KodeBaru[]) {
    struct Paket* PaketBaru = (struct Paket*)malloc(sizeof(struct Paket));
    if (PaketBaru == NULL) {
        printf("Alokasi memori gagal!\n");
    }
    PaketBaru->N = NBaru;
    //PaketBaru->k = KataBaru;
    int i = 0;
    int j = 0;
    while(i != NULL){
        PaketBaru->key[i] = KeyBaru[i]; 
    }
    PaketBaru->jumlahHuruf = sizeof(KodeBaru) / sizeof(KodeBaru[0]);
    int jumlahtemp = PaketBaru->jumlahHuruf;
    char temp;
    if (jumlahtemp % 2 == 0){
        int q = jumlahtemp/2;
        for (int p = 0; p < q; p++){
            temp = KodeBaru[p];
            KodeBaru[p] = KodeBaru[jumlahtemp];
            KodeBaru[jumlahtemp] = temp;
            jumlahtemp--;
        }
    }
    else {
        int q = (jumlahtemp-1)/2;
        for (int p = 0; p < q; p++){
            temp = KodeBaru[p];
            KodeBaru[p] = KodeBaru[jumlahtemp];
            KodeBaru[jumlahtemp] = temp;
            jumlahtemp--;
        }
    }
    
    while(j != NULL){
        PaketBaru->kode[j] = KodeBaru[j];
    }
    PaketBaru->next = NULL;
    return PaketBaru;
}

void tambahDiAkhir(struct Paket** head_ref, int NBaru, char KeyBaru[], char KodeBaru[]) {
    struct Paket* PaketBaru = buatPaket(NBaru, KeyBaru, KodeBaru);
    
    if (*head_ref == NULL) {
        *head_ref = PaketBaru;
        return;
    }

    struct Paket* terakhir = *head_ref;
    while (terakhir->next != NULL) {
        terakhir = terakhir->next;
    }
    terakhir->next = PaketBaru;
}

void cetakBaris(struct Paket* node, int jumlahHuruf) {
    if (node == NULL) {
        printf("Kosong\n");
        return;
    }
    while (node != NULL) {
        printf("%s ", node->kode);
        node = node->next;
    }
    printf("\n");
    printf("LENGTH %d\n", jumlahHuruf);
}

void urutkanBaris(struct Paket* head){
    struct Paket* top = head;
    struct Paket* curr = NULL;
    struct Paket* largest;
    struct Paket* prev;
    prev = NULL;
    curr = top;
    largest = top;

    while(curr != NULL) {
        prev = curr;
        if(curr->N > largest->N) {
            largest = curr;
            prev->next = curr->next;
            largest->next = top;
        }
        curr = curr->next;
    }
    if(prev == NULL) {
        largest->next = top;
    }
}

int hitungHuruf(struct Paket* head){
    int jumlah;
    while (head != NULL){
        jumlah = jumlah + head->jumlahHuruf;
    }
    return jumlah;
}

int main (){
    struct Paket *head = NULL;

    int jumlahBaris;
    char kunci[20];
    scanf("%d %s", &jumlahBaris, kunci);

    int urutanBaris;
    char tempkey[20];
    char tempkode[20];
    for (int i = 0; i < jumlahBaris; i++){
        scanf("%d %s %s", &urutanBaris, tempkey, tempkode);
        if (strcmp(kunci,tempkey) == 0){
            tambahDiAkhir(&head, urutanBaris, tempkey, tempkode);
        }
    }

    urutkanBaris(&head);
    cetakBaris(&head, hitungHuruf(&head));

    return 0;
}
