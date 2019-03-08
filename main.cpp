#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
    Set<char>o1;
    cout<<"Citesc un obiect o1\n";
    cin>>o1;
    cout<<"Afisez elementele din multimea obiectului o1\n";
    cout<<o1<<'\n';
    Set<char>o2;
    o2.inserare('b');
    o2.inserare('a');
    o2.inserare('w');
    o2.inserare('t');
    o2.inserare('k');
    o2.inserare('q');
    o2.inserare('a');
    o2.inserare('k');
    o2.inserare('d');
    cout<<"Afisez elementele din multimea obiectului o2\n";
    cout<<o2<<'\n';
    cout<<"Afisez numarul de elemente din multimea lui o2\n"<<o2.numarelemente()<<'\n';
    cout<<"Suma elementelor din multimea o2\n"<<o2.sumaelemente()<<'\n';
    cout<<"Cautarea  lui 'k' in o2\n"<<o2.cautarebinara('k')<<'\n';
    o2.stergere('d');
    o2.stergere('k');
    cout<<"Afisez elementele din multimea obiectului o2 dupa stergerea lui 'k' si 'd'\n";
    cout<<o2<<'\n';
    int nr=0,nr1=0;
    char *p=o2.elementeimpare(),*t=o2.elementepare();
    cout<<"Afisez elementele impare din multimea lui o2\n";
    for(int i=1; i<p[0]; i++)
        cout<<p[i]<<" ";
    cout<<'\n';
    cout<<"Afisez elementele pare din multimea lui o2\n";
    for(int i=1; i<t[0]; i++)
        cout<<t[i]<<" ";
    cout<<'\n';
    o2.inserare('c');
    o2.inserare('r');
    o2.inserare('p');
    Set<char>o3;
    o3.inserare('a');
    o3.inserare('c');
    o3.inserare('t');
    o3.inserare('i');
    cout<<"Afisez elementele din multimea obiectului o2\n";
    cout<<o2<<'\n';
    cout<<"Afisez elementele din multimea obiectului o3\n";
    cout<<o3<<'\n';
    int x=o2<o3;//x=1 daca numarul de elemente din o2 este mai mic decat numarul de elemente din o3,0 altfel
    int y=o2>o3;//y=1 daca numarul de elemente din o2 este mai mare decat numarul de elemente din o3,0 altfel
    cout<<"Afisez x si y"<<'\n';
    cout<<x<<" "<<y<<'\n';
    Set<char>o4=o2+o3;//reunesc cele doua multimi ale lui o2 si o3,fara a contine duplicate
    cout<<"Afisez elementele din multimea lui o4\n";
    cout<<o4<<'\n';
    o3=o3*3*2*1;//inmultesc fiecare element din multimea lui o3 cu 3,2 si 1
    cout<<"Afisez elementele din multimea lui o3\n";
    cout<<o3<<'\n';
    o3=o2=o4;
    cout<<"Afisez elementele din multimea lui o2\n";
    cout<<o2<<'\n';
    cout<<"Afisez elementele din multimea lui o3\n";
    cout<<o3<<'\n';
    Set<char>o5=o2*3+o3*2;
    cout<<"Afisez elementele din multimea lui o5\n";
    cout<<o5;

    return 0;
}
