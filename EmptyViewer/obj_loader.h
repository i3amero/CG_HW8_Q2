#pragma once
#pragma warning(disable:4996)
#include <vector>
#include <string>

bool loadObj(const std::string& filename,
    std::vector<float>& out_vertices,
    std::vector<float>& out_normals,
    std::vector<unsigned int>& out_indices);
