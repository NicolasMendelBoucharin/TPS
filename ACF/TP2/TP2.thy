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

lemma exercice3:"
List.member(clean(x)) = List.member(x)
"
  nitpick

(*Exercice 4:*)

lemma exercice4:"
\<forall>L. isSet(L) \<longrightarrow> clean(L)=L
"
nipick
  oops

lemma exercice4bis:"
isSet(clean l )
"
nitpick

(*Exercice 5:*)

fun delete::" 'a  \<Rightarrow> 'a list \<Rightarrow> 'a list"
  where
"delete x []  = []" |
"delete x (y#ys)  = (if x=y then delete x ys else y#delete x ys)"


(*Exercice 6:*)

lemma  "
\<not>(List.member(delete x List)(x))
"
  nitpick
  sorry

(*Exercice 7:*)

fun intersection:: "'a list \<Rightarrow> 'a list \<Rightarrow> 'a list"
  where
"intersection xs [] = []" |
"intersection [] xs = []" |
"intersection (x#xs) ys = (if List.member ys x then (x#intersection xs ys) else intersection xs ys)"
(*Exercice 8:*)

lemma "
List.member (intersection L K) x = (List.member L x) \<and> (List.member K x) 
"
  nitpick
  oops

(*Exercice 9:*)

lemma "
isSet ( intersection K L)
"
  nitpick
  oops


(*Exercice 10:*)

fun union :: "'a list \<Rightarrow> 'a list \<Rightarrow> 'a list"
  where 
"union xs [] = xs" |
"union [] xs = xs" |
"union (x#xs) ys = (if List.member ys x then (x#union xs ys) else union xs ys)"

value " union [1::nat, 2, 3] [2::nat, 5, 4]"

(*visiblement faux du coup mdr*)


(*Exercice 11:*)

lemma  "
List.member (union L K) x =((List.member L x) \<or> (List.member K x))
"
  nitpick
  oops

(*Exercice 12:*)

lemma "
(isSet(union L K)) = (isSet(K) \<or> isSet(L))
"
  nitpick
  oops


(*Exercice 13:*)

fun equal:: "'a list \<Rightarrow> 'a list \<Rightarrow> bool"
  where 
"equal [] [] = True" |
"equal xs [] = False" |
"equal [] ys = False" |
"equal (x#xs) ys =( if List.member ys x then ( equal xs (delete x ys)) else False)"

value "equal [1::nat, 2 , 3] [2::nat, 1, 3, 4] "

(*Exercice 14:*)
lemma "
 
"
end

