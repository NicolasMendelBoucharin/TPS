theory tp1
imports Main
begin

lemma "A \<or> B"
nitpick
oops

lemma "A \<and> B \<longrightarrow> B"
apply auto
done

lemma demorgan1: "A\<and>(B\<or>C) \<longleftrightarrow> (A\<and>B) \<or> (A\<and>C) "
  apply auto
  done 

lemma demorgan2: "(\<not>(A\<and>B)) \<longleftrightarrow> (\<not>A \<or> \<not>B)"
  apply auto
  done


lemma exercice2: "
\<not>(
((\<not>E)\<longrightarrow>C) 
\<and>
(C\<longrightarrow>K)
\<and>
(M\<longrightarrow>(\<not>D))
\<and>
(D\<longleftrightarrow>E)
\<and>
(K\<longrightarrow>(E\<and>M))
\<and>
(E\<longrightarrow>K)
)
"

  apply auto
  done

(* le club ne peut pas accepter des membres *)

lemma exercice2suite: "
\<not>(
(C\<longrightarrow>K)
\<and>
(M\<longrightarrow>(\<not>D))
\<and>
(D\<longleftrightarrow>E)
\<and>
(K\<longrightarrow>(E\<and>M))
\<and>
(E\<longrightarrow>K)
)
"

  apply auto
  oops

(*si on enleve la premiere condition le club 
peut accepter des membres non ecossais pied nu 
qui ne sortent pas le dimanche qui ne sont pas maries
 et qui ont les fesses à l'air *)

lemma exercice3:"
\<not>(\<forall>x y z::nat. ((x+y)>(x+z)) \<longrightarrow> ((x+x)>(y+z))) 

"
  apply auto
  done

(*ça marche jamais *)

lemma exercice32:"
\<forall>x y::nat. (x+y)\<le>(x*y)
"
  apply auto
  oops

(*vrai pour les entiers naturels non nuls*)

lemma exercice33:"
\<forall>x y z::nat. ((x>y)\<and>(z>0))\<longrightarrow>((x*z)>(y*z))
"
  apply auto
  done

(*youpi ça marche*)

lemma exercice34:"
\<exists>x::nat. (P(f(x))) \<longrightarrow> (\<forall>x::nat. P(f(x)))
"
  apply auto
  done

(*pas sûr de moi*)

lemma exercice41:"
\<forall>x y z::nat. x*(y+z) = (x*y) + (x*z)
"
  apply (simp add: add_mult_distrib2)
  done

lemma exercice42:"
\<forall>x y::nat. x+y=y+x
"
  apply auto
  done

lemma exercice43:"
\<exists>x::nat. \<forall>y::nat. x+y=y
"

  apply auto
  done

lemma exercice5:"
\<forall>L K.  append L K  =  append K L
"
 nitpick
  oops



end





