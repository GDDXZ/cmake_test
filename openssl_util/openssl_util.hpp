#include <openssl/bn.h>
#include <openssl/bio.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <openssl/err.h>

class COpenSSLUtil{
private:
	int m = 0;
public:
	COpenSSLUtil();
	~COpenSSLUtil();
};