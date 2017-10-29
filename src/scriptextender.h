#ifndef SCRIPTEXTENDER
#define SCRIPTEXTENDER

class QString;
class QStringList;

class ScriptExtender {

public:

  virtual ~ScriptExtender() {}

  /** Get the name of the script extender binary */
  virtual QString BinaryName() const = 0;
  
    /** Get the script extender plugin path*/
  virtual QString PluginFolder() const = 0;


  /** The loader to use to ensure the game runs with the script extender */
  virtual QString loaderName() const = 0;

  /** Full path of the loader */
  virtual QString loaderPath() const = 0;

  /** Additional savegame attachments */
  virtual QStringList saveGameAttachmentExtensions() const = 0;

  /** Returns true if the extender is installed */
  virtual bool isInstalled() const = 0;

  /** Get version of extender */
  virtual QString getExtenderVersion() const = 0;


};

#endif // SCRIPTEXTENDER

