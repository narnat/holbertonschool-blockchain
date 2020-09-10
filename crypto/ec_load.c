#include "hblk_crypto.h"

/**
* ec_load - load keys from a file
* @folder: folder where key pair is stored
* Return: EC_KEY key pair
 */
EC_KEY *ec_load(char const *folder)
{
	EC_KEY *key = NULL;
	char file[512] = {0};
	FILE *fp;

	if (!folder)
		return (NULL);
	sprintf(file, "%s/key.pem", folder);
	fp = fopen(file, "w");
	if (!fp)
		return (NULL);
	if (!PEM_read_ECPrivateKey(fp, &key, NULL, NULL))
		return (NULL);
	fclose(fp);
	sprintf(file, "%s/key_pub.pem", folder);
	fp = fopen(file, "w");
	if (!fp)
		return (NULL);
	if (!PEM_read_EC_PUBKEY(fp, &key, NULL, NULL))
		return (NULL);
	fclose(fp);
	return (key);
}