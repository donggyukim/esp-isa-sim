require_fp;
softfloat_roundingMode = VRM;
WRITE_HFRD(f32_add(f32(HFRS1), f32(HFRS2)));
set_fp_exceptions;
