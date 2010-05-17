/* ***** BEGIN LICENSE BLOCK *****
* Version: MPL 1.1/GPL 2.0/LGPL 2.1
* This code was based on the npsimple.c sample code in Gecko-sdk.
*
* The contents of this file are subject to the Mozilla Public License Version
* 1.1 (the "License"); you may not use this file except in compliance with
* the License. You may obtain a copy of the License at
* http://www.mozilla.org/MPL/
*
* Software distributed under the License is distributed on an "AS IS" basis,
* WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
* for the specific language governing rights and limitations under the
* License.
*
* Contributor(s):
*   Bo Chen   <chen_bo-bj@vanceinfo.com>
*   Jing Zhao <jingzhao@google.com>
*
* Alternatively, the contents of this file may be used under the terms of
* either the GNU General Public License Version 2 or later (the "GPL"), or 
* the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
* in which case the provisions of the GPL or the LGPL are applicable instead
* of those above. If you wish to allow use of your version of this file only
* under the terms of either the GPL or the LGPL, and not to allow others to
* use your version of this file under the terms of the NPL, indicate your
* decision by deleting the provisions above and replace them with the notice
* and other provisions required by the GPL or the LGPL. If you do not delete
* the provisions above, a recipient may use your version of this file under
* the terms of any one of the NPL, the GPL or the LGPL.
* ***** END LICENSE BLOCK ***** */

#ifndef NPDOWNLOAD__NPDOWNLOADHELPER_H_
#define NPDOWNLOAD__NPDOWNLOADHELPER_H_

#include "npfunctions.h"
#include "flashget/flashget.h"
#include "thunder/thunder.h"

class CPlugin: NPObject {
public:
  static NPObject* Allocate(NPP instance, NPClass* npclass);
  static void Deallocate(NPObject* obj);
  static bool HasMethod(NPObject* obj, NPIdentifier methodName);
  static bool InvokeDefault(NPObject* obj, const NPVariant* args,
                            uint32_t argCount, NPVariant* result);
  static bool Invoke(NPObject* obj, NPIdentifier methodName,
                     const NPVariant* args, uint32_t argCount,
                     NPVariant* result);
  static bool HasProperty(NPObject* obj, NPIdentifier propertyName);
  static bool GetProperty(NPObject* obj, NPIdentifier propertyName,
                          NPVariant* result);
  NPP npp;
};
  
extern NPNetscapeFuncs* npnfuncs;

void DebugLog(const char* msg);

#endif  // NPDOWNLOAD__NPDOWNLOADHELPER_H_