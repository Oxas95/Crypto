Pour installer la bibliothèque dans le répertoire par default "/usr/local" :

- Décompression de l'archive "gmp-6.1.2.zip"
- Exécution des commandes suivantes dans le répertoire "gmp-6.1.2" :
	(1) "./configure"
	(2) "make install"
	(3) "make check"

//################//



"make" ou "make main" pour compiler
"make clean" pour supprimer les fichiers de compilation et le dossier gmp-6.1.2 décompréssé

l'exécutable se nomme "main"

pour tester si un nombre est premier, le programme doit être exécuté de la façcon suivante :
"./main <nombre à tester> <nombre d'itérations>"

