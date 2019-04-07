Pour installer la bibliothèque dans le répertoire par default "/usr/local" :

- Décompression de l'archive "gmp-6.1.2.zip"
- Exécution des commandes suivantes dans le répertoire "gmp-6.1.2" :
	(1) "./configure"
	(2) "make install"
	(3) "make check"

//################//



"make" ou "make main" pour compiler
"make test" pour tester plusieurs nombres
"make clean" pour supprimer les fichiers de compilation et le dossier gmp-6.1.2 décompréssé

l'exécutable se nomme "main"

//pour l'instant ça ne marche pas
"./main <nombre à tester> <nombre d'itérations>"

