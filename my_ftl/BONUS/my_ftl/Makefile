CPP = gcc
LDFLAGS =  -lSDL -lSDL_image -lSDL_ttf
EXEC = ftl


SRC = 		my_ftl.c \
		rand.c \

OBJ =		$(SRC:%.c=%.o) 

${EXEC}: 	$(OBJ)
		${CPP} -g $(LDFLAGS) $(OBJ) -o $(EXEC) $(LDFLAGS)

all: 		${EXEC}

clean:
		rm -fr *.o

mrproper: 	clean
		rm -fr ${EXEC}
