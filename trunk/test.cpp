//
// test.cpp for  in /home/lund/Projets/bomberpony
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Sat May 11 22:05:06 2013 florian dewulf
// Last update Sat May 11 22:08:54 2013 florian dewulf
//

#include	<iostream>
#include	"File.hpp"

int	main()
{
  std::list<std::string>	list;
  File				toto;

  std::cout << toto.getStatemap() << std::endl;
  list.push_back("toto");
  list.push_back("toti");
  toto.putFile("./map/test.map", list);
  toto.putFile(".score", list);
  list = toto.getFileContent();
  for (std::list<std::string>::iterator it = list.begin() ; it != list.end() ; ++it)
    std::cout << "=> " << *it << std::endl;
  std::cout << "====" << std::endl;
  list = toto.ls();
  for (std::list<std::string>::iterator it = list.begin() ; it != list.end() ; ++it)
    std::cout << "=> " << *it << std::endl;
}
