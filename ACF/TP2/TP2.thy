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

fun delete:: 'a list \<Rightarrow> 'a \<Rightarrow> 'a list
  where
"delete(x#xs) = (if (List.member xs x)then  )"

end
