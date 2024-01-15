// Final project
// Streaming service
// Christian Jesús González Ramírez     A01657929
// Luis Grabriel Martínez Rentería      A01651812
#include <iostream>
#include <string>
#include <new>
#include <fstream>

#include "catalog.hpp"
#include "video.hpp"
#include "movie.hpp"
#include "serie.hpp"
#include "colormod.h"

using namespace std;

Color::Modifier red(Color::FG_RED);

class NesflisMenu {
    private:
        Catalog catalog;
        static const int EXIT = 6;

        void displayOptions() {
          cout << red << "---------------------" << endl;
          cout << "1. Create a movie" << endl;
          cout << "2. Create a series" << endl;
          cout << "3. Display elements" << endl;
          cout << "4. Eliminate an element" << endl;
          cout << "5. Save names" << endl;
          cout << EXIT <<  ". EXIT" << endl;
        }

        int selectOption() {
            int option;
            string tmp;
            do {
                cout << "SELECT AN OPTION: ";
                cin >> option;
                getline(cin, tmp);
            } while (option < 1 || option > EXIT);
            cout << "---------------------" << endl;

            return option;
        }

        void performAction(int action) {
            string title, episode_title, tmp, genre;
            int length, seasons, videos, rating, i, j;
            Video* v;
            Movie* m;
            Serie* s;
            Season* season;
            Episode* e;
            bool failure;

            switch(action) {
                case 1:
                    //Ask for the title, genre, length and rating
                    failure = true;
                    do{
                      try{
                    cout << "Movie title: ";
                    getline(cin, title);
                    cout << "Movie genre: ";
                    getline(cin, genre);
                    cout << "Movie length: ";
                    cin >> length;
                    cout << "Movie rating: ";
                    cin >> rating;

                    m = new Movie();
                    m->setRating(rating);
                    v = new Video(length);
                    m->setTitle(title);
                    m->setGenre(genre);
                    m->setVideo(v);
                    failure = false;
                    } catch (runtime_error& err){
                      cout << "There was a problem... " << err.what() << endl; 
                      getline(cin, tmp);
                    }
                    }while(failure);
                    catalog.addCatalogElement(m);
                    break;

                case 2:
                //Ask for the title, genre, number of videos, their lengths and ratings
                  cout << "Serie title: ";
                  getline(cin, title);
                  cout << "Serie genre: ";
                  getline(cin, genre);
                  
                  do{cout << "Number of seasons (up to 10): ";
                  cin >> seasons;}while(seasons < 0 || seasons > 10);

                  s = new Serie();
                  s->setTitle(title);
                  s->setGenre(genre);

                  for (i = 0; i < seasons; i++) {
                    do{
                      cout << "How many episodes in season " << i + 1 << "? ";
                      cin >> videos;
                    }while(videos < 0 || videos > 15);
                      season = new Season();

                      for(j = 0; j < videos; j++){
                        failure = true;
                        do{
                        try{cout << "Title of episode " << j + 1 << ": ";
                          getline(cin, tmp);
                          getline(cin, episode_title);
                          cout << "Length of episode " << j + 1 << ": ";
                          cin >> length;
                          cout << "Rating of Episode " << j + 1 << ": ";
                          cin >> rating;
                          v = new Video(length);
                          e = new Episode();
                          e->setName(episode_title);
                          e->setRating(rating);
                          e->setVideo(v);
                          failure = false;
                          season->addEpisode(e);
                        } catch (runtime_error& err){
                          cout << "There was a problem... " << err.what() << endl;
                        }
                        }while (failure);
                  }
                  s->addSeason(season);
                  }
                  catalog.addCatalogElement(s);
                  break;

                case 3:
                  catalog.displayElements();
                  break;

                case 4:
                
                  catalog.deleteCatalogElement();
                  break;

                case 5:
                      catalog.saveElements();
                      cout << "saved all the elements" << endl;
                  break;

                default:
                  break;
            }
        }
        
    
    
    public:

  
    void readElements(){
      Video* v;
      Movie* m;
      Serie* s;
      Episode* e;
      Season* season;

      string value, title, capTitle, tmp, genre;
      int rating, length, seasons, eps;
      
      ifstream file;
      file.open("catalog.txt");
        do{
          getline(file, value);
          if(value == "-Movie-"){
            getline(file, title);
            getline(file, genre);
            file >> length;
            getline(file, tmp);
            file >> rating;
            getline(file, tmp);

            v = new Video(length);
            m = new Movie();
            m->setTitle(title);
            m->setGenre(genre);
            m->setRating(rating);
            m->setVideo(v);
            catalog.addCatalogElement(m);
            //-------------------------+
          }else if(value == "-Serie-"){
            s = new Serie();
            
            getline(file, title);
            getline(file, genre);
            file >> seasons;
            getline(file, tmp);

            s->setTitle(title);
            s->setGenre(genre);

            for (int i = 0; i < seasons; i++) {
              season = new Season();
              file >> eps;
              getline(file, tmp);
              for(int j = 0; j < eps; j++){
                e = new Episode();

                getline(file, capTitle);
                file >> length;
                getline(file, tmp);
                file >> rating;
                getline(file, tmp);

                v = new Video(length);
                e->setRating(rating);
                e->setVideo(v);
                e->setName(capTitle);
                season->addEpisode(e);
              }
              s->addSeason(season);
            }
            catalog.addCatalogElement(s);
          }
          //-------------------------
        }while(value != "");
        file.close();
      }

        void runMenu() {
            int option;
            do {
                displayOptions();
                option = selectOption();
                performAction(option);
            } while (option != EXIT);
        }
};