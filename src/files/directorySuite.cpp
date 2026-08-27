#include "../../include/files/directorySuite.hpp"
extern "C" {
#include "../../include/converter/converter.h"
}

directorySuite::directorySuite(const t_char* directory_path) {

	char2wchar((t_char*)directory_path, this->path);

}
directorySuite::directorySuite(t_char* directory_path) {

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
