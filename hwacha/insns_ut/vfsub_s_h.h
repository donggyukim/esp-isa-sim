require_fp;
softfloat_roundingMode = VRM;
WRITE_FRD(f32_sub(f32(HFRS1), f32(HFRS2)));
set_fp_exceptions;
