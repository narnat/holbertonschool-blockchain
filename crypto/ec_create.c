#include "hblk_crypto.h"

/**
* ec_create - EC key pair
* Return: new keypair or NULL if failed
*/
EC_KEY *ec_create(void)
{
	EC_KEY *key;

	key = EC_KEY_new_by_curve_name(EC_CURVE);
	if (!key)
		return (NULL);
	if (EC_KEY_generate_key(key) != 1)
		return (NULL);
	return (key);
}