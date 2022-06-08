
#ifndef DATA_H_
#define DATA_H_
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

namespace data {
std::vector<std::string> getHeaderText(char spacer,std::string filename);
std::vector<std::string> getBodyText(char spacer,std::string filename);
}


#endif /* DATA_H_ */

