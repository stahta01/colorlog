#include <iostream>

namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_YELLOW  	= 33,
        FG_BLUE     = 34,
        FG_WHITE	= 37,
        FG_DEFAULT  = 39,
        BG_YELLOW 	= 43,
        BG_DEFAULT  = 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}

int main(int argc, char** argv)
{
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier yellow(Color::FG_YELLOW);
    Color::Modifier white(Color::FG_WHITE);
    Color::Modifier red(Color::FG_RED);
    Color::Modifier yellowbg(Color::BG_YELLOW);
    Color::Modifier def(Color::FG_DEFAULT);
    Color::Modifier defbg(Color::BG_DEFAULT);

    std::string str;
    while(std::getline(std::cin, str)){
        if(std::cin.eof()){
            exit(EXIT_SUCCESS);
        }

        if(str.find("TRACE") != std::string::npos){
            // default?
        }
        if(str.find("DEBUG") != std::string::npos){
            std::cout << blue;
        }
        if(str.find("INFO") != std::string::npos){
            std::cout << white;
        }
        if(str.find("WARN") != std::string::npos){
            std::cout << yellow;
        }
        if(str.find("ERROR") != std::string::npos){
            std::cout << red;
        }
        if(str.find("FATAL") != std::string::npos){
            std::cout << yellowbg << red;
        }
        std::cout << str << def << defbg << std::endl;
    }
}