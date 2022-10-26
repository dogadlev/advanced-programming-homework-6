#include <iostream>
#include <string>
#include <map>

//Функция читает символы строки-текста и подсчитывает сколько раз символ встречается в тексте.
//Пары символ-количество (key-value) помещаются в std::map.
void count(const std::string &in, std::map<char, int> &out)
{
    for (const auto &el : in)
    {
        //insert() возвращает пару итератор-bool значение.
        //Если вставка успешна, bool значение - true.
        //Итератор указывает на новый, вставленный элемент.
        //Если вставка не успешна (в out уже есть такой key), итератор указывает на элемент, где случился конфликт.
        const auto itr = out.insert({el, 1});
        if (!itr.second)
        {
            //Увеличиваем значение на 1.
            ++itr.first->second;
        }
    }
}

//Функция выводит в консоль элементы хранящиеся в input.
//Вывод прозводится, начиная с наибольшего key.
void printRes (const std::multimap<int, char> &input)
{
    std::cout << "[OUT]:" << std::endl;
    for (auto itr = input.crbegin(); itr != input.crend(); ++itr)
        std::cout << itr->second << ": " << itr->first << std::endl;
}

//Функция вставляет пары ключ-значение в std::multimap.
//Изначальные пары ключ-значения "отзеркаливаются".
//При вставке в std::multimap происходит автоматическая сортировка.
void changeKeyValue(const std::map<char, int> &input, std::multimap<int, char> &output)
{
    for (const auto &el : input)
        output.insert({el.second, el.first});
}

int main(int argc, char **argv)
{
    std::string text{"Hello world!!"};
    std::cout << "[IN]: " << text << std::endl;

    std::map<char, int> inHW{};
    count(text, inHW);

    std::multimap<int, char> outHW;
    changeKeyValue(inHW, outHW);

    printRes(outHW);

    return 0;
}