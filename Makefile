CC = gcc
AR = ar
FLAGS = -Wall -g

all: loops recursives recursived loopd mains maindloop maindrec
loops: libclassloops.a
libclassloops.a:basicClassification.o advancedClassificationLoop.o
	$(AR) -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o
recursives: libclassrec.a
libclassrec.a:basicClassification.o advancedClassificationRecursion.o
	$(AR) -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o
recursived: libclassrec.so
libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	$(CC) -shared -fPIC -o libclassrec.so basicClassification.o advancedClassificationRecursion.o
loopd: libclassloops.so
libclassloops.so:basicClassification.o advancedClassificationLoop.o
	$(CC) -shared -fPIC -o libclassloops.so basicClassification.o advancedClassificationLoop.o
mains: main.o libclassrec.a
	$(CC) $(FLAGS) -o mains main.o libclassrec.a
maindloop: main.o
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so
maindrec: main.o
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c
main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c
clean:
	rm -f *.o *.so *.a mains maindloop maindrec
