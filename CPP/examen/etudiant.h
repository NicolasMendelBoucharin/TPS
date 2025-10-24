#include<string>
#include<iostream>
class Etudiant{
    private:
    std::string nom, prenom;
    int anneeNaissance, numEtudiant;
    public:
    Etudiant(std::string leNom="sansNom", std::string lePrenom="sansPrenom", int anneeN=2000, int numEtud=0);
    void afficheNomPrenom() const;
    void afficheAnn() const;
    void afficheNum() const;
    void affiche() const;
};