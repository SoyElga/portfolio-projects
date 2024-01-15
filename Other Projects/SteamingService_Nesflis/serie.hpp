// Final project
// Streaming service
// Christian Jesús González Ramírez     A01657929
// Luis Grabriel Martínez Rentería      A01651812
#include <iostream>
#include <string>
#include <new>

#include "season.hpp"

using namespace std;


class Serie : public CatalogElement {
    private:
        Season* seasons[10];
        int counter;
    public:
        Serie(){
            counter = 0;
        }
        void addSeason(Season* s){
            seasons[counter] = s;
            counter++;
        }        
        Season* getSeason(int index){return seasons[index];}

        int getLength(){
            int total = 0;
            for(int i = 0; i < counter; i++){
                total += seasons[i]->getLength();
            }
            return total;
        }

        int getRating(){
            int total = 0, n = 0;
            for(int i = 0; i < counter; i++){
                total += seasons[i]->getRaitings();
                n += seasons[i]->getCounter();
            }
            return total / n;
        }

        int getCounter(){return this->counter;}

        void displayInformation(){
            cout << this << endl;
        }

        string saveInformation(){
            string info = "";
            cout << info << endl;
            info += "-Serie-";
            info += "\n";
            info += this->getTitle();
            info += "\n";
            info += this->getGenre();
            info += "\n";
            info += to_string(this->counter);
            info += "\n";
            for(int i = 0; i < counter; i++){
            info += to_string(this->seasons[i]->getCounter());
            info += "\n";
            info += this->seasons[i]->saveEpisodes();
            }
            return info;
        }

        friend ostream& operator <<(ostream& os, Serie* s){
            string stars = "";
            for(int i = 0; i < s->getRating(); i++){
                stars += "*";
            }
            
                os << "Serie: " << s->getTitle() << " (" << s->getLength() << " min)\nRating: " << stars << "\nGenre: " << s->getGenre() <<endl;
                for(int i = 0; i < s->counter; i++){
                    os << "Season " << i+1 << ":" << endl;
                    for(int j = 0; j < s->seasons[i]->getCounter(); j++){
                        os << "\t" << j + 1 << ". " << s->seasons[i]->getEpisode(j)->getName() << " (" << s->seasons[i]->getEpisode(j)->getVideo()->getLength() << " min)" << endl;
                    }
                }
            
        
        return os;
    }
};