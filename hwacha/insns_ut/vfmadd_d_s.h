require_fp;
softfloat_roundingMode = RM;
WRITE_FRD(f64_mulAdd(f32_to_f64(FRS1), f32_to_f64(FRS2), f32_to_f64(FRS3)));
set_fp_exceptions;
