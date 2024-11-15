theory tp5
imports Main "~~/src/HOL/Library/Code_Target_Nat" ENSEMBLES
begin

type_synonym address= "nat*nat*nat*nat"
datatype rule= Drop "(address list)" | Accept "(address list)" 
type_synonym chain= "rule list"

definition "aChain1= [(Drop [(1,1,1,1)]),(Accept [(1,1,1,1),(2,2,2,2)])]"
definition "aChain2= [(Accept [(1,1,1,1),(2,2,2,2)]),(Drop [(1,1,1,1)])]"

(* ---------   This is the TRUSTED BASE! So do not modify those two functions! ------------ *)
(* But, you SHOULD carefully read their code to understand how chains are used *)

(* The function defining if an address is accepted by a chain *)
fun filter:: "address \<Rightarrow> chain \<Rightarrow> bool"
  where
"filter a [] = False" |
"filter a ((Accept al)#r) = (if (List.member al a) then True else (filter a r))"|
"filter a ((Drop al)#r) = (if (List.member al a) then False else (filter a r))" 

value "filter (1,1,1,1) aChain1"
value "filter (1,1,1,1) aChain2"
value "filter (2,2,2,2) aChain1"
value "filter (2,2,2,2) aChain2"

(* ------------------------------------------------------------------------------------------ *)
(* TP/Lab session starts here!*)

(* Counterexample generators and some useful options for this lab session *)
(* nitpick *)
(* nitpick [timeout=120] *)
(* quickcheck [tester=exhaustive] *)
(* quickcheck [tester=narrowing] *)
(* quickcheck [tester=narrowing, size=7, timeout=120] *)


(*Test*)

definition "aChain3= [(Drop [(1,1,1,1), (3,3,3,3)]),(Accept [(1,1,1,1),(2,2,2,2), (3,3,3,3)])]"
definition "aChain4= [(Accept [(1,1,1,1),(2,2,2,2)]),(Drop [(1,1,1,1)]), (Accept[(1,1,1,1)])]"

value "filter (1,1,1,1) aChain4"
value "filter (3,3,3,3) aChain3"

(* The function/predicate to program and to prove! *)

fun acceptation:: "chain \<Rightarrow> address list"
  where
"acceptation [] = []"|
"acceptation ((Accept l)#c1) = (union (acceptation c1) (clean l))"|
"acceptation ((Drop l)#c1) = (ENSEMBLES.deleteList (clean l) (acceptation c1))"


fun equal:: "chain \<Rightarrow> chain \<Rightarrow> bool"
  where
"(equal c1 c2) = (ENSEMBLES.equal (acceptation c1) (acceptation c2))"

lemma acceptation_isset_element:
"
 \<forall>a c. isSet (acceptation c) \<Longrightarrow> isSet (acceptation (a # c))
"

  apply auto
  done

lemma acceptation_isset:"
isSet (acceptation c)
"
  sorry
  
  

lemma acceptationfilter:"
(filter x c) \<longrightarrow> (List.member (acceptation c) x)
"
 
  sorry
   

lemma equalfilterdeddirect1:"
( equal c1 c2) \<longrightarrow> (\<forall>x. (filter x c1) \<longrightarrow>  (filter x c2))
"
  sorry

 

lemma equalfilterdeddirect2:"
( equal c1 c2) \<longrightarrow> (\<forall>x. (filter x c2) \<longrightarrow>  (filter x c1))
"

  apply auto
  by (meson ENSEMBLES.equal.elims(3) equalfilterdeddirect1 tp5.equal.elims(3))



lemma equalfiltertedindirect:"

 (\<forall>x. (filter x c1) \<longleftrightarrow>  (filter x c2))\<longrightarrow>( equal c1 c2)
"

  apply (induct c1)
   apply (induct c2)
    apply simp
  apply simp
  sorry

lemma equalfilterded: "
 ( equal c1 c2) \<longleftrightarrow> (\<forall>x. (filter x c1) \<longleftrightarrow> (filter x c2))
"
  using equalfilterdeddirect1 equalfilterdeddirect2 equalfiltertedindirect by blast


(*j'ai rien qui marche mais mon pc galère un peu avec sledghammer je ne sais pas dans quel mesure cela a un impact *)

  

  


(*
lemma " ? ? ?"
  nitpick  [timeout=120]
  quickcheck [tester=narrowing]
  oops
*)
(* Code exportation directive *)
export_code equal in Scala
end