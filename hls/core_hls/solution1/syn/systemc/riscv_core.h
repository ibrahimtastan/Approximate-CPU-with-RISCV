// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.1
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _riscv_core_HH_
#define _riscv_core_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "datapath.h"

namespace ap_rtl {

struct riscv_core : public sc_module {
    // Port declarations 6
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;


    // Module declarations
    riscv_core(sc_module_name name);
    SC_HAS_PROCESS(riscv_core);

    ~riscv_core();

    sc_trace_file* mVcdFile;

    ofstream mHdltvinHandle;
    ofstream mHdltvoutHandle;
    datapath* grp_datapath_fu_14;
    sc_signal< sc_lv<2> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<32> > PC;
    sc_signal< sc_logic > grp_datapath_fu_14_ap_start;
    sc_signal< sc_logic > grp_datapath_fu_14_ap_done;
    sc_signal< sc_logic > grp_datapath_fu_14_ap_idle;
    sc_signal< sc_logic > grp_datapath_fu_14_ap_ready;
    sc_signal< sc_lv<32> > grp_datapath_fu_14_ap_return;
    sc_signal< sc_logic > grp_datapath_fu_14_ap_start_reg;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_lv<32> > PC_assign_i_fu_30_p2;
    sc_signal< sc_lv<2> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<2> ap_ST_fsm_state1;
    static const sc_lv<2> ap_ST_fsm_state2;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_PC_assign_i_fu_30_p2();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state2();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_grp_datapath_fu_14_ap_start();
    void thread_ap_NS_fsm();
    void thread_hdltv_gen();
};

}

using namespace ap_rtl;

#endif
