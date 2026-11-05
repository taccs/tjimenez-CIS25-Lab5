#include <iostream>
#include <iomanip>

using namespace std;

void getScores(int scores[], int size) {
    cout << "\n\nPlease enter " << size << " scores between 0-100. \n\n";
    for (int i=0; i<size; i++) {
        cout << "Number " << (i + 1) << ": ";
        int candidateScore = -1;
        cin >> candidateScore;
        while(candidateScore < 0 || candidateScore > 100) {
            cout << "\n\nScore must be between 0-100. Try Again: ";
            cin >> candidateScore;
            cout << endl;
        }
        scores[i] = candidateScore;
        cout << endl;
    }
}

void printScores(const int scores[], int size) {
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << scores[i] << endl;
    }
}

int getLowest(const int scores[], int size) {
    int lowest = 100;
    for (int i = 0; i < size; i++) {
        if(scores[i] < lowest) {
            lowest = scores[i];
        }
    }
    return lowest;
}

double calculateAverage(const int scores [], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    sum -= getLowest(scores, size);
    return (sum / ( size - 1 ));
}

int main() {
    const int SIZE = 5;
    int scores[SIZE];

    cout << fixed << setprecision(2);

    getScores(scores, SIZE); 
    printScores(scores, SIZE);

    double average = calculateAverage(scores, SIZE);

    cout << "The scores you enetered are: ";
    for (int i = 0; i < SIZE; i++) {
        cout << scores[i] << " ";
    }
    cout << "\n\nAfter dropping the lowest score, the average is: " << average << endl;
    return 0;
}