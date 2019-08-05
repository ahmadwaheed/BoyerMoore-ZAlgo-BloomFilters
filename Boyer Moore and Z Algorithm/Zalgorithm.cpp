#include <list>
#include <string>
#include <vector>
#include <iostream>
#include "Zalgorithm.h"
//using namespace std;

// Input: Pattern P, text T, data structure matches to store result
//      P is 1-indexed, so we represent the pattern "abc" by P = " abc"
//      T is also 1-indexed
// Output: Indices corresponding to occurrances of P in T
void ZalgorithmBasedMatching(const std::string& P,const std::string& T,
                             std::list<int>* matches) {
    // TODO: Implement this
    int a = 0;
    std::string conStr = P + "$" + T;
    int len = conStr.length();
    std::vector<int> vect;

    Zalgorithm(conStr, &vect);

    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i] == P.length())
        {
            matches->push_back(i);
        }
    }

    /* for(int i=0;i<len;i++){
     if(len == P.length())
     cout << "Occurance found at " << i - P.length() - 1 << endl;
     }*/
}

// Input: String S, data structure Z to store result
//      S is 1-indexed, so we represent the string "abc" by S = " abc"
// Output: Indices corresponding to occurrances of P in T
void Zalgorithm(const std::string& S, std::vector<int>* Z) {
    // TODO: Implement this
    int len2 = S.length(); //setting strings length
    int left = 0,right = 0,k; // setting initial values

    for(int a=1;a<len2;a++){
        if(a > right){ //(1 > 0)
            left = right = a; //left and right will become 1

            //right < len2 checking for right to be not out of bound
            //S[right - left] == S[right] (0 == 1) comparing index 0 and 1
            while(S[right - left] == S[right] && right < len2) {
                //since it is not same we came outta while loop
                right++;
            } // while loop

          //dereferencing
          (*Z)[a] = right - left; //putting 0 in Z[a]
            right--; //value of right becomes 0

            //After that we go top of the for loop and value becomes 2
        }else{
            k = a - left;

            if(S[k] < right - a + 1){
                Z[a] = Z[k];
            }else{
                left = a;
                while(S[right] == S[right - left] && right < len2)
                    right++;

                //Dereferencing
                (*Z)[a] = right - left;
                right--;
            }
        }
    }
}

// Input: String S, positions i and j of S
//      S is 1-indexed, so we represent the string "abc" by S = " abc"
// Output: length of longest common prefix of S[i, n] and S[j, n] where n = |S|
int MatchLength(const std::string& S, int i, int j) {
    // TODO: Implement this
    int match_length = 0;
    int j_count = j;

    for(int k=i; k < S.length();k++) { //for the length of string

        if(S[k] != S[j_count] || j_count > S.length()) {
            break;
        }
        else {
            j_count++;
            match_length++;
        }
    }
    return match_length;
}
