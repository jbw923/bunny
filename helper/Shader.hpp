//
//  Shader.hpp
//  opengl-bunny
//
//  Created by vtta on 12/16/19.
//  Copyright © 2019 vtta. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include <filesystem>
#include <string>

#include "Utils.hpp"

struct ShaderProgramSource {
    std::string vertex;
    std::string fragment;
};

class Shader {
private:
    u32 render_id_;
    std::filesystem::path file_path_;

public:
    Shader(const std::filesystem::path &file_path);
    ~Shader();

    void bind() const;
    void unbind() const;

    void setUniform4f(const std::string &name, float v0, float v1, float v2,
                      float v3);

private:
    u32 uniformLocation(const std::string &name);

    ShaderProgramSource parse(const std::filesystem::path &file_path);
    u32 compile(u32 type, const std::string &source);
    u32 create(const std::string &vertex_code,
               const std::string &fragment_code);
};

#endif /* Shader_hpp */