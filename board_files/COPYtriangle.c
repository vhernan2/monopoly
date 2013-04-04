#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "shader_utils.h"

GLuint program;
GLint attribute_coord2d;

int init_resources(void){
	GLint compile_ok = GL_FALSE, link_ok = GL_FALSE;

GLuint vs, fs;
  if ((vs = create_shader("triangle.v.glsl", GL_VERTEX_SHADER))   == 0) return 0;
  if ((fs = create_shader("triangle.f.glsl", GL_FRAGMENT_SHADER)) == 0) return 0;
	program = glCreateProgram();
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &link_ok);
	if (!link_ok) {
		fprintf(stderr, "glLinkProgram:");
		print_log(program);
		return 0;
	}
 
	const char* attribute_name = "coord2d";
	attribute_coord2d = glGetAttribLocation(program, attribute_name);
	if (attribute_coord2d == -1) {
		fprintf(stderr, "Could not bind attribute %s\n", attribute_name);
		return 0;
	}

	return 1;
}

void onDisplay(){

	//set background to white
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(program);
	glEnableVertexAttribArray(attribute_coord2d);
	GLfloat triangle_vertices[] = {
		0.0, 0.8,
		-0.8, -0.8,
		0.8, -0.8,
	};

	//Describe vertices array to OpenGL
	glVertexAttribPointer(
		attribute_coord2d, //attribute
		2, //number of elements per vertex (x,y)
		GL_FLOAT, //the type of each element
		GL_FALSE, //take out values as-is
		0, // no extra data between each position
		triangle_vertices // pointer to the C array
	);

	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(attribute_coord2d);

	//display result
	glutSwapBuffers();

}

void free_resources(){
	glDeleteProgram(program);
}

int main (int argc, char* argv[]){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutCreateWindow("My Second Triangle - Hello Blue World in Graphics");

	//Extension wrangler initializing
	GLenum glew_status = glewInit();
	if (glew_status != GLEW_OK){
		fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_status));
		return EXIT_FAILURE;
	}

	//init resources creates the GLSL program
	if (1 == init_resources()){
		//onDisplay draws the triangle
		glutDisplayFunc(onDisplay);
		glutMainLoop();
	}
	
	//free_resources destroys the GLSL program
	free_resources();
	return EXIT_SUCCESS;

}
