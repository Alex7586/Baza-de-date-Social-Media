#include "User.h"

User::User() {
}

User::User(std::string _name, std::string _email, std::string _pass, bool _newAcc) {
	name = _name;
	eMail = _email;
	password = _pass;
}

User::User(const User& other) {
	name = other.name;
	eMail = other.eMail;
	password = other.password;
	personalPosts = other.personalPosts;
	following = other.following;
}

void User::setPassword(std::string newPass) {
	password = newPass;
}

std::vector<Post> User::getPPosts() {
	return personalPosts;
}

void User::setPPosts(std::vector<Post> PP) {
	//personalPosts.clear();
	personalPosts = PP;
}

std::vector<User> User::getFollowing() {
	return following;
}

std::string User::getName() {
	return name;
}

std::ostream& operator<<(std::ostream& os, const User& user) {
	os << "Username: " << user.name << '\n';
	os << "Following: " << user.following.size() << '\n';
	os << "--------------------\n";
	os << "Users posts:\n";
	for (Post post : user.personalPosts)
		os << post;
	return os;
}

std::istream& operator>>(std::istream& is, User& user) {
	std::cout << "Nume:\t";
	is >> user.name;
	std::cout << "Mail:\t";
	is >> user.eMail;
	std::cout << "Parola:\t";
	is >> user.password;
	return is;
}

User& User::operator=(const User& other) {
	name = other.name;
	eMail = other.eMail;
	password = other.password;
	personalPosts = other.personalPosts;
	following = other.following;
	return *this;
}

void User::addPost(Post& post) {
	personalPosts.push_back(post);
}//adaugă postare în feed-ul personal

bool User::operator==(const User& other) {
	return name == other.name && eMail == other.eMail && password == other.password;
}

void User::follow(const User& user) {
	following.push_back(user);
}

void User::like(Post& post) {
	std::cout << post.getLikes() << '\n';
	post.setLikes(post.getLikes() + 1);
	std::cout << post.getLikes() << '\n';
}

void User::comment(Post& post, Comment& comment) {
	post.addComment(comment);
}