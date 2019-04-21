NOM=DEJESUS_Mathieu-BAZIN_Sarah

#options de compilation
OPT = -lgmp

#fichiers objet
FIC_O = main.o SS_SM.o jacobi.o

main: $(FIC_O)
	gcc -g -Wall $(FIC_O) $(OPT) -o main

ex:
	./main 250967591999227657826035737101213190249364889593209500926828905337003986874210364637932820538143817283987165842706253714923770699474187521582136375564316109395344938206965824403323324542081796263603391438279496119389028258246917648843191985598346234715847035235717058523812623113392891270205429811723774700237 1000

main.o: main.c SS_SM.h
	gcc -g -c -Wall main.c

SS_SM.o: SS_SM.c SS_SM.h jacobi.h
	gcc -g -c -Wall SS_SM.c

jacobi.o: jacobi.c jacobi.h
	gcc -g -c -Wall jacobi.c

#ouvrir gmp.h dans geany
gmp:
	geany /usr/include/x86_64-linux-gnu/gmp.h

clean:
	rm -f *.o *.gch main
	rm -fr gmp-6.1.2
	rm -fr $(NOM) $(NOM).zip
	

zip: clean
	mkdir $(NOM)
	cp *.c $(NOM)
	cp *.h $(NOM)
	cp Makefile $(NOM)
	zip -r $(NOM).zip $(NOM)
	rm -fr $(NOM)
