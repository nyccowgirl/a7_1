/*
 Trang Hoang
 CS110B
 Dave Harden
 10/12/20
 a7_1.cpp
 
 Assignment 7.1
 
 Program records high-score data for a fictitious game. The program asks user to enter the
 number of scores and the respective indicated number of names and scores. It then prints
 the names and scores sorted by score in descending order.
 
 Created by nyccowgirl on 10/12/20.
 Copyright © 2020 nyccowgirl. All rights reserved.
*/

#include <iostream>
#include <cctype>
#include <utility>
using namespace std;


const int LIMIT = 24;


struct Highscore
{
    char name[LIMIT];
    int score;
};


void readData(Highscore scores[], int size);
void sortData(Highscore scores[], int size);
int idxOfHigh(const Highscore scores[], int start, int size);
void displayData(const Highscore scores[], int size);


int main(int argc, const char * argv[]) {
    Highscore *scores;                      // To dynamically allocate array for scores
    int numScores;                          // To hold number of scores
    
    cout << "How many scores will you enter?: ";
    cin >> numScores;
    scores = new Highscore[numScores];
    readData(scores, numScores);
    sortData(scores, numScores);
    displayData(scores, numScores);
    
    delete [] scores;
    scores = nullptr;
    return 0;
}






/*
 Definition of function readData. The function passes in a Highscore structure array, and
 the size of the array. It gets names and scores from the user to store into the structure
 array. It assumes that user inputs valid type (e.g., string as character array for name of
 less than 24 characters and integer for score).
 
 Pre: None
 Post: scores structure array contains names and scores combinations inputted by user
*/

void readData(Highscore scores[], int size) {
    for (int x = 0; x < size; x++) {
        cout << "\nSCORE #" << (x + 1) << endl;
        cout << "------------" << endl;
        cin.ignore();
        cout << "Enter the name: ";

        do {
            cin.getline(scores[x].name, LIMIT);
        } while (*scores[x].name == '\0');

        cout << "Enter the score: ";
        cin >> scores[x].score;
    }
}






/*
 Definition of function sortData. The function passes in a Highscore structure array, and
 the size of the arrays. It sorts the array based on scores in descending order by calling
 the idxOfHigh function to determine the index of the higher score to swap the name/score
 combination.
 
 Pre: scores structure array contains one or more name/score combinations
 Post: Sorts scores structure array in descending order by score
 */

void sortData(Highscore scores[], int size) {
    int highIdx;                            // To hold index of highest remaining number
    
    for (int x = 0; x < (size - 1); x++) {
        highIdx = idxOfHigh(scores, x, size);
        swap(scores[highIdx], scores[x]);
    }

}






/*
 Definition of function idxOfHigh. The function passes in a Highscore structure array, a
 starting index and size of the array. It compares the remaining scores in the scores array
 from the starting index and returns the index of the highest score.
 
 Pre: The starting index of the remaining elements to traverse to determine highest score
 Post: Returns the index of the highest score in the prescribed range of the array
 */

int idxOfHigh(const Highscore scores[], int start, int size) {
    int target = start;                     // To define initial starting index
    
    for (int x = (start + 1); x < size; x++) {
        if (scores[x].score > scores[target].score) {
            target = x;
        }
    }
    
    return target;
}






/*
 Definition of function displayData. The function passes in a Highscore structure array,
 and the size of the array. It displays names and scores of the players in descending
 order.
 
 Pre: scores structured array sorted by scores in descending order
 Post: Displays the names and scores of the top scorers in descending order
 */

void displayData(const Highscore scores[], int size) {
    cout << "\nTOP SCORERS:" << endl;
    cout << "------------" << endl;
    
    for (int x = 0; x < size; x++) {
        cout << scores[x].name << ": " << scores[x].score << endl;
    }
}


/*
 
 How many scores will you enter?: 4
 
 SCORE #1
 ------------
 Enter the name: Suzy
 Enter the score: 600

 SCORE #2
 ------------
 Enter the name: Kim
 Enter the score: 9900

 SCORE #3
 ------------
 Enter the name: Armando
 Enter the score: 8000

 SCORE #4
 ------------
 Enter the name: Tim
 Enter the score: 514

 TOP SCORERS:
 ------------
 Kim: 9900
 Armando: 8000
 Suzy: 600
 Tim: 514
 Program ended with exit code: 0
 
 How many scores will you enter?: 5

 SCORE #1
 ------------
 Enter the name:
 Suzy Q
 Enter the score: 666

 SCORE #2
 ------------
 Enter the name: Kim Kardashian
 Enter the score:
 9999

 SCORE #3
 ------------
 Enter the name: Armando Biggies
 Enter the score: 8888

 SCORE #4
 ------------
 Enter the name: Tiny Tim
 Enter the score: 11

 SCORE #5
 ------------
 Enter the name: The Notorious RBG
 Enter the score: 987123

 TOP SCORERS:
 ------------
 The Notorious RBG: 987123
 Kim Kardashian: 9999
 Armando Biggies: 8888
 Suzy Q: 666
 Tiny Tim: 11
 Program ended with exit code: 0
 
 */

