exec: 
	make clean
	zip -r 22_lab0.zip Ejercicio_1 Ejercicio_2 integrantes.txt

clean:
	find . -type f -name '*.o' -exec rm {} \;
	find . -type f -name '*.hpp.gch' -exec rm {} \;
#	find . -type f -name '*.zip' -exec rm {} \;
	find . -type f -name 'executable' -exec rm {} \;
	@[ -f ./22_lab0.zip ] && rm 22_lab0.zip || true

