#pragma once

class CServer
{
public:
	CServer();
	virtual void StartQueryHandle() = 0;
	~CServer();

protected:
	static std::string CreateResponse(size_t status, const std::string & contentType, const std::string & charset, const std::string & responseBody);
	WSADATA m_wsaData;
	struct addrinfo* m_address;
	struct addrinfo m_hints;
	int m_listenSocket;
};

