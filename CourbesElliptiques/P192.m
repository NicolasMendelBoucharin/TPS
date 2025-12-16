//Exercice 1.
"Exercice 1.";

//a)
"a)";
ZZ := Integers();
p := 6277101735386680763835789423207666416083908700390324961279;
k := GF(p);
n := 6277101735386680763835789423176059013767194773182842284081;
b := elt<ZZ|0x64210519e59c80e70fa7e9ab72243049feb8deecc146b9b1>;
Gx := elt<ZZ|0x188da80eb03090f67cbf20eb43a18800f4ff0afd82ff1012>;
Gy := elt<ZZ|0x07192b95ffc8da78631011ed6b24cdd573f977a11e794811>;
E := EllipticCurve([k!(-3),b]);
G:=E![Gx,Gy];
//pas de messages d'erreurs donc on est bien dedans 

//b)
"b)";
time #E;
card := #E;

//c)
"c)";
r :=6277101735386680763835789423176059013767194773182842284081;
IsPrime(card);
card eq r;

//d)
"d)";
r*G;
q:=p;
borneba:=q+1-2*Sqrt(2);
bornehau :=q+1-2*Sqrt(2);
2*r ge bornehau;
//comme r est le seul kr compris dans la borne et que r est l'ordre de Q on a bien que r est le cardinal

//e)
"e)";
a:=q+1-card;
cardtwist:=q+1+a;
//Factorisation(cardtwist); j'ai commenté parce que ça prends trop de temps
//on voit que une fois factorisé on a un facteur 23 dans le card du twist donc un sous groupe petit et donc pas twist secure

//Exercice 2.
"Exercice 2.";
//NIST 521
p:=6864797660130609714981900799081393217269435300143305409394463459185543183397656052122559640661454554977296311391480858037121987999716643812574028291115057151;
k := GF(p);
r:= 6864797660130609714981900799081393217269435300143305409394463459185543183397655394245057746333217197532963996371363321113864768612440380340372808892707005449;
b:=  elt<ZZ|1093849038073734274511112390766805569936207598951683748994586394495953116150735016013708737573759623248592132296706313309438452531591012912142327488478985984>;
Gx:= elt<ZZ|2661740802050217063228768716723360960729859168756973147706671368418802944996427808491545080627771902352094241225065558662157113545570916814161637315895999846>;
Gy:= elt<ZZ|3757180025770020463545507224491183603594455134769762486694567779615544477440556316691234405012945539562144444537289428522585666729196580810124344277578376784>;
E := EllipticCurve([k!(-3),b]);
G:=E![Gx,Gy];

//a)
"a)";

P:=Random(E);

//b)
"b)";

somme := function(P, Q)
    m:= (Q[2]-P[2])/(Q[1]-P[1]);
    x3:=m^2 -P[1] -Q[1];
    y3:=m*(P[1]-x3) - P[2];
    return E![k!(x3), k!(y3)];
end function;

//c)
"c)";
time for i:=1 to 5000 do
P:=somme(P,G);
end for;

time for i:=1 to 5000 do
P:= P+G;
end for;

//d)

jacob := function(P,Q)
    X1 := P[1];
    Y1 := P[2];
    Z1 := P[3];
    X2 := Q[1];
    Y2 := Q[2];
    Z2 := Q[3];

    A := X1*Z2^2;
    B := X2*Z1^2;
    C := Y1*Z2^3;
    D := Y2*Z1^3;
    E := B - A;
    F := D-C;
    
    X3 := -E^3 - 2*A*E^2 + F^2;
    Y3 := -C*E^3 + F*(A*E^2-X3);
    Z3 := Z1*Z2*E;
    return [X3, Y3, Z3];
end function;


time for i:=1 to 5000 do
P:=jacob(P,G);
end for;

doublejacob := function(P)
    X1 := P[1];
    Y1 := P[2];
    Z1 := P[3];
    A := 4*X1*Y1^2;
    B := 3*X1^2 -3*Z1^4;
    
    X3 := -2*A+B^2;
    Y3 := -8*Y1^4 + B*(A-X3);
    Z3 := 2*Y1*Z1;
    return [X3, Y3, Z3];
end function;

time for i:=1 to 5000 do
P:=doublejacob(P);
end for;

//e)

//5)

fenetrejacob := function(P, n)
    L := Intseq(n);
    i := #L-2;
    res := P;
    while (i ge 0) do 
        res := doublejacob(res);
        if (L[i] = 1) then
            res := jacob(res, P);
        end if;
    i := i-1;
    end while;
    return res;
end function;

//Exercice 3 :

"Exercice 3"

//a)

"a)"


