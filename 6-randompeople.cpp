#include <iostream>
#include <cstring>
#include <wchar.h>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <time.h>

using namespace std;

int main(){

char name[100] = "";

string music[14] = {"Master of puppets Metallica", "Брошу Pyrokinesis", "Homebody PH1","Червяк Даргомыжский","Russian Ebunny","Enemy Imagine dragons"," Зизазай Огги и тараканы","Valentine Justice","Swimming pools Kendrick Lamar","Night Call Kovinsky","Yesterday The Beatles","Так закалялась сталь Гражданская оборона","За деньги да Инстасамка","Bad habits Ed sheeran"};
string movies[14] = {"Короткое замыкание", "Трансформеры", "Полночь", "По соображениям совести","Джентльмены","Ван Хельсинк","Операция Ы","Драйв","Большая игра","Игра в имитацию","Всё везде и сразу","Форрест Гамп","Терминал","Не смотрите наверх"};
string actors[14] = {"Райан Гослинг", "Кристиан Бейл", "Джеки Чан","Эндрю Гарфилд","Леонардо ДиКаприо","Бенедикт Кембербетч","Мэтью Макконахи","Дэвид Линч","Дэниэлл Рэдклифф","Джейк Джиллехолл","Александр Петров","Рональд Рейган","Том Круз","Брэд Питт"};
string actriss[14] = {"Наталия Крачковская", "Меган Фокс", "Джениффер Лопез","Эмма Стоун","Эмма Уотсон","Кира Найтли","Милла Йовович","Марго Робби","Мерил Стрип","Скарлет Йоханссон","Александра Бортич","Анджелина Джоли","Шарлиз Терон","Ингеборга Дапкунайте"};
string seleb[14] = {"Дейв Майнстейн", "Иван Зола", "Сергей Мавроди", "Екатерина Гордеева", "Роберт Опенгеймер", "Лионель Месси", "Папич", "Хидэо Кодзима", "Ляйсан Утяшева","Павел Воля","Криштиану Роналду","Борис Бурда","Ким Кардашьян","Клава Кока"};

cout << "Введите имя:" << endl;
cin >> name;

char birthday[10] = "";
char a[10] = "";

cout << "Введите дату рождения:" << endl;
cin >> birthday;

for ( int i = 0; i < 10 ; i++ ){
        a[i]='.';
} //маску >> побитовый сдвиг вправо 


int s = 0;
int Sum = 0;
int arr[3] = {0, 11111111, 22222222};
srand(time(NULL));


for( int i = 0; i < 10; i++){
    if(birthday[i] && birthday[i] != '\n'){
        if( birthday[i] >= '0' && birthday[i] <= '9')
            s += birthday[i] - '0';
    }
}

char* day = strtok(birthday, ".");
    char* month = strtok(nullptr, ".");
    char* year = strtok(nullptr, ".");
    
    int monthInt = atoi(month);

Sum = pow(s, monthInt) + arr[rand() % 3];


//Sum += pow(s, 10 * birthday[3] + 1 * birthday[4] + arr[rand() % 3]));

cout << s << "\n";
cout << Sum << endl;
cout << "Здравствуйте!:  " << name << endl;

cout << "Ваша песня сегодня:\n" << music[ Sum&15 ] << endl;
cout << "Ваша фильм сегодня:\n" << movies[ (Sum>>4)&15 ] << endl;
cout << "Ваша актер сегодня:\n" << actors[ (Sum>>8)&15 ] << endl;
cout << "Ваша актриса сегодня:\n" << actriss[ (Sum>>12)&15 ] << endl;
cout << "Ваша знаменитость сегодня:\n" << seleb[ (Sum>>16)&15 ] << "\n";
cout << "Хорошего дня!" << "\n" << name << "\n";

return 0;

}