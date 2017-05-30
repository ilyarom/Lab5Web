#include "stdafx.h"
#include "Server.h"

CServer::CServer()
	: m_address(nullptr)
{
	if (0 != WSAStartup(MAKEWORD(2, 2), & m_wsaData))
	{
		throw std::runtime_error("WSAStartup failed");
	}

	ZeroMemory(&m_hints, sizeof(m_hints));

	m_hints.ai_family = AF_INET;
	m_hints.ai_socktype = SOCK_STREAM;
	m_hints.ai_protocol = IPPROTO_TCP;
	m_hints.ai_flags = AI_PASSIVE;

	if (0 != getaddrinfo(HOST.c_str(), PORT.c_str(), & m_hints, & m_address))
	{
		WSACleanup();
		throw std::runtime_error("getaddrinfo failed");
	}

	m_listenSocket = socket(m_address->ai_family, m_address->ai_socktype, m_address->ai_protocol);
	if (INVALID_SOCKET == m_listenSocket)
	{
		freeaddrinfo(m_address);
		WSACleanup();
		throw std::runtime_error("Creating of socket failed:" + WSAGetLastError());
	}

	if (SOCKET_ERROR == bind(m_listenSocket, m_address->ai_addr, (int)m_address->ai_addrlen))
	{
		freeaddrinfo(m_address);
		closesocket(m_listenSocket);
		WSACleanup();
		throw std::runtime_error("bind failed with error: " + WSAGetLastError());
	}

	if (SOCKET_ERROR == listen(m_listenSocket, SOMAXCONN))
	{
		closesocket(m_listenSocket);
		WSACleanup();
		throw std::runtime_error("listen failed with error: " + WSAGetLastError());
	}
}

CServer::~CServer()
{
	closesocket(m_listenSocket);
	freeaddrinfo(m_address);
	WSACleanup();
}

std::string CServer::CreateResponse(size_t status, const std::string & contentType, const std::string & charset, const std::string & responseBody)
{
	std::string result = "HTTP/1.1 " + std::to_string(status) + " " + STATUSES.find(status)->second + "\r\n"
		+ "Version: HTTP/1.1\r\n"
		+ "Content-Type: " + contentType;

	if ("" != charset)
	{
		result += "; charset=" + charset;
	}

	result += "\r\n";
	result += "Content-Length: " + std::to_string(responseBody.length());
	
	if (400 == status)
	{
		result += "\r\nConnection: close";
	}

	result += "\r\n\r\n" + responseBody;
	return result;
}
