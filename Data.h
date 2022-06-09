
#ifndef DATA_H_
#define DATA_H_
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

namespace data {
std::vector<std::string> getHeaderText(char spacer,std::string filename);
std::vector<std::string> getBodyText(char spacer,std::string filename);
std::vector<std::string> get(char spacer,std::string filename);
std::vector<std::string> getTextData(std::string filename, std::string spacer,std::vector<std::string> search);
}


#endif /* DATA_H_ */

