#include "../../include/files/fileSuite.hpp"

#include <stdio.h>

fileSuite::fileSuite() {



}

fileSuite::fileSuite(const t_char* filepath, fileSuiteOpeningMode mode) {

	this->open(filepath, mode);

}

fileSuite::~fileSuite() {

	if (this->isFileOpened) {
		this->close();
	}

}

void fileSuite::open(const t_char* filepath, fileSuiteOpeningMode mode) {

	if (mode == fileSuiteOpeningMode::INIT) {
		return;
	}

	// string for fopen_s
	const t_char* open_mode_str = mode == fileSuiteOpeningMode::READ ? "rb" : "wb";

	// open file
	t_int err = fopen_s(&this->fp, filepath, open_mode_str);
	if (err != 0) {
		return;
	}

	// set parameter
	this->isFileOpened = true;
	this->opening_mode = mode;

}

void fileSuite::read(void* dataP, size_t elemSize, size_t elemCount) {

	fread_s(dataP, elemSize * elemCount, elemSize, elemCount, this->fp);

}

void fileSuite::write(const void* dataP, size_t elemSize, size_t elemCount) {

	fwrite(dataP, elemSize, elemCount, this->fp);

}

void fileSuite::close() {

	// close opened file
	fclose(this->fp);

}