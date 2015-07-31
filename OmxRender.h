/* Copyright (c) 2015, Benjamin Huber
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the copyright holder nor the
 *      names of its contributors may be used to endorse or promote products
 *      derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ImageDef.h"
#include "ilclient.h"

#define OMX_RENDER_OK 0x0
#define OMX_RENDER_ERROR_CREATE_COMP 0x01
#define OMX_RENDER_ERROR_EXECUTING 0x02
#define OMX_RENDER_ERROR_PARAMETER 0x04
#define OMX_RENDER_ERROR_PORTS 0x08
#define OMX_RENDER_ERROR_UNKNOWN 0x10
#define OMX_RENDER_ERROR_MEMORY 0x20
#define OMX_RENDER_ERROR_DISP_CONF 0x40

#define OMX_DISP_CONFIG_FLAG_NO_ASPECT 0x1
#define OMX_DISP_CONFIG_FLAG_MIRROR 0x2

typedef struct OMX_RENDER_DISP_CONF{	
	int xOffset; 
	unsigned int width; 
	int yOffset;
	unsigned int height;
	int rotation;
	int layer;
	int display;
	int alpha;
	int mode;
	int configFlags;
	
} OMX_RENDER_DISP_CONF;

typedef struct OMX_RENDER{
	ILCLIENT_T *client;
	COMPONENT_T *component;
	OMX_HANDLETYPE handle;
	int inPort;
	
	OMX_BUFFERHEADERTYPE *pInputBufferHeader;
	
} OMX_RENDER;

/** Change display configuration of the image render component. */
int setDisplayConfig(OMX_RENDER *render, OMX_RENDER_DISP_CONF *dispConf);

/** Renders an image on an omx-video_render component. */
int renderImage(OMX_RENDER *render, IMAGE *image, OMX_RENDER_DISP_CONF *dispConfig);

/** Stops rendering of current image and cleans up. */
int stopImageRender(OMX_RENDER *render);
