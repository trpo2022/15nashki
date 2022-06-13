#include <libpyatnashki/Field.h>

Field::Field(int size){
    if(size < 0){
        throw "Size couldnt be negative";
    }
    this->size = size;
    field = new int*[size];
    for(int i = 0; i < size; i++){
        field[i] = new int[size];
    }
}

Field::~Field(){
    for(int i = 0; i < size; i++){
        delete[] field[i];
    }
    delete[] field;
}

bool Field::CheckWin(){
    
    for(int i = 0; i < size; i++){
        
        for(int j = 0; j < size; j++){

            if(field[i][j] != (1 + j + i * size)){
                if((i == size - 1) && (j == size - 1)){
                    return true;
                }
                return false;
            }
            
        }

    }
    return true;
}

void Field::TryMove(DIRECTION dir){
    if(int(dir) < 0 || int(dir) > 3){
        throw "Not valid direction";
    }
    switch (dir)
    {
    case UP:
        if(null_i != 0){
            Swap(field[null_i][null_j], field[null_i - 1][null_j]);
            null_i -= 1;
        }
        break;
    case DOWN:
        if(null_i != size - 1){
            Swap(field[null_i][null_j], field[null_i + 1][null_j]);
            null_i += 1;
        }
        break;
    case LEFT:
        if(null_j != 0){
            Swap(field[null_i][null_j], field[null_i][null_j - 1]);
            null_j -= 1;
        }
        break;
    case RIGHT:
        if(null_j != size - 1){
            Swap(field[null_i][null_j], field[null_i][null_j + 1]);
            null_j += 1;
        }
        break;
    
    default:
        break;
    }
}

void Field::ShowField(){
    
    std::cout << "+";
    for(int i = 0; i < size; i++){
        std::cout << std::setw(size) << std::setfill('-') << "+";
    }
    std::cout << '\n';
    
    for(int i = 0; i < size; i++){
        std::cout << "|";
        for(int j = 0; j < size; j++){
            std::cout << std::setw(size) << std::setfill(' ') << std::to_string(field[i][j]) + "|";
        }
        std::cout << '\n';
        
        std::cout << "+";
        for(int j = 0; j < size; j++){
            std::cout << std::setw(size) << std::setfill('-') << "+";
        }
        std::cout << '\n';
    }
}

void Field::GenerateField(){
    
    std::srand(time(0));

    for(int i = 0; i < size; i++){
        
        for(int j = 0; j < size; j++){
            
            if((i != size - 1) || (j != size - 1)){
                field[i][j] = 1 + j + i * size;
            }else{
                field[i][j] = 0;
                null_i = i;
                null_j = j;
            }

        }
    }

    for(int i = 0; i < 1500; i++){
        TryMove(DIRECTION(std::rand() % 4));
    }

}