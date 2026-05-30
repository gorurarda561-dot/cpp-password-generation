#include <iostream>
using namespace std;
#include <cstdlib>


int yardım () {
    cout << "şifre oluşturucu yardım sayfası:" << endl; 
    cout << "-l --> şifre uzunluğu" << endl;
    cout << "-s --> şifrede kullanılacak karakterler" << endl;
    return 0;
}


 
string sifre_uretici(int karakter_sayısı) {
    char karakter_listesi[] = {'a' , 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    string şifre;
    int i=0;
    while (i<karakter_sayısı){
        int sayı = rand() % 29;
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
    string sifre = sifre_uretici(karakter_sayısı);
    cout << "şifren: \n" << sifre << endl;
    return 0;

}
