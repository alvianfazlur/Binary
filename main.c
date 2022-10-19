#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <sysinfoapi.h>
#define MAKS 1000
void urutkan(int[], int);
void tampil(int[], int);
void binary(int[], int, int);
void isi(int[], int);
int main()
{
    int key,n;
    int sort[n];
    puts("Binary Searching");
    printf("Masukkan Banyak Data: ");
    scanf("%d", &n);
    isi(sort,n);
    tampil(sort,n);
    urutkan(sort,n);
    printf("Masukkan Data Yang Ingin Dicari: ");
    scanf("%d", &key);
    binary(sort,n,key);
    return 0;
}
void isi(int sort[], int panjang)
{
    for (int i = 0; i < panjang; i++)
    {
        sort[i] = rand();
    }
}

void tampil(int array[], int panjang)
{
    for (int i = 0; i < panjang; i++)
    {
        printf("%d ", array[i]);
    }
    puts(" ");
}
void urutkan(int sort[], int panjang)
{
    int cek, akhir = panjang, temp;

    for (int i = 0; i < panjang; i++)
    {
        cek = 0;
        akhir--;
        for (int j = 0; j < akhir; j++)
        {
            if (sort[j] > sort[j + 1])
            {
                temp = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = temp;
                cek = 1;
            }
        }
        if (cek == 0)
        {
            puts("Data telah diurutkan");
            break;
        }
    }
    tampil(sort, panjang);
}
void binary(int array[], int panjang, int key)
{
    int kiri = 0, kanan = panjang, tengah, valid = 0, perbandingan = 0;

    while (kiri <= kanan)
    {
        usleep(1000);
        perbandingan++;
        tengah = (kiri + kanan) / 2;
        if (array[tengah] == key)
        {
            printf("%d ada di dalam Array indeks ke %d\n", key, tengah);
            valid = 1;
            break;
        }
        else if (array[tengah] < key)
        {
            kiri = tengah + 1;
        }
        else
        {
            kanan = tengah - 1;
        }
    }
    if (!valid)
    {
        puts("Data tidak ditemukan di dalam Array");
    }
    printf("Perbandingan : %d\n", perbandingan);
}
