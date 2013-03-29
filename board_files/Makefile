CC=g++
LIBS = -lGL -lGLU -lm
FREEGLUT = /afs/nd.edu/user37/ccl/software/external/freeglut
ifneq "$(wildcard $(FREEGLUT))" ""
	INCPATH += -I$(FREEGLUT)/include
	LIBPATH += -L$(FREEGLUT)/lib
	LIBS += -lglut
endif
GLEW = /afs/nd.edu/user37/ccl/software/external/glew
ifneq "$(wildcard $(GLEW))" ""
	INCPATH += -I$(GLEW)/include
	LIBPATH += -L$(GLEW)/lib
	LIBS += -lGLEW
endif
GLM = /afs/nd.edu/user14/kmulholl/spring13/fundofcomp2/lab_project/glm
ifneq "$(wildcard $(GLM))" ""
	INCPATH += -I$(GLM)/include
endif

all: cube

cube: cube.o shader_utils.o
	$(CC) $(INCPATH) -o cube cube.o shader_utils.o $(LIBPATH) $(LIBS)

cube.o: cube.cpp res_texture.c
	$(CC) $(INCPATH) -c cube.cpp res_texture.c

shader_utils.o: shader_utils.c
	$(CC) $(INCPATH) -c shader_utils.c

clean:
	rm -f *.o cube
