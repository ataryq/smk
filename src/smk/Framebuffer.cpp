#include <smk/Framebuffer.hpp>
#include <smk/RenderState.hpp>
#include <smk/Color.hpp>
#include <smk/Drawable.hpp>

namespace smk {

Framebuffer::Framebuffer(int width, int height) {
  width_ = width;
  height_ = height;

  color_texture.width = width_;
  color_texture.height = height_;

  // The frame buffer.
  glGenFramebuffers(1, &frame_buffer_);
  glBindFramebuffer(GL_FRAMEBUFFER, frame_buffer_);

  // The color buffer.
  glGenTextures(1, &(color_texture.id));
  glBindTexture(GL_TEXTURE_2D, color_texture.id);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width_, height_, 0, GL_RGB,
               GL_UNSIGNED_BYTE, nullptr);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glBindTexture(GL_TEXTURE_2D, 0);

  // Attach the texture to the framebuffer.
  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,
                         color_texture.id, 0);

  // The render buffer.
  glGenRenderbuffers(1, &render_buffer_);
  glBindRenderbuffer(GL_RENDERBUFFER, render_buffer_);
  glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width_, height_);
  glBindRenderbuffer(GL_RENDERBUFFER, 0);

  // Attach it to the framebuffer.
  glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT,
                            GL_RENDERBUFFER, render_buffer_);

  if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
    std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!"
              << std::endl;
  }

  glBindFramebuffer(GL_FRAMEBUFFER, 0);

  InitRenderTarget();
}

Framebuffer::~Framebuffer() {
  if (frame_buffer_) {
    glDeleteFramebuffers(1, &frame_buffer_);
    frame_buffer_ = 0;
  }

  if (render_buffer_) {
    glDeleteRenderbuffers(1, &render_buffer_);
    render_buffer_ = 0;
  }
}

Framebuffer::Framebuffer(Framebuffer&& other) {
  this->operator=(std::move(other));
}

void Framebuffer::operator=(Framebuffer&& other) {
  RenderTarget::operator=(std::move(other));
  std::swap(color_texture, other.color_texture);
  std::swap(render_buffer_, other.render_buffer_);
}

}  // namespace smk