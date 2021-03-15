#include <iostream>
#include <cstdlib>  //losowanie wartosci wpisywanych do tablicy
#include <time.h>
#include <windows.h> //system cls

using namespace std;


//funkcje z laboratorium 1
void przydzielPamiec1D(int *&tab, int n){   tab = new int[n];   }
void przydzielPamiec2D(int **&tab, int w, int k)
{   tab= new int*[w];
    for(int x=0;x<w;x++){  tab[x]=new int[k];  }}

void wypelnijTablice1D(int *tab, int n, int a, int b){
    srand (time(NULL));
    for(int x=0;x<n;x++){
        tab[x]=rand()%(b-a+1)+a;// liczby z zakresu <a,b>
}}
void wypelnijTablice2D(int **tab, int w, int k, int a, int b){
    srand (time(NULL));
    for(int x=0;x<w;x++){
        for(int y=0;y<k;y++){
            tab[x][y]=rand()%(b-a+1)+a;// liczby z zakresu <a,b>
}}}

void usunTablice1D(int *&tab){  delete[] tab;   }
void usunTablice2D(int **&tab, int w){
    for(int x=0;x<w;x++){    delete[] tab[x];}
    delete[] tab;
}

void wyswietl1D(int* tab, int n){
    for(int x=0;x<n;x++){
        cout<<tab[x]<<" ";
}}
void wyswietl2D(int** tab, int w, int k){
    for(int x=0;x<w;x++){
        for(int y=0;y<k;y++){
            cout<<tab[x][y]<<" ";
    }cout<<endl;}}

void menu(){
cout<<endl<<"Menu:"<<endl;
cout<<"1. zadanie 2.2 (Sortowanie babelkowe)"<<endl;
cout<<"2. zadanie 2.3 (Sortowanie przez wybor)"<<endl;
cout<<"3. zadanie 2.4 (Sortowanie przez wstawianie)"<<endl;
cout<<"4. zadanie 2.5 (Sortowanie babelkowe 2D)"<<endl;
cout<<"5. wyjscie z programu"<<endl;
cout<<"Wybieram:";
}
void line(){cout<<"----------------------------------------------------";}
void lineD(){cout<<"===================================================";}


//funkcje z laboratorium 2
void sortowanieBabelkowe(int* tab, int n, int tryb){
    line();
    cout<<endl<<"Sortowanie babelkowe"<<endl;
    cout<<"Przed posortowaniem:";
    wyswietl1D(tab,n);//wyswietlic tablice przed sortowaniem
    if(tryb==0){    //malejaco
        for(int a=n-1;a>=0;a--){
            for(int b=0;b<n-1;b++){
                if(tab[b]<tab[b+1]){
                    swap(tab[b],tab[b+1]);
                }
            }
        }
    }
    else if(tryb==1){   //rosnaco
        for(int a=n-1;a>=0;a--){
            for(int b=0;b<n-1;b++){
                if(tab[b]>tab[b+1]){
                    swap(tab[b],tab[b+1]);
                }
            }
        }
    }
    cout<<endl<<"Po posortowaniu:";
    wyswietl1D(tab,n);//wyswietlic po sortowaniu
    cout<<endl;
}
void sortowaniePrzezWybor(int* tab, int n, int tryb){
    line();
    cout<<endl<<"Sortowanie przez wybor"<<endl;
    cout<<"Przed sortowaniem:";
    wyswietl1D(tab,n);  //wyswietlenie przed sortowaniem

    if(tryb==0){    //malejaco
        int minIndex;   //indeks na którym le¿y najmniejsza wartoœæ
        for(int a=0;a<n-1;a++){
            minIndex=a;
            for(int b=a+1;b<n;b++){ //petla wyszukujaca element najmniejszy w podzbiorze nieposortowanym
                if(tab[minIndex]>tab[b]){
                    minIndex=b;
            }}
            swap(tab[a],tab[minIndex]); //zamiana elementu najmniejszego ze zbioru posortwanego z najmniejszym z nieposortowanego
    }}
    else if(tryb==1){   //rosnaco
        int maxIndex;
        for(int a=0;a<n-1;a++){
            maxIndex=a;
            for(int b=a+1;b<n;b++){
                if(tab[b]>tab[maxIndex]){
                    maxIndex=b;

            }}
            swap(tab[a],tab[maxIndex]);
    }}
    cout<<endl<<"Po sortowaniu:";
    wyswietl1D(tab,n);
    cout<<endl;
}
void sortowaniePrzezWstawienie(int* tab, int n, int tryb){
    line();
    cout<<endl<<"Sortowanie przez wybor"<<endl;
    cout<<"Przed sortowaniem";
    wyswietl1D(tab,n);  //wyswietlenie przed sortowaniem

    if(tryb==0){
        int tmp,b;
        for(int a=1;a<n;a++){
            tmp=tab[a];
            b=a-1;

            while(b>=0 && tab[b]>tmp){
                tab[b+1]=tab[b];
                --b;
            }
            tab[b+1]=tmp;
        }
    }
    else if(tryb==1){
        int tmp,b;
        for(int a=1;a<n;a++){
            tmp=tab[a];
            b=a-1;

            while(b>=0 && tab[b]<tmp){
                tab[b+1]=tab[b];
                --b;
            }
            tab[b+1]=tmp;
        }
    }

    cout<<endl<<"Po sortowaniu:";
    wyswietl1D(tab,n);
    cout<<endl;
}
void sortowanieBabelkowe2D(int** tab, int w, int k, int tryb, int nrKol){
    line();
    cout<<endl<<"Sortowanie babelkowe 2D"<<endl;
    cout<<"Przed sortowaniem:"<<endl;
    wyswietl2D(tab,w,k);
    nrKol=nrKol-1;
    if(tryb==0){    //malejaco
            for(int a=0;a<w;a++){
                for(int b=0;b<w-1;b++){
                    if(tab[b][nrKol]<tab[b+1][nrKol]){
                        swap(tab[b],tab[b+1]);
    }}}}
    else if(tryb==1){   //rosnaco
            for(int a=0;a<w;a++){
                for(int b=0;b<w-1;b++){
                    if(tab[b][nrKol]>tab[b+1][nrKol]){
                        swap(tab[b],tab[b+1]);
    }}}}

    //1 rosnoco

    cout<<endl<<"Po sortowaniu:"<<endl;
    wyswietl2D(tab,w,k);
}


int main()
{
    line();
    //przydzielenie pamieci tablicy jednowymiarowej
    cout<<endl<<"Deklaracja tablicy jednowymiarowej:"<<endl;
    cout<<"Podaj ilosc komorek tablicy jednowymiarowej:";
    int a;
    cin>>a;
    int* tab1 = new int;
    przydzielPamiec1D(tab1,a);

    line();
    //przydzielenie pamieci tablicy dwuwymiarowej
    cout<<endl<<"Deklaracja tablicy dwuwymiarowej:"<<endl;
    int b,c;
    cout<<"Podaj ilosc wierszy:";
    cin>>b;
    cout<<"Podaj ilosc kolumn:";
    cin>>c;
    int** tab2 = nullptr;
    przydzielPamiec2D(tab2,b,c);

    lineD();
    //wypelnienie tablicy jednowymiarowej losowymi wartosciami z przedzialu
    cout<<endl<<"Wypelnienie wartosciami tablicy jednowymierowej:"<<endl;
    cout<<"Podaj przedzial z ktorego zostana wylosowane wartosci <a,b>"<<endl;
    cout<<"Podaj min:";
    int d,e;
    cin>>d;
    cout<<"Podaj max:";
    cin>>e;
    wypelnijTablice1D(tab1,a,d,e);

    line();
    //wypelnienie tablicy dwuwymiarowej losowymi wartosciami z przedzialu
    cout<<endl<<"Wypelnienie wartosciami tablicy dwuwymiarowej:"<<endl;
    cout<<"Podaj przedzial z ktorego zostana wylosowane wartosci <a,b>"<<endl;
    cout<<"Podaj min:";
    int f,g;
    cin>>f;
    cout<<"Podaj max:";
    cin>>g;
    wypelnijTablice2D(tab2,b,c,f,g);

    system("cls");  //wyczyszczenie terminala

    lineD();
    //wyswietlenie wygenerowanej tablicy jednowymiarowej
    cout<<endl<<"Wygenerowano tablice:"<<endl;
    cout<<"Jednowymiarowa:";
    wyswietl1D(tab1,a);
    cout<<endl;

    line();
    //wyswietlenie wygenerowanej tablicy dwuwymiarowej
    cout<<endl<<"Dwuwymiarowa:"<<endl;
    wyswietl2D(tab2,b,c);
    cout<<endl;
    line();



    int tryb;   //tryb sortowania uzywany w poszczegolnych case
    menu();
    int opt=0;
    cin>>opt;
    while(opt!=5){
        switch (opt)
      {
         case 1:
            cout<<"Wybierz tryb (0-malejaco,1-rosnaco):";
            cin>>tryb;
            sortowanieBabelkowe(tab1,a,tryb);
            line();
            menu();
            cin>>opt;
            break;
         case 2:
            cout<<"Wybierz tryb (1-malejaco,0-rosnaco):";
            cin>>tryb;
            sortowaniePrzezWybor(tab1,a,tryb);
            line();
            menu();
            cin>>opt;
            break;
         case 3:
            cout<<"Wybierz tryb (1-malejaco,0-rosnaco):";
            cin>>tryb;
            sortowaniePrzezWstawienie(tab1,a,tryb);
            line();
            menu();
            cin>>opt;
            break;
         case 4:
            cout<<"Wybierz tryb (0-malejaco,1-rosnaco):";
            cin>>tryb;
            int kolumna;
            cout<<"Wybierz kolumne, po ktorej ma odbyc sie sortowanie:";
            cin>>kolumna;
            sortowanieBabelkowe2D(tab2,b,c,tryb,kolumna);
            line();
            menu();
            cin>>opt;
            break;
         default:
            line();
            menu();
            cin>>opt;
      }
    }


    usunTablice1D(tab1);
    usunTablice2D(tab2,b);

    return 0;
}


