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

		void clear(){
			data.clear();
			length = 0;
		}

		unsigned int size(){
			return length;
		}

		void insert(int i){
			data.push_back(i);
			length++;
		}

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
		typename T::iterator operator[] (int i){
			typename T::iterator ret = data.begin();
			for(int j = 0;j<i;j++){ //might need to change range of this for loop
				ret++;
			}
			return ret;
		}

		void insertionSort(){
			std::clock_t start;
    		double duration;
    		start = std::clock();
			
            std::vector<int> temp;
            for(typename T::iterator iter = data.begin();iter != data.end();iter++){
                temp.push_back(*iter);
            }


            for(int i = 2;i<length;i++){
                for(int j = i-1;j>=0;j--){
                    if(temp[j]>temp[j+1]){
                        int t = temp[j+1];
                        temp[j+1] = temp[j];
                        temp[j] = t;
                    }
                    else if(j>0 && temp[j]>temp[j-1]){
                        break;
                    }
                }
            }

			for(std::vector<int>::iterator iter = temp.begin();iter != temp.end();iter++){
                data.pop_back();
            }
			for(std::vector<int>::iterator iter = temp.begin();iter != temp.end();iter++){
                data.push_back(*iter);
            
            }
            
            duration = ( std::clock() - start ) * 1000000 / (double) CLOCKS_PER_SEC;
    		std::cout<<"insertion sort took: "<< duration << " microseconds on " <<length << " elements"<<'\n'; 
		}
		void selectionSort(){

			std::clock_t start;
    		double duration;
    		start = std::clock();

			std::vector<int> temp;
            for(typename T::iterator iter = data.begin();iter != data.end();iter++){
                temp.push_back(*iter);
            }
	        for(int i = 0;i<length;i++){
                int min = temp[i];
                int minIndex = i;
                for(int j = i;j<length;j++){
                    if(temp[j]<min){
                        min = temp[j];
                        minIndex = j;
                    }
                }
                temp[minIndex] = temp[i];
                temp[i] = min;
            }

            for(std::vector<int>::iterator iter = temp.begin();iter != temp.end();iter++){
                data.pop_back();
            }
			for(std::vector<int>::iterator iter = temp.begin();iter != temp.end();iter++){
                data.push_back(*iter);
            }

            duration = ( std::clock() - start ) *1000000/ (double) CLOCKS_PER_SEC;
    		std::cout<<"selection sort took: "<< duration << " microseconds on " <<length << " elements"<<'\n'; 

		}
		void bubbleSort(){
			
            std::clock_t start;
    		double duration;
    		start = std::clock();
			
            std::vector<int> temp;
            for(typename T::iterator iter = data.begin();iter != data.end();iter++){
                temp.push_back(*iter);
            }
            for(int i = 0;i<length;i++){
                for(int j =0;j<length-i-1;j++){
                    if(temp[j]>temp[j+1]){
                        int t = temp[j];
                        temp[j] = temp[j+1];
                        temp[j+1] = t;
                    }
                }
			}

            for(std::vector<int>::iterator iter = temp.begin();iter != temp.end();iter++){
                data.pop_back();
            }
			for(std::vector<int>::iterator iter = temp.begin();iter != temp.end();iter++){
                data.push_back(*iter);
            }
            
            duration = ( std::clock() - start ) *1000000 / (double) CLOCKS_PER_SEC;
    		std::cout<<"bubble sort took: "<< duration << " microseconds on " <<length << " elements"<<'\n'; 
        }
		
		void print(){
			std::vector<int> temp;
			for(typename T::iterator iter = data.begin();iter != data.end();iter++){
                temp.push_back(*iter);
                data.pop_back();
            }

			for (std::vector<int>::iterator i = temp.begin(); i != temp.end(); ++i)
				    std::cout << *i << ' ';
			
            for( std::vector<int>::iterator iter = temp.begin();iter != temp.end();iter++){
                data.push_back(*iter);
            }
			std::cout<<"\n"<<std::endl;
		}


};


#endif
