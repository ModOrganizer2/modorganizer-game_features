#ifndef SCRIPTEXTENDER
#define SCRIPTEXTENDER

#include <QString>

class ScriptExtender {

public:

  virtual ~ScriptExtender() {}

  virtual QString name() const = 0;

};

#endif // SCRIPTEXTENDER

