#include "CommonHeader.h"
#include <vector>
#include <sstream>
#include <unordered_map>
#include <string>
#include <algorithm>
// # 1 Tokenized String "Hello,world,this,Is,A,teSt", with token ,
// # 2 "ThIs iS mY HomE, I loVe it"-->"This is My Home, I love it"// do not change "is","and", "it"
// # 3 "aich@gmail.com  aich@calsoft.com, aich@niva.com iaich@gmail.com", find the domain name count
// # 4 {[()()]}
// # 5  a a b c d d find the count

void validateBrackets_(const std::string& str)
{
	std::cout << "\tFunction name" << __FUNCTION__ << std::endl ;
	std::vector<char>brackets;
	for (auto& tmp : str)
	{
		if ((tmp == '{') || (tmp == '[') || (tmp == '('))
		{
			brackets.push_back(tmp);
		}
		else if(((tmp == '}') && (brackets.back() == '{')) 
			|| ((tmp == ']') && (brackets.back() == '['))
			|| ((tmp == ')') && (brackets.back() == '(')))
		{
			brackets.pop_back();
		}
	}
	if (brackets.empty())
	{
		std::cout << "\t brackets are valid" << std::endl;
	}
}


void tokenizedStr_(const std::string& str)
{
	std::string token;
	std::vector<std::string>tokens;
	std::stringstream ss(str);
	std::cout << "\tFunction name" << __FUNCTION__ << std::endl << "\t";
	while (ss >> token)
	{
		std::transform(token.begin(), token.end(), token.begin(), ::tolower);
		if (token != "is" && token != "and" && token != "it")
		{
			token[0] = std::toupper(token[0]);
		}

		tokens.push_back(token);

	}
	for (auto& tmp : tokens)
	{
		std::cout << tmp << " ";
	}

}

void tokenizedStr_(const std::string& str, char deli)
{
	std::string token;
	std::vector<std::string>tokens;
	std::stringstream ss(str);
	std::cout << "\tFunction name" << __FUNCTION__ << std::endl<<"\t";
	while (std::getline(ss, token, deli))
	{
		std::transform(token.begin(), token.end(), token.begin(), ::tolower);
		if (token != "is" && token != "A" && token != "the")
		{

			token[0] = std::toupper(token[0]);
		}

		tokens.push_back(token);
		
	}
	for (auto& tmp : tokens)
	{
		std::cout << tmp << " ";
	}

}

//"aich@gmail.com  aich@calsoft.com aich@niva.com iaich@gmail.com"
void findDomainName_(const std::string & str)
{
	std::cout << "\tFunction name" << __FUNCTION__ << std::endl << "\t";
	std::string token;
	std::vector<std::string>tokens;
	std::stringstream ss(str);
	std::unordered_map<std::string, int> domains;
	int count = 0;
	while (ss>>token)
	{
		tokens.push_back(token);
		
	}
	for (auto& tmp : tokens)
	{
		size_t pos = tmp.find("@");
		if (pos != std::string::npos)
		{
			domains[tmp.substr(pos + 1, tmp.length())]++;
		}
		
	}
	for (auto& tmp : domains)
	{
		std::cout << "\t domain" << tmp.first << " count" << tmp.second;
	}
}
void funcToManipulateString_()
{
	std::cout << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
	/*
	std::string input = "Hello,world,this,is,a,test";
	char delimiter = ',';
	tokenizedStr_(input, delimiter);
	tokenizedStr_("ThIs iS mY HomE, I loVe it");
	validateBrackets_("{ [()()] }");*/
	findDomainName_("aich@gmail.com  aich@calsoft.com aich@niva.com iaich@gmail.com");
}