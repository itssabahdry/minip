#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<ctime>
using namespace std;

const int sizeOfExam = 10;
const int maximumExamForStudent = 400;
const int maximumtestQuestion = 30 , maximumDescriptiveQuestion = 30;
class student;
class saveNameAndExam{
private:
     struct Protest {
        string name;
        int examNum;
        string protestText;
        string response;
        bool resolved;
    };
    vector<pair< string , int >> forCheckAnswer;
    vector <int> numExam;
    vector <Protest> protests;
    int countExam = 0 ;
public:
void addProtest(string name, int examNum, string protestText) {
        protests.push_back({name, examNum, protestText, "", false});
    }
    void displayProtests() {
        for (const auto& protest : protests) {
            cout << "Student: " << protest.name << ", Exam: " << protest.examNum << ", Protest: " << protest.protestText << endl;
            if (protest.resolved) {
                cout << "Response: " << protest.response << endl;
            }
        }
    }
void resolveProtest(string name, int examNum, string response) {
        for (auto& protest : protests) {
            if (protest.name == name && protest.examNum == examNum) {
                protest.response = response;
                protest.resolved = true;
                cout << "Response to " << name << "'s protest for exam " << examNum << ": " << response << endl;
            }
        }
    }

    void displayStudentProtestResult(string name, int examNum) {
        for (const auto& protest : protests) {
            if (protest.name == name && protest.examNum == examNum) {
                if (protest.resolved) {
                    cout << "Response to your protest for exam " << examNum << ": " << protest.response << endl;
                } else {
                    cout << "Your protest for exam " << examNum << " is still being reviewed." << endl;
                }
            }
        }
    }
    void setNameAndExam( string name , int listnumber , int num){
        forCheckAnswer.push_back(make_pair(name , listnumber));
        numExam.push_back(num);
    }
    void search(int numlist){
        for (int i = 0 ; i < forCheckAnswer.size() ; ++i) {
            if ( forCheckAnswer[i].second == numlist ){
                cout << forCheckAnswer[i].first << "\t";
            }
        }
    }
 void search2(string name){
        for (int i = 0; i < forCheckAnswer.size(); ++i) {
            if (forCheckAnswer[i].first == name)
                cout << forCheckAnswer[i].second << "\t";
        }
    }
    int search3( string name , int numlist ){
        for (int i = 0; i < forCheckAnswer.size(); ++i) {
            if ( forCheckAnswer[i].first == name && forCheckAnswer[i].second == numlist )
                return numExam[i];
        }
    }
    int selectAnswerExam( string name){
        for (int i = 0; i < forCheckAnswer.size() ; ++i) {
            if ( forCheckAnswer[i].first == name ){
                return numExam[i];
            }
        }
    }
};
class ostad {
protected:
    string user , pass , s1;
    string answer , ask;
    string descriptiveQuestion[maximumDescriptiveQuestion] , testQuestion[maximumtestQuestion] , fouranswer[maximumtestQuestion * 4];
    int n = 0;
    float totalPoint = 0;
    vector <string> explanation;
    float descriptivePoint[maximumDescriptiveQuestion], testPoint[maximumtestQuestion];
    int i = 0 , j = 0;
    int nameNum = 0 , four = 0;
    char abcd[4] = { 'a' , 'b' , 'c' , 'd' } , correctAnswer[maximumtestQuestion];
    vector <string> nameStudent , examList;
    char testAnswer [maximumtestQuestion];
    string   descriptiveAnswer [30] ;
    int num  , count , numberOfTestQuestion  ;
    vector <pair< string , float >> pointForStudent;
    vector <int> numlistforAwnser;
    int ExamTime = 0;
public:
 void examTime() {
        cout << "Enter the desired test time in seconds : " << endl;
        cin >> ExamTime;
        ExamTime *= CLOCKS_PER_SEC;
    }
    void Exam() {
            while(totalPoint != 20) {
                cout << "Test or Descriptive ?";
                cin >> answer;
                cin.ignore();
                if(answer == "Descriptive" || answer == "descriptive") {
                    cout << "Descriptive question " << i + 1 << " : ";
                    getline(cin , descriptiveQuestion[i]);
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
                    cout << "Test question " << j + 1 << " : ";
                    getline(cin , testQuestion[i]);
                    int p = 0;
                    for(int j = 0 + n; j < 4 + n ; j++) {
                        cout << abcd[p] << " ) ";
                        getline(cin , fouranswer[j + n]);
                        p++;
                    }
                    cout << "correct answer is : (please enter the number --> (a,b,c,d))";
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
        examList.push_back( namelist );
        cout << "new exam list '" << namelist << "' created succesfuly :)." << endl;
    }
    void displayExam( int listNumber){
        if ( listNumber >= 0 && listNumber < 10 ){
            cout << "Exam list " << listNumber + 1 << " : " << examList [listNumber] << endl
                 << "list of student who can take the exam : ";
            for (size_t k = 0; k < nameStudent.size() ; ++k) {
                if ( k == 0 )
                    cout << nameStudent[k] ;
                else
                    cout << " , " <<  nameStudent[k] ;
            }
            cout << " ." << endl;
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
    void addStudent(){
        int numberOfStudent;
        cout << "how many student do you want to add ?" << endl;
        cin >> numberOfStudent;
        cout << "the list of student who can take the exam: ";
        for (int i = 0; i < numberOfStudent ; ++i) {
            string name;
            cin >> name;
            nameStudent.push_back( name );
        }
    }
   string searchName( string name ){
        for (size_t k = 0; k < nameStudent.size() ; ++k) {
            if ( nameStudent.at( k ) == name )
                return name;
        }
    }
    void calculateAverageScores(const vector<int>& selectedExamLists) {
        vector<pair<string, float>> studentAverages;
        vector<pair<string, vector<float>>> studentScores;

        for (const int& listNumber : selectedExamLists) {
            if (listNumber >= 0 && listNumber < examList.size()) {
                for (const auto& student : pointForStudent) {
                    for (size_t k = 0; k < numlistforAwnser.size(); ++k) {
                        if (numlistforAwnser[k] == listNumber) {
                            bool found = false;
                            for (auto& entry : studentScores) {
                                if (entry.first == student.first) {
                                    entry.second.push_back(student.second);
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) {
                                studentScores.push_back(make_pair(student.first, vector<float>{student.second}));
                            }
                        }
                    }
                }
            }
        }
        for (const auto& entry : studentScores) {
            float sum = 0;
            for (const auto& score : entry.second) {
                sum += score;
            }
            float average = sum / entry.second.size();
            studentAverages.push_back(make_pair(entry.first, average));
        }
        for (size_t i = 0; i < studentAverages.size(); ++i) {
            for (size_t j = 0; j < studentAverages.size() - i - 1; ++j) {
                if (studentAverages[j].second > studentAverages[j + 1].second) {
                    swap(studentAverages[j], studentAverages[j + 1]);
                }
            }
        }
        cout << "Student averages in ascending order:" << endl;
        for (const auto& entry : studentAverages) {
            cout << entry.first << ": " << entry.second << endl;
        }
    }
};
class student : public ostad {
public:
 void displayExamForStudent(int listNumber) {
        if ( listNumber >= 0 && listNumber < sizeOfExam ) {
            cout << "Exam list " << listNumber + 1 << " : " << examList [ listNumber ] << endl;
            count = 0;
            num = 1;
            four = 0;
            clock_t now = clock();
         while (clock() - now < ExamTime) {
            for (int i = 0; testQuestion[i] != "\0"; ++i) {
                cout << "Question " << num  << " : " << endl;
                int p = 0;
                cout << testQuestion[i] << " ( " << testPoint[i] << " point )" << endl;
                for (int k = four; k < four + 4 ; ++k) {
                    cout << abcd[p] << " ) " << fouranswer[k] << endl;
                    p++;
                }
                four +=4;
                num++;
            }
         for (int i = 0; i < this->i; ++i) {
                    cout << "Question " << num << " : " << endl;
                    cout << descriptiveQuestion[i] << " ( " << descriptivePoint[i] << " point )" << endl;
                    num++;
                }
             if(clock() - now >= ExamTime) {
                 cout << "time is up!" << endl;
                 for(int i = 0 ; i < j ; i++) {
                     if(testAnswer[i] == '\0') {
                         testAnswer[i] = 'f';
                         break;
                     }
                 }
             }
                for (int i = 0; i < j; ++i) {
                    cin >> answer;
                    if (answer.empty()) {
                        testAnswer[i] = 'f';
                    } else
                        testAnswer[i] = answer.at(0);
                }
                cin.ignore();
                for (int k = 0; k < this->i; ++k) {
                    getline(cin, answer);
                    if (answer.empty()) {
                        descriptiveAnswer[k] = "No answer";
                    } else
                        descriptiveAnswer[k] = answer;
                }
             }
        } else {
            cout << "Invalid list number!" << endl;
        }
    }
 void displayAnswer( int listNumber , string nameStudent){
        if ( listNumber >= 0 && listNumber < sizeOfExam ) {
            cout << "Exam list " << listNumber + 1 << " : " << examList [ listNumber ] << endl;
            count = 0;
            num = 1;
            four = 0;
            float point = 0;
            for (int i = 0; i < j  ; ++i) {
                cout << "Question " << i + 1 << " :  "
                     << testQuestion[i] <<  " ( " << testPoint[i] << " point )" << endl
                     << "student awnser:  " << testAnswer[i] << endl
                     << "correct awnser:  " << correctAnswer[i] << endl;
                if ( testAnswer[i] == correctAnswer[i] )
                    point +=testPoint[i];
                num++;
            }
            if( num > 0 )
              cout << "total test score:" << "  " << point << endl;
            for (int i = 0; i < this-> i ; ++i) {
                cout << "Question " << i + 1 << " :  "
                     << descriptiveQuestion[i] << " ( " << descriptivePoint[i] << " point )" << endl
                     << "student answer:  " << descriptiveAnswer[i] << endl
                     << "Enter score for this answer: ";
                int score;
                cin >> score;
                while ( score > descriptivePoint[i]){
                    cout << "The entered score exceeds the maximum score for this question. please enter a valid score: ";
                    cin >> score;
                }
                point += score;
                cin.ignore();
                num++;
                cout << "Do you have an explanation for this question?" << endl ;
                string s;
                getline(cin , s);
                if ( s == "yes" || s == "Yes" ){
                    cin >> s;
                    explanation.push_back(s);
                }
                else
                    continue;
            }
            pointForStudent.push_back( make_pair( nameStudent , point ) );
            numlistforAwnser.push_back( listNumber );
        } else {
            cout << "Invalid list number!" << endl;
          }
    }
 void searchNumlistForScore(int numlist){
        for (int k = 0; k < numlistforAwnser.size() ; ++k) {
            if ( numlistforAwnser[k] == numlist )
                cout << pointForStudent[k].second << endl;
        }
}
void changeScore(string name , float newScore){
        for (int k = 0; k < pointForStudent.size(); ++k) {
            if ( name == pointForStudent[k].first )
                pointForStudent[k].second = newScore;
        }
    }
};

int main() {
    string user, pass, person, nameList, sentence;
    int flag = 0 , i = 0, num , countForStudent = 0;
    ostad ob[sizeOfExam];
    student *ob1[maximumExamForStudent];
    saveNameAndExam ob3;
     vector <pair<string , int>> examinationProtest;
    vector <pair<string , string>> answerOstad;
    vector <string> description ;
    while ( flag != 10 ) {
        cout << "ostad or student ?";
        cin >> person;
        cout << "enter your ID : ";
        cin >> user;
        cout << "enter your pasword : ";
        cin >> pass;
        if (person == "ostad" && user == "Lotfi" && pass == "1234") {
            while (i <= sizeOfExam) {
                cout<< "which one ? ( 1 : create new list , 2 : display exam , 3 : add student , 4 : check the answer  , 5 : see the max average point of students ,  6 : examination protest)"
                << endl << "the maximum of exam list is '" << sizeOfExam << "' "
                << "and your number of your exam list is '" << i << "' ." << endl
                << "if you type ( end ), the app will be close." << endl;
                cin >> ws;
                getline(cin, sentence);
                if (sentence == "1" || sentence == "create new list") {
                    cout << "namelist: ";
                    getline(cin, nameList);
                    ob[i].newExam( nameList );
                    ob[i].Exam();
                    ob[i].examTime();
                    ob[i].addStudent();
                    i++;
                }
                if (sentence == "2" || sentence == "display exam") {
                    cout << "Which exam list do you want?" << endl
                         << "Sort that list by typing in the natural numbers. ";
                    cin >> num;
                    ob[num - 1].displayExam(num - 1);
                }
                if (sentence == "3" || sentence == "add student") {
                    int numberList;
                    cout << "for which exam list ?";
                    cin >> numberList;
                    ob[numberList - 1].addStudent();
                }
                if (sentence == "4" || sentence == "check the answer") {
                        int numberList;
                        cout << "for which exam list ?";
                        cin >> numberList;
                        ob3.search( numberList );
                        cout << endl << "which one ?";
                        string nameStudent;
                        cin.ignore();
                        getline(cin , nameStudent );
                        ob1[ ob3.selectAnswerExam( nameStudent ) ] = static_cast<student *>(&ob[ numberList - 1]);
                        ob1[ ob3.selectAnswerExam( nameStudent ) ] -> displayAnswer( numberList - 1 , nameStudent );

                    }
                if (sentence == "5" || sentence == "see the max avarge point of studets") {
                    int numLists;
                    cout << "Enter the number of exam lists to calculate average scores for: ";
                    cin >> numLists;
                    vector<int> selectedExamLists(numLists);
                    cout << "Enter the exam list numbers: ";
                    for (int i = 0; i < numLists; ++i) {
                        cin >> selectedExamLists[i];
                    }
                    ostad teacher;
                    teacher.calculateAverageScores(selectedExamLists);
                }
                 if (sentence == "6" || sentence == "examination protest") {
                        cout << "protests:" << endl;
                        ob3.displayProtests();
                        cout << "Enter student name to resolve protest: ";
                        string studentName;
                        cin >> studentName;
                        cout << "Enter exam number: ";
                        int examNum;
                        cin >> examNum;
                        cout << "Enter response: ";
                        string response;
                        cin.ignore();
                        getline(cin, response);
                        ob3.resolveProtest(studentName, examNum, response);
                        cout << "Do you want to change Score? (yes or no) : ";
                        string ans;
                        cin >> ans;
                        if (ans == "yes" || ans == "Yes"){
                            float newp;
                            cin >> newp;
                            int index = ob3.search3(studentName, examNum );
                            ob1[index]->changeScore( studentName , newp );
                        }
                    }else if (sentence == "end" || sentence == "End") {
                    flag++;
                    break;
                }
            }
        } else if (person == "student" || person == "Student") {
            string sentence;
            string nameStudent;
            string studentPassword;
            cout << "what is your name?";
            cin >> nameStudent;
            cout << "enter your password : ";
            cin >> studentPassword;
            cout<< "which one ? ( 1 : check your exam , 2 : show exam to answer it , 3 : examination protest , 4 : history of exams , 5 : see your score , 6 : result protest)" << endl
                << "if you type ( end ), the app will be close." << endl;
            cin.ignore();
            getline(cin,sentence);
            if (sentence == "end" || sentence == "End") {
                flag++;
                break;
            }
            else {
                if (sentence == "1" || sentence == "check my exam" || sentence == "check your exam") {
                    int numberOfExam[sizeOfExam], count = 0;

                    for (int j = 0; j < i; ++j) {
                        if (ob[j].searchName(nameStudent) == nameStudent) {
                            numberOfExam[count] = j;
                            count++;
                        }
                    }
                    cout << "Exam lists that are there for you : ";
                    if (count == 0)
                        cout << "not found any exam!" << endl;
                    else {
                        for (int j = 0; j < count; ++j) {
                            cout << numberOfExam[j] + 1 << " ";
                        }
                    }
                }
        if (sentence == "2" || sentence == "show exam to answer it") {
                    int numberOfExam[sizeOfExam], count = 0;
                    for (int j = 0; j < i; ++j) {
                        if (ob[j].searchName(nameStudent) == nameStudent) {
                            numberOfExam[count] = j;
                            count++;
                        }
                    }
                    cout << "Exam lists that are there for you : ";
                    if (count == 0)
                        cout << "not found any exam!" << endl;
                    else {
                        for (int j = 0; j < count; ++j) {
                            cout << numberOfExam[j] + 1 << " ";
                        }
                        int n;
                        cout << endl <<  "which exam do you want to start ? ";
                        cin >> n;
                        ob1[countForStudent] = static_cast<student *>(&ob[n - 1]);
                        ob1[ countForStudent ]->displayExamForStudent(n - 1);
                        ob3.setNameAndExam(nameStudent, n, countForStudent);
                        countForStudent++;
                    }
                }
                if (sentence == "3" || sentence == "examination protest") {
                    int numberOfExam[sizeOfExam], count = 0;
                    for (int j = 0; j < i; ++j) {
                        if (ob[j].searchName(nameStudent) == nameStudent) {
                            numberOfExam[count] = j;
                            count++;
                        }
                    }
                    cout << "Exam lists that are there for you : ";
                    if (count == 0)
                        cout << "not found any exam!" << endl;
                    else {
                        for (int j = 0; j < count; ++j) {
                            cout << numberOfExam[j] + 1 << " ";
                        }
                        cout << "which exam you want to protest? :  ";
                        int numlist;
                        cin >> numlist;
                        cin.ignore();
                        string descript;
                        getline(cin, descript);
                        ob3.addProtest(nameStudent, numlist, descript);
                    }
                }
                        if (sentence == "4" || sentence == "history of exams") {

                        }
                        if (sentence == "5" || sentence == "see your score" || sentence == "see my score") {
                            string sentence1;
                            while ( sentence1 != "end" ) {
                                cout << "the list exam for you:" << "\t";
                                ob3.search2(nameStudent);
                                cout << endl;
                                int number;
                                cin >> number;
                                int index = ob3.search3(nameStudent, number);
                            if (index < 0 || index >= countForStudent) {
                                cout << "Invalid exam number or no exam found!" << endl;
                            } else {
                                student *studentobj = ob1[index];
                                if (studentobj != nullptr) {
                                    studentobj->searchNumlistForScore(number);
                                } else
                                    cout << "student object not found for the given index!" << endl;
                            }
                            cout << "Enter 'end' to finish or any key to continue: ";
                            cin >> sentence1;
                            }
                        }
                 if (sentence == "6" || sentence == "result protest") {
                        int examNum;
                        cout << "Enter exam number: ";
                        cin >> examNum;
                        ob3.displayStudentProtestResult(nameStudent, examNum);
                    }
            }
        }else
            cout << "Login error." << endl << "One of the parts name , user or pass Wrong!";
        }
    return 0;
}
