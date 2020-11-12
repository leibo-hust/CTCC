; ModuleID = 'bitmap_test.c'
source_filename = "bitmap_test.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %retval = alloca i32, align 4
  %arr1 = alloca [10 x i32], align 16
  %arr2 = alloca [10 x i32], align 16
  %arr3 = alloca [10 x i32], align 16
  %i = alloca i32, align 4
  %i5 = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  %0 = bitcast [10 x i32]* %arr1 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %0, i8 0, i64 40, i1 false)
  %1 = bitcast i8* %0 to [10 x i32]*
  %2 = getelementptr inbounds [10 x i32], [10 x i32]* %1, i32 0, i32 0
  store i32 1, i32* %2, align 16
  %3 = getelementptr inbounds [10 x i32], [10 x i32]* %1, i32 0, i32 3
  store i32 1, i32* %3, align 4
  %4 = getelementptr inbounds [10 x i32], [10 x i32]* %1, i32 0, i32 5
  store i32 1, i32* %4, align 4
  %5 = getelementptr inbounds [10 x i32], [10 x i32]* %1, i32 0, i32 6
  store i32 1, i32* %5, align 8
  %6 = getelementptr inbounds [10 x i32], [10 x i32]* %1, i32 0, i32 7
  store i32 1, i32* %6, align 4
  %7 = getelementptr inbounds [10 x i32], [10 x i32]* %1, i32 0, i32 9
  store i32 1, i32* %7, align 4
  %8 = bitcast [10 x i32]* %arr2 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %8, i8 0, i64 40, i1 false)
  %9 = bitcast i8* %8 to [10 x i32]*
  %10 = getelementptr inbounds [10 x i32], [10 x i32]* %9, i32 0, i32 2
  store i32 1, i32* %10, align 8
  %11 = getelementptr inbounds [10 x i32], [10 x i32]* %9, i32 0, i32 3
  store i32 1, i32* %11, align 4
  %12 = getelementptr inbounds [10 x i32], [10 x i32]* %9, i32 0, i32 4
  store i32 1, i32* %12, align 16
  %13 = getelementptr inbounds [10 x i32], [10 x i32]* %9, i32 0, i32 5
  store i32 1, i32* %13, align 4
  %14 = getelementptr inbounds [10 x i32], [10 x i32]* %9, i32 0, i32 9
  store i32 1, i32* %14, align 4
  %15 = bitcast [10 x i32]* %arr3 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %15, i8 0, i64 40, i1 false)
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %16 = load i32, i32* %i, align 4
  %cmp = icmp slt i32 %16, 10
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %17 = load i32, i32* %i, align 4
  %idxprom = sext i32 %17 to i64
  %arrayidx = getelementptr inbounds [10 x i32], [10 x i32]* %arr1, i64 0, i64 %idxprom
  %18 = load i32, i32* %arrayidx, align 4
  %19 = load i32, i32* %i, align 4
  %idxprom1 = sext i32 %19 to i64
  %arrayidx2 = getelementptr inbounds [10 x i32], [10 x i32]* %arr2, i64 0, i64 %idxprom1
  %20 = load i32, i32* %arrayidx2, align 4
  %and = and i32 %18, %20
  %21 = load i32, i32* %i, align 4
  %idxprom3 = sext i32 %21 to i64
  %arrayidx4 = getelementptr inbounds [10 x i32], [10 x i32]* %arr3, i64 0, i64 %idxprom3
  store i32 %and, i32* %arrayidx4, align 4
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %22 = load i32, i32* %i, align 4
  %inc = add nsw i32 %22, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  store i32 0, i32* %i5, align 4
  br label %for.cond6

for.cond6:                                        ; preds = %for.inc11, %for.end
  %23 = load i32, i32* %i5, align 4
  %cmp7 = icmp slt i32 %23, 10
  br i1 %cmp7, label %for.body8, label %for.end13

for.body8:                                        ; preds = %for.cond6
  %24 = load i32, i32* %i5, align 4
  %idxprom9 = sext i32 %24 to i64
  %arrayidx10 = getelementptr inbounds [10 x i32], [10 x i32]* %arr3, i64 0, i64 %idxprom9
  %25 = load i32, i32* %arrayidx10, align 4
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 %25)
  br label %for.inc11

for.inc11:                                        ; preds = %for.body8
  %26 = load i32, i32* %i5, align 4
  %inc12 = add nsw i32 %26, 1
  store i32 %inc12, i32* %i5, align 4
  br label %for.cond6

for.end13:                                        ; preds = %for.cond6
  ret i32 0
}

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
