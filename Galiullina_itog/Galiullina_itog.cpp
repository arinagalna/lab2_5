#include <iostream>
#include <vector>
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

void prov_name() {

}

int test_int() {
    string k;
    bool n;

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
    if ()


    

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
    float pipe_lenght;
    int pipe_diametr;
    bool pipe_condition;
    cout << "Enter pipe name:";
    cin >> pipe_name;
    cout << "Enter pipe lenght:";
    cin >> pipe_lenght;
    cout << "Enter pipe diametr";
    cin >> pipe_diametr;
    cout << "Enter pipe condition. If the pipe is working, please print 1, else, please print 0.";
    cin >> pipe_condition;

    p.name = pipe_name;
    p.lenght = pipe_lenght;
    p.diametr = pipe_diametr;
    p.condition = pipe_condition;

    return p;
}

//Создание функции для создания кс
Compressor_station compressor_ctation_create(Compressor_station& cs) {
    

    string cs_name;
    int cs_workshop;
    int cs_work_workshop, n;
    double cs_eff;
    cout << "Enter cs name:";
    cin >> cs_name;
    cout << "Enter num compressor station workshop:";
    cin >> cs_workshop;
    cout << "Enter num of working compressor station workshop:";
    cin >> n;
    while (n > cs_workshop) {
        cout << "Please change num work workshop";
        cin >> n;
    }
    cs_work_workshop = n;
    cout << "Enter compressor performance indicator:";
    cin >> cs_eff;

    cs.name = cs_name;
    cs.number_workshop = cs_workshop;
    cs.number_working_workshop = cs_work_workshop;
    cs.effectiv = cs_eff;
    return cs;
}

void Show(Pipe p, Compressor_station cs)
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
    bool k;
    cout << "Change. if yes print 1, else 0";
    cin >> k;
    // проверка того что воодит
    if (k == true) {
        p.condition = not(p.condition);
    }
}

void cs_change(Compressor_station& cs) {
    int n, nw;
    string ans;
    n = cs.number_workshop;
    nw = cs.number_working_workshop;
    cout << "if need add workshop print add, else print del";
    cin >> ans;
    if (ans == "add"){
        if (nw = n) {
            cout << "you cant add work workshop. All is worring now";
            cin >> ans;
        }
        else {
            cs.number_working_workshop += cs.number_working_workshop;
        }
    }
}

int main()
{
    Pipe p;
    Compressor_station cs;

    //vector<Pipe> all_pipes;
    //vector<Compressor_station> all_cs;
    int vvod;
    int pipe_id = 0;
    int cs_id = 0;


    while (1) {
        menu();
        cout << "Enter command number";
        cin >> vvod;
        switch (vvod){
        case 1:
            //all_pipes.resize(pipe_id + 1);
            //all_pipes[pipe_id] = pipe_create();
            //pipe_id++;
            pipe_create(p);
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
            break;
        case 7:
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

