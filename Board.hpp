/**
  * Messages Board header
  * Create a Messages Board 
  * CPP course, Ariel University
  * For more documentation visit: 
  * https://github.com/cpp-exercises/messageboard-a
  * Created by: Moti Dahari
  * https://github.com/motidahari
  */

#include <map>
#include "Direction.hpp"
#include <string>
using namespace std;
/**
  * NodeStr - A structure that represents a single character
  * @param: letter - char
  */
struct Char{
    char c = '_';
};
namespace ariel {

    class Board {    
        public:
            map<uint, map<uint, Char>> boardMat;
            uint endRow = 0, endColumn = 0, startColumn = UINT32_MAX, startRow = UINT32_MAX;

            /**
             * post
             * @param: row - The number of row we start adding the message from
             * @param: column - The number of lines we start adding the message from
             * @param: direction - Type of insertion, whether we insert the message horizontally or vertically
             * @param: msg - A string representing the message
             * @return: none
             */

            void post(uint row, uint column, Direction direction, string const &msg);
            /**
             * read - get a Messages as a string from the Messages Board
             * @param: row - The row number from which we begin to receive the message
             * @param: column - The column number from which we begin to receive the message
             * @param: direction - Type of income, whether we receive the message horizontally or vertically from the board
             * @param: length - The length of the string we want to get
             * @return: result - A string representing the message on the bulletin board
             */
            std::string read(uint row, uint column, Direction direction, uint length);
            /**
             * show - print all the Messages Board with number of row
             * @param: none
             * @return: none
             */
            void show();
    };
}
