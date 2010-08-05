#include "stdafx.h"

#include "npfunctions.h"
#include "pluginbase.h"
#include "pluginfactory.h"
#include "log.h"

CPluginFactory g_PluginFactory;
extern CLog gLog;

#ifdef XP_UNIX
char* NPP_GetMIMEDescription() {
  return "";
}
#endif

NPError NP_LOADDS NPP_Initialize() {
  return NPERR_NO_ERROR;
}

void NP_LOADDS NPP_Shutdown() {

}

NPError NP_LOADDS NPP_New(NPMIMEType pluginType, NPP instance,
                          uint16_t mode, int16_t argc, char* argn[],
                          char* argv[], NPSavedData* saved) {
  CPluginBase* pPlugin = g_PluginFactory.NewPlugin(pluginType);
  if (pPlugin == NULL)
    return NPERR_OUT_OF_MEMORY_ERROR;
  else
    return pPlugin->Init(instance,mode,argc,argn,argv,saved);
}

NPError NP_LOADDS NPP_Destroy(NPP instance, NPSavedData** save) {
  CPluginBase* pPlugin = (CPluginBase*)instance->pdata;
  return pPlugin->UnInit(save);
}

NPError NP_LOADDS NPP_SetWindow(NPP instance, NPWindow* window) {
  CPluginBase* pPlugin = (CPluginBase*)instance->pdata;
  return pPlugin->SetWindow(window);
}

NPError NP_LOADDS NPP_NewStream(NPP instance, NPMIMEType type,
                                NPStream* stream, NPBool seekable,
                                uint16_t* stype) {
  CPluginBase* pPlugin = (CPluginBase*)instance->pdata;
  return pPlugin->NewStream(type,stream,seekable,stype);
}

NPError NP_LOADDS NPP_DestroyStream(NPP instance, NPStream* stream,
                                    NPReason reason) {
  CPluginBase* pPlugin = (CPluginBase*)instance->pdata;
  return pPlugin->DestroyStream(stream,reason);
}

int32_t NP_LOADDS NPP_WriteReady(NPP instance, NPStream* stream) {
  CPluginBase* pPlugin = (CPluginBase*)instance->pdata;
  return pPlugin->WriteReady(stream);
}

int32_t NP_LOADDS NPP_Write(NPP instance, NPStream* stream, int32_t offset,
                            int32_t len, void* buffer) {
  CPluginBase* pPlugin = (CPluginBase*)instance->pdata;
  return pPlugin->Write(stream,offset,len,buffer);
}

void    NP_LOADDS NPP_StreamAsFile(NPP instance, NPStream* stream,
                                   const char* fname) {
  CPluginBase* pPlugin = (CPluginBase*)instance->pdata;
  pPlugin->StreamAsFile(stream,fname);
}

void    NP_LOADDS NPP_Print(NPP instance, NPPrint* platformPrint) {
  CPluginBase* pPlugin = (CPluginBase*)instance->pdata;
  pPlugin->Print(platformPrint);
}

int16_t NP_LOADDS NPP_HandleEvent(NPP instance, void* event) {
  CPluginBase* pPlugin = (CPluginBase*)instance->pdata;
  return pPlugin->HandleEvent(event);
}

void    NP_LOADDS NPP_URLNotify(NPP instance, const char* url,
                                NPReason reason, void* notifyData) {
  CPluginBase* pPlugin = (CPluginBase*)instance->pdata;
  pPlugin->URLNotify(url,reason,notifyData);
}

NPError NP_LOADDS NPP_GetValue(NPP instance, NPPVariable variable, void *value) {
  CPluginBase* pPlugin = (CPluginBase*)instance->pdata;
  return pPlugin->GetValue(variable,value);
}

NPError NP_LOADDS NPP_SetValue(NPP instance, NPNVariable variable, void *value) {
  CPluginBase* pPlugin = (CPluginBase*)instance->pdata;
  return pPlugin->SetValue(variable,value);
}
