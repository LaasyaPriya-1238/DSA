// #include <stdio.h>
// #include <string.h>

// #define MAX_WORDS 100  
// #define WORD_LEN 3      

// int main() 
// {
//     int t;
    
//     printf("Enter the number of test cases: ");
//     scanf("%d", &t);

//     while (t--) 
//     {
//         int n;

//         printf("\nEnter the number of words each player writes (max %d): ", MAX_WORDS);
//         scanf("%d", &n);

//         if (n > MAX_WORDS) 
//         {
//             printf("\nError: You can't enter more than %d words!\n", MAX_WORDS);
//             return 1;
//         }

//         char player[3][MAX_WORDS][WORD_LEN];  
//         int points[3] = {0, 0, 0};  

//         // Reading player words
//         for (int i = 0; i < 3; i++) 
//         {
//             printf("\nEnter %d words for Player %d (3 letters each):\n", n, i + 1);
//             for (int j = 0; j < n; j++) 
//             {
//                 scanf("%3s", player[i][j]);
//             }
//         }

//         // Calculate points
//         for (int i = 0; i < 3; i++) 
//         {        // Loop over players
//             for (int j = 0; j < n; j++) 
//             {    // Loop over their words
//                 int count = 0;

//                 // Check occurrences excluding the current player
//                 for (int k = 0; k < 3; k++) 
//                 {
//                     if (k == i) continue;    // Skip own words

//                     for (int l = 0; l < n; l++) 
//                     {
//                         if (strcmp(player[i][j], player[k][l]) == 0) 
//                         {
//                             count++;
//                         }
//                     }
//                 }

//                 // Assign points correctly
//                 if (count == 0) 
//                 {
//                     points[i] += 3;   // Unique word → 3 points
//                 } 
//                 else if (count == 1) 
//                 {
//                     points[i] += 1;    // Shared by 2 players → 1 point
//                 }
//             }
//         }

//         // Display points
//         printf("\nPoints for this test case: %d %d %d\n", points[0], points[1], points[2]);
//     }

//     return 0;
// }


//Program to calculate word game points
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<unordered_map>
using namespace std;
void solve();
int main(){
    int t;
    printf("Enter the number of testcases:");
    scanf("%d",&t);
    while(t--){
        solve();
        printf("\n");
    }
}
//Function to calculate word game points
void solve(){
    int n;
    printf("Enter the number of words by each person:");
    scanf("%d",&n);

    vector<vector<string>>words(3, vector<string>(n));
    unordered_map<string,int> freq;
    printf("Enter the words:");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j){
            cin >> words[i][j];
            freq[words[i][j]]++;
        }
    }

    vector<int>points(3,0);
    for(int i=0;i<3;i++){
        for(const string& word:words[i]){
            switch(freq[word]){
                case 1:
                       points[i]+=3;
                       break;
                case 2:
                       points[i]+=1;
                       break;
                case 3:
                       break;
                       
            }
        }
    }
    for(int i=0;i<3;i++){
    printf("%d ",points[i]);
    }
}
