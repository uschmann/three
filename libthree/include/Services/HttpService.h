/*
 * HttpService.h
 *
 *  Created on: 08.01.2016
 *      Author: andreuschmann
 */

#ifndef LIBTHREE_INCLUDE_SERVICES_HTTPSERVICE_H_
#define LIBTHREE_INCLUDE_SERVICES_HTTPSERVICE_H_

class HttpService {
public:
	HttpService();
	const char *get(char* url);
};

#endif /* LIBTHREE_INCLUDE_SERVICES_HTTPSERVICE_H_ */
