#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Actor{
//Here we use the term generally for both females and males
	private:
	string name;
	int age;

  public:
  Actor(string name, int age) : name(name), age(age) {}
	
};
class User{
        private:
        Actor favoriteActor;
        public:
	User(Actor favA){favoriteActor = favA;}
        Actor GetFav(){return favoriteActor;}
};

class Movie{
	protected:
	string name;
	int genre;
	int rating;
	vector<Actor> cast;
	public:

  Movie(string name, int genre, int rating, vector<Actor> cast) :
    name(name), genre(genre), rating(rating), cast(cast) {}
	
};
class IndependantFilm:public Movie{
	vector<string> Contributors;

  IndependantFilm(string name, int genre, int rating, vector<Actor> cast, vector<string> Contributors) :
    Movie(name, genre, rating, cast), Contributors(Contributors) {}
};
class StudioFilm: public Movie{
	string studioName;

  StudioFilm(string name, int genre, int rating, vector<Actor> cast, string studioName) :
    Movie(name, genre, rating, cast), studioName(studioName) {}
};
int Recommended_Movies( vector<Movie*> mv, User u ){
  Actor favoriteActor = u.GetFav();
  for (int i = 0; i < mv.size(); i++) {
    if (mv->)
    cout << mv[i] << endl;
    cout << "Printed" << mv.size() << endl;
  }
}
void PrintStudio( Movie* m ){
m->DisplayInfo();
}

int main(){
//Let's just initialized some actors, users, and movies. We didn't use your constructors here so,
//make sure you've included the constroctors for this code to work if you plan to compile.
//Basically, we are using this as a test driver for our functions and classes.
Actor a1,a2,a3,a4,a5;
User user1(a1), user2(a5), user3(a1), user4(a3);
IndependantFilm iF1, iF2, iF3;
StudioFilm sF1, sF2, sF3;

// Here we try to simulate a vector of slected movies by user 1
vector<Movie*> selectedMovies;
selectedMovies.push_back(&iF3);
selectedMovies.push_back(&sF2);
selectedMovies.push_back(&sF3);

int num = Recommended_Movies(selectedMovies, user1); //Here the function should print recommended movies if there are any

PrintStudio(&sF1);// Here the studio should be printed for the movie sF1.
PrintStudio(&iF3);// Here the contributors should be printed for the movie iF3.
}