#include <iostream>
#include <string>
#include <vector>
using namespace std;

class editura {
public:
    editura& operator=(const editura&) = default;
    editura() { denumire = "Corint"; valoare_pe_piata = 100000; }
    friend istream& operator>>(istream&, editura&);
    friend ostream& operator<<(ostream&, editura&);

private:
    string denumire;
    double valoare_pe_piata;
};



class carte {
public:
    carte();
    carte& operator=(const carte&);
    bool operator!=(carte&);
    bool operator==(carte&);
    friend istream& operator>>(istream&, carte&);
    friend ostream& operator<<(ostream&, carte&);
    string get_title();
    double cat_costa();


private:
    string titlu;
    string autor_1;
    string autor_2;
    int an_aparitie;
    int nr_pagini;
    double pret;
    editura Editura;


};


carte& carte::operator=(const carte& ob)
{
    this->titlu = ob.titlu;
    this->autor_1 = ob.autor_1;
    this->autor_2 = ob.autor_2;
    this->an_aparitie = ob.an_aparitie;
    this->nr_pagini = ob.nr_pagini;
    this->pret = ob.pret;
    this->Editura = ob.Editura;
    return (*this);
}
class librarie {
public:
    librarie();
    librarie(string, int, int, double, double, int, int);
    librarie(librarie& ob);
    ~librarie();
    librarie operator+=(int y);
    librarie operator-=(int);
    librarie operator+(librarie&);
    librarie operator-(librarie&);
    librarie& operator=(const librarie&);
    bool operator==(librarie&);
    bool operator!=(librarie&);
    friend istream& operator>>(istream&, librarie&);
    friend ostream& operator<<(ostream&, librarie&);
    void set_name(string name) { nume = name; }
    inline string get_nume() { return nume; }
    int get_angajati() { return nr_angajati; }

    ///functionalitati
    bool are_profit();
    double are_carte(string);
    double cat_cheltuie_un_client();
    bool vreau_sa_cumpar_libraria(double, double&);
    bool pot_sa_intretin_libraria(double);

private:
    string nume;
    int nr_angajati;
    int an_infiintare;
    double cheltuieli;
    double incasari;
    int clienti;
    int nr_carti;
    carte v[100];
};

carte::carte() {
    titlu = "Morometul"; autor_1 = "Mircea"; autor_2 = "Petcu";
    an_aparitie = 2022; nr_pagini = 200; pret = 25; editura e; Editura = e;
}

librarie::librarie(librarie& ob)
{
    an_infiintare = ob.an_infiintare;
    nume = ob.nume;
    cheltuieli = ob.cheltuieli;
    incasari = ob.incasari;
    clienti = ob.clienti;
    nr_angajati = ob.nr_angajati;
    nr_carti = ob.nr_carti;
    for (int i = 0; i <= ob.nr_carti; i++)
        v[i] = ob.v[i];
}


bool librarie::are_profit()
{
    double profit = incasari - cheltuieli;
    if (profit > 0)
        return true;
    return false;

}

double librarie::are_carte(string title)
{
    for (int i = 0; i < nr_carti; i++) {
        if (title == v[i].get_title())
            return v[i].cat_costa();
    }
    cout << "Nu avem cartea";
    return -1;


}
bool librarie::vreau_sa_cumpar_libraria(double suma_de_bani, double& s)
{
    for (int i = 0; i < nr_carti; i++)
        s += are_carte(v[i].get_title());
    s += nr_angajati * 3500;//un angajat este platit cu 3500 de lei
    if (an_infiintare < 1920) s *= 2;
    else if (an_infiintare < 1960) s *= 1.5;
    else if (an_infiintare < 2000) s *= 1.2;
    if (suma_de_bani >= s)
        return true;
    else
        return false;

}

bool librarie::pot_sa_intretin_libraria(double suma_de_bani)
{
    double s = 0;
    if (librarie::vreau_sa_cumpar_libraria(suma_de_bani, s) == true)
    {
        s += s * 0.045;
        s += cheltuieli * 12;
        if (s <= suma_de_bani)
            return true;
        else
            return false;

    }
    else
        return false;
}


double librarie::cat_cheltuie_un_client()
{
    double c = (double)incasari / clienti;
    return c;
}

string carte::get_title() { return titlu; }
double carte::cat_costa() { return pret; }

librarie& librarie::operator=(const librarie& ob)
{
    nume = ob.nume;
    an_infiintare = ob.an_infiintare;
    nr_angajati = ob.nr_angajati;
    cheltuieli = ob.cheltuieli;
    clienti = ob.clienti;
    nr_carti = ob.nr_carti;
    incasari = ob.incasari;
    int k = 0;
    for (int i = 0; i < ob.nr_carti; i++)
        v[k++] = ob.v[i];
    return (*this);

}
librarie::librarie() {
    nume = "Nul"; nr_angajati = 0;
    an_infiintare = 2022; cheltuieli = 100; incasari = 90;
    clienti = 2;
    nr_carti = 1;
    for (int i = 0; i < nr_carti; i++)
    {
        carte c;
        v[i] = c;
    }
}
librarie::librarie(string nm, int nr, int an, double che, double inc, int cli, int nrc)
{
    nume = nm; nr_angajati = nr;
    an_infiintare = an; cheltuieli = che; incasari = inc;
    clienti = cli;
    nr_carti = nrc;
    for (int i = 0; i < nr_carti; i++)
    {
        carte c;
        v[i] = c;
    }

}

librarie::~librarie() {
    nume = ""; nr_angajati = 0;
    an_infiintare = 0; cheltuieli = 0; incasari = 0;
    clienti = 0;
    nr_carti = 0;
}
librarie librarie::operator+=(int y)
{
    int i, j;
    if (y != 0)
    {
        vector <carte> a;
        for (i = 0; i < y; i++)
        {
            carte c;
            a.push_back(c);
        }
        if (!a.empty())
        {
            for (i = 0; i < y; i++)
                cheltuieli += 0.7 * a[i].cat_costa();
            for (i = 0; i < y; i++)
                incasari += a[i].cat_costa();
            clienti += y / 2; //cele y carti aduc y/2 in plus clienti librariei
            int x = nr_carti;
            nr_carti += y;
            j = 0;
            for (i = x; i < nr_carti; i++)
                v[i] = a[j++];
        }
        return (*this);
    }
    else
        return (*this);



}

librarie librarie::operator-=(int y)
{
    int i;
    if (y != 0)

    {
        vector <carte> a;
        for (i = 0; i < y; i++)
        {
            carte c;
            a.push_back(c);
        }
        if (!a.empty())
        {
            for (i = 0; i < y; i++)
                cheltuieli -= 0.7 * a[i].cat_costa();
            for (i = 0; i < y; i++)
                incasari -= a[i].cat_costa();
            clienti -= y / 2; //cele y carti aduc y/2 in plus clienti librariei
            int x = nr_carti;
            nr_carti -= y;
            if (nr_carti < 0)
            {
                nume = "";
                nr_angajati = 0;
                clienti = 0;
                an_infiintare = NULL;
                cheltuieli = 100000;
                incasari = 0;
            }
        }

        return (*this);
    }
    else
        return (*this);


}



librarie librarie::operator+(librarie& ob)
{
    librarie loc;
    loc.nume = nume + ob.nume;
    loc.nr_angajati = nr_angajati + ob.nr_angajati;
    loc.clienti = clienti + ob.clienti;
    loc.incasari = incasari + ob.incasari;
    loc.cheltuieli = cheltuieli + ob.cheltuieli;
    if (an_infiintare < ob.an_infiintare)
        loc.an_infiintare = an_infiintare;
    else
        loc.an_infiintare = ob.an_infiintare;
    int i;
    i = 0;
    while (i < nr_carti)
    {
        loc.v[i] = v[i];
        i++;
    }
    i = 0;
    while (i < ob.nr_carti)
    {
        loc.v[i] = ob.v[i];
        i++;
    }
    loc.nr_carti = nr_carti + ob.nr_carti;
    return loc;

}

librarie librarie::operator-(librarie& ob)
{
    librarie loc;
    loc.nume = nume;
    loc.nr_angajati = nr_angajati - ob.nr_angajati;
    loc.clienti = clienti - ob.clienti;
    loc.incasari = incasari - ob.incasari;
    loc.cheltuieli = cheltuieli - ob.cheltuieli;
    loc.an_infiintare = an_infiintare;
    int i;
    i = 0;
    while (i < nr_carti)
    {
        if (v[i] != ob.v[i])
            loc.v[i] = v[i];
        i++;
    }

    loc.nr_carti = nr_carti - ob.nr_carti;
    return loc;

}

bool librarie::operator==(librarie& ob) {
    if (nume == ob.nume && nr_angajati == ob.nr_angajati && an_infiintare == ob.an_infiintare && clienti == ob.clienti && incasari == ob.incasari && cheltuieli == ob.cheltuieli && nr_carti == ob.nr_carti)
    {
        int ok = 1;
        for (int i = 0; i < nr_carti; i++)
            if (v[i] != ob.v[i])
                ok = 0;
        if (ok) return true;
        else
            return false;
    }
    else return false;
}

bool librarie::operator!=(librarie& ob) {
    if (!(nume == ob.nume && nr_angajati == ob.nr_angajati && an_infiintare == ob.an_infiintare && clienti == ob.clienti && incasari == ob.incasari && cheltuieli == ob.cheltuieli && nr_carti == ob.nr_carti))
    {
        if (nr_carti == ob.nr_carti) {
            int ok = 0;
            for (int i = 0; i < nr_carti; i++)
                if (v[i] != ob.v[i])
                    ok = 1;
            if (ok) return true;
            else
                return false;
        }
        else
            return true;
    }
    else return false;
}

istream& operator>>(istream& in, librarie& ob)
{
    in >> ob.nume >> ob.nr_angajati >> ob.an_infiintare >> ob.clienti >> ob.incasari >> ob.cheltuieli >> ob.nr_carti;

    return in;
}

ostream& operator<<(ostream& out, librarie& ob)
{
    out << ob.nume << ' ' << ob.nr_angajati << ' ' << ob.an_infiintare << ' ' << ob.clienti << ' ' << ob.incasari << ' ' << ob.cheltuieli << ' ' << ob.nr_carti;
    out << endl;
    for (int i = 0; i < ob.nr_carti; i++)
        out << ob.v[i] << ' ';
    out << endl;
    return out;

}

bool carte::operator!=(carte& ob)
{
    if (!(titlu == ob.titlu && autor_1 == ob.autor_1 && autor_2 == ob.autor_2 && an_aparitie == ob.an_aparitie && nr_pagini == ob.nr_pagini && pret == ob.pret))
        return true;
    return false;
}

bool carte::operator==(carte& ob)
{
    if (titlu == ob.titlu && autor_1 == ob.autor_1 && autor_2 == ob.autor_2 && an_aparitie == ob.an_aparitie && nr_pagini == ob.nr_pagini && pret == ob.pret)
        return true;
    return false;
}

istream& operator>>(istream& i, carte& ob)
{
    i >> ob.titlu >> ob.autor_1 >> ob.autor_2 >> ob.an_aparitie >> ob.nr_pagini >> ob.pret;

    return i;
}

ostream& operator<<(ostream& o, carte& ob)
{
    o << ob.titlu << ' ' << ob.autor_1 << ' ' << ob.autor_2 << ' ' << ob.an_aparitie << ' ' << ob.nr_pagini << ' ' << ob.pret << ' ' << ob.Editura << endl;
    return o;
}
istream& operator>>(istream& i, editura& ob)
{
    i >> ob.denumire >> ob.valoare_pe_piata;
    return i;
}
ostream& operator<<(ostream& o, editura& ob)
{
    o << ob.denumire << ' ' << ob.valoare_pe_piata;
    return o;
}

int main() {
    cout << "se vor afisa operatorii: " << endl;
    cout << "introduceti valori pentru a citi o librarie \n";
    cout << ">>" << endl;
    librarie l4;
    cin >> l4;
    cout << "<<" << endl;
    librarie l5;
    cout << l5;
    cout << "+" << endl;
    librarie l1("Carturesi", 40, 2013, 100000.345, 200000.4567, 100, 10);
    librarie l2, l3;
    cout << "l3: " << endl;
    l3 = l1 + l2;
    cout << l3;
    cout << "-" << endl;
    cout << "l3 " << endl;
    l3 = l1 - l2;
    cout << l3;
    cout << "+=(l2)" << endl;
    l2 += 2;
    l1 -= 6;
    cout << "-=(l1)" << endl;
    cout << l2;
    cout << l1;
    cout << "== si !=" << endl;
    cout << (l1 == l2);
    cout << (l1 != l2);




    cout << "construcor parametrizat de initializare,copiere si operator de atribuire: " << endl;
    librarie l6("Carturesi", 40, 2013, 100000.345, 200000.4567, 100, 10);
    cout << "l6: " << endl;
    cout << l6;
    librarie l7 = l6;
    cout << "l7: " << endl;
    cout << l7;
    librarie l8(l6);
    cout << "l8: " << endl;
    cout << l8;
    cout << "l9: " << endl;
    librarie l9;
    cout << l9;

    librarie l10("Carturesi", 40, 2013, 100000.345, 200000.4567, 100, 10);
    string car_title;
    cout << "se cauta cartea Morometul in librarie " << endl;
    car_title = "Morometul";
    cout << l10.are_carte(car_title);
    cout << endl;

    cout << l10.are_profit();
    cout << endl;

    cout << l10.cat_cheltuie_un_client();
    cout << endl;
    double ss = 100000000;
    double sb = 0;
    cout << "Cineva vine cu suma de 100000000 lei sa cumpere si sa intretina libraria: " << endl;

    cout << l10.vreau_sa_cumpar_libraria(ss, sb);
    cout << endl;
    cout << l10.pot_sa_intretin_libraria(ss);
    cout << endl;



    cout << "constructorii si operatorii ==,!=,>>,<< si functionalitatile: " << endl;
    carte c1, c2;
    cout << ">> " << endl;
    cout << "introduceti valori pentru a citi o carte \n";
    cin >> c2;
    cout << " == si != " << endl;
    cout << (c1 == c2) << endl;
    cout << (c1 != c2) << endl;
    cout << "= " << endl;
    carte c3 = c2;
    carte c4(c2);
    cout << c3 << endl << c4 << endl;
    cout << c1.cat_costa() << endl;
    cout << c1.get_title();


    cout << "constructor,operatori de atribuire si operatori I/O: " << endl;

    editura e1, e2;
    cout << ">>" << endl;
    cin >> e2;
    cout << e1 << e2;
    editura e3 = e2;
    cout << e3;










    return 0;
}
