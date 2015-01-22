#include "Etudiant.h"
#include <sstream>
using namespace std;

void Etudiant::affiche() const
{
    Personne::affiche();
    cout<<"Moyenne globale : "<<getMoyenneGlobale()<<endl;
}

void Etudiant::saisir(std::istream& cin)
{
    Personne::saisir(cin);
    cout<<"nombre de matieres : ";
    //cin>>nbMatieres;
    //cin.get();
    //saisie plus securisee si valeur erronnee
    string temp;
    getline(cin,temp);
    stringstream(temp)>>nbMatieres;		// inclusion de <sstream>
    delete [] matieres;	// nécessaire si on appelle cette methode
    delete [] notes;	// sur un Etudiant dejà initialisé
    matieres = new string[nbMatieres];
    notes = new float[nbMatieres];
    saisirMatieres(cin);
}

void Etudiant::setNote(string mat,float note)
{
    int i=0;
    while (i<nbMatieres && mat!=matieres[i])
        i++;
    if(i!=nbMatieres)
       notes[i]=note;
    else
        cout<<mat<<"non suivie "<<endl;
}

float Etudiant::getMoyenneGlobale() const
    // retourne la moyenne globale de l'etudiant.
{

	float moy=0;
    for (int i=0 ; i< nbMatieres;i++)
    {
        moy = moy + notes[i];
	}
    if (nbMatieres)
        return moy/nbMatieres;
    else
        return -1;
}

void Etudiant::saisirMatieres(std::istream& cin)
{
	for (int i=0; i< nbMatieres; i++)
	{
		cout << "matiere " << i << " : ";
	    getline(cin,matieres[i]);
	    cout << "note obtenue : ";
	    //cin>>notes[i];
	    //cin.get(); //permet de vider le tampon d'entree
	    string temp;
	    getline(cin,temp);
	    stringstream(temp)>>notes[i];
	}
}
Etudiant::~Etudiant()
{
	delete [] matieres;
	delete [] notes;
}

void Etudiant::affiche(std::ostream& out) const {
	Personne::affiche(out);
	out << " est un eleve et sa moyenne est " << getMoyenneGlobale();
}

Etudiant::Etudiant(const Etudiant& e):Personne(e),nbMatieres(e.nbMatieres),matieres(NULL),notes(NULL)
{
	*this = e;
}



Etudiant::Etudiant(string nom, string prenom,int n): Personne(nom,prenom),nbMatieres(n),matieres(NULL),notes(NULL)
{
	if(n>0)
	{
		matieres=new string[n];
		notes= new float[n];
	}
	//saisie des matieres ds appel de saisirMatieres
}

Etudiant& Etudiant::operator =(const Etudiant& other) {

	if(nbMatieres)
	{
		matieres = new string[nbMatieres];
		notes = new float[nbMatieres];

		for(int i=0;i<nbMatieres;i++)
		{
			matieres[i] = other.matieres[i];
			notes[i] = other.notes[i];
		}
	}

	return *this;
}
