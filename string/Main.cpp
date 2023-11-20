#include "String.h"

#define DEBUG 1

int main(int argc, char** argv)
{
	String s1 = String("Hello");
	String s2 = String(" World");
	String s3 = s1 + s2;
	String s4 = String(0);
	String s5 = s3;
	String s6 = s1;
	s6 = s6;
	s6 = s2;


#if DEBUG
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;
	std::cout << s4 << std::endl;
	std::cout << s5 << std::endl;
	std::cout << (s1 < s3) << std::endl;
	std::cout << (s1 > s3) << std::endl;
	std::cout << (s1 == s3) << std::endl;
	std::cout << (s1 != s3) << std::endl;
#endif //DEBUG

	return 0;
}