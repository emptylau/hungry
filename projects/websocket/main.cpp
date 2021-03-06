#include <iostream>
#include "func.h"

static bool quit = false;

void signal_handler(int signal){
	quit = true;
}

struct lws_protocols* protocols[] ={

	{"WebService", callback, sizeof(NetData), 1024},
	{nullptr, nullptr, 0, 0}
};

int main(int argc, char* argv[])
{
	if(argc < 2){
		std::cout << "usage: exec port" << std::endl;
		return 0;
	}

	int port = atoi(argv[1]);
	if (port > 65535){
		std::cout << "port overlap" << std::endl;
		return 0;
	}

	signal(SIGINT, signal_handler);
	
	std::string host("0.0.0.0");

	struct lws_context_creation_info info;
	info.port = port;
	info.iface = host.c_str();
	info.protocols = s_protocols;
	info.token_limits = nullptr;
	info.ssl_private_key_password = nullptr;
	info.ssl_private_key_filepath = nullptr;
	info.ssl_cert_filepath = nullptr;
	info.ssl_ca_filepath = nullptr;
	info.ssl_cipher_list = nullptr;
	info.http_proxy_address = nullptr;
	info.http_proxy_port = 0;
	info.gid = 0;
	info.uid = 0;
	info.options = 0;
	info.user = nullptr;
	info.ka_time = 0;
	info.ka_probes = 0;
	info.ka_interval = 0;
#ifdef LWS_OPENSSL_SUPPORT
	info.provided_client_ssl_ctx = nullptr;
#else
	info.provided_client_ssl_ctx = nullptr;
#endif
	info.max_http_header_data = 0;
	info.max_http_header_pool = 0;

	struct lws_context* pContext = lws_create_context(&info);
	if (!pContext){
		std::cout << "lws context create failure" << std::endl;
		return 0;
	}


	pthread_t thread_service;
	int ret = pthread_create(&thread_service, nullptr, service_thread, nullptr);
	if (0 != ret){
		perror("pthread_create");
		return 0;
	}

	int ret = 0;
	while( ret >=0 && !quit){
		n = lws_service(&pContext, 50);
		usleep(10000);
	}

	lws_cancel_service(&pContext);

	pthread_join(thread_service, nullptr);

	lws_context_destroy(&pContext);

	return 0;
}
