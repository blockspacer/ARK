/*
* This source file is part of ARK
* For the latest info, see https://github.com/ArkNX
*
* Copyright (c) 2013-2019 ArkNX authors.
*
* Licensed under the Apache License, Version 2.0 (the "License"),
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/

#pragma once

#include "proto/AFProtoCPP.hpp"
#include "interface/AFIModule.h"

namespace ark
{
    class AFINetServerService;

    class AFIWorldNetModule : public AFIModule
    {
    public:
        virtual bool SendMsgToGame(const int nGameID, const AFMsg::EGameMsgID eMsgID, google::protobuf::Message& xData, const AFGUID nPlayer = AFGUID()) = 0;
        virtual bool SendMsgToGame(const AFIDataList& argObjectVar, const AFIDataList& argGameID, const AFMsg::EGameMsgID eMsgID, google::protobuf::Message& xData) = 0;
        virtual int OnObjectListEnter(const AFIDataList& self, const AFIDataList& argVar) = 0;
        virtual int OnObjectListLeave(const AFIDataList& self, const AFIDataList& argVar) = 0;

        virtual ARK_SHARE_PTR<AFServerData> GetSuitProxyForEnter() = 0;
        virtual AFINetServerService* GetNetServer() = 0;

    };

}