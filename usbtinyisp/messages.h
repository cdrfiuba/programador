#ifndef _MESSAGES_H_
#define _MESSAGES_H_

#include "common.h"

typedef struct {
	byte_t nothing;
	byte_t typeRequest;
}tGenericMessage;

typedef struct {
	byte_t nothing_1;
	byte_t typeRequest;
	byte_t sck_size;
	byte_t nothing_2;
	byte_t resetState;
}tPowerUpMess;


#endif