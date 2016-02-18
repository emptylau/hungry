#ifndef _FUNC_H_
#define _FUNC_H_

struct NetData{
	int fd;
	int len;
	char* data;
};

extern int callback(struct lws* wsi, \
		enum lws_callback_reasons, \
		void*,\
		void*, \
		size_t);


#endif // !_FUNC_H_
