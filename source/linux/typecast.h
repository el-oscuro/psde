#ifndef __typecasth
#define __typecasth

typedef union _WORDS {
		union	_WORDS	  * words_far;
		void *              	void_far;
 		UWORD									uword;
    SWORD									sword;
		SLONG									slong;
	 	ULONG 								ulong;
		UCHAR_FAR							uchar_far;
		SCHAR_FAR				  		schar_far;
		UINT_FAR				  		uint_far;
		SINT_FAR		    			sint_far;
		SLONG_FAR		   				slong_far;
		ULONG_FAR		    			ulong_far;
		UINT									uints[2];
		SINT									sints[2];
		UCHAR 								ubytes[4];
		SCHAR 								sbytes[4];
		} WORDS,  * WORDS_FAR;


#define   word0 	uints[0]
#define   word1 	uints[1]
#define   sint0 	sints[0]
#define   sint1 	sints[1]

#define   byte0 	ubytes[0]
#define   byte1 	ubytes[1]
#define   byte2 	ubytes[2]
#define   byte3 	ubytes[3]

#define   char0 	sbytes[0]
#define   char1 	sbytes[1]
#define   char2 	sbytes[2]
#define   char3 	sbytes[3]


#endif
