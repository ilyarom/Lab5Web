#include "stdafx.h"
#include "Parser.h"

bool CRequestParser::Parse(const char str[])
{
	httpparser::HttpRequestParser::ParseResult result = m_parser.parse(m_request, str, str + strlen(str));
	return httpparser::HttpRequestParser::ParsingCompleted == result;
}

std::string CRequestParser::GetMethod() const
{
	return m_request.method;
}

std::string CRequestParser::GetPath() const
{
	return m_request.uri;
}
