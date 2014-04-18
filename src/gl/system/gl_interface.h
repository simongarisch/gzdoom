#ifndef R_RENDER
#define R_RENDER

#include "basictypes.h"

enum RenderFlags
{
	// [BB] Added texture compression flags.
	RFL_TEXTURE_COMPRESSION=8,
	RFL_TEXTURE_COMPRESSION_S3TC=16,
	RFL_NVIDIA = 512,
	RFL_ATI = 1024,
};

enum TexMode
{
	TMF_MASKBIT = 1,
	TMF_OPAQUEBIT = 2,
	TMF_INVERTBIT = 4,

	TM_MODULATE = 0,
	TM_MASK = TMF_MASKBIT,
	TM_OPAQUE = TMF_OPAQUEBIT,
	TM_INVERT = TMF_INVERTBIT,
	//TM_INVERTMASK = TMF_MASKBIT | TMF_INVERTBIT
	TM_INVERTOPAQUE = TMF_INVERTBIT | TMF_OPAQUEBIT,
};

struct RenderContext
{
	unsigned int flags;
	unsigned int maxuniforms;
	int max_texturesize;
	char * vendorstring;

	int MaxLights() const
	{
		return maxuniforms>=2048? 128:64;
	}
};

extern RenderContext gl;

#endif

