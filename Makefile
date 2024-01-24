all:loops recursives recursived loops loopd mains maindloop maindrec

loops: basicClassification.o advancedClassificationLoop.o NumClass.h
	ar -rc libclassloops.a basicClassification.o advancedClassificationLoop.o

recursives: basicClassification.o advancedClassificationRecursion.o NumClass.h
	ar -rc libclassrec.a basicClassification.o advancedClassificationRecursion.o

loopd: basicClassification.o advancedClassificationLoop.o NumClass.h
	gcc -shared -g -o libclassloops.so basicClassification.o advancedClassificationLoop.o -lm

recursived:basicClassification.o advancedClassificationRecursion.o NumClass.h
	gcc -shared -g -o libclassrec.so basicClassification.o advancedClassificationRecursion.o

mains: main.o recursives
	gcc -Wall -g -o mains main.c libclassrec.a -lm

maindloop: main.o loopd
	gcc -Wall -g -o maindloop main.c ./libclassloops.so -lm

maindrec: main.o recursived
	gcc -Wall -g -o maindrec main.c ./libclassrec.so -lm

clean:
	rm *.o *.so *.a mains maindloop maindrec