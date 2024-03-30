#include "empaque.h"

empaque::empaque()
	: _tripa(true) {
}

empaque::empaque(bool tripa)
	: _tripa(tripa) {
}

empaque::empaque(const empaque& obj) : _tripa(obj._tripa) {
}

empaque::~empaque()
{
}

bool empaque::getTripa() {
	return _tripa;
}

string empaque::toString() const {
	stringstream s;

	s << "Tripa: ";
	if (_tripa) {
		s << "si" << endl;
	}
	else {
		s << "no" << endl;
	}
	s << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;

	return s.str();
}
