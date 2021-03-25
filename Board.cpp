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
#include "Board.hpp"
#include <string.h>
using namespace std;
const int num10 = 10;
const int num54 = 54;

    /**
     * setStartAndEndMessagesBoard - set the range for the function show
     * @param: b - the object class
     * @param: row - The row number from which we begin to receive the message
     * @param: column - The column number from which we begin to receive the message
     * @param: msgSize - The size of the Messages
     * @return: none
     */
    void setStartAndEndMessagesBoard(ariel::Board* b , uint row, uint column, uint msgSize){
        //set start row and col to print the messages board
        b->startColumn = min(b->startColumn, column);
        b->startRow = min(b->startRow, row);   
       //set end row and col to print the messages board
        b->endColumn = max(b->endColumn, column);
        b->endRow = max(b->endRow, row);
    }

    /**
     * setStartAndEndMessagesBoard - Receiving a String with spaces for each character
     * @param: maxColums - A number that represents the number of columns
     * @return: result - String with spaces
     */
    std::string getTheSpaceForShow(uint maxColums){
        string result = " ";
        while (maxColums > 0){
            maxColums /= num10;
            result += " ";
        }
        return result;
    }
    /**
     * getSpaceToArrows - Receiving a String with spaces for arrows in the colomn
     * @param: maxColums - A number that represents the number of columns
     * @return: result - String with spaces
     */
    std::string getSpaceToArrows(uint num){
        string str = std::to_string(num);
        string result = " ";
        for (size_t i = 0; i < str.size()/2; i++){
           result += " ";
        }
        return result;
    }

namespace ariel {
    /**
    * post
    * @param: row - The number of row we start adding the message from
    * @param: column - The number of lines we start adding the message from
    * @param: direction - Type of insertion, whether we insert the message horizontally or vertically
    * @param: msg - A string representing the message
    * @return: none
    */
    void Board::post(uint row, uint column, Direction direction, string const &msg) {
        for(char c : msg){
            this->boardMat[row][column].c = c;
            if(direction == Direction::Vertical){
                row++;
            }else{
                column++;
            }
        }
        setStartAndEndMessagesBoard(this, row, column, ((uint)msg.size()));
    }
    /**
    * read - get a Messages as a string from the Messages Board
    * @param: row - The row number from which we begin to receive the message
    * @param: column - The column number from which we begin to receive the message
    * @param: direction - Type of income, whether we receive the message horizontally or vertically from the board
    * @param: length - The length of the string we want to get
    * @return: result - A string representing the message on the bulletin board
    */
    string Board::read(uint row, uint column, Direction direction, uint length) {
        string result;
        for(uint i = 0; i < length; ++i){
            result += this->boardMat[row][column].c;
            if(direction == Direction::Vertical){
                row++;
            }else{
                column++;
            }
        }
        return result;
    }
    /**
    * show - print all the Messages Board with number of row and column
    * @param: none
    * @return: none
    */
    void Board::show() {
        uint indexRow = this->startRow;
        uint maxRow = this->endRow;
        uint indexColumn = this->startColumn;
        uint maxColumn = this->endColumn;
        std::string spaceForNum = getSpaceToArrows(maxColumn);
        std::string maxSpaceForNum = getTheSpaceForShow(maxColumn);
        if(maxColumn > num54){
            for (uint row = indexRow; row < maxRow; row++) {
                for (uint col = indexColumn; col < maxColumn; col++) {
                    cout << this->boardMat[row][col].c << " ";
                }
                cout << "← " << row << "\n";
            }
        }else{
            for (uint col = indexColumn; col < maxColumn; col++) {
                cout << col << spaceForNum;
            }
            cout << "\n";
            for (uint col = indexColumn; col < maxColumn; col++) {
                cout << "↓" << maxSpaceForNum;
            }
            cout << "\n\n";
            for (uint row = indexRow; row < maxRow; row++) {
                for (uint col = indexColumn; col < maxColumn; col++) {
                    cout << this->boardMat[row][col].c << maxSpaceForNum;
                }
                cout << "← " << row << "\n";
            }
        }
    }
}