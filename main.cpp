#include<iostream>
#include<string>
#include<chrono>
#include<thread>
using namespace std;

class ostad {
protected:
    string user , pass , s1;
    string answer , ask , question ;
    string descriptiveQuestion[30] , testQuestion[30] , fouranswer[200];
    int n = 0;
    float totalPoint = 0;
    float descriptivePoint[30], testPoint[30];
    int i = 0 , j = 0 , correctAnswer[30];
    string examList[10];
    int nameNum = 0 , four = 0;
    char abcd[4] = { 'a' , 'b' , 'c' , 'd' };
public:
    void Exam() {
            while(totalPoint != 20) {
                cout << "Test or Descriptive ?";
                cin >> answer;
                if(answer == "Descriptive" || answer == "descriptive") {
                    cin >> ws;
                    getline(cin , question);
                    descriptiveQuestion[i] = question;
                    cin >> ws;
                    cout << "Score for this question" << i + 1 << " : ";
                    cin >> descriptivePoint[i];
                    while((descriptivePoint[i] + totalPoint) > 20) {
                        cout << "Score for this exam is more than 20!" << endl
                        << "your total score is " << totalPoint << " . " << endl
                        << "you can use up to " << 20 - totalPoint << " no more than this is allowed." << endl;
                        cin >> descriptivePoint[i];
                    }
                    totalPoint += descriptivePoint[i];
                    i++;
                } else if(answer == "test" || answer == "Test") {
                    cin >> ws;
                    getline(cin , ask);
                    testQuestion[j] = ask;
                    for(int j = 0 + n; j < 4 + n ; j++) {
                        getline(cin , fouranswer[j + n]);
                    }
                    cout << "correct answer is : (please enter the number --> (1,2,,3,4))";
                    cin >> correctAnswer[j];
                    n += 4;
                    cout << "score for this question " << j + 1 << " : " << endl;
                    cin >> testPoint[j];
                    while((testPoint[j] + totalPoint) > 20) {
                        cout << "score for this Exam is more than 20!" << endl <<
                        "your total score is " << totalPoint << " . " << endl <<
                        "you can use up to " << 20 - totalPoint << " ,no more than this is allowed. "
                        << endl;
                        cin >> testPoint[j];
                    }
                    totalPoint += testPoint[j];
                    j++;
                }
            }
        }
    void newExam( string namelist){
        examList [ nameNum ] = namelist ;
        cout << "new exam list '" << namelist << "' created succesfuly :)." << endl;
        nameNum ++;
    }
    void displayExam( int listNumber){
        if ( listNumber >= 0 && listNumber < 10 ){
            cout << "Exam list " << listNumber + 1 << " : " << examList [listNumber] << endl;
            for (int i = 0; testQuestion[i] != "\0"; ++i) {
                int p = 0;
                cout << testQuestion[i] << " ( " << testPoint[i] << " point )" << endl;
                for (int k = four; k < four + 4 ; ++k) {
                    cout << abcd[p] << " ) " << fouranswer[k] << endl;
                    p++;
                }
            four +=4;
            }
            for (int i = 0; descriptiveQuestion[i] != "\0" ; ++i) {
                cout << descriptiveQuestion[i] << " ( " << descriptivePoint[i] << " point )" << endl;
            }

        } else {
            cout << "Invalid list number!" << endl;
        }
    }
};
class ExamTime : public ostad {
public:
    bool isTime() {
        auto start = chrono:: steady_clock ::now();
        auto TimeLimit = chrono:: minutes(30);
        this_thread::sleep_for(TimeLimit);
        auto end = chrono:: steady_clock ::now();
        return(end - start) >= TimeLimit;
    }
};
class student {
private: 
    int a;
public:
};
int main() {
    string user, pass, person, nameList, sentence;
    int i = 0, num;
    cout << "ostad or student ?";
    cin >> person;
    cout << "enter your ID : ";
    cin >> user;
    cout << "enter your pasword : ";
    cin >> pass;
    ostad ob[10];
    if (person == "ostad" && user == "Lotfi" && pass == "1234") {
        while (i <= 9) {
            cout << "which one ?(1 : create new list , 2 : display exam)" << endl;
            cout << "if you type ( end ) the app will close." << endl;
            cin >> ws;
            getline(cin, sentence);
        }
    }
    return 0;
}