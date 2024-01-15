// Final project
// Streaming service
// Christian Jesús González Ramírez     A01657929
// Luis Grabriel Martínez Rentería      A01651812
#include <iostream>
#include <string>
#include <new>

#include "episode.hpp"

using namespace std;

class Season{
    private:
    Episode* episodes[15];
    int counter;

    public:
    Season(){
        counter = 0;
    }
    void addEpisode(Episode* e){
        if(counter < 15){
        episodes[counter] = e;
        counter++;
            }
        }

    Episode* getEpisode(int index){
        return episodes[index];
    }

    int getLength(){
        int total = 0;
        for(int i = 0; i < counter; i++){
            total += episodes[i]->getVideo()->getLength();
        }
        return total;
    }
    int getCounter(){
        return this->counter;
    }

    string saveEpisodes(){
        string info = "";
        for(int i = 0; i < counter; i++){
        info += episodes[i]->getName(); 
        info += "\n";
        info += to_string(episodes[i]->getVideo()->getLength()); 
        info += "\n";
        info += to_string(episodes[i]->getRating()); 
        info += "\n";
        }
        return info;
    }

    int getRaitings(){
        int total = 0;
        for(int i = 0; i < counter; i++){
            total += episodes[i]->getRating();
        }
        return total;
    }
};
