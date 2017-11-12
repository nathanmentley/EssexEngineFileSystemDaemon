/* 
 * Essex Engine
 * 
 * Copyright (C) 2017 Nathan Mentley - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license.
 *
 * You should have received a copy of the BSD license with
 * this file. If not, please visit: https://github.com/nathanmentley/EssexEngine
 */
#pragma once

#include <string>

#include <EssexEngineCore/IDriver.h>
#include <EssexEngineCore/WeakPointer.h>
#include <EssexEngineFileSystemDaemon/IFileBuffer.h>

namespace EssexEngine{
namespace Daemons{
namespace FileSystem{
	class IFileSystemDriver: public Core::IDriver
	{
		public:
			virtual void LoadZipArchive(std::string filepath) = 0;
            virtual void CloseZipArchive() = 0;
            virtual WeakPointer<IFileBuffer> ReadFile(std::string filename) = 0;
            virtual void SaveFile(std::string filename, void* data, uint64_t size) = 0;
		private:
	};
}}};
