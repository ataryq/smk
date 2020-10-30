// Copyright 2019 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.

#ifndef SMK_COLOR_HPP
#define SMK_COLOR_HPP

#include <glm/glm.hpp>

namespace smk {
namespace Color {

glm::vec4 RGBA(float red, float green, float blue, float alpha);
glm::vec4 RGB(float red, float green, float blue);

constexpr float toNorm(int i) {
  return static_cast<float>(i) / 255;
}

constexpr glm::vec4 RGB_255(int red, int green, int blue, int alpha) {
  return {toNorm(red), toNorm(green), toNorm(blue), toNorm(alpha)};
}

  // Predefined colors.
extern const glm::vec4 White;
extern const glm::vec4 Black;
extern const glm::vec4 Grey;
extern const glm::vec4 Red;
extern const glm::vec4 Green;
extern const glm::vec4 Blue;
extern const glm::vec4 Yellow;
extern const glm::vec4 Magenta;
extern const glm::vec4 Cyan;
extern const glm::vec4 Transparent;

}  // namespace Color
}  // namespace smk

#endif /* end of include guard: SMK_COLOR_HPP */
