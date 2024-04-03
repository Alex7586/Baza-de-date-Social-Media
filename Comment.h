#pragma once
#ifndef COMMENT
#define COMMENT

#include <iostream>
#include <string>

class Comment
{
private:
	std::string textComm;
	std::string date; //dată + ora

public:
	Comment();
	Comment(std::string, std::string);
	Comment(const Comment&);

	friend std::ostream& operator<<(std::ostream&, const Comment&);
	friend std::istream& operator>>(std::istream&, Comment&);
	Comment& operator=(const Comment&);
	bool operator!=(const Comment&);

};

#endif
