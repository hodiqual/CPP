#include "Personne.h"

using namespace std;

int Personne::no_id=0;

string Personne::getNom() const
{
    return nom;
}

string Personne::getPrenom() const
{
    return prenom;
}

int Personne::getId() const
{
    return id;
}

void Personne::setPrenom(string nouveau_prenom)
{
   prenom = nouveau_prenom;
}
void Personne::setNom(string nouveau_nom)
{
    nom = nouveau_nom;
}
void Personne::affiche() const
{
    cout<<id<<" "<<nom<< " "<<prenom<< " saisi le ";
    dateSaisie.affiche();
}
void Personne::saisir()
{
    string temp;

    cout<<"Donnez le nom de la personne : ";
    getline(cin,temp);  //permet de saisir une chaine avec des espaces
    setNom(temp);

    cout<<"Donnez son prenom : ";
    getline(cin,temp);
    setPrenom(temp);
}

Personne::Personne(const Personne& other):id(Personne::no_id++)
{
	*this = other;
}

Personne::Personne(string nom, string prenom):id(Personne::no_id++)
{
   setNom(nom);
   setPrenom(prenom);
}

Personne::~Personne()
{
	cout<<"Destruction de :"<<endl;
	affiche();
}

void Personne::affiche(std::ostream& out) const {
	out << nom << " " << prenom
			  << " (id:" << id << ", saisie le: " << dateSaisie << ")";
}

std::ostream& operator << (std::ostream& out, const Personne& p)
{
    p.affiche(out);
    return out;
}

void Personne::saisir(std::istream& cin) {
    string temp;

    cout<<"Donnez le nom de la personne : ";
    getline(cin,temp);  //permet de saisir une chaine avec des espaces
    setNom(temp);

    cout<<"Donnez son prenom : ";
    getline(cin,temp);
    setPrenom(temp);

}

std::istream& operator >> (std::istream& in, Personne& p)
{
    p.saisir(in);
    return in;
}

Personne & Personne::operator=(const Personne& other)
{
	nom = other.nom;
	prenom = other.prenom;
	return *this;
}

