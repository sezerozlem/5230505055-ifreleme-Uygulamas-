#include <stdio.h>
#include <ctype.h>

void Sifreleme(char *ptr, int anahtar) { //Sifreleme fonksiyonunu yazdim
    while (*ptr != '\0') { //Dongu baslattim
        if (isalpha(*ptr)) { //Sadece alfabedeki karakterleri kulanilmasi icin gerekli kodlamalari yaptim (Interneten yardim aldim)
            char baslangic = isupper(*ptr) ? 'A' : 'a';
            *ptr = (char)((( *ptr - baslangic + anahtar) % 26 + 26) % 26 + baslangic); //Kaydirma sayisi kadar metni pozitif yonde kaydirdim
        }
        ptr++; 
    }
}

void SifreCozme(char *ptr, int anahtar) { //Sifre cozme fonksiyonunu yazdim
    while (*ptr != '\0') { //Dongu baslattim
        if (isalpha(*ptr)) { //Sadece alfabedeki karakterlerin kulanilmasi icin gerekli kodlamalari yaptim (Interneten yardim aldim)
            char baslangic = isupper(*ptr) ? 'A' : 'a';
            *ptr = (char)((( *ptr - baslangic - anahtar) % 26 + 26) % 26 + baslangic); //Kaydirma sayisi kadar metni negatif yonde kaydirdim
        }
        ptr++;
    }
}

int main() {
    char metin[100]; //Kullanicidan metin almak icin char degiskenini kullandim
    int anahtar = 3; //Kullanicidan ilerletme sayisini almak icin int degiskenini kullandim

    printf("Sifrelemek Istediginiz Metni Giriniz: "); //Ekrana "Sifrelemek Istediginiz Metni Giriniz: " ifadesini yazdirdim
    scanf("%[^\n]s", metin); //Kulanicidan metni aldim

    printf("Kaydirma Anahtar Sayisini Giriniz: "); //Ilerletme sayisi icin ekrana "Kaydirma Anahtar Sayisini Giriniz: " ifadesini yazdirdim
    scanf("%d", &anahtar); //Kulanicidan ilerletme sayisini  aldim

    Sifreleme(metin, anahtar); //Sifreleme fonksiyonunu baslattim
    printf("\nSifrelenmis Metin: %s\n", metin); //Ekrana "Sifrelenmis Metin: " yazdirdim

    SifreCozme(metin, anahtar); //Sifre cozme fonksiyonunu baslattim
    printf("Sifresi Cozulmus Metin: %s\n", metin); //Ekrana "Sifresi Cozulmus Metin: " yazdirdim

    return 0;
}




