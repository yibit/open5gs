#ifndef __SGW_S11_HANDLER_H__
#define __SGW_S11_HANDLER_H__

#include "gtp_tlv.h"
#include "context.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(void) sgw_s11_handle_create_session_request(
        gtp_xact_t *xact, gtp_message_t *gtp_message);

CORE_DECLARE(void) sgw_s11_handle_create_session_response(
        gtp_xact_t *xact, gtp_message_t *gtp_message);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __SGW_S11_HANDLER_H__ */