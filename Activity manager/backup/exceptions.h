#pragma once
#include <string>

class AddException {

};

class DelException {

};

class UptExceptions {

};

class SrcExceptions {

};

class ValidException {

};

class FileException {

};

class UndoException {

};

class PacanicaException {
public:
	PacanicaException(const float& p) : p{ p } {}
	~PacanicaException() = default;
	float getMessage() {
		return p;
	}
private:
	float  p;
};