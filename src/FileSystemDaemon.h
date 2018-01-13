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

#include <utility>
#include <string>

#include <EssexEngineCore/BaseDaemon.h>
#include <EssexEngineCore/LogDaemon.h>
#include <EssexEngineCore/CachedPointer.h>
#include <EssexEngineCore/ResourceCache.h>
#include <EssexEngineCore/WeakPointer.h>

#include <EssexEngineFileSystemDaemon/IFileSystemDriver.h>

namespace EssexEngine{
namespace Daemons{
namespace FileSystem{
	class FileSystemDaemon:public BaseDaemon<IFileSystemDriver>
	{
		public:
			FileSystemDaemon(WeakPointer<Context> _context);
			~FileSystemDaemon();
			
			void Init() {
				if(GetContext()->HasDaemon<Core::Logging::LogDaemon>()) {
					GetContext()->GetDaemon<Core::Logging::LogDaemon>()->LogLine(
						"Loading Daemon [%s] [%s]",
						GetDaemonName().c_str(),
						GetDaemonVersion().c_str()
					);
				}
			}
			std::string GetDaemonName() { return "File System"; }
			std::string GetDaemonVersion() { return ESSEX_ENGINE_VERSION; }
			
			void LoadZipArchive(std::string filepath);
            void CloseZipArchive();
            CachedPointer<std::string, IFileBuffer> ReadFile(std::string filename);
            void SaveFile(std::string filename, void* data, uint64_t size);
		private:
			Core::Utils::ResourceCache<std::string, IFileBuffer> fileCache;
	};
}}};
