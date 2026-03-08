p := 2^448-2^224-1 ; 
Fp :=GF(p) ;
n :=181709681073901722637330951972001133588410340171829515070372549795146003961539585716195755291692375963310293709091662304773755859649779 ;
A :=Fp !156326 ; B :=Fp !1 ;
Gu := Fp ! 5 ;
Gv := Fp ! 355293926785568175264127502063783334808976399387714271831880898435169088786967410002932673765864550910142774147268105838985595290606362 ;
G := [Gu,Gv] ;
a := (3-A^2 )/(3*B^2) ; b := (2*A^3-9*A)/(27*B^3) ;
E :=EllipticCurve([a,b]) ;


//comme ça c'est fait à l'avance
Binv := B^(-1);
Afois3Binv := A*(3*B)^(-1);
A_plus_2_div_4 := (A+2)/4;





Ladder := function(n, P)
//celle du cours en gros
//Moins lisible mais on m'a dit que ça vallait plus le coups de faire tout dans la même fonctoin
    T1_X :=Fp!1;
    T1_Z := Fp!0;
    T2_X := P[1];
    T2_Z := Fp!1;
    x:=P[1];
    bin:= Reverse(Intseq(n,2));
    for ni in bin do

    
        if ni eq 0 then 

            //Somme
            sp:=T1_X-T1_Z;
            sq:=T2_X-T2_Z;
            ap:=T1_X+T1_Z;
            aq:=T2_X+T2_Z;
            sqap := sq*ap;
            aqsp := aq*sp;
            X3 := ((sqap + aqsp)^2);
            Z3 := (x*(sqap - aqsp)^2);
            T2_X:= X3;
            T2_Z:= Z3;


            //doublage de T1
            //ap:=T1_X+T1_Z; déjà utilisé plus haut
            //sp:=T1_X-T1_Z;
            apsquared:=ap^2;
            spsquared:=sp^2;
            prod := (apsquared - spsquared);
            X3 := (apsquared * spsquared);
            Z3 := (prod*(spsquared + A_plus_2_div_4*prod));
            T1_X:=X3;
            T1_Z:=Z3;
        else 
            //Somme
            sp:=T2_X-T2_Z;
            sq:=T1_X-T1_Z;
            ap:=T2_X+T2_Z;
            aq:=T1_X+T1_Z;
            sqap := sq*ap;
            aqsp := aq*sp;
            X3 := ((sqap + aqsp)^2);
            Z3 := (x*(sqap - aqsp)^2);
            T1_X:= X3;
            T1_Z:= Z3;

            //doublage de T2
            //ap:=T2_X+T2_Z;
            //sp:=T2_X-T2_Z; déjà utilisé plus haut
            apsquared:=ap^2;
            spsquared:=sp^2;
            prod := (apsquared - spsquared);
            X3 := (apsquared * spsquared);
            Z3 := (prod*(spsquared + A_plus_2_div_4*prod));
            T2_X:=X3;
            T2_Z:=Z3;
        end if;     
    end for;
    return (T1_X/T1_Z);

end function;


LadderDPA := function(k, P)
//celle du cours en gros
//Moins lisible mais on m'a dit que ça vallait plus le coups de faire tout dans la même fonctoin
    T1_X :=Fp!1;
    T1_Z := Fp!0;
    T2_X := P[1];
    T2_Z := Fp!1;
    x:=P[1];
    r:=Random(n);
    bin:= Reverse(Intseq((k+r*n),2)); // on rajoute 0 en gros mais je capte pas pourquoi ça prends si longtemps

    for ni in bin do

    
        if ni eq 0 then 

            //Somme
            sp:=T1_X-T1_Z;
            sq:=T2_X-T2_Z;
            ap:=T1_X+T1_Z;
            aq:=T2_X+T2_Z;
            sqap := sq*ap;
            aqsp := aq*sp;
            X3 := ((sqap + aqsp)^2);
            Z3 := (x*(sqap - aqsp)^2);
            T2_X:= X3;
            T2_Z:= Z3;


            //doublage de T1
            //ap:=T1_X+T1_Z; déjà utilisé plus haut
            //sp:=T1_X-T1_Z;
            apsquared:=ap^2;
            spsquared:=sp^2;
            prod := (apsquared - spsquared);
            X3 := (apsquared * spsquared);
            Z3 := (prod*(spsquared + A_plus_2_div_4*prod));
            T1_X:=X3;
            T1_Z:=Z3;
        else 
            //Somme
            sp:=T2_X-T2_Z;
            sq:=T1_X-T1_Z;
            ap:=T2_X+T2_Z;
            aq:=T1_X+T1_Z;
            sqap := sq*ap;
            aqsp := aq*sp;
            X3 := ((sqap + aqsp)^2);
            Z3 := (x*(sqap - aqsp)^2);
            T1_X:= X3;
            T1_Z:= Z3;

            //doublage de T2
            //ap:=T2_X+T2_Z;
            //sp:=T2_X-T2_Z; déjà utilisé plus haut
            apsquared:=ap^2;
            spsquared:=sp^2;
            prod := (apsquared - spsquared);
            X3 := (apsquared * spsquared);
            Z3 := (prod*(spsquared + A_plus_2_div_4*prod));
            T2_X:=X3;
            T2_Z:=Z3;
        end if;     
    end for;
    return (T1_X/T1_Z);

end function;



M2W := function(P)

    x:= P[1]*Binv + Afois3Binv;
    y:= P[2]*Binv;
    return [x, y];
end function;




m2w:= function(xP)
    return (xP*Binv + Afois3Binv);
end function;

//Test de validité
//Merci du retour sur le pourquoi une coordonnée 
//mais au final j'avais compris en révisant le partiel j'avais juste oublié de mettre à jour le commentaire
k:=Random(n); 
(k*E!M2W(G))[1] eq m2w(LadderDPA(k,G));

//test de performance

time for i:=1 to 200 do k:=Random(n); T:=LadderDPA(k,G); end for;

