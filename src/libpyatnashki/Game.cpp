#include <libpyatnashki/Game.h>

void Game(){
    
    std::string startMessage = "Hello, and Welcome to the Game!\nLet the game Start!\n";
    for(int i = 0; i < startMessage.size(); i++){
        std::cout << startMessage[i];
        Sleep(33);
    }
    system("CLS");

    int size;
    
    std::cout << "Write number from 3 to 6: ";
    std::cin >> size;

    Field field(size);
    field.GenerateField();
    field.ShowField();

    while(true){
        char input;
        input = std::getchar();
        std::cout << "char " + input;
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
        system("CLS");
        field.ShowField();
        if(field.CheckWin()){
            break;
        }
    }

    std::cout << "Congratulations! You win!\n";
    system("pause");
}