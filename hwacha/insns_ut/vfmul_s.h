require_fp;
softfloat_roundingMode = VRM;
WRITE_SFRD(f32_mul(f32(FRS1), f32(FRS2)).v);
set_fp_exceptions;
