; ModuleID = 'gemm.c'
source_filename = "gemm.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@__const.main.A = private unnamed_addr constant [3 x float] [float 1.000000e+00, float 2.500000e+00, float 3.000000e+00], align 4
@__const.main.weight = private unnamed_addr constant [3 x [2 x float]] [[2 x float] [float 4.000000e+00, float 5.000000e+00], [2 x float] [float 0x4014CCCCC0000000, float 0x4019333340000000], [2 x float] [float 0x401D333340000000, float 8.000000e+00]], align 16
@.str = private unnamed_addr constant [5 x i8] c" %f\0A\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %retval = alloca i32, align 4
  %A = alloca [3 x float], align 4
  %weight = alloca [3 x [2 x float]], align 16
  %resA = alloca [2 x float], align 4
  %i = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  %0 = bitcast [3 x float]* %A to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %0, i8* align 4 bitcast ([3 x float]* @__const.main.A to i8*), i64 12, i1 false)
  %1 = bitcast [3 x [2 x float]]* %weight to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %1, i8* align 16 bitcast ([3 x [2 x float]]* @__const.main.weight to i8*), i64 24, i1 false)
  %2 = bitcast [2 x float]* %resA to i8*
  call void @llvm.memset.p0i8.i64(i8* align 4 %2, i8 0, i64 8, i1 false)
  %arrayidx = getelementptr inbounds [3 x [2 x float]], [3 x [2 x float]]* %weight, i64 0, i64 0
  %arraydecay = getelementptr inbounds [2 x float], [2 x float]* %arrayidx, i64 0, i64 0
  %arraydecay1 = getelementptr inbounds [3 x float], [3 x float]* %A, i64 0, i64 0
  %arraydecay2 = getelementptr inbounds [2 x float], [2 x float]* %resA, i64 0, i64 0
  call void @cblas_sgemm(i32 101, i32 112, i32 112, i32 2, i32 1, i32 3, float 1.000000e+00, float* %arraydecay, i32 2, float* %arraydecay1, i32 3, float 0.000000e+00, float* %arraydecay2, i32 1)
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %3 = load i32, i32* %i, align 4
  %cmp = icmp slt i32 %3, 2
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %4 = load i32, i32* %i, align 4
  %idxprom = sext i32 %4 to i64
  %arrayidx3 = getelementptr inbounds [2 x float], [2 x float]* %resA, i64 0, i64 %idxprom
  %5 = load float, float* %arrayidx3, align 4
  %conv = fpext float %5 to double
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str, i64 0, i64 0), double %conv)
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %6 = load i32, i32* %i, align 4
  %inc = add nsw i32 %6, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  ret i32 0
}

; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture writeonly, i8* nocapture readonly, i64, i1 immarg) #1

; Function Attrs: argmemonly nounwind
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #1

declare dso_local void @cblas_sgemm(i32, i32, i32, i32, i32, i32, float, float*, i32, float*, i32, float, float*, i32) #2

declare dso_local i32 @printf(i8*, ...) #2

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { argmemonly nounwind }
attributes #2 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 9.0.0 (tags/RELEASE_900/final)"}
