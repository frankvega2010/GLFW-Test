/*
 * This is a very basic Windows C application for testing GLUT (and compatible
 * implementations such as freeglut). It displays a red square, and exits when
 * the escape key is pressed.
 */
#include <GL/glew.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#include "Callbacks.h"

 /* Main method */
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	/* Create a single window with a keyboard and display callback */
	glutCreateWindow("GLUT Test");
	glutKeyboardFunc(&keyboard);
	glutDisplayFunc(&display);

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

	/* Run the GLUT event loop */
	glutMainLoop();

	return EXIT_SUCCESS;
}