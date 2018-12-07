#include<GLFW\glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include<stb_image.h>
#include<iostream>
#include"ShaderManager.h"
#include"CommonTools\ShaderTool.h"
int main(int argc, char** argv) {
	if (!glfwInit()) {
		std::cout << "glfw初始化失败" << std::endl;
		return -1;
	}
	GLFWwindow *window = glfwCreateWindow(256, 256, "Test1", NULL, NULL);
	if (window == NULL) {
		std::cout << "glfwWindow创建失败" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	try {
		BaseManager<ShaderManager>::CreateInstance();
		std::cout << BaseManager<ShaderManager>::GetInstance()->GetName() << std::endl;
		BaseManager<ShaderManager>::DestroyInstance();
	}
	catch (ManagerException& e) {
		std::cout << e.msg << std::endl;
	}
	int textureWidth = -1;
	int textureHeight = -1;
	int textureChannels = -1;
	unsigned int textureID = -1;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	char input[100];
	std::cin>>input;
	char* content;
		content = ReadTextFile(input);
			std::cout<<"i="<<content<<std::endl;
		free(content);

		unsigned char* textureData = stbi_load("texture1.png", &textureWidth, &textureHeight, &textureChannels, 0);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, textureData);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		stbi_image_free(textureData);


	std::cout <<textureWidth<<":"<<textureHeight<< std::endl;
	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_FLAT);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glBindTexture(GL_TEXTURE_2D, textureID);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 1);
		glVertex2f(-1, -1);
		glTexCoord2f(1, 1);
		glVertex2f(1, -1);
		glTexCoord2f(1, 0);
		glVertex2f(1, 1);
		glTexCoord2f(0, 0);
		glVertex2f(-1, 1);
		glEnd();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
