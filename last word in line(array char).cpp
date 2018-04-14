#include <iostream>
#include <cstring>

using namespace std;

int lastIndexOf(const char * str, const char toFind);
char* lastWordOf(const char * line);

int main()
{
    int maxSize = 256;
	char line[maxSize] = {0};
	cout << "Please enter line: " << endl;
	cin.getline(line, maxSize-1, '\n');
	char* word = lastWordOf(line);
	cout << endl << "Last word of line is : " << word <<endl;
    return 0;
}

char* lastWordOf(const char * line)
{
    int offset = lastIndexOf(line,' ') + 1;// الدالة ترجع في مكان الفراغ لهدا نزيد في واحد
    char* temp = new char[15];// هدي باش امتى نتطلع من الفنكتشن ماتتلوحش
    strcpy(temp, line + offset);
    return temp;
}

int lastIndexOf(const char * str, const char toFind)
{
    int index = -1;
    int i = 0;

    while(str[i] != '\0')
    {
        if(str[i] == toFind)//  فيه خطءهني امتى ادخل فراغ في الاخير عند الادخال
        {
            index = i;
        }
        i++;
    }

    return index;
}
