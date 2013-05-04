Norme de code permettant ainsi à tout le monde de s''y retrouver plus facilement :

- Chaque attribut est préfixé d''un underscore
- Chaque class commence par une majuscule
- Si vous créez une fonction retournant un booléen et que vous pouvez nommer la fonction "is" + quelque chose, le quelque chose commence par une majuscule (isOpen(), isClose())
- Meme règle pour les getters et setters, get + nom_de_l''attribut_avec_une_majuscule (exemple : getList(), setFile())

Exemple d''une classe bien organisée :

class	Toto
{
 public:
   Toto();
   virtual	~Toto();
   //si besoin :
   Toto(const Toto &);
   Toto		&operator=(const Toto &);

 public:
   //getter
   //setter

 public:
   //fonctions membres

 private:
   //attributs
};

- Dans le cas d''une classe abstraite, mettre les attributs en protected peut être pratique.
(Pour rappel, cela permet de garder la notion d''encapsulation, sans pour autant avoir besoin de passer par des getters et setters dans les classes filles).

- Si possible (et c''est préférable) avant chaque fonction (hormis getter, setter, constructeur, etc), mettez ceci :

/*
** Description
** A quoi équilavent les arguments
** Valeur de retour
*/

exemple :

/*
** Open a file and return its ifstream
** string str = filename
** return the ifstream of the file open
*/

ifstream	OpenFile(const string str)
{
  ifstream	file(str.c_str());
  return (file);
}
