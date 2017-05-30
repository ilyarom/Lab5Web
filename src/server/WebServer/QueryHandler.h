#pragma once
#include "Server.h"

class CQueryHandler : public CServer
{
public:
	CQueryHandler();
	virtual void StartQueryHandle() override;

private:

	std::string GetQueryHandle(const std::string & path);
	std::string DeleteQueryHandle(const std::string & path);

	bool Index(const std::string & path) const;
	bool FileStruct(const std::string & path) const;
	bool Css(const std::string & path) const;
	bool Scripts(const std::string & path) const;
	bool SpecialDir(const std::string & path) const;

	std::string HandleValidQueries(char buffer[], int res);

	std::string ContentResponse(const std::string & type, const std::string & path);
	std::string FileStructureResponse(const std::string & path);
	std::string FileResponse(const std::string & path);

	std::string DirectoryToJson();
	std::string GetJsonString(const rapidjson::Document & document);
	void GetFiles(std::vector<filesystem::path> & files, const filesystem::path & directoryPath);
	std::string GetContentTypeByExtension(const std::string & extension) const;
};
