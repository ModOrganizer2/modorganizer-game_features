#ifndef SCRIPTEXTENDER
#define SCRIPTEXTENDER

class QString;
class QStringList;

class ScriptExtender {

public:

  virtual ~ScriptExtender() {}

  virtual QString name() const = 0;

  virtual QString loaderName() const = 0;

  virtual QString loaderPath() const = 0;

  virtual QStringList saveGameAttachmentExtensions() const = 0;

  virtual bool isInstalled() const = 0;

};

#endif // SCRIPTEXTENDER

