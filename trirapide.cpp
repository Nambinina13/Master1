#include<iostream>
#include<random>
#include<chrono>
#include<vector>
#include<algorithm>

/*Pour eviter de tape std a plusieur fois*/
using namespace std;

/*Creation du fonction insertion nombre aleatoir */

namespace myRandom{

  auto generate(int min_t,int max_t,int nombre){

  random_device rd;
  mt19937 gen (rd());

    uniform_int_distribution<int>dis(min_t,max_t);

  auto tab = std::vector<int> (nombre);

    for(auto &n:tab){

      n=dis(gen);

    }

    return tab;
  }
}
void echange(vector<int> &tab, const size_t a, const size_t b)
{
    int c(tab[a]);
    tab[a] = tab[b];
    tab[b] = c;
}

/*Creation de fonction du trirapide*/
size_t pivotage(vector<int> &tab, const size_t deb, const size_t fin)
{
    size_t index(deb);

    for (size_t i(deb+1); i<=fin; ++i)
    {
        if ( tab[i]<tab[deb] )
        {
            index++; // On incrémente la place finale du pivot
            echange(tab, index, i); // On positionne l'élément
            }
    }
    echange(tab, index, deb);

    return index; // Et on retroune sa position
}

void trirapide(vector<int> &tab, const size_t deb, const size_t fin)
{
    if (deb<fin)
    {
        size_t pivot( pivotage(tab, deb, fin) );

        trirapide(tab, deb, pivot-1);
        trirapide(tab, pivot+1, fin);
    }
}
void affichage(std::vector<int>& tab){

    for (int i = 0; i < tab.size(); i++) {
      std::cout << tab[i]<<'\t' ;
    }
    std::cout << '\n';
}

void mesure(){
  auto start = chrono::system_clock::now();

  auto end = chrono::system_clock::now();

  chrono::duration<double> elapsed_seconds = end-start;

  time_t end_time = chrono::system_clock::to_time_t(end);

  cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

}
int main(int argc, char const *argv[]) {

  int min_t,max_t,nombre;

  std::cout << "Valeur minimum" << '\n';

  std::cin >> min_t;

  std::cout << "Valeur maximum" << '\n';

  std::cin >> max_t;

  std::cout << "Nombre d'element" << '\n';

  std::cin >> nombre;

    std::vector<int> tab=

    myRandom::generate(min_t,max_t,nombre);

    affichage(tab);

      std::cout << "**********************************" << '\n';

    trirapide(tab,min_t,nombre);

    affichage(tab);

    mesure();

/*Creation de nombre aleatoire suivant le tri sort*/
    std::vector<int> tab1= myRandom::generate(min_t,max_t,nombre);

      std::cout << "**********************************" << '\n';

    affichage(tab1);

      std::cout << "**********************************" << '\n';

    std::sort(tab1.begin(),tab1.end());

    affichage(tab1);

    mesure();

    std::cout <<  '\n';

  return 0;
}
