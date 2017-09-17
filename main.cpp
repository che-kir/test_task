#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "testheader.hpp"


//The test task result should be located at any convenient Git repository

testBase::~testBase(){};

void yourTestClass::signedIntGenerator(signed int* &arr) {
    srand( time(NULL) );
    gLengthRandArray = rand() % 20 + 1;
    arr = new int[ gLengthRandArray ];
    std::cout << "\nGenerated sequence: " << std::endl;
    for ( int i = 0; i < gLengthRandArray; i++ )
    {
        arr[i] = rand() % RAND_MAX - RAND_MAX / 2;  
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

signed int yourTestClass::signedMin(signed int* &arr) {
    signedIntGenerator( arr );
    int minNum = INT_MAX;
    for ( int i = 0; i < gLengthRandArray; i++ )
    {
        if ( arr[i] < minNum )
        {
            minNum = arr[i];
        }
    } 
    delete[] arr;
    return minNum;
}

void yourTestClass::revertWords(char* arr)
{    
    int leftIndex = 0;
    int rightIndex = strlen(arr) - 1;
    size_t len = rightIndex + 1;
    if ( rightIndex > 1 )
    {
        arr = reverseString(arr, 0, rightIndex);
        for (rightIndex = 0; rightIndex <= len; rightIndex++)
        {
            if (rightIndex == len || arr[rightIndex] == ' ')
            {
                arr = reverseString(arr, leftIndex, rightIndex - 1);
                leftIndex = rightIndex + 1;
            }
        }
    }
}


char* yourTestClass::reverseString(char* inText, int leftIndex, int rightIndex)
{
    char tempChar;
    while (leftIndex < rightIndex)
    {
        tempChar = inText[leftIndex];
        inText[leftIndex++] = inText[rightIndex];
        inText[rightIndex--] = tempChar;
    }
    return inText;
}

std::string yourTestClass::processWords(std::string& input) {
    std::string longestWord = "";
    std::string temp = input;
    size_t maxLen = 0;
    int wordBegin = 0;
    char *writable = new char[ input.size() + 1 ];
    std::copy( input.begin(), input.end(), writable );
    writable[ input.size() ] = '\0'; 
    revertWords( writable );
    input.assign(writable);
    
    if ( 0 == temp.compare(input) )
    {
        return temp;
    }

    for ( int i = 0; i < input.length() + 1; i++ )
    {
        if ( input[i] == ' ' || input[i] == '\0' )
        {
            temp = input.substr(wordBegin, i - wordBegin);
            if ( temp.length() > longestWord.length() )
            {
                longestWord = temp;    
            }
            wordBegin = i + 1;
        }
    }
    delete[] writable;   
    return longestWord;
}



int main() //DO NOT MODIFY THIS BLOCK
{
	yourTestClass myTest;
	signed int* arr = nullptr;

	std::cout << "Test started" << std::endl;
	std::cout << "Please input a text with several words" << std::endl;
	std::string input;
	std::getline(std::cin, input);
	std::cout << "Input text: " << input << std::endl;
	std::cout << "Longest word: " << myTest.processWords(input) << std::endl;
	std::cout << "Reverted text: " << input << std::endl;
	std::cout << "Minimal is : " << myTest.signedMin(arr) << std::endl;
	std::cout << std::endl << "Test ended";
	return 0;
}