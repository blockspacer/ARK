/*****************************************************************************
// * This source file is part of ArkGameFrame                                *
// * For the latest info, see https://github.com/ArkGame                     *
// *                                                                         *
// * Copyright(c) 2013 - 2017 ArkGame authors.                               *
// *                                                                         *
// * Licensed under the Apache License, Version 2.0 (the "License");         *
// * you may not use this file except in compliance with the License.        *
// * You may obtain a copy of the License at                                 *
// *                                                                         *
// *     http://www.apache.org/licenses/LICENSE-2.0                          *
// *                                                                         *
// * Unless required by applicable law or agreed to in writing, software     *
// * distributed under the License is distributed on an "AS IS" BASIS,       *
// * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*
// * See the License for the specific language governing permissions and     *
// * limitations under the License.                                          *
// *                                                                         *
// *                                                                         *
// * @file  	AFGamePlugin.cpp                                              *
// * @author    Ark Game Tech                                                *
// * @date      2015-12-15                                                   *
// * @brief     AFGamePlugin                                                  *
*****************************************************************************/
#include "AFGamePlugin.h"
#include "AFCGameServerModule.h"
#include "AFCSceneProcessModule.h"
#include "AFCPropertyModule.h"
#include "AFCLevelModule.h"
#include "AFCPropertyConfigModule.h"

#ifdef ARK_DYNAMIC_PLUGIN

ARK_EXPORT void DllStartPlugin(AFIPluginManager* pm)
{
#if ARK_PLATFORM == PLATFORM_WIN
    SetConsoleTitle("NFGameServer");
#endif // ARK_PLATFORM
    CREATE_PLUGIN(pm, AFGamePlugin)

};

ARK_EXPORT void DllStopPlugin(AFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, AFGamePlugin)
};

#endif
//////////////////////////////////////////////////////////////////////////

const int AFGamePlugin::GetPluginVersion()
{
    return 0;
}

const std::string AFGamePlugin::GetPluginName()
{
    return GET_CLASS_NAME(AFGamePlugin)
}

void AFGamePlugin::Install()
{

    REGISTER_MODULE(pPluginManager, AFIGameServerModule, AFCGameServerModule)
    REGISTER_MODULE(pPluginManager, AFISceneProcessModule, AFCSceneProcessModule)

    REGISTER_MODULE(pPluginManager, AFIPropertyModule, AFCPropertyModule)
    REGISTER_MODULE(pPluginManager, AFILevelModule, AFCLevelModule)
    REGISTER_MODULE(pPluginManager, AFIPropertyConfigModule, AFCPropertyConfigModule)
}

void AFGamePlugin::Uninstall()
{
    UNREGISTER_MODULE(pPluginManager, AFIPropertyConfigModule, AFCPropertyConfigModule)
    UNREGISTER_MODULE(pPluginManager, AFILevelModule, AFCLevelModule)
    UNREGISTER_MODULE(pPluginManager, AFIPropertyModule, AFCPropertyModule)

    UNREGISTER_MODULE(pPluginManager, AFISceneProcessModule, AFCSceneProcessModule)
    UNREGISTER_MODULE(pPluginManager, AFIGameServerModule, AFCGameServerModule)
}

