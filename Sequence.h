#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <string>
using namespace std;
class Sequence
{
        public:
                Sequence(string);
                int length();
                int numberOf(char);
                string longestConsecutive();

                string longestRepeated();
                
        private:
                string DNA;
};

#endif
