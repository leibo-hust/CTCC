; ModuleID = 'mmm.c'
source_filename = "mmm.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@__const.main.A = private unnamed_addr constant [6 x [5 x float]] [[5 x float] [float 0x3FF19999A0000000, float 0x4000CCCCC0000000, float 0x40099999A0000000, float 0x4010CCCCC0000000, float 5.500000e+00], [5 x float] [float 0x4003333340000000, float 0x400E666660000000, float 0x4014CCCCC0000000, float 0x401D9999A0000000, float 8.500000e+00], [5 x float] [float 0x4008CCCCC0000000, float 0x4000CCCCC0000000, float 5.000000e-01, float 0x3FF028F5C0000000, float 0x401147AE20000000], [5 x float] [float 4.500000e+00, float 0x40099999A0000000, float 0x4020333340000000, float 1.500000e+00, float 0x4002666660000000], [5 x float] [float 0x3FF19999A0000000, float 1.300000e+01, float 0x4016CCCCC0000000, float 0x3FF1EB8520000000, float 0x4020A8F5C0000000], [5 x float] [float 0xC022051EC0000000, float 0x402275C280000000, float 0x40219999A0000000, float 0x40219999A0000000, float 0x40219999A0000000]], align 16
@__const.main.b = private unnamed_addr constant [2 x [6 x float]] [[6 x float] [float 0x4011333340000000, float 0xC01D9999A0000000, float 0x40219999A0000000, float 0xC002666660000000, float 0x3FF4CCCCC0000000, float 0x4004A3D700000000], [6 x float] [float 5.000000e-01, float 0x3FF51EB860000000, float 0x40070A3D80000000, float 0x400B333340000000, float 0xBFE3333340000000, float 0x3FFB333340000000]], align 16
@.str = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %retval = alloca i32, align 4
  %A = alloca [6 x [5 x float]], align 16
  %b = alloca [2 x [6 x float]], align 16
  %c = alloca [2 x [5 x float]], align 16
  %c1 = alloca [2 x [5 x float]], align 16
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %a = alloca float, align 4
  store i32 0, i32* %retval, align 4
  %0 = bitcast [6 x [5 x float]]* %A to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %0, i8* align 16 bitcast ([6 x [5 x float]]* @__const.main.A to i8*), i64 120, i1 false)
  %1 = bitcast [2 x [6 x float]]* %b to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %1, i8* align 16 bitcast ([2 x [6 x float]]* @__const.main.b to i8*), i64 48, i1 false)
  %2 = bitcast [2 x [5 x float]]* %c to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %2, i8 0, i64 40, i1 false)
  %3 = bitcast [2 x [5 x float]]* %c1 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %3, i8 0, i64 40, i1 false)
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc20, %entry
  %4 = load i32, i32* %i, align 4
  %cmp = icmp slt i32 %4, 2
  br i1 %cmp, label %for.body, label %for.end22

for.body:                                         ; preds = %for.cond
  store i32 0, i32* %j, align 4
  br label %for.cond1

for.cond1:                                        ; preds = %for.inc17, %for.body
  %5 = load i32, i32* %j, align 4
  %cmp2 = icmp slt i32 %5, 5
  br i1 %cmp2, label %for.body3, label %for.end19

for.body3:                                        ; preds = %for.cond1
  store i32 0, i32* %k, align 4
  br label %for.cond4

for.cond4:                                        ; preds = %for.inc, %for.body3
  %6 = load i32, i32* %k, align 4
  %cmp5 = icmp slt i32 %6, 6
  br i1 %cmp5, label %for.body6, label %for.end

for.body6:                                        ; preds = %for.cond4
  %7 = load i32, i32* %i, align 4
  %idxprom = sext i32 %7 to i64
  %arrayidx = getelementptr inbounds [2 x [6 x float]], [2 x [6 x float]]* %b, i64 0, i64 %idxprom
  %8 = load i32, i32* %k, align 4
  %idxprom7 = sext i32 %8 to i64
  %arrayidx8 = getelementptr inbounds [6 x float], [6 x float]* %arrayidx, i64 0, i64 %idxprom7
  %9 = load float, float* %arrayidx8, align 4
  %10 = load i32, i32* %k, align 4
  %idxprom9 = sext i32 %10 to i64
  %arrayidx10 = getelementptr inbounds [6 x [5 x float]], [6 x [5 x float]]* %A, i64 0, i64 %idxprom9
  %11 = load i32, i32* %j, align 4
  %idxprom11 = sext i32 %11 to i64
  %arrayidx12 = getelementptr inbounds [5 x float], [5 x float]* %arrayidx10, i64 0, i64 %idxprom11
  %12 = load float, float* %arrayidx12, align 4
  %mul = fmul float %9, %12
  %13 = load i32, i32* %i, align 4
  %idxprom13 = sext i32 %13 to i64
  %arrayidx14 = getelementptr inbounds [2 x [5 x float]], [2 x [5 x float]]* %c, i64 0, i64 %idxprom13
  %14 = load i32, i32* %j, align 4
  %idxprom15 = sext i32 %14 to i64
  %arrayidx16 = getelementptr inbounds [5 x float], [5 x float]* %arrayidx14, i64 0, i64 %idxprom15
  %15 = load float, float* %arrayidx16, align 4
  %add = fadd float %15, %mul
  store float %add, float* %arrayidx16, align 4
  br label %for.inc

for.inc:                                          ; preds = %for.body6
  %16 = load i32, i32* %k, align 4
  %inc = add nsw i32 %16, 1
  store i32 %inc, i32* %k, align 4
  br label %for.cond4

for.end:                                          ; preds = %for.cond4
  br label %for.inc17

for.inc17:                                        ; preds = %for.end
  %17 = load i32, i32* %j, align 4
  %inc18 = add nsw i32 %17, 1
  store i32 %inc18, i32* %j, align 4
  br label %for.cond1

for.end19:                                        ; preds = %for.cond1
  br label %for.inc20

for.inc20:                                        ; preds = %for.end19
  %18 = load i32, i32* %i, align 4
  %inc21 = add nsw i32 %18, 1
  store i32 %inc21, i32* %i, align 4
  br label %for.cond

for.end22:                                        ; preds = %for.cond
  %arrayidx23 = getelementptr inbounds [2 x [5 x float]], [2 x [5 x float]]* %c, i64 0, i64 1
  %arrayidx24 = getelementptr inbounds [5 x float], [5 x float]* %arrayidx23, i64 0, i64 2
  %19 = load float, float* %arrayidx24, align 4
  store float %19, float* %a, align 4
  %20 = load float, float* %a, align 4
  %conv = fpext float %20 to double
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), double %conv)
  %21 = load i32, i32* %retval, align 4
  ret i32 %21
}

; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture writeonly, i8* nocapture readonly, i64, i1 immarg) #1

; Function Attrs: argmemonly nounwind
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #1

declare dso_local i32 @printf(i8*, ...) #2

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { argmemonly nounwind }
attributes #2 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 9.0.0 (tags/RELEASE_900/final)"}
