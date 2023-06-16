#include "header.h"
#include <iostream>
#include <fstream>
#include <string>



//Function that prints out an array on one line
void print_array(int arr[100], int count){
    std::cout << "New array: " << "\n";
    for (int i = 0; i < count; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

//Checks to see if a number exists in the array
//returns positive number if exists in the arrat
//returns negative if it doesn't
int exists_in_array(int num, int array[100], int count){
    for(int i = 0; i < count; i++){
        if(array[i] == num){
            return i;
        }
    }
    return -1;
}

//Modifies an element in the array given an index and a new value
//Returns
int modify_element_in_array(int index, int array[100], int new_int, int count){

   try{
        if(index < count && index >=0){
            int old_int = array[index];
            array[index] = new_int;
            return old_int;
        }else{
            throw (index);
        }
        
    }catch( int ind){
        std::cerr << "Sorry, index " << ind << " cannot be modified" << "\n";
   }
   return -1;
}

//adds an elment to the end of the array
void add_to_array(int num, int array[100], int count){
    try{
        if(count < 100){
            array[count] = num;
            
        }else{
            throw num;
        }
        
        
        
    }catch(int number){
        std::cerr << "Sorry, " << number << " can't be added" << "\n";
    }
    
}

//given an index will turn that index value to zero
void turns_to_zero(int index, int array[100], int count){
    if(index < count){
        array[index] = 0;
    }else{
        std::cout << "Cannot turn index " << index << " to zero" << "\n";
    }
    
}

int main(){

   std::ifstream inputFile("numbers.txt");
    if (!inputFile.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    const int MAX_NUMBERS = 100;
    int numbers[MAX_NUMBERS];
    int number;
    int count = 0;

    while (inputFile >> number && count < MAX_NUMBERS) {
        numbers[count] = number;
        count++;
    }

    inputFile.close();

    std::cout << "\n" << "Array from text file" << "\n";
    for (int i = 0; i < count; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";
    std::cout << "\n";



    //Part 1 of question 1
    int check_integer;
    std::cout << "\n" << "Question 1" << "\n";
   std::cout << "Which number would you like to check to see if it exists?" << "\n";

   std::cin >> check_integer;

    int exists = exists_in_array(check_integer, numbers, count);
    
    
    if(exists >= 0){
        std::cout << "Your integer is at index " << exists << "\n";
    }else{
        std::cout << "The integer does not exist in the array" << "\n";
    }

    //Part 2 of question 1
    int index,value;
    std::cout << "\n"<< "Question 2" << "\n";
    std::cout << "Which index would you like to change?" << "\n";
    std::cin >> index;

    std::cout << "What value would you like to change that index to?" << "\n";
    std::cin >> value;

    int part_two_asnwer = modify_element_in_array(index,numbers,value,count);

    std::cout << "Old integer in array is " << part_two_asnwer << "\n";
    std::cout << "New value is " << value << "\n";

    print_array(numbers, count);

    //Part 3 of question 1
    std::cout << "\n" << "Question 3" << "\n";
    int value_part_three;
    std::cout << "What value would you like to add to the end of the array?" << "\n";
    std::cin >> value_part_three;

    
    add_to_array(value_part_three, numbers,count);
    count++;

    print_array(numbers, count);
    
    //Part 4 of question 1

    std::cout << "\n" << "Question 4" << "\n";
    int index_part_four;

    std::cout << "Which index would you like to turn to zero?" << "\n";
    std::cin >> index_part_four;

    turns_to_zero(index_part_four, numbers, count);
    
    print_array(numbers, count);
    
    return 0;
}


