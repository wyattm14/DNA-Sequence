#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
//https://stackoverflow.com/questions/30141000/c-how-to-pass-command-line-argument-to-read-txt-file
//http://www.java2s.com/Tutorial/Cpp/0240__File-Stream/Readanddisplayatextfilelinebyline.htm
//https://www.techiedelight.com/generate-random-numbers-cpp/
//https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c

using namespace std;
//main methoid
int main (int argc, char **argv){
  //initializing my variables
  string text;
  string getcontent;
  fstream f;
  // command line arg for the input text file
  string fn = argv [1];
  //opening the file
  f.open(fn);
  //initializing more variables
  string str = "";
  string bigString = "";
  float difference;
  int sum = 0;
  int count = 0;
  int variance = 0;
  int n =2;
  int Acount = 0;
  int Ccount = 0;
  int Tcount = 0;
  int Gcount = 0;
  int AAcount = 0;
  int AGcount = 0;
  int ATcount = 0;
  int ACcount = 0;
  int CAcount = 0;
  int CCcount = 0;
  int CTcount = 0;
  int CGcount = 0;
  int GAcount = 0;
  int GTcount = 0;
  int GGcount = 0;
  int GCcount = 0;
  int TTcount = 0;
  int TAcount = 0;
  int TCcount = 0;
  int TGcount = 0;
  float bigramCount = 0;
  int totalLetter = 0;
  float Aprob = 1;
  float Cprob = 1;
  float Tprob = 1;
  float Gprob = 1;
  float a = 0;
  float b = 0;
  float c = 0;
  float d = 0;
  string substring = "";
  string gausian = "";
  int wordlength = 1;
  //while loop to get the count of the amount of lines and the length of each of the strings
  while (f){
    getline(f, str);
    if (f) sum += str.length();
    if (f) count += 1;
  }
//getting the mean
  int realSize = sum - count + 1;
  float mean = ((float)realSize)/ count;
//closing and reopening the file because I want to work in a new while loop
  f.close();
  f.open(fn);
  //initializing new varaibles, bad order
  int newCount = 0;
  float squaredNum = 1;
  float numeratorVar = 0;
  float numerator = 0;
  float var = 1;
  float standardDev = 1;
//new while loop for everything else
  while(f){
    getline(f, str);
    int size = str.size();
    if (f) newCount += 1;
    if (f) if (newCount != count){
      size = size - 1;
    }
    // finding the variance
    // if (f) cout << "the size is: " << size << endl;
    if (f) difference = size - mean;
    // if (f) cout<< "The difference is: " <<difference << endl;
    if (f) squaredNum = difference * difference;
    // if (f) cout << "the squared num is: "<< squaredNum << endl;
    if (f) numeratorVar += squaredNum;
    if (f) if (newCount == count){
      numerator = numeratorVar;
    }
    // if (f) cout << "the numerator is: "<< numerator<< endl;
    // if (f) cout << "the denom is: "<< count<< endl;
    if (f) var = numerator/count;
    //finding the standard deviation from the varaince
    if (f) standardDev = sqrt(var);
    //for loop to find the occurances of each letter
    for (int i = 0; i < str.size(); ++i) {
      str[i] = toupper(str[i]);
      if (f) if (str[i] == 'A' || str[i] == 'a') Acount++;
      //size_t n = std::count(str.begin(), str.end(), 'A');
      if (f) if (str[i] == 'C' || str[i] == 'c') Ccount++;
      if (f) if (str[i] == 'T' || str[i] == 't') Tcount++;
      if (f) if (str[i] == 'G' || str[i] == 'g') Gcount++;
    }
    totalLetter = Acount + Ccount + Tcount + Gcount;
    Aprob = Acount/(float)totalLetter;
    Tprob = Tcount/(float)totalLetter;
    Gprob = Gcount/(float)totalLetter;
    Cprob = Ccount/(float)totalLetter;

    //for loop to find the occurances of each bigram
    if (f) for (int i = 0; i< str.size(); i += 2){
      str[i] = toupper(str[i]);
      substring = str.substr(i,2);
      str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
      if (substring == "AA"){
        AAcount++;
      }
      else if (substring == "AT"){
        ATcount++;
      }
      else if (substring == "AG"){
        AGcount++;
      }
      else if (substring == "AC"){
        ACcount++;
      }
      else if (substring == "CA"){
        CAcount++;
      }
      else if (substring == "CC"){
        CCcount++;
      }
      else if (substring == "CG"){
        CGcount++;
      }
      else if (substring == "CT"){
        CTcount++;
      }
      else if (substring == "GA"){
        GAcount++;
      }
      else if (substring == "GG"){
        GGcount++;
      }
      else if (substring == "GT"){
        GTcount++;
      }
      else if (substring == "GC"){
        GCcount++;
      }
      else if (substring == "TA"){
        TAcount++;
      }
      else if (substring == "TT"){
        TTcount++;
      }
      else if (substring == "TC"){
        TCcount++;
      }
      else if (substring == "TG"){
        TGcount++;
      }
    }//gettig the total amount of bigrams to find the prob
    bigramCount = TGcount + TCcount + TTcount + TAcount + GAcount + GGcount + GCcount + GTcount + AAcount + ATcount + AGcount + ACcount + CAcount + CCcount + CGcount + CTcount;
  }
  //outputting to a file
  std::ofstream ofs ("WyattMiller.txt", std::ofstream::out);
  ofs<<
  "Wyatt Miller \n2302376\n"<< endl <<
  "The sum of the nucleotides is: "<< realSize << endl <<
  "The amount of DNA Strings are: "<< count<< endl<<
  "The mean length of each is: "<< mean<< endl <<
  "the varaince is: "<< var << endl <<
  "the standard deviation is: "<< standardDev<< endl <<
  "           "<< endl <<
  "A's probability "<< Aprob << endl <<
  "G's probability "<< Gprob << endl <<
  "C's probability "<< Cprob << endl <<
  "T's probability " << Tprob << endl <<
  "           "<< endl <<
  "The probability of AA is: "<< AAcount/bigramCount << endl<<
  "The probability of AT is: "<< ATcount/bigramCount << endl<<
  "The probability of AC is: "<< ACcount/bigramCount << endl<<
  "The probability of AG is: "<< AGcount/bigramCount << endl<<
  "The probability of TT is: "<< TTcount/bigramCount << endl<<
  "The probability of TA is: "<< TAcount/bigramCount << endl<<
  "The probability of TG is: "<< TGcount/bigramCount << endl<<
  "The probability of TC is: "<< TCcount/bigramCount << endl<<
  "The probability of GT is: "<< GTcount/bigramCount << endl<<
  "The probability of GA is: "<< GAcount/bigramCount << endl<<
  "The probability of GG is: "<< GGcount/bigramCount << endl<<
  "The probability of GC is: "<< GCcount/bigramCount << endl<<
  "The probability of CT is: "<< TTcount/bigramCount << endl<<
  "The probability of CA is: "<< TAcount/bigramCount << endl<<
  "The probability of CG is: "<< TGcount/bigramCount << endl<<
  "The probability of CC is: "<< TCcount/bigramCount << endl<<
  "           "<< endl
  ;

  srand(time(NULL));
//printing 1000 strings
  for (int i = 0; i <= 1000; ++i){
    // making the equations from the document
    a = rand()/(float)RAND_MAX;
    b = rand()/(float)RAND_MAX;
    c = sqrt(-2*log(a)) * cos(2*M_PI*b);
    d = (standardDev*c)+mean;

    string possibleLetter = "ACTG";
    // creating a word length variable
    wordlength = d;
    // making it so it will round up or round down based on the decimal, and adjusting the word length
    float decimal = d-wordlength;
    if (decimal >= .5){
      wordlength = wordlength + 1;
    }
    // the amount of times each letter should occur
    int Aoccur = d * Aprob;
    int Coccur = d * Cprob;
    int Toccur = d * Tprob;
    int Goccur = d * Gprob;

    string testerString = "";

    // nested for loop to append each letter by their length
    for (int i = 0; testerString.length() <= wordlength; ++i){
      for (int i = 0; i<= Aoccur; ++i ){
        testerString.append("A");
      }
      for (int i = 0; i<= Coccur; ++i ){
        testerString.append("C");
      }
      for (int i = 0; i<= Toccur; ++i ){
        testerString.append("T");
      }
      for (int i = 0; i<= Goccur; ++i ){
        testerString.append("G");
      }
      random_shuffle(testerString.begin(), testerString.end());
    }


//outputting to the file
    ofs<< testerString<< endl;


  }
  //closing the file
  ofs.close();
  // cout << wordlength << endl;
  f.close();
  return 0;
}
