require_fp;
softfloat_roundingMode = VRM;
WRITE_SFRD(i32_to_f32((int32_t)RS1).v);
set_fp_exceptions;
