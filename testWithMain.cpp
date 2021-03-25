/**
  * Messages Board
  * Create a Messages Board 
  * CPP course, Ariel University
  * For more documentation visit: 
  * https://github.com/cpp-exercises/messageboard-a
  * Created by: Moti Dahari
  * https://github.com/motidahari
  */

#include <iostream>
#include "Board.cpp"
#include <string.h>
using namespace std;

const int maxMsg = 150;
const int maxRows = UINT8_MAX;
const int maxColums = UINT8_MAX;
/**
 * getMsgWithSizeAndVal - Receive a message with a certain character and size
 * @param: size - Message size
 * @param: c - The character we want to insert into the message
 * @return: msg - A string that represents the message in the size and character requested
 */
string getMsgWithSizeAndVal(uint size,char c){
    string msg;
    for (size_t i = 0; i < size; i++)
        msg += c; 
    return msg;
}
/**
 * getMsgWithSize - Receive a random message with a certain size
 * @param: size - Message size
 * @return: msg - A string that represents the message in the size requested
 */
string getMsgWithSize(uint size){
    string msg;
    for (size_t i = 0; i < size; i++)
        msg += (rand() % 89 + 1) + 33; 
    return msg;
}
/**
 * getMsgWithSizeAndVal - Receive a random message 
 * @param: none
 * @return: msg - A string that represents the random message 
 */
string getRandMsg(){
    string msg;
    for (size_t i = 0; i < rand()%maxMsg; i++)
        msg += (rand() % 89 + 1) + 33; 
    return msg;
}


int main(){

    ariel::Board board, board2,board3;
    std::string msg,msg2,check,result;
    uint row,col;
    ariel::Direction direction;

    cout << "\n\n*********************************** Messages Board 1  ***********************************\n\n";

    row = rand()%maxRows;
    col = rand()%maxColums;
    for (size_t i = 0; i < 50; i++){
        msg = getMsgWithSizeAndVal(20,'a' + i);
        msg2 = getMsgWithSizeAndVal(20,'b'+ i);
        board2.post(i+10,i+10,ariel::Direction::Horizontal,msg);
        board2.post(i+10,i+10,ariel::Direction::Vertical,msg); 
    }
    board2.show();  
    cout << "\n\n\n";


    cout << "\n\n*********************************** Messages Board 2  ***********************************\n\n";
    row = rand()%maxRows;
    col = rand()%maxColums;
    for (size_t i = 0; i < 20; i++){
        msg = getMsgWithSizeAndVal(20,'a' + i);
        msg2 = getMsgWithSizeAndVal(20,'b'+ i);
        board3.post(i+10,i+10,ariel::Direction::Horizontal,msg);
        board3.post(i+10,i+10,ariel::Direction::Vertical,msg); 
    }
    board3.show(); 


    cout << "\n\n\n*********************************** Test for Messages-Board   ***********************************\n";

    int flag = 0;
    cout << "\n\n******************* Test number: 1  ****************\n";
    for (uint i = 0; i < 20; i++){
        row = rand()%maxRows;
        col = rand()%maxColums;
        msg = getMsgWithSizeAndVal(100,'_');
        direction = (rand()%2 == 1)? ariel::Direction::Horizontal : ariel::Direction::Vertical;
        if(board.read(row, col, direction, 100) != msg){
            flag = -1;    
        }
    }
    result = (flag == 0)? "Test number 1 was successful\n" : "Test number 1 failed\n";
    cout << result;
    flag = 0;    



    cout << "\n\n******************* Test number: 2  ****************\n";
    for (uint i = 1; i < 20; i++){
        msg = getMsgWithSize(10);
        board.post(i,i,ariel::Direction::Horizontal,msg);
        msg2 = getMsgWithSize(10);
        check = msg2.substr(0, 1) + msg.substr(1, msg.size());
        board.post(i,i,ariel::Direction::Vertical,msg2);
        board.read(i,i,ariel::Direction::Horizontal,msg.size());
        board.read(i,i,ariel::Direction::Vertical,msg2.size());
        if(check != board.read(i,i,ariel::Direction::Horizontal,msg.size())){
            flag = -1;
        }
    }
    result = (flag == 0)? "Test number 2 was successful\n" : "Test number 2 failed\n";
    cout << result;



    cout << "\n\n******************* Test number: 3  ****************\n";
    for (uint i = 0; i < 20; i++){
        row = rand()%maxRows;
        col = rand()%maxColums;
        direction = (rand()%2 == 1)? ariel::Direction::Horizontal: ariel::Direction::Vertical;
        msg = getRandMsg();
        board.post(row,col,direction,msg);
        if(board.read(row, col, direction, msg.size()) != msg){
            flag = -1;
        }
    } 
    result = (flag == 0)? "Test number 3 was successful\n" : "Test number 3 failed\n";
    cout << result;

    return 0;
}

