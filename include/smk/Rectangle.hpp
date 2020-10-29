// Copyright 2019 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.

#ifndef SMK_RECTANGLE
#define SMK_RECTANGLE

//test
#include <glm/glm.hpp>

namespace smk {

struct Rectangle {

  float x;
  float y;
  float width;
  float height;

  bool isInside(const glm::vec2& pt) const {
    return pt.x >= x && pt.y >= y && pt.x <= right() && pt.y <= bottom();
  }

  glm::vec2 size() const { return {width, height}; }
  glm::vec2 position() const { return {x, y}; }

  void move(const glm::vec2& vec) {
    x += vec.x;
    y += vec.y;
  }
  void setPosition(const glm::vec2& vec) {
    x = vec.x;
    y = vec.y;
  }
  void setSize(const glm::vec2& vec) {
    width = vec.x;
    height = vec.y;
  }

  float left() const { return x; }
  float top() const { return y; }
  float right() const { return x + width; }
  float bottom() const { return y + height; }
};

}  // namespace smk

#endif /* end of include guard: SMK_RECTANGLE */
