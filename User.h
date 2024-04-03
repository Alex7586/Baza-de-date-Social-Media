#ifndef USER
#define USER

#include "Post.h"
#include "Comment.h"
#include <iostream>
#include <vector>
#include <fstream>

class User
{
private:
	std::string name;
	std::string eMail;
	std::string password;
	std::vector<Post> personalPosts;
	std::vector<User> following;
	bool newAcc = true;

public:
	User();
	User(std::string, std::string, std::string, bool = false);
	User(const User&);

	std::vector<Post> getPPosts();
	std::vector<User> getFollowing();
	std::string getName();
	void setPPosts(std::vector<Post>);
	void setPassword(std::string); //implementare draguta in main

	friend std::ostream& operator<<(std::ostream&, const User&);
	friend std::istream& operator>>(std::istream&, User&);
	User& operator=(const User&);
	bool operator==(const User&);

	void addPost(Post&);
	void follow(const User&);
	void like(Post&);
	void comment(Post&, Comment&);
};

#endif // !#USER

