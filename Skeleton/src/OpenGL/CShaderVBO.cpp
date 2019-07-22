#include "CShaderVBO.h"
#include <atltrace.h>

GLfloat g_aVertices[] =
{
	-0.5f, -0.5f, 0.f, //0 
	1.f, 0.f, 0.f, //

	0.5f, -0.5f, 0.f, //2
	0.f, 1.f, 0.f, //

	0.5f, 0.5f, 0.f, //4
	0.f, 0.f, 1.f, //

	-0.5f, 0.5f, 0.f, //6
	0.f, 1.f, 0.f, //		
};

GLuint g_aIndexs[] =
{
	0, 1, 2,
	0, 2, 3,
};

CShaderVBO::CShaderVBO()
	: m_uiVAO(0), m_uiVBO(0), m_uiEBO(0)
{
}

CShaderVBO::~CShaderVBO()
{
}

bool CShaderVBO::GLBind()
{
	if (!m_uiVAO)
	{
		ATLASSERT(false);
		ATLTRACE("[error] not found vao");
		return false;
	}

	glBindVertexArray(m_uiVAO);

	return true;
}

void CShaderVBO::GLUnbind()
{
	glBindVertexArray(0);
}

bool CShaderVBO::GLLoadVBO(unsigned int eShaderType)
{
	switch (eShaderType)
	{
	case E_SHADER_GLFW:
		{
			glGenVertexArrays(1, &m_uiVAO);
			glGenBuffers(1, &m_uiVBO);
			glGenBuffers(1, &m_uiEBO);

			glBindVertexArray(m_uiVAO);
			{
				glBindBuffer(GL_ARRAY_BUFFER, m_uiVBO);
				glBufferData(GL_ARRAY_BUFFER, sizeof(g_aVertices), g_aVertices, GL_STATIC_DRAW);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_uiEBO);
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(g_aIndexs), g_aIndexs, GL_STATIC_DRAW);

				// vertex, stride 6
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GL_FLOAT), (void*)0);
				glEnableVertexAttribArray(0);

				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GL_FLOAT), (void*)(3 * sizeof(GLfloat)));
				glEnableVertexAttribArray(1);
			}
			glBindVertexArray(0);
		}
		break;
	default:
		{
			ATLASSERT(false);
			ATLTRACE("[error] unknown type");
			return false;
		}
		break;
	}

	return true;
}