p := 2448-2224-1 ; 
Fp :=GF(p) ;
n :=181709681073901722637330951972001133588410340171829515070372549795146003961539585716195755291692375963310293709091662304773755859649779 ;
A :=Fp !156326 ; B :=Fp !1 ;
Gu := Fp ! 5 ;
Gv := Fp ! 355293926785568175264127502063783334808976399387714271831880898435169088786967410002932673765864550910142774147268105838985595290606362 ;
G := [Gu,Gv] ;
a := (3-A^2 )/(3*B^2) ; b := (2*A^3-9*A)/(27*B^3) ;
E :=EllipticCurve([a,b]) ;


Somme := function(P, Q, x)
    X3 := Fp!(((Q[1]-Q[2])*(P[1] + P [2]) + (Q[1] + Q[2])*(P[1]-P[2]))^2);
    Z3 := Fp!(x*((Q[1]-Q[2])*(P[1] + P [2]) - (Q[1] + Q[2])*(P[1]-P[2]))^2);
    return [X3, Z3];
end function;


Doublage := function(P)
    prod := Fp!((P[1] + P[2]) ^ 2 - (P[1]-P[2])^2);
    X3 := Fp!(((P[1] + P[2])^2) * ((P[1] - P[2])^2));
    Z3 := Fp!(prod*( ((P[1] - P[2])^2) + ((A+2)/4)*prod));
    return [X3, Z3];
end function;


Ladder := function(n, P)
    T1 :=[Fp!1, 0];
    T2 := [Fp!P[1], 1];
    x:=P[1];
    bin:= Reverse(Intseq(n,2));
    for ni in bin do
        if ni eq 0 then 
            T2:=Somme(T1, T2, x);
            T1:= Doublage(T1);
        else 
            T1:=Somme(T1, T2, x);
            T2:= Doublage(T2);
        end if;
    end for;
    return Fp!(T1[1]/T1[2]);

end function;


Binv := B^(-1);
Binv3 := 3^(-1)*Binv ;

M2W := function(P)
    x:= P[1]*B^(-1) + A *(3*B)^(-1);
    y:= P[2]*B^(-1);
    return [Fp!x, y];
end function;
//

m2w:= function(xP)
    return Fp!(xP*B^(-1) + A *(3*B)^(-1));
end function;
//Test de validité
k:=Random(n); 
(k*E!M2W(G))[1] eq m2w(Ladder(k,G));

//test de performance

time for i:=1 to 200 do k:=Random(n); T:=Ladder(k,G); end for;
