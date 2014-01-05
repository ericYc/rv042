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
 * Module to support operations on bitmap of cores. Coremask can be used to
 * select a specific core, a group of cores, or all available cores, for
 * initialization and differentiation of roles within a single shared binary
 * executable image.
 *
 * $Id: cvmx-coremask.c 2 2007-04-05 08:51:12Z tt $ $Name$
 *
 */

#include <assert.h>

#include "cvmx-config.h"
#include "cvmx.h"
#include "cvmx-spinlock.h"
#include "cvmx-coremask.h"


#define  CVMX_COREMASK_MAX_SYNCS  20  /* maximum number of coremasks for barrier sync */

/**
 * This structure defines the private state maintained by coremask module.
 *
 */
CVMX_SHARED static struct {

    cvmx_spinlock_t            lock;       /**< mutex spinlock */

    struct {

        unsigned int           coremask;   /**< coremask specified for barrier */
        unsigned int           checkin;    /**< bitmask of cores checking in */
        volatile unsigned int  exit;       /**< variable to poll for exit condition */

    } s[CVMX_COREMASK_MAX_SYNCS];

} state = {

    { CVMX_SPINLOCK_UNLOCKED_VAL },

    { { 0, 0, 0 } },
};


/**
 * Wait (stall) until all cores in the given coremask has reached this point
 * in the program execution before proceeding.
 *
 * @param  coremask  the group of cores performing the barrier sync
 *
 */
void cvmx_coremask_barrier_sync(unsigned int coremask)
{
    int i;
    unsigned int target;

    assert(coremask != 0);

    cvmx_spinlock_lock(&state.lock);

    for (i = 0; i < CVMX_COREMASK_MAX_SYNCS; i++) {

        if (state.s[i].coremask == 0) {
            /* end of existing coremask list, create new entry, fall-thru */
            state.s[i].coremask = coremask;
        }

        if (state.s[i].coremask == coremask) {

            target = state.s[i].exit + 1;  /* wrap-around at 32b */

            state.s[i].checkin |= cvmx_coremask_core(cvmx_get_core_num());
            if (state.s[i].checkin == coremask) {
                state.s[i].checkin = 0;
                state.s[i].exit = target;  /* signal exit condition */
            }
            cvmx_spinlock_unlock(&state.lock);

            while (state.s[i].exit != target)
                ;

            return;
        }
    }

    /* error condition - coremask array overflowed */
    cvmx_spinlock_unlock(&state.lock);
    assert(0);
}
