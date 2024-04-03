#include "Comment.h"

Comment::Comment() {}
Comment::Comment(std::string com, std::string dat) : textComm{ com }, date{ dat } {}
Comment::Comment(const Comment& other) {
	textComm = other.textComm;
	date = other.date;
}

std::ostream& operator<<(std::ostream& os, const Comment& comm) {
	os << '\t' << comm.textComm << "\t\t" << comm.date << '\n';
	return os;
}
std::istream& operator>>(std::istream& is, Comment& comm) {
	std::getline(is >> std::ws, comm.textComm);
	std::getline(is >> std::ws, comm.date);
	return is;
}
Comment& Comment::operator=(const Comment&) { return *this; }

bool Comment::operator!=(const Comment& other) {
	return textComm != other.textComm && date != other.date;
}