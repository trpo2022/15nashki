#include <libpyatnashki/Game.h>

void Game(){
    
    std::string startMessage = "Hello, and Welcome to the Game!\nLet the game Start!\n";
    for(int i = 0; i < int(startMessage.size()); i++){
        std::cout << startMessage[i];
        usleep(33);
    }
    system("clear");

    int size;
    
    do{
        system("clear");
        std::cout << "Write number from 3 to 6: ";
        std::cin >> size;
    }while(size < 3 || size > 6);

    Field field(size);
    field.GenerateField();
    field.ShowField();

    while(true){
        char input;
        input = std::getchar();
        switch (input)
        {
        case 'w':
            field.TryMove(UP);
            break;
        case 'a':
            field.TryMove(LEFT);
            break;
        case 's':
            field.TryMove(DOWN);
            break;
        case 'd':
            field.TryMove(RIGHT);
            break;
        
        default:
            break;
        }
        system("clear");
        field.ShowField();
        if(field.CheckWin()){
            break;
        }
    }
    system("clear");

    std::cout << "Congratulations! You win!\n";
}