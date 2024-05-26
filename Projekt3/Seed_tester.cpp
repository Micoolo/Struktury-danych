#include <iostream>
#include <random> 
#include <algorithm>
#include <cstdlib>


using namespace std;

int main() {
    int seed = 1890;
    srand(seed);



    int tab[100000];
    int lowerBound = 0;
    int upperBound = 2147483647;
    std::mt19937 rp(seed);
    // std::uniform_int_distribution<unsigned int> rozklad(lowerBound, upperBound);
    std::uniform_int_distribution<int> rozklad(0, std::numeric_limits<int>::max());
    for (int i = 0; i < 100000; i++) {
        int randomNumber = rozklad(rp);  //losuje liczbe z przedzialu od 0 do size - 1
        // randomNumber = abs(randomNumber);
        tab[i] = randomNumber;
    }
    for (int i = 0; i < 100000; i ++) {
        for (int j = 0; j < 100000; j++) {
            if (i == j)
                break;
            if (tab[i]==tab[j]) {
                cout << "danwjdnajkwnda" << endl;
                cout << tab[i] << "     : " << tab[j] << endl;
            }
        }
    }
        cout << "nie ma takich samych" << endl;
    // for (int i = 0; i < 50; i++) {
    //     cout << tab[i] << endl;
    // }
}