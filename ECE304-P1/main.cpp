#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>

struct student{
    int id;
    int score;
    char grade;
};
int main() {
    srand(time(0));
    std::cout << "Enter Number of Students" << std::endl;
    int numberOfStudents;
    std::cin >> numberOfStudents;
    std::cout << "Generating " << numberOfStudents << " records." << std::endl;
    student *students = new student[numberOfStudents];

    int sumScores = 0;
    for (int i = 0; i < numberOfStudents; ++i) {
        students[i].id = i +1;
        students[i].score = rand() % 71 + 30;
        sumScores += students[i].score;
    }
    double mean = sumScores/numberOfStudents;
    double partialSigma = 0;
    for (int i = 0; i < numberOfStudents; ++i) {
        int xi = students[i].score;
        partialSigma += (xi - mean)*(xi - mean);
    }
    double sigmaSquared = partialSigma/numberOfStudents;
    double sigma = sqrt(sigmaSquared);
    for (int i = 0; i < numberOfStudents; ++i) {

        int score = students[i].score;
        if(score < mean - 1.5*sigma){
            //F
            students[i].grade = 'F';
        }else if(score >= mean - 1.5*sigma && score < mean - 0.5*sigma){
            //D
            students[i].grade = 'D';
        }else if(score >= mean - 0.5*sigma && score < mean + 0.5*sigma){
            //C
            students[i].grade = 'C';
        }else if(score >= mean + 0.5*sigma && score < mean + 1.5*sigma){
            //B
            students[i].grade = 'B';
        }else if(score >= mean + 1.5*sigma){
            //A
            students[i].grade = 'A';
        }else{
            //Shouldn't happen. Throw an error.
            std::cout << "Somehow, someone got a grade that doesn't fall in these categories." << std::endl;
        }
    }
    std::ofstream out_stream;
    out_stream.open("grades.txt");
    std::cout << "ID\t\tScore\tGrade" << std::endl;
    out_stream << "ID\t\tScore\tGrade" << std::endl;
    for (int i = 0; i < numberOfStudents; ++i) {
        std::cout << students[i].id << "\t\t" << students[i].score << "\t\t" << students[i].grade << std::endl;
        out_stream << students[i].id << "\t\t" << students[i].score << "\t\t" << students[i].grade << std::endl;
    }
    std::cout << "Mean = " << mean << std::endl;
    std::cout << "Std. Dev. = " << sigma << std::endl;
    out_stream.close();
    return 0;
}