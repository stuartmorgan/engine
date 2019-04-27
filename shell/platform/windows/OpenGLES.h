
#ifndef FLUTTER_SHELL_PLATFORM_WINDOWS_OPENGLES_H_
#define FLUTTER_SHELL_PLATFORM_WINDOWS_OPENGLES_H_

// Enable function definitions in the GL headers below
//#define GL_GLEXT_PROTOTYPES
#define EGL_EGL_PROTOTYPES

// OpenGL ES includes
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

// EGL includes
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <EGL/eglplatform.h>

//// EGL includes
//#include "third_party/angle/include/EGL/egl.h"
//#include "third_party/angle/include/EGL/eglext.h"
//#include <third_party/angle/include/EGL/eglplatform.h>
//
//// OpenGL ES includes
//#include <third_party/angle/include/GLES2/gl2.h>
//#include <third_party/angle/include/GLES2/gl2ext.h>

const wchar_t EGLNativeWindowTypeProperty[] = L"EGLNativeWindowTypeProperty";

class OpenGLES
{
public:
    OpenGLES();
    ~OpenGLES();

	//EGLSurface CreateSurface(winrt::Windows::UI::Composition::ISpriteVisual & visual);
    EGLSurface CreateSurface(HWND window);
    void GetSurfaceDimensions(const EGLSurface surface, EGLint *width, EGLint *height);
    void DestroySurface(const EGLSurface surface);
    void MakeCurrent(const EGLSurface surface);
    EGLBoolean SwapBuffers(const EGLSurface surface);
    void Reset();

private:
    void Initialize();
    void Cleanup();

private:
    EGLDisplay mEglDisplay;
    EGLContext mEglContext;
    EGLConfig  mEglConfig;
};

#endif  // FLUTTER_SHELL_PLATFORM_WINDOWS_OPENGLES_H_
