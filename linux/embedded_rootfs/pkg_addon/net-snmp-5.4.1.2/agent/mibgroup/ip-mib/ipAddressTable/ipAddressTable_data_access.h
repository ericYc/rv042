/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.17 $ of : mfd-data-access.m2c,v $
 *
 * $Id: ipAddressTable_data_access.h 1786 2008-11-10 13:36:41Z richie $
 */
#ifndef IPADDRESSTABLE_DATA_ACCESS_H
#define IPADDRESSTABLE_DATA_ACCESS_H

#ifdef __cplusplus
extern          "C" {
#endif


    /*
     *********************************************************************
     * function declarations
     */

    /*
     *********************************************************************
     * Table declarations
     */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ipAddressTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * IP-MIB::ipAddressTable is subid 34 of ip.
     * Its status is Current.
     * OID: .1.3.6.1.2.1.4.34, length: 8
     */


    int             ipAddressTable_init_data(ipAddressTable_registration *
                                             ipAddressTable_reg);


    /*
     * TODO:180:o: Review ipAddressTable cache timeout.
     * The number of seconds before the cache times out
     */
#define IPADDRESSTABLE_CACHE_TIMEOUT   60

    void            ipAddressTable_container_init(netsnmp_container
                                                  **container_ptr_ptr,
                                                  netsnmp_cache * cache);
    void            ipAddressTable_container_shutdown(netsnmp_container
                                                      *container_ptr);

    int             ipAddressTable_container_load(netsnmp_container
                                                  *container);
    void            ipAddressTable_container_free(netsnmp_container
                                                  *container);

    int             ipAddressTable_cache_load(netsnmp_container
                                              *container);
    void            ipAddressTable_cache_free(netsnmp_container
                                              *container);

    int             ipAddressTable_row_prep(ipAddressTable_rowreq_ctx *
                                            rowreq_ctx);

    int
        ipAddressTable_validate_index(ipAddressTable_registration *
                                      ipAddressTable_reg,
                                      ipAddressTable_rowreq_ctx *
                                      rowreq_ctx);
    int             ipAddressAddrType_check_index(ipAddressTable_rowreq_ctx * rowreq_ctx);      /* internal */
    int             ipAddressAddr_check_index(ipAddressTable_rowreq_ctx * rowreq_ctx);  /* internal */


#ifdef __cplusplus
}
#endif
#endif                          /* IPADDRESSTABLE_DATA_ACCESS_H */
