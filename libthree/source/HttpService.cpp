/*
 * HttpService.cpp
 *
 *  Created on: 08.01.2016
 *      Author: andreuschmann
 */
#include "three.h"
#include <cstring>

HttpService::HttpService() {
	httpcInit();
}

const char* HttpService::get(char *url) {
	u32 statuscode = 0;
	u32 contentsize = 0;
	u8 *buf;
	httpcContext context;
	Result ret = 0;
	ret = httpcOpenContext(&context, url, 1);
	ret = httpcBeginRequest(&context);
	if(ret!=0)return NULL;

	ret = httpcGetResponseStatusCode(&context, &statuscode, 0);
	if(ret!=0)return NULL;
	if(statuscode!=200)return NULL;

	ret=httpcGetDownloadSizeState(&context, NULL, &contentsize);
	if(ret!=0)return NULL;

	buf = (u8*)malloc(contentsize + 1);
	if(buf==NULL)return NULL;
	memset(buf, 0, contentsize + 1);

	ret = httpcDownloadData(&context, buf, contentsize, NULL);
	if(ret!=0)
	{
		free(buf);
		return NULL;
	}
	httpcCloseContext(&context);
	return (const char*)buf;
}

