/****************************************************************
 * Copyright (c) 2003-2004, Cavium Networks. All rights reserved.
 *
 * This Software is the property of Cavium Networks.  The Software and all
 * accompanying documentation are copyrighted.  The Software made available
 * here constitutes the proprietary information of Cavium Networks.  You
 * agree to take reasonable steps to prevent the disclosure, unauthorized use
 * or unauthorized distribution of the Software.  You shall use this Software
 * solely with Cavium hardware.
 *
 * Except as expressly permitted in a separate Software License Agreement
 * between You and Cavium Networks, you shall not modify, decompile,
 * disassemble, extract, or otherwise reverse engineer this Software.  You
 * shall not make any copy of the Software or its accompanying documentation,
 * except for copying incident to the ordinary and intended use of the
 * Software and the Underlying Program and except for the making of a single
 * archival copy.
 *
 * This Software, including technical data, may be subject to U.S.  export
 * control laws, including the U.S.  Export Administration Act and its
 * associated regulations, and may be subject to export or import regulations
 * in other countries.  You warrant that You will comply strictly in all
 * respects with all such regulations and acknowledge that you have the
 * responsibility to obtain licenses to export, re-export or import the
 * Software.
 *
 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
 * AND WITH ALL FAULTS AND CAVIUM MAKES NO PROMISES, REPRESENTATIONS OR
 * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT
 * TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY
 * REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT
 * DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES
 * OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR
 * PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET
 * POSSESSION OR CORRESPONDENCE TO DESCRIPTION.  THE ENTIRE RISK ARISING OUT
 * OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.
 *
 **************************************************************************/

/**
 * @file
 *
 * Support library for the hardware DFA engine.
 *
 * $Id: cvmx-dfa.c 2 2007-04-05 08:51:12Z tt $
 */
#include <stdio.h>
#include <string.h>
#include "executive-config.h"
#ifdef CVMX_ENABLE_DFA_FUNCTIONS

#include "cvmx-config.h"
#include "cvmx.h"
#include "cvmx-fau.h"
#include "cvmx-dfa.h"
CVMX_SHARED cvmx_dfa_state_t cvmx_dfa_state;



/**
 * Initialize the DFA hardware before use
 */
int cvmx_dfa_initialize(void)
{
    cvmx_dfa_difctl_t control;
    void *initial_base_address;
    cvmx_dfa_state_t initial_state;
    if (!cvmx_octeon_dfa_present())
    {
        cvmx_dprintf("ERROR: attempting to initialize DFA when no DFA hardware present\n.");
        return -1;
    }

    memset(&cvmx_dfa_state, 0, sizeof(cvmx_dfa_state));

    control.u64 = 0;
    control.s.dwbcnt = CVMX_FPA_DFA_POOL_SIZE / 128;
    control.s.pool = CVMX_FPA_DFA_POOL;
    control.s.size = (CVMX_FPA_DFA_POOL_SIZE - 8) / sizeof(cvmx_dfa_command_t);
    CVMX_SYNCWS;
    cvmx_write_csr(CVMX_DFA_DIFCTL, control.u64);

    initial_base_address = cvmx_fpa_alloc(CVMX_FPA_DFA_POOL);

    initial_state.u64 = 0;
    initial_state.s.base_address_div16 = (CAST64(initial_base_address))/16;
    cvmx_fau_atomic_write64(CVMX_FAU_DFA_STATE, initial_state.u64);

    CVMX_SYNCWS;
    cvmx_write_csr(CVMX_DFA_DIFRDPTR, cvmx_ptr_to_phys(initial_base_address));

    return 0;
}


/**
 * Shutdown and cleanup resources used by the DFA
 */
void cvmx_dfa_shutdown(void)
{
    void *final_base_address;
    cvmx_dfa_state_t final_state;

    CVMX_SYNCWS;

    final_state.u64 = cvmx_fau_fetch_and_add64(CVMX_FAU_DFA_STATE, 0);

    // make sure the carry is clear
    final_base_address = CASTPTR(void, (final_state.s2.base_address_div32 * 32ull));

    if (final_base_address)
    {
        cvmx_fpa_free(final_base_address, CVMX_FPA_DFA_POOL, 0);
    }

    CVMX_SYNCWS;
    final_state.u64 = 0;
    cvmx_fau_atomic_write64(CVMX_FAU_DFA_STATE, final_state.u64);
}

#endif
