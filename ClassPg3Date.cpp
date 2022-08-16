/*  Projet
*/


#include <stdio.h>      // pour printf
#include <iostream>

using namespace std;

class DateHeure {
int jour;
int mois, annee;
int heure,minut,sec;

public:
DateHeure (int jour,int mois,int annee,int heure,int minut,int sec);
void DtHrExporteConsole(void);
//void DateHeureEcrit1(void);
int NbDeJours();
int NumDeSemaine();
};
DateHeure::DateHeure(int i_jour,int i_mois,int i_annee,int i_heure,int i_minut,int i_sec)
{
    jour=i_jour; mois=i_mois; annee=i_annee; heure=i_heure;minut=i_minut;sec=i_sec;
    return;
}
void DateHeure::DtHrExporteConsole(void)
{
    printf("%2d-%2dT%2d:%2d", jour, mois, heure, minut);
}
int DateHeure::NbDeJours()
{
    int moisprecedent=mois-1;
    int u=moisprecedent/2+moisprecedent%2;int v=moisprecedent/2;
    int partie1=u*31;int partie2;
    partie2=(v<=1 ? v*28:v*30-2);
    int resultat = partie1+partie2;
    resultat+=jour;
    return resultat;
}
int DateHeure::NumDeSemaine()
{
    DateHeure jour1sem1(2,1,2023,00,00,01);
    int n1=jour1sem1.NbDeJours();
    int n2=NbDeJours();int n=n2-n1+1;
    int resultat ; resultat = n/7+1;// num de semaine par div euclidienne par 7
    return resultat;
}
struct T_Noe {// struct de donnees pour representer un planning par chainage
    int Chiffre;
    string Nom;
    struct T_Noe* Suivant;
    };
T_Noe* InsererEnTete(T_Noe *Liste, int i, string s)
{   // insertion de I en tête de Liste (passé par valeur : pointeur Noeud)
    T_Noe* N = new T_Noe;
    N->Chiffre = i;   N->Nom = s;
    N->Suivant = Liste;             // raccrochage en queue
    return N;                       // nlle liste
}
/* Fonction insertion en queue de Liste */
InsererEnQueue(T_Noe* &Liste, int i, string s) // le param liste passé par reference
{
    T_Noe* N = new T_Noe;
    N->Chiffre = i;   N->Nom = s;
    N->Suivant = NULL;

    if (Liste == NULL)
        Liste = N;
    else {
        T_Noe *Ptr = Liste;// création d'un pointeur pour parcourir la Liste
        while (Ptr->Suivant != NULL)// parcours systématique de la Liste
            Ptr = Ptr->Suivant;
        // Ptr pointe maintenant le dernier noeud de la Liste
        Ptr->Suivant = N;
    }
}
int Longueur(T_Noe *Liste)
{   int Lg = 0;
    while (Liste != NULL) {             // noeud non vide
        Lg++;
        Liste = Liste->Suivant;         // lecture de la suite
        }
    return Lg;
}
int main()
{
    
    // test classe DateHeure
    DateHeure D0(9,2,2023,0,0,2);
    D0.DtHrExporteConsole();
    int x;
    x=D0.NbDeJours();cout << endl <<x << endl;
    x=D0.NumDeSemaine();cout << endl << "resu=" << x << endl;
   // test collection d'evenements datés (planning)
    T_Noe *Liste = NULL;
    const int N=5;
    for (int I=0; I<N; I++) Liste = InsererEnTete(Liste, I," ");

    for (int I=0; I<N; I++) InsererEnQueue(Liste, I," ");
    /* Longueur */
    cout << "La longueur de la liste est " << Longueur(Liste) << endl;

    delete Liste;

    return 0;
}
