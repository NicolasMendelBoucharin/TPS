theory TP2_3
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
"union L K = clean (append L K)"

value " union [1::nat, 2, 3] [2::nat, 5, 4]"




(*Exercice 11:*)



lemma memberunion:"
(List.member (union L K) x) = ((List.member L x) \<or> (List.member K x))
"

  apply (induct L)
  apply (simp add: member_rec(2) memberclean)
  by (metis append_Cons member_rec(1) memberclean union.simps)

  


(*Exercice 12:*)

lemma "
 (isSet(K) \<and> isSet(L))\<longrightarrow>(isSet(union L K)) 
"
  nitpick
  


(*Exercice 13:*)

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

lemma equalmemberhelp1: "

 ((equal xs ys) \<longrightarrow> (\<forall>x. (List.member ys x) \<longrightarrow> (List.member xs x)))
"
  apply (induct xs)
  using includee.elims(2) apply fastforce

  
  

lemma equalmemberhelp2: "

(\<forall>x.  (List.member ys x) \<longleftrightarrow> (List.member xs x) ) \<longrightarrow> (equal xs ys)
"
  

lemma includemember:"

(\<forall>x. (List.member L x)\<longrightarrow>(List.member K x)) \<longrightarrow> (includee L K)
"

  apply (induct L)
  using includee.simps(1) apply blast
  by (smt (verit, del_insts) includee.elims(3) list.inject member_rec(1) member_rec(2))

lemma includememberbis:"
(includee L K) \<longrightarrow> (\<forall>x. (List.member L x)\<longrightarrow>(List.member K x))
"
  apply (induct L)
  apply (simp add: member_rec(2))
  by (metis includee.elims(2) includee.simps(3) member_rec(1) neq_Nil_conv)

lemma equalmember: "
 ( equal xs ys) \<longleftrightarrow> (\<forall>x. (List.member ys x) \<longleftrightarrow> (List.member xs x))
"
  apply auto
  apply (meson equal.elims(3) equalmemberhelp1)
  apply (simp add: equalmemberhelp1)
  using equalmemberhelp2 apply auto[1]
  by (meson equal.elims(2) equalmemberhelp2)

 

end

