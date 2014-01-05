/******************************************************************************
*
* FILE: tmferr.h
*
*------------------------------------------------------------------------------
*
*  Copyright 2005, 2006 Trend Micro, Inc.  All rights reserved
*
******************************************************************************/

#ifndef _TMFR_ERROR_H_
#define _TMFR_ERROR_H_

#include "emprimitive.h"

/**
 * Type definition for TMFRE specified error code.
 */
typedef em_int32   TM_FR_ERRORCODE;

/**
 * Base error code definition.
 */
#define TM_FR_SUCCESS                             (1)
#define TM_FR_ERROR                               (0)

#define TM_FR_INVALID_HANDLE                      (0)

/**
 * Macros to examine the error code.
 */
#define TM_FR_IS_SUCCESS(code)                    (((code) >= TM_FR_SUCCESS) ? TRUE : FALSE)
#define TM_FR_IS_ERROR(code)                      (((code) <= TM_FR_ERROR) ? TRUE : FALSE)

/**
 * Common Error Code (0 ~ -99)
 */
#define TM_FR_ERR_COMM_BASE                       TM_FR_ERROR
#define TM_FR_ERR_COMM_INVALID_PARAM              (TM_FR_ERR_COMM_BASE - 1)
#define TM_FR_ERR_COMM_FILE_OPEN_FAILED           (TM_FR_ERR_COMM_BASE - 2)
#define TM_FR_ERR_COMM_MEM_ALLOC_FAIL             (TM_FR_ERR_COMM_BASE - 3)
#define TM_FR_ERR_COMM_UNKNOWN_EXCEPTION          (TM_FR_ERR_COMM_BASE - 4)
#define TM_FR_ERR_COMM_FILE_PATH_TOO_LONG         (TM_FR_ERR_COMM_BASE - 5)
#define TM_FR_ERR_COMM_FILE_IO_FAILED             (TM_FR_ERR_COMM_BASE - 6)
#define TM_FR_ERR_COMM_CRYPTO_FAILED              (TM_FR_ERR_COMM_BASE - 7)
#define TM_FR_ERR_COMM_FILE_DIR_NOT_EXIST         (TM_FR_ERR_COMM_BASE - 8)
#define TM_FR_ERR_COMM_FILE_CREATE_FAILED         (TM_FR_ERR_COMM_BASE - 9)
#define TM_FR_ERR_COMM_INVALID_PLATFORM           (TM_FR_ERR_COMM_BASE - 10)

/**
 * Initialization Error Code (-100 ~ -199)
 */
#define TM_FR_ERR_INIT_BASE                       (TM_FR_ERROR - 100)
#define TM_FR_ERR_INIT_PRIV_IP_TABLE_INIT_FAILED  (TM_FR_ERR_INIT_BASE - 1)
/*#define TM_FR_ERR_INIT_ASSIGN_AC_FAILED           (TM_FR_ERR_INIT_BASE - 2)*/
/*#define TM_FR_ERR_INIT_TMSC_INIT_FAILED           (TM_FR_ERR_INIT_BASE - 3)*/
/*#define TM_FR_ERR_INIT_OPEN_RATING_TREE_FAILED    (TM_FR_ERR_INIT_BASE - 4)*/
#define TM_FR_ERR_INIT_ALREADY_INIT               (TM_FR_ERR_INIT_BASE - 5)
#define TM_FR_ERR_INIT_NOT_INIT                   (TM_FR_ERR_INIT_BASE - 6)
/*#define TM_FR_ERR_INIT_OPTION_CONFLICT            (TM_FR_ERR_INIT_BASE - 7)*/
#define TM_FR_ERR_INIT_HTTP_LIB_INIT_FAILED       (TM_FR_ERR_INIT_BASE - 8)
/*#define TM_FR_ERR_INIT_INVALID_WORKING_DIR        (TM_FR_ERR_INIT_BASE - 9)*/
#define TM_FR_ERR_INIT_INVALID_LICENSE_ID         (TM_FR_ERR_INIT_BASE - 10)
#define TM_FR_ERR_INIT_INVALID_VENDOR_ID          (TM_FR_ERR_INIT_BASE - 11)

/**
 * Option Error Code (-200 ~ -299)
 */
#define TM_FR_ERR_OPTION_BASE                     (TM_FR_ERROR - 200)
#define TM_FR_ERR_OPTION_INVALID_ID               (TM_FR_ERR_OPTION_BASE - 1)
#define TM_FR_ERR_OPTION_INCORRECT_SIZE           (TM_FR_ERR_OPTION_BASE - 2)
#define TM_FR_ERR_OPTION_MISSING_RS_INFO          (TM_FR_ERR_OPTION_BASE - 3)
#define TM_FR_ERR_OPTION_MISSING_PROXY_INFO       (TM_FR_ERR_OPTION_BASE - 4)
#define TM_FR_ERR_OPTION_INVALID_RS_INFO          (TM_FR_ERR_OPTION_BASE - 5)
#define TM_FR_ERR_OPTION_INVALID_CACHE_SIZE       (TM_FR_ERR_OPTION_BASE - 6)
#define TM_FR_ERR_OPTION_INVALID_CACHE_LIFE       (TM_FR_ERR_OPTION_BASE - 7)
#define TM_FR_ERR_OPTION_INVALID_RATING_TYPE      (TM_FR_ERR_OPTION_BASE - 8)
#define TM_FR_ERR_OPTION_INVALID_RATING_PROTOCOL  (TM_FR_ERR_OPTION_BASE - 9)

/**
 * URL Error Code (-300 ~ -399)
 */
#define TM_FR_ERR_URL_BASE                        (TM_FR_ERROR - 300)
/*#define TM_FR_ERR_URL_TOO_LONG                    (TM_FR_ERR_URL_BASE - 1)*/
/*#define TM_FR_ERR_URL_INVALID                     (TM_FR_ERR_URL_BASE - 2)*/
#define TM_FR_ERR_URL_DOMAIN_INVALID              (TM_FR_ERR_URL_BASE - 3)
#define TM_FR_ERR_URL_PORT_INVALID                (TM_FR_ERR_URL_BASE - 4)
#define TM_FR_ERR_URL_PATH_INVALID                (TM_FR_ERR_URL_BASE - 5)
#define TM_FR_ERR_URL_ENCODING_ERROR              (TM_FR_ERR_URL_BASE - 6)
#define TM_FR_ERR_URL_IP_TOO_LONG                 (TM_FR_ERR_URL_BASE - 7)
#define TM_FR_ERR_URL_HOST_IS_PRIVATE_IP          (TM_FR_ERR_URL_BASE - 8)
#define TM_FR_ERR_URL_FORMAT_TSATP_FAIL           (TM_FR_ERR_URL_BASE - 9)

/**
 * Pattern Error Code (-400 ~ -499)
 */
#define TM_FR_ERR_PTN_BASE                        (TM_FR_ERROR - 400)
/*#define TM_FR_ERR_PTN_INCORRECT_FILE_SIZE         (TM_FR_ERR_PTN_BASE - 1)*/
#define TM_FR_ERR_PTN_IMPORT_INCOMPLETE           (TM_FR_ERR_PTN_BASE - 2)
#define TM_FR_ERR_PTN_FILE_INTEGRITY_FAIL         (TM_FR_ERR_PTN_BASE - 3)
#define TM_FR_ERR_PTN_INVALID_HEADER_INFO         (TM_FR_ERR_PTN_BASE - 4)
#define TM_FR_ERR_PTN_CACHE_INCONSISTENT          (TM_FR_ERR_PTN_BASE - 5)
#define TM_FR_ERR_PTN_NO_CACHE                    (TM_FR_ERR_PTN_BASE - 6)
#define TM_FR_ERR_PTN_LOAD_FAILED                 (TM_FR_ERR_PTN_BASE - 7)
#define TM_FR_ERR_PTN_GEN_MD5_FAILED              (TM_FR_ERR_PTN_BASE - 8)
#define TM_FR_ERR_PTN_INSERT_DATA_FAILED          (TM_FR_ERR_PTN_BASE - 9)
/*#define TM_FR_ERR_PTN_CACHE_INVALID_PLATFORM      (TM_FR_ERR_PTN_BASE - 10)*/

/**
 * WBList Error Code (-500 ~ -599)
 *
#define TM_FR_ERR_WBLIST_BASE                     (TM_FR_ERROR - 500)
#define TM_FR_ERR_WBLIST_NOT_INITED               (TM_FR_ERR_WBLIST_BASE - 1)
#define TM_FR_ERR_WBLIST_HAS_BEEN_BUILT           (TM_FR_ERR_WBLIST_BASE - 2)
#define TM_FR_ERR_WBLIST_DUPLICATED_PATTERN       (TM_FR_ERR_WBLIST_BASE - 3)
#define TM_FR_ERR_WBLIST_INVALID_HANDLE           (TM_FR_ERR_WBLIST_BASE - 4)
 */

/**
 * Cache (Hash) Error Code (-600 ~ -699)
 */
#define TM_FR_ERR_CACHE_BASE                      (TM_FR_ERROR - 600)
/*#define TM_FR_ERR_CACHE_RESIZE_FAILED             (TM_FR_ERR_CACHE_BASE - 1)*/
#define TM_FR_ERR_CACHE_SIZE_TOO_SMALL            (TM_FR_ERR_CACHE_BASE - 2)
#define TM_FR_ERR_CACHE_SIZE_TOO_BIG              (TM_FR_ERR_CACHE_BASE - 3)
#define TM_FR_ERR_CACHE_LOCK_INIT_FAILED          (TM_FR_ERR_CACHE_BASE - 4)
#define TM_FR_ERR_CACHE_NOT_INIT                  (TM_FR_ERR_CACHE_BASE - 5)
/*#define TM_FR_ERR_CACHE_GEN_KEY_FAILED            (TM_FR_ERR_CACHE_BASE - 6)*/
/*#define TM_FR_ERR_CACHE_FILE_INVALID_PLATFORM     (TM_FR_ERR_CACHE_BASE - 7)*/
#define TM_FR_ERR_HASH_CREATE_FAILED              (TM_FR_ERR_CACHE_BASE - 8)

/**
 * Connection Error Code (-700 ~ -799)
 */
#define TM_FR_ERR_CONN_BASE                       (TM_FR_ERROR - 700)
#define TM_FR_ERR_CONN_RS_CONNECT_FAILED          (TM_FR_ERR_CONN_BASE - 1)
#define TM_FR_ERR_CONN_START_SOCKET_FAILED        (TM_FR_ERR_CONN_BASE - 2)  /* SC_ERR_CREATE_SOCKET ? */
#define TM_FR_ERR_CONN_CLEAN_SOCKET_FAILED        (TM_FR_ERR_CONN_BASE - 3)
#define TM_FR_ERR_CONN_INIT_HANDLE_FAILED         (TM_FR_ERR_CONN_BASE - 4)
#define TM_FR_ERR_CONN_CLOSE_SOCKET_FAILED        (TM_FR_ERR_CONN_BASE - 5)
#define TM_FR_ERR_CONN_RS_BAD_RESULT              (TM_FR_ERR_CONN_BASE - 6)
#define TM_FR_ERR_CONN_SOCKS4_IPV6_NOT_SUPPORTED  (TM_FR_ERR_CONN_BASE - 7) /* SC_ERR_SOCKS4_IPV6_NOT_SUPPORTED */

#define TM_FR_ERR_CONN_COMM_FAILED                (TM_FR_ERR_CONN_BASE - 21)
#define TM_FR_ERR_CONN_COMM_UNREACH               (TM_FR_ERR_CONN_BASE - 22)
#define TM_FR_ERR_CONN_COMM_RESOLVE               (TM_FR_ERR_CONN_BASE - 23)
#define TM_FR_ERR_CONN_COMM_CONNECTION_REFUSED    (TM_FR_ERR_CONN_BASE - 24)
#define TM_FR_ERR_CONN_COMM_CONNECTION_CLOSED     (TM_FR_ERR_CONN_BASE - 25)
#define TM_FR_ERR_CONN_COMM_TRANSFER              (TM_FR_ERR_CONN_BASE - 26)
#define TM_FR_ERR_CONN_COMM_TIMEOUT               (TM_FR_ERR_CONN_BASE - 27)
#define TM_FR_ERR_CONN_COMM_SET_NON_BLOCKING      (TM_FR_ERR_CONN_BASE - 28)

#define TM_FR_ERR_CONN_PROXY_FAILED               (TM_FR_ERR_CONN_BASE - 41)
#define TM_FR_ERR_CONN_PROXY_UNREACH              (TM_FR_ERR_CONN_BASE - 42)  /* SC_ERR_PROXY_UNREACH */
#define TM_FR_ERR_CONN_PROXY_RESOLVE              (TM_FR_ERR_CONN_BASE - 43)
#define TM_FR_ERR_CONN_PROXY_CONNECTION_REFUSED   (TM_FR_ERR_CONN_BASE - 44)
#define TM_FR_ERR_CONN_PROXY_CONNECTION_CLOSED    (TM_FR_ERR_CONN_BASE - 45)
#define TM_FR_ERR_CONN_PROXY_TRANSFER             (TM_FR_ERR_CONN_BASE - 46)
#define TM_FR_ERR_CONN_PROXY_TIMEOUT              (TM_FR_ERR_CONN_BASE - 47)
#define TM_FR_ERR_CONN_PROXY_WRONG_VERSION        (TM_FR_ERR_CONN_BASE - 48)
#define TM_FR_ERR_CONN_PROXY_AUTH_FAILED          (TM_FR_ERR_CONN_BASE - 49)
#define TM_FR_ERR_CONN_PROXY_ADDR_NOT_SUPPORTED   (TM_FR_ERR_CONN_BASE - 50)
#define TM_FR_ERR_CONN_PROXY_TYPE                 (TM_FR_ERR_CONN_BASE - 51) /* SC_ERR_PROXY_TYPE */
#define TM_FR_ERR_CONN_PASS_PROXY                 (TM_FR_ERR_CONN_BASE - 52) /* SC_ERR_PASS_PROXY */

/**
 * HTTP response Error Code (-800 ~ -899)
 */
#define TM_FR_ERR_HTTP_BASE                       (TM_FR_ERROR - 800)
#define TM_FR_ERR_HTTP_NULL_HANDLE                (TM_FR_ERR_HTTP_BASE - 1)  /* SC_ERR_HTTP_HANDLE */
#define TM_FR_ERR_HTTP_NO_MEM                     (TM_FR_ERR_HTTP_BASE - 2)  /* SC_ERR_HTTP_NO_MEM */
#define TM_FR_ERR_HTTP_AUTH                       (TM_FR_ERR_HTTP_BASE - 3)  /* SC_ERR_HTTP_AUTH */
#define TM_FR_ERR_HTTP_SEND_HEADER                (TM_FR_ERR_HTTP_BASE - 4)  /* SC_ERR_HTTP_SEND_HEADER */
#define TM_FR_ERR_HTTP_SEND_DATA                  (TM_FR_ERR_HTTP_BASE - 5)  /* SC_ERR_HTTP_SEND_DATA */
#define TM_FR_ERR_HTTP_RECV                       (TM_FR_ERR_HTTP_BASE - 6)  /* SC_ERR_HTTP_RECV */
#define TM_FR_ERR_HTTP_FILENAME                   (TM_FR_ERR_HTTP_BASE - 7)  /* SC_ERR_HTTP_FILENAME */
#define TM_FR_ERR_HTTP_NO_STATUS                  (TM_FR_ERR_HTTP_BASE - 8)  /* SC_ERR_HTTP_NO_STATUS */ /* Response buffer doesn't include the HTTP status code */
#define TM_FR_ERR_HTTP_RECEIVER                   (TM_FR_ERR_HTTP_BASE - 9)  /* SC_ERR_HTTP_RECEIVER */
#define TM_FR_ERR_HTTP_NO_DATA                    (TM_FR_ERR_HTTP_BASE - 10) /* SC_ERR_HTTP_NO_DATA */
#define TM_FR_ERR_HTTP_CREATE_FILE                (TM_FR_ERR_HTTP_BASE - 11) /* SC_ERR_HTTP_CREATE_FILE */
#define TM_FR_ERR_HTTP_WRITE_FILE                 (TM_FR_ERR_HTTP_BASE - 12) /* SC_ERR_HTTP_WRITE_FILE */
#define TM_FR_ERR_HTTP_PROXY_TYPE                 (TM_FR_ERR_HTTP_BASE - 13) /* SC_ERR_HTTP_PROXY_TYPE */
#define TM_FR_ERR_HTTP_REPLY                      (TM_FR_ERR_HTTP_BASE - 14) /* SC_ERR_HTTP_REPLY */
#define TM_FR_ERR_HTTP_NO_LENGTH                  (TM_FR_ERR_HTTP_BASE - 15) /* SC_ERR_HTTP_NO_LENGTH */
#define TM_FR_ERR_HTTP_OPTION                     (TM_FR_ERR_HTTP_BASE - 16) /* SC_ERR_HTTP_OPTION */
#define TM_FR_ERR_HTTP_URL                        (TM_FR_ERR_HTTP_BASE - 17) /* SC_ERR_HTTP_URL */

/**
 * HTTP Response Status Code (-2000 ~ -2505)
 */
#define TM_FR_HTTP_STATUS_BASE                    (TM_FR_ERROR - 2000)
#define TM_FR_HTTP_STATUS_CONTINUE                (TM_FR_HTTP_STATUS_BASE - 100) /* OK to continue with request */
#define TM_FR_HTTP_STATUS_SWITCH_PROTOCOLS        (TM_FR_HTTP_STATUS_BASE - 101) /* server has switched protocols in upgrade header */

#define TM_FR_HTTP_STATUS_OK                      (TM_FR_HTTP_STATUS_BASE - 200) /* request completed */
#define TM_FR_HTTP_STATUS_CREATED                 (TM_FR_HTTP_STATUS_BASE - 201) /* object created, reason = new URI */
#define TM_FR_HTTP_STATUS_ACCEPTED                (TM_FR_HTTP_STATUS_BASE - 202) /* async completion (TBS) */
#define TM_FR_HTTP_STATUS_PARTIAL                 (TM_FR_HTTP_STATUS_BASE - 203) /* partial completion */
#define TM_FR_HTTP_STATUS_NO_CONTENT              (TM_FR_HTTP_STATUS_BASE - 204) /* no info to return */
#define TM_FR_HTTP_STATUS_RESET_CONTENT           (TM_FR_HTTP_STATUS_BASE - 205) /* request completed, but clear form */
#define TM_FR_HTTP_STATUS_PARTIAL_CONTENT         (TM_FR_HTTP_STATUS_BASE - 206) /* partial GET furfilled */

#define TM_FR_HTTP_STATUS_AMBIGUOUS               (TM_FR_HTTP_STATUS_BASE - 300) /* server couldn't decide what to return */
#define TM_FR_HTTP_STATUS_MOVED                   (TM_FR_HTTP_STATUS_BASE - 301) /* object permanently moved */
#define TM_FR_HTTP_STATUS_REDIRECT                (TM_FR_HTTP_STATUS_BASE - 302) /* object temporarily moved */
#define TM_FR_HTTP_STATUS_REDIRECT_METHOD         (TM_FR_HTTP_STATUS_BASE - 303) /* redirection w/ new access method */
#define TM_FR_HTTP_STATUS_NOT_MODIFIED            (TM_FR_HTTP_STATUS_BASE - 304) /* if-modified-since was not modified */
#define TM_FR_HTTP_STATUS_USE_PROXY               (TM_FR_HTTP_STATUS_BASE - 305) /* redirection to proxy, location header specifies proxy to use */
#define TM_FR_HTTP_STATUS_REDIRECT_KEEP_VERB      (TM_FR_HTTP_STATUS_BASE - 307) /* HTTP/1.1: keep same verb */

#define TM_FR_HTTP_STATUS_BAD_REQUEST             (TM_FR_HTTP_STATUS_BASE - 400) /* invalid syntax */
#define TM_FR_HTTP_STATUS_DENIED                  (TM_FR_HTTP_STATUS_BASE - 401) /* access denied */
#define TM_FR_HTTP_STATUS_PAYMENT_REQ             (TM_FR_HTTP_STATUS_BASE - 402) /* payment required */
#define TM_FR_HTTP_STATUS_FORBIDDEN               (TM_FR_HTTP_STATUS_BASE - 403) /* request forbidden */
#define TM_FR_HTTP_STATUS_NOT_FOUND               (TM_FR_HTTP_STATUS_BASE - 404) /* object not found */
#define TM_FR_HTTP_STATUS_BAD_METHOD              (TM_FR_HTTP_STATUS_BASE - 405) /* method is not allowed */
#define TM_FR_HTTP_STATUS_NONE_ACCEPTABLE         (TM_FR_HTTP_STATUS_BASE - 406) /* no response acceptable to client found */
#define TM_FR_HTTP_STATUS_PROXY_AUTH_REQ          (TM_FR_HTTP_STATUS_BASE - 407) /* proxy authentication required */
#define TM_FR_HTTP_STATUS_REQUEST_TIMEOUT         (TM_FR_HTTP_STATUS_BASE - 408) /* server timed out waiting for request */
#define TM_FR_HTTP_STATUS_CONFLICT                (TM_FR_HTTP_STATUS_BASE - 409) /* user should resubmit with more info */
#define TM_FR_HTTP_STATUS_GONE                    (TM_FR_HTTP_STATUS_BASE - 410) /* the resource is no longer available */
#define TM_FR_HTTP_STATUS_LENGTH_REQUIRED         (TM_FR_HTTP_STATUS_BASE - 411) /* the server refused to accept request w/o a length */
#define TM_FR_HTTP_STATUS_PRECOND_FAILED          (TM_FR_HTTP_STATUS_BASE - 412) /* precondition given in request failed */
#define TM_FR_HTTP_STATUS_REQUEST_TOO_LARGE       (TM_FR_HTTP_STATUS_BASE - 413) /* request entity was too large */
#define TM_FR_HTTP_STATUS_URI_TOO_LONG            (TM_FR_HTTP_STATUS_BASE - 414) /* request URI too long */
#define TM_FR_HTTP_STATUS_UNSUPPORTED_MEDIA       (TM_FR_HTTP_STATUS_BASE - 415) /* unsupported media type */

#define TM_FR_HTTP_STATUS_SERVER_ERROR            (TM_FR_HTTP_STATUS_BASE - 500) /* internal server error */
#define TM_FR_HTTP_STATUS_NOT_SUPPORTED           (TM_FR_HTTP_STATUS_BASE - 501) /* required not supported */
#define TM_FR_HTTP_STATUS_BAD_GATEWAY             (TM_FR_HTTP_STATUS_BASE - 502) /* error response received from gateway */
#define TM_FR_HTTP_STATUS_SERVICE_UNAVAIL         (TM_FR_HTTP_STATUS_BASE - 503) /* temporarily overloaded */
#define TM_FR_HTTP_STATUS_GATEWAY_TIMEOUT         (TM_FR_HTTP_STATUS_BASE - 504) /* timed out waiting for gateway */
#define TM_FR_HTTP_STATUS_VERSION_NOT_SUP         (TM_FR_HTTP_STATUS_BASE - 505)

#endif /* _TMFR_ERROR_H_ */
