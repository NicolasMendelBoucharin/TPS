theory TP2
  imports Main
begin

(*Exercice 1:*)

fun isSet:: "'a list \<Rightarrow> bool"
  where
  "isSet Nil =  True" |
  "isSet (x#xs) = (~(List.member xs x) \<and> (isSet xs))"

value "isSet[(1::nat), 2, 3] "
value "isSet[1::nat, 2, 3, 1]"

(* Exercice 2:*)

fun clean:: " 'a list \<Rightarrow> 'a list"
  where
"clean Nil = Nil" |
"clean(x#xs) = (if (List.member xs x) then clean xs else x#(clean xs))"

value "clean[1::nat, 2, 3, 4, 3, 2, 1]"


(*Exercice 3:*)

lemma memberclean:"
(List.member (clean xs) y ) \<longleftrightarrow> (List.member xs y)
"
  apply (induct xs)
   apply simp
  by (metis clean.simps(2) member_rec(1))




 

(*Exercice 4:*)

lemma issetclean:"
(isSet L) \<longrightarrow> ((clean L) = L)
"

  apply (induct L)
  using clean.simps(1) apply blast
  by simp


lemma issetcleanbis:"
isSet(clean L)
"

  apply (induct L)
  apply simp
  by (simp add: memberclean)

(*Exercice 5:*)

fun delete::" 'a  \<Rightarrow> 'a list \<Rightarrow> 'a list"
  where
"delete x []  = []" |
"delete x (y#ys)  = (if x=y then delete x ys else y#delete x ys)"

value " delete 1 [1::nat, 2, 3, 1, 5]"

(*Exercice 6:*)

lemma memberdelete: "
\<not>(List.member (delete x L)  x )
"
  apply (induct L)
  apply (simp add: member_rec(2))
  by (metis delete.simps(2) member_rec(1))
   

  

(*Exercice 7:*)

fun intersection:: "'a list \<Rightarrow> 'a list \<Rightarrow> 'a list"
  where
"intersection xs [] = []" |
"intersection [] xs = []" |
"intersection (x#xs) ys = (if List.member ys x then (x#intersection xs ys) else intersection xs ys)"

(*Exercice 8:*)

lemma memberintersect: "
List.member (intersection L K) x =( (List.member L x) \<and> (List.member K x) )
"
  apply (induct L)
  apply (smt (verit, ccfv_SIG) intersection.elims member_rec(2) neq_Nil_conv)
  by (smt (verit) intersection.elims list.discI list.sel(3) member_rec(1))
 
(*Exercice 9:*)


lemma setintersect: "
isSet(L) \<and> isSet(K) \<longrightarrow> isSet(intersection L K)
"
  apply (induct L )
  apply (metis intersection.simps(1) intersection.simps(2) isSet.elims(2))
  by (smt (verit) intersection.elims isSet.simps(2) list.sel(3) memberintersect)

  
  

(*Exercice 10:*)

fun union :: "'a list  \<Rightarrow> 'a list \<Rightarrow> 'a list"
  where 
"union [] xs = xs" |
"union (x#xs) ys = union xs (x#(delete x ys))"

value " union [1::nat, 2, 3] [2::nat, 5, 4]"




(*Exercice 11:*)
lemma memberunionhelp: "
((List.member L x )) \<longrightarrow> (List.member (union L K) x)

"

  apply (induct L)
  using member_rec(2) apply force
  


lemma memberunion: "
List.member (union L K) x =((List.member L x) \<or> (List.member K x))
"

  
  


(*Exercice 12:*)

lemma "
 (isSet(K) \<and> isSet(L))\<longrightarrow>(isSet(union L K)) 
"
  nitpick
  


(*Exercice 13:*)

(*
fun equal:: "'a list \<Rightarrow> 'a list \<Rightarrow> bool"
  where 
"equal [] [] = True" |
"equal xs [] = False" |
"equal [] ys = False" |
"equal (x#xs) ys =( if List.member ys x then ( equal xs (delete x ys)) else False)"
*)

fun includee:: " 'a list \<Rightarrow> 'a list \<Rightarrow> bool"
  where
"includee []  xs = True"|
"includee (x#xs) [] = False"|
"includee (x#xs) ys = ((List.member ys x) \<and> (includee xs ys)) "


fun equal:: "'a list \<Rightarrow> 'a list \<Rightarrow> bool"
  where
  "equal xs ys = ((includee xs ys) \<and> (includee ys xs))"
  

value "equal [1::nat, 2 , 3] [2::nat, 1, 3, 4] "

(*Exercice 14:*)
lemma "
 (equal xs ys) \<longleftrightarrow> ((List.member ys x) \<longleftrightarrow> (List.member xs x))
"

  nitpick
end

