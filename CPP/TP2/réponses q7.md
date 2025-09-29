Pour les translations de la question 7 : 


- On ne peut pas écrire C1 = C.translate_(x1, y1) car on a défini cette fonction comme une void qui ne retourne rien.
- 
- La fonction TranslateR ne crée pas de copies qu'on devrait supprimer après.
  
- La fonction TranslateN crée à chaque appel un nouvel objet Cercle de copie.


(Je ne sais pas trop quoi dire de plus mais si c'est pas assez précis je peux m'expliquer plus au prochain tp)