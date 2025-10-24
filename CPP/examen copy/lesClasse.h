#include<string>
#include<iostream>

class Personne{
    private:
    std::string nom, prenom;
    int anneeNaissance;
    
    public:
    void afficheNomPrenom() const;
    void afficheAnn() const;
    virtual void affiche();
    
}


class Etudiant:public Personne{
    private:
    std::string nom, prenom;
    int anneeNaissance;
    int numEtudiant;
    public:
    Etudiant(std::string leNom="sansNom", std::string lePrenom="sansPrenom", int anneeN=2000, int numEtud=0);
    void afficheNomPrenom() const;
    void afficheAnn() const;
    void afficheNum() const;
    void affiche() const;
};