#ifndef _HWACHA_H
#define _HWACHA_H

#include "extension.h"

static const uint32_t MAX_SPR = 256;
static const uint32_t MAX_APR = 32;

struct ct_state_t
{
  void reset();

  uint32_t nxpr;
  uint32_t nppr;
  uint32_t maxvl;
  uint32_t vl;
  uint32_t count;
  uint32_t prec;

  uint32_t fflags;
  uint32_t frm;

  bool enable;

  reg_t vf_pc;
  regfile_t<reg_t, 256, true> SPR;
  regfile_t<reg_t, 32, false> APR;
};

struct ut_state_t
{
  void reset();

  bool run;
  regfile_t<reg_t, 256, true> XPR;
  regfile_t<bool, 16, false> PPR;
};

class hwacha_t : public extension_t
{
public:
  hwacha_t() : cause(0), aux(0), debug(false) {}
  std::vector<insn_desc_t> get_instructions();
  std::vector<disasm_insn_t*> get_disasms();
  const char* name() { return "hwacha"; }
  void reset();
  void set_debug(bool value) { debug = value; }

  ct_state_t* get_ct_state() { return &ct_state; }
  ut_state_t* get_ut_state(int idx) { return &ut_state[idx]; }
  bool vf_active();
  reg_t get_cause() { return cause; }
  reg_t get_aux() { return aux; }
  void take_exception(reg_t, reg_t);
  void clear_exception() { clear_interrupt(); }

  bool get_debug() { return debug; }
  disassembler_t* get_ut_disassembler() { return &ut_disassembler; }

  static const int max_uts = 2048;

private:
  ct_state_t ct_state;
  ut_state_t ut_state[max_uts];
  reg_t cause;
  reg_t aux;

  disassembler_t ut_disassembler;
  bool debug;
};

#endif
