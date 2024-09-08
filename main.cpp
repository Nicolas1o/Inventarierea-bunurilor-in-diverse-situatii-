#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
using namespace std;
struct sac{
    int nrsac;
    int nrsacob;
    char nume[151][201];

}saci[151],n,n3;

struct cutie{
    int nrcuti;
    int nrcutiob;
    char nume[151][201];
}v[151],n1,n4;
int x=0;
int x1=0;
int nsac=0;
int ncutie=0;
int nrtotobcuti=0;
int nrtotobsac=0;
int sumatotob=0;
int memVec[6];
void meniu();
void meniu1();
void memoryEle();
bool ok11=1,ok22=1,ok33=1;
void saveStruct(cutie v[], int size) {
    ofstream outFile("cutief.txt", ios::trunc); // Deschidere în mod append
    if (outFile.is_open()) {
        for (int i = 1; i <= size; ++i) { // Am schimbat de la 1 la 0
            if (v[i].nrcuti != 0) { // Salvăm doar cutiile existente
                outFile << v[i].nrcuti << endl;
                outFile << v[i].nrcutiob << endl;
                for (int j = 1; j <= v[i].nrcutiob; ++j) {
                    outFile << v[i].nume[j] << endl;
                }
            }
        }
        outFile.close();
    } else {
        cerr << "Nu se poate deschide fișierul pentru scriere!" << endl;
    }
}

void saveStructS(sac saci[], int size) {
    ofstream outFileS("sacf.txt", ios::trunc); // Deschidere în mod append
    if (outFileS.is_open()) {
        for (int i = 1; i <= size; ++i) {
            if (saci[i].nrsac != 0) {
                outFileS << saci[i].nrsac << endl;
                outFileS << saci[i].nrsacob << endl;
                for (int j = 1; j <= saci[i].nrsacob; ++j) {
                    outFileS << saci[i].nume[j] << endl;
                }
            }
        }
        outFileS.close();
    } else {
        cerr << "Nu se poate deschide fișierul pentru scriere!!" << endl;
    }
}

void readStruct(const string& cutief, cutie v[], int &size) {
    ifstream inFile(cutief);
    if (inFile.is_open()) {
        int i = 1;
        while (inFile >> v[i].nrcuti) {
            inFile >> v[i].nrcutiob;
            inFile.ignore(); // Ignorăm caracterul newline rămas
            for (int j = 1; j <= v[i].nrcutiob; ++j) {
                inFile.getline(v[i].nume[j], 200);
            }
            i++;
        }
        size = i; // Setăm dimensiunea actuală a vectorului
        inFile.close();
    } else {
        cerr << "Nu se poate deschide fișierul pentru citire!" << endl;
    }
}

void readStructS(const string& sacf, sac saci[], int &size) {
    ifstream inFile(sacf);
    if (inFile.is_open()) {
        int i = 1;
        while (inFile >> saci[i].nrsac) {
            inFile >> saci[i].nrsacob;
            inFile.ignore(); // Ignorăm caracterul newline rămas
            for (int j = 1; j <= saci[i].nrsacob; ++j) {
                inFile.getline(saci[i].nume[j], 200);
            }
            i++;
        }
        size = i; // Setăm dimensiunea actuală a vectorului
        inFile.close();
    } else {
        cerr << "Nu se poate deschide fișierul pentru citire!" << endl;
    }
}

void adaugare(char *introdu)
{    cout<<"Tot ce trebuie sa faci e sa spui Da sau Nu"<<"\n";
     cin>>introdu;
}
void adaugare1()
{ cout<<"Adauga numarul sacilor(maxim 60,numere pozitive): "<<"\n";
    cin>>n.nrsac;
}
void adaugare2()
{
    cout<<"Adauga numarul cutiilor(maxim 60,numere pozitive): "<<"\n";
    cin>>n1.nrcuti;
}
void stergeCutie(int index) {
    if (index < 1 || index > ncutie ||v[index].nrcuti == 0  ) {
        cout << "Index invalid sau cutie inexistenta.\n";
        return;
    }
    memVec[2]--;
    memVec[4]=memVec[4]-v[index].nrcutiob;
    memVec[5]=memVec[5]-v[index].nrcutiob;
    v[index].nrcuti = 0; // Marcam cutia ca fiind ștearsă
    cout << "Cutia cu numarul " << index << " a fost stearsa.\n";
    memoryEle();
    saveStruct(v,ncutie+1);

}
void stergeSac(int index) {
    if (index < 1 || index >nsac || saci[index].nrsac == 0 ) {
        cout << "Index invalid sau sac inexistent.\n";
        return;
    }
    memVec[1]--;
    memVec[3]=memVec[3]-saci[index].nrsacob;
    memVec[5]=memVec[5]-saci[index].nrsacob;
    saci[index].nrsac = 0; // Marcam sacul ca fiind șters
    cout << "Sacul cu numarul " << index << " a fost sters.\n";

    memoryEle();
    saveStructS(saci, nsac + 1);

}
void afiseazaCutie(int index) {

    if (index < 1 || index > ncutie  || v[index].nrcuti == 0) {
        cout << "Index invalid sau cutie inexistenta.\n";
        return;
    }

    cout << "Cutia cu numarul " << v[index].nrcuti << " contine:\n";
    cout << "Numar de obiecte: " << v[index].nrcutiob << "\n";
    for (int i = 1; i <= v[index].nrcutiob; ++i) {
        cout << "- " << v[index].nume[i] << "\n";
    }
}
void afiseazaSac(int index) {

    if (index < 1 || index > nsac  || saci[index].nrsac == 0) {
        cout << "Index invalid sau sac inexistent.\n";
        return;
    }

    cout << "Sacul cu numarul " << saci[index].nrsac << " contine:\n";
    cout << "Numar de obiecte: " << saci[index].nrsacob<< "\n";
    for (int i = 1; i <= saci[index].nrsacob; ++i) {
        cout << "- " << saci[index].nume[i] << "\n";
    }
}

void adaugaresacisicutii() {
    int s;
    int a, b;
    int ok1 = 0;
        cout << "Introdu\n1.Sac\n2.Cutie" << "\n";
        cin >> s;

        if (s == 2) {
            ok1 = 1;
        } else if (s == 1) {
            ok1 = 2;
        }
        if (ok1 == 1) {
            cout << "Am adaugat o cutie: ";
            x++;
            v[x].nrcuti = x;
            ncutie=x;
            memVec[2]=ncutie;
            cout << "Cutia cu numarul " << v[x].nrcuti << "\n";
            cout << "Adauga numarul de obiecte: " << "\n";
                cin >> v[x].nrcutiob;

                if (v[x].nrcutiob < 1 || v[x].nrcutiob > 60) {
                    cout << "Pentru cutia cu numarul " << v[x].nrcuti<< " Introdu numarul de obiecte intre 1 si 60" << "\n";
                    adaugaresacisicutii();
                } else {
                     nrtotobcuti=nrtotobcuti+v[x].nrcutiob;
                     sumatotob=sumatotob+v[x].nrcutiob;
                      memVec[4]=nrtotobcuti;
                     memVec[5]=sumatotob;
                       memoryEle();
                    cout << "Cutia cu numarul " << v[x].nrcuti << " are " << v[x].nrcutiob << " obiecte" << "\n";
                    cout << "Si contine(introdu fiecare obiect cu enter): " << "\n";
                    cin.get();
                    for (int j = 1; j <= v[x].nrcutiob; ++j) {
                        cin.getline(v[x].nume[j], 150);
                    }
                }
        }else if(ok1==2)
        { cout << "Am adaugat un sac: ";
            x1++;
            saci[x1].nrsac = x1;
            nsac=x1;
            memVec[1]=nsac;
            cout << "Sacul cu numarul " << saci[x1].nrsac << "\n";
            cout << "Adauga numarul de obiecte: " << "\n";
            bool ok3=1;
                cin >> saci[x1].nrsacob;

                if (saci[x1].nrsacob < 1 || saci[x1].nrsacob > 60) {
                    cout << "Pentru sacul cu numarul " << saci[x1].nrsac<< " Introdu numarul de obiecte intre 1 si 60" << "\n";
                    adaugaresacisicutii();
                } else {
                      nrtotobsac=nrtotobsac+saci[x1].nrsacob;
                      sumatotob=sumatotob+saci[x1].nrsacob;
                       memVec[3]=nrtotobsac;
                     memVec[5]=sumatotob;
                     memoryEle();
                    cout << "Sacul cu numarul " << saci[x1].nrsac << " are " << saci[x1].nrsacob << " obiecte" << "\n";
                    cout << "Si contine(introdu fiecare obiect cu enter): " << "\n";
                    cin.get();
                    for (int j = 1; j <= saci[x1].nrsacob; ++j) {
                        cin.getline(saci[x1].nume[j], 150);
                    }
                }
        }

        cout << "Daca vrei sa adaugi apasa\n 1.Cutie sau Sac\n 2.Meniu secundar\n 3.Salveaza\n 4.meniu principal" << "\n";
        cin >> a;
        if (a == 1) {
            adaugaresacisicutii();
        } else if (a == 2) {
            meniu1();
        } else if (a == 3) {
            cout<<"1.Cutie sau 2.Sac?\n";
             int select;
            cin>>select;
            if(select==1)
            {
            saveStruct(v, ncutie);
            }
            else if(select==2){
             saveStructS(saci,nsac);
             }
            cout << "Salvat\n";

        }else if(a==4)
        {
            meniu();
        }

}

void adaugarecutii()
{
     adaugare2();

    if(n1.nrcuti<1 || n1.nrcuti>60)
    {
        adaugare2();

    }else if(n1.nrcuti>0 && n1.nrcuti<61)
    {
         ncutie=n1.nrcuti;
         memVec[2]=ncutie;
        for(int i=1;i<=n1.nrcuti;++i)
        {
        v[i].nrcuti=i;

         cout<<"Introdu numarul obiectelor(maxim 60,numere pozitive) pentru cutia cu numarul "<<v[i].nrcuti<<":\n";
          cin>>v[i].nrcutiob;
          nrtotobcuti=nrtotobcuti+v[i].nrcutiob;
          sumatotob=sumatotob+v[i].nrcutiob;
          memVec[4]=nrtotobcuti;
          memVec[5]=sumatotob;
           memoryEle();
         if(v[i].nrcutiob<1 || v[i].nrcutiob>60){
             cout<<"Pentru cutia cu numarul "<<v[i].nrcuti<<" Introdu numarul de obiecte intre 1 si 60\n";
             adaugarecutii();
         }else if(v[i].nrcutiob>0 && v[i].nrcutiob<61){
        cout<<"Cutia cu numarul "<<v[i].nrcuti<<" are "<<v[i].nrcutiob<<" obiecte\n";
            cout<<"Si contine(introdu fiecare obiect cu enter): \n";
            cin.get();
            for(int j=1;j<=v[i].nrcutiob;++j)
            {
                cin.getline(v[i].nume[j],150);
            }
         }
        }
        }
cout<<"Vrei sa salvezi(apasa 1 sau 2.Meniu)?\n";
int l;
cin>>l;
if(l==1)
saveStruct(v, ncutie);
else if(l==2)
    meniu();
}
void adaugaresaci()
{
     adaugare1();

    if(n.nrsac<1 || n.nrsac>60)
    {
        adaugare1();

    }else if(n.nrsac>0 && n.nrsac<61)
    {
        nsac=n.nrsac;
        memVec[1]=nsac;
        for(int i=1;i<=n.nrsac;++i)
        {
        saci[i].nrsac=i;
         cout<<"Introdu numarul obiectelor(maxim 60,numere pozitive) pentru sacul cu numarul "<<saci[i].nrsac<<":\n";
          cin>>saci[i].nrsacob;
          nrtotobsac=nrtotobsac+saci[i].nrsacob;
          sumatotob=sumatotob+saci[i].nrsacob;
          memVec[3]=nrtotobsac;
          memVec[5]=sumatotob;
         memoryEle();

         if(saci[i].nrsacob<1 || saci[i].nrsacob>60){
             cout<<"Pentru sacul cu numarul "<<saci[i].nrsac<<" Introdu numarul de obiecte intre 1 si 60"<<"\n";
               adaugaresaci();
         }else if(saci[i].nrsacob>0 && saci[i].nrsacob<61){

        cout<<"Sacul cu numarul "<<saci[i].nrsac<<" are "<<saci[i].nrsacob<<" obiecte\n";
            cout<<"Si contine(introdu fiecare obiect cu enter): \n";
            cin.get();
            for(int j=1;j<=saci[i].nrsacob;++j)
            {
                cin.getline(saci[i].nume[j],200);
            }
         }
        }
        }
cout<<"Vrei sa salvezi(apasa 1 sau 2.Meniu)?\n";
int l;
cin>>l;
if(l==1){
saveStructS(saci,nsac);
}
else if(l==2){
    meniu();
}
}
void reset()
{

   for(int i=1;i<=memVec[1];i++)
    {
        saci[i].nrsac=0;
    }
   for(int i=1;i<=memVec[1];i++)
    {
        for(int j=1;j<=saci[i].nrsacob;j++)
        {
            strcpy(saci[i].nume[j], "");
        }
        saci[i].nrsacob=0;

    }

    memVec[1]=0;
    memVec[3]=0;

   for(int i=1;i<=memVec[2];i++)
   {
       v[i].nrcuti=0;
   }
   for(int i=1;i<=memVec[2];i++)
   {

       for(int j=1;j<=v[i].nrcutiob;j++)
       {
           strcpy(v[i].nume[j], "");
       }
       v[i].nrcutiob=0;
   }
   memVec[2]=0;
   memVec[4]=0;
   memVec[5]=0;
   saveStructS(saci,nsac);
   saveStruct(v, ncutie);
   memoryEle();
}
void memoryEle()
{ofstream outF("memory.txt", ios::trunc);
if (outF.is_open()) {
   outF<<memVec[1]<<endl;
   outF<<memVec[2]<<endl;
    outF<<memVec[3]<<endl;
    outF<<memVec[4]<<endl;
   outF<<memVec[5]<<endl;
    outF.close();
}else
{ cerr << "Nu se poate deschide fișierul pentru scriere!" << endl;
}
}
void readEle()
{ifstream inF("memory.txt");
 if (inF.is_open()) {
    inF>>memVec[1];
     inF>>memVec[2];
    inF>>memVec[3];
    inF>>memVec[4];
    inF>>memVec[5];
  inF.close();
    } else {
        cerr << "Nu se poate deschide fișierul pentru citire!" << endl;
    }
}
void memoryBool()
{
    ofstream fout("memoryB.txt",ios::trunc);
    if (fout.is_open()){
            fout<<ok11<<endl;
            fout<<ok22<<endl;
            fout<<ok33<<endl;
     fout.close();
}else
{ cerr << "Nu se poate deschide fișierul pentru scriere!" << endl;
}
}
 void readBool()
 {ifstream fin("memoryB.txt");
 if (fin.is_open()) {
     fin>>ok11;
     fin>>ok22;
     fin>>ok33;
     fin.close();
 }
 else
 {
     cerr<<"Nu se pote deschide fisierul pentru scriere!\n";
 }
 }
void meniu1()
{   int af,st,nr;
   int optiune1;
    cout<<"Apasa\n1.Afiseaza\n2.Sterge\n3.Meniu principal\n";
    cin>>optiune1;
    if(optiune1==1)
    {

            cout<<"1.Cutie sau 2.Sac?\n";
            cin>>af;

            if(af==1){
            cout<<"Introdu nr pe care vrei sa-l afisezi\n";
            cin>>nr;
            afiseazaCutie(nr);
            meniu1();
            }
            else if(af==2)
            {
           cout<<"Introdu nr pe care vrei sa-l afisezi\n";
            cin>>nr;
            afiseazaSac(nr);
            meniu1();
            }


    }
 else if(optiune1==2){
            cout<<"1.Cutie sau 2.Sac?\n";
            cin>>st;
            cout<<"Introdu nr pe care vrei sa-l stergi\n";
            cin>>nr;
            if(st==1){
            stergeCutie(nr);
            st=0;
            meniu1();
            }
            else if(st==2)
            {
             stergeSac(nr);
             st=0;
             meniu1();
            }



    }
 else if(optiune1==3){
            meniu();

    }


}

void meniu()
{
int optiune;
        cout << "Meniu principal:\n";
        cout << "1. Adauga saci si cutii\n";
        cout<< "2. Adauga toti sacii toate cutiile\n";
        cout<< "3. Adauga toate cutiile toti sacii\n";
        cout<<"4.Meniu secundar\n";
        cout<<"5.Afiseaza numarul de saci si cutii existenti\n";
        cout <<"6.Iesire\n";
        cout<<"7.Reset\n";
        cout << "Alege o optiune: \n";
        cin >> optiune;
        cin.ignore(); // Ignorăm newline pentru eventuale getline-uri


            if(optiune==1 && ok11==1){
                adaugaresacisicutii();
               ok11=1;
               ok22=0;
               ok33=0;
               memoryBool();
                meniu();
            }
             else if(optiune==1 && ok11==0)
            {
                cout<<"Trebuie sa dai reset ca sa ai acces\n";
                meniu();
            }
            if(optiune==2 && ok22==1)
                {ok22=0;
                 ok11=0;
                 ok33=0;
                 memoryBool();
                adaugaresaci();
  //saveStructS(saci,nsac);
          adaugarecutii();
    //      saveStruct(v, ncutie);
          meniu();

            }
             else if(optiune==2 && ok22==0){
                cout<<"Trebuie sa dai reset ca sa ai acces\n";
                meniu();
            }
             if(optiune==3 && ok33==1)
                {ok33=0;
                 ok22=0;
                 ok11=0;
                 memoryBool();
                adaugarecutii();
        adaugaresaci();
        meniu();
}
        else if(optiune==3 && ok33==0){
    cout<<"Trebuie sa dai reset ca sa ai acces\n";
    meniu();
}
            if(optiune==4){
                meniu1();
            }

            if(optiune==5){

                cout<<"Numarul de saci: \n";
                cout<<memVec[1];
                cout<<"\n";
                cout<<"Numarul de cutii: \n";
                cout<<memVec[2];
                cout<<"\n";
                cout<<"Numar total obiecte sac: \n";
                cout<<memVec[3]<<"\n";
                cout<<"Numar total obiecte cutii: \n";
                cout<<memVec[4]<<"\n";
                cout<<"Numar total obiecte: \n";
                cout<<memVec[5]<<"\n";
                meniu();

            }
            if(optiune==6){

                cout << "Iesire...\n";


            }
            if(optiune==7)
            {  cout<<"Resetat\n";
                reset();
                ok11=1;
                ok22=1;
                ok33=1;
                memoryBool();
                meniu();
            }
            if(optiune<1){
                cout << "Opțiune invalidă. Încearcă din nou.\n";
                meniu();

        }
        if(optiune>7){
                cout << "Opțiune invalidă. Încearcă din nou.\n";
                meniu();

        }

}
const char* response_file = "response.txt";

bool as=1;

void saveResponse(const char* response) {
    ofstream outFileDN(response_file);
    if (outFileDN.is_open()) {
        outFileDN << response;
        outFileDN.close();
    } else {
        cerr << "Nu se poate deschide fișierul pentru scriere!" << endl;
    }
}

bool readResponse(char* response, size_t size) {
    ifstream inFileDN(response_file);
    if (inFileDN.is_open()) {
        inFileDN.getline(response, size);
        inFileDN.close();
        return true;
    }
    return false;
}
void Sascunde()
{ofstream salv("asc.txt",ios::trunc);
  salv<<as;

}
void Reascunde()
{
    ifstream salvi("asc.txt");
    salvi>>as;
}
int main()
{
      as=1;

     readStruct("cutief.txt", v, ncutie);
    readStructS("sacf.txt", saci, nsac);
    readEle();
    readBool();
    Reascunde();
      char introdu[20];
    if(as==1){
    cout<<"Bine ai venit"<<"\n";
    cout<<"Vrei sa te muti si sa iti impachetezi lucrurile in saci si cutii(tasteaza Da sau Nu)?"<<"\n";

    }

    char vreau[3]="Da";
    char nuvreau[3]="Nu";




    bool ok2=1;
    if (readResponse(introdu, sizeof(introdu))){
    if(strcmp(introdu,vreau)==0)
    {   as=0;
        Sascunde();

        ok2=0;
        cout<<"Ma bucur ca ai un interes pentru a te organiza si ma bucur sa te ajut"<<"\n";
        cout<<"Exista  mai multe optiuni de a adauga saci  si cuti si obiecte la ele depinde de tine cum te organizezi"<<"\n";
        cout<<"Daca doresti simultan toti saci si toate cutiile(te poti intoarce in meniul principal si va trebui sa incepi de la inceput(inseamna ca trebuie sa sti ce sunt in saci si cuti)"<<"\n";
        cout<<"A doua optiune este la fel ca prima doar ca invers cutiile prima data apoi sacii";
        cout<<"A treia optiune nu conteaza ce adaugi sac sau cutie"<<"\n";

        meniu();
        return 0;
    }

    }
     while (ok2) {
        cin >> introdu;
        if (strcmp(introdu, vreau) == 0) {

                as=0;
                Sascunde();
            ok2 = 0;
            saveResponse(introdu); // Salvăm răspunsul utilizatorului

            cout << "Ma bucur ca ai un interes pentru a te organiza si ma bucur sa te ajut" << "\n";
            cout << "Exista  mai multe optiuni de a adauga saci  si cutii si obiecte la ele depinde de tine cum te organizezi" << "\n";
            cout << "Daca doresti simultan toti sacii si toate cutiile (te poti intoarce in meniul principal si va trebui sa incepi de la inceput, inseamna ca trebuie sa sti ce sunt in saci si cutii)" << "\n";
            cout << "A doua optiune este la fel ca prima doar ca invers cutiile prima data apoi sacii" << "\n";
            cout << "A treia optiune nu conteaza ce adaugi sac sau cutie" << "\n";

            meniu();
        } else if (strcmp(introdu, nuvreau) == 0) {
            ok2 = 0;
            saveResponse(introdu); // Salvăm răspunsul utilizatorului
            cout << "E in regula poate data viitoare" << "\n";
            as=1;
            Sascunde();
        } else {
            cout << "Introdu un raspuns valid (Da sau Nu): " << "\n";
            ok2 = 1;
        }
    }


    return 0;
}
