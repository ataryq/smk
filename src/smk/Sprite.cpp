// Copyright 2019 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.

#include <smk/Framebuffer.hpp>
#include <smk/OpenGL.hpp>
#include <smk/Shader.hpp>
#include <smk/Sprite.hpp>
#include <smk/VertexArray.hpp>
#include <vector>

namespace smk {

/// @brief A Sprite for drawing a texture.
/// @param texture The Texture to be displayed.
Sprite::Sprite(const Texture& texture) : Sprite() {
  SetTexture(texture);
}

/// @brief A Sprite for drawing a part of a Texture.
/// @param texture The Texture to be displayed.
/// @param rectangle A rectangle in the texture to be used.
Sprite::Sprite(const Texture& texture, const Rectangle rectangle) {
  Transformable::SetTexture(texture);
  SetTextureRectangle(rectangle);
}

/// @brief A sprite for drawing the content of a Framebuffer.
/// @param framebuffer The framebuffer to be used.
Sprite::Sprite(Framebuffer& framebuffer) {
  Transformable::SetTexture(framebuffer.color_texture());
  float l = 0.f;
  float r = 1.f;
  float t = 0.f;
  float b = 1.f;
  float www = framebuffer.color_texture().width();
  float hhh = framebuffer.color_texture().height();
  Transformable::SetVertexArray(VertexArray(std::vector<Vertex>({
      {{0.f, 0.f}, {l, b}},
      {{0.f, hhh}, {l, t}},
      {{www, hhh}, {r, t}},
      {{0.f, 0.f}, {l, b}},
      {{www, hhh}, {r, t}},
      {{www, 0.f}, {r, b}},
  })));
}

/// @brief Update the sprite's texture.
/// @param texture The Texture to be displayed.
void Sprite::SetTexture(const Texture& texture) {
  Transformable::SetTexture(texture);
  SetTextureRectangle(
      {0.f, 0.f, float(texture.width()), float(texture.height())});
}

/// @brief Update the sprite texture area.
/// @param texture The Texture to be displayed.
/// @param rectangle A rectangle in the texture to be used.
void Sprite::SetTextureRectangle(const Rectangle& rectangle) {
  SetVertexRectangle(rectangle);
}

}  // namespace smk
