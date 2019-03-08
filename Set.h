#ifndef SET_H
#define SET_H
#include <iostream>
#include <stdlib.h>

using namespace std;

template<class T>
class Set
{
    int n;
    T *v;
public:
    Set();
    Set(T*,int);
    Set(const Set<T> &);
    int cautarebinara(T);
    void inserare(T);
    void stergere(T);
    int numarelemente();
    T sumaelemente();
    T *elementepare();
    T *elementeimpare();
    T &operator[](int);
    int operator<(Set<T>);
    int operator>(Set<T>);
    Set<T> operator=(const Set<T> &);
    template <class U> friend Set<U> operator*(const Set<U> &,int);
    template <class U> friend Set<U> operator+(const Set<U> &,const Set<U> &);
    template <class U> friend istream &operator>>(istream &,Set<U> &);
    template <class U> friend ostream &operator<<(ostream &,Set<U> &);
    virtual ~Set();
protected:
private:
};

#endif // SET_H
template <class T>
Set<T>::Set()//constructor fara parametrii
{
    v=NULL;
    n=0;
}
template <class T>
Set<T>::Set(T *p,int nr)//constructor cu parametrii prin care copiez in v pe p
{
    this->n=0;
    this->v=NULL;
    for(int i=0; i<nr; i++)
        this->inserare(p[i]);

}
template <class T>
Set<T>::Set(const Set<T> &s)//constructor de copiere prin care copiez un obiect peste altul
{
    v=(T *)malloc((s.n)*sizeof(T));
    n=s.n;
    for(int i=0; i<s.n; i++)
        v[i]=s.v[i];
}
template <class T>
int Set<T>::cautarebinara(T x)//folosesc cautarea binara care are complexitatea O(log n)
{
    int st=0,dr=n-1,mij=0;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(v[mij]==x)
            return mij;//daca am gasit elementul returnez pozitia
        else if(v[mij]>x)
            dr=mij-1;//trebuie sa caut in partea de la st la mij-1
        else if(v[mij]<x)
            st=mij+1;//trebuie sa caut in partea de la mij+1 la dr
    }
    return -1;//daca nu am gasit elementul in vector
}
template <class T>
void Set<T>::inserare(T x)//are complexitate de O(n)
{
    int poz=0,ok=1;
    if(n==0)//daca nu e niciun element in vector
    {
        v=(T *)realloc(v,(n+1)*sizeof(T));//aloc memorie necesara
        v[0]=x;//inserez elementul
        n++;//cresc numarul de elemente din vector
    }
    else if(v[0]>x)//daca primul element este mai mare decat elementul pe care vreau sa-l inserez inseamna ca acela trebuie sa se afle pe prima pozitie
    {

        n++;//cresc numarul de elemente
        v=(T *)realloc(v,(n)*sizeof(T));//aloc memorie
        for(int i=n-1; i>=1; i--)
            v[i]=v[i-1];//mut elementele cu o pozitie spre dreapta
        v[0]=x;//inserez elementul
    }
    else
    {
        int st=0,dr=n-1,mij=0,poz=-1;
        while(st<=dr)
        {
            mij=(st+dr)/2;
            if(v[mij]==x)
            {
                poz=mij;
                break;
            }
            else if(v[mij]>x)
                dr=mij-1;
            else if(v[mij]<x)
                st=mij+1;
        }//folosesc cautarea binara sa vad daca elementul pe care vreau sa il inserez se mai afla in vector
        if(poz==-1)//daca nu se afla
        {
            v=(T *)realloc(v,(n+1)*sizeof(T));//aloc memorie suficienta
            for(int i=0; i<n; i++)//caut pozitia pe care trebuie inserat
                if(v[i]>x)
                {
                    ok=0;
                    poz=i;
                    break;
                }
            if(ok==1)//elementul trebuie inserat la final
            {
                v[n]=x;//inserez elementul
                n++;//cresc numarul de elemente
            }
            else
            {
                n++;
                for(int i=n-1; i>poz; i--)//altfel mut elementele cu o pozitie spre dreapta pana pozitia pe care vreau sa inserez
                    v[i]=v[i-1];
                v[poz]=x;//inserez elementul pe pozitia determinata
            }
        }
        else
            return;

    }

}
template <class T>
void Set<T>::stergere(T numar)//are complexitate O(n)
{
    int st=0,dr=n-1,mij=0,poz=-1;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(v[mij]==numar)
        {
            poz=mij;
            break;
        }
        else if(v[mij]>numar)
            dr=mij-1;
        else if(v[mij]<numar)
            st=mij+1;
    }//verfic daca elementul pe care vreau sa il inserez se afla in vector
    if(poz==-1)
        return;
    else
    {
        for(int i=poz; i<n-1; i++)
            v[i]=v[i+1];//mut elementele de la cu o pozitie spre stanga,astfel sterg elementul de pe pozitia poz
        v=(T *)realloc(v,(n-1)*sizeof(T));//realoc v
        n--;//scad numarul de elemente
    }
}
template <class T>
int Set<T>::numarelemente()
{
    return n;
}
template <class T>
T Set<T>::sumaelemente()
{
    T s=0;
    for(int i=0; i<n; i++)//suma elementelor din vector
        s=s+v[i];
    return s;
}
template <class T>
T *Set<T>::elementepare()
{
    T *pare=NULL;
    int nr=1;
    for(int i=0; i<n; i++)
    {
        if(v[i]%2==0)//determin daca v[i] este par
        {
            pare=(T *)realloc(pare,(nr+1)*sizeof(T));//aloc memorie
            pare[nr]=v[i];//il pun in vector
            nr++;//cresc numarul de elemente pare
        }
    }
    pare[0]=nr-1;//salvez in pare[0] cate elemente pare am gasit
    return pare;//returnez vectorul care contine elemente pare
}
template <class T>
T *Set<T>::elementeimpare()
{
    T *impare=NULL;
    int nr1=1;
    for(int i=0; i<n; i++)
    {
        if(v[i]%2==1)//determin daca v[i] este impar
        {
            impare=(T *)realloc(impare,(nr1+1)*sizeof(T));//aloc memorie
            impare[nr1]=v[i];//il pun in vector
            nr1++;//cresc numarul de elemente impare
        }
    }
    impare[0]=nr1-1;//salvez in impare[0] cate elemente impare am gasit
    return impare;//returnez vectorul care contine elemente impare

}
template <class T>
T &Set<T>::operator[](int i)
{
    return this->v[i];
}
template <class T>
int Set<T>::operator>(Set<T>o1)
{
    if(this->n>o1.n)
        return 1;
    else
        return 0;
}
template <class T>
int Set<T>::operator<(Set<T>o1)
{
    if(this->n<o1.n)
        return 1;
    else
        return 0;
}
template <class T>
Set<T> Set<T>::operator=(const Set<T> &o1)
{
    free(v);//eliberez v
    this->v=(T *)malloc(o1.n*sizeof(T));//aloc memorie
    this->n=o1.n;//this->n ia valoarea lui o1.n
    for(int i=0; i<o1.n; i++)
        this->v[i]=o1.v[i];//copiez in this->v[i] pe o1.v[i]
    return *this;//returnez *this

}
template <class T>
Set<T> operator+(const Set<T> &o1,const Set<T> &o2)//folosesc interclasarea pentru a obtine reuninea a doua multimi care are complexitate O(n1+m)
{
    Set<T> temp;
    int n1=o1.n,m=o2.n,i=0,j=0,nr=0;
    while(i<n1 && j<m)
    {
        if(o1.v[i]<o2.v[j])
        {
            temp.v=(T *)realloc(temp.v,(nr+1)*sizeof(T));
            temp.v[nr]=o1.v[i];
            nr++;
            i++;
        }
        else if(o1.v[i]>o2.v[j])
        {
            temp.v=(T *)realloc(temp.v,(nr+1)*sizeof(T));
            temp.v[nr]=o2.v[j];
            nr++;
            j++;
        }
        else if(o1.v[i]==o2.v[j])
        {
            temp.v=(T *)realloc(temp.v,(nr+1)*sizeof(T));
            temp.v[nr]=o2.v[j];
            nr++;
            i++;
            j++;
        }
    }

    if(i<n1)//daca raman cu elemente le copiez
    {
        for(int l=i; l<n1; l++)
        {
            temp.v=(T *)realloc(temp.v,(nr+1)*sizeof(T));
            temp.v[nr]=o1.v[l];
            nr++;
        }
    }
    if(j<m)//daca raman cu elemente le copiez
    {
        for(int l=j; l<m; l++)
        {
            temp.v=(T *)realloc(temp.v,(nr+1)*sizeof(T));
            temp.v[nr]=o2.v[l];
            nr++;
        }
    }
    temp.n=nr;
    return temp;//returnez temp
}
template <class T>
Set<T> operator*(const Set<T> &o1,int val)
{
    Set<T> temp;
    temp.v=(T*)malloc(o1.n*sizeof(T));//aloc memorie
    temp.n=o1.n;
    for(int i=0; i<o1.n; i++)
        temp.v[i]=o1.v[i]*val;//inmultesc o1.v[i] cu val si o pun in temp.v[i]
    return temp;
}
template <class T>
istream &operator>>(istream &in,Set<T> &s)
{
    in>>s.n;//citesc numarul de elemente ale obiectului s
    s.v=(T *)malloc(s.n*sizeof(T));//aloc memorie
    for(int i=0; i<s.n; i++)
        in>>s.v[i];//citesc elementele din multimea obiectului s
    return in;
}
template <class T>
ostream &operator<<(ostream &out,Set<T> &s)
{
    for(int i=0; i<s.n; i++)
        out<<s.v[i]<<" ";//afisez elementele din multimea obiectului s
    return out;
}
template <class T>
Set<T>::~Set()
{
    if(v!=NULL)
        free(v);
    n=0;
}
