CC = gcc
AR = ar
OBJECTS_MAIN = main.o
OBJECTS_LIB_LOOP = basicClassification.o advancedClassificationLoop.o
OBJECTS_LIB_RECURSIVE = basicClassification.o advancedClassificationRecursion.o
FLAGS = -Wall -g

all: loops recursives recursived loopd mains maindloop maindrec
loops: libclassloops.a
libclassloops.a:$(OBJECTS_LIB_LOOP)
	$(AR) -rcs libclassloops.a $(OBJECTS_LIB_LOOP)
recursives: libclassrec.a
libclassrec.a:$(OBJECTS_LIB_RECURSIVE)
	$(AR) -rcs libclassrec.a $(OBJECTS_LIB_RECURSIVE)
recursived: libclassrec.so
libclassrec.so:$(OBJECTS_LIB_RECURSIVE)
	$(CC) -shared -o libclassrec.so $(OBJECTS_LIB_RECURSIVE)
loopd: libclassloops.so
libclassloops.so:$(OBJECTS_LIB_LOOP)
	$(CC) -shared -o libclassloops.so $(OBJECTS_LIB_LOOP)
mains: $(OBJECTS_MAIN) libclassrec.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a
maindloop: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloops.so
maindrec: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) ./libclassrec.so
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
