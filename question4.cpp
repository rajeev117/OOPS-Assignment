#include <iostream>
using namespace std;

int main() {
    int votes[5] = {0};  
    int spoilt_ballots = 0;
    int ballot;

    cout << "Enter the ballot numbers (1 to 5). Enter 0 to stop: " << endl;
    
    while (true) {
        cin >> ballot;

        if (ballot == 0) {
            break;  
        }

        if (ballot >= 1 && ballot <= 5) {
            votes[ballot - 1]++;  
        } else {
            spoilt_ballots++;  
        }
    }

    cout << "\nVote count for each candidate:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Candidate " << (i + 1) << ": " << votes[i] << " votes" << endl;
    }

    cout << "Number of spoilt ballots: " << spoilt_ballots << endl;

    return 0;
}
