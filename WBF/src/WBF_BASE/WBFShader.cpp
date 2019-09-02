#include "stdafx.h"
#include "WBFShader.h"

#include <fstream>
#include <sstream>

CWBFShader::CWBFShader()
	: m_nProg(0)
{
}

CWBFShader::~CWBFShader()
{
}

void CWBFShader::GLCreateProgram()
{
	m_nProg = glCreateProgram();
}

void CWBFShader::GLAttachShader(unsigned int nShaderType, CString strPath)
{
	auto lambda_code = [](CString csFilePath, std::string& code)
	{
		std::ifstream ifs;
		ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try
		{
			std::stringstream rb;

			ifs.open(csFilePath);
			rb << ifs.rdbuf();
			ifs.close();

			code = rb.str();
		}
		catch (const std::exception&)
		{
			// unknown
			return FALSE;
		}

		return TRUE;
	};

	auto lambda_status = [](unsigned int id, unsigned int type)
	{
		int nCompile = 0;
		glGetShaderiv(id, type, &nCompile);
		if (!nCompile)
		{
			int nLogLength = 0;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &nLogLength);

			if (nLogLength > 0)
			{
				auto aLog = new char[nLogLength];
				glGetShaderInfoLog(id, nLogLength, &nLogLength, aLog);
				TRACE(aLog);
				delete[] aLog;
			}

			return FALSE;
		}

		return TRUE;
	};
		
	std::string code;
	if (!lambda_code(strPath, code))
		return;

	unsigned int nShader = glCreateShader(nShaderType);

	auto pCode = code.c_str();
	glShaderSource(nShader, 1, &pCode, NULL);
	glCompileShader(nShader);
	if (!lambda_status(nShader, GL_COMPILE_STATUS))
		return;

	glAttachShader(m_nProg, nShader);
	m_vShader.push_back(nShader);
}

void CWBFShader::GLLinkShader()
{
	auto lambda_status = [](unsigned int id, unsigned int type)
	{
		int nStatus = 0;
		glGetProgramiv(id, type, &nStatus);
		if (!nStatus)
		{
			int nLogLength = 0;
			glGetProgramiv(id, GL_INFO_LOG_LENGTH, &nLogLength);

			if (nLogLength > 0)
			{
				auto aLog = new char[nLogLength];
				glGetProgramInfoLog(id, nLogLength, &nLogLength, aLog);
				TRACE(aLog);
				delete[] aLog;
			}

			return FALSE;
		}

		return TRUE;
	};
	
	glLinkProgram(m_nProg);
	if (!lambda_status(m_nProg, GL_LINK_STATUS))
	{
		// unknown
	}

	for (auto sh : m_vShader)
		glDeleteShader(sh);
}