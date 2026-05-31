#include <iostream>
#include <random>
#include <cstdlib>
#include <string>
using namespace std;



int yardım () {
    cout << "şifre oluşturucu yardım sayfası:" << endl; 
    cout << "-l --> şifre uzunluğu" << endl;
    cout << "-s --> şifrede kullanılacak karakterler (harf , sayı , sembol , hepsi )" << endl;
    cout << "-n --> kaç tane şifre üreteceği" << endl;
    return 0;
}


 
string sifre_uretici(int karakter_sayısı , string mod) {
    string harfler = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string sayılar = "0123456789";
    string semboller = "!@#$%^&*()-+";

    string karakter_listesi = "";

    if (mod == "harf")   karakter_listesi = harfler;
    else if (mod == "sayı") karakter_listesi = sayılar;
    else if (mod == "sembol") karakter_listesi = semboller;
    else                      karakter_listesi = harfler + sayılar + semboller;


    //güvenli rastgele sayı üreticisi
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, karakter_listesi.size() - 1);


    string şifre"";
    for (int i = 0; i < karakter_sayısı; i++) {
        şifre += karakter_listesi[dis(gen)];
    
    }
    
    return şifre;

}

int main (int argc, char *argv[]) {

    int karakter_sayısı = 12; //istediğimiz uzunluk 
    string adet = "1"; //istediğimiz şifre adedi
    string mod = "hepsi"; //varsayılan karakter seti 

     
    int argüman = 1; // 0. argüman program adı olduğu için 1 den başlatıyoruz
    while (argüman<argc) {
        if (string(argv[argüman]) == "--help" || string(argv[argüman]) == "-h") {
            yardım ();
            return 0;
        }
        }
        if (string(argv[argüman]) == "-l") {
            if (argüman + 1 < argc) {
                cout << "hata: -l'den sonra sayı giriniz" << endl;
                return 1;
            }
        {
             karakter_sayısı = stoi(argv[argüman+1]);
              argüman++;
            }
            else if (string(argv[argüman]) == "-s") {
                if (argüman + 1 < argc) {
                    cout << "hata: -s'den sonra karakter türü giriniz (harf , sayı , sembol , hepsi)" << endl;
                    return 1;
        }
        mod = argv[argüman+1];
        argüman++;
    }
    else if (string(argv[argüman]) == "-n") {
        if (argüman + 1 < argc) {
            cout << "hata: -n'den sonra sayı giriniz" << endl;
            return 1;
        }
        adet = argv[argüman+1];
        argüman++;
    }
    for (int i = 0; i < adet; i++) {
        cout << "sifre " << i + 1 << ": " << sifre_uretici(karakter_sayısı, mod) << endl;
    
}
    return 0;

}
