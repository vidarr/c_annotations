/*
 * (C) 2019 Michael J. Beer
 *
 * All rights reserved.
 *
 * Redistribution  and use in source and binary forms, with or with‐
 * out modification, are permitted provided that the following  con‐
 * ditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above  copy‐
 * right  notice,  this  list  of  conditions and the following dis‐
 * claimer in the documentation and/or other materials provided with
 * the distribution.
 *
 * 3.  Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote  products  derived
 * from this software without specific prior written permission.
 *
 * THIS  SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBU‐
 * TORS "AS IS" AND ANY EXPRESS OR  IMPLIED  WARRANTIES,  INCLUDING,
 * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE  ARE  DISCLAIMED.  IN  NO  EVENT
 * SHALL  THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DI‐
 * RECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS IN‐
 * TERRUPTION)  HOWEVER  CAUSED  AND  ON  ANY  THEORY  OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  NEGLI‐
 * GENCE  OR  OTHERWISE)  ARISING  IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/**
 * Define some useful code annotations.
 * All annotations aim at 2 things:
 *    1. Make the code readable by replacing obfuscated bits like (void)(arg) with UNUSED(arg);
 *    2. Have the compiler / the program make you hint at stuff when DEBUG is set
 */
#ifndef ANNOTATIONS_H
#define ANNOTATIONS_H

#if __STDC_VERSION__ < 201112L
#    error("C11 support required")
#endif

#include <stdio.h>
/*----------------------------------------------------------------------------*/

#define TODO(msg) INTERNAL_TODO(msg)

/**
 * Declare a variable / argument as 'unused'. Useful for callbacks that require an
 * fixed prototype.
 */
#define UNUSED(arg) INTERNAL_UNUSED(arg)

/**
 * Declare a function as deprecated like
 *
 * DEPRECATED("Use random(3) instead")
 */
#define DEPRECATED(msg) INTERNAL_DEPRECATED(msg)

/*----------------------------------------------------------------------------
 *
 *BEWARE:
 *
 *    EVERYTHING BELOW IS ACTUALLY INTERNAL AND NO USERSHOULD CARE
 *    ABOUT THE INTERNAL IMPLEMENTATION.
 *
 *    I'D RATHER HIDE IT IN AN EXTERNAL FILE, BUT UNFORTUNATELY, SINCE
 *    MOST OF THE STUFF REQUIRES PP MACROS, IT NEEDS TO BE included into
 *    the source using them.
 *
*----------------------------------------------------------------------------*/

#define INTERNAL_UNUSED(arg) (void)(arg)

/*----------------------------------------------------------------------------*/

#ifdef __GNUC__

#if (__GNUC__ > 5) || (__GNUC__ > 4 && __GNUC_MINOR__ > 5)

/* attribute deprecated with message supported since gcc v4.5
 * [https://www.gnu.org/software/gcc/gcc-4.5/changes.html](GCC 4.5) */

#define INTERNAL_DEPRECATED(msg) __attribute__((deprecated(msg)))

#else

/* Unknown since which compiler version deprecated attribute supported ... */
#define INTERNAL_DEPRECATED(msg) __attribute__((deprecated))

#endif /* __GNUC__ > 5 ... */

#else

/* Unknown compiler ... */

#define INTERNAL_DEPRECATED(msg)

#endif /* ifdef __GNUC__ */

/*----------------------------------------------------------------------------*/

#ifdef DEBUG

#define INTERNAL_TODO(msg)                                                   \
    fprintf(stderr, "TODO: %s(%d) %s(): %s\n", __FILE__, __LINE__, __func__, \
            (msg))

#else

#define INTERNAL_TODO(msg)

#endif /* ifdef DEBUG */

/*----------------------------------------------------------------------------*/
#endif /* ifdef ANNOTATIONS_H */
