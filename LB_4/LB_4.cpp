/* С клавиатуры или с файла (*) (пользователь сам может выбрать способ ввода) вводится последовательность, 
   содержащая от 1 до 50 слов, в каждом из которых от 1 до 10 строчных латинских букв и цифр. 
   Между соседними словами произвольное количество пробелов. За последним символом стоит точка.
*/

/*2)    Необходимо отредактировать входной текст:

·        удалить лишние пробелы;

·        удалить лишние знаки препинания (под «лишними» подразумевается несколько подряд идущих знаков (обратите внимание, что «…» - корректное использование знака) в тексте);

·        исправить регистр букв, если это требуется (пример некорректного использования регистра букв: пРиМЕр);*/

/*Вывести на экран слова последовательности в алфавитном порядке*/

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm> 


using namespace std;

void OpenFile() {

    string path = "MyFiles.txt";

    ifstream fin;
    fin.open(path);

    if (!fin.is_open())
    {
        cout << "error" << endl;
    }

    else {

        cout << "File is open!";
        string str;

        while (!fin.eof()) {
            fin >> str;
            cout << str << "\n";
        }
    }

    fin.close();

   

}

void inputText() {
      
}

void MainMenu() {

    while (1)
    {
        int opt;

        cout << endl << "----------------------------" << endl;
        cout << endl << "      Main Menu   " << endl;
        cout << endl << "----------------------------" << endl;
        cout << endl << "Chose: 1 or 2 " << endl;


        cin >> opt;
        cout << "\n" << endl;

        switch (opt)
        {
        case 1:
            OpenFile();
            break;
        case 2:
            //
            break;
        case 0:
            exit(1);
        default:
            break;
        }
    }
}

void sortString(string& msg) 
{
  for (int i = 1; i < msg.length(); i++) 
  {
    for (int j = 0; j < msg.length(); j++) 
    {
        if ((msg[i], msg[j]) > 0) 
         {
             int tmp = msg[i];
             msg[i] = msg[j];
             msg[j] = tmp;
         }
    }
  }
}

int main()
{

    //MainMenu();

    /*string path = "MyFiles.txt";
    cout << "Name file .txt: ";
    cout << "Create file: \n";

    cin >> path;
    ofstream fout;
    fout.open(path);

    if (!fout.is_open()) {
        cout << "errrorrrr!!!\n";
    }

    else {

        for (int i = 0; i < 10; i++) {
            string text;
            cout << "Enter the text: ";
            cin >> text;
            fout << text << endl;
        }      
    }

    fout.close();*/

    //OpenFile();


   

    string path = "TestFile12.txt";
    fstream fs;
    fs.open(path,fstream::in | fstream::out | fstream::app);
    
    if (!fs.is_open()) {
        cout << "Eror!";
    }

    else {

        string msg;
        int value;
        cout << "File is open \n";
        cout << "========================================================================" << endl;
        cout << "Enter the number 1 for write text to file or 2 our text from file: ";
        cin >> value;
        cout << "Enter the text: ";

        if (value == 1) {

            for (int i = 0; i < 2; i++)
            {
                    cin >> msg;

                    for (int i = 1; i < msg.length(); i++)
                    {
                        if (msg[i] == ' ') {
                            msg.erase(i--, 1);
                        }
                        
                        if (ispunct(msg[i])) {
                            msg.erase(i++, 1);
                        }

                        if (ispunct(msg[i])) {
                            msg.erase(i++, 1);
                        }

                        if ('a' <= msg[i] && msg[i] <= 'z') {
                            msg[i] = char(((int) msg[i]) - 32);
                        }

                        if ('A' <= msg[i] && msg[i] <= 'Z') {
                            msg[i] = char(((int) msg[i]) + 32);
                        }

                        for (int i = 1; i < msg.length(); i++)
                        {
                            for (int j = 0; j < msg.length(); j++)
                            {
                                if ((msg[i], msg[j]) > 0) {

                                    int tmp = msg[i];
                                    msg[i] = msg[j];
                                    msg[j] = tmp;
                                }
                            }
                        }

                        
                    }

                    fs << msg << " ";
            }
            
        }

        if (value == 2) {

            cout << "Reading data from a file";
            while (!fs.eof()) {
                msg = "";
                fs >> msg;
                cout << msg << " "; 
            }
            
        }
    }

    fs.close();

    system("pause");
}


