###############################################################################
#
# Copyright (C) 2005 - 2014 Xilinx, Inc.  All rights reserved.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# Use of the Software is limited solely to applications:
# (a) running on a Xilinx device, or
# (b) that interact with a Xilinx device through a bus or interconnect.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
# XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
# WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
# OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#
# Except as contained in this notice, the name of the Xilinx shall not be used
# in advertising or otherwise to promote the sale, use or other dealings in
# this Software without prior written authorization from Xilinx.
#
###############################################################################
#
# Modification History
#
# Ver   Who  Date     Changes
# ----- ---- -------- -----------------------------------------------
# 2.00a sdm  07/26/10 Updated to use the string "Axi_Fifo" in canonical
#                     definitions for AxiFifo
# 3.00a adk  08/10/13 Added parameters C_AXI4_BASEADDR and C_AXI4_HIGHADDR
#		      and C_DATA_INTERFACE_TYPE inorder to support AXI4 
#		      Datainterface.
# 4.0      adk    12/10/13 Updated as per the New Tcl API's
#
##############################################################################


proc generate {drv_handle} {
    ::hsi::utils::define_include_file $drv_handle "xparameters.h" "XLlFifo"  "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR"  "C_AXI4_BASEADDR" "C_AXI4_HIGHADDR" "C_DATA_INTERFACE_TYPE"

    ::hsi::utils::define_canonical_xpars $drv_handle "xparameters.h" "Axi_Fifo" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" "C_AXI4_BASEADDR" "C_AXI4_HIGHADDR" "C_DATA_INTERFACE_TYPE"
		
   ::hsi::utils::define_config_file $drv_handle "xllfifo_g.c" "XLlFifo"  "DEVICE_ID" "C_BASEADDR" "C_AXI4_BASEADDR" "C_DATA_INTERFACE_TYPE"
}