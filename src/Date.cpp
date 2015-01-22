#include "Date.h"

Date::Date()
{
    //cout<<"appel constructeur sans parametre"<<endl;
    time_t t;
    time(&t);
    tm date= *localtime(&t);
    jour=date.tm_mday;
    mois=date.tm_mon; //de 0 à 12  cf affichage
    annee=1900+date.tm_year;
}

Date::Date(int j,int m,int a):jour(j),mois(m),annee(a)
{   //cout<<"appel constructeur avec parametre"<<endl;
}

void Date::affiche() const
{
    string t[] = {"janvier","fevrier","mars","avril","mai","juin",
                    "juillet","aout","septembre","octobre","novembre","decembre"};

    cout<<jour<<" "<<t[mois]<<" "<<annee<<endl;
}

int Date::comparer(const Date& d) const
{
	if (annee!= d.annee)
    {
        if(annee<d.annee)
            return -1;
        else
            return 1;
    }
	else if (mois != d.mois)
        return ((mois<d.mois)?-1:1);	// utilisation ici de l operateur ternaire
    else if (jour!=d.jour)
        return ((jour<d.jour)?-1:1);
    else
        return 0;
}

const std::string Date::mois2Str[12] =
{"Janvier","Fevrier","Mars","Avril","Mai","Juin","Juillet","Aout","Septembre","Octobre","Novembre","Decembre"};

std::ostream& operator << (std::ostream& O, const Date& d)
{
    d.affiche(O);
    return O;
}

void Date::affiche(std::ostream& O) const {
	O << jour << " " << mois2Str[mois] << " " << annee ;
}
