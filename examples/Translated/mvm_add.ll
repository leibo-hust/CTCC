; ModuleID = 'test.c'
source_filename = "test.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@__const.main.A = private unnamed_addr constant [3 x float] [float 1.000000e+00, float 2.000000e+00, float 3.000000e+00], align 4
@__const.main.weight = private unnamed_addr constant [3 x [2 x float]] [[2 x float] [float 4.000000e+00, float 5.000000e+00], [2 x float] [float 5.000000e+00, float 6.000000e+00], [2 x float] [float 7.000000e+00, float 8.000000e+00]], align 16
@.str = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1

declare dso_local void @cblas_sgemm(i32, i32, i32, i32, i32, i32, float, float*, i32, float*, i32, float, float*, i32)
declare dso_local void @cblas_dgemm(i32, i32, i32, i32, i32, i32, double, double*, i32, double*, i32, double, double*, i32)
declare dso_local void @cblas_sgemv(i32, i32, i32, i32, float, float*, i32, float*, i32, float, float*, i32)

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %retval = alloca i32, align 4
  %A = alloca [3 x float], align 4
  %weight = alloca [3 x [2 x float]], align 16
  %res = alloca [2 x float], align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %i13 = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  %0 = bitcast [3 x float]* %A to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %0, i8* align 4 bitcast ([3 x float]* @__const.main.A to i8*), i64 12, i1 false)
  %1 = bitcast [3 x [2 x float]]* %weight to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %1, i8* align 16 bitcast ([3 x [2 x float]]* @__const.main.weight to i8*), i64 24, i1 false)
  %2 = bitcast [2 x float]* %res to i8*
  call void @llvm.memset.p0i8.i64(i8* align 4 %2, i8 0, i64 8, i1 false)
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc10, %entry
  %3 = load i32, i32* %i, align 4
  %cmp = icmp slt i32 %3, 2
  br i1 %cmp, label %for.body, label %for.end12

for.body:                                         ; preds = %for.cond
  store i32 0, i32* %j, align 4
  br label %for.cond1

for.cond1:                                        ; preds = %for.inc, %for.body
  %4 = load i32, i32* %j, align 4
  %cmp2 = icmp slt i32 %4, 3
  br label %block_mvm_0

block_mvm_0:
  %vec_0 = getelementptr inbounds [3 x float], [3 x float]* %A, i64 0, i64 0
  %mat_middle_0 = getelementptr inbounds [3 x [2 x float]], [3 x [2 x float]]* %weight, i64 0, i64 0
  %mat_0 = getelementptr inbounds [2 x float], [2 x float]* %mat_middle_0 , i64 0, i64 0
  %out_0 = getelementptr inbounds [2 x float], [2 x float]* %res, i64 0, i64 0
  call void @cblas_sgemv(i32 101, i32 112, i32 3, i32 2, float 1.000000e+00, float* %mat_0, i32 2, float* %vec_0, i32 1, float 0.000000e+00, float* %out_0, i32 1)
  br label %for.end12

for.body3:                                        ; preds = %for.cond1
  %5 = load i32, i32* %j, align 4
  %idxprom = sext i32 %5 to i64
  %arrayidx = getelementptr inbounds [3 x float], [3 x float]* %A, i64 0, i64 %idxprom
  %6 = load float, float* %arrayidx, align 4
  %7 = load i32, i32* %j, align 4
  %idxprom4 = sext i32 %7 to i64
  %arrayidx5 = getelementptr inbounds [3 x [2 x float]], [3 x [2 x float]]* %weight, i64 0, i64 %idxprom4
  %8 = load i32, i32* %i, align 4
  %idxprom6 = sext i32 %8 to i64
  %arrayidx7 = getelementptr inbounds [2 x float], [2 x float]* %arrayidx5, i64 0, i64 %idxprom6
  %9 = load float, float* %arrayidx7, align 4
  %mul = fmul float %6, %9
  %10 = load i32, i32* %i, align 4
  %idxprom8 = sext i32 %10 to i64
  %arrayidx9 = getelementptr inbounds [2 x float], [2 x float]* %res, i64 0, i64 %idxprom8
  %11 = load float, float* %arrayidx9, align 4
  %add = fadd float %11, %mul
  store float %add, float* %arrayidx9, align 4
  br label %for.inc

for.inc:                                          ; preds = %for.body3
  %12 = load i32, i32* %j, align 4
  %inc = add nsw i32 %12, 1
  store i32 %inc, i32* %j, align 4
  br label %for.cond1

for.end:                                          ; preds = %for.cond1
  br label %for.inc10

for.inc10:                                        ; preds = %for.end
  %13 = load i32, i32* %i, align 4
  %inc11 = add nsw i32 %13, 1
  store i32 %inc11, i32* %i, align 4
  br label %for.cond

for.end12:                                        ; preds = %for.cond
  store i32 0, i32* %i13, align 4
  br label %for.cond14

for.cond14:                                       ; preds = %for.inc19, %for.end12
  %14 = load i32, i32* %i13, align 4
  %cmp15 = icmp slt i32 %14, 2
  br i1 %cmp15, label %for.body16, label %for.end21

for.body16:                                       ; preds = %for.cond14
  %15 = load i32, i32* %i13, align 4
  %idxprom17 = sext i32 %15 to i64
  %arrayidx18 = getelementptr inbounds [2 x float], [2 x float]* %res, i64 0, i64 %idxprom17
  %16 = load float, float* %arrayidx18, align 4
  %conv = fpext float %16 to double
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), double %conv)
  br label %for.inc19

for.inc19:                                        ; preds = %for.body16
  %17 = load i32, i32* %i13, align 4
  %inc20 = add nsw i32 %17, 1
  store i32 %inc20, i32* %i13, align 4
  br label %for.cond14

for.end21:                                        ; preds = %for.cond14
  ret i32 0
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
