#include <ctest.h>
#include <limits.h>
#include <libpyatnashki/Utility.h>
#include <libpyatnashki/Field.h>

CTEST(SwapNumbers, positive_case){
    /*
    Check swap functionality
    */
    int first = 0, second = 1;
    Swap(first, second);
    ASSERT_EQUAL(1, first);
    ASSERT_EQUAL(0, second);
}

CTEST(SwapNumbers, min_max_case){
    /*
    Check swap functionality with limits
    */
    int first = INT_MAX, second = INT_MIN;
    Swap(first, second);
    ASSERT_EQUAL(INT_MIN, first);
    ASSERT_EQUAL(INT_MAX, second);
}

CTEST(FieldFunctionality, constructor){
    /*
    Check if we can create field with negative size
    */
    try{
        Field field(-1);
    }catch(const char* message){
        CTEST_LOG("%s", message);
    }
}

CTEST(FieldFunctionality, generation_field){
    /*
    Check if we win on game start
    */
    Field field(5);
    field.GenerateField();
    ASSERT_FALSE(field.CheckWin());
}

CTEST(FieldFunctionality, try_move){
    /*
    Check if invalid direction would work
    */
    Field field(5);
    field.GenerateField();

    try{
        field.TryMove((DIRECTION)10);
    }catch(const char* message){
        CTEST_LOG("%s", message);
    }

}