#include "Post.h"

Post::Post() {}
Post::Post(std::string text) : text_Post{ text } {}

Post::Post(const Post& post) {
	text_Post = post.text_Post;
	likes = post.likes;
	comments = post.comments;
}

int Post::getLikes() {
	return likes;
}

void Post::setLikes(int num) {
	likes = num;
}

std::vector<Comment> Post::getComments() {
	return comments;
}

void Post::setComments(std::vector<Comment> com) {
	comments = com;
}

std::ostream& operator<<(std::ostream& os, const Post& post) {
	os << "--------------------\n";
	os << post.text_Post << "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
	os << "Likes: " << post.likes << "\tComments: " << post.comments.size() << '\n';
	os << "--------------------\n";
	post.showComments(os);
	return os;
}

std::istream& operator>>(std::istream& is, Post& post) {
	std::getline(is >> std::ws, post.text_Post);
	is >> post.likes;
	return is;
}

bool Post::operator==(const Post& other) {
	if (text_Post == other.text_Post && likes == other.likes)
		for (int i = 0; i < comments.size(); i++)
			if (comments[i] != other.comments[i]) return false;
	return true;
}

Post& Post::operator=(const Post& other) {
	return *this;
}

void Post::showComments(std::ostream& os) const {
	for (auto comm : comments) {
		os << "\t---------------\n";
		os << comm;
		os << "\t---------------\n";
	}
}

void Post::addComment(Comment& comm) {
	comments.push_back(comm);
}