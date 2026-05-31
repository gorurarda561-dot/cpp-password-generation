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
    

    string şifre;
    int i=0;
    while (i<karakter_sayısı){
        int sayı = rand() % 53;
        cout << sayı << endl;
        şifre = (karakter_listesi)[sayı];
        cout << şifre << endl;
        i++;
    
    }
    
    return şifre;

}

int main (int argc, char *argv[]) {

    int karakter_sayısı;
     
    cout << "Toplam argüman sayısı:" << argc << endl;
    cout << "toplam kelime sayısı:" << *argv << endl;
    int argüman = 0;
    while (argüman<argc) {
        cout << "argüman" << argüman+1 << ":" << argv[argüman] << endl;
        if (string(argv[argüman]) == "--help" || string(argv[argüman]) == "-h") {
            yardım ();
        }
        if (string(argv[argüman]) == "-l") {
             karakter_sayısı = stoi(argv[argüman+1]);
        {
            }
        }
        argüman++;

    }
    string sifre = sifre_uretici(karakter_sayısı , mod);
    cout << "şifren: \n" << sifre << endl;
    return 0;

}
