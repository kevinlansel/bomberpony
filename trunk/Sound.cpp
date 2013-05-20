//
// Sound.cpp for bomberpony in /home/peelou/SVN/bomberpony
// 
// Made by gery baudry
// Login   <baudry_g@epitech.net>
// 
// Started on  Mon May 20 15:33:40 2013 gery baudry
// Last update Mon May 20 16:52:34 2013 gery baudry
//

#include	"Sound.hpp"
#include	<pthread.h>

Sound::Sound()
{
  if (!this->_menusound.LoadFromFile("./ressource/fart.wav"))
    std::cout << "Erreur chargement fichier audio" << std::endl;
}

Sound::~Sound()
{
}

void			*Sound::PlaySound(void *)
{
  sf::Sound		sound;

  sound.SetBuffer(this->_menusound);
  sound.Play();
  while (sound.GetStatus() == sf::Sound::Playing)
    sf::Sleep(0.1f);
  return (NULL);
}

void			Sound::create_thread()
{
  pthread_t		thread;
  pthread_mutex_t	mutex;

  pthread_mutex_init(mutex, NULL);
  pthread_join(thread, NULL);
  pthread_mutex_lock(mutex);
  pthread_create(thread, NULL, PlaySound, thread);
}

sf::SoundBuffer		Sound::getSound()
{
  return (this->_menusound);
}

void			Sound::setSound(std::string &sound)
{
  if (this->_menusound.LoadFromFile(sound))
    std::cout << "Erreur chargement fichier audio" << std::endl;
}
