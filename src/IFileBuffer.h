/* 
 * Essex Engine
 * 
 * Copyright (C) 2018 Nathan Mentley - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license.
 *
 * You should have received a copy of the BSD license with
 * this file. If not, please visit: https://github.com/nathanmentley/EssexEngine
 */
#pragma once

#include <string>
#include <fstream>

namespace EssexEngine{
namespace Daemons{
namespace FileSystem{
    class IFileBuffer {
        public:
            virtual ~IFileBuffer() {};
            virtual std::string GetFileName() = 0;
            virtual void* GetBuffer() = 0;
            virtual uint64_t GetSize() = 0;

            std::fstream GetStream() {
                std::fstream filestr;

                filestr.rdbuf()->pubsetbuf((char*)GetBuffer(), GetSize());

                return filestr;
            }
    };
}}};
