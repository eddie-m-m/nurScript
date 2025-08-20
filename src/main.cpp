#include <vector>
#include <string>
#include <print>
#include <cstdlib>
#include <filesystem>
#include <cstddef>
#include <iterator>
#include <fstream>
#include <sstream>

namespace { 

	void run_file(std::string path) {

		std::ifstream file(path);

		std::stringstream buffer;
		buffer << file.rdbuf();
		

		run(buffer.str());
	}


	void run_prompt(){};
}


int main(int argc, char* argv[]) {
	std::vector<std::string> args{};
        
	for (auto i = 0; i < argc; ++i) {
		args.push_back(argv[i]);
	}

	if (args.size() > 1) {
		std::print("Usage: nurScript [script].ns");
		std::exit(64);

	} else if (args.size() == 1) {
		run_file(args.at(0));
	} else {
		run_prompt();
	}

}
