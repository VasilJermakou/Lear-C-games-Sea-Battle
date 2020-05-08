// main.cpp This file contains a game "Sea Battle"


#include <iostream>

//PROTOTYPES OF FUNCTIONS
void display_map(int map[][5], const int size);
void map_init(int map[][5], const int size);
void map_clear(int map[][5], const int size);

int main()
{
    
    const int SIZE = 5;

    int sea_map[SIZE][SIZE] = { 0 };
    int map[SIZE][SIZE] = { 0 };

    int counter = 0;
    bool game = true;
    bool incorrect_value = true;
    int trys = 0;
    int record = 0;
    char status = 'y';
    int x = 0;
    int y = 0;
  

    display_map(sea_map, SIZE);
    std::cout << std::endl;
    map_init(sea_map, SIZE);
    std::cout << std::endl;

    do
    {
        std::cout << "\n***********************************************************************\n";
        std::cout << "\n\tThis is a Sea Battle Game!!!" << std::endl;
        std::cout << "\nBattle AREA consists of 5 rows and 5 columns.";
        std::cout << "\nROW numeration goes from top to bottom.";
        std::cout << "\nCOLUMN numeration goes from left to right.";
        std::cout << "\nAll points on battle field are marked as 0.";
        std::cout << "\nThere are 5 enemy ships on the battle field.";
        std::cout << "\nIf you make a shot and missed, this point will change from 0 to 8.";
        std::cout << "\nIf you make a shot and hit the ship, point will change from 0 to 1." << std::endl;
        std::cout << "\n\t---===Good luck!!!===---" << std::endl;
        std::cout << "\n***********************************************************************\n";

        while (game)
        {
            //check input data x
            while (incorrect_value)
            {
                std::cout << "Enter ROW(x) coordinate (from 0 to 4): ";
                std::cin >> x;
                std::cin.ignore(5, '\n');
                
                if (std::cin.good())
                {
                    if (x >= 0 && x < 5)
                        incorrect_value = false;
                    else
                        std::cout << "\nYou entered incorrect value(enter numbers from 0 to 4)." << std::endl;
                }
                else
                {
                    std::cout << "\nYou entered incorrect value(enter numbers from 0 to 4)." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(5, '\n');
                }
            }

            incorrect_value = true;

            //check input data y
            while (incorrect_value)
            {
                std::cout << "Enter COLUMN(y) coordinate (from 0 to 4): ";
                std::cin >> y;
                std::cin.ignore(5, '\n');

                if (std::cin.good())
                {
                    if (y >= 0 && y < 5)
                        incorrect_value = false;
                    else
                        std::cout << "\nYou entered incorrect value(enter numbers from 0 to 4)" << std::endl;
                }
                else
                {
                    std::cout << "\nYou entered incorrect value(enter numbers from 0 to 4)" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(5, '\n');
                }
            }

            incorrect_value = true;
        
            if (sea_map[x][y] == 1)
            {
                std::cout << "\nYou hit the ship!!!" << std::endl;
                sea_map[x][y] = 0;
                counter++;
                trys++;
                map[x][y] = 1;
            }
            else
            {
                std::cout << "\nYou missed :( \n" << std::endl;
                trys++;
                map[x][y] = 8;
            }

            if (counter == 5)
            {
                std::cout << "\nCongratulations, You have won the game!!!" << std::endl;
                game = false;
            }

            display_map(map, SIZE);
            std::cout << std::endl;
        }

        //set best result
        if (record < trys)
        {
            record = trys;
        }

        std::cout << "\n***********************************************************************\n";
        std::cout << "\nTotal number of attempts: " << trys << std::endl;
        std::cout << "\nBest result: " << record << std::endl;
        std::cout << "\n***********************************************************************\n";

        std::cout << "\nWould you like to play one more time(y or n)?: ";
        std::cin >> status;

        //reload all variables
        game = true;
        counter = 0;
        trys = 0;
        map_clear(map, SIZE);
        map_init(sea_map, SIZE);

    } while (status == 'y' || status == 'Y');
    
    std::cout << "\n***********************************************************************\n";
    std::cout << "\n\t---===END OF THE GAME===---";
    std::cout << "\n***********************************************************************\n";

    

   
    return 0;
}


//*************************************************
//DEFINITION OF FUNCTIONS
//*************************************************

void display_map(int map[][5], const int size)
{
    for (int i = 0; i != size; ++i)
    {
        for (int j = 0; j != size; ++j)
        {
            std::cout << *(*(map + i) + j) << " ";
        }
        std::cout << std::endl;
    }
    return;
}

void map_init(int map[][5], const int size)
{
    int x = 0;
    int y = 0;
    
    for (int i = 0; i != size; ++i)
    {
        x = rand() % 5;
        y = rand() % 5;
        
        for (int j = 0; j != size; ++j)
        {
            map[x][y] = 1;
        }
    }

    return;
}

void map_clear(int map[][5], const int size)
{
    for (int i = 0; i != size; ++i)
        for (int j = 0; j != size; ++j)
            *(*(map + i) + j) = 0;
            
    return;
}

