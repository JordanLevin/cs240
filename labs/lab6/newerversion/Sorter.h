#ifndef SORTER_H
#define SORTER_H


#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>

template <class T>
class Sorter{

	private:
		T data;
		int length;
	public:
		Sorter(){
			length = 0;
		}

        //clears the container
		void clear(){
			data.clear();
			length = 0;
		}

        //returns the length
		unsigned int size(){
			return length;
		}

        //inserts an item into the container
		void insert(int i){
			data.push_back(i);
			length++;
		}

        //shuffle the container by moving everything into a vector, shuffling, then putting it back
		void shuffle(){
			std::vector<int> temp;
            for(int i = 0;i<length;i++){
				int t = data.back();
				temp.push_back(t);
				data.pop_back();
			}
			std::random_shuffle(temp.begin(), temp.end());
			for(int i = 0;i<length;i++){
				int t = temp.back();
				data.push_back(t);
				temp.pop_back();
			}
		}

        //overload [] operator for the sorter
		typename T::iterator operator[] (int i){
			typename T::iterator ret = data.begin();
			for(int j = 0;j<i;j++){ //might need to change range of this for loop
				ret++;
			}
			return ret;
		}

		void insertionSort(){
            //create a clock for timing
			std::clock_t start;
    		double duration;
    		start = std::clock();
            
            //do insertion sort
            int current;
            typename T::iterator j;
            for(typename T::iterator i = std::next(data.begin() ,1);i != data.end();i++){
                current = *i;
                for(j = std::prev(i, 1); *j>current ;j--){
                    *(std::next(j, 1)) = *j;
                    if(j==data.begin()){
                        j--;
                        break;
                    }
                }
                *(std::next(j, 1)) = current;
            }
            
            //display the time it took
            duration = ( std::clock() - start ) * 1000000 / (double) CLOCKS_PER_SEC;
    		std::cout<<"insertion sort took: "<< duration << " microseconds on " <<length << " elements"<<'\n'; 
		}
		void selectionSort(){
            
            //create a clock for timing
			std::clock_t start;
    		double duration;
    		start = std::clock();

            //do selection sort
	        for(typename T::iterator i = data.begin() ;i!=data.end();i++){
                int min = *i;
                typename T::iterator minIndex = i;
                for(typename T::iterator j = i;j != data.end();j++){
                    if(*j<min){
                        min = *j;
                        minIndex = j;
                    }
                }
                *minIndex = *i;
                *i = min;
            }

            //display the time it took
            duration = ( std::clock() - start ) *1000000/ (double) CLOCKS_PER_SEC;
    		std::cout<<"selection sort took: "<< duration << " microseconds on " <<length << " elements"<<'\n'; 

		}
		void bubbleSort(){
		    //create a clock for timing	
            std::clock_t start;
    		double duration;
    		start = std::clock();
			
            //do the sorting
            for(typename T::iterator i = data.begin(); i!= data.end(); i++){
                for(typename T::iterator j = data.begin();j!= std::prev(data.end(), 1);j++){
                    if(*j>*(std::next(j, 1))){
                        std::iter_swap(j, std::next(j, 1));
                    }
                }
			}
            
            //display the time it took
            duration = ( std::clock() - start ) *1000000 / (double) CLOCKS_PER_SEC;
    		std::cout<<"bubble sort took: "<< duration << " microseconds on " <<length << " elements"<<'\n'; 
        }
};


#endif
