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

#include <EssexEngineFileSystemDaemon/IFileSystemDriver.h>
#include <EssexEngineCore/BaseDaemon.h>

namespace EssexEngine{
namespace Daemons{
namespace FileSystem{
	class FileSystemDaemon:public BaseDaemon<IFileSystemDriver>
	{
		public:
			FileSystemDaemon(WeakPointer<Context> _context);
			~FileSystemDaemon();
			
			void Init() {
				if(GetContext()->HasDriver<Core::Logging::ILogDriver>()) {
					GetContext()->GetDriver<Core::Logging::ILogDriver>()->LogLine(
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
            SharedPointer<IFileBuffer> ReadFile(std::string filename);
            void SaveFile(std::string filename, void* data, uint64_t size);
		private:
	};
}}};