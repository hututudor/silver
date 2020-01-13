#pragma once

class GameObject {
public:
  GameObject();
  ~GameObject();

  virtual void onStart();
  virtual void onUpdate();
  virtual void onRender();
  virtual void onDestroy();
};
