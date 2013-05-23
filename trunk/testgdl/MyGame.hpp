////////////////////////////////////////////////////////////////////////////////
/// Declaration de la classe MyGame
////////////////////////////////////////////////////////////////////////////////


#include <list>
#include "Camera.hpp"
#include "AObject.hpp"
#include "Forme.hpp"
#include "Game.hpp"
#include "Model.hpp"
#include "Bombe.hpp"
#include "Explosion.hpp"

class MyGame : public gdl::Game
{
public:
  void initialize(void);
  void update(void);
  void draw(void);
  void unload(void);

private:
  Camera		camera_;
  std::list<AObject*>	objects_;
  Bombe			*_bombe;
  Explosion		*_explosion;
  Vector3f		_translation;
};
