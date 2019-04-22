NOM=DEJESUS_Mathieu-BAZIN_Sarah

#fichiers objet
FIC_O = main.o SS_SM.o jacobi.o

main: $(FIC_O)
	gcc -g -Wall $(FIC_O) $(OPT) -o main -lgmp

main.o: main.c SS_SM.h
	gcc -g -c -Wall main.c SS_SM.h

SS_SM.o: SS_SM.c SS_SM.h jacobi.h
	gcc -g -c -Wall SS_SM.c SS_SM.h jacobi.h

jacobi.o: jacobi.c jacobi.h
	gcc -g -c -Wall jacobi.c jacobi.h

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
