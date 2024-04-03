#pragma once
#ifndef POST
#define POST

#include "Comment.h"
#include <iostream>
#include <vector>
#include <string>

class Post {
private:
	std::string text_Post;
	int likes = 0;
	std::vector<Comment> comments;

public:
	Post();
	Post(std::string);
	Post(const Post&);

	int getLikes();
	void setLikes(int);
	std::vector<Comment> getComments();
	void setComments(std::vector<Comment>);

	friend std::ostream& operator<<(std::ostream&, const Post&);
	friend std::istream& operator>>(std::istream&, Post&);
	bool operator==(const Post&);
	Post& operator=(const Post&);

	void showComments(std::ostream&) const;
	void addComment(Comment&);
};

#endif
