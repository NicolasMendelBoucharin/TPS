//Question 1.
"Question 1.";

//a)
"a)";
i:=4;
"Le typer magma de l'entier", i, "est", Type(i);

//b)
"b)";
n:=10^29;
p:=NextPrime(n);
p;

//c)
"c)";
a := 123456789;
e :=12345678;
exponentiation:=Modexp(a,e,p);
exponentiation;

//d)
"d)";
elementprimitif:=PrimitiveElement(GF(p));
IsPrimitive(elementprimitif);
Order(elementprimitif) eq (p-1);

//e)
"e)";
FPt<t> := PolynomialRing(GF(p));
P := t^4 + t + 1;
while not IsIrreducible(P) do
    P := P+1;
end while;
P;

//f)
"f)";
FPquotient<x> := quo<FPt|P>;
pol:= x+1;
pol^(-1);

//g)
"g)";
discrim :=function( a1, a2, a3, a4, a6)
    b2:=a1^2 + 4*a2;
    b4:= 2*a4 +a1*a3;
    b6:= a3^2 + 4*a6;
    b8 := a1^2*a6+4*a2*a6-a1*a3*a4+a2*a3^2-a4^2;
    dis:=-b2^2*b8-8*b4^3-27*b6^2 + 9*b2*b4*b6;
    return dis;
end function;

//Question 2.
"Question 2.";

//a)
"a)";
vecteurdesa:=[0,1,0,0,1];
E:=EllipticCurve(vecteurdesa);
E;

//b)
"b)";
mondiscriminant:=discrim(0,1,0,0,1);
mondiscriminant;
Discriminant(E);

//c)
"c)";
jinv :=function( a1, a2, a3, a4, a6)
    b2:=a1^2 + 4*a2;
    b4:= 2*a4 +a1*a3;
    dis := discrim( a1, a2, a3, a4, a6);
    c4:=b2^2-24*b4;
    j:=c4^3/dis;
    return j;
end function;

j:=jinv(0,1,0,0,1);
j;
jInvariant(E);

//d)
"d)";
//i)
"i.";
"isomorphe car même j-invariant";
vecteurdesaprime:=[0,0,0,3*j/(1728-j),2*j/(1728-j)];
Eprime:=EllipticCurve(vecteurdesaprime);
jInvariant(Eprime);

//ii)
"ii)";
IsIsomorphic(E,Eprime);

//Question 3.
"Question 3.";

//a)
"a)";
F23:=GF(23); 
E:=EllipticCurve([F23!2,1]);

//b)
"b)";
#E;

//c)
"c)";
Points(E);

//d)
"d)";
P :=[2,17];
Q :=[9,9];
IsPoint(E,P);
IsPoint(E,Q);
E!P + E!Q;

//e)
"e)";
Order(E!P); //ordre 30
//généré par P ?

//f)
"f)";


// card:=0;
// for a in F23 do
//     for b in F23 do
//         c:=4*a^3+27*b^2;
//         if c ne 0 then
//             E2:=EllipticCurve([F23!a,b]);
//             if jInvariant(E2) eq jInvariant(E) then
//                 if #E2 eq 30 then
//                     card := card + 1;
//                     E2;
//                 end if;
                    
//             end if;
//         end if;
//     end for;
// end for;
// card;

// ne marche pas 

card:=0;
for j in F23 do
    E2:=EllipticCurveFromjInvariant(j);
    if #E2 eq 30 then
        E2;
        card:= card + 1;
    end if;
end for;
card;



//Question 4.

//flemme

//Question 5.
"Question 5.";

//a)
"a)";
R<ix,igrc> := PolynomialRing(Rationals(), 2);

//b)
"b)";
I:= Ideal(R!(igrc^2-ix^3-1));
Q<y,x>:=quo<R | I>;

//c)
"c)";
print y^2;



