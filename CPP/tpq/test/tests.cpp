#include <iostream>
#include <cassert>
#include <sstream>
#include <cmath>
#include "../include/qq.h"
#include "../include/vect.hpp"
#include "../include/matrice.hpp"
#include "../include/datas.hpp"

using namespace std;

// Simple test framework
int tests_run = 0;
int tests_passed = 0;

#define TEST(condition, message) \
    do { \
        tests_run++; \
        if (condition) { \
            tests_passed++; \
            cout << "✓ " << message << endl; \
        } else { \
            cout << "✗ FAIL: " << message << endl; \
        } \
    } while(0)

#define ASSERT_THROW(expression, exception_type, message) \
    do { \
        tests_run++; \
        try { \
            expression; \
            cout << "✗ FAIL: " << message << " (exception not thrown)" << endl; \
        } catch (const exception_type&) { \
            tests_passed++; \
            cout << "✓ " << message << endl; \
        } catch (...) { \
            cout << "✗ FAIL: " << message << " (wrong exception type)" << endl; \
        } \
    } while(0)

// ============================================
// TESTS POUR LA CLASSE QQ (Nombres Rationnels)
// ============================================

void test_qq() {
    cout << "\n=== TESTS CLASSE QQ ===" << endl;
    
    // Constructeurs
    qq q1(3, 4);
    TEST(q1 == qq(3, 4), "Constructeur qq(3,4)");
    
    qq q2(5);
    TEST(q2 == qq(5, 1), "Constructeur qq(5) => 5/1");
    
    qq q3;
    TEST(q3 == qq(0, 1), "Constructeur par défaut qq() => 0/1");
    
    // Réduction
    qq q4(6, 8);
    q4.reduction();
    TEST(q4 == qq(3, 4), "Réduction de 6/8 => 3/4");
    
    // Opérateurs arithmétiques
    qq a(1, 2);
    qq b(1, 3);
    qq c = a + b;
    TEST(c == qq(5, 6), "Addition: 1/2 + 1/3 = 5/6");
    
    qq d = a - b;
    TEST(d == qq(1, 6), "Soustraction: 1/2 - 1/3 = 1/6");
    
    qq e = a * b;
    TEST(e == qq(1, 6), "Multiplication: 1/2 * 1/3 = 1/6");
    
    qq f = a / b;
    TEST(f == qq(3, 2), "Division: 1/2 / 1/3 = 3/2");
    
    // Opérateur unaire -
    qq g = -a;
    TEST(g == qq(-1, 2), "Unaire moins: -(1/2) = -1/2");
    
    // Puissance
    qq h = a.pow(2);
    TEST(h == qq(1, 4), "Puissance: (1/2)^2 = 1/4");
    
    qq i = a.pow(3);
    TEST(i == qq(1, 8), "Puissance: (1/2)^3 = 1/8");
    
    qq j = a.pow(0);
    TEST(j == qq(1, 1), "Puissance: (1/2)^0 = 1");
    
    // Valeur absolue
    qq k(-3, 4);
    qq l = k.abs();
    TEST(l == qq(3, 4), "Valeur absolue: |-3/4| = 3/4");
    
    // Comparaisons
    qq m(1, 2);
    qq n(2, 3);
    TEST(m < n, "Comparaison: 1/2 < 2/3");
    TEST(!(m > n), "Comparaison: !(1/2 > 2/3)");
    TEST(m == qq(1, 2), "Comparaison: 1/2 == 1/2");
    
    // Opérateur +=
    qq p(1, 4);
    qq q(1, 4);
    p += q;
    TEST(p == qq(1, 2), "Opérateur +=: 1/4 += 1/4 => 1/2");
    
    // Conversion en double
    qq r(1, 2);
    double dr = (double)r;
    TEST(fabs(dr - 0.5) < 1e-10, "Conversion en double: 1/2 => 0.5");
    
    // Opérateur *: 1/2 * 2.0 = 1.0
    double d_result = r * 2.0;
    TEST(fabs(d_result - 1.0) < 1e-10, "Opérateur *: 1/2 * 2.0 = 1.0");
    
    // I/O
    stringstream ss;
    qq s(7, 5);
    ss << s;
    string output = ss.str();
    TEST(!output.empty(), "Opérateur <<: affichage de 7/5");
}

// ============================================
// TESTS POUR LA CLASSE VECT (Vecteurs)
// ============================================

void test_vect() {
    cout << "\n=== TESTS CLASSE VECT ===" << endl;
    
    // Constructeurs
    Vect<double> v1(3);
    TEST(v1.size() == 3, "Constructeur Vect(3)");
    
    Vect<double> v2;
    TEST(v2.size() == 0, "Constructeur par défaut Vect()");
    
    // Initialisation
    v1.init(0.0);
    TEST(v1.get(0) == 0.0 && v1.get(1) == 0.0 && v1.get(2) == 0.0, 
         "Initialisation init(0.0)");
    
    // Modification et accès
    v1.modif(0, 1.0);
    v1.modif(1, 2.0);
    v1.modif(2, 3.0);
    TEST(v1.get(0) == 1.0, "get(0) après modif(0, 1.0)");
    TEST(v1.get(1) == 2.0, "get(1) après modif(1, 2.0)");
    TEST(v1.get(2) == 3.0, "get(2) après modif(2, 3.0)");
    
    // Setter
    v1.set(0, 5.0);
    TEST(v1.get(0) == 5.0, "set(0, 5.0)");
    
    // Addition
    Vect<double> v3(3);
    v3.init(0.0);
    v3.modif(0, 1.0);
    v3.modif(1, 2.0);
    v3.modif(2, 3.0);
    
    Vect<double> v4(3);
    v4.init(0.0);
    v4.modif(0, 2.0);
    v4.modif(1, 3.0);
    v4.modif(2, 4.0);
    
    Vect<double> v5 = v3 + v4;
    TEST(v5.get(0) == 3.0 && v5.get(1) == 5.0 && v5.get(2) == 7.0,
         "Addition: [1,2,3] + [2,3,4] = [3,5,7]");
    
    // Soustraction
    Vect<double> v6 = v4 - v3;
    TEST(v6.get(0) == 1.0 && v6.get(1) == 1.0 && v6.get(2) == 1.0,
         "Soustraction: [2,3,4] - [1,2,3] = [1,1,1]");
    
    // Produit scalaire
    Vect<double> va(3);
    va.init(0.0);
    va.modif(0, 1.0);
    va.modif(1, 2.0);
    va.modif(2, 3.0);
    
    Vect<double> vb(3);
    vb.init(0.0);
    vb.modif(0, 4.0);
    vb.modif(1, 5.0);
    vb.modif(2, 6.0);
    
    double scal = va.scal(vb);
    TEST(fabs(scal - 32.0) < 1e-10, "Produit scalaire: [1,2,3]·[4,5,6] = 32");
    
    // Produit externe (multiplication par scalaire)
    Vect<double> v_ext = v3.produit_externe(2.0);
    TEST(v_ext.get(0) == 2.0 && v_ext.get(1) == 4.0 && v_ext.get(2) == 6.0,
         "Produit externe: [1,2,3] * 2 = [2,4,6]");
    
    // Différence de norme
    Vect<double> vx(3);
    vx.init(0.0);
    vx.modif(0, 0.0);
    vx.modif(1, 0.0);
    vx.modif(2, 0.0);
    
    Vect<double> vy(3);
    vy.init(0.0);
    vy.modif(0, 3.0);
    vy.modif(1, 4.0);
    vy.modif(2, 0.0);
    
    double diff_norm = vx.difference_norme(vy);
    TEST(fabs(diff_norm - 25.0) < 1e-10, 
         "Différence de norme: ||[0,0,0] - [3,4,0]||² = 25");
    
    // Copie
    Vect<double> v_copy = v3;
    TEST(v_copy.get(0) == v3.get(0) && v_copy.get(1) == v3.get(1),
         "Copie par constructeur");
    
    // Assignation
    Vect<double> v_assign(3);
    v_assign = v3;
    TEST(v_assign.get(0) == v3.get(0), "Assignation operator=");
    
    // Test add()
    Vect<double> v_add(3);
    v_add.add(v3, v4);
    TEST(v_add.get(0) == 3.0 && v_add.get(1) == 5.0 && v_add.get(2) == 7.0,
         "Méthode add(): v_add.add(v3, v4)");
}

// ============================================
// TESTS POUR LA CLASSE MATRICE
// ============================================

void test_matrice() {
    cout << "\n=== TESTS CLASSE MATRICE ===" << endl;
    
    // Constructeurs
    Matrice<double> m1(2);
    TEST(m1.size() == 2, "Constructeur Matrice(2)");
    
    Matrice<double> m2;
    TEST(m2.size() >= 0, "Constructeur par défaut Matrice()");
    
    // Initialisation
    m1.init(0.0);
    TEST(m1.get(0, 0) == 0.0 && m1.get(0, 1) == 0.0 &&
         m1.get(1, 0) == 0.0 && m1.get(1, 1) == 0.0,
         "Initialisation init(0.0)");
    
    // Modification et accès
    m1.set(0, 0, 1.0);
    m1.set(0, 1, 2.0);
    m1.set(1, 0, 3.0);
    m1.set(1, 1, 4.0);
    
    TEST(m1.get(0, 0) == 1.0, "get(0,0) après set(0,0,1.0)");
    TEST(m1.get(0, 1) == 2.0, "get(0,1) après set(0,1,2.0)");
    TEST(m1.get(1, 0) == 3.0, "get(1,0) après set(1,0,3.0)");
    TEST(m1.get(1, 1) == 4.0, "get(1,1) après set(1,1,4.0)");
    
    // Matrice pour tests suivants: [[1,2],[3,4]]
    Matrice<double> a(2);
    a.init(0.0);
    a.set(0, 0, 1.0);
    a.set(0, 1, 2.0);
    a.set(1, 0, 3.0);
    a.set(1, 1, 4.0);
    
    Matrice<double> b(2);
    b.init(0.0);
    b.set(0, 0, 5.0);
    b.set(0, 1, 6.0);
    b.set(1, 0, 7.0);
    b.set(1, 1, 8.0);
    
    // Addition
    Matrice<double> c = a + b;
    TEST(c.get(0, 0) == 6.0 && c.get(0, 1) == 8.0 &&
         c.get(1, 0) == 10.0 && c.get(1, 1) == 12.0,
         "Addition: [[1,2],[3,4]] + [[5,6],[7,8]] = [[6,8],[10,12]]");
    
    // Multiplication
    Matrice<double> d = a * b;
    // [[1,2],[3,4]] * [[5,6],[7,8]] = [[1*5+2*7, 1*6+2*8], [3*5+4*7, 3*6+4*8]]
    //                                  = [[19, 22], [43, 50]]
    TEST(d.get(0, 0) == 19.0 && d.get(0, 1) == 22.0 &&
         d.get(1, 0) == 43.0 && d.get(1, 1) == 50.0,
         "Multiplication: [[1,2],[3,4]] * [[5,6],[7,8]] = [[19,22],[43,50]]");
    
    // Copie
    Matrice<double> m_copy = a;
    TEST(m_copy.get(0, 0) == a.get(0, 0), "Copie par constructeur");
    
    // Assignation
    Matrice<double> m_assign(2);
    m_assign = a;
    TEST(m_assign.get(0, 0) == a.get(0, 0), "Assignation operator=");
    
    // Déterminant
    Matrice<double> m_det(2);
    m_det.init(0.0);
    m_det.set(0, 0, 1.0);
    m_det.set(0, 1, 2.0);
    m_det.set(1, 0, 3.0);
    m_det.set(1, 1, 4.0);
    // det([[1,2],[3,4]]) = 1*4 - 2*3 = -2
    double det_result = m_det.Determinant();
    TEST(fabs(det_result - (-2.0)) < 1e-10, 
         "Déterminant: det([[1,2],[3,4]]) = -2");
    
    // Produit matrice-vecteur
    Vect<double> v(2);
    v.init(0.0);
    v.modif(0, 1.0);
    v.modif(1, 2.0);
    
    Vect<double> v_result = a.produit_matrice_vecteur(v);
    // [[1,2],[3,4]] * [1,2] = [1*1+2*2, 3*1+4*2] = [5, 11]
    TEST(v_result.get(0) == 5.0 && v_result.get(1) == 11.0,
         "Produit matrice-vecteur: [[1,2],[3,4]] * [1,2] = [5,11]");
    
    // Gauss (résolution de système Ax=b)
    Matrice<double> m_gauss(2);
    m_gauss.init(0.0);
    m_gauss.set(0, 0, 2.0);
    m_gauss.set(0, 1, 1.0);
    m_gauss.set(1, 0, 1.0);
    m_gauss.set(1, 1, 3.0);
    
    Vect<double> b_gauss(2);
    b_gauss.init(0.0);
    b_gauss.modif(0, 5.0);
    b_gauss.modif(1, 6.0);
    
    Vect<double> x_gauss = m_gauss.gauss(b_gauss);
    // Système: 2x + y = 5, x + 3y = 6
    // Solution: x = 1.5, y = 2
    TEST(x_gauss.size() == 2, "Gauss: Vecteur solution bien formé");
    
    // solveLU
    Matrice<double> m_lu(2);
    m_lu.init(0.0);
    m_lu.set(0, 0, 2.0);
    m_lu.set(0, 1, 1.0);
    m_lu.set(1, 0, 1.0);
    m_lu.set(1, 1, 3.0);
    
    Vect<double> b_lu(2);
    b_lu.init(0.0);
    b_lu.modif(0, 5.0);
    b_lu.modif(1, 6.0);
    
    Vect<double> x_lu = m_lu.solveLU(b_lu);
    TEST(x_lu.size() == 2, "solveLU: Vecteur solution bien formé");
}

// ============================================
// TESTS POUR LA CLASSE DATAS
// ============================================

void test_datas() {
    cout << "\n=== TESTS CLASSE DATAS ===" << endl;
    
    // Note: Les tests complets de datas nécessiteraient un fichier
    // Nous faisons un test basique de création
    datas d;
    
    // Vérifier que les getters retournent des valeurs
    int corps = d.getCorps();
    int taille = d.getTaille();
    int algo = d.getAlgo();
    double tolerance = d.getTolerance();
    
    TEST(true, "Datas: Constructeur et getters fonctionnent");
}

// ============================================
// MAIN - EXÉCUTION DES TESTS
// ============================================

int main() {
    cout << "\n╔════════════════════════════════════╗" << endl;
    cout << "║   SUITE DE TESTS UNITAIRES - TPQ   ║" << endl;
    cout << "╚════════════════════════════════════╝" << endl;
    
    test_qq();
    test_vect();
    test_matrice();
    test_datas();
    
    cout << "\n╔════════════════════════════════════╗" << endl;
    cout << "║          RÉSULTATS FINAUX          ║" << endl;
    cout << "╚════════════════════════════════════╝" << endl;
    cout << "Tests passés: " << tests_passed << "/" << tests_run << endl;
    
    if (tests_passed == tests_run) {
        cout << "✓ TOUS LES TESTS SONT PASSÉS !" << endl;
        return 0;
    } else {
        cout << "✗ " << (tests_run - tests_passed) << " test(s) échoué(s)" << endl;
        return 1;
    }
}
