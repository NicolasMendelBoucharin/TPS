//exercice 4


myseed := 2011; 

function EllipticCurveWithCM(n, d : Seed :=myseed)
    assert n ge 32 and d lt -3 and IsSquarefree(d);//Check arguments 
	SetSeed(Seed);				        
	N := Random(2^(n-1),2^n-1);		    
	p := NextPrime(N : Proof := false); 	
	
    //On fait l'algo du cours 6.1 en se basant sur l'exemple de juste après
	K := QuadraticField(d);O<w> := MaximalOrder(K);

    H := HilbertClassPolynomial(Discriminant(O));
	
	premier := false; //on cherche un cardinal premier
    m := 0;
    	
   
    repeat
        
        if KroneckerSymbol(Discriminant(O), p) eq 1 then

        	Ip := ideal<O | p>;
        	fac := Factorization(Ip);
        	P1 := fac[1][1];
            
            
        	principal, pi := IsPrincipal(P1);
        	if principal then
                // Trace du Frobenius
                a := Integers() ! Trace(pi);
                
                // Cardinaux possibles pour la courbe et sa tordue
                m1 := p + 1 - a;
                m2 := p + 1 + a;
                
                // On vérifie si l'un des cardinaux est premier
                if IsPrime(m1) then
                    m := m1;
                    premier := true;
                elif IsPrime(m2) then
                    m := m2;
                    premier := true;
                end if;
            end if;
        end if;
        if not premier then //si on trouve pas un cardinal premier ni dans la courbe ni la tordue on recommence
            p := NextPrime(p : Proof := false);
        end if;
    until premier;

    //On construit la courbe    
    Fp := GF(p);
    Fp_X := PolynomialRing(Fp);
    H_Fp := Fp_X ! H;
    j := Roots(H_Fp)[1][1]; //On trouve le J invariant
    
    //création de la courbe
    A := Fp ! (3*j / (1728 - j));
    B := Fp ! (2*j / (1728 - j));
    E := EllipticCurve([A, B]);

    //on trouve le point à l'infini    
    P := Random(E);
    while P eq E!0 do
        P := Random(E);
    end while;
    
    //Verification si le point à l'infini marche bien sinon on prend la tordue
    if m * P ne E!0 then
        delta := Fp ! 2;
        while IsSquare(delta) do //il faut un delta non carré
            delta +:= 1;
        end while;
        E := EllipticCurve([delta^2 * A, delta^3 * B]);
    end if;
	
	assert IsPrime(p) and IsPrime(m) and m*Random(E) eq E!0;
	return E, m; 				// Une courbe elliptique CM par Q(sqrt(-d)) et son nombre de points m
end function;

time E128, m128 := EllipticCurveWithCM(128, -35 : Seed := myseed); E128, m128;
//ça rame trop :(
//time E256, m256 := EllipticCurveWithCM(256, -51 : Seed := myseed); E256, m256;
//time E384, m384 := EllipticCurveWithCM(384, -59 : Seed := myseed); E384, m384;
//time E512, m512 := EllipticCurveWithCM(512, -83 : Seed := myseed); E512, m512;











