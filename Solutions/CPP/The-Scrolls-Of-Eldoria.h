#pragma once


static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s);
void FetchAndDecipherScroll(const std::string& url);