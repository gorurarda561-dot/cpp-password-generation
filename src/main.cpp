#include <iostream>
using namespace std;
bool arda = true;
int main (int argc, char *argv[]) {
    cout << "Toplam argüman sayısı:" << argc << endl;
    cout << "toplam kelime sayısı:" << *argv << endl;
    int argüman = 0;
    while (argüman<argc) {
        cout << "argüman" << argüman+1 << ":" << argv[argüman] << endl;
        argüman++;
    }
    return 0;

}
