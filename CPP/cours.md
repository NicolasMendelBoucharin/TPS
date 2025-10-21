# Évocation de la STL 
Standard library of C++.
Pour la referencer : 
- `using namespace std; # Importe toute la librairie (bouuuuh)`
- `using std::sqrt;`
- `double a = std::sqrt(2);`

Warning: Conseil `std::abs` systématiquement.

Pour faire appel à sqrt :
```cpp
#include <cmath>
```

Fonctions d'écriture à l'écran et de lecture au clavier : 
```cpp
#include <iostream>
```

# Entrées-Sorties standard

Fonction `cin` et `cout` avec les opérateurs << et >> dont les prototypes sont dans `<iostream>`

Exemple : 

```cpp
#include <iostream>
using namespace std; 
// alternative : 
// using std::cin; 
// using std::cout;
// using std::endl;

int main(){
    int num_annee;
    cout<<"Donner moi la moulaga"<<endl;
    cin>>num_annee;
    cout<<"Tia donner "<<num_annee<<" de moulaga"<<endl;
}
```

# Définition d'une classe

## Premier exemple
- Dans le fichier MaClasse.hpp
```cpp
#ifndef MACLASS_H
#define MACLASS_H

class MaClass{
    private: 
        // donnees membres (attributs)
            int donnee1;
            double donnee2;
    public:
        // fonctions membres (méthodes) 
        MaClasse(...); // declaration constructeur
        int fonc1();
        double fonc2();

};

#endif
```

- Dans le fichier MaClasse.cpp
```cpp
#include "MaClasse.hpp"

MaClasse::MaClasse(int i, double d){
    donnee1 = i;
    donnee2 = d;
}
int MaClasse::fonc1(){return donnee1++;} //exemple
double MaClasse::fonc2(){return donnee2;} // exemple
```

- Dans toto.cpp :

```cpp
// ...

int main(){
    MaClasse MonObjet(2, 3.14);
    int i = MonObjet.fonc1();

    Maclasse* MO_p = &MonObjet;
    double d = MO_p->fonc2();
}   
```

## Constructeur 

### Premier pas 

Si on ne définit pas de constructeur, il y en a un par défaut 
```cpp
MaClasse();
```

si on en définit un du style 

```cpp
MaClasse(int a = 0, int b = 1);
```

et on perd celui par défaut (sans arguments) mais on peut le redéfinir mais attention au cas 

```cpp
MaClasse();
MaClasse(int a = 0, int b = 1);
```

où le compilateur ne sait pas lequels appelé quand on tape 

```cpp
MaClasse T;
```

### Constructeurs par défaut, par copie, destructeur.

Le constructeur par défaut

```cpp
MaClasse();
```

Le constructeur par copie, accessible par défaut. On peut le redéfinir avec le prototype 

```cpp
MaClasse(const MaClasse&);
```

Ex : 

```cpp
class ClTest{
    // ...
}

// ...

ClTest C1, C2;
C1 = C2; // Affectation
ClTest C3(C1); // Copie
ClTest C4 = C1; // Copie
```

Le destructeur existe par défaut

```cpp
~MaClasse(); // On peut le redéfinir 
```

mais attention, si l'objet est un tableau il faut le redéfinir pour faire un delete propre. 

#### Usage du constructeur par copie

Lors de l'initialisation au moment de la définition d'un objet :

```cpp
Complexe z(1,2.5);

// Deux façons équivalentes d'appeler le constructeur par copie :
Complexe zz(z);
// ou bien 
Complexe zz = z;
```

#### Liste d'initialisation dans le constructeur

```cpp
class Complexe{
    private :
        double re, im;
    public :
        Complexe(double r, double i):re(r),im(i){}
};
```

## Données membres et fonctions membres `static`

### Données membres `static`

Une **donnée membre** `static` dans une classe existe en un exemplaire unique partagé par l'ensemble des objets de la classe.

**Exemple** : Dans la classe `Complexe`, on peut définir : 

- Dans la définition de la classe dans le fichier .h++/.hpp :

```cpp
static Complexe eye;
```

- Dans le fichier .c++/.cpp :

```cpp
Complexe Complexe::eye(0.,1.);
```

### Fonctions membres `static` 

Possible pour toute fonction dont l'action est indépendantes de l'objet de la classe.

**Exemple** :

- Dans le fichier .h++/.hpp :

```cpp
static void afficheEye();
```

- Dans le fichier .c++/.cpp :

```cpp
Complexe::afficheEye(){...}
```

**Usage** :

Trois cas équivalents

```cpp
Complexe X,Y;
X.afficheEye();
Y.afficheEye();
Complexe::afficheEye(); // Possible uniquement parce que la fonction est static
```

### Plusieurs classes dans un combiné .hpp/.cpp

Le fichier `.hpp` :

```cpp
class C1{
    // ...
};

class C2{
    // ...
};
```

Le fichier `.cpp` :

```cpp
C1::fct1(...){...}
C1::fct2(...){...}
// ...

C2::fct1(...){...}
// ...
```

# Usage préprocesseur

- Référencer des fichiers qui contiennt des déclarations de fonctions ou des définition de classes.
- Référencer des headers de la STL (ex : `#include <iostream>`).
- Un header contient principalement :
    - déclaration de fonction
    - déclaration de variables globales
    - déclaration ou définition de classes 
    - définition de fonction "inline"
- Ne pas utiliser "using" dans les headers.

## Usage de #include

Ordre conseillé : 
```cpp
#include "MesFichiers.h"
#include <headers_de_la_STL>

using std::truc // Que dans un .cpp
```

## Listes d'initialisation :

```cpp
Complexe(double pr, double pi):partie_reelle(pr), partie_imaginaire(pi){};
// ou 
Complexe(double pr, double pi){partie_reelle=pr, partie_imaginaire=pi};
```

# Fonction et arguments avec valeur par défaut

## Cas 1
```cpp
int som(int a, int b=1){return a + b;}
```
Usage :
```cpp
int b = 1;
int c = som(b); // c = 2
```

## Cas 2
```cpp
int som(int a=0, int b=1){return a + b;}
```

Usage :
```cpp
int a = 1, b = 0;
int c = som(a,2); // c = 3
int d = som(3); // d = 4
int e= som(); // e = 1
```

# Surchage de fonction :

```cpp
int add(int a, int b){return a+b;}
double add(double a, double b){return a+b;}
```

Usage :

```cpp
int a = 1;
int c = add(a,2); // c = 3
double d = add(1.5, 2.5); // d = 4
double e = add(1.5,a); // Erreur : ambiguité
```

# Transmission par valeur, par pointeur ou par référence

## Transmission par valeur/pointeur
Comme en C

## Référence :

"Comme un pointeur mais on a pas besoin de déréférencer."

```cpp
int var = 1;
int& r(var); // définition d'une référence sur "var" 
int x = r; // x devient 1;
r = 2; // var = 2
r++; // var = 3
int *p = &r; // p pointe vers var 
```

## Transmission par référence :

```cpp
int add1(int a, int b){return a+b;}
int add2(int *a, int *b){return *a + *b;}
int add3(int& a, int& b){return a + b;}
int add4(const int& a, const int& b){return a + b;} // Pour être sûr que a et b ne soient pas modifiées pendant l'appel de la fonction
```

Usage :

```cpp
int i = 1, j = 2;
int k = add1(i,j);
int l = add2(&i,&j);
int m = add3(i,j);
```

# Fonction assert

Prototype de la fonction :
```cpp
void assert(int expression);
```

Si "expression" vaut 0 (false), la fonction renvoie un message d'erreur et interrompt le programme.
La fonction est désactivée si l'étiquette `NDEBUG` définie par

```cpp
#define NDEBUG
```

au moment de l'inclusion de `<assert.h>`.

# Allocation dynamique de mémoire 

`new` pour allouer de la mémoire et `delete` pour libérer de la mémoire.

## 1er usage 

```cpp
double* d = new double(2.5); // Zone mémoire d'un double valant 2.5
// ...
delete d;
```

## 2ème usage 

```cpp
double* d = new double[10]; // Zone mémoire de 10 double
// ...
delete [] d;
```

Cas particulier :

Ça va marcher et c'est ce qu'il faut faire car le compilateur va bien le gérer. Si on sépare le cas `N=0` attention aux problèmes. 

```cpp
float* a;
a = new float[0]; // new float[N] avec N = 0
// ...
delete [] a;
```

# Pointeur `this`

Dans une classe, chaque fonctions membres non `static` a accès à un pointeur vers l'objet courant : `this`.

**Exemple** : l'écriture de l'opération affectation fini par : 

```cpp
return *this;
```

# Mot clef `friend` et alternative

Tell your friends : "don't use friend"
Ça existe mais on doit pas l'utiliser, paie ta logique. 

## Concept de class amies 

On a une class `C1` avec une donnée membre `i` de type `int`.
On veut accéder à `i` depuis un objet de `C1` depuis un objet de la class `C2` et depuis une fonction externe `nomFonction`.

```cpp
int nomFonction(C1 objC1){
    return objC1.i + 1;
}
```

Pour pouvoir faire cela on peut identifier cette fpnction comme 'amie' de la class `C1` 

```cpp
class C1{
    private :
        int i;
    public :
        // ...
        friend int nomFonction(C1);
        friend void C2::affiche(C1);
        friend class C2; // Toutes les méthodes de C2 sont friend
};
```

Pour utiliser `i` de `C1` dans une fonction de `C2` :

- Dans le .hpp :

```cpp
class C1; // Déclare C1 sans le définir, ~ extern en C

class C2{
    private :
        int j;
    public :
        void affiche(C1);
}
```

- Dans le .cpp :

```cpp
void C2::affiche(C1 O1){
    cout<<"i from C1 object : "<< O1.i << endl;
}
```

Il faut bien séparer la déclaration et la définition de cette fonction (`affiche`) car sinon on a un problème à la compilation car `C2` à besoin de `C1` et `C1` a besoin de `C2`.


**Conclusion** :

```cpp
class C1;

class C2{
    // ...
    void affiche(C1);
    // ...
};

class C1{
    // ...
    friend C2::affiche(C1);
    // ...
};
```

## Fonction d'accès dans une class

Alternative à l'utilisation du mot clef `friend`. 

```cpp
class C1{
    private :
        int i;
    public :
        // ...
        int geti(){return i;} // inline -> le compilateur remplace chaque appel de la fonction par son code. Ça peut devenir très lourd. Si c'est pas une ligne, on le fait pas en gros. 
        // ...
};
```

Conseiller d'utiliser le mot clef `const` ici :

```cpp
class C1{
    private :
        int i;
    public :
        // ...
        int geti() const {return i;} 
        void affiche() const;
        // ...
};
```

# Surcharge d'opérateurs 

## Comme fonction externe

- L'un au moins des opérandes est un objet.
- On ne peut pas créer un nouvel opérateur.
- Même nombre d'opérandes que l'opérateur d'origine.
- `.`, `::`, `?:`, `sizeof`, `.*``ne peuvent pas être surchargés.
- `=`, `()`, `[]`, `->` ne peuvent pas être surchargés comme fonction externe.


**Protypes possible** 

- Pour un opérateur unaire :

```
type operator op(type)
```

- Pour un opérateur binaire :

```
type1 operator op(type2,type3)
```

**Exemples**

```cpp
bool operator < (Type Obj1, Type Obj2){
    //....
    return booleen;
}
```

```cpp
Type& operator += (Type& Obj1, Type Obj2){
    // ...
    return a Type& object;
}
```

```cpp
Type operator + (Type Obj1, Type Obj2){
    // ...
    return a Type object;
}
```

## Surcharge d'opérateurs dans une class  

Ça sera une fonction membre d'une class.

**Prototypes**

- opérateur unaire :
```
type operator op()
```

- opérateur binaire :
```
type operator op(type1, type2)
```

**Correspondance écriture appel/définitions**

||Appel opérateur  | Fonction externe | Fonction d'une classe 
| -------- | ------- | ------- |------- |
| Unaire | op A | operator op(A)| A.operator op() 
| Binaire |A op B | operator op(A,B) | A.operator op(B)


**Exemple sur la classe `Complexe`**

```cpp
Complexe Complexe::operator+(const Complexe& z){
    Complexe zz(re+z.re, im + z.im);
    return zz;
}

Complexe& Complexe::operator+=(const Complexe& z){
    re += z.re;
    im += z.im;
    return (*this);
}
```

# Mot clef `explicit`

**Exemple**

```cpp
// Constructeur
explicit Complexe(double a, double b=0);

// Dans une fonction appelante
Complexe z(0,1.5);
Complexe zz = z + 0.5; // Marche pas avec explicit, il faudra bien définir l'opération 
```

# Allocation dynamique dans une classe

**Exemple**

Soit la classe
```cpp
class MaClasse{
    private :
        int lg;
        double* p_val;
    public :
        MaClasse(int);
        ~MaClasse();
};
```

Dans le fichier `.cpp`

```cpp
MaClasse::MaClasse(int lo):lg(lo){
    p_val = new double[lg];
}

MaClasse::MaClasse(){
    delete [] p_val;
}
```

**Usage**

```cpp
{ // Début bloc 1
MaClasse o1(10); // Constructeur programmé dans le classe
{ // Début bloc 2
    MaClasse o2(o1); // Constructeur par copie
    // A l'appel du destructeur sur o2, on désalloue le pointeur p_val qui est le même que dans o1
} // Fin bloc 2
MaClasse o3 = o1; // Constructeur par copie
} // Fin bloc 1 
// En sortie : message d'erreur -> tentative de libération de mémoire non allouée 
```

## Récriture du constructeur par copie 
Récriture du constructeur par copie pour une copie en profondeur et non une copie superficielle. 

Dans la définition de la classe

```cpp
class MaClasse{
    // ...
    public : 
        MaClasse(const MaClasse&);
}
```

Dans le `.cpp` 

```cpp
MaClasse::MaClasse(const MaClasse& M){
    lg = M.lg;
    p_val = new double[lg];
    for(int i = 0; i < lg; i++){
        p_val[i] = M.p_val[i];
    }
}
```

## Récriture de l'opérateur d'affection

```cpp
MaClasse o1(10);
Maclasse o2();
o2 = o1;
```

Redéfinition de l'opérateur `n` 

```cpp
MaClasse& MaClasse::operator=(const MaClasse& M){
    if(lg != M.lg){
        delete [] p_val;
        lg = M.lg;
        p_val = new double[lg];
    }
    for(int i = 0; i < lg; i++){
        p_val[i] = M.p_val[i];
    }
    return *this;
}
```

## Neutralisation des constructeurs par copie, par move et de l'affectation

Dans la déclaration de la classe

```cpp
MaClasse(const MaClasse&) = delete; 
MaClasse(MaClasse&&) = delete; // par move
MaClasse& operator=(const MaClasse&) = delete;
MaClasse& operator=(const MaClasse&&) = delete;
```

# Fonctions génériques

## Exemple

```cpp
int add(int a, int b){return a+b;}
float add(float a,float b){return a+b;}
```

## Alternatives

- **Possibilité 1**

Dans un header `.hpp`

```cpp
template <class K> K add(K a, K b){return a+b;}
```

Ici c'est pas compiler mais géré par le prerocesseur donc il remplace les appels de la fonction partout où c'est utilisé dans le code et il connaît alors le type des variables en paramètres. 

- **Possibilité 2**

Dans un header 

```cpp
template <class K> K add(K a, K b);
```

Dans un fichier `.cpp` :

```cpp
template <class K> K add(K,a K b){return a+b;}

// Instanciation
template int add(int,int);
template float add(float,float);
template double add(double, double);
```

Ici, on est obligé d'instantier car le compilateur ne s'est pas avec quels types on va appeler la fonction donc il faut lui dire. 

## Autre exemple

```cpp
template <class K, class L> K add(K a, L b){return a+b;}
// ...
int add(int a, int b){return a+b;} // Spécialisation, elle est prioritaire sur la fonction générique d'avant 
```

Attention, si **K** est `int` et **L** `float` alors le résultat sera un `int` donc on perd de l'information (conversion dégradente).

# Classes génériques 

## Définition

Fichier `.hpp` :

```cpp
template <class K> class MaClassTemp{
    private : 
        // donnes membres
    public :
        type fonctionT(const K& data);
        // ...
}
```

Définition de **fonctionT** dans le `.cpp`

```cpp
template <class K> type MaClasseTemp<K>::fonctionT(const K& data){...}
```

Ici il faudrait de l'instanciation (car une partie dans le `.cpp` si tout est dans le fichier `.hpp` c'est pas la peine) aussi mais c'est pas dans les notes du prof donc il faut se débrouiller seul pour trouver la syntaxe.

## Exemple

```cpp
template <class T> class essai{
    T i;
};
```

**Usage :**

```cpp
// ...
essai<int> ci;
essai<float> cf;
```

# Classe de base et classes dérivées

On définit une classe (de base) `MaClasseBase`.
On veut définir une classe `MaClasseDer` qui dérive de `MaClasseBase`.

```cpp
class MaClasseDer: public MaClasseBase{ // public peut être remplacé par protected, private, ...
    private :
        // données membres propres à cette classe
    public :
        // fonctions membres propres à cette classe
};
```

Un objet du type `MaClassDer` est aussi un objet du type `MaClasseBase`.


## Héritage

Un objet de la classe `MaClasseDer` hérite des données membres et fonctions membres de MaClasseBase identifiées **public** ou **protected**.

(parce que MaClasseDer est déf à partir de MaClasseBase avec le mot clef **public**)

(Les données membres **private** ne sont pas héritées, il faut mettre **protected** si on veut la protection apporté par **private** mais transmisent par héritage.)[Dit à l'oral par le prof mais pas noté]

## Constructeur

### Possibilité 1

Dans le header `.hpp`

```cpp
MaClasseDer(...):MaClasseBase(...){...}
```

### Possibilité 2

- Dans le header `.hpp`

```cpp
MaClasseDer(...):MaClasseBase(...);
```

- Dans le `.cpp`

```cpp
MaClasseDer::MaClasseDer(...):MaClasseBase(...){...}
```


# Entrées-Sorties dans un fichier

## Exemple 

```cpp
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int donnees1,donnees2;
    string ficdon("monfichier.don"), ficres("monfichier.res");

    // Ouverture d'un flot d'entree
    ifstream fdon(ficdon.c_str()); // ifstream pour in file stream 
    
    if(!fdon.is_open()){
        cout<<"Fichier "<<ficdon<<" inexistant. Abandon."<<endl
        exit(1);
    }
    
    // Lecture des données 
    fdon>>donnee1;
    fdon>>donnee2;

    fdon.close();

    // Ouverture d'un flot d'écriture
    ofstream fres(ficres.c_str());

    //Ecriture des résultats
    fres<<"Les resultats sont :"<<endl;
    fres.close();
}
```

# String

```cpp
#include <iostream>
#include <string>

// ---------------------- //
using std::string;
using std::cout;
using std::endl;
// ou using namespace std //

string nom = "sansNom";
cout<<nom<<endl;
```

# Fonction virtuelle

## Notion de polymorphisme

La fonction `MaFonction` est déclarée ou définie dans la classe de base.
On souhaite la redéfinir dans une classe dérivée.
Pour cela, elle est déclarée virtuelle dans la classe de base. 

Dans le fichier `.h`, lors de la définition de la classe 

```cpp
virtual type MaFonction(...);
// ou
virtual type MaFonction(...){...} //si inline
// ou 
virtual type MaFonction(...) const;
// ou 
virtual type MaFonction(...) const {...} // si inline 
```


**Remarques :**

- Le constructeur ne peut pas être virtuel.
- Les fonctions impliquées dans la construction : idem.
- Le destructeurs peut être virtuel. Il doit l'être s'il y a de l'allocation dynamique dans une classe dérivée.

## Fonction virtuelle pure et classe abstraite

On peut déclarer une fonction "virtuelle pure"

```cpp
virtual type MaFonction(...) = 0;
// ou
virtual type MaFonction(...) const = 0;
```

**Conséquences**

- La fonction doit être nécessairement redéclarée et définie dans toute classe dérivée.
- On ne peut pas déclarer un objet comme objet de cette classe de base.
- Une classe qui contient au moins une fonction virtuelle pure est dite "classe abstraite".

## Exemple de classe abstraite

### Fichier `geometry.h`

```cpp
#ifndef GEOMETRY_H
#define GEOMETRY_H

// Classe abstraite car on a une fonction virtuelle pure (... = 0)
class Geometry{
    protected :
        static const double pi;
    public :
        virtual ~Geometry(){}
        virtual void affiche() const;
        virtual double surface() const = 0;
};

class Cercle:public Geometry{
    private :
        double x,C, yC, rayon;
    public :
        Cercle(double x, double y, double r);

        // Redéfinition pas obligatoire :
        void affiche() const;

        // Redéfinition obligatoire :
        double surface() const{ return p*rayon*rayon; }
}

class Rectangle:public Geometry{
    private: 
        double Lo , la;
    public:
        Rectangle(double Lon, double la);
        void affiche() const;
        double surface() const {return Lo * la;}
}

#endif
```

### Fichier `geometry.cpp`

```cpp
#include "geometry.h"
#include <cmath>
#include <iostream>
using namespace std;

const double Geometry::pi4*atan(double(1.));

void Geometry::affiche() const {
    cout<<"je suis geometry, pi = "<<pi<<endl;
}

Cercle::Cercle(double x, double y, double r):Geometry(),xC(x),yC(y),rayon(r){}

void Cercle::affiche(){
    cout<<"Je suis Cercle,"<<endl;
    // Affichage intermediaire 
    cout<<"Surface = "<<surface()<<endl;
}
```

### Dans un fichier d'utilisation `blabla.cpp`

```cpp
#include "geometry.h"
#include <iostream>
using namespace std;

int main(){
    // Geometry geo; // error
    Cercle C(3,2,5);
    Rectangle R(4,5);
    R.affiche();

    Geometry* p = new Cercle(2,1,6);
    p->affiche();
    delete p;
}
```

----------------------------------------------------

# Exercices

```cpp
class TheClasse{
    private:
        int a;
};
```

À quoi on a accès avec cet objet ? 
Le constructeur par défaut, constructeur par copie, destructeur, constructeur par move (pas vu dans le cours actuellement) et l'opérateur d'affectation (voir suite) 

```cpp
Complexe z(1.,0.);

Complexe zz;
zz = z;
// Différent de Complexe zz = z;
```

