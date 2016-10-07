//
//  main.cpp
//  Guessing Passwords
//
//  Created by Edward Chu on 1/10/2016.
//  Copyright (c) 2016 Puffins. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // initialization
    int numGuesses, wrongConsec;
    vector<string> guesses;
    string password, temp;
    vector<int> guessesLength;
    cin >> numGuesses >> wrongConsec;
    for(int i=0;i<numGuesses;i++){
        cin >> temp;
        guesses.push_back(temp);
    }
    cin >> password;
    
    
    //putting lengths of passwords in a vector
    for(int i=0;i<password.length();i++){
        guessesLength.push_back(0);
    }
    
    for(int i=1;i<=password.length();i++){
        for(int j=0;j<numGuesses;j++){
            if(guesses[j].length()==i){
                guessesLength[i-1]++;
                
            }
        }
    }
    
    //fucking hell duplicating cases
    int count=0;
    for(int i=0;i<numGuesses;i++){
        if(password==guesses[i]){
            count++;
        }
    }
    count--;
    guessesLength[password.length()-1] -= count;
    
    int totalBelow=0;
    
    for(int i=0;i<guessesLength.size()-1;i++){
        totalBelow += guessesLength[i];
    }
    
    //best case
    cout << (totalBelow/wrongConsec)*5 + totalBelow + 1 << " ";
    
    
    //worse case
    cout << ((totalBelow+guessesLength[guessesLength.size()-1]-1)/wrongConsec)*5 + totalBelow + guessesLength[guessesLength.size()-1];
    
    
    
    
    
    return 0;
}
