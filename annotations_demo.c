/*
 * (C) 2019 Michael J. Beer
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

#include "annotations.h"

#include <stdlib.h>

/*----------------------------------------------------------------------------*/

void arbitrary_function() {

    TODO("Imlementation pending");

}

/*----------------------------------------------------------------------------*/

void function_with_unused_arg_no_unused(int i) {

    printf("I am not using my argument!\n");

}

/*----------------------------------------------------------------------------*/

void function_with_unused_arg(int i) {

    UNUSED(i);
    printf("I am not using my argument!\n");

}

/*----------------------------------------------------------------------------*/

DEPRECATED("Use useless_function() instead")
void deprecated_function () {
    printf("I am deprecated!");
}

/*----------------------------------------------------------------------------*/

int main(int argc, char **argv) {

    UNUSED(argc);
    UNUSED(argv);

    fprintf(stdout, "Some demos ...\n");

    printf("\nTODO() macro:\n");
    arbitrary_function();

    printf("\nUnused argument without UNUSED():\n");
    function_with_unused_arg_no_unused(13);

    printf("\nUnused argument with UNUSED():\n");
    function_with_unused_arg(13);

    printf("\nDeprecated function:\n");
    deprecated_function();

    return EXIT_SUCCESS;
}
