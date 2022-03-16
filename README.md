FUNCTIONALITATI:
bool are_profit() - returneaza daca o librarie are profit pe luna
double are_carte(string) - returneaza daca -1 daca cartea al carei titlu a fost transmis ca parametru sau pretul acesteia daca aceasta este in librarie
double cat_cheltuie_un_client() - returneaza cat cheltuie un client (incasarile supra nr de clienti/ sunt calculate la luna)
bool vreau_sa_cumpar_libraria(double,double&) - cineva vine cu o suma de bani (primul argument) si doreste sa cumpere libraria . Al doilea argument reprezinta valoare librariei care este initial 0, aceasta va fi calculata in functie. Valoarea librariei se calculeaza astfel: se aduna pretul fiecarei carti din librarie, salariile angajatiilor (un angajat castiga 3500 de lei) si se mareste valoarea cu in functie de anul infiintarii(cu cat este mai veche, cu atat mai scumpa). Daca persoana are suficienti bani pentru a plati valoare librariei returnam true daca nu are, false.
bool pot_sa_intretin_libraria(double suma_de_bani)- se verifica, in primul rand daca persoana are banii necesari sa cumpere libraria (suma_de_bani) daca o are, valoarea librarie se indexeaza la inflatie si se aduna cheltuieliile pentru 12 luni. Daca are indeajunsi bani returnam true daca nu false.
functia cat_costa este o functie getter
operatorul:
+ reprezinta unirea a doua librarii
- reprezinta plecare unei librarii din libraria de baza
(librariile aici sunt vazute ca afaceri)
+= reprezinta adaugarea unui numar de carti la biblioteca librariei, crescand astfel incasarile dar si cheltuielile si clientii
-= reprezinta fix in opusul lui += in sensul ca libraria vinde un nr de carti(transmis ca parametru)
== si != reprezinta o comparatie intre 2 libarii
Pentru citire se introduc toate datele membre cu exceptia vectorului de carti pentru librarie si editura 
pentru clasa carte
Libraria are vector de tip carte ce reprezinta biblioteca acesteia iar clasa carte are Editura de tip editura.
