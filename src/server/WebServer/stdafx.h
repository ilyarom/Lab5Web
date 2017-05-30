#pragma once

#include <string>
#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <filesystem>
#include <vector>
#include <algorithm>

#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#include "httpparser\request.h"
#include "httpparser\httprequestparser.h"
#define RAPIDJSON_HAS_STDSTRING 1
#include "rapidjson\document.h"
#include "rapidjson\writer.h"

namespace filesystem = std::tr2::sys;
static const size_t MAX_BUFFER_SIZE = 1024;
static const std::string HOST = "0.0.0.0";
static const std::string PORT = "80";
static const std::string GET_REQUEST = "GET";
static const std::string DELETE_REQUEST = "DELETE";
static const std::string JSON_ARRAY_KEY = "elements";
static const std::string ROOT_DIRECTORY = "/";
static const std::string CLIENT_INDEX_PAGE = "index.html";
static const std::string CLIENT_FILES_STRUCTURE = "files";
static const std::string CLIENT_STYLES_DIRECTORY = "css/";
static const std::string CLIENT_SCRIPTS_DIRECTORY = "js/";
static const std::string SPECIAL_FILE_DIRECTORY = "files/";
static const std::string BASE_TYPE = "Application/octet-stream";
static const std::string TYPE_HTML = "Text/html";
static const std::string TYPE_PLAIN_TEXT = "Text/plain";
static const std::string TYPE_CSS = "Text/css";
static const std::string TYPE_JS = "Text/javascript";
static const std::string TYPE_JSON = "Application/json";
static const std::string CHARSET_UTF8 = "utf-8";
static const std::string CHARSET_WIN1251 = "windows-1251";
static const unsigned MAX_FILE_SIZE = 52428800;
static const std::map<std::string, std::string> CONTENT =
{
	{ ".html", "Text/html" },
	{ ".txt", "Text/plain" },
	{ ".css", "Text/css" },
	{ ".js", "Text/javascript" },
	{ ".json", "Application/json" },
	{ ".png", "Image/png" },
	{ ".jpg", "Image/jpeg" },
	{ ".jpeg", "Image/jpeg" },
	{ ".gif", "Image/gif" }
};
static const std::map<size_t, std::string> STATUSES =
{
	{ 200, "OK" },
	{ 400, "Bad request" },
	{ 403, "Forbidden" },
	{ 404, "Not Found" }
};
