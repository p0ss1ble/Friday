#include <iostream>
#include <vector>
#include <cstring>

class Player
{
public:
    const char* name_ = NULL;
    size_t score_ = 0;

    Player(const char* str):
        name_(str)
    {}

    char get_letter()
    {
        char letter;
        std::cin >> letter;
        return letter;
    }

    void increase_score()
    {
        score_++;
    }
};

class Game
{
public:
    const char* word_ = NULL;
    std::vector<Player*>game_players_;
    Game(const char* str):
        word_(str)
    {}
    void append_player(Player* player)
    {
        game_players_.push_back(player);
        std::cout << "added player " << (*player).name_ << std::endl;
    }
    void start_game()
    {
        char* a = new char[strlen(word_) + 1];
        a[strlen(word_)] = '\0';

        for ( int i = 0; i < strlen(word_); i++ ){
            a[i]='.';
        }
        
        std::cout << word_ << '\n' << std::endl;
        std::cout << a << '\n' << std::endl;
        
        char letter;
        size_t num_of_players = game_players_.size();

        for (size_t i = 0; i < num_of_players;)
        {
            if(strcmp(word_, a) == 0)
            {
                break;
            }

            //while (getchar() != '\n');

            Player* player = game_players_[i];
            std::cout << (*player).name_ <<" Введите букву:" << "\n";
            letter = (*player).get_letter();
            bool found = false;
            for( int j = 0; j < strlen(word_); j++ )
            {
                if( word_[j] == letter )
                {
                    a[j] = word_[j];
                    player->increase_score();
                    found = true;
                }
            }
            if (!found)
            {
                i = (i + 1) % num_of_players;
            }
            std::cout << "current word: " << a << '\n';
        }
        std::cout << "\n" << "Вы угадали слово!" << std::endl;

        size_t max_score = 0;
        size_t index = 0;
        for (size_t i = 0; i < num_of_players; i++)
        {
            Player* player = game_players_[i];
            if ((*player).score_ > max_score)
            {
                index = i;
                max_score = (*player).score_;
            }
        }
        std::cout << "\n" << "Победитель " << game_players_[index]->name_ << std::endl;
    }
};

int main()
{
    Player player1("Player1");
    Player player2("Player2");
    char str[100] = "";
    std::cout << "Введите слово:" << std::endl; 
    std::cin  >> str;
    std::cout << str << std::endl;
    Game game(str);
    game.append_player(&player1);
    game.append_player(&player2);
    game.start_game();
}


