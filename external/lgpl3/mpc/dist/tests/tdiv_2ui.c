/* tdiv_2ui -- test file for mpc_div_2ui.

Copyright (C) 2008, 2012, 2013 INRIA

This file is part of GNU MPC.

GNU MPC is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the
Free Software Foundation; either version 3 of the License, or (at your
option) any later version.

GNU MPC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General Public License
along with this program. If not, see http://www.gnu.org/licenses/ .
*/

#include "mpc-tests.h"

#define MPC_FUNCTION_CALL                                               \
  P[0].mpc_inex = mpc_div_2ui (P[1].mpc, P[2].mpc, P[3].ui, P[4].mpc_rnd)
#define MPC_FUNCTION_CALL_REUSE_OP1                                     \
  P[0].mpc_inex = mpc_div_2ui (P[1].mpc, P[1].mpc, P[3].ui, P[4].mpc_rnd)

#include "tgeneric.tpl"

int
main (void)
{
  test_start ();

  tgeneric_template ("div_2ui.dsc", 2, 1024, 7, 1024);

  test_end ();

  return 0;
}
