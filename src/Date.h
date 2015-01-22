#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>

using namespace std;

class Date{

    int jour,mois,annee;
	static const std::string mois2Str[12];

    public:

    Date();

    Date(int,int,int);

    int comparer(const Date& ) const;

    void affiche() const;

    friend std::ostream& operator << (std::ostream& O, const Date& B);

    virtual void affiche(std::ostream& O) const;

};

#endif // DATE
