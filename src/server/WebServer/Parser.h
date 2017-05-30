#pragma once

#include "stdafx.h"

class CRequestParser
{
public:
	bool Parse(const char str[]);
	std::string GetMethod() const;
	std::string GetPath() const;
private:
	httpparser::Request m_request;
	httpparser::HttpRequestParser m_parser;
};

