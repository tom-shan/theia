#ifndef WIN_FFMPEG
#define WIN_FFMPEG

// WIP

#include <windows.h>

static const char *error_library_not_found = "library not found";
static const char *error_function_not_found = "function not found";

char *load_ffmpeg_library(struct FFMPEG_Library *library, char *library_path)
{
  char *error = NULL;

  HMODULE handle = LoadLibraryA(library_path);
  if (!handle)
  {
    error = error_library_not_found;
    goto error;
  }

  void (*avcodec_register_all)(void) = GetProcAddress(handle, "avcodec_register_all");
  if (!avcodec_register_all)
  {
    error = error_function_not_found;
    goto error;
  }

  struct AVCodec *(*av_codec_next)(const struct AVCodec *c) = GetProcAddress(handle, "av_codec_next");
  if (!av_codec_next)
  {
    error = error_function_not_found;
    goto error;
  }

  library->handle = handle;
  library->avcodec_register_all = avcode_register_all;
  library->av_codec_next = av_codec_next;
  return NULL;

error:
  if (!handle)
    FreeLibrary(handle);
  return error;
}

char *unload_ffmpeg_library(struct FFMPEG_Library *library)
{
}

#endif // WIN_FFMPEG guard
