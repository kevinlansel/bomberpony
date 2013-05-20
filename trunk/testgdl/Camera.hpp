////////////////////////////////////////////////////////////////////////////////
/// Declaration de la classe Camera
////////////////////////////////////////////////////////////////////////////////
#include <GL/glu.h>
#include <GL/glut.h>

 # include "GameClock.hpp"
 # include "Input.hpp"
 # include "Vector3f.hpp"

 class Camera
 {
 public:
   Camera(void);
   void initialize(void);
   void update(gdl::GameClock const &, gdl::Input &);
 private:
   Vector3f position_;
   Vector3f rotation_;
 };
