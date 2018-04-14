#include<fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void gradeExam(){
    system("cls");
   string name_file,    // اسم الملف
            course,     // اسم المادة
            question,   //  عدد الاسئلة
            ans,        // الاجابات الصحيحة
            id,         // رقم الطالب
            student_ans;//  اجابة الطالب
   cout << "Enter File Name : " ;
   cin >> name_file;
   fstream file( name_file , ios::in ),     // ملف ans
                                file_grd,   // ملف الدرجات
                                file_sts;   // ملف كل سؤال كم طالب حله
   if(!file)
   {
       cerr << "File (\"" << name_file << "\") not open " << endl;
       system("pause");
       return ;
   }
   file >> course >> question >> ans;   //قرائة السطر الاول



   file_grd.open(course + ".grd" , ios::out);
   file_grd << course << " " << question << "\n";   // كتابة السطر الاول في ملف الدرجات

   file_sts.open(course + ".sts" , ios::out);

   string grd ="";                              // متغير لوضع الاجابات على شكل صفر وواحد
   int q = stoi(question);
   int Count = 0,         //    عدد اجابات كل طالب
        correct[q],       //    كل سؤال كم اجابه طالب
        nostu = 0;        //  عدد الطلبة
   for(int i = 0 ; i < q; i++)
    {   correct[i] = 0; }

   while(!file.eof())
   {
        file >> id >> student_ans;          //قراءة درجات جميع الطلبة
        if(!file) continue;                 // تفادي سطر فارغ في نهاة الملف
        nostu++;
        for(int i = 0; i < q ; i++)
        {
            if(ans[i] == student_ans[i])
            {
                Count++;
                grd += "1";
                correct[i]++;
            }
            else{
                grd += "0";
            }
        }// end for

        file_grd << id << " " << Count << " " << grd << "\n";       //كتابة في ملف الدرجات درجت كل طالب
        Count = 0;                                                  //  تصفير البيانات لحساب طالب جديد
        grd = "";                                                   //
   }// end while


   file_sts << course << " " << question << " " << nostu << "\n";   //كتابة اول سطر في ملف الاسئلة
   for(int i = 0; i < q ; i++)
   {
       file_sts << correct[i] << "\n";                              //
   }//end for
   cout << "Grading Done ... " << endl;
   file.close();
   file_grd.close();
   file_sts.close();
   system("pause");
}

void showGrades(){
    system("cls");
    string name_file,   // اسم الملف
            name,       // اسم الملف بعد التعديل
            course,     // اسم المادة
            question,   //  عدد الاسئلة
                id,     // رقم الطالب
                ans,    // درجة الطالب
                t;      // الاجابات الصحيحة 0101010
    cout << "Enter File Name : " ;
    cin >> name_file;
    name = name_file.substr(0 , 5);     // الدالة تقوم باخد الخمسة الحروف الاولى
    fstream file( name + ".grd" , ios::in );
    if(!file)
    {
        cerr << "File (\"" << name << ".grd\") not open " << endl;
        system("pause");
        return ;
    }
    file >> course >> question;
    cout << "No oF question : " << question << endl;
    cout << "Student\tNo\tans\tprcnty %" << endl;
    int Count = 0;  //  عدد الطلبة
    float stu = 0,  //  عدد الناجحين
                X,
            Y = stof(question); //  عدد الاسئلة
    while(!file.eof())
    {
        file >> id >> ans >> t;
        X = stof(ans);
        if(!file) continue;
        cout << "\t" << id << "\t" << ans << "\t" <<int( (X/Y)*100 ) << "%" << endl;
        if(X >= Y/2){ stu++; }
        Count++;
    }
    cout << "Coures : " << course << endl;
    cout << "no of question : " << question << endl;
    cout << "no of student : " << Count << endl;
    cout << "no of passed : " << stu << endl;
    cout << "pass percentage : " << int( (stu/Count)*100 ) << "%"<< endl;
    file.close();
    system("pause");
}

void showStatistics(){
    system("cls");
    string name_file,        // اسم الملف
                name,        // اسم الملف بعد التعديل
                course,      // اسم المادة
                question,    //  عدد الاسئلة
                nubr_ans,    //    كل سؤال كم اجابه طالب
                nostu;      //  عدد الطلبة
    cout << "Enter File Name : " ;
    cin >> name_file;
    name = name_file.substr(0 , 5);
    fstream file( name + ".sts" , ios::in );
    if(!file)
    {
        cerr << "File (\"" << name << ".grd\") not open " << endl;
        system("pause");
        return ;
    }
    file >> course >> question >> nostu;
    cout << "Coures : " << course << endl;
    cout << "no of question : " << question << endl;
    cout << "no of student : " << nostu << endl;
    cout << "question  correct prcntg % " << endl;
    for(int i=1 ; !file.eof() ; i++)
    {
        file >> nubr_ans ;
        if(!file) continue;
        cout << "\t" << i << "\t" << nubr_ans << "\t" << int( stof(nubr_ans)/stof(nostu)*100 ) << "%" << endl;
    }
    file.close();
    system("pause");
}

int enterChoice(){
   cout << "\n\nChoice ................" << endl
        << "1 - Add  Grade" << endl
        << "2 - Grade Exam" << endl
        << "3 - Show Grade" << endl
        << "4 - Show Statistics" << endl
        << "0 - End program " << endl;
   int menuChoice;
   cout << "\nEnter your choice: "; cin >> menuChoice;
   return menuChoice;
}

main(){
   int choice;
   do {
        system("cls");
       choice = enterChoice();
       switch (choice) {
          case 0: exit(1);
          case 1: cout << "Under devolemnet ... ";
                  system("pause");
                  break;
          case 2:
                  gradeExam();
                  break;
          case 3:
                  showGrades();
                  break;
          case 4:
                  showStatistics();
                  break;
          default: cout << "Enter valid choice ...\n";
       }
   } while(choice);
   cout <<endl;
   system("pause");
}
