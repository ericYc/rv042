/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.19 $ of : mfd-data-set.m2c,v $ 
 *
 * $Id: usmDHUserKeyTable_data_set.h 1786 2008-11-10 13:36:41Z richie $
 */
#ifndef USMDHUSERKEYTABLE_DATA_SET_H
#define USMDHUSERKEYTABLE_DATA_SET_H

#ifdef __cplusplus
extern          "C" {
#endif

    /*
     *********************************************************************
     * SET function declarations
     */

    /*
     *********************************************************************
     * SET Table declarations
     */
/**********************************************************************
 **********************************************************************
 ***
 *** Table usmDHUserKeyTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * SNMP-USM-DH-OBJECTS-MIB::usmDHUserKeyTable is subid 2 of usmDHPublicObjects.
     * Its status is Current.
     * OID: .1.3.6.1.3.101.1.1.2, length: 9
     */


    int            
        usmDHUserKeyTable_undo_setup(usmDHUserKeyTable_rowreq_ctx *
                                     rowreq_ctx);
    int            
        usmDHUserKeyTable_undo_cleanup(usmDHUserKeyTable_rowreq_ctx *
                                       rowreq_ctx);
    int             usmDHUserKeyTable_undo(usmDHUserKeyTable_rowreq_ctx *
                                           rowreq_ctx);
    int             usmDHUserKeyTable_commit(usmDHUserKeyTable_rowreq_ctx *
                                             rowreq_ctx);
    int            
        usmDHUserKeyTable_undo_commit(usmDHUserKeyTable_rowreq_ctx *
                                      rowreq_ctx);
    int            
        usmDHUserKeyTable_irreversible_commit(usmDHUserKeyTable_rowreq_ctx
                                              * rowreq_ctx);


    int            
        usmDHUserAuthKeyChange_check_value(usmDHUserKeyTable_rowreq_ctx *
                                           rowreq_ctx, char
                                           *usmDHUserAuthKeyChange_val_ptr, size_t
                                           usmDHUserAuthKeyChange_val_ptr_len);
    int            
        usmDHUserAuthKeyChange_undo_setup(usmDHUserKeyTable_rowreq_ctx *
                                          rowreq_ctx);
    int             usmDHUserAuthKeyChange_set(usmDHUserKeyTable_rowreq_ctx
                                               * rowreq_ctx, char
                                               *usmDHUserAuthKeyChange_val_ptr, size_t
                                               usmDHUserAuthKeyChange_val_ptr_len);
    int            
        usmDHUserAuthKeyChange_undo(usmDHUserKeyTable_rowreq_ctx *
                                    rowreq_ctx);

    int            
        usmDHUserOwnAuthKeyChange_check_value(usmDHUserKeyTable_rowreq_ctx
                                              * rowreq_ctx, char
                                              *usmDHUserOwnAuthKeyChange_val_ptr, size_t
                                              usmDHUserOwnAuthKeyChange_val_ptr_len);
    int            
        usmDHUserOwnAuthKeyChange_undo_setup(usmDHUserKeyTable_rowreq_ctx *
                                             rowreq_ctx);
    int            
        usmDHUserOwnAuthKeyChange_set(usmDHUserKeyTable_rowreq_ctx *
                                      rowreq_ctx, char
                                      *usmDHUserOwnAuthKeyChange_val_ptr, size_t
                                      usmDHUserOwnAuthKeyChange_val_ptr_len);
    int            
        usmDHUserOwnAuthKeyChange_undo(usmDHUserKeyTable_rowreq_ctx *
                                       rowreq_ctx);

    int            
        usmDHUserPrivKeyChange_check_value(usmDHUserKeyTable_rowreq_ctx *
                                           rowreq_ctx, char
                                           *usmDHUserPrivKeyChange_val_ptr, size_t
                                           usmDHUserPrivKeyChange_val_ptr_len);
    int            
        usmDHUserPrivKeyChange_undo_setup(usmDHUserKeyTable_rowreq_ctx *
                                          rowreq_ctx);
    int             usmDHUserPrivKeyChange_set(usmDHUserKeyTable_rowreq_ctx
                                               * rowreq_ctx, char
                                               *usmDHUserPrivKeyChange_val_ptr, size_t
                                               usmDHUserPrivKeyChange_val_ptr_len);
    int            
        usmDHUserPrivKeyChange_undo(usmDHUserKeyTable_rowreq_ctx *
                                    rowreq_ctx);

    int            
        usmDHUserOwnPrivKeyChange_check_value(usmDHUserKeyTable_rowreq_ctx
                                              * rowreq_ctx, char
                                              *usmDHUserOwnPrivKeyChange_val_ptr, size_t
                                              usmDHUserOwnPrivKeyChange_val_ptr_len);
    int            
        usmDHUserOwnPrivKeyChange_undo_setup(usmDHUserKeyTable_rowreq_ctx *
                                             rowreq_ctx);
    int            
        usmDHUserOwnPrivKeyChange_set(usmDHUserKeyTable_rowreq_ctx *
                                      rowreq_ctx, char
                                      *usmDHUserOwnPrivKeyChange_val_ptr, size_t
                                      usmDHUserOwnPrivKeyChange_val_ptr_len);
    int            
        usmDHUserOwnPrivKeyChange_undo(usmDHUserKeyTable_rowreq_ctx *
                                       rowreq_ctx);


    int            
        usmDHUserKeyTable_check_dependencies(usmDHUserKeyTable_rowreq_ctx *
                                             ctx);


#ifdef __cplusplus
}
#endif
#endif                          /* USMDHUSERKEYTABLE_DATA_SET_H */