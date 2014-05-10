/*
 * Copyright © 2013-2014  Rinat Ibragimov
 *
 * This file is part of FreshPlayerPlugin.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "ppb_opengles2.h"
#include <GLES2/gl2.h>
#include <stddef.h>
#include "trace.h"
#include "pp_resource.h"


static
void
setup_ctx(PP_Resource context)
{
    struct pp_graphics3d_s *g3d = pp_resource_acquire(context, PP_RESOURCE_GRAPHICS3D);
    glXMakeContextCurrent(g3d->dpy, g3d->glx_pixmap, g3d->glx_pixmap, g3d->glc);
    pp_resource_release(context);
}

void
ppb_opengles2_ActiveTexture(PP_Resource context, GLenum texture)
{
    setup_ctx(context);
    glActiveTexture(texture);
}

void
ppb_opengles2_AttachShader(PP_Resource context, GLuint program, GLuint shader)
{
    setup_ctx(context);
    glAttachShader(program, shader);
}

void
ppb_opengles2_BindAttribLocation(PP_Resource context, GLuint program, GLuint index,
                                 const char *name)
{
    setup_ctx(context);
    glBindAttribLocation(program, index, name);
}

void
ppb_opengles2_BindBuffer(PP_Resource context, GLenum target, GLuint buffer)
{
    setup_ctx(context);
    glBindBuffer(target, buffer);
}

void
ppb_opengles2_BindFramebuffer(PP_Resource context, GLenum target, GLuint framebuffer)
{
    setup_ctx(context);
    glBindFramebuffer(target, framebuffer);
}

void
ppb_opengles2_BindRenderbuffer(PP_Resource context, GLenum target, GLuint renderbuffer)
{
    setup_ctx(context);
    glBindRenderbuffer(target, renderbuffer);
}

void
ppb_opengles2_BindTexture(PP_Resource context, GLenum target, GLuint texture)
{
    setup_ctx(context);
    glBindTexture(target, texture);
}

void
ppb_opengles2_BlendColor(PP_Resource context, GLclampf red, GLclampf green, GLclampf blue,
                         GLclampf alpha)
{
    setup_ctx(context);
    glBlendColor(red, green, blue, alpha);
}

void
ppb_opengles2_BlendEquation(PP_Resource context, GLenum mode)
{
    setup_ctx(context);
    glBlendEquation(mode);
}

void
ppb_opengles2_BlendEquationSeparate(PP_Resource context, GLenum modeRGB, GLenum modeAlpha)
{
    setup_ctx(context);
    glBlendEquationSeparate(modeRGB, modeAlpha);
}

void
ppb_opengles2_BlendFunc(PP_Resource context, GLenum sfactor, GLenum dfactor)
{
    setup_ctx(context);
    glBlendFunc(sfactor, dfactor);
}

void
ppb_opengles2_BlendFuncSeparate(PP_Resource context, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha,
                                GLenum dstAlpha)
{
    setup_ctx(context);
    glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void
ppb_opengles2_BufferData(PP_Resource context, GLenum target, GLsizeiptr size, const void *data,
                         GLenum usage)
{
    setup_ctx(context);
    glBufferData(target, size, data, usage);
}

void
ppb_opengles2_BufferSubData(PP_Resource context, GLenum target, GLintptr offset, GLsizeiptr size,
                            const void *data)
{
    setup_ctx(context);
    glBufferSubData(target, offset, size, data);
}

GLenum
ppb_opengles2_CheckFramebufferStatus(PP_Resource context, GLenum target)
{
    setup_ctx(context);
    return glCheckFramebufferStatus(target);
}

void
ppb_opengles2_Clear(PP_Resource context, GLbitfield mask)
{
    setup_ctx(context);
    glClear(mask);
}

void
ppb_opengles2_ClearColor(PP_Resource context, GLclampf red, GLclampf green, GLclampf blue,
                         GLclampf alpha)
{
    setup_ctx(context);
    glClearColor(red, green, blue, alpha);
}

void
ppb_opengles2_ClearDepthf(PP_Resource context, GLclampf depth)
{
    setup_ctx(context);
    glClearDepthf(depth);
}

void
ppb_opengles2_ClearStencil(PP_Resource context, GLint s)
{
    setup_ctx(context);
    glClearStencil(s);
}

void
ppb_opengles2_ColorMask(PP_Resource context, GLboolean red, GLboolean green, GLboolean blue,
                        GLboolean alpha)
{
    setup_ctx(context);
    glColorMask(red, green, blue, alpha);
}

void
ppb_opengles2_CompileShader(PP_Resource context, GLuint shader)
{
    setup_ctx(context);
    glCompileShader(shader);
}

void
ppb_opengles2_CompressedTexImage2D(PP_Resource context, GLenum target, GLint level,
                                   GLenum internalformat, GLsizei width, GLsizei height,
                                   GLint border, GLsizei imageSize, const void *data)
{
    setup_ctx(context);
    glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}

void
ppb_opengles2_CompressedTexSubImage2D(PP_Resource context, GLenum target, GLint level,
                                      GLint xoffset, GLint yoffset, GLsizei width, GLsizei height,
                                      GLenum format, GLsizei imageSize, const void *data)
{
    setup_ctx(context);
    glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize,
                              data);
}

void
ppb_opengles2_CopyTexImage2D(PP_Resource context, GLenum target, GLint level, GLenum internalformat,
                             GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
    setup_ctx(context);
    glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}

void
ppb_opengles2_CopyTexSubImage2D(PP_Resource context, GLenum target, GLint level, GLint xoffset,
                                GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
    setup_ctx(context);
    glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}

GLuint
ppb_opengles2_CreateProgram(PP_Resource context)
{
    setup_ctx(context);
    return glCreateProgram();
}

GLuint
ppb_opengles2_CreateShader(PP_Resource context, GLenum type)
{
    setup_ctx(context);
    return glCreateShader(type);
}

void
ppb_opengles2_CullFace(PP_Resource context, GLenum mode)
{
    setup_ctx(context);
    glCullFace(mode);
}

void
ppb_opengles2_DeleteBuffers(PP_Resource context, GLsizei n, const GLuint *buffers)
{
    setup_ctx(context);
    glDeleteBuffers(n, buffers);
}

void
ppb_opengles2_DeleteFramebuffers(PP_Resource context, GLsizei n, const GLuint *framebuffers)
{
    setup_ctx(context);
    glDeleteFramebuffers(n, framebuffers);
}

void
ppb_opengles2_DeleteProgram(PP_Resource context, GLuint program)
{
    setup_ctx(context);
    glDeleteProgram(program);
}

void
ppb_opengles2_DeleteRenderbuffers(PP_Resource context, GLsizei n, const GLuint *renderbuffers)
{
    setup_ctx(context);
    glDeleteRenderbuffers(n, renderbuffers);
}

void
ppb_opengles2_DeleteShader(PP_Resource context, GLuint shader)
{
    setup_ctx(context);
    glDeleteShader(shader);
}

void
ppb_opengles2_DeleteTextures(PP_Resource context, GLsizei n, const GLuint *textures)
{
    setup_ctx(context);
    glDeleteTextures(n, textures);
}

void
ppb_opengles2_DepthFunc(PP_Resource context, GLenum func)
{
    setup_ctx(context);
    glDepthFunc(func);
}

void
ppb_opengles2_DepthMask(PP_Resource context, GLboolean flag)
{
    setup_ctx(context);
    glDepthMask(flag);
}

void
ppb_opengles2_DepthRangef(PP_Resource context, GLclampf zNear, GLclampf zFar)
{
    setup_ctx(context);
    glDepthRangef(zNear, zFar);
}

void
ppb_opengles2_DetachShader(PP_Resource context, GLuint program, GLuint shader)
{
    setup_ctx(context);
    glDetachShader(program, shader);
}

void
ppb_opengles2_Disable(PP_Resource context, GLenum cap)
{
    setup_ctx(context);
    glDisable(cap);
}

void
ppb_opengles2_DisableVertexAttribArray(PP_Resource context, GLuint index)
{
    setup_ctx(context);
    glDisableVertexAttribArray(index);
}

void
ppb_opengles2_DrawArrays(PP_Resource context, GLenum mode, GLint first, GLsizei count)
{
    setup_ctx(context);
    glDrawArrays(mode, first, count);
}

void
ppb_opengles2_DrawElements(PP_Resource context, GLenum mode, GLsizei count, GLenum type,
                           const void *indices)
{
    setup_ctx(context);
    glDrawElements(mode, count, type, indices);
}

void
ppb_opengles2_Enable(PP_Resource context, GLenum cap)
{
    setup_ctx(context);
    glEnable(cap);
}

void
ppb_opengles2_EnableVertexAttribArray(PP_Resource context, GLuint index)
{
    setup_ctx(context);
    glEnableVertexAttribArray(index);
}

void
ppb_opengles2_Finish(PP_Resource context)
{
    setup_ctx(context);
    glFinish();
}

void
ppb_opengles2_Flush(PP_Resource context)
{
    setup_ctx(context);
    glFlush();
}

void
ppb_opengles2_FramebufferRenderbuffer(PP_Resource context, GLenum target, GLenum attachment,
                                      GLenum renderbuffertarget, GLuint renderbuffer)
{
    setup_ctx(context);
    glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}

void
ppb_opengles2_FramebufferTexture2D(PP_Resource context, GLenum target, GLenum attachment,
                                   GLenum textarget, GLuint texture, GLint level)
{
    setup_ctx(context);
    glFramebufferTexture2D(target, attachment, textarget, texture, level);
}

void
ppb_opengles2_FrontFace(PP_Resource context, GLenum mode)
{
    setup_ctx(context);
    glFrontFace(mode);
}

void
ppb_opengles2_GenBuffers(PP_Resource context, GLsizei n, GLuint *buffers)
{
    setup_ctx(context);
    glGenBuffers(n, buffers);
}

void
ppb_opengles2_GenerateMipmap(PP_Resource context, GLenum target)
{
    setup_ctx(context);
    glGenerateMipmap(target);
}

void
ppb_opengles2_GenFramebuffers(PP_Resource context, GLsizei n, GLuint *framebuffers)
{
    setup_ctx(context);
    glGenFramebuffers(n, framebuffers);
}

void
ppb_opengles2_GenRenderbuffers(PP_Resource context, GLsizei n, GLuint *renderbuffers)
{
    setup_ctx(context);
    glGenRenderbuffers(n, renderbuffers);
}

void
ppb_opengles2_GenTextures(PP_Resource context, GLsizei n, GLuint *textures)
{
    setup_ctx(context);
    glGenTextures(n, textures);
}

void
ppb_opengles2_GetActiveAttrib(PP_Resource context, GLuint program, GLuint index, GLsizei bufsize,
                              GLsizei *length, GLint *size, GLenum *type, char *name)
{
    setup_ctx(context);
    glGetActiveAttrib(program, index, bufsize, length, size, type, name);
}

void
ppb_opengles2_GetActiveUniform(PP_Resource context, GLuint program, GLuint index, GLsizei bufsize,
                               GLsizei *length, GLint *size, GLenum *type, char *name)
{
    setup_ctx(context);
    glGetActiveUniform(program, index, bufsize, length, size, type, name);
}

void
ppb_opengles2_GetAttachedShaders(PP_Resource context, GLuint program, GLsizei maxcount,
                                 GLsizei *count, GLuint *shaders)
{
    setup_ctx(context);
    glGetAttachedShaders(program, maxcount, count, shaders);
}

GLint
ppb_opengles2_GetAttribLocation(PP_Resource context, GLuint program, const char *name)
{
    setup_ctx(context);
    return glGetAttribLocation(program, name);
}

void
ppb_opengles2_GetBooleanv(PP_Resource context, GLenum pname, GLboolean *params)
{
    setup_ctx(context);
    glGetBooleanv(pname, params);
}

void
ppb_opengles2_GetBufferParameteriv(PP_Resource context, GLenum target, GLenum pname, GLint *params)
{
    setup_ctx(context);
    glGetBufferParameteriv(target, pname, params);
}

GLenum
ppb_opengles2_GetError(PP_Resource context)
{
    setup_ctx(context);
    return glGetError();
}

void
ppb_opengles2_GetFloatv(PP_Resource context, GLenum pname, GLfloat *params)
{
    setup_ctx(context);
    glGetFloatv(pname, params);
}

void
ppb_opengles2_GetFramebufferAttachmentParameteriv(PP_Resource context, GLenum target,
                                                  GLenum attachment, GLenum pname, GLint *params)
{
    setup_ctx(context);
    glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}

void
ppb_opengles2_GetIntegerv(PP_Resource context, GLenum pname, GLint *params)
{
    setup_ctx(context);
    glGetIntegerv(pname, params);
}

void
ppb_opengles2_GetProgramiv(PP_Resource context, GLuint program, GLenum pname, GLint *params)
{
    setup_ctx(context);
    glGetProgramiv(program, pname, params);
}

void
ppb_opengles2_GetProgramInfoLog(PP_Resource context, GLuint program, GLsizei bufsize,
                                GLsizei *length, char *infolog)
{
    setup_ctx(context);
    glGetProgramInfoLog(program, bufsize, length, infolog);
}

void
ppb_opengles2_GetRenderbufferParameteriv(PP_Resource context, GLenum target, GLenum pname,
                                         GLint *params)
{
    setup_ctx(context);
    glGetRenderbufferParameteriv(target, pname, params);
}

void
ppb_opengles2_GetShaderiv(PP_Resource context, GLuint shader, GLenum pname, GLint *params)
{
    setup_ctx(context);
    glGetShaderiv(shader, pname, params);
}

void
ppb_opengles2_GetShaderInfoLog(PP_Resource context, GLuint shader, GLsizei bufsize, GLsizei *length,
                               char *infolog)
{
    setup_ctx(context);
    glGetShaderInfoLog(shader, bufsize, length, infolog);
}

void
ppb_opengles2_GetShaderPrecisionFormat(PP_Resource context, GLenum shadertype, GLenum precisiontype,
                                       GLint *range, GLint *precision)
{
    setup_ctx(context);
    glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
}

void
ppb_opengles2_GetShaderSource(PP_Resource context, GLuint shader, GLsizei bufsize, GLsizei *length,
                              char *source)
{
    setup_ctx(context);
    glGetShaderSource(shader, bufsize, length, source);
}

const GLubyte *
ppb_opengles2_GetString(PP_Resource context, GLenum name)
{
    setup_ctx(context);
    return glGetString(name);
}

void
ppb_opengles2_GetTexParameterfv(PP_Resource context, GLenum target, GLenum pname, GLfloat *params)
{
    setup_ctx(context);
    glGetTexParameterfv(target, pname, params);
}

void
ppb_opengles2_GetTexParameteriv(PP_Resource context, GLenum target, GLenum pname, GLint *params)
{
    setup_ctx(context);
    glGetTexParameteriv(target, pname, params);
}

void
ppb_opengles2_GetUniformfv(PP_Resource context, GLuint program, GLint location, GLfloat *params)
{
    setup_ctx(context);
    glGetUniformfv(program, location, params);
}

void
ppb_opengles2_GetUniformiv(PP_Resource context, GLuint program, GLint location, GLint *params)
{
    setup_ctx(context);
    glGetUniformiv(program, location, params);
}

GLint
ppb_opengles2_GetUniformLocation(PP_Resource context, GLuint program, const char *name)
{
    setup_ctx(context);
    return glGetUniformLocation(program, name);
}

void
ppb_opengles2_GetVertexAttribfv(PP_Resource context, GLuint index, GLenum pname, GLfloat *params)
{
    setup_ctx(context);
    glGetVertexAttribfv(index, pname, params);
}

void
ppb_opengles2_GetVertexAttribiv(PP_Resource context, GLuint index, GLenum pname, GLint *params)
{
    setup_ctx(context);
    glGetVertexAttribiv(index, pname, params);
}

void
ppb_opengles2_GetVertexAttribPointerv(PP_Resource context, GLuint index, GLenum pname,
                                      void **pointer)
{
    setup_ctx(context);
    glGetVertexAttribPointerv(index, pname, pointer);
}

void
ppb_opengles2_Hint(PP_Resource context, GLenum target, GLenum mode)
{
    setup_ctx(context);
    glHint(target, mode);
}

GLboolean
ppb_opengles2_IsBuffer(PP_Resource context, GLuint buffer)
{
    setup_ctx(context);
    return glIsBuffer(buffer);
}

GLboolean
ppb_opengles2_IsEnabled(PP_Resource context, GLenum cap)
{
    setup_ctx(context);
    return glIsEnabled(cap);
}

GLboolean
ppb_opengles2_IsFramebuffer(PP_Resource context, GLuint framebuffer)
{
    setup_ctx(context);
    return glIsFramebuffer(framebuffer);
}

GLboolean
ppb_opengles2_IsProgram(PP_Resource context, GLuint program)
{
    setup_ctx(context);
    return glIsProgram(program);
}

GLboolean
ppb_opengles2_IsRenderbuffer(PP_Resource context, GLuint renderbuffer)
{
    setup_ctx(context);
    return glIsRenderbuffer(renderbuffer);
}

GLboolean
ppb_opengles2_IsShader(PP_Resource context, GLuint shader)
{
    setup_ctx(context);
    return glIsShader(shader);
}

GLboolean
ppb_opengles2_IsTexture(PP_Resource context, GLuint texture)
{
    setup_ctx(context);
    return glIsTexture(texture);
}

void
ppb_opengles2_LineWidth(PP_Resource context, GLfloat width)
{
    setup_ctx(context);
    glLineWidth(width);
}

void
ppb_opengles2_LinkProgram(PP_Resource context, GLuint program)
{
    setup_ctx(context);
    glLinkProgram(program);
}

void
ppb_opengles2_PixelStorei(PP_Resource context, GLenum pname, GLint param)
{
    setup_ctx(context);
    glPixelStorei(pname, param);
}

void
ppb_opengles2_PolygonOffset(PP_Resource context, GLfloat factor, GLfloat units)
{
    setup_ctx(context);
    glPolygonOffset(factor, units);
}

void
ppb_opengles2_ReadPixels(PP_Resource context, GLint x, GLint y, GLsizei width, GLsizei height,
                         GLenum format, GLenum type, void *pixels)
{
    setup_ctx(context);
    glReadPixels(x, y, width, height, format, type, pixels);
}

void
ppb_opengles2_ReleaseShaderCompiler(PP_Resource context)
{
    setup_ctx(context);
    glReleaseShaderCompiler();
}

void
ppb_opengles2_RenderbufferStorage(PP_Resource context, GLenum target, GLenum internalformat,
                                  GLsizei width, GLsizei height)
{
    setup_ctx(context);
    glRenderbufferStorage(target, internalformat, width, height);
}

void
ppb_opengles2_SampleCoverage(PP_Resource context, GLclampf value, GLboolean invert)
{
    setup_ctx(context);
    glSampleCoverage(value, invert);
}

void
ppb_opengles2_Scissor(PP_Resource context, GLint x, GLint y, GLsizei width, GLsizei height)
{
    setup_ctx(context);
    glScissor(x, y, width, height);
}

void
ppb_opengles2_ShaderBinary(PP_Resource context, GLsizei n, const GLuint *shaders,
                           GLenum binaryformat, const void *binary, GLsizei length)
{
    setup_ctx(context);
    glShaderBinary(n, shaders, binaryformat, binary, length);
}

void
ppb_opengles2_ShaderSource(PP_Resource context, GLuint shader, GLsizei count, const char **str,
                           const GLint *length)
{
    setup_ctx(context);
    const char *v100 = "#version 100\n";
    const unsigned int v100_len = strlen(v100);

    // prepend "#version 100" line to all shaders
    // This enables shader compatibility mode introduced by GL_ARB_ES2_compatibility
    char **str2 = malloc(count * sizeof(char *));
    for (uintptr_t k = 0; k < count; k ++) {
        size_t shader_len = strlen(str[k]);
        str2[k] = malloc(shader_len + 1 + v100_len);
        memcpy(str2[k], v100, v100_len); // first line
        memcpy(str2[k] + v100_len, str[k], shader_len + 1); // shader source with trailing \0
    }

    glShaderSource(shader, count, (const char **)str2, length);

    for (uintptr_t k = 0; k < count; k ++)
        free(str2[k]);
    free(str2);
}

void
ppb_opengles2_StencilFunc(PP_Resource context, GLenum func, GLint ref, GLuint mask)
{
    setup_ctx(context);
    glStencilFunc(func, ref, mask);
}

void
ppb_opengles2_StencilFuncSeparate(PP_Resource context, GLenum face, GLenum func, GLint ref,
                                  GLuint mask)
{
    setup_ctx(context);
    glStencilFuncSeparate(face, func, ref, mask);
}

void
ppb_opengles2_StencilMask(PP_Resource context, GLuint mask)
{
    setup_ctx(context);
    glStencilMask(mask);
}

void
ppb_opengles2_StencilMaskSeparate(PP_Resource context, GLenum face, GLuint mask)
{
    setup_ctx(context);
    glStencilMaskSeparate(face, mask);
}

void
ppb_opengles2_StencilOp(PP_Resource context, GLenum fail, GLenum zfail, GLenum zpass)
{
    setup_ctx(context);
    glStencilOp(fail, zfail, zpass);
}

void
ppb_opengles2_StencilOpSeparate(PP_Resource context, GLenum face, GLenum fail, GLenum zfail,
                                GLenum zpass)
{
    setup_ctx(context);
    glStencilOpSeparate(face, fail, zfail, zpass);
}

void
ppb_opengles2_TexImage2D(PP_Resource context, GLenum target, GLint level, GLint internalformat,
                         GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type,
                         const void *pixels)
{
    setup_ctx(context);
    glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}

void
ppb_opengles2_TexParameterf(PP_Resource context, GLenum target, GLenum pname, GLfloat param)
{
    setup_ctx(context);
    glTexParameterf(target, pname, param);
}

void
ppb_opengles2_TexParameterfv(PP_Resource context, GLenum target, GLenum pname,
                             const GLfloat *params)
{
    setup_ctx(context);
    glTexParameterfv(target, pname, params);
}

void
ppb_opengles2_TexParameteri(PP_Resource context, GLenum target, GLenum pname, GLint param)
{
    setup_ctx(context);
    glTexParameteri(target, pname, param);
}

void
ppb_opengles2_TexParameteriv(PP_Resource context, GLenum target, GLenum pname, const GLint *params)
{
    setup_ctx(context);
    glTexParameteriv(target, pname, params);
}

void
ppb_opengles2_TexSubImage2D(PP_Resource context, GLenum target, GLint level, GLint xoffset,
                            GLint yoffset, GLsizei width, GLsizei height, GLenum format,
                            GLenum type, const void *pixels)
{
    setup_ctx(context);
    glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}

void
ppb_opengles2_Uniform1f(PP_Resource context, GLint location, GLfloat x)
{
    setup_ctx(context);
    glUniform1f(location, x);
}

void
ppb_opengles2_Uniform1fv(PP_Resource context, GLint location, GLsizei count, const GLfloat *v)
{
    setup_ctx(context);
    glUniform1fv(location, count, v);
}

void
ppb_opengles2_Uniform1i(PP_Resource context, GLint location, GLint x)
{
    setup_ctx(context);
    glUniform1i(location, x);
}

void
ppb_opengles2_Uniform1iv(PP_Resource context, GLint location, GLsizei count, const GLint *v)
{
    setup_ctx(context);
    glUniform1iv(location, count, v);
}

void
ppb_opengles2_Uniform2f(PP_Resource context, GLint location, GLfloat x, GLfloat y)
{
    setup_ctx(context);
    glUniform2f(location, x, y);
}

void
ppb_opengles2_Uniform2fv(PP_Resource context, GLint location, GLsizei count, const GLfloat *v)
{
    setup_ctx(context);
    glUniform2fv(location, count, v);
}

void
ppb_opengles2_Uniform2i(PP_Resource context, GLint location, GLint x, GLint y)
{
    setup_ctx(context);
    glUniform2i(location, x, y);
}

void
ppb_opengles2_Uniform2iv(PP_Resource context, GLint location, GLsizei count, const GLint *v)
{
    setup_ctx(context);
    glUniform2iv(location, count, v);
}

void
ppb_opengles2_Uniform3f(PP_Resource context, GLint location, GLfloat x, GLfloat y, GLfloat z)
{
    setup_ctx(context);
    glUniform3f(location, x, y, z);
}

void
ppb_opengles2_Uniform3fv(PP_Resource context, GLint location, GLsizei count, const GLfloat *v)
{
    setup_ctx(context);
    glUniform3fv(location, count, v);
}

void
ppb_opengles2_Uniform3i(PP_Resource context, GLint location, GLint x, GLint y, GLint z)
{
    setup_ctx(context);
    glUniform3i(location, x, y, z);
}

void
ppb_opengles2_Uniform3iv(PP_Resource context, GLint location, GLsizei count, const GLint *v)
{
    setup_ctx(context);
    glUniform3iv(location, count, v);
}

void
ppb_opengles2_Uniform4f(PP_Resource context, GLint location, GLfloat x, GLfloat y, GLfloat z,
                        GLfloat w)
{
    setup_ctx(context);
    glUniform4f(location, x, y, z, w);
}

void
ppb_opengles2_Uniform4fv(PP_Resource context, GLint location, GLsizei count, const GLfloat *v)
{
    setup_ctx(context);
    glUniform4fv(location, count, v);
}

void
ppb_opengles2_Uniform4i(PP_Resource context, GLint location, GLint x, GLint y, GLint z, GLint w)
{
    setup_ctx(context);
    glUniform4i(location, x, y, z, w);
}

void
ppb_opengles2_Uniform4iv(PP_Resource context, GLint location, GLsizei count, const GLint *v)
{
    setup_ctx(context);
    glUniform4iv(location, count, v);
}

void
ppb_opengles2_UniformMatrix2fv(PP_Resource context, GLint location, GLsizei count,
                               GLboolean transpose, const GLfloat *value)
{
    setup_ctx(context);
    glUniformMatrix2fv(location, count, transpose, value);
}

void
ppb_opengles2_UniformMatrix3fv(PP_Resource context, GLint location, GLsizei count,
                               GLboolean transpose, const GLfloat *value)
{
    setup_ctx(context);
    glUniformMatrix3fv(location, count, transpose, value);
}

void
ppb_opengles2_UniformMatrix4fv(PP_Resource context, GLint location, GLsizei count,
                               GLboolean transpose, const GLfloat *value)
{
    setup_ctx(context);
    glUniformMatrix4fv(location, count, transpose, value);
}

void
ppb_opengles2_UseProgram(PP_Resource context, GLuint program)
{
    setup_ctx(context);
    glUseProgram(program);
}

void
ppb_opengles2_ValidateProgram(PP_Resource context, GLuint program)
{
    setup_ctx(context);
    glValidateProgram(program);
}

void
ppb_opengles2_VertexAttrib1f(PP_Resource context, GLuint indx, GLfloat x)
{
    setup_ctx(context);
    glVertexAttrib1f(indx, x);
}

void
ppb_opengles2_VertexAttrib1fv(PP_Resource context, GLuint indx, const GLfloat *values)
{
    setup_ctx(context);
    glVertexAttrib1fv(indx, values);
}

void
ppb_opengles2_VertexAttrib2f(PP_Resource context, GLuint indx, GLfloat x, GLfloat y)
{
    setup_ctx(context);
    glVertexAttrib2f(indx, x, y);
}

void
ppb_opengles2_VertexAttrib2fv(PP_Resource context, GLuint indx, const GLfloat *values)
{
    setup_ctx(context);
    glVertexAttrib2fv(indx, values);
}

void
ppb_opengles2_VertexAttrib3f(PP_Resource context, GLuint indx, GLfloat x, GLfloat y, GLfloat z)
{
    setup_ctx(context);
    glVertexAttrib3f(indx, x, y, z);
}

void
ppb_opengles2_VertexAttrib3fv(PP_Resource context, GLuint indx, const GLfloat *values)
{
    setup_ctx(context);
    glVertexAttrib3fv(indx, values);
}

void
ppb_opengles2_VertexAttrib4f(PP_Resource context, GLuint indx, GLfloat x, GLfloat y, GLfloat z,
                             GLfloat w)
{
    setup_ctx(context);
    glVertexAttrib4f(indx, x, y, z, w);
}

void
ppb_opengles2_VertexAttrib4fv(PP_Resource context, GLuint indx, const GLfloat *values)
{
    setup_ctx(context);
    glVertexAttrib4fv(indx, values);
}

void
ppb_opengles2_VertexAttribPointer(PP_Resource context, GLuint indx, GLint size, GLenum type,
                                  GLboolean normalized, GLsizei stride, const void *ptr)
{
    setup_ctx(context);
    glVertexAttribPointer(indx, size, type, normalized, stride, ptr);
}

void
ppb_opengles2_Viewport(PP_Resource context, GLint x, GLint y, GLsizei width, GLsizei height)
{
    setup_ctx(context);
    glViewport(x, y, width, height);
}

GLboolean
ppb_opengles2_chromium_enable_feature_enable_feature_chromium(PP_Resource context,
                                                              const char *feature)
{
    return PP_FALSE;
}

void *
ppb_opengles2_chromium_map_sub_map_buffer_sub_data_chromium(PP_Resource context, GLuint target,
                                                            GLintptr offset, GLsizeiptr size,
                                                            GLenum access)
{
    return NULL;
}

void
ppb_opengles2_chromium_map_sub_unmap_buffer_sub_data_chromium(PP_Resource context, const void *mem)
{
}

void *
ppb_opengles2_chromium_map_sub_map_tex_sub_image_2d_chromium(PP_Resource context, GLenum target,
                                                             GLint level, GLint xoffset,
                                                             GLint yoffset, GLsizei width,
                                                             GLsizei height, GLenum format,
                                                             GLenum type, GLenum access)
{
    if (target != GL_TEXTURE_2D || level != 0 || access != GL_WRITE_ONLY) {
        trace_warning("%s, wrong arguments\n", __func__);
        return NULL;
    }

    struct pp_graphics3d_s *g3d = pp_resource_acquire(context, PP_RESOURCE_GRAPHICS3D);
    if (!g3d) {
        trace_warning("%s, wrong context\n", __func__);
        return NULL;
    }

    g3d->sub_map_bytes_per_pixel = (GL_RGB == format) ? 3 : 4;
    void *res = malloc(width * height * g3d->sub_map_bytes_per_pixel);
    g3d->sub_map_xoffset = xoffset;
    g3d->sub_map_yoffset = yoffset;
    g3d->sub_map_width = width;
    g3d->sub_map_height = height;
    pp_resource_release(context);

    return res;
}

void
ppb_opengles2_chromium_map_sub_unmap_tex_sub_image_2d_chromium(PP_Resource context,
                                                               const void *mem)
{
    struct pp_graphics3d_s *g3d = pp_resource_acquire(context, PP_RESOURCE_GRAPHICS3D);
    if (!g3d) {
        trace_warning("%s, wrong context\n", __func__);
        return;
    }

    XImage *xi = XCreateImage(g3d->dpy, DefaultVisual(g3d->dpy, 0), 24, ZPixmap, 0, (void *)mem,
                              g3d->sub_map_width, g3d->sub_map_height,
                              g3d->sub_map_bytes_per_pixel * 4,
                              g3d->sub_map_width * g3d->sub_map_bytes_per_pixel);

    XPutImage(g3d->dpy, g3d->pixmap, DefaultGC(g3d->dpy, 0), xi, 0, 0,
              g3d->sub_map_xoffset, g3d->sub_map_yoffset,
              g3d->sub_map_width, g3d->sub_map_height);
    free(xi);
    XSync(g3d->dpy, False);

    pp_resource_release(context);
    free((void *)mem);
}

void
ppb_opengles2_framebuffer_blit_blit_framebuffer_ext(PP_Resource context, GLint srcX0, GLint srcY0,
                                                    GLint srcX1, GLint srcY1, GLint dstX0,
                                                    GLint dstY0, GLint dstX1, GLint dstY1,
                                                    GLbitfield mask, GLenum filter)
{
}

void
ppb_opengles2_framebuffer_multisample_renderbuffer_storage_multisample_ext
                    (PP_Resource context, GLenum target, GLsizei samples, GLenum internalformat,
                     GLsizei width, GLsizei height)
{
}

void
ppb_opengles2_instanced_arrays_draw_arrays_instanced_angle(PP_Resource context, GLenum mode,
                                                           GLint first, GLsizei count,
                                                           GLsizei primcount)
{
}

void
ppb_opengles2_instanced_arrays_draw_elements_instanced_angle(PP_Resource context, GLenum mode,
                                                             GLsizei count, GLenum type,
                                                             const void *indices, GLsizei primcount)
{
}

void
ppb_opengles2_instanced_arrays_vertex_attrib_divisor_angle(PP_Resource context, GLuint index,
                                                           GLuint divisor)
{
}

void
ppb_opengles2_query_gen_queries_ext(PP_Resource context, GLsizei n, GLuint *queries)
{
}

void
ppb_opengles2_query_delete_queries_ext(PP_Resource context, GLsizei n, const GLuint *queries)
{
}

GLboolean
ppb_opengles2_query_is_query_ext(PP_Resource context, GLuint id)
{
    return PP_TRUE;
}

void
ppb_opengles2_query_begin_query_ext(PP_Resource context, GLenum target, GLuint id)
{
}

void
ppb_opengles2_query_end_query_ext(PP_Resource context, GLenum target)
{
}

void
ppb_opengles2_query_get_queryiv_ext(PP_Resource context, GLenum target, GLenum pname, GLint *params)
{
}

void
ppb_opengles2_query_get_query_objectuiv_ext(PP_Resource context, GLuint id, GLenum pname,
                                            GLuint *params)
{
}


// trace wrappers
static
void
trace_ppb_opengles2_ActiveTexture(PP_Resource context, GLenum texture)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_ActiveTexture(context, texture);
}

static
void
trace_ppb_opengles2_AttachShader(PP_Resource context, GLuint program, GLuint shader)
{
    trace_info("[PPB] {full} %s context=%d, program=%d, shader=%d\n", __func__+6, context,
               program, shader);
    ppb_opengles2_AttachShader(context, program, shader);
}

static
void
trace_ppb_opengles2_BindAttribLocation(PP_Resource context, GLuint program, GLuint index,
                                       const char *name)
{
    trace_info("[PPB] {full} %s context=%d, program=%d, index=%d, name=%s\n", __func__+6,
               context, program, index, name);
    ppb_opengles2_BindAttribLocation(context, program, index, name);
}

static
void
trace_ppb_opengles2_BindBuffer(PP_Resource context, GLenum target, GLuint buffer)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_BindBuffer(context, target, buffer);
}

static
void
trace_ppb_opengles2_BindFramebuffer(PP_Resource context, GLenum target, GLuint framebuffer)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_BindFramebuffer(context, target, framebuffer);
}

static
void
trace_ppb_opengles2_BindRenderbuffer(PP_Resource context, GLenum target, GLuint renderbuffer)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_BindRenderbuffer(context, target, renderbuffer);
}

static
void
trace_ppb_opengles2_BindTexture(PP_Resource context, GLenum target, GLuint texture)
{
    trace_info("[PPB] {full} %s context=%d, target=0x%x, texture=%d\n", __func__+6, context,
               target, texture);
    ppb_opengles2_BindTexture(context, target, texture);
}

static
void
trace_ppb_opengles2_BlendColor(PP_Resource context, GLclampf red, GLclampf green, GLclampf blue,
                               GLclampf alpha)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_BlendColor(context, red, green, blue, alpha);
}

static
void
trace_ppb_opengles2_BlendEquation(PP_Resource context, GLenum mode)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_BlendEquation(context, mode);
}

static
void
trace_ppb_opengles2_BlendEquationSeparate(PP_Resource context, GLenum modeRGB, GLenum modeAlpha)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_BlendEquationSeparate(context, modeRGB, modeAlpha);
}

static
void
trace_ppb_opengles2_BlendFunc(PP_Resource context, GLenum sfactor, GLenum dfactor)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_BlendFunc(context, sfactor, dfactor);
}

static
void
trace_ppb_opengles2_BlendFuncSeparate(PP_Resource context, GLenum srcRGB, GLenum dstRGB,
                                      GLenum srcAlpha, GLenum dstAlpha)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_BlendFuncSeparate(context, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

static
void
trace_ppb_opengles2_BufferData(PP_Resource context, GLenum target, GLsizeiptr size,
                               const void *data, GLenum usage)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_BufferData(context, target, size, data, usage);
}

static
void
trace_ppb_opengles2_BufferSubData(PP_Resource context, GLenum target, GLintptr offset,
                                  GLsizeiptr size, const void *data)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_BufferSubData(context, target, offset, size, data);
}

static
GLenum
trace_ppb_opengles2_CheckFramebufferStatus(PP_Resource context, GLenum target)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    return ppb_opengles2_CheckFramebufferStatus(context, target);
}

static
void
trace_ppb_opengles2_Clear(PP_Resource context, GLbitfield mask)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Clear(context, mask);
}

static
void
trace_ppb_opengles2_ClearColor(PP_Resource context, GLclampf red, GLclampf green, GLclampf blue,
                               GLclampf alpha)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_ClearColor(context, red, green, blue, alpha);
}

static
void
trace_ppb_opengles2_ClearDepthf(PP_Resource context, GLclampf depth)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_ClearDepthf(context, depth);
}

static
void
trace_ppb_opengles2_ClearStencil(PP_Resource context, GLint s)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_ClearStencil(context, s);
}

static
void
trace_ppb_opengles2_ColorMask(PP_Resource context, GLboolean red, GLboolean green, GLboolean blue,
                              GLboolean alpha)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_ColorMask(context, red, green, blue, alpha);
}

static
void
trace_ppb_opengles2_CompileShader(PP_Resource context, GLuint shader)
{
    trace_info("[PPB] {full} %s context=%d, shader=%d\n", __func__+6, context, shader);
    ppb_opengles2_CompileShader(context, shader);
}

static
void
trace_ppb_opengles2_CompressedTexImage2D(PP_Resource context, GLenum target, GLint level,
                                         GLenum internalformat, GLsizei width, GLsizei height,
                                         GLint border, GLsizei imageSize, const void *data)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_CompressedTexImage2D(context, target, level, internalformat, width, height,
                                       border, imageSize, data);
}

static
void
trace_ppb_opengles2_CompressedTexSubImage2D(PP_Resource context, GLenum target, GLint level,
                                            GLint xoffset, GLint yoffset, GLsizei width,
                                            GLsizei height, GLenum format, GLsizei imageSize,
                                            const void *data)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_CompressedTexSubImage2D(context, target, level, xoffset, yoffset, width, height,
                                          format, imageSize, data);
}

static
void
trace_ppb_opengles2_CopyTexImage2D(PP_Resource context, GLenum target, GLint level,
                                   GLenum internalformat, GLint x, GLint y, GLsizei width,
                                   GLsizei height, GLint border)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_CopyTexImage2D(context, target, level, internalformat, x, y, width, height,
                                 border);
}

static
void
trace_ppb_opengles2_CopyTexSubImage2D(PP_Resource context, GLenum target, GLint level,
                                      GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width,
                                      GLsizei height)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_CopyTexSubImage2D(context, target, level, xoffset, yoffset, x, y, width, height);
}

static
GLuint
trace_ppb_opengles2_CreateProgram(PP_Resource context)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    return ppb_opengles2_CreateProgram(context);
}

static
GLuint
trace_ppb_opengles2_CreateShader(PP_Resource context, GLenum type)
{
    trace_info("[PPB] {full} %s context=%d type=0x%x\n", __func__+6, context, type);
    return ppb_opengles2_CreateShader(context, type);
}

static
void
trace_ppb_opengles2_CullFace(PP_Resource context, GLenum mode)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_CullFace(context, mode);
}

static
void
trace_ppb_opengles2_DeleteBuffers(PP_Resource context, GLsizei n, const GLuint *buffers)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_DeleteBuffers(context, n, buffers);
}

static
void
trace_ppb_opengles2_DeleteFramebuffers(PP_Resource context, GLsizei n, const GLuint *framebuffers)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_DeleteFramebuffers(context, n, framebuffers);
}

static
void
trace_ppb_opengles2_DeleteProgram(PP_Resource context, GLuint program)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_DeleteProgram(context, program);
}

static
void
trace_ppb_opengles2_DeleteRenderbuffers(PP_Resource context, GLsizei n, const GLuint *renderbuffers)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_DeleteRenderbuffers(context, n, renderbuffers);
}

static
void
trace_ppb_opengles2_DeleteShader(PP_Resource context, GLuint shader)
{
    trace_info("[PPB] {full} %s context=%d, shader=%d\n", __func__+6, context, shader);
    ppb_opengles2_DeleteShader(context, shader);
}

static
void
trace_ppb_opengles2_DeleteTextures(PP_Resource context, GLsizei n, const GLuint *textures)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_DeleteTextures(context, n, textures);
}

static
void
trace_ppb_opengles2_DepthFunc(PP_Resource context, GLenum func)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_DepthFunc(context, func);
}

static
void
trace_ppb_opengles2_DepthMask(PP_Resource context, GLboolean flag)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_DepthMask(context, flag);
}

static
void
trace_ppb_opengles2_DepthRangef(PP_Resource context, GLclampf zNear, GLclampf zFar)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_DepthRangef(context, zNear, zFar);
}

static
void
trace_ppb_opengles2_DetachShader(PP_Resource context, GLuint program, GLuint shader)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_DetachShader(context, program, shader);
}

static
void
trace_ppb_opengles2_Disable(PP_Resource context, GLenum cap)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Disable(context, cap);
}

static
void
trace_ppb_opengles2_DisableVertexAttribArray(PP_Resource context, GLuint index)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_DisableVertexAttribArray(context, index);
}

static
void
trace_ppb_opengles2_DrawArrays(PP_Resource context, GLenum mode, GLint first, GLsizei count)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_DrawArrays(context, mode, first, count);
}

static
void
trace_ppb_opengles2_DrawElements(PP_Resource context, GLenum mode, GLsizei count, GLenum type,
                                 const void *indices)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_DrawElements(context, mode, count, type, indices);
}

static
void
trace_ppb_opengles2_Enable(PP_Resource context, GLenum cap)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Enable(context, cap);
}

static
void
trace_ppb_opengles2_EnableVertexAttribArray(PP_Resource context, GLuint index)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_EnableVertexAttribArray(context, index);
}

static
void
trace_ppb_opengles2_Finish(PP_Resource context)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Finish(context);
}

static
void
trace_ppb_opengles2_Flush(PP_Resource context)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Flush(context);
}

static
void
trace_ppb_opengles2_FramebufferRenderbuffer(PP_Resource context, GLenum target, GLenum attachment,
                                            GLenum renderbuffertarget, GLuint renderbuffer)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_FramebufferRenderbuffer(context, target, attachment, renderbuffertarget,
                                          renderbuffer);
}

static
void
trace_ppb_opengles2_FramebufferTexture2D(PP_Resource context, GLenum target, GLenum attachment,
                                         GLenum textarget, GLuint texture, GLint level)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_FramebufferTexture2D(context, target, attachment, textarget, texture, level);
}

static
void
trace_ppb_opengles2_FrontFace(PP_Resource context, GLenum mode)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_FrontFace(context, mode);
}

static
void
trace_ppb_opengles2_GenBuffers(PP_Resource context, GLsizei n, GLuint *buffers)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GenBuffers(context, n, buffers);
}

static
void
trace_ppb_opengles2_GenerateMipmap(PP_Resource context, GLenum target)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GenerateMipmap(context, target);
}

static
void
trace_ppb_opengles2_GenFramebuffers(PP_Resource context, GLsizei n, GLuint *framebuffers)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GenFramebuffers(context, n, framebuffers);
}

static
void
trace_ppb_opengles2_GenRenderbuffers(PP_Resource context, GLsizei n, GLuint *renderbuffers)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GenRenderbuffers(context, n, renderbuffers);
}

static
void
trace_ppb_opengles2_GenTextures(PP_Resource context, GLsizei n, GLuint *textures)
{
    trace_info("[PPB] {full} %s context=%d, n=%d\n", __func__+6, context, n);
    ppb_opengles2_GenTextures(context, n, textures);
}

static
void
trace_ppb_opengles2_GetActiveAttrib(PP_Resource context, GLuint program, GLuint index,
                                    GLsizei bufsize, GLsizei *length, GLint *size, GLenum *type,
                                    char *name)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GetActiveAttrib(context, program, index, bufsize, length, size, type, name);
}

static
void
trace_ppb_opengles2_GetActiveUniform(PP_Resource context, GLuint program, GLuint index,
                                     GLsizei bufsize, GLsizei *length, GLint *size, GLenum *type,
                                     char *name)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GetActiveUniform(context, program, index, bufsize, length, size, type, name);
}

static
void
trace_ppb_opengles2_GetAttachedShaders(PP_Resource context, GLuint program, GLsizei maxcount,
                                       GLsizei *count, GLuint *shaders)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GetAttachedShaders(context, program, maxcount, count, shaders);
}

static
GLint
trace_ppb_opengles2_GetAttribLocation(PP_Resource context, GLuint program, const char *name)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    return ppb_opengles2_GetAttribLocation(context, program, name);
}

static
void
trace_ppb_opengles2_GetBooleanv(PP_Resource context, GLenum pname, GLboolean *params)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GetBooleanv(context, pname, params);
}

static
void
trace_ppb_opengles2_GetBufferParameteriv(PP_Resource context, GLenum target, GLenum pname,
                                         GLint *params)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GetBufferParameteriv(context, target, pname, params);
}

static
GLenum
trace_ppb_opengles2_GetError(PP_Resource context)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    return ppb_opengles2_GetError(context);
}

static
void
trace_ppb_opengles2_GetFloatv(PP_Resource context, GLenum pname, GLfloat *params)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GetFloatv(context, pname, params);
}

static
void
trace_ppb_opengles2_GetFramebufferAttachmentParameteriv(PP_Resource context, GLenum target,
                                                        GLenum attachment, GLenum pname,
                                                        GLint *params)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GetFramebufferAttachmentParameteriv(context, target, attachment, pname, params);
}

static
void
trace_ppb_opengles2_GetIntegerv(PP_Resource context, GLenum pname, GLint *params)
{
    trace_info("[PPB] {full} %s context=%d, pname=0x%x\n", __func__+6, context, pname);
    ppb_opengles2_GetIntegerv(context, pname, params);
}

static
void
trace_ppb_opengles2_GetProgramiv(PP_Resource context, GLuint program, GLenum pname, GLint *params)
{
    trace_info("[PPB] {full} %s context=%d, program=%d, pname=0x%x\n", __func__+6, context,
               program, pname);
    ppb_opengles2_GetProgramiv(context, program, pname, params);
}

static
void
trace_ppb_opengles2_GetProgramInfoLog(PP_Resource context, GLuint program, GLsizei bufsize,
                                GLsizei *length, char *infolog)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GetProgramInfoLog(context, program, bufsize, length, infolog);
}

static
void
trace_ppb_opengles2_GetRenderbufferParameteriv(PP_Resource context, GLenum target, GLenum pname,
                                               GLint *params)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GetRenderbufferParameteriv(context, target, pname, params);
}

static
void
trace_ppb_opengles2_GetShaderiv(PP_Resource context, GLuint shader, GLenum pname, GLint *params)
{
    trace_info("[PPB] {full} %s context=%d, shader=%d, pname=0x%x\n", __func__+6, context,
               shader, pname);
    ppb_opengles2_GetShaderiv(context, shader, pname, params);
}

static
void
trace_ppb_opengles2_GetShaderInfoLog(PP_Resource context, GLuint shader, GLsizei bufsize,
                                     GLsizei *length, char *infolog)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GetShaderInfoLog(context, shader, bufsize, length, infolog);
}

static
void
trace_ppb_opengles2_GetShaderPrecisionFormat(PP_Resource context, GLenum shadertype,
                                             GLenum precisiontype, GLint *range, GLint *precision)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GetShaderPrecisionFormat(context, shadertype, precisiontype, range, precision);
}

static
void
trace_ppb_opengles2_GetShaderSource(PP_Resource context, GLuint shader, GLsizei bufsize,
                                    GLsizei *length, char *source)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GetShaderSource(context, shader, bufsize, length, source);
}

static
const GLubyte*
trace_ppb_opengles2_GetString(PP_Resource context, GLenum name)
{
    trace_info("[PPB] {full} %s context=%d name=0x%x\n", __func__+6, context, name);
    return ppb_opengles2_GetString(context, name);
}

static
void
trace_ppb_opengles2_GetTexParameterfv(PP_Resource context, GLenum target, GLenum pname,
                                      GLfloat *params)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GetTexParameterfv(context, target, pname, params);
}

static
void
trace_ppb_opengles2_GetTexParameteriv(PP_Resource context, GLenum target, GLenum pname,
                                      GLint *params)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GetTexParameteriv(context, target, pname, params);
}

static
void
trace_ppb_opengles2_GetUniformfv(PP_Resource context, GLuint program, GLint location,
                                 GLfloat *params)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GetUniformfv(context, program, location, params);
}

static
void
trace_ppb_opengles2_GetUniformiv(PP_Resource context, GLuint program, GLint location, GLint *params)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GetUniformiv(context, program, location, params);
}

static
GLint
trace_ppb_opengles2_GetUniformLocation(PP_Resource context, GLuint program, const char *name)
{
    trace_info("[PPB] {full} %s context=%d, program=%d, name=%s\n", __func__+6, context,
               program, name);
    return ppb_opengles2_GetUniformLocation(context, program, name);
}

static
void
trace_ppb_opengles2_GetVertexAttribfv(PP_Resource context, GLuint index, GLenum pname,
                                      GLfloat *params)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GetVertexAttribfv(context, index, pname, params);
}

static
void
trace_ppb_opengles2_GetVertexAttribiv(PP_Resource context, GLuint index, GLenum pname,
                                      GLint *params)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GetVertexAttribiv(context, index, pname, params);
}

static
void
trace_ppb_opengles2_GetVertexAttribPointerv(PP_Resource context, GLuint index, GLenum pname,
                                            void **pointer)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_GetVertexAttribPointerv(context, index, pname, pointer);
}

static
void
trace_ppb_opengles2_Hint(PP_Resource context, GLenum target, GLenum mode)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Hint(context, target, mode);
}

static
GLboolean
trace_ppb_opengles2_IsBuffer(PP_Resource context, GLuint buffer)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    return ppb_opengles2_IsBuffer(context, buffer);
}

static
GLboolean
trace_ppb_opengles2_IsEnabled(PP_Resource context, GLenum cap)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    return ppb_opengles2_IsEnabled(context, cap);
}

static
GLboolean
trace_ppb_opengles2_IsFramebuffer(PP_Resource context, GLuint framebuffer)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    return ppb_opengles2_IsFramebuffer(context, framebuffer);
}

static
GLboolean
trace_ppb_opengles2_IsProgram(PP_Resource context, GLuint program)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    return ppb_opengles2_IsProgram(context, program);
}

static
GLboolean
trace_ppb_opengles2_IsRenderbuffer(PP_Resource context, GLuint renderbuffer)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    return ppb_opengles2_IsRenderbuffer(context, renderbuffer);
}

static
GLboolean
trace_ppb_opengles2_IsShader(PP_Resource context, GLuint shader)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    return ppb_opengles2_IsShader(context, shader);
}

static
GLboolean
trace_ppb_opengles2_IsTexture(PP_Resource context, GLuint texture)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    return ppb_opengles2_IsTexture(context, texture);
}

static
void
trace_ppb_opengles2_LineWidth(PP_Resource context, GLfloat width)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_LineWidth(context, width);
}

static
void
trace_ppb_opengles2_LinkProgram(PP_Resource context, GLuint program)
{
    trace_info("[PPB] {full} %s context=%d, program=%d\n", __func__+6, context, program);
    ppb_opengles2_LinkProgram(context, program);
}

static
void
trace_ppb_opengles2_PixelStorei(PP_Resource context, GLenum pname, GLint param)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_PixelStorei(context, pname, param);
}

static
void
trace_ppb_opengles2_PolygonOffset(PP_Resource context, GLfloat factor, GLfloat units)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_PolygonOffset(context, factor, units);
}

static
void
trace_ppb_opengles2_ReadPixels(PP_Resource context, GLint x, GLint y, GLsizei width, GLsizei height,
                               GLenum format, GLenum type, void *pixels)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_ReadPixels(context, x, y, width, height, format, type, pixels);
}

static
void
trace_ppb_opengles2_ReleaseShaderCompiler(PP_Resource context)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_ReleaseShaderCompiler(context);
}

static
void
trace_ppb_opengles2_RenderbufferStorage(PP_Resource context, GLenum target, GLenum internalformat,
                                        GLsizei width, GLsizei height)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_RenderbufferStorage(context, target, internalformat, width, height);
}

static
void
trace_ppb_opengles2_SampleCoverage(PP_Resource context, GLclampf value, GLboolean invert)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_SampleCoverage(context, value, invert);
}

static
void
trace_ppb_opengles2_Scissor(PP_Resource context, GLint x, GLint y, GLsizei width, GLsizei height)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Scissor(context, x, y, width, height);
}

static
void
trace_ppb_opengles2_ShaderBinary(PP_Resource context, GLsizei n, const GLuint *shaders,
                                 GLenum binaryformat, const void *binary, GLsizei length)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_ShaderBinary(context, n, shaders, binaryformat, binary, length);
}

static
void
trace_ppb_opengles2_ShaderSource(PP_Resource context, GLuint shader, GLsizei count,
                                 const char **str, const GLint *length)
{
    trace_info("[PPB] {full} %s context=%d, shader=%d, count=%d, str=%p, length=%p\n",
               __func__+6, context, shader, count, str, length);
    for (size_t k = 0; k < count; k++) {
        trace_info("             shader_source[%u] = \n%s\n", (unsigned)k, str[k]);
    }
    ppb_opengles2_ShaderSource(context, shader, count, str, length);
}

static
void
trace_ppb_opengles2_StencilFunc(PP_Resource context, GLenum func, GLint ref, GLuint mask)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_StencilFunc(context, func, ref, mask);
}

static
void
trace_ppb_opengles2_StencilFuncSeparate(PP_Resource context, GLenum face, GLenum func, GLint ref,
                                        GLuint mask)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_StencilFuncSeparate(context, face, func, ref, mask);
}

static
void
trace_ppb_opengles2_StencilMask(PP_Resource context, GLuint mask)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_StencilMask(context, mask);
}

static
void
trace_ppb_opengles2_StencilMaskSeparate(PP_Resource context, GLenum face, GLuint mask)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_StencilMaskSeparate(context, face, mask);
}

static
void
trace_ppb_opengles2_StencilOp(PP_Resource context, GLenum fail, GLenum zfail, GLenum zpass)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_StencilOp(context, fail, zfail, zpass);
}

static
void
trace_ppb_opengles2_StencilOpSeparate(PP_Resource context, GLenum face, GLenum fail, GLenum zfail,
                                      GLenum zpass)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_StencilOpSeparate(context, face, fail, zfail, zpass);
}

static
void
trace_ppb_opengles2_TexImage2D(PP_Resource context, GLenum target, GLint level,
                               GLint internalformat, GLsizei width, GLsizei height, GLint border,
                               GLenum format, GLenum type, const void *pixels)
{
    trace_info("[PPB] {full} %s context=%d, target=0x%x, level=%d, internalformat=0x%x, width=%d, "
               "height=%d, border=%d, format=0x%x, type=0x%x\n", __func__+6, context, target,
               level, internalformat, width, height, border, format, type);
    ppb_opengles2_TexImage2D(context, target, level, internalformat, width, height, border, format,
                             type, pixels);
}

static
void
trace_ppb_opengles2_TexParameterf(PP_Resource context, GLenum target, GLenum pname, GLfloat param)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_TexParameterf(context, target, pname, param);
}

static
void
trace_ppb_opengles2_TexParameterfv(PP_Resource context, GLenum target, GLenum pname,
                                   const GLfloat *params)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_TexParameterfv(context, target, pname, params);
}

static
void
trace_ppb_opengles2_TexParameteri(PP_Resource context, GLenum target, GLenum pname, GLint param)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_TexParameteri(context, target, pname, param);
}

static
void
trace_ppb_opengles2_TexParameteriv(PP_Resource context, GLenum target, GLenum pname,
                                   const GLint *params)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_TexParameteriv(context, target, pname, params);
}

static
void
trace_ppb_opengles2_TexSubImage2D(PP_Resource context, GLenum target, GLint level, GLint xoffset,
                                  GLint yoffset, GLsizei width, GLsizei height, GLenum format,
                                  GLenum type, const void *pixels)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_TexSubImage2D(context, target, level, xoffset, yoffset, width, height, format,
                                type, pixels);
}

static
void
trace_ppb_opengles2_Uniform1f(PP_Resource context, GLint location, GLfloat x)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Uniform1f(context, location, x);
}

static
void
trace_ppb_opengles2_Uniform1fv(PP_Resource context, GLint location, GLsizei count, const GLfloat *v)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Uniform1fv(context, location, count, v);
}

static
void
trace_ppb_opengles2_Uniform1i(PP_Resource context, GLint location, GLint x)
{
    trace_info("[PPB] {full} %s context=%d, location=%d, x=%d\n", __func__+6, context, location, x);
    ppb_opengles2_Uniform1i(context, location, x);
}

static
void
trace_ppb_opengles2_Uniform1iv(PP_Resource context, GLint location, GLsizei count, const GLint *v)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Uniform1iv(context, location, count, v);
}

static
void
trace_ppb_opengles2_Uniform2f(PP_Resource context, GLint location, GLfloat x, GLfloat y)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Uniform2f(context, location, x, y);
}

static
void
trace_ppb_opengles2_Uniform2fv(PP_Resource context, GLint location, GLsizei count, const GLfloat *v)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Uniform2fv(context, location, count, v);
}

static
void
trace_ppb_opengles2_Uniform2i(PP_Resource context, GLint location, GLint x, GLint y)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Uniform2i(context, location, x, y);
}

static
void
trace_ppb_opengles2_Uniform2iv(PP_Resource context, GLint location, GLsizei count, const GLint *v)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Uniform2iv(context, location, count, v);
}

static
void
trace_ppb_opengles2_Uniform3f(PP_Resource context, GLint location, GLfloat x, GLfloat y, GLfloat z)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Uniform3f(context, location, x, y, z);
}

static
void
trace_ppb_opengles2_Uniform3fv(PP_Resource context, GLint location, GLsizei count, const GLfloat *v)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Uniform3fv(context, location, count, v);
}

static
void
trace_ppb_opengles2_Uniform3i(PP_Resource context, GLint location, GLint x, GLint y, GLint z)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Uniform3i(context, location, x, y, z);
}

static
void
trace_ppb_opengles2_Uniform3iv(PP_Resource context, GLint location, GLsizei count, const GLint *v)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Uniform3iv(context, location, count, v);
}

static
void
trace_ppb_opengles2_Uniform4f(PP_Resource context, GLint location, GLfloat x, GLfloat y, GLfloat z,
                              GLfloat w)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Uniform4f(context, location, x, y, z, w);
}

static
void
trace_ppb_opengles2_Uniform4fv(PP_Resource context, GLint location, GLsizei count, const GLfloat *v)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Uniform4fv(context, location, count, v);
}

static
void
trace_ppb_opengles2_Uniform4i(PP_Resource context, GLint location, GLint x, GLint y, GLint z,
                              GLint w)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Uniform4i(context, location, x, y, z, w);
}

static
void
trace_ppb_opengles2_Uniform4iv(PP_Resource context, GLint location, GLsizei count, const GLint *v)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Uniform4iv(context, location, count, v);
}

static
void
trace_ppb_opengles2_UniformMatrix2fv(PP_Resource context, GLint location, GLsizei count,
                                     GLboolean transpose, const GLfloat *value)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_UniformMatrix2fv(context, location, count, transpose, value);
}

static
void
trace_ppb_opengles2_UniformMatrix3fv(PP_Resource context, GLint location, GLsizei count,
                                     GLboolean transpose, const GLfloat *value)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_UniformMatrix3fv(context, location, count, transpose, value);
}

static
void
trace_ppb_opengles2_UniformMatrix4fv(PP_Resource context, GLint location, GLsizei count,
                                     GLboolean transpose, const GLfloat *value)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_UniformMatrix4fv(context, location, count, transpose, value);
}

static
void
trace_ppb_opengles2_UseProgram(PP_Resource context, GLuint program)
{
    trace_info("[PPB] {full} %s context=%d, program=%d\n", __func__+6, context, program);
    ppb_opengles2_UseProgram(context, program);
}

static
void
trace_ppb_opengles2_ValidateProgram(PP_Resource context, GLuint program)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_ValidateProgram(context, program);
}

static
void
trace_ppb_opengles2_VertexAttrib1f(PP_Resource context, GLuint indx, GLfloat x)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_VertexAttrib1f(context, indx, x);
}

static
void
trace_ppb_opengles2_VertexAttrib1fv(PP_Resource context, GLuint indx, const GLfloat *values)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_VertexAttrib1fv(context, indx, values);
}

static
void
trace_ppb_opengles2_VertexAttrib2f(PP_Resource context, GLuint indx, GLfloat x, GLfloat y)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_VertexAttrib2f(context, indx, x, y);
}

static
void
trace_ppb_opengles2_VertexAttrib2fv(PP_Resource context, GLuint indx, const GLfloat *values)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_VertexAttrib2fv(context, indx, values);
}

static
void
trace_ppb_opengles2_VertexAttrib3f(PP_Resource context, GLuint indx, GLfloat x, GLfloat y,
                                   GLfloat z)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_VertexAttrib3f(context, indx, x, y, z);
}

static
void
trace_ppb_opengles2_VertexAttrib3fv(PP_Resource context, GLuint indx, const GLfloat *values)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_VertexAttrib3fv(context, indx, values);
}

static
void
trace_ppb_opengles2_VertexAttrib4f(PP_Resource context, GLuint indx, GLfloat x, GLfloat y,
                                   GLfloat z, GLfloat w)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_VertexAttrib4f(context, indx, x, y, z, w);
}

static
void
trace_ppb_opengles2_VertexAttrib4fv(PP_Resource context, GLuint indx, const GLfloat *values)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_VertexAttrib4fv(context, indx, values);
}

static
void
trace_ppb_opengles2_VertexAttribPointer(PP_Resource context, GLuint indx, GLint size, GLenum type,
                                        GLboolean normalized, GLsizei stride, const void *ptr)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_VertexAttribPointer(context, indx, size, type, normalized, stride, ptr);
}

static
void
trace_ppb_opengles2_Viewport(PP_Resource context, GLint x, GLint y, GLsizei width, GLsizei height)
{
    trace_info("[PPB] {full} %s context=%d\n", __func__+6, context);
    ppb_opengles2_Viewport(context, x, y, width, height);
}

static
GLboolean
trace_ppb_opengles2_chromium_enable_feature_enable_feature_chromium(PP_Resource context,
                                                                    const char *feature)
{
    trace_info("[PPB] {zilch} %s\n", __func__+6);
    return ppb_opengles2_chromium_enable_feature_enable_feature_chromium(context, feature);
}

static
void *
trace_ppb_opengles2_chromium_map_sub_map_buffer_sub_data_chromium(PP_Resource context,
                                                                  GLuint target, GLintptr offset,
                                                                  GLsizeiptr size, GLenum access)
{
    trace_info("[PPB] {zilch} %s context=%d, target=%u, offset=%d, size=%u, access=%d\n",
               __func__+6, context, target, (int)offset, (unsigned int)size, access);
    return ppb_opengles2_chromium_map_sub_map_buffer_sub_data_chromium(context, target, offset,
                                                                       size, access);
}

static
void
trace_ppb_opengles2_chromium_map_sub_unmap_buffer_sub_data_chromium(PP_Resource context,
                                                                    const void *mem)
{
    trace_info("[PPB] {zilch} %s context=%d, mem=%p\n", __func__+6, context, mem);
    ppb_opengles2_chromium_map_sub_unmap_buffer_sub_data_chromium(context, mem);
}

static
void *
trace_ppb_opengles2_chromium_map_sub_map_tex_sub_image_2d_chromium(PP_Resource context,
                                                                   GLenum target, GLint level,
                                                                   GLint xoffset, GLint yoffset,
                                                                   GLsizei width, GLsizei height,
                                                                   GLenum format, GLenum type,
                                                                   GLenum access)
{
    trace_info("[PPB] {full} %s context=%d, target=%d, level=%d, xoffset=%d, yoffset=%d, "
               "width=%u, height=%u, format=%d, type=%d, access=%d\n", __func__+6, context, target,
               level, xoffset, yoffset, width, height, format, type, access);
    return ppb_opengles2_chromium_map_sub_map_tex_sub_image_2d_chromium(context, target, level,
                                        xoffset, yoffset, width, height, format, type, access);
}

static
void
trace_ppb_opengles2_chromium_map_sub_unmap_tex_sub_image_2d_chromium(PP_Resource context,
                                                                     const void *mem)
{
    trace_info("[PPB] {full} %s context=%d, mem=%p\n", __func__+6, context, mem);
    ppb_opengles2_chromium_map_sub_unmap_tex_sub_image_2d_chromium(context, mem);
}

static
void
trace_ppb_opengles2_framebuffer_blit_blit_framebuffer_ext(PP_Resource context, GLint srcX0,
                                                          GLint srcY0, GLint srcX1, GLint srcY1,
                                                          GLint dstX0, GLint dstY0, GLint dstX1,
                                                          GLint dstY1, GLbitfield mask,
                                                          GLenum filter)
{
    trace_info("[PPB] {zilch} %s\n", __func__+6);
    return ppb_opengles2_framebuffer_blit_blit_framebuffer_ext(context, srcX0, srcY0, srcX1, srcY1,
                                                               dstX0, dstY0, dstX1, dstY1, mask,
                                                               filter);
}

static
void
trace_ppb_opengles2_framebuffer_multisample_renderbuffer_storage_multisample_ext
                    (PP_Resource context, GLenum target, GLsizei samples, GLenum internalformat,
                     GLsizei width, GLsizei height)
{
    trace_info("[PPB] {zilch} %s\n", __func__+6);
    ppb_opengles2_framebuffer_multisample_renderbuffer_storage_multisample_ext(context, target,
                                                        samples, internalformat, width, height);
}

static
void
trace_ppb_opengles2_instanced_arrays_draw_arrays_instanced_angle(PP_Resource context, GLenum mode,
                                                                 GLint first, GLsizei count,
                                                                 GLsizei primcount)
{
    trace_info("[PPB] {zilch} %s\n", __func__+6);
    ppb_opengles2_instanced_arrays_draw_arrays_instanced_angle(context, mode, first, count,
                                                               primcount);
}


static
void
trace_ppb_opengles2_instanced_arrays_draw_elements_instanced_angle(PP_Resource context, GLenum mode,
                                                                   GLsizei count, GLenum type,
                                                                   const void *indices,
                                                                   GLsizei primcount)
{
    trace_info("[PPB] {zilch} %s\n", __func__+6);
    ppb_opengles2_instanced_arrays_draw_elements_instanced_angle(context, mode, count, type,
                                                                 indices, primcount);
}

static
void
trace_ppb_opengles2_instanced_arrays_vertex_attrib_divisor_angle(PP_Resource context, GLuint index,
                                                                 GLuint divisor)
{
    trace_info("[PPB] {zilch} %s\n", __func__+6);
    ppb_opengles2_instanced_arrays_vertex_attrib_divisor_angle(context, index, divisor);
}

static
void
trace_ppb_opengles2_query_gen_queries_ext(PP_Resource context, GLsizei n, GLuint *queries)
{
    trace_info("[PPB] {zilch} %s\n", __func__+6);
    ppb_opengles2_query_gen_queries_ext(context, n, queries);
}

static
void
trace_ppb_opengles2_query_delete_queries_ext(PP_Resource context, GLsizei n, const GLuint *queries)
{
    trace_info("[PPB] {zilch} %s\n", __func__+6);
    ppb_opengles2_query_delete_queries_ext(context, n, queries);
}

static
GLboolean
trace_ppb_opengles2_query_is_query_ext(PP_Resource context, GLuint id)
{
    trace_info("[PPB] {zilch} %s\n", __func__+6);
    return ppb_opengles2_query_is_query_ext(context, id);
}

static
void
trace_ppb_opengles2_query_begin_query_ext(PP_Resource context, GLenum target, GLuint id)
{
    trace_info("[PPB] {zilch} %s\n", __func__+6);
    ppb_opengles2_query_begin_query_ext(context, target, id);
}

static
void
trace_ppb_opengles2_query_end_query_ext(PP_Resource context, GLenum target)
{
    trace_info("[PPB] {zilch} %s\n", __func__+6);
    ppb_opengles2_query_end_query_ext(context, target);
}

static
void
trace_ppb_opengles2_query_get_queryiv_ext(PP_Resource context, GLenum target, GLenum pname,
                                          GLint *params)
{
    trace_info("[PPB] {zilch} %s\n", __func__+6);
    ppb_opengles2_query_get_queryiv_ext(context, target, pname, params);
}

static
void
trace_ppb_opengles2_query_get_query_objectuiv_ext(PP_Resource context, GLuint id, GLenum pname,
                                                  GLuint *params)
{
    trace_info("[PPB] {zilch} %s\n", __func__+6);
    ppb_opengles2_query_get_query_objectuiv_ext(context, id, pname, params);
}


const struct PPB_OpenGLES2 ppb_opengles2_interface_1_0 = {
    .ActiveTexture =            trace_ppb_opengles2_ActiveTexture,
    .AttachShader =             trace_ppb_opengles2_AttachShader,
    .BindAttribLocation =       trace_ppb_opengles2_BindAttribLocation,
    .BindBuffer =               trace_ppb_opengles2_BindBuffer,
    .BindFramebuffer =          trace_ppb_opengles2_BindFramebuffer,
    .BindRenderbuffer =         trace_ppb_opengles2_BindRenderbuffer,
    .BindTexture =              trace_ppb_opengles2_BindTexture,
    .BlendColor =               trace_ppb_opengles2_BlendColor,
    .BlendEquation =            trace_ppb_opengles2_BlendEquation,
    .BlendEquationSeparate =    trace_ppb_opengles2_BlendEquationSeparate,
    .BlendFunc =                trace_ppb_opengles2_BlendFunc,
    .BlendFuncSeparate =        trace_ppb_opengles2_BlendFuncSeparate,
    .BufferData =               trace_ppb_opengles2_BufferData,
    .BufferSubData =            trace_ppb_opengles2_BufferSubData,
    .CheckFramebufferStatus =   trace_ppb_opengles2_CheckFramebufferStatus,
    .Clear =                    trace_ppb_opengles2_Clear,
    .ClearColor =               trace_ppb_opengles2_ClearColor,
    .ClearDepthf =              trace_ppb_opengles2_ClearDepthf,
    .ClearStencil =             trace_ppb_opengles2_ClearStencil,
    .ColorMask =                trace_ppb_opengles2_ColorMask,
    .CompileShader =            trace_ppb_opengles2_CompileShader,
    .CompressedTexImage2D =     trace_ppb_opengles2_CompressedTexImage2D,
    .CompressedTexSubImage2D =  trace_ppb_opengles2_CompressedTexSubImage2D,
    .CopyTexImage2D =           trace_ppb_opengles2_CopyTexImage2D,
    .CopyTexSubImage2D =        trace_ppb_opengles2_CopyTexSubImage2D,
    .CreateProgram =            trace_ppb_opengles2_CreateProgram,
    .CreateShader =             trace_ppb_opengles2_CreateShader,
    .CullFace =                 trace_ppb_opengles2_CullFace,
    .DeleteBuffers =            trace_ppb_opengles2_DeleteBuffers,
    .DeleteFramebuffers =       trace_ppb_opengles2_DeleteFramebuffers,
    .DeleteProgram =            trace_ppb_opengles2_DeleteProgram,
    .DeleteRenderbuffers =      trace_ppb_opengles2_DeleteRenderbuffers,
    .DeleteShader =             trace_ppb_opengles2_DeleteShader,
    .DeleteTextures =           trace_ppb_opengles2_DeleteTextures,
    .DepthFunc =                trace_ppb_opengles2_DepthFunc,
    .DepthMask =                trace_ppb_opengles2_DepthMask,
    .DepthRangef =              trace_ppb_opengles2_DepthRangef,
    .DetachShader =             trace_ppb_opengles2_DetachShader,
    .Disable =                  trace_ppb_opengles2_Disable,
    .DisableVertexAttribArray = trace_ppb_opengles2_DisableVertexAttribArray,
    .DrawArrays =               trace_ppb_opengles2_DrawArrays,
    .DrawElements =             trace_ppb_opengles2_DrawElements,
    .Enable =                   trace_ppb_opengles2_Enable,
    .EnableVertexAttribArray =  trace_ppb_opengles2_EnableVertexAttribArray,
    .Finish =                   trace_ppb_opengles2_Finish,
    .Flush =                    trace_ppb_opengles2_Flush,
    .FramebufferRenderbuffer =  trace_ppb_opengles2_FramebufferRenderbuffer,
    .FramebufferTexture2D =     trace_ppb_opengles2_FramebufferTexture2D,
    .FrontFace =                trace_ppb_opengles2_FrontFace,
    .GenBuffers =               trace_ppb_opengles2_GenBuffers,
    .GenerateMipmap =           trace_ppb_opengles2_GenerateMipmap,
    .GenFramebuffers =          trace_ppb_opengles2_GenFramebuffers,
    .GenRenderbuffers =         trace_ppb_opengles2_GenRenderbuffers,
    .GenTextures =              trace_ppb_opengles2_GenTextures,
    .GetActiveAttrib =          trace_ppb_opengles2_GetActiveAttrib,
    .GetActiveUniform =         trace_ppb_opengles2_GetActiveUniform,
    .GetAttachedShaders =       trace_ppb_opengles2_GetAttachedShaders,
    .GetAttribLocation =        trace_ppb_opengles2_GetAttribLocation,
    .GetBooleanv =              trace_ppb_opengles2_GetBooleanv,
    .GetBufferParameteriv =     trace_ppb_opengles2_GetBufferParameteriv,
    .GetError =                 trace_ppb_opengles2_GetError,
    .GetFloatv =                trace_ppb_opengles2_GetFloatv,
    .GetFramebufferAttachmentParameteriv = trace_ppb_opengles2_GetFramebufferAttachmentParameteriv,
    .GetIntegerv =              trace_ppb_opengles2_GetIntegerv,
    .GetProgramiv =             trace_ppb_opengles2_GetProgramiv,
    .GetProgramInfoLog =        trace_ppb_opengles2_GetProgramInfoLog,
    .GetRenderbufferParameteriv = trace_ppb_opengles2_GetRenderbufferParameteriv,
    .GetShaderiv =              trace_ppb_opengles2_GetShaderiv,
    .GetShaderInfoLog =         trace_ppb_opengles2_GetShaderInfoLog,
    .GetShaderPrecisionFormat = trace_ppb_opengles2_GetShaderPrecisionFormat,
    .GetShaderSource =          trace_ppb_opengles2_GetShaderSource,
    .GetString =                trace_ppb_opengles2_GetString,
    .GetTexParameterfv =        trace_ppb_opengles2_GetTexParameterfv,
    .GetTexParameteriv =        trace_ppb_opengles2_GetTexParameteriv,
    .GetUniformfv =             trace_ppb_opengles2_GetUniformfv,
    .GetUniformiv =             trace_ppb_opengles2_GetUniformiv,
    .GetUniformLocation =       trace_ppb_opengles2_GetUniformLocation,
    .GetVertexAttribfv =        trace_ppb_opengles2_GetVertexAttribfv,
    .GetVertexAttribiv =        trace_ppb_opengles2_GetVertexAttribiv,
    .GetVertexAttribPointerv =  trace_ppb_opengles2_GetVertexAttribPointerv,
    .Hint =                     trace_ppb_opengles2_Hint,
    .IsBuffer =                 trace_ppb_opengles2_IsBuffer,
    .IsEnabled =                trace_ppb_opengles2_IsEnabled,
    .IsFramebuffer =            trace_ppb_opengles2_IsFramebuffer,
    .IsProgram =                trace_ppb_opengles2_IsProgram,
    .IsRenderbuffer =           trace_ppb_opengles2_IsRenderbuffer,
    .IsShader =                 trace_ppb_opengles2_IsShader,
    .IsTexture =                trace_ppb_opengles2_IsTexture,
    .LineWidth =                trace_ppb_opengles2_LineWidth,
    .LinkProgram =              trace_ppb_opengles2_LinkProgram,
    .PixelStorei =              trace_ppb_opengles2_PixelStorei,
    .PolygonOffset =            trace_ppb_opengles2_PolygonOffset,
    .ReadPixels =               trace_ppb_opengles2_ReadPixels,
    .ReleaseShaderCompiler =    trace_ppb_opengles2_ReleaseShaderCompiler,
    .RenderbufferStorage =      trace_ppb_opengles2_RenderbufferStorage,
    .SampleCoverage =           trace_ppb_opengles2_SampleCoverage,
    .Scissor =                  trace_ppb_opengles2_Scissor,
    .ShaderBinary =             trace_ppb_opengles2_ShaderBinary,
    .ShaderSource =             trace_ppb_opengles2_ShaderSource,
    .StencilFunc =              trace_ppb_opengles2_StencilFunc,
    .StencilFuncSeparate =      trace_ppb_opengles2_StencilFuncSeparate,
    .StencilMask =              trace_ppb_opengles2_StencilMask,
    .StencilMaskSeparate =      trace_ppb_opengles2_StencilMaskSeparate,
    .StencilOp =                trace_ppb_opengles2_StencilOp,
    .StencilOpSeparate =        trace_ppb_opengles2_StencilOpSeparate,
    .TexImage2D =               trace_ppb_opengles2_TexImage2D,
    .TexParameterf =            trace_ppb_opengles2_TexParameterf,
    .TexParameterfv =           trace_ppb_opengles2_TexParameterfv,
    .TexParameteri =            trace_ppb_opengles2_TexParameteri,
    .TexParameteriv =           trace_ppb_opengles2_TexParameteriv,
    .TexSubImage2D =            trace_ppb_opengles2_TexSubImage2D,
    .Uniform1f =                trace_ppb_opengles2_Uniform1f,
    .Uniform1fv =               trace_ppb_opengles2_Uniform1fv,
    .Uniform1i =                trace_ppb_opengles2_Uniform1i,
    .Uniform1iv =               trace_ppb_opengles2_Uniform1iv,
    .Uniform2f =                trace_ppb_opengles2_Uniform2f,
    .Uniform2fv =               trace_ppb_opengles2_Uniform2fv,
    .Uniform2i =                trace_ppb_opengles2_Uniform2i,
    .Uniform2iv =               trace_ppb_opengles2_Uniform2iv,
    .Uniform3f =                trace_ppb_opengles2_Uniform3f,
    .Uniform3fv =               trace_ppb_opengles2_Uniform3fv,
    .Uniform3i =                trace_ppb_opengles2_Uniform3i,
    .Uniform3iv =               trace_ppb_opengles2_Uniform3iv,
    .Uniform4f =                trace_ppb_opengles2_Uniform4f,
    .Uniform4fv =               trace_ppb_opengles2_Uniform4fv,
    .Uniform4i =                trace_ppb_opengles2_Uniform4i,
    .Uniform4iv =               trace_ppb_opengles2_Uniform4iv,
    .UniformMatrix2fv =         trace_ppb_opengles2_UniformMatrix2fv,
    .UniformMatrix3fv =         trace_ppb_opengles2_UniformMatrix3fv,
    .UniformMatrix4fv =         trace_ppb_opengles2_UniformMatrix4fv,
    .UseProgram =               trace_ppb_opengles2_UseProgram,
    .ValidateProgram =          trace_ppb_opengles2_ValidateProgram,
    .VertexAttrib1f =           trace_ppb_opengles2_VertexAttrib1f,
    .VertexAttrib1fv =          trace_ppb_opengles2_VertexAttrib1fv,
    .VertexAttrib2f =           trace_ppb_opengles2_VertexAttrib2f,
    .VertexAttrib2fv =          trace_ppb_opengles2_VertexAttrib2fv,
    .VertexAttrib3f =           trace_ppb_opengles2_VertexAttrib3f,
    .VertexAttrib3fv =          trace_ppb_opengles2_VertexAttrib3fv,
    .VertexAttrib4f =           trace_ppb_opengles2_VertexAttrib4f,
    .VertexAttrib4fv =          trace_ppb_opengles2_VertexAttrib4fv,
    .VertexAttribPointer =      trace_ppb_opengles2_VertexAttribPointer,
    .Viewport =                 trace_ppb_opengles2_Viewport,
};

const struct PPB_OpenGLES2ChromiumEnableFeature ppb_opengles2_chromium_enable_feature_interface_1_0 = {
    .EnableFeatureCHROMIUM = trace_ppb_opengles2_chromium_enable_feature_enable_feature_chromium,
};

const struct PPB_OpenGLES2ChromiumMapSub ppb_opengles2_chromium_map_sub_interface_1_0 = {
    .MapBufferSubDataCHROMIUM =   trace_ppb_opengles2_chromium_map_sub_map_buffer_sub_data_chromium,
    .UnmapBufferSubDataCHROMIUM = trace_ppb_opengles2_chromium_map_sub_unmap_buffer_sub_data_chromium,
    .MapTexSubImage2DCHROMIUM =   trace_ppb_opengles2_chromium_map_sub_map_tex_sub_image_2d_chromium,
    .UnmapTexSubImage2DCHROMIUM = trace_ppb_opengles2_chromium_map_sub_unmap_tex_sub_image_2d_chromium,
};

const struct PPB_OpenGLES2FramebufferBlit ppb_opengles2_framebuffer_blit_interface_1_0 = {
    .BlitFramebufferEXT = trace_ppb_opengles2_framebuffer_blit_blit_framebuffer_ext,
};

const struct PPB_OpenGLES2FramebufferMultisample ppb_opengles2_framebuffer_multisample_interface_1_0 = {
    .RenderbufferStorageMultisampleEXT =
                trace_ppb_opengles2_framebuffer_multisample_renderbuffer_storage_multisample_ext,
};

const struct PPB_OpenGLES2InstancedArrays ppb_opengles2_instanced_arrays_interface_1_0 = {
    .DrawArraysInstancedANGLE = trace_ppb_opengles2_instanced_arrays_draw_arrays_instanced_angle,
    .DrawElementsInstancedANGLE =trace_ppb_opengles2_instanced_arrays_draw_elements_instanced_angle,
    .VertexAttribDivisorANGLE = trace_ppb_opengles2_instanced_arrays_vertex_attrib_divisor_angle,

};

const struct PPB_OpenGLES2Query ppb_opengles2_query_interface_1_0 = {
    .GenQueriesEXT =        trace_ppb_opengles2_query_gen_queries_ext,
    .DeleteQueriesEXT =     trace_ppb_opengles2_query_delete_queries_ext,
    .IsQueryEXT =           trace_ppb_opengles2_query_is_query_ext,
    .BeginQueryEXT =        trace_ppb_opengles2_query_begin_query_ext,
    .EndQueryEXT =          trace_ppb_opengles2_query_end_query_ext,
    .GetQueryivEXT =        trace_ppb_opengles2_query_get_queryiv_ext,
    .GetQueryObjectuivEXT = trace_ppb_opengles2_query_get_query_objectuiv_ext,
};
