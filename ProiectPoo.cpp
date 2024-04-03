#include "User.h"
#include "Post.h"
#include "Comment.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ctime>


int main()
{
	srand(time(NULL));

	std::vector<User> utilizatori;
	std::vector<Post> postari;
	std::vector<Comment> comentarii;

	utilizatori.push_back(User("Dumitru", "ceva.com", "kkk"));
	utilizatori.push_back(User("Marin", "email.ro", "ewoiej"));
	utilizatori.push_back(User("Mircea", "pantaloni_pufosi.com", "de55edewd"));
	
	postari.push_back(Post("Ce frumos e afara"));
	postari.push_back(Post("MaMaLiGa"));
	postari.push_back(Post("Creo"));
	postari.push_back(Post("joe"));
	postari.push_back(Post("mama"));
	
	comentarii.push_back(Comment("WOW", "date1"));
	comentarii.push_back(Comment("vrefa", "date2"));
	
	utilizatori[0].addPost(postari[0]);
	utilizatori[0].addPost(postari[1]);
	utilizatori[1].addPost(postari[2]);
	utilizatori[1].addPost(postari[4]);
	utilizatori[2].addPost(postari[3]);

	utilizatori[0].follow(utilizatori[1]);
	utilizatori[0].follow(utilizatori[2]);

	User acc;
	std::cin >> acc;
	for (User user : utilizatori) {
		if (acc == user) {
			acc = user;
			break;
		}
	}

	std::vector<User> followingUsers = acc.getFollowing();
	int u = rand() % followingUsers.size();
	int p = rand() % followingUsers[u].getPPosts().size();
	std::cout << followingUsers[u].getName() << " : " << followingUsers[u].getPPosts()[p];
	bool end = false;

	while(!end) {
		std::cout << "\nWhat do you want to do now?\n";
		std::cout << "\t[0] like\n\t[1] comment\n\t[2] addPost\n\t[3] nextPost\n\t[4] close\n\n Your choice: ";
		int choice=-1;
		std::cin >> choice;
		switch (choice) {
		case 0:
		{
			//acc.like(postareCurenta)
			break;
		}
		case 1:
		{
			//acc.comment(postareCurenta)
			break;
		}
		case 2: 
		{
			std::cout << "What do you have in mind?:\n";
			std::string postare;
			std::getline(std::cin >> std::ws, postare);
			Post alta(postare);
			postari.push_back(alta);
			for (int i = 0; i < utilizatori.size();i++) {
				if (acc == utilizatori[i]) {
					utilizatori[i].addPost(postari[postari.size() - 1]);
					acc = utilizatori[i];
					break;
				}
			}
			break;
		}
		case 3:
		{
			followingUsers = acc.getFollowing();
			u = rand() % followingUsers.size();
			p = rand() % followingUsers[u].getPPosts().size();
			std::cout << followingUsers[u].getName() << " : " << followingUsers[u].getPPosts()[p];
			break;
		}
		case 4:
			end = true;
			break;
		default:
			std::cout << "NO! TRY AGAIN\n\n";
			break;
		}
	}
	return 0;
}