#include <iostream> // giriş çıkış işlemleri için
#include <random> // rastgele sayı üretmek için
#include <cstdlib> // atoi fonksiyonu için
#include <string> 
using namespace std;


 // programı nasıl kullanmamız gerektiği hakkında bilgi veren fonksiyon
int yardım () {            
    cout << "şifre oluşturucu yardım sayfası:" << endl; 
    cout << "-l --> şifre uzunluğu" << endl;
    cout << "-s --> şifrede kullanılacak karakterler (harf , sayı , sembol , hepsi )" << endl;
    cout << "-n --> kaç tane şifre üreteceği" << endl;
    return 0;
}


  // parametre olarak şifrenin karakter türünü ve çeşidini alan şifre üretici fonksiyonu
string sifre_uretici(int karakter_sayısı , string mod) {          
    string harfler = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string sayılar = "0123456789";
    string semboller = "!@#$%^&*()-+";

    string karakter_listesi = "";
 // seçilen moda göre karakter listesini belirleme
    if (mod == "harf")   karakter_listesi = harfler;        
    else if (mod == "sayı") karakter_listesi = sayılar;
    else if (mod == "sembol") karakter_listesi = semboller;
    else                      karakter_listesi = harfler + sayılar + semboller;

 //güvenli rastgele sayı üreticisi
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, karakter_listesi.size() - 1);

// şifre oluşturma
    string şifre ="";
    for (int i = 0; i < karakter_sayısı; i++) {
        şifre += karakter_listesi[dis(gen)];
    
    }
    
    return şifre;

}
// programın ana fonksiyonu, komut satırı argümanlarını işleyerek şifre üretici fonksiyonunu çağırır ve sonuçları ekrana yazdırır
int main (int argc, char *argv[]) {

    int karakter_sayısı = 12;
    int adet = 1;
    string mod = "hepsi";

    int argüman = 1;
    while (argüman < argc) {
        if (string(argv[argüman]) == "--help" || string(argv[argüman]) == "-h") {
            yardım();
            return 0;
        }
        else if (string(argv[argüman]) == "-l") {
            if (argüman + 1 >= argc) {
                cout << "hata: -l'den sonra sayı giriniz" << endl;
                return 1;
            }
            karakter_sayısı = stoi(argv[argüman+1]);
            argüman++;
        }
        else if (string(argv[argüman]) == "-s") {
            if (argüman + 1 >= argc) {
                cout << "hata: -s'den sonra karakter türü giriniz" << endl;
                return 1;
            }
            mod = argv[argüman+1];
            argüman++;
        }
        else if (string(argv[argüman]) == "-n") {
            if (argüman + 1 >= argc) {
                cout << "hata: -n'den sonra sayı giriniz" << endl;
                return 1;
            }
            adet = stoi(argv[argüman+1]);
            argüman++;
        }
        argüman++;
    }

    for (int i = 0; i < adet; i++) {
        cout << "varsayılan sifre " << i + 1 << ": " << sifre_uretici(karakter_sayısı, mod) << endl;
    }

    return 0;
}
