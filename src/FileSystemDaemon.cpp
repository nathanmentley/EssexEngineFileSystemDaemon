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

#include <EssexEngineFileSystemDaemon/FileSystemDaemon.h>

EssexEngine::Daemons::FileSystem::FileSystemDaemon::FileSystemDaemon(WeakPointer<Context> _context):BaseDaemon(_context),
    fileCache(_context->GetDaemon<Core::Logging::LogDaemon>()) {}

EssexEngine::Daemons::FileSystem::FileSystemDaemon::~FileSystemDaemon() {}

extern "C" {
    void daemon_init(EssexEngine::WeakPointer<EssexEngine::Context> context) {
        context->RegisterDaemon<EssexEngine::Daemons::FileSystem::FileSystemDaemon>(
            new EssexEngine::Daemons::FileSystem::FileSystemDaemon(context)
        );
    }
}

void EssexEngine::Daemons::FileSystem::FileSystemDaemon::LoadZipArchive(std::string filepath) {
    GetDriver()->LoadZipArchive(filepath);
}

void EssexEngine::Daemons::FileSystem::FileSystemDaemon::CloseZipArchive() {
    GetDriver()->CloseZipArchive();
}

EssexEngine::CachedPointer<std::string, EssexEngine::Daemons::FileSystem::IFileBuffer> EssexEngine::Daemons::FileSystem::FileSystemDaemon::ReadFile(std::string filename) {
    if (!fileCache.HasKey(filename)) {
        WeakPointer<IFileBuffer> file = GetDriver()->ReadFile(filename);

        fileCache.Cache(filename, file);
    }

    return fileCache.Get(filename);
}

void EssexEngine::Daemons::FileSystem::FileSystemDaemon::SaveFile(std::string filename, void* data, uint64_t size) {
    GetDriver()->SaveFile(filename, data, size);
}
