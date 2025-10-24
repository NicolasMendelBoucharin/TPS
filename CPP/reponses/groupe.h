#include "etudiant.h"

class groupe{
    protected:
    static Etudiant etudVid;
    private:
    int nbEtud;
    Etudiant** listEtud;
    //static 
    public:
    groupe();
    groupe(int nmetudiantconstruit);
    groupe(const groupe& groupe1);
    void modif(int i, Etudiant* p_cetEtud);
    void afficheNbEtud() const;
    void afficheEtud(int i) const;
    void affiche() const;
    groupe& operator=(const groupe& groupe1);
    ~groupe();
};
