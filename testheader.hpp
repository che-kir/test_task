/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   testheader.hpp
 * Author: kirillchernega
 *
 * Created on September 17, 2017, 5:24 PM
 */

#ifndef TESTHEADER_HPP
#define TESTHEADER_HPP


//Create a class "yourTestClass", which is inherited from interface class "testBase" presented below.
//Implement functions described in the interface class.
size_t gLengthRandArray;

class testBase
{
public:
	//Function must revert the sequence of words. ("word1 word2 word3" becomes "word3 word2 word1")
	virtual void revertWords(char* arr) = 0;

	//Function must revert words using revertWords method and return the longest word.
	virtual std::string processWords(std::string& input) = 0;

	//Function must generate random length(up to 20) array of random signed integer numbers.
	//Function must print the generated sequence in console.
	virtual void signedIntGenerator(signed int* &arr) = 0;

	//Function must use signedIntGenerator() and return minimum value.
	virtual signed int signedMin(signed int* &arr) = 0;

	virtual ~testBase() = 0;

};


class yourTestClass: public testBase
{
public:
    void revertWords(char* arr);
    char* reverseString(char* inText, int leftIndex, int rightIndex);
    std::string processWords(std::string& input);
    void signedIntGenerator(signed int* &arr);
    signed int signedMin(signed int* &arr);
};



#endif /* TESTHEADER_HPP */

