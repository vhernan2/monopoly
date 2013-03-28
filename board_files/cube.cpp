#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "res_texture.c"
#include "shader_utils.h"
/*
GLint uniform_m_transform;

GLuint program;
GLint attribute_coord3d, attribute_v_color;
GLuint vbo_cube, vbo_cube_colors;
GLint uniform_fade;
*/

int screen_width=800, screen_height=600;
GLuint vbo_cube_vertices, vbo_cube_texcoords;
GLuint ibo_cube_elements;
GLuint program;
GLint attribute_coord3d, attribute_v_color, attribute_texcoord;
GLint uniform_mvp;
GLuint texture_id;
GLint uniform_mytexture;


int init_resources(void){

	GLfloat cube_vertices[] = {
	//front
	-1.0, -1.0, 1.0,
	1.0, -1.0, 1.0,
	1.0, 1.0, 1.0,
	-1.0, 1.0, 1.0,
	//back 
	-1.0, -1.0, -1.0,
        1.0, -1.0, -1.0,
        1.0, 1.0, -1.0,
        -1.0, 1.0, -1.0,
	};

	glGenBuffers(1, &vbo_cube_vertices);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_cube_vertices);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);

	GLfloat cube_texcoords[] = {
		0.0, 0.0,
		1.0, 0.0,
		1.0, 1.0,
		0.0, 1.0,
	};
	glGenBuffers(1, &vbo_cube_texcoords);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_cube_texcoords);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_texcoords), cube_texcoords, GL_STATIC_DRAW);

	GLushort cube_elements[] = {
		//front
		0, 1, 2,
		2, 3, 0,
		//top
		1, 5, 6,
		6, 2, 1,
		//back
		7, 6, 5,
		5, 4, 7,
		//bottom
		4, 0, 3,
		3, 7, 4,
		//left
		4, 5, 1,
		1, 0, 4,
		//right
		3, 2, 6,
		6, 7, 3,
	};
	glGenBuffers(1, &ibo_cube_elements);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_cube_elements);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_elements), cube_elements, GL_STATIC_DRAW);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D,
		0,
		GL_RGB,
		res_texture.width,
		res_texture.height,
		0,
		GL_RGB,
		GL_UNSIGNED_BYTE,
		res_texture.pixel_data);

	//GLint compile_ok = GL_FALSE;
	GLint link_ok = GL_FALSE;

GLuint vs, fs;
  if ((vs = create_shader("cube.v.glsl", GL_VERTEX_SHADER))   == 0) return 0;
  if ((fs = create_shader("cube.f.glsl", GL_FRAGMENT_SHADER)) == 0) return 0;
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
 
	const char* attribute_name;
	attribute_name = "coord3d";
	attribute_coord3d = glGetAttribLocation(program, attribute_name);
	if (attribute_coord3d == -1) {
		fprintf(stderr, "Could not bind attribute %s\n", attribute_name);
		return 0;
	}
	attribute_name = "texcoord";
	attribute_texcoord = glGetAttribLocation(program, attribute_name);
	if (attribute_texcoord == -1){
		fprintf(stderr, "Could not bind attribute %s\n", attribute_name);
		return 0;
	}

	const char* uniform_name;
	uniform_name = "mvp";
	uniform_mvp = glGetUniformLocation(program, uniform_name);
	if (uniform_mvp == -1) {
		fprintf(stderr, "Could not bind uniform %s\n", uniform_name);
		return 0;
	}

/*
	const char* uniform_name = "m_transform";
	uniform_m_transform = glGetUniformLocation(program, uniform_name);
	if (uniform_m_transform == -1) {
		fprintf(stderr, "Could not bind uniform %s\n", uniform_name);
		return 0;
	}
*/
	printf("End of init_resources()");

	return 1;
}

void idle(){

	float angle = glutGet(GLUT_ELAPSED_TIME) / 1000.0 * 45;  // 45° per second
	glm::vec3 axis_y(0, 1, 0);
	glm::mat4 anim = glm::rotate(glm::mat4(1.0f), angle, axis_y);
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 0.0, -4.0));
	glm::mat4 view = glm::lookAt(glm::vec3(0.0, 2.0, 0.0), glm::vec3(0.0, 0.0, -4.0), glm::vec3(0.0, 1.0, 0.0));
	glm::mat4 projection = glm::perspective(45.0f, 1.0f*screen_width/screen_height, 0.1f, 10.0f);
	glm::mat4 mvp = projection * view * model * anim;
	glUseProgram(program);
	glUniformMatrix4fv(uniform_mvp, 1, GL_FALSE, glm::value_ptr(mvp));
	glutPostRedisplay();

//	float move = sinf(glutGet(GLUT_ELAPSED_TIME) / 1000.0 * (2*3.14) /5);
//	float angle = glutGet(GLUT_ELAPSED_TIME) / 1000.0 * 45;
//	float cur_fade = sinf(glutGet(GLUT_ELAPSED_TIME) / 1000.0 * (2*3.14) / 5) /2 + .5;
//	glm::vec3 axis_z(0, 0, 1);
//	glm::mat4 m_transform = glm::translate(glm::mat4(1.0f), glm::vec3(move, 0.0, 0.0)) * glm::rotate(glm::mat4(1.0f), angle, axis_z);
//	glUseProgram(program);
//	glUniform1f(uniform_fade, cur_fade);
//	glUniformMatrix4fv(uniform_m_transform, 1, GL_FALSE, glm::value_ptr(m_transform));
//	glutPostRedisplay();

}

void onDisplay(){

	//set background to white
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glUseProgram(program);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glUniform1i(uniform_mytexture, 0);

	glEnableVertexAttribArray(attribute_coord3d);
//	glEnableVertexAttribArray(attribute_v_color);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_cube_vertices);


	printf("right before attribute coord3d\n");

	//Describe vertices array to OpenGL
	glVertexAttribPointer(
		attribute_coord3d, //attribute
		3, //number of elements per vertex (x,y)
		GL_FLOAT, //the type of each element
		GL_FALSE, //take out values as-is
		0, // next coord3d appears every 5 floats
		0
	);

	printf("right before texcoord\n");

	glEnableVertexAttribArray(attribute_texcoord);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_cube_texcoords);
	glVertexAttribPointer(
		attribute_texcoord, //attribute
		2, //number of elements per vertex, here (x,y)
		GL_FLOAT,
		GL_FALSE,
		0,
		0
	);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_cube_elements);
	int size; glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
	glDrawElements(GL_TRIANGLES, size/sizeof(GLushort), GL_UNSIGNED_SHORT, 0);

//	printf("right before glDrawArrays is called in onDisplay\n");
//	glDrawArrays(GL_TRIANGLES, 0, 3);
	printf("Disabling attribute_coord3d\n");
	glDisableVertexAttribArray(attribute_coord3d);
	printf("Disabling attribute_v_color\n");
	glDisableVertexAttribArray(attribute_texcoord);
	//display result
	printf("right before glutSwapBuffers\n");
	glutSwapBuffers();

	printf("end of onDisplay()\n");

}

void onReshape(int width, int height) {

	screen_width = width;
	screen_height = height;
	glViewport(0, 0, screen_width, screen_height);

}

void free_resources(){
	glDeleteProgram(program);
	glDeleteBuffers(1, &vbo_cube_vertices);
	glDeleteBuffers(1, &vbo_cube_texcoords);
	glDeleteBuffers(1, &ibo_cube_elements);
	glDeleteTextures(1, &texture_id);
}

int main (int argc, char* argv[]){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_ALPHA|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(screen_width, screen_height);
	glutCreateWindow("Check it out, a cube! And it rotates!");

	//Extension wrangler initializing
	GLenum glew_status = glewInit();
	if (glew_status != GLEW_OK){
		fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_status));
		return 1;
	}

	//init resources creates the GLSL program
	if (1 == init_resources()){
		//onDisplay draws the cube
		glutDisplayFunc(onDisplay);
		glutReshapeFunc(onReshape);
		glutIdleFunc(idle);
		glEnable(GL_BLEND);
		glEnable(GL_DEPTH_TEST);
		//glDepthFunc(GL_LESS);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glutMainLoop();
	}
	
	//free_resources destroys the GLSL program
	free_resources();
	return 0;

}
