#include <iostream>
#include <string>
#include <fstream>

using namespace std;



int main()
{
    string file_name, cours, gread, ansr;
    float temp;
    fstream file;

    file.open( "test.txt" , ios::out | ios::in );
    /*
    if(!file)
    {
        cerr << "file not open" ;
        exit(1);
    } else {
        cout << "file open" ;
    }
    */

    /* data in file	البيانات في الملف
        ma200 18    kijgfdnnm
        cs800  27    mhgsxghk
    */

    while(file)// اذا الملف لم يصل الى نهاية الملف يتحقق الشرط
    {
        // file.get( ch )  ch == char   read one character in file
        //دالة الجت تقرأ بالحرف وتقرأ الحروف الخاصة مثل الفراغ والتاب و السطر
        // file.unget()     back one character in file
        // دالة نفي الجت ترجعك حرف للخلف  ويمكن وضعها في وايل للرجوع عدد معين من الحروف
        // getline(file , line , '#') read one line in file   # men read all character in file
        // دالة الجت لين تقوم بقراءة سطر كامل  من الملف والمدخل الثالث اختياري ,و# تعني قراءة الملف كما هوى
        file >> cours >> gread >> ansr;     // يقرأ لحد الفراغ او الحروف الخاصة
        // Operator ( >> ) Not read space & \n,\t,...  القراءة بالطريقة هذه لا يقرأ الحروف المخفية مثل الفراغ والسطر
        //  تستخدم في العادة لقراءة رقم او حرف او اسم  بتحديد حجم السلسلة او يستخدم مع السلاسل لقراءة اسم غير معروف طوله او قراءة رقم 
        if(!file) continue;//break;             // end of file back in while العودة للوايل وتنفيذ الشرط من جديد
        // هذه حتى يتجنب لو كان هناك سطر فارغ في نهاية الملف
        cout << "cours : " << cours << "\t gread : " << gread << "\t ansr : " << ansr << endl ;
        temp = stof( gread ); // نقل الرقم من السلسلة الى متغير رقمي
        cout << ansr[7] << ansr.at(4) << ++temp << endl ;  // يطبع الحرف رقم 7 و 4 الحروف يبدو من الصفر
        //متغير السلسلة يمكن ان تصل لكل الحروف فيه
    }

    file.clear();   //
    file.seekg(0);  //اعادة مؤشر القراءة لبداية الملف
    //or
    file.clear();   //
    file.seekp(0);  //اعادة مؤشر الكتابة لبداية الملف

    file.close();   //قفل الملف
    /* print program
        cours : ma200 gread : 18 ansr : kijgfdnnm
        nf19
        cours : cs800 gread : 27 ansr : mhgsxghk
        kx28
    */

    return 0;
}
