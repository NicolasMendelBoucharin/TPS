p := 2^448-2^224-1 ; 
Fp :=GF(p) ;
n :=181709681073901722637330951972001133588410340171829515070372549795146003961539585716195755291692375963310293709091662304773755859649779 ;
A :=Fp !156326 ; B :=Fp !1 ;
Gu := Fp ! 5 ;
Gv := Fp ! 355293926785568175264127502063783334808976399387714271831880898435169088786967410002932673765864550910142774147268105838985595290606362 ;
G := [Gu,Gv] ;
a := (3-A^2 )/(3*B^2) ; b := (2*A^3-9*A)/(27*B^3) ;
E :=EllipticCurve([a,b]) ;




Somme := function(P, Q, x)
// ajouts : on fouille qu'une fois les listes
//on précalcules les produits internes 
    q1:=Q[1];
    q2:=Q[2];
    p1:=P[1];
    p2:=P[2];
    //q1p1 := q1*p1; ça sert à rien au final
    //q1p2 := q1*p2;
    //q2p1 := q2*p1;
    //q2p2 := q2*p2;
    //X3 := 4*q1p1^2 - 8*q1p1*q2p2 + 4*(q2p2)^2 //nouvelle version développé (pas sûr que ça soit plus efficace au final)
    //on précalcule plutot les additions et soustractions réutilisé
    sp:=p1-p2;
    sq:=q1-q2;
    ap:=p1+p2;
    aq:=q1+q2;
    sqap := sq*ap;
    aqsp := aq*sp;
    X3 := Fp!((sqap + aqsp)^2);
    Z3 := Fp!(x*(sq*ap - aq*sp)^2);
    return [X3, Z3];
end function;



Doublage := function(P)
//pareil qu'en haut en gros
    p1:=P[1];
    p2:=P[2];
    ap:=p1+p2;
    sp:=p1-p2;
    apsquared:=ap^2;
    spsquared:=sp^2;
    prod := Fp!(apsquared - spsquared);
    X3 := Fp!(apsquared * spsquared);
    //Z3 := Fp!(prod*((spsquared) + ((A+2)/4)*prod)); //pour ne pas recaculer X3 qui est caché dans le produit*(p1-p2)^2
    Z3 := Fp!(X3-spsquared*spsquared + ((A+2)/4)*prod); //pour ne pas recaculer X3 qui est caché dans le produit*(p1-p2)^2
    return [X3, Z3];
end function;



Ladder := function(n, P)
//celle du cours en gros
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



M2W := function(P)
//pareil il faudrait sans doute faire les inversions à part pour pas les faire deux fois
    x:= P[1]*B^(-1) + A *(3*B)^(-1);
    y:= P[2]*B^(-1);
    return [Fp!x, y];
end function;
//

m2w:= function(xP)
    return Fp!(xP*B^(-1) + A *(3*B)^(-1));
end function;

//Test de validité
//pas compris pourquoi on se contente d'une coordonnée
k:=Random(n); 
(k*E!M2W(G))[1] eq m2w(Ladder(k,G));

//test de performance

time for i:=1 to 200 do k:=Random(n); T:=Ladder(k,G); end for;
