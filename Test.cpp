/**
  * Messages Board Tests
  * Create a Messages Board 
  * CPP course, Ariel University
  * For more documentation visit: 
  * https://github.com/cpp-exercises/messageboard-a
  * Created by: Moti Dahari
  * https://github.com/motidahari
  */
#include "Direction.hpp"
#include "doctest.h"
// #include "Board.hpp"
#include <iostream>
#include <ctime>
#include <stdexcept>
#include <string>

using namespace ariel;
using namespace std;
const int maxMsg = 150;
const int maxRows = UINT8_MAX*10;
const int maxColums = UINT8_MAX*10;



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
    /**
     * Test 1 - Test function for a blank bulletin board
    */
    TEST_CASE("Test 1 -> check empty board"){
        Board board;
        uint row,col;
        std::string msg;
        Direction direction;
        for (uint i = 0; i < 3000; i++){
            row = rand()%maxRows;
            col = rand()%maxColums;
            msg = getMsgWithSizeAndVal(100,'_');
            direction = (rand()%2 == 1)? Direction::Horizontal : Direction::Vertical;
            CHECK(board.read(row, col, direction, 100) == msg);
        }
    }
    /**
     * Test 2 - Function test function Creates messages in the bulletin board, and tests the result with the read function
    */
    TEST_CASE("Test 2 -> create Post and check the result"){
        Board board;
        uint row,col;
        std::string msg;
        Direction direction;
        for (uint i = 0; i < 3000; i++){
            row = rand()%maxRows;
            col = rand()%maxColums;
            direction = (rand()%2 == 1)? Direction::Horizontal:Direction::Vertical;
            msg = getRandMsg();
            board.post(row,col,direction,msg);
            CHECK(board.read(row, col, direction, msg.size()) == msg);
        }
    }
    /**
     * Test 2 - Function test function Creates messages in the bulletin board and overrides them in other messages
     * and tests the result with the read function
    */
    TEST_CASE("Test 3 -> create Post and overiding the first char in the msg"){
        Board board;
        std::string msg,msg2,check;
        for (uint i = 1; i < 3000; i++){
            msg = getMsgWithSize(10);
            msg2 = getMsgWithSize(10);
            check = msg2.substr(0, 1) + msg.substr(1, msg.size());
            board.post(i,i,Direction::Horizontal,msg);
            board.post(i,i,Direction::Vertical,msg2);
            board.read(i,i,Direction::Horizontal,msg.size());
            board.read(i,i,Direction::Vertical,msg2.size());
            CHECK(check == board.read(i,i,Direction::Horizontal,msg.size()));
        } 
    }

