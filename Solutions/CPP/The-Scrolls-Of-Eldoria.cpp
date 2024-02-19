#include "pch.h"
#include "The-Scrolls-Of-Eldoria.h"

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s)
{
    size_t newLength = size * nmemb;
    try
    {
        s->append((char*)contents, newLength);
    }
    catch (std::bad_alloc&e) {
        std::cerr << "std::bad_alloc caught: " << e.what() << std::endl;
        return 0;
    }
    return newLength;
    }

 void FetchAndDecipherScroll(const std::string& url) 
 {
     std::cout << "Fetching scroll from " << url << std::endl;
     CURL* curl;
     CURLcode res;
     std::string readBuffer;

     curl = curl_easy_init();
     if (curl)
     {
         curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
         curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
         res = curl_easy_perform(curl);
         curl_easy_cleanup(curl);

         if (res == CURLE_OK)
         {
             std::regex secretsPattern("\\{\\*(.*?)\\*\\}");
             std::smatch matches;
             std::string::const_iterator searchStart(readBuffer.cbegin());
             while (std::regex_search(searchStart, readBuffer.cend(), matches, secretsPattern))
             {
                 std::cout << matches[1] << std::endl;
                 searchStart = matches.suffix().first;
             }
         }
         else
         {
             std::cerr << "An error occurred: " << curl_easy_strerror(res) << std::endl;
         }
     }
 }