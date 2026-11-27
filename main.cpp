#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    const string invalidScoreMessage =
        "Invalid score. Enter a value from 0 to 100.";

    string studentName;
    int studentCount = 0;
    double sumOfAverages = 0;

    // Repeat for many students until the teacher types "end"
    while (true) {
        cout << "Student name (or end to finish): ";
        cin >> studentName;

        if (studentName == "end") {
            break;
        }

        int scoreSum = 0;

        // Read 5 scores for one student
        for (int scoreNumber = 1; scoreNumber <= 5; scoreNumber++) {
            int score;

            // Ask again until the score is a whole number from 0 to 100
            while (true) {
                cout << "Score " << scoreNumber << ": ";
                cin >> score;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << invalidScoreMessage << endl;
                } else if (score < 0 || score > 100) {
                    cout << invalidScoreMessage << endl;
                } else {
                    break;
                }
            }

            scoreSum += score;
        }

        double average = scoreSum / 5.0;
        char grade;

        if (average >= 90) {
            grade = 'A';
        } else if (average >= 75) {
            grade = 'B';
        } else if (average >= 60) {
            grade = 'C';
        } else {
            grade = 'F';
        }

        cout << fixed << setprecision(1);
        cout << studentName << ": average " << average
             << ", grade " << grade << endl;

        studentCount++;
        sumOfAverages += average;
    }

    if (studentCount == 0) {
        cout << "No students entered" << endl;
    } else {
        cout << "Students entered: " << studentCount << endl;
        cout << "Class average: " << fixed << setprecision(1)
             << sumOfAverages / studentCount << endl;
    }

    return 0;
}
