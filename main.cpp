#include<iostream>
#include<string>
using namespace std;
class ostad {
private:
    string user , pass;
    string answer , ask , question ;
    string descriptiveQuestion[30] , testQuestion[30] , fouranswer[200];
    int n = 0;
    float totalPoint = 0;
    float descriptivePoint[30], testPoint[30];
    int i = 0 , j = 0 , correctAnswer[30];
public:
    ostad(string s1 , string s2) {
        user = s1;
        pass = s2;
    }
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
            cout << "Exam list " << listNumber + 1 << " : " << examList [ listNumber ] << endl;
            for (int i = 0; questionTest [ i ] != "\0"; ++i) {
                int p = 0;
                cout << questionTest [ i ] << " ( " << pointTest [ i ] << " point )" << endl;
                for (int k = four; k < four + 4 ; ++k) {
                    cout << abcd [ p ] << " ) " << fourAwnser[ k ] << endl;
                    p++;
                }
            four +=4;
            }
            for (int i = 0; questionDescriptive [ i ] != "\0" ; ++i) {
                cout << questionDescriptive [ i ] << " ( " << pointDescriptive [ i ] << " point )" << endl;
            }

        } else {
            cout << "Invalid list number!" << endl;
        }
    }
};

