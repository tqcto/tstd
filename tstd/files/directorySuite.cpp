#include "directorySuite.hpp"
extern "C" {
#include "../converter/converter.h"
}

directorySuite::directorySuite(const char* directory_path) {

	char2wchar((char*)directory_path, this->path);

}
directorySuite::directorySuite(char* directory_path) {

	char2wchar(directory_path, this->path);

}
directorySuite::directorySuite(const wchar_t* directory_path) {

	memcpy(this->path, directory_path, sizeof(wchar_t) * TSTD_MAX_PATH_UNIC);

}
directorySuite::directorySuite(wchar_t* directory_path) {

	memcpy(this->path, directory_path, sizeof(wchar_t) * TSTD_MAX_PATH_UNIC);

}

directorySuite::~directorySuite() {



}
