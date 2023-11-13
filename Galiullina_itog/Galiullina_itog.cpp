#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>

using namespace std;

//порядковый номер автоматически, айдишник новый

//Создание структур под трубу и кс
struct Pipe
{
    string name;
    float lenght;
    int diametr;
    bool condition;
};

struct Compressor_station
{
    string name;
    int number_workshop;
    int number_working_workshop;
    double effectiv;
};

double test_dob() {
    bool test = 1, test1 = 1;
    string k, itog, itog1, res;
    double resi;
    int sp;

    cin >> k;
    /*
    for (int i = 0; i < k.size(); i++) {
        if (k[i] == '.') {
            sp = i;
            break;
        }
    }
    for (int i = 0; i < k.size(); i++) {
        if (i < sp) {
            itog += k[i];
        }
        if (i > sp) {
            itog1 += k[i];
        }
    }*/
    auto pos = k.find(".");
    if (pos != string::npos) 
    {
        itog = k.substr(0, pos);
        itog1 = k.substr(pos + 1);
    }
    
    for (int i = 0; i < itog.size(); i++)
    {
        cout << test;
        if (isdigit(itog[i]))
        {
            test = 1;
        }
        else {
            test = 0;
            break;
        }
    }
    for (int i = 0; i < itog1.size(); i++)
    {
        if (!isdigit(itog1[i]))
        {
            test1 = 0;
            break;
        }
    }

    if (test == 1 && test1 == 1 && (itog1.size() > 0))
    {
        res = itog + "." + itog1;
        resi = stod(res);
        return resi;
    }
    else {
        std::cout << "please try again";
        test_dob();
    }
    
       
}

/*
int test_int() {
   
    string k;
    bool n;
    int res;


    // флагом, если не число то брейкать если нет то все ок, он пройдет до конца
    // 0 false 1 true
    cin >> k;
    n = 1;
    for (int i = 0; i < k.size(); i++) {
        if (!isdigit(k[i])) {
            n = false;
            break;
        }
    }
    
    if (n == true) {
        res = stoi(k);
        return res;
    }
    else {
        cout << "please try again";
        test_int();
    }
    //return res;
    }
    */
    

int GettCorrectNum(int min, int max) {
    int x;
    do {
        cin.clear();
        cin.ignore(100000, '/n');
        cout << "tupe number (" << min << "-" << max << "):";
        cin >> x;
    } while (cin.fail() || x<min || x>max);
    return x;
}

// Создание функции для вывода меню имеющихся функций
void menu() {
    cout << "Menu" << endl
        << "1) Add pipe " << endl
        << "2) Add compressor station" << endl
        << "3) Show objects" << endl
        << "4) Edit pipe" << endl
        << "5) Edit compressor ctation" << endl
        << "6) Save" << endl
        << "7) Download" << endl
        << "0) Exit" << endl;
    
}

//Создание функции для создания трубы
Pipe pipe_create(Pipe& p) {
    
    string pipe_name;
    double pipe_lenght;
    int pipe_diametr, n;
    //string pipe_diametr;
    int pipe_condition;
    cout << "Enter pipe name:";
   //син иннор . н
    getline(cin, pipe_name);
    getline(cin, pipe_name);
    cout << "Enter pipe lenght:: (valie must be double)";
    pipe_lenght = test_dob();
    cout << "Enter pipe diametr: (valie must be integer)";
    //cin >> pipe_diametr;
   




    //раском
    cin >> pipe_diametr;
    // pipe_diametr = test_int();
    cout << "Enter pipe condition. If the pipe is working, please print 1, else, please print 0.";
   




    //раском
    //n = test_int();
    cin >> n;
    while (n < 0 || n > 1) {
        cout << "please enter 0 or 1";




        //раском
        //n = test_int();
    }
    pipe_condition = n;

    p.name = pipe_name;
    p.lenght = pipe_lenght;
    p.diametr = pipe_diametr;
    p.condition = pipe_condition;

    return p;
}

//Создание функции для создания кс
Compressor_station compressor_ctation_create(Compressor_station& cs) {
    //  провечка что кс не 0 и не отриц, почему-то вылез бесконечный цикл pltase tru again2

    string cs_name;
    //int cs_workshop;
    int cs_workshop;
    int cs_work_workshop, n, n1;
    double cs_eff;
    double num;
    bool f = 0;
    cout << "Enter cs name:";
    getline(cin, cs_name);
    getline(cin, cs_name);
    cout << "Enter num compressor station workshop: (valie must be integer)";
    //cin >> n;";
    //cin >> cs_workshop;

    ///
//
    //раском
    cin >> n;
    //n = test_int();
    while (n <= 1) {
        cout << "Please change num workshop: (valie must be integer)";
        
        cin >> n;
        //
    ///
    /// 
    ///
    /// 
    /// раскоментировать
    //n = test_int();
       
    }
    cs_workshop = n;
    cout << "Enter num of working compressor station workshop: (valie must be integer):";
    //
    ///
    ///
    /// 
    ///
    /// 
    /// раскоментировать
    //n1 = test_int();
    cin >> n1;
    while (n1 > cs_workshop) {
        cout << "Please change num work workshop (valie must be integer)";
        //cin >> n;
        // 
        // 
        // 
        // 
        // 
        // раскоментировать
        //n1 = test_int();
    }
    cs_work_workshop = n1;
    cout << "Enter compressor performance indicator: (valie must be double)";
    //cin >> cs_eff;
    cs_eff = test_dob();
    /*
    if (test_dob(cs_eff)) {
        cout << "Введенное значение соответствует типу double." << std::endl;
        num = stod(cs_eff);
        f = 0;
    }
    else {
        std::cout << "Введенное значение не соответствует типу double." << std::endl;
        f = 1;
        while (f != 0) {
            cin >> cs_eff;
            if (test_dob(cs_eff)) {
                cout << "Введенное значение соответствует типу double." << std::endl;
                num = stod(cs_eff);
                f = 0;
            }
            else {
                std::cout << "Введенное значение не соответствует типу double." << std::endl;
                f = 1;
        }

    }*/
    cs.name = cs_name;
    cs.number_workshop = cs_workshop;
    cs.number_working_workshop = cs_work_workshop;
    cs.effectiv = cs_eff;
    return cs;
}

void save_file(Pipe p, Compressor_station cs)
// ссылку и консе
{
    ofstream out;
    string f_name;
    if (p.name.size() > 0 || cs.name.size() > 0) {
        cout << "Enter file name: ";
        cin >> f_name;
        out.open("save" + f_name + ".txt");
        // проверка что только кс
        if (out.is_open() && (p.name.size() > 0 || cs.name.size() > 0)) {
            out << p.name << endl << p.lenght << endl << p.diametr << endl << p.condition << endl;
            out << cs.name << endl << cs.number_workshop << endl << cs.number_working_workshop << endl << cs.effectiv << endl;
                    
        }
        out.close();
        cout << "File has been saved " << endl;
    }
    else {
        cout << "empty vec" << endl;
    };

};

void read_file(Pipe& p, Compressor_station& cs)
{
    ifstream fin;
    //string path = "saves";
    //vector <filesystem::path> file_names;
    bool test = false;
    //string searshing_file;
    //int load_switch;

    string file_name;
    ifstream file;

    while (true) {
        cout << "Enter file name: ";
        getline(cin, file_name);

        file.open("save" + file_name + ".txt");
        if (file) {
            cout << "file open" <<endl;

            fin.open("save" + file_name+".txt");
            if (fin.is_open()) {
                cout << "start" << endl;
               
               // Pipe p;
                //getline(fin, p.name);
                getline(fin, p.name);
                fin >> p.lenght;
                fin >> p.diametr;
                fin >> p.condition;
                
                
                //Compressor_station cs;
               // getline(fin, cs.name);
                //getline(fin, cs.name);
                fin >> cs.name;
                fin >> cs.number_workshop;
                fin >> cs.number_working_workshop;
                fin >> cs.effectiv;             
               
            }
            else {
                cout << "err" << endl;
            }
            fin.close();
            cout << "File has been imported" << endl;
            break;
        };
    }
    if (!test)
    {
        cout << "try again" << endl;
    }

}


void Show(Pipe p, Compressor_station cs)
// сслылку конс
{
   
    string work;

    if (p.name.empty()) {
        cout << "No pipes" << endl;

    }
    else {
        if (p.condition)
        {
            work = "repairing";
        }
        else {
            work = "working";
        };

        cout << "name: " << p.name << "; lenght: " << p.lenght << "; diametp: " << p.diametr << "; condition: "
            << work << endl;
    }

    if (cs.name.empty()) {
        cout << "No compressor stations" << endl;

    }
    else {
        cout << "name: " << cs.name << "; number workshop: " << cs.number_workshop << "; number working_workshop"
            << cs.number_working_workshop << "; effectiv: " << cs.effectiv << endl;
    }
}

void pipe_change(Pipe& p) {
    if (p.name.empty()) {
        cout << "Please add pipe";
    }
    else {
        bool k;
        cout << "Change. if yes print 1, else 0";
        cin >> k;
        // проверка того что воодит
        if (k == true) {
            p.condition = not(p.condition);
        }
    }
}

void cs_change(Compressor_station& cs) {
    if (cs.name.empty()) {
        cout << "please add sc";
    }
    else {
        int n, nw;
        string ans;
        n = cs.number_workshop;
        nw = cs.number_working_workshop;
        cout << "if need add workshop print add, else print del";
        cin >> ans;
        if (ans == "add") {
            if (nw = n) {
                cout << "you cant add work workshop. All is worring now";
                cin >> ans;
            }
            else {
                cs.number_working_workshop += cs.number_working_workshop;
            }
        }
    }
}

int main()
{
    Pipe p;
    Compressor_station cs;

    //vector<Pipe> all_pipes;
    //vector<Compressor_station> all_cs;
    int vvod, m;
    int pipe_id = 0;
    int cs_id = 0;


    while (1) {
        menu();
        /* Изменение проверок ввода на консоль и в меню
        
        cout << "Enter command number";
        //cin >> vvod;
        vvod = test_int();
        while (vvod < 0 || vvod > 7) {
            cout << "please again";
            m = test_int();
            vvod = m;
        }
        //else {
        */
            switch (GettCorrectNum(0,7)) {
            case 1:
                //all_pipes.resize(pipe_id + 1);
                //all_pipes[pipe_id] = pipe_create();
                //pipe_id++;
                pipe_create(p);
                //ен возвращать трубу, емлт задается
                cout << "Pipe create suscessfully" << endl;
                break;
            case 2:
                compressor_ctation_create(cs);

                //all_cs.resize(cs_id + 1);
                //all_cs[cs_id] = cs_create();
                //cs_id++;
                cout << "Cs create suscessfully" << endl;
                break;
            case 3:
                Show(p, cs);
                break;
            case 4:
                //изменить трубу
                pipe_change(p);
                break;
            case 5:
                //изменить кс
                cs_change(cs);
                break;
            case 6:
                //сохранить
                save_file(p, cs);
                break;
            case 7:
                read_file(p, cs);
                // загрузить
                break;
            case 0:
                // выход
                return 0;
            default:
                cout << "enter correct num" << endl;



            }
        }
    }
//}

