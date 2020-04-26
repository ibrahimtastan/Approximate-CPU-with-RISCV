// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.1
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "approx_mul.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic approx_mul::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic approx_mul::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<2> approx_mul::ap_ST_fsm_state1 = "1";
const sc_lv<2> approx_mul::ap_ST_fsm_state2 = "10";
const sc_lv<32> approx_mul::ap_const_lv32_0 = "00000000000000000000000000000000";
const sc_lv<32> approx_mul::ap_const_lv32_1 = "1";
const sc_lv<32> approx_mul::ap_const_lv32_1C = "11100";
const sc_lv<32> approx_mul::ap_const_lv32_1D = "11101";
const sc_lv<32> approx_mul::ap_const_lv32_1E = "11110";
const sc_lv<32> approx_mul::ap_const_lv32_1F = "11111";
const sc_lv<32> approx_mul::ap_const_lv32_12 = "10010";
const sc_lv<32> approx_mul::ap_const_lv32_10 = "10000";
const sc_lv<32> approx_mul::ap_const_lv32_13 = "10011";
const sc_lv<32> approx_mul::ap_const_lv32_6 = "110";
const sc_lv<32> approx_mul::ap_const_lv32_3 = "11";
const sc_lv<32> approx_mul::ap_const_lv32_14 = "10100";
const sc_lv<32> approx_mul::ap_const_lv32_19 = "11001";
const sc_lv<18> approx_mul::ap_const_lv18_0 = "000000000000000000";
const sc_lv<32> approx_mul::ap_const_lv32_2 = "10";
const sc_lv<32> approx_mul::ap_const_lv32_B = "1011";
const sc_lv<32> approx_mul::ap_const_lv32_9 = "1001";
const sc_lv<32> approx_mul::ap_const_lv32_16 = "10110";
const sc_lv<32> approx_mul::ap_const_lv32_7 = "111";
const sc_lv<32> approx_mul::ap_const_lv32_8 = "1000";
const sc_lv<1> approx_mul::ap_const_lv1_0 = "0";
const sc_lv<5> approx_mul::ap_const_lv5_0 = "00000";
const sc_lv<2> approx_mul::ap_const_lv2_0 = "00";
const sc_lv<7> approx_mul::ap_const_lv7_0 = "0000000";
const sc_lv<3> approx_mul::ap_const_lv3_0 = "000";
const sc_lv<27> approx_mul::ap_const_lv27_1000000 = "1000000000000000000000000";
const sc_lv<8> approx_mul::ap_const_lv8_0 = "00000000";
const sc_lv<20> approx_mul::ap_const_lv20_0 = "00000000000000000000";
const sc_lv<32> approx_mul::ap_const_lv32_1A = "11010";
const sc_lv<6> approx_mul::ap_const_lv6_0 = "000000";
const sc_lv<11> approx_mul::ap_const_lv11_0 = "00000000000";
const sc_lv<32> approx_mul::ap_const_lv32_F = "1111";
const sc_lv<32> approx_mul::ap_const_lv32_1B = "11011";
const sc_lv<32> approx_mul::ap_const_lv32_40 = "1000000";
const bool approx_mul::ap_const_boolean_1 = true;

approx_mul::approx_mul(sc_module_name name) : sc_module(name), mVcdFile(0) {

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_ap_CS_fsm_state1);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state2);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_done);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( ap_CS_fsm_state2 );

    SC_METHOD(thread_ap_idle);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );

    SC_METHOD(thread_ap_ready);
    sensitive << ( ap_CS_fsm_state2 );

    SC_METHOD(thread_ap_return);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( tmp_73_fu_776_p2 );
    sensitive << ( ap_return_preg );

    SC_METHOD(thread_sig_1015_fu_232_p2);
    sensitive << ( tmp_55_fu_162_p3 );
    sensitive << ( tmp_58_fu_186_p3 );

    SC_METHOD(thread_sig_1058_fu_238_p2);
    sensitive << ( tmp_54_fu_154_p3 );
    sensitive << ( tmp_57_fu_178_p3 );

    SC_METHOD(thread_sig_1219_fu_244_p2);
    sensitive << ( tmp_60_fu_194_p3 );
    sensitive << ( tmp_54_fu_154_p3 );

    SC_METHOD(thread_sig_1405_fu_250_p2);
    sensitive << ( sig_504_fu_220_p2 );
    sensitive << ( sig_1058_fu_238_p2 );

    SC_METHOD(thread_sig_158_fu_202_p2);
    sensitive << ( tmp_60_fu_194_p3 );
    sensitive << ( tmp_52_fu_138_p3 );

    SC_METHOD(thread_sig_2089_fu_256_p2);
    sensitive << ( sig_504_fu_220_p2 );
    sensitive << ( sig_1058_fu_238_p2 );

    SC_METHOD(thread_sig_2643_fu_268_p2);
    sensitive << ( tmp_58_fu_186_p3 );
    sensitive << ( tmp3_fu_262_p2 );

    SC_METHOD(thread_sig_2740_fu_274_p2);
    sensitive << ( sig_2089_fu_256_p2 );
    sensitive << ( sig_827_fu_226_p2 );

    SC_METHOD(thread_sig_280_fu_208_p2);
    sensitive << ( tmp_58_fu_186_p3 );
    sensitive << ( tmp_54_fu_154_p3 );

    SC_METHOD(thread_sig_3272_fu_280_p2);
    sensitive << ( sig_2740_fu_274_p2 );
    sensitive << ( sig_280_fu_208_p2 );

    SC_METHOD(thread_sig_3383_fu_286_p2);
    sensitive << ( sig_2740_fu_274_p2 );
    sensitive << ( sig_280_fu_208_p2 );

    SC_METHOD(thread_sig_3438_fu_292_p2);
    sensitive << ( sig_3272_fu_280_p2 );
    sensitive << ( sig_2643_fu_268_p2 );

    SC_METHOD(thread_sig_3452_fu_298_p2);
    sensitive << ( sig_2089_fu_256_p2 );
    sensitive << ( sig_3383_fu_286_p2 );

    SC_METHOD(thread_sig_3760_fu_304_p2);
    sensitive << ( sig_3272_fu_280_p2 );
    sensitive << ( sig_2643_fu_268_p2 );

    SC_METHOD(thread_sig_3974_fu_310_p2);
    sensitive << ( sig_481_fu_214_p2 );
    sensitive << ( sig_3760_fu_304_p2 );

    SC_METHOD(thread_sig_3992_fu_316_p2);
    sensitive << ( sig_481_fu_214_p2 );
    sensitive << ( sig_3760_fu_304_p2 );

    SC_METHOD(thread_sig_4402_fu_322_p2);
    sensitive << ( sig_3992_fu_316_p2 );
    sensitive << ( sig_3438_fu_292_p2 );

    SC_METHOD(thread_sig_481_fu_214_p2);
    sensitive << ( tmp_60_fu_194_p3 );
    sensitive << ( tmp_53_fu_146_p3 );

    SC_METHOD(thread_sig_504_fu_220_p2);
    sensitive << ( tmp_55_fu_162_p3 );
    sensitive << ( tmp_56_fu_170_p3 );

    SC_METHOD(thread_sig_5314_fu_328_p2);
    sensitive << ( sig_158_fu_202_p2 );
    sensitive << ( sig_3974_fu_310_p2 );

    SC_METHOD(thread_sig_5458_fu_352_p2);
    sensitive << ( tmp5_fu_346_p2 );
    sensitive << ( tmp4_fu_334_p2 );

    SC_METHOD(thread_sig_810_cast_fu_397_p1);
    sensitive << ( sig_810_fu_393_p2 );

    SC_METHOD(thread_sig_810_fu_393_p2);
    sensitive << ( tmp_55_reg_802 );
    sensitive << ( tmp_60_reg_807 );

    SC_METHOD(thread_sig_827_fu_226_p2);
    sensitive << ( tmp_55_fu_162_p3 );
    sensitive << ( tmp_57_fu_178_p3 );

    SC_METHOD(thread_tmp22_fu_770_p2);
    sensitive << ( tmp29_fu_762_p3 );
    sensitive << ( tmp8_fu_510_p24 );

    SC_METHOD(thread_tmp23_fu_577_p2);
    sensitive << ( tmp26_fu_555_p12 );

    SC_METHOD(thread_tmp26_fu_555_p12);
    sensitive << ( sig_158_reg_812 );
    sensitive << ( sig_481_reg_817 );
    sensitive << ( sig_504_reg_822 );
    sensitive << ( tmp_80_reg_860 );
    sensitive << ( tmp_88_fu_487_p3 );
    sensitive << ( tmp_87_fu_480_p3 );
    sensitive << ( tmp_81_fu_421_p3 );

    SC_METHOD(thread_tmp29_fu_762_p3);
    sensitive << ( tmp_72_fu_752_p4 );
    sensitive << ( tmp_71_fu_746_p2 );

    SC_METHOD(thread_tmp30_fu_670_p3);
    sensitive << ( tmp_63_fu_654_p4 );
    sensitive << ( tmp_62_fu_648_p2 );

    SC_METHOD(thread_tmp32_fu_603_p5);
    sensitive << ( sig_3452_reg_837 );
    sensitive << ( sig_3992_reg_843 );

    SC_METHOD(thread_tmp33_fu_734_p2);
    sensitive << ( tmp35_fu_718_p3 );
    sensitive << ( tmp30_fu_670_p3 );

    SC_METHOD(thread_tmp34_fu_678_p5);
    sensitive << ( sig_3992_reg_843 );
    sensitive << ( sig_5314_reg_849 );

    SC_METHOD(thread_tmp35_fu_718_p3);
    sensitive << ( tmp_66_fu_698_p4 );
    sensitive << ( tmp_65_fu_692_p2 );

    SC_METHOD(thread_tmp3_fu_262_p2);
    sensitive << ( sig_1405_fu_250_p2 );
    sensitive << ( tmp_53_fu_146_p3 );

    SC_METHOD(thread_tmp4_fu_334_p2);
    sensitive << ( sig_3452_fu_298_p2 );
    sensitive << ( sig_1015_fu_232_p2 );

    SC_METHOD(thread_tmp5_fu_346_p2);
    sensitive << ( tmp6_fu_340_p2 );
    sensitive << ( sig_1219_fu_244_p2 );

    SC_METHOD(thread_tmp6_fu_340_p2);
    sensitive << ( sig_5314_fu_328_p2 );
    sensitive << ( sig_4402_fu_322_p2 );

    SC_METHOD(thread_tmp7_fu_374_p2);
    sensitive << ( sig_158_fu_202_p2 );
    sensitive << ( sig_3974_fu_310_p2 );

    SC_METHOD(thread_tmp8_fu_510_p24);
    sensitive << ( sig_1058_reg_827 );
    sensitive << ( tmp_70_reg_854 );
    sensitive << ( tmp_80_reg_860 );
    sensitive << ( tmp_89_fu_494_p3 );
    sensitive << ( tmp_86_fu_473_p3 );
    sensitive << ( tmp_85_fu_466_p3 );
    sensitive << ( tmp_fu_386_p3 );
    sensitive << ( tmp_84_fu_442_p3 );
    sensitive << ( tmp_83_fu_435_p3 );
    sensitive << ( tmp_82_fu_428_p3 );
    sensitive << ( tmp_47_fu_501_p4 );
    sensitive << ( tmp_79_fu_401_p3 );

    SC_METHOD(thread_tmp_42_fu_411_p1);
    sensitive << ( size_op1 );

    SC_METHOD(thread_tmp_43_fu_415_p2);
    sensitive << ( tmp_97_cast_fu_408_p1 );
    sensitive << ( tmp_42_fu_411_p1 );

    SC_METHOD(thread_tmp_44_fu_449_p1);
    sensitive << ( size_op2 );

    SC_METHOD(thread_tmp_45_fu_453_p2);
    sensitive << ( sig_810_cast_fu_397_p1 );
    sensitive << ( tmp_44_fu_449_p1 );

    SC_METHOD(thread_tmp_46_fu_459_p3);
    sensitive << ( sig_1405_reg_832 );

    SC_METHOD(thread_tmp_47_fu_501_p4);
    sensitive << ( opA );

    SC_METHOD(thread_tmp_48_fu_587_p2);
    sensitive << ( tmp_90_fu_583_p1 );
    sensitive << ( tmp_46_fu_459_p3 );

    SC_METHOD(thread_tmp_49_fu_593_p4);
    sensitive << ( tmp_45_fu_453_p2 );

    SC_METHOD(thread_tmp_50_fu_613_p4);
    sensitive << ( tmp_45_fu_453_p2 );

    SC_METHOD(thread_tmp_51_fu_623_p3);
    sensitive << ( tmp_49_fu_593_p4 );
    sensitive << ( tmp_48_fu_587_p2 );

    SC_METHOD(thread_tmp_52_fu_138_p3);
    sensitive << ( opA );

    SC_METHOD(thread_tmp_53_fu_146_p3);
    sensitive << ( opA );

    SC_METHOD(thread_tmp_54_fu_154_p3);
    sensitive << ( opA );

    SC_METHOD(thread_tmp_55_fu_162_p3);
    sensitive << ( opA );

    SC_METHOD(thread_tmp_56_fu_170_p3);
    sensitive << ( opB );

    SC_METHOD(thread_tmp_57_fu_178_p3);
    sensitive << ( opB );

    SC_METHOD(thread_tmp_58_fu_186_p3);
    sensitive << ( opB );

    SC_METHOD(thread_tmp_59_fu_631_p4);
    sensitive << ( sig_3452_reg_837 );

    SC_METHOD(thread_tmp_60_fu_194_p3);
    sensitive << ( opB );

    SC_METHOD(thread_tmp_61_fu_640_p3);
    sensitive << ( tmp_48_fu_587_p2 );
    sensitive << ( tmp_50_fu_613_p4 );

    SC_METHOD(thread_tmp_62_fu_648_p2);
    sensitive << ( tmp_51_fu_623_p3 );
    sensitive << ( tmp32_fu_603_p5 );

    SC_METHOD(thread_tmp_63_fu_654_p4);
    sensitive << ( tmp_45_fu_453_p2 );

    SC_METHOD(thread_tmp_64_fu_664_p2);
    sensitive << ( tmp_61_fu_640_p3 );
    sensitive << ( tmp_59_fu_631_p4 );

    SC_METHOD(thread_tmp_65_fu_692_p2);
    sensitive << ( tmp_91_fu_688_p1 );
    sensitive << ( tmp34_fu_678_p5 );

    SC_METHOD(thread_tmp_66_fu_698_p4);
    sensitive << ( tmp_43_fu_415_p2 );

    SC_METHOD(thread_tmp_67_fu_708_p4);
    sensitive << ( tmp_43_fu_415_p2 );

    SC_METHOD(thread_tmp_68_fu_726_p3);
    sensitive << ( tmp_65_fu_692_p2 );
    sensitive << ( tmp_67_fu_708_p4 );

    SC_METHOD(thread_tmp_69_fu_740_p2);
    sensitive << ( tmp_68_fu_726_p3 );
    sensitive << ( tmp_64_fu_664_p2 );

    SC_METHOD(thread_tmp_71_fu_746_p2);
    sensitive << ( tmp_69_fu_740_p2 );
    sensitive << ( tmp23_fu_577_p2 );

    SC_METHOD(thread_tmp_72_fu_752_p4);
    sensitive << ( tmp33_fu_734_p2 );

    SC_METHOD(thread_tmp_73_fu_776_p2);
    sensitive << ( tmp22_fu_770_p2 );

    SC_METHOD(thread_tmp_79_fu_401_p3);
    sensitive << ( opA );

    SC_METHOD(thread_tmp_81_fu_421_p3);
    sensitive << ( opB );

    SC_METHOD(thread_tmp_82_fu_428_p3);
    sensitive << ( opB );

    SC_METHOD(thread_tmp_83_fu_435_p3);
    sensitive << ( opA );

    SC_METHOD(thread_tmp_84_fu_442_p3);
    sensitive << ( opA );

    SC_METHOD(thread_tmp_85_fu_466_p3);
    sensitive << ( opA );

    SC_METHOD(thread_tmp_86_fu_473_p3);
    sensitive << ( opA );

    SC_METHOD(thread_tmp_87_fu_480_p3);
    sensitive << ( opB );

    SC_METHOD(thread_tmp_88_fu_487_p3);
    sensitive << ( opB );

    SC_METHOD(thread_tmp_89_fu_494_p3);
    sensitive << ( opB );

    SC_METHOD(thread_tmp_90_fu_583_p1);
    sensitive << ( tmp_45_fu_453_p2 );

    SC_METHOD(thread_tmp_91_fu_688_p1);
    sensitive << ( tmp_43_fu_415_p2 );

    SC_METHOD(thread_tmp_97_cast_fu_408_p1);
    sensitive << ( tmp_s_reg_867 );

    SC_METHOD(thread_tmp_fu_386_p3);
    sensitive << ( opA );

    SC_METHOD(thread_tmp_s_fu_380_p2);
    sensitive << ( tmp7_fu_374_p2 );
    sensitive << ( sig_5458_fu_352_p2 );

    SC_METHOD(thread_ap_NS_fsm);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm );
    sensitive << ( ap_CS_fsm_state1 );

    ap_CS_fsm = "01";
    ap_return_preg = "00000000000000000000000000000000";
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "approx_mul_sc_trace_" << apTFileNum ++;
    string apTFn = apTFilenSS.str();
    mVcdFile = sc_create_vcd_trace_file(apTFn.c_str());
    mVcdFile->set_time_unit(1, SC_PS);
    if (1) {
#ifdef __HLS_TRACE_LEVEL_PORT_HIER__
    sc_trace(mVcdFile, ap_clk, "(port)ap_clk");
    sc_trace(mVcdFile, ap_rst, "(port)ap_rst");
    sc_trace(mVcdFile, ap_start, "(port)ap_start");
    sc_trace(mVcdFile, ap_done, "(port)ap_done");
    sc_trace(mVcdFile, ap_idle, "(port)ap_idle");
    sc_trace(mVcdFile, ap_ready, "(port)ap_ready");
    sc_trace(mVcdFile, opA, "(port)opA");
    sc_trace(mVcdFile, opB, "(port)opB");
    sc_trace(mVcdFile, size_op1, "(port)size_op1");
    sc_trace(mVcdFile, size_op2, "(port)size_op2");
    sc_trace(mVcdFile, ap_return, "(port)ap_return");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, ap_CS_fsm, "ap_CS_fsm");
    sc_trace(mVcdFile, ap_CS_fsm_state1, "ap_CS_fsm_state1");
    sc_trace(mVcdFile, tmp_55_fu_162_p3, "tmp_55_fu_162_p3");
    sc_trace(mVcdFile, tmp_55_reg_802, "tmp_55_reg_802");
    sc_trace(mVcdFile, tmp_60_fu_194_p3, "tmp_60_fu_194_p3");
    sc_trace(mVcdFile, tmp_60_reg_807, "tmp_60_reg_807");
    sc_trace(mVcdFile, sig_158_fu_202_p2, "sig_158_fu_202_p2");
    sc_trace(mVcdFile, sig_158_reg_812, "sig_158_reg_812");
    sc_trace(mVcdFile, sig_481_fu_214_p2, "sig_481_fu_214_p2");
    sc_trace(mVcdFile, sig_481_reg_817, "sig_481_reg_817");
    sc_trace(mVcdFile, sig_504_fu_220_p2, "sig_504_fu_220_p2");
    sc_trace(mVcdFile, sig_504_reg_822, "sig_504_reg_822");
    sc_trace(mVcdFile, sig_1058_fu_238_p2, "sig_1058_fu_238_p2");
    sc_trace(mVcdFile, sig_1058_reg_827, "sig_1058_reg_827");
    sc_trace(mVcdFile, sig_1405_fu_250_p2, "sig_1405_fu_250_p2");
    sc_trace(mVcdFile, sig_1405_reg_832, "sig_1405_reg_832");
    sc_trace(mVcdFile, sig_3452_fu_298_p2, "sig_3452_fu_298_p2");
    sc_trace(mVcdFile, sig_3452_reg_837, "sig_3452_reg_837");
    sc_trace(mVcdFile, sig_3992_fu_316_p2, "sig_3992_fu_316_p2");
    sc_trace(mVcdFile, sig_3992_reg_843, "sig_3992_reg_843");
    sc_trace(mVcdFile, sig_5314_fu_328_p2, "sig_5314_fu_328_p2");
    sc_trace(mVcdFile, sig_5314_reg_849, "sig_5314_reg_849");
    sc_trace(mVcdFile, tmp_70_reg_854, "tmp_70_reg_854");
    sc_trace(mVcdFile, tmp_80_reg_860, "tmp_80_reg_860");
    sc_trace(mVcdFile, tmp_s_fu_380_p2, "tmp_s_fu_380_p2");
    sc_trace(mVcdFile, tmp_s_reg_867, "tmp_s_reg_867");
    sc_trace(mVcdFile, ap_CS_fsm_state2, "ap_CS_fsm_state2");
    sc_trace(mVcdFile, tmp_52_fu_138_p3, "tmp_52_fu_138_p3");
    sc_trace(mVcdFile, tmp_58_fu_186_p3, "tmp_58_fu_186_p3");
    sc_trace(mVcdFile, tmp_54_fu_154_p3, "tmp_54_fu_154_p3");
    sc_trace(mVcdFile, tmp_53_fu_146_p3, "tmp_53_fu_146_p3");
    sc_trace(mVcdFile, tmp_56_fu_170_p3, "tmp_56_fu_170_p3");
    sc_trace(mVcdFile, tmp_57_fu_178_p3, "tmp_57_fu_178_p3");
    sc_trace(mVcdFile, tmp3_fu_262_p2, "tmp3_fu_262_p2");
    sc_trace(mVcdFile, sig_2089_fu_256_p2, "sig_2089_fu_256_p2");
    sc_trace(mVcdFile, sig_827_fu_226_p2, "sig_827_fu_226_p2");
    sc_trace(mVcdFile, sig_2740_fu_274_p2, "sig_2740_fu_274_p2");
    sc_trace(mVcdFile, sig_280_fu_208_p2, "sig_280_fu_208_p2");
    sc_trace(mVcdFile, sig_3272_fu_280_p2, "sig_3272_fu_280_p2");
    sc_trace(mVcdFile, sig_2643_fu_268_p2, "sig_2643_fu_268_p2");
    sc_trace(mVcdFile, sig_3383_fu_286_p2, "sig_3383_fu_286_p2");
    sc_trace(mVcdFile, sig_3760_fu_304_p2, "sig_3760_fu_304_p2");
    sc_trace(mVcdFile, sig_3438_fu_292_p2, "sig_3438_fu_292_p2");
    sc_trace(mVcdFile, sig_3974_fu_310_p2, "sig_3974_fu_310_p2");
    sc_trace(mVcdFile, sig_1015_fu_232_p2, "sig_1015_fu_232_p2");
    sc_trace(mVcdFile, sig_4402_fu_322_p2, "sig_4402_fu_322_p2");
    sc_trace(mVcdFile, tmp6_fu_340_p2, "tmp6_fu_340_p2");
    sc_trace(mVcdFile, sig_1219_fu_244_p2, "sig_1219_fu_244_p2");
    sc_trace(mVcdFile, tmp5_fu_346_p2, "tmp5_fu_346_p2");
    sc_trace(mVcdFile, tmp4_fu_334_p2, "tmp4_fu_334_p2");
    sc_trace(mVcdFile, tmp7_fu_374_p2, "tmp7_fu_374_p2");
    sc_trace(mVcdFile, sig_5458_fu_352_p2, "sig_5458_fu_352_p2");
    sc_trace(mVcdFile, sig_810_fu_393_p2, "sig_810_fu_393_p2");
    sc_trace(mVcdFile, tmp_97_cast_fu_408_p1, "tmp_97_cast_fu_408_p1");
    sc_trace(mVcdFile, tmp_42_fu_411_p1, "tmp_42_fu_411_p1");
    sc_trace(mVcdFile, sig_810_cast_fu_397_p1, "sig_810_cast_fu_397_p1");
    sc_trace(mVcdFile, tmp_44_fu_449_p1, "tmp_44_fu_449_p1");
    sc_trace(mVcdFile, tmp_89_fu_494_p3, "tmp_89_fu_494_p3");
    sc_trace(mVcdFile, tmp_86_fu_473_p3, "tmp_86_fu_473_p3");
    sc_trace(mVcdFile, tmp_85_fu_466_p3, "tmp_85_fu_466_p3");
    sc_trace(mVcdFile, tmp_fu_386_p3, "tmp_fu_386_p3");
    sc_trace(mVcdFile, tmp_84_fu_442_p3, "tmp_84_fu_442_p3");
    sc_trace(mVcdFile, tmp_83_fu_435_p3, "tmp_83_fu_435_p3");
    sc_trace(mVcdFile, tmp_82_fu_428_p3, "tmp_82_fu_428_p3");
    sc_trace(mVcdFile, tmp_47_fu_501_p4, "tmp_47_fu_501_p4");
    sc_trace(mVcdFile, tmp_79_fu_401_p3, "tmp_79_fu_401_p3");
    sc_trace(mVcdFile, tmp_88_fu_487_p3, "tmp_88_fu_487_p3");
    sc_trace(mVcdFile, tmp_87_fu_480_p3, "tmp_87_fu_480_p3");
    sc_trace(mVcdFile, tmp_81_fu_421_p3, "tmp_81_fu_421_p3");
    sc_trace(mVcdFile, tmp26_fu_555_p12, "tmp26_fu_555_p12");
    sc_trace(mVcdFile, tmp_45_fu_453_p2, "tmp_45_fu_453_p2");
    sc_trace(mVcdFile, tmp_90_fu_583_p1, "tmp_90_fu_583_p1");
    sc_trace(mVcdFile, tmp_46_fu_459_p3, "tmp_46_fu_459_p3");
    sc_trace(mVcdFile, tmp_49_fu_593_p4, "tmp_49_fu_593_p4");
    sc_trace(mVcdFile, tmp_48_fu_587_p2, "tmp_48_fu_587_p2");
    sc_trace(mVcdFile, tmp_50_fu_613_p4, "tmp_50_fu_613_p4");
    sc_trace(mVcdFile, tmp_51_fu_623_p3, "tmp_51_fu_623_p3");
    sc_trace(mVcdFile, tmp32_fu_603_p5, "tmp32_fu_603_p5");
    sc_trace(mVcdFile, tmp_61_fu_640_p3, "tmp_61_fu_640_p3");
    sc_trace(mVcdFile, tmp_59_fu_631_p4, "tmp_59_fu_631_p4");
    sc_trace(mVcdFile, tmp_63_fu_654_p4, "tmp_63_fu_654_p4");
    sc_trace(mVcdFile, tmp_62_fu_648_p2, "tmp_62_fu_648_p2");
    sc_trace(mVcdFile, tmp_43_fu_415_p2, "tmp_43_fu_415_p2");
    sc_trace(mVcdFile, tmp_91_fu_688_p1, "tmp_91_fu_688_p1");
    sc_trace(mVcdFile, tmp34_fu_678_p5, "tmp34_fu_678_p5");
    sc_trace(mVcdFile, tmp_66_fu_698_p4, "tmp_66_fu_698_p4");
    sc_trace(mVcdFile, tmp_65_fu_692_p2, "tmp_65_fu_692_p2");
    sc_trace(mVcdFile, tmp_67_fu_708_p4, "tmp_67_fu_708_p4");
    sc_trace(mVcdFile, tmp35_fu_718_p3, "tmp35_fu_718_p3");
    sc_trace(mVcdFile, tmp30_fu_670_p3, "tmp30_fu_670_p3");
    sc_trace(mVcdFile, tmp_68_fu_726_p3, "tmp_68_fu_726_p3");
    sc_trace(mVcdFile, tmp_64_fu_664_p2, "tmp_64_fu_664_p2");
    sc_trace(mVcdFile, tmp_69_fu_740_p2, "tmp_69_fu_740_p2");
    sc_trace(mVcdFile, tmp23_fu_577_p2, "tmp23_fu_577_p2");
    sc_trace(mVcdFile, tmp33_fu_734_p2, "tmp33_fu_734_p2");
    sc_trace(mVcdFile, tmp_72_fu_752_p4, "tmp_72_fu_752_p4");
    sc_trace(mVcdFile, tmp_71_fu_746_p2, "tmp_71_fu_746_p2");
    sc_trace(mVcdFile, tmp29_fu_762_p3, "tmp29_fu_762_p3");
    sc_trace(mVcdFile, tmp8_fu_510_p24, "tmp8_fu_510_p24");
    sc_trace(mVcdFile, tmp22_fu_770_p2, "tmp22_fu_770_p2");
    sc_trace(mVcdFile, tmp_73_fu_776_p2, "tmp_73_fu_776_p2");
    sc_trace(mVcdFile, ap_return_preg, "ap_return_preg");
    sc_trace(mVcdFile, ap_NS_fsm, "ap_NS_fsm");
#endif

    }
}

approx_mul::~approx_mul() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

}

void approx_mul::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_fsm_state1;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_return_preg = ap_const_lv32_0;
    } else {
        if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
            ap_return_preg = tmp_73_fu_776_p2.read();
        }
    }
    if ((esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1) && esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
        sig_1058_reg_827 = sig_1058_fu_238_p2.read();
        sig_1405_reg_832 = sig_1405_fu_250_p2.read();
        sig_158_reg_812 = sig_158_fu_202_p2.read();
        sig_3452_reg_837 = sig_3452_fu_298_p2.read();
        sig_3992_reg_843 = sig_3992_fu_316_p2.read();
        sig_481_reg_817 = sig_481_fu_214_p2.read();
        sig_504_reg_822 = sig_504_fu_220_p2.read();
        sig_5314_reg_849 = sig_5314_fu_328_p2.read();
        tmp_55_reg_802 = opA.read().range(31, 31);
        tmp_60_reg_807 = opB.read().range(31, 31);
        tmp_70_reg_854 = opA.read().range(18, 18);
        tmp_80_reg_860 = opB.read().range(16, 16);
        tmp_s_reg_867 = tmp_s_fu_380_p2.read();
    }
}

void approx_mul::thread_ap_CS_fsm_state1() {
    ap_CS_fsm_state1 = ap_CS_fsm.read()[0];
}

void approx_mul::thread_ap_CS_fsm_state2() {
    ap_CS_fsm_state2 = ap_CS_fsm.read()[1];
}

void approx_mul::thread_ap_done() {
    if (((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read())) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()))) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_const_logic_0;
    }
}

void approx_mul::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void approx_mul::thread_ap_ready() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void approx_mul::thread_ap_return() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
        ap_return = tmp_73_fu_776_p2.read();
    } else {
        ap_return = ap_return_preg.read();
    }
}

void approx_mul::thread_sig_1015_fu_232_p2() {
    sig_1015_fu_232_p2 = (tmp_58_fu_186_p3.read() & tmp_55_fu_162_p3.read());
}

void approx_mul::thread_sig_1058_fu_238_p2() {
    sig_1058_fu_238_p2 = (tmp_57_fu_178_p3.read() & tmp_54_fu_154_p3.read());
}

void approx_mul::thread_sig_1219_fu_244_p2() {
    sig_1219_fu_244_p2 = (tmp_60_fu_194_p3.read() & tmp_54_fu_154_p3.read());
}

void approx_mul::thread_sig_1405_fu_250_p2() {
    sig_1405_fu_250_p2 = (sig_1058_fu_238_p2.read() | sig_504_fu_220_p2.read());
}

void approx_mul::thread_sig_158_fu_202_p2() {
    sig_158_fu_202_p2 = (tmp_60_fu_194_p3.read() & tmp_52_fu_138_p3.read());
}

void approx_mul::thread_sig_2089_fu_256_p2() {
    sig_2089_fu_256_p2 = (sig_1058_fu_238_p2.read() & sig_504_fu_220_p2.read());
}

void approx_mul::thread_sig_2643_fu_268_p2() {
    sig_2643_fu_268_p2 = (tmp3_fu_262_p2.read() & tmp_58_fu_186_p3.read());
}

void approx_mul::thread_sig_2740_fu_274_p2() {
    sig_2740_fu_274_p2 = (sig_2089_fu_256_p2.read() ^ sig_827_fu_226_p2.read());
}

void approx_mul::thread_sig_280_fu_208_p2() {
    sig_280_fu_208_p2 = (tmp_58_fu_186_p3.read() & tmp_54_fu_154_p3.read());
}

void approx_mul::thread_sig_3272_fu_280_p2() {
    sig_3272_fu_280_p2 = (sig_2740_fu_274_p2.read() ^ sig_280_fu_208_p2.read());
}

void approx_mul::thread_sig_3383_fu_286_p2() {
    sig_3383_fu_286_p2 = (sig_2740_fu_274_p2.read() & sig_280_fu_208_p2.read());
}

void approx_mul::thread_sig_3438_fu_292_p2() {
    sig_3438_fu_292_p2 = (sig_3272_fu_280_p2.read() & sig_2643_fu_268_p2.read());
}

void approx_mul::thread_sig_3452_fu_298_p2() {
    sig_3452_fu_298_p2 = (sig_3383_fu_286_p2.read() | sig_2089_fu_256_p2.read());
}

void approx_mul::thread_sig_3760_fu_304_p2() {
    sig_3760_fu_304_p2 = (sig_3272_fu_280_p2.read() ^ sig_2643_fu_268_p2.read());
}

void approx_mul::thread_sig_3974_fu_310_p2() {
    sig_3974_fu_310_p2 = (sig_3760_fu_304_p2.read() ^ sig_481_fu_214_p2.read());
}

void approx_mul::thread_sig_3992_fu_316_p2() {
    sig_3992_fu_316_p2 = (sig_3760_fu_304_p2.read() & sig_481_fu_214_p2.read());
}

void approx_mul::thread_sig_4402_fu_322_p2() {
    sig_4402_fu_322_p2 = (sig_3992_fu_316_p2.read() | sig_3438_fu_292_p2.read());
}

void approx_mul::thread_sig_481_fu_214_p2() {
    sig_481_fu_214_p2 = (tmp_60_fu_194_p3.read() & tmp_53_fu_146_p3.read());
}

void approx_mul::thread_sig_504_fu_220_p2() {
    sig_504_fu_220_p2 = (tmp_56_fu_170_p3.read() & tmp_55_fu_162_p3.read());
}

void approx_mul::thread_sig_5314_fu_328_p2() {
    sig_5314_fu_328_p2 = (sig_3974_fu_310_p2.read() & sig_158_fu_202_p2.read());
}

void approx_mul::thread_sig_5458_fu_352_p2() {
    sig_5458_fu_352_p2 = (tmp5_fu_346_p2.read() ^ tmp4_fu_334_p2.read());
}

void approx_mul::thread_sig_810_cast_fu_397_p1() {
    sig_810_cast_fu_397_p1 = esl_zext<32,1>(sig_810_fu_393_p2.read());
}

void approx_mul::thread_sig_810_fu_393_p2() {
    sig_810_fu_393_p2 = (tmp_60_reg_807.read() & tmp_55_reg_802.read());
}

void approx_mul::thread_sig_827_fu_226_p2() {
    sig_827_fu_226_p2 = (tmp_57_fu_178_p3.read() & tmp_55_fu_162_p3.read());
}

void approx_mul::thread_tmp22_fu_770_p2() {
    tmp22_fu_770_p2 = (tmp29_fu_762_p3.read() | tmp8_fu_510_p24.read());
}

void approx_mul::thread_tmp23_fu_577_p2() {
    tmp23_fu_577_p2 = (tmp26_fu_555_p12.read() ^ ap_const_lv27_1000000);
}

void approx_mul::thread_tmp26_fu_555_p12() {
    tmp26_fu_555_p12 = esl_concat<20,7>(esl_concat<19,1>(esl_concat<16,3>(esl_concat<15,1>(esl_concat<12,3>(esl_concat<11,1>(esl_concat<4,7>(esl_concat<3,1>(esl_concat<2,1>(esl_concat<1,1>(tmp_88_fu_487_p3.read(), tmp_80_reg_860.read()), sig_158_reg_812.read()), tmp_87_fu_480_p3.read()), ap_const_lv7_0), sig_504_reg_822.read()), ap_const_lv3_0), tmp_81_fu_421_p3.read()), ap_const_lv3_0), sig_481_reg_817.read()), ap_const_lv7_0);
}

void approx_mul::thread_tmp29_fu_762_p3() {
    tmp29_fu_762_p3 = esl_concat<5,27>(tmp_72_fu_752_p4.read(), tmp_71_fu_746_p2.read());
}

void approx_mul::thread_tmp30_fu_670_p3() {
    tmp30_fu_670_p3 = esl_concat<2,30>(tmp_63_fu_654_p4.read(), tmp_62_fu_648_p2.read());
}

void approx_mul::thread_tmp32_fu_603_p5() {
    tmp32_fu_603_p5 = esl_concat<10,20>(esl_concat<9,1>(esl_concat<1,8>(sig_3992_reg_843.read(), ap_const_lv8_0), sig_3452_reg_837.read()), ap_const_lv20_0);
}

void approx_mul::thread_tmp33_fu_734_p2() {
    tmp33_fu_734_p2 = (tmp35_fu_718_p3.read() | tmp30_fu_670_p3.read());
}

void approx_mul::thread_tmp34_fu_678_p5() {
    tmp34_fu_678_p5 = esl_concat<13,2>(esl_concat<12,1>(esl_concat<1,11>(sig_3992_reg_843.read(), ap_const_lv11_0), sig_5314_reg_849.read()), ap_const_lv2_0);
}

void approx_mul::thread_tmp35_fu_718_p3() {
    tmp35_fu_718_p3 = esl_concat<17,15>(tmp_66_fu_698_p4.read(), tmp_65_fu_692_p2.read());
}

void approx_mul::thread_tmp3_fu_262_p2() {
    tmp3_fu_262_p2 = (tmp_53_fu_146_p3.read() & sig_1405_fu_250_p2.read());
}

void approx_mul::thread_tmp4_fu_334_p2() {
    tmp4_fu_334_p2 = (sig_3452_fu_298_p2.read() ^ sig_1015_fu_232_p2.read());
}

void approx_mul::thread_tmp5_fu_346_p2() {
    tmp5_fu_346_p2 = (tmp6_fu_340_p2.read() ^ sig_1219_fu_244_p2.read());
}

void approx_mul::thread_tmp6_fu_340_p2() {
    tmp6_fu_340_p2 = (sig_4402_fu_322_p2.read() ^ sig_5314_fu_328_p2.read());
}

void approx_mul::thread_tmp7_fu_374_p2() {
    tmp7_fu_374_p2 = (sig_3974_fu_310_p2.read() ^ sig_158_fu_202_p2.read());
}

void approx_mul::thread_tmp8_fu_510_p24() {
    tmp8_fu_510_p24 = esl_concat<31,1>(esl_concat<30,1>(esl_concat<29,1>(esl_concat<28,1>(esl_concat<27,1>(esl_concat<26,1>(esl_concat<24,2>(esl_concat<22,2>(esl_concat<20,2>(esl_concat<19,1>(esl_concat<18,1>(esl_concat<16,2>(esl_concat<15,1>(esl_concat<13,2>(esl_concat<12,1>(esl_concat<11,1>(esl_concat<10,1>(esl_concat<9,1>(esl_concat<4,5>(esl_concat<3,1>(esl_concat<2,1>(esl_concat<1,1>(tmp_70_reg_854.read(), sig_1058_reg_827.read()), ap_const_lv1_0), tmp_89_fu_494_p3.read()), ap_const_lv5_0), tmp_86_fu_473_p3.read()), tmp_85_fu_466_p3.read()), ap_const_lv1_0), tmp_fu_386_p3.read()), ap_const_lv2_0), tmp_84_fu_442_p3.read()), ap_const_lv2_0), tmp_83_fu_435_p3.read()), tmp_82_fu_428_p3.read()), ap_const_lv2_0), tmp_47_fu_501_p4.read()), ap_const_lv2_0), tmp_80_reg_860.read()), tmp_80_reg_860.read()), tmp_79_fu_401_p3.read()), ap_const_lv1_0), tmp_70_reg_854.read()), ap_const_lv1_0);
}

void approx_mul::thread_tmp_42_fu_411_p1() {
    tmp_42_fu_411_p1 = esl_zext<32,8>(size_op1.read());
}

void approx_mul::thread_tmp_43_fu_415_p2() {
    tmp_43_fu_415_p2 = (!tmp_42_fu_411_p1.read().is_01())? sc_lv<32>(): tmp_97_cast_fu_408_p1.read() << (unsigned short)tmp_42_fu_411_p1.read().to_uint();
}

void approx_mul::thread_tmp_44_fu_449_p1() {
    tmp_44_fu_449_p1 = esl_zext<32,8>(size_op2.read());
}

void approx_mul::thread_tmp_45_fu_453_p2() {
    tmp_45_fu_453_p2 = (!tmp_44_fu_449_p1.read().is_01())? sc_lv<32>(): sig_810_cast_fu_397_p1.read() << (unsigned short)tmp_44_fu_449_p1.read().to_uint();
}

void approx_mul::thread_tmp_46_fu_459_p3() {
    tmp_46_fu_459_p3 = esl_concat<1,18>(sig_1405_reg_832.read(), ap_const_lv18_0);
}

void approx_mul::thread_tmp_47_fu_501_p4() {
    tmp_47_fu_501_p4 = opA.read().range(8, 7);
}

void approx_mul::thread_tmp_48_fu_587_p2() {
    tmp_48_fu_587_p2 = (tmp_90_fu_583_p1.read() | tmp_46_fu_459_p3.read());
}

void approx_mul::thread_tmp_49_fu_593_p4() {
    tmp_49_fu_593_p4 = tmp_45_fu_453_p2.read().range(29, 19);
}

void approx_mul::thread_tmp_50_fu_613_p4() {
    tmp_50_fu_613_p4 = tmp_45_fu_453_p2.read().range(26, 19);
}

void approx_mul::thread_tmp_51_fu_623_p3() {
    tmp_51_fu_623_p3 = esl_concat<11,19>(tmp_49_fu_593_p4.read(), tmp_48_fu_587_p2.read());
}

void approx_mul::thread_tmp_52_fu_138_p3() {
    tmp_52_fu_138_p3 = opA.read().range(28, 28);
}

void approx_mul::thread_tmp_53_fu_146_p3() {
    tmp_53_fu_146_p3 = opA.read().range(29, 29);
}

void approx_mul::thread_tmp_54_fu_154_p3() {
    tmp_54_fu_154_p3 = opA.read().range(30, 30);
}

void approx_mul::thread_tmp_55_fu_162_p3() {
    tmp_55_fu_162_p3 = opA.read().range(31, 31);
}

void approx_mul::thread_tmp_56_fu_170_p3() {
    tmp_56_fu_170_p3 = opB.read().range(28, 28);
}

void approx_mul::thread_tmp_57_fu_178_p3() {
    tmp_57_fu_178_p3 = opB.read().range(29, 29);
}

void approx_mul::thread_tmp_58_fu_186_p3() {
    tmp_58_fu_186_p3 = opB.read().range(30, 30);
}

void approx_mul::thread_tmp_59_fu_631_p4() {
    tmp_59_fu_631_p4 = esl_concat<7,20>(esl_concat<6,1>(ap_const_lv6_0, sig_3452_reg_837.read()), ap_const_lv20_0);
}

void approx_mul::thread_tmp_60_fu_194_p3() {
    tmp_60_fu_194_p3 = opB.read().range(31, 31);
}

void approx_mul::thread_tmp_61_fu_640_p3() {
    tmp_61_fu_640_p3 = esl_concat<8,19>(tmp_50_fu_613_p4.read(), tmp_48_fu_587_p2.read());
}

void approx_mul::thread_tmp_62_fu_648_p2() {
    tmp_62_fu_648_p2 = (tmp_51_fu_623_p3.read() | tmp32_fu_603_p5.read());
}

void approx_mul::thread_tmp_63_fu_654_p4() {
    tmp_63_fu_654_p4 = tmp_45_fu_453_p2.read().range(31, 30);
}

void approx_mul::thread_tmp_64_fu_664_p2() {
    tmp_64_fu_664_p2 = (tmp_61_fu_640_p3.read() | tmp_59_fu_631_p4.read());
}

void approx_mul::thread_tmp_65_fu_692_p2() {
    tmp_65_fu_692_p2 = (tmp_91_fu_688_p1.read() | tmp34_fu_678_p5.read());
}

void approx_mul::thread_tmp_66_fu_698_p4() {
    tmp_66_fu_698_p4 = tmp_43_fu_415_p2.read().range(31, 15);
}

void approx_mul::thread_tmp_67_fu_708_p4() {
    tmp_67_fu_708_p4 = tmp_43_fu_415_p2.read().range(26, 15);
}

void approx_mul::thread_tmp_68_fu_726_p3() {
    tmp_68_fu_726_p3 = esl_concat<12,15>(tmp_67_fu_708_p4.read(), tmp_65_fu_692_p2.read());
}

void approx_mul::thread_tmp_69_fu_740_p2() {
    tmp_69_fu_740_p2 = (tmp_68_fu_726_p3.read() | tmp_64_fu_664_p2.read());
}

void approx_mul::thread_tmp_71_fu_746_p2() {
    tmp_71_fu_746_p2 = (tmp_69_fu_740_p2.read() | tmp23_fu_577_p2.read());
}

void approx_mul::thread_tmp_72_fu_752_p4() {
    tmp_72_fu_752_p4 = tmp33_fu_734_p2.read().range(31, 27);
}

void approx_mul::thread_tmp_73_fu_776_p2() {
    tmp_73_fu_776_p2 = (tmp22_fu_770_p2.read() | ap_const_lv32_40);
}

void approx_mul::thread_tmp_79_fu_401_p3() {
    tmp_79_fu_401_p3 = opA.read().range(6, 6);
}

void approx_mul::thread_tmp_81_fu_421_p3() {
    tmp_81_fu_421_p3 = opB.read().range(3, 3);
}

void approx_mul::thread_tmp_82_fu_428_p3() {
    tmp_82_fu_428_p3 = opB.read().range(20, 20);
}

void approx_mul::thread_tmp_83_fu_435_p3() {
    tmp_83_fu_435_p3 = opA.read().range(16, 16);
}

void approx_mul::thread_tmp_84_fu_442_p3() {
    tmp_84_fu_442_p3 = opA.read().range(25, 25);
}

void approx_mul::thread_tmp_85_fu_466_p3() {
    tmp_85_fu_466_p3 = opA.read().range(2, 2);
}

void approx_mul::thread_tmp_86_fu_473_p3() {
    tmp_86_fu_473_p3 = opA.read().range(11, 11);
}

void approx_mul::thread_tmp_87_fu_480_p3() {
    tmp_87_fu_480_p3 = opB.read().range(9, 9);
}

void approx_mul::thread_tmp_88_fu_487_p3() {
    tmp_88_fu_487_p3 = opB.read().range(22, 22);
}

void approx_mul::thread_tmp_89_fu_494_p3() {
    tmp_89_fu_494_p3 = opB.read().range(7, 7);
}

void approx_mul::thread_tmp_90_fu_583_p1() {
    tmp_90_fu_583_p1 = tmp_45_fu_453_p2.read().range(19-1, 0);
}

void approx_mul::thread_tmp_91_fu_688_p1() {
    tmp_91_fu_688_p1 = tmp_43_fu_415_p2.read().range(15-1, 0);
}

void approx_mul::thread_tmp_97_cast_fu_408_p1() {
    tmp_97_cast_fu_408_p1 = esl_zext<32,1>(tmp_s_reg_867.read());
}

void approx_mul::thread_tmp_fu_386_p3() {
    tmp_fu_386_p3 = opA.read().range(19, 19);
}

void approx_mul::thread_tmp_s_fu_380_p2() {
    tmp_s_fu_380_p2 = (tmp7_fu_374_p2.read() & sig_5458_fu_352_p2.read());
}

void approx_mul::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if ((esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1) && esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
                ap_NS_fsm = ap_ST_fsm_state2;
            } else {
                ap_NS_fsm = ap_ST_fsm_state1;
            }
            break;
        case 2 : 
            ap_NS_fsm = ap_ST_fsm_state1;
            break;
        default : 
            ap_NS_fsm = "XX";
            break;
    }
}

}

