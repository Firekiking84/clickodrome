

structure de t_gui:

	1er const char c'est le nom du fichier de comfiguration.
	2eme t_vector qui ce déplace de composant en composant(5) *1.
	3eme t_componant qui est une structure *2.
	4eme t_vectore qui ce déplace de div en div *3.

*1 I Chaque composant BUTTON comporte:

	type = button // le nom du composant //.
	pos = une position // x , y et z //.
	size = d'une taile // width et height //.
	name = d'un nom qui lui est l'ID.
	text = d'un texte.
	fond_color = d'une couleur sur le composant // red, blue, green //.
	bg = d'un fond // back groun //.
	hover_color = losrque le focus est sur le composant , il peut ne pas exister.
	functions = les differant fonction qui seront utiliser par le composant.

   II Chaque composant PICTURE comporte:

	type = picture // le nom du composant //.
	pos = une position // x , y et z //.
	size = d'une taile // width et height //.
	name = d'un nom qui lui est l'ID.
	img = a l'image a afficher.

   III Chaque composant TEXT_BOX comporte:

	type = text_box // le nom du composant //.
	pos = une position // x , y et z //.
	size = d'une taile // width et height //.
	name = d'un nom qui lui est l'ID.
	font = le nom du fichier qui contient la font.
	font_size = taille de l'image dans la quel nous allons mettre la couleur font_color.
	fond_color = d'une couleur sur le composant // red, blue, green //.
	bg = d'un fond // back groun //.
	functions = les differant fonction qui seront utiliser par le composant.

   IV Chaque composant LABEL comporte:

	type = label // le nom du composant //.
	pos = une position // x , y et z //.
	pos_end = la dernière position // x , y et z //.
	size = d'une taile // width et height //.
	name = d'un nom qui lui est l'ID.
	font =  je ne sais plus //.
	font_size = taille de l'image dans la quel nous allons mettre la couleur font_color.
	fond_color = d'une couleur sur le composant // red, blue, green //.
	bg = d'un fond // back groun //.

   V Chaque composant TIMER comporte:

	type = timer // le nom du composant //.
	last_time = dernière utilisation de timer.
	delay = le temps défini apres l'action.
	name = d'un nom qui lui est l'ID.
	functions = les differant fonction qui seront utiliser par le composant.

*2 structure component

	void *component // pour le cast //
	t_type type // le type du composant //.

*3 chaque div dispose:

	divName = d'un nom, // div1, div2, ... //.
	pos = d'une position, // x , y  z //.
	size = d'une taile, // width et height //.
