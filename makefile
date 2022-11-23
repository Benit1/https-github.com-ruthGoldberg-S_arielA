CC = gcc
AR =ar
OBJECTS_MAIN =main.o
OBJECTS_BASIC = basicClassification.o
OBJECTS_LOOP = advancedClassificationLoop.o
OBJECTS_RECURSION =advancedClassificationRecursion.o
FLAGS = -Wall -g

all:  loops loopd recursives recursived mains maindloop maindrec

loops: libclassloops.a 
loopd: libclassloops.so 

recursives: libclassrec.a 
recursived: libclassrec.so

mains: $(OBJECTS_MAIN) libclassrec.a
	$(CC)  $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a
	
maindloop:$(OBJECTS_MAIN) 
	$(CC)  $(FLAGS) -o maindloop $(OBJECTS_MAIN)  ./libclassloops.so 
	
maindrec:$(OBJECTS_MAIN) 
	$(CC)  $(FLAGS) -o maindrec $(OBJECTS_MAIN)  ./libclassrec.so
	
		
libclassloops.a: $(OBJECTS_BASIC) $(OBJECTS_LOOP)
	$(AR) -rcs libclassloops.a $(OBJECTS_BASIC) $(OBJECTS_LOOP)	
	
libclassrec.a: $(OBJECTS_BASIC) $(OBJECTS_RECURSION)
	$(AR) -rcs libclassrec.a $(OBJECTS_BASIC) $(OBJECTS_RECURSION)
	
libclassrec.so: $(OBJECTS_BASIC) $(OBJECTS_RECURSION)
	$(CC) -shared -o libclassrec.so $(OBJECTS_BASIC)  $(OBJECTS_RECURSION)	

libclassloops.so: $(OBJECTS_BASIC) $(OBJECTS_LOOP)
	$(CC) -shared -o libclassloops.so $(OBJECTS_BASIC)  $(OBJECTS_LOOP)


$(OBJECTS_BASIC): basicClassification.c NumClass.h
	$(CC) -fPIC $(FLAGS) -c basicClassification.c 

$(OBJECTS_LOOP): advancedClassificationLoop.c NumClass.h
	$(CC) -fPIC $(FLAGS) -c advancedClassificationLoop.c

$(OBJECTS_RECURSION): advancedClassificationRecursion.c NumClass.h	
	$(CC) -fPIC $(FLAGS) -c advancedClassificationRecursion.c

$(OBJECTS_MAIN): main.c NumClass.h
	$(CC)  -fPIC $(FLAGS) -c main.c

.PHONY: clean all
clean:
	rm -f *.o *.a *.so mains maindloop maindrec



