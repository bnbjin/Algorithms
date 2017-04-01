#include "my_aes.h"
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


const char TESTFILEPATH[] = {"/home/paradoximov/MyCode/Algorithms/Crypto/AES/testfile.sh"};

int EncryptFile(
	const char *_szFilePath,
	const unsigned char *_pKey,
	const unsigned char *_IV);

int DecryptFile(
	const char *_szFilePath,
	const unsigned char *_pKey,
	const unsigned char *_IV);

int main (void)
{
  	/* A 256 bit key */
	/* 32Byes */
  	unsigned char *key = (unsigned char *)"01234567890123456789012345678901";

  	/* A 128 bit IV */
	/* 16Bytes */
  	unsigned char *iv = (unsigned char *)"0123456789012345";

  	/* Initialise the library */
  	ERR_load_crypto_strings();
  	OpenSSL_add_all_algorithms();
  	OPENSSL_config(NULL);

  	EncryptFile(TESTFILEPATH, key, iv);
	
	int abc;
	scanf("press any key. %d", abc);

  	DecryptFile(TESTFILEPATH, key, iv);

  	/* Clean up */
  	EVP_cleanup();
  	ERR_free_strings();

  	return 0;
}


int EncryptFile(
		const char *_szFilePath,
		const unsigned char* _pKey,
		const unsigned char* _IV)
{
	int retcode;
	FILE *filefd;
	int filesize;
	unsigned char *pBuffer;

	filefd = fopen(_szFilePath, "r+");
	assert(filefd);

	fseek(filefd, 0, SEEK_END);
	filesize = ftell(filefd);
	pBuffer = malloc(filesize);
	assert(pBuffer);

	fseek(filefd, 0, SEEK_SET);
	retcode = fread(pBuffer, filesize, sizeof(unsigned char), filefd);
	assert(retcode);

	int ciphertext_len;
	char *ciphertext = malloc((filesize / 16 + 1) * 16);
	assert(ciphertext);

	ciphertext_len = encrypt (pBuffer, filesize, _pKey, _IV, ciphertext);

	fseek(filefd, 0 , SEEK_SET);
	retcode = fwrite(ciphertext, ciphertext_len, sizeof(char), filefd);
	assert(retcode);

	free(pBuffer);
	free(ciphertext);
	fclose(filefd);

	return 0;
}


int DecryptFile(
	const char *_szFilePath,
	const unsigned char *_pKey,
	const unsigned char *_IV)
{
	int retcode;
	FILE *filefd;
	int filesize;
	unsigned char *pBuffer;

	filefd = fopen(_szFilePath, "r+");
	assert(filefd);

	fseek(filefd, 0, SEEK_END);
	filesize = ftell(filefd);
	pBuffer = malloc(filesize);
	assert(pBuffer);

	fseek(filefd, 0, SEEK_SET);
	retcode = fread(pBuffer, filesize, sizeof(unsigned char), filefd);
	assert(retcode);
	fclose(filefd);


	int plaintext_len;
	char *plaintext = malloc((filesize / 16 + 1) * 16);
	assert(plaintext);

	plaintext_len = decrypt (pBuffer, filesize, _pKey, _IV, plaintext);

	filefd = fopen(_szFilePath, "w");
	assert(filefd);
	fseek(filefd, 0, SEEK_SET);
	fwrite(plaintext, plaintext_len, sizeof(char), filefd);

	free(pBuffer);
	free(plaintext);
	fclose(filefd);

	return 0;
}
