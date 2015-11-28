#ifndef SCRIPTEXTENDER
#define SCRIPTEXTENDER

class QString;
class QStringList;

class ScriptExtender {

public:

  virtual ~ScriptExtender() {}

  virtual QString name() const = 0;

  virtual QString loaderName() const = 0;

  virtual QStringList saveGameAttachmentExtensions() const = 0;

};

#endif // SCRIPTEXTENDER

