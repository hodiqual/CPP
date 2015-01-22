#ifndef _PERSONNE_H
#define _PERSONNE_H

#include <iostream>
#include "Date.h"

using std::string;

class Personne
{
    string nom;
    // le nom de la personne(objet string).

    string prenom;
    // le prenom de la personne (objet string).

    const int id;
    // identifiant de la personne

    static int no_id;
    // compteur du nombre de personne

    const Date dateSaisie;
    // date

    public:
    //Personne();
    // construit une personne non initialis�e (donc non valide).

    Personne(const Personne& other);

    Personne(string nom="inconnu", string prenom="inconnu");
    // construit une personne valide.

    string getNom() const;
    //retourne le prenom de la personne

    void setNom(string nouveau_nom);
    // change le nom de la personne.

    string getPrenom() const;
    // retourne le prenom de la personne.

    void setPrenom(string nouveau_prenom);
    // change le prenom de la personne.

    int getId() const ;
    // retourne l'identifiant

    virtual void saisir();
    // saisie une personne

    virtual void affiche() const;
    //affiche une personne

    virtual ~Personne();
    // detruit cette personne et ses ressources allouees.

    virtual void affiche(std::ostream& out) const;

    virtual void saisir(std::istream& cin);

    friend std::ostream& operator << (std::ostream& out, const Personne& p);

    friend std::istream& operator >> (std::istream& in, Personne& p);

    Personne & operator=(const Personne& other);

};   // fin de la classe Personne


#endif
