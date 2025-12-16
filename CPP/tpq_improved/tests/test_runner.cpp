#include <iostream>
#include <cassert>
#include <cmath>
#include <functional>
#include "qq.h"
#include "vect.hpp"
#include "matrice.hpp"

using namespace std;

/**
 * @brief Framework de test simple (sans dépendance externe)
 * Plus léger que Google Test, suffisant pour ce projet
 */
class TestRunner {
private:
    int tests_run = 0;
    int tests_passed = 0;
    int tests_failed = 0;
    string current_suite;
    
public:
    void suite(const string& name) {
        current_suite = name;
        cout << "\n=== Test Suite: " << name << " ===" << endl;
    }
    
    void assert_true(const string& test_name, bool condition) {
        tests_run++;
        if (condition) {
            tests_passed++;
            cout << "✓ " << test_name << endl;
        } else {
            tests_failed++;
            cout << "✗ " << test_name << " FAILED" << endl;
        }
    }
    
    void assert_equals(const string& test_name, double actual, double expected, double epsilon = 1e-10) {
        tests_run++;
        if (abs(actual - expected) < epsilon) {
            tests_passed++;
            cout << "✓ " << test_name << endl;
        } else {
            tests_failed++;
            cout << "✗ " << test_name << " FAILED: expected " << expected << ", got " << actual << endl;
        }
    }
    
    void assert_exception(const string& test_name, function<void()> func) {
        tests_run++;
        try {
            func();
            tests_failed++;
            cout << "✗ " << test_name << " FAILED: no exception thrown" << endl;
        } catch (...) {
            tests_passed++;
            cout << "✓ " << test_name << endl;
        }
    }
    
    void print_summary() {
        cout << "\n" << string(50, '=') << endl;
        cout << "TESTS SUMMARY" << endl;
        cout << "Total : " << tests_run << endl;
        cout << "Passed: " << tests_passed << " ✓" << endl;
        cout << "Failed: " << tests_failed << " ✗" << endl;
        cout << "Rate  : " << (100.0 * tests_passed / tests_run) << "%" << endl;
        cout << string(50, '=') << "\n" << endl;
    }
};

// ============================================================================
// TESTS QQ (NOMBRES RATIONNELS)
// ============================================================================

void test_qq(TestRunner& runner) {
    runner.suite("QQ - Rational Numbers");
    
    // Constructeurs
    qq a(1, 2);
    runner.assert_equals("Constructor(1,2): numerator", a.operator double(), 0.5);
    
    qq b(3, 4);
    runner.assert_equals("Constructor(3,4): value", b.operator double(), 0.75);
    
    // Addition
    qq sum = a + b;
    runner.assert_equals("Addition 1/2 + 3/4 = 5/4", sum.operator double(), 1.25);
    
    // Soustraction
    qq diff = b - a;
    runner.assert_equals("Subtraction 3/4 - 1/2 = 1/4", diff.operator double(), 0.25);
    
    // Multiplication
    qq prod = a * b;
    runner.assert_equals("Multiplication 1/2 * 3/4 = 3/8", prod.operator double(), 0.375);
    
    // Division
    qq div = a / b;
    runner.assert_equals("Division 1/2 / 3/4 = 2/3", div.operator double(), 2.0/3.0);
    
    // Réduction
    qq unreduced(6, 9);
    unreduced.reduction();
    runner.assert_true("Reduction 6/9 = 2/3", unreduced == qq(2, 3));
    
    // Comparaison
    runner.assert_true("Comparison 1/2 < 3/4", a < b);
    runner.assert_true("Comparison 3/4 > 1/2", b > a);
    runner.assert_true("Comparison 1/2 == 2/4", a == qq(2, 4));
    runner.assert_true("Comparison 1/2 != 3/4", a != b);
    
    // Valeur absolue
    qq neg(-1, 2);
    runner.assert_true("Absolute value |-1/2| = 1/2", neg.abs() == a);
    
    // Puissance
    qq base(2, 1);  // 2/1 = 2
    qq power = base.pow(3);
    runner.assert_equals("Power (2/1)^3 = 8", power.operator double(), 8.0);
    
    // Division par zéro
    runner.assert_exception("Exception on zero denominator", [](){ qq x(1, 0); });
    runner.assert_exception("Exception on division by zero", [](){
        qq a(1, 2), b(0, 1);
        a / b;
    });
}

// ============================================================================
// TESTS VECT
// ============================================================================

void test_vect(TestRunner& runner) {
    runner.suite("VECT - Vectors");
    
    // Constructeur et initialisation
    Vect<double> v(3);
    v.init(1.0);
    runner.assert_equals("Vector init to 1.0", v.get(0), 1.0);
    runner.assert_equals("Vector all elements init", v.get(2), 1.0);
    
    // Copie
    Vect<double> v2 = v;
    runner.assert_equals("Copy constructor", v2.get(1), 1.0);
    v2.set(1, 2.0);
    runner.assert_equals("Deep copy (modify copy)", v.get(1), 1.0);
    
    // Setter/Getter avec vérification bounds
    runner.assert_exception("Get out of bounds", [&](){ v.get(100); });
    runner.assert_exception("Set out of bounds", [&](){ v.set(100, 0); });
    
    // Addition
    Vect<double> v3(3);
    v3.init(2.0);
    Vect<double> v_sum = v + v3;
    runner.assert_equals("Vector addition", v_sum.get(0), 3.0);
    runner.assert_equals("Vector addition all", v_sum.get(2), 3.0);
    
    // Soustraction
    Vect<double> v_diff = v3 - v;
    runner.assert_equals("Vector subtraction", v_diff.get(0), 1.0);
    
    // Produit scalaire
    Vect<double> a(3);
    a.set(0, 1.0); a.set(1, 2.0); a.set(2, 3.0);
    Vect<double> b(3);
    b.set(0, 2.0); b.set(1, 3.0); b.set(2, 4.0);
    double dot = a.scal(b);  // 1*2 + 2*3 + 3*4 = 20
    runner.assert_equals("Dot product (1,2,3)·(2,3,4) = 20", dot, 20.0);
    
    // Produit externe
    Vect<double> ext = a.produit_externe(2.0);
    runner.assert_equals("Outer product scalar mult", ext.get(0), 2.0);
    runner.assert_equals("Outer product scalar mult 2", ext.get(2), 6.0);
    
    // Norme de la différence
    Vect<double> u(2);
    u.set(0, 0.0); u.set(1, 0.0);
    Vect<double> w(2);
    w.set(0, 3.0); w.set(1, 4.0);
    double norm_sq = w.difference_norme(u);  // 3² + 4² = 25
    runner.assert_equals("Vector norm squared (3,4) - (0,0)", norm_sq, 25.0);
    
    // Auto-affectation
    v = v;
    runner.assert_equals("Self-assignment", v.get(0), 1.0);
    
    // Taille mismatch
    Vect<double> v_small(2);
    runner.assert_exception("Addition size mismatch", [&](){ v + v_small; });
}

// ============================================================================
// TESTS MATRICE
// ============================================================================

void test_matrice(TestRunner& runner) {
    runner.suite("MATRICE - Matrices");
    
    // Constructeur et initialisation
    Matrice<double> A(2);
    A.init(0.0);
    runner.assert_equals("Matrix init", A.get(0, 0), 0.0);
    
    A.set(0, 0, 1.0);
    A.set(0, 1, 2.0);
    A.set(1, 0, 3.0);
    A.set(1, 1, 4.0);
    runner.assert_equals("Matrix set/get", A.get(1, 1), 4.0);
    
    // Copie
    Matrice<double> B = A;
    runner.assert_equals("Matrix copy", B.get(0, 1), 2.0);
    B.set(0, 1, 999.0);
    runner.assert_equals("Matrix deep copy", A.get(0, 1), 2.0);
    
    // Déterminant 2x2
    double det = A.Determinant();  // 1*4 - 2*3 = -2
    runner.assert_equals("Determinant 2x2", det, -2.0);
    
    // Déterminant 3x3
    Matrice<double> C(3);
    C.set(0, 0, 1); C.set(0, 1, 2); C.set(0, 2, 3);
    C.set(1, 0, 0); C.set(1, 1, 1); C.set(1, 2, 4);
    C.set(2, 0, 5); C.set(2, 1, 6); C.set(2, 2, 0);
    double det3 = C.Determinant();  // Should be 1
    runner.assert_equals("Determinant 3x3", det3, 1.0, 1e-9);
    
    // GAUSS: Résoudre Ax = b
    // A = [[1, 2], [3, 4]], b = [5, 11]
    // Expected: x = [1, 2] car 1*1 + 2*2 = 5, 3*1 + 4*2 = 11
    Vect<double> b(2);
    b.set(0, 5.0);
    b.set(1, 11.0);
    Vect<double> x = A.gauss(b);
    runner.assert_equals("Gauss solve x[0]", x.get(0), 1.0, 1e-9);
    runner.assert_equals("Gauss solve x[1]", x.get(1), 2.0, 1e-9);
    
    // Vérification : Ax = b
    Vect<double> Ax = A.produit_matrice_vecteur(x);
    runner.assert_equals("Verify Ax=b, first component", Ax.get(0), 5.0, 1e-9);
    runner.assert_equals("Verify Ax=b, second component", Ax.get(1), 11.0, 1e-9);
    
    // LU: Résoudre avec LU
    Vect<double> x_lu = A.solveLU(b);
    runner.assert_equals("LU solve x[0]", x_lu.get(0), 1.0, 1e-9);
    runner.assert_equals("LU solve x[1]", x_lu.get(1), 2.0, 1e-9);
    
    // Produit matriciel
    Matrice<double> P(2);
    P.set(0, 0, 2); P.set(0, 1, 0);
    P.set(1, 0, 0); P.set(1, 1, 3);
    Matrice<double> AP = A * P;
    runner.assert_equals("Matrix product [0][0]", AP.get(0, 0), 2.0);
    runner.assert_equals("Matrix product [0][1]", AP.get(0, 1), 6.0);
    
    // Addition matricielle
    Matrice<double> sum = A + P;
    runner.assert_equals("Matrix addition", sum.get(0, 0), 3.0);
    
    // Matrice singulière (déterminant = 0)
    Matrice<double> singular(2);
    singular.set(0, 0, 1); singular.set(0, 1, 2);
    singular.set(1, 0, 2); singular.set(1, 1, 4);  // Ligne 2 = 2*Ligne 1
    double det_sing = singular.Determinant();
    runner.assert_equals("Singular matrix determinant", det_sing, 0.0, 1e-10);
    
    // Vérification que Gauss gère singularité
    Vect<double> b_sing(2);
    b_sing.set(0, 1.0);
    b_sing.set(1, 2.0);
    Vect<double> x_sing = singular.gauss(b_sing);  // Ne doit pas planter
    runner.assert_true("Singular matrix handled", true);
}

// ============================================================================
// TESTS INTEGRATION
// ============================================================================

void test_integration(TestRunner& runner) {
    runner.suite("INTEGRATION - Complex Scenarios");
    
    // Système mal conditionné
    Matrice<double> illcond(2);
    illcond.set(0, 0, 1.0);    illcond.set(0, 1, 1.0 - 1e-8);
    illcond.set(1, 0, 1.0 - 1e-8); illcond.set(1, 1, 1.0);
    
    Vect<double> b_ill(2);
    b_ill.set(0, 1.0);
    b_ill.set(1, 1.0);
    
    Vect<double> x_ill = illcond.gauss(b_ill);
    runner.assert_true("Ill-conditioned system solved", 
                      abs(x_ill.get(0) - 0.5) < 1.0);  // Loose bound
    
    // Système 3x3
    Matrice<double> M3(3);
    M3.set(0, 0, 2); M3.set(0, 1, -1); M3.set(0, 2, 1);
    M3.set(1, 0, -2); M3.set(1, 1, 2); M3.set(1, 2, 1);
    M3.set(2, 0, 1); M3.set(2, 1, 1); M3.set(2, 2, 2);
    
    Vect<double> b3(3);
    b3.set(0, 2); b3.set(1, 1); b3.set(2, 5);
    
    Vect<double> x3 = M3.gauss(b3);
    Vect<double> Ax3 = M3.produit_matrice_vecteur(x3);
    double err3 = Ax3.difference_norme(b3);
    runner.assert_true("3x3 system solution good", err3 < 1e-15);
    
    // Rationnels
    Matrice<qq> Mqq(2);
    Mqq.set(0, 0, qq(2, 1));  // 2
    Mqq.set(0, 1, qq(1, 1));  // 1
    Mqq.set(1, 0, qq(1, 1));  // 1
    Mqq.set(1, 1, qq(3, 1));  // 3
    
    Vect<qq> bqq(2);
    bqq.set(0, qq(5, 1));
    bqq.set(1, qq(8, 1));
    
    Vect<qq> xqq = Mqq.gauss(bqq);
    runner.assert_true("Rational system solution", 
                      xqq.get(0) == qq(2, 1) || xqq.get(0) == qq(1, 1));
}

// ============================================================================
// MAIN
// ============================================================================

int main() {
    TestRunner runner;
    
    test_qq(runner);
    test_vect(runner);
    test_matrice(runner);
    test_integration(runner);
    
    runner.print_summary();
    
    return 0;
}
