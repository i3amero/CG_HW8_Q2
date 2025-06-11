
##  Q2: Vertex Array and VBO Rendering - 202011378 차현준

In this task, we replaced the immediate mode rendering with OpenGL's modern approach using Vertex Array Objects (VAOs) and Vertex Buffer Objects (VBOs). This improves performance and prepares the codebase for more efficient GPU rendering.

---

###  What Was Implemented

#### 1. Vertex Data Preparation

- Interleaved the vertex positions and normals into a single float buffer:
  ```
  [posX, posY, posZ, normX, normY, normZ, ...]
  ```
- Triangle indices are extracted into a separate index buffer.

#### 2. VAO / VBO / EBO Setup

```cpp
glGenVertexArrays(1, &vao);
glGenBuffers(1, &vbo_positions);
glGenBuffers(1, &ebo);
```

- Bound and uploaded vertex+normal data to `GL_ARRAY_BUFFER`.
- Bound and uploaded triangle indices to `GL_ELEMENT_ARRAY_BUFFER`.
- Enabled and configured `glVertexAttribPointer` for:
  - Location 0 → Position (3 floats)
  - Location 1 → Normal   (3 floats)

#### 3. Rendering Using `glDrawElements`

- Replaced `glBegin()` / `glVertex()` / `glNormal()` calls with:
  ```cpp
  glBindVertexArray(vao);
  glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);
  ```

- Rendering is now done in a single draw call using indexed geometry.

---

###  Integration

- `setup_vertex_buffers()` is called in `main()` after mesh loading.
- A new function `draw_bunny_vbo()` is defined for VAO-based rendering.
- `display()` function now calls `draw_bunny_vbo()` instead of immediate mode.

---

###  Results

- Bunny is rendered exactly as in Q1, but now using GPU buffers.
- FPS measurement still works via OpenGL timer query.
- Code is now scalable for future shader-based rendering in later stages.

---

###  Files Involved

| File             | Description                                   |
|------------------|-----------------------------------------------|
| `main.cpp`       | VAO/VBO setup, `draw_bunny_vbo()`             |
| `frame_timer.cpp`| Calls `draw_bunny_vbo()` in `display()`       |
| `load_mesh.cpp`  | Mesh loading reused from Q1                   |

---

###  Notes

- This implementation avoids deprecated immediate mode entirely.
- No shaders were used yet; OpenGL fixed-function pipeline is still in use.


![image](https://github.com/user-attachments/assets/4b3a14d2-e7c0-4bc2-87ff-acaced0c2d6c)

