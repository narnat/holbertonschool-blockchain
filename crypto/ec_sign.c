#include "hblk_crypto.h"

/**
* ec_sign - sign msg with EC_KEY pair
* @key: key pair
* @msg: message to sign
* @msglen: len of message
* @sig: signature
* Return: buffer to signature
*/
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg,
				 size_t msglen, sig_t *sig)
{
	uint8_t digest[SHA256_DIGEST_LENGTH];

	if (!key || !msg || !sig)
		return (NULL);
	if (!SHA256(msg, msglen, digest))
		return (NULL);
	if (!ECDSA_sign(0, digest, SHA256_DIGEST_LENGTH,
					sig->sig, (uint32_t *)&(sig->len), (EC_KEY *)key))
		return (NULL);
	return (sig->sig);
}