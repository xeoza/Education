#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <regex>

using namespace std;

void lower(string &value) {
    bool flag = false;

    for (auto &it: value) {
        if (flag) {
            flag = false;
            continue;
        }

        if (it >= 0) {
            if (it >= 'A' and it <= 'Z')
                it += -'A' + 'a';
            continue;
        }
        
        if (it >= "А"[0] and it <= "П"[0] and *(&it+1) >= "А"[1] and *(&it+1) <= "П"[1]) {
            it = it - "А"[0] + "а"[0];
            *(&it+1) = *(&it+1) - "А"[1] + "а"[1];
            
        } else if (it >= "Р"[0] and it <= "Я"[0] and *(&it+1) >= "Р"[1] and *(&it+1) <= "Я"[1]) {
            it = it - "Р"[0] + "р"[0];
            *(&it+1) = *(&it+1) - "Р"[1] + "р"[1];
        }

        flag = true;
    }
}

int main()
{   
    while (true)
    {
        map<string, vector<int>> dictionary;
        string s;
        cout << "Введите строку состоящую из слов и нажмите Enter: " << endl;
        getline(cin, s);
        cout << endl << "Результат работы программы: " << endl;
        regex re ("[a-zабвгдеёжзийклмнопрстуфхцчшщъыьэюя]+");
        lower(s);
        regex_iterator<string::iterator> reIt ( s.begin(), s.end(), re);
        regex_iterator<string::iterator> reEnd;
        
        while (reIt != reEnd)
        {
            dictionary[reIt->str()].push_back(reIt->position(0));
            ++reIt;
        }

        for (auto &value : dictionary)
        {
            cout << value.first << ' ' << value.second.size() << endl;
        }
        cout << "______________________________" << endl;
    }
    return 0;
}
