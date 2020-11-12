; ModuleID = 'bitmap_de.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu-elf"

%union.anon = type { i64 }
%seg_400700__rodata_type = type <{ [8 x i8] }>
%seg_600e10__init_array_type = type <{ i64, i64 }>
%seg_600ff0__got_type = type <{ i64, i64 }>
%seg_601038__bss_type = type <{ [8 x i8] }>
%struct.State = type { %struct.ArchState, [32 x %union.VectorReg], %struct.ArithFlags, %union.anon, %struct.Segments, %struct.AddressSpace, %struct.GPR, %struct.X87Stack, %struct.MMX, %struct.FPUStatusFlags, %union.anon, %union.FPU, %struct.SegmentCaches }
%struct.ArchState = type { i32, i32, %union.anon }
%union.VectorReg = type { %union.vec512_t }
%union.vec512_t = type { %struct.uint64v8_t }
%struct.uint64v8_t = type { [8 x i64] }
%struct.ArithFlags = type { i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8 }
%struct.Segments = type { i16, %union.SegmentSelector, i16, %union.SegmentSelector, i16, %union.SegmentSelector, i16, %union.SegmentSelector, i16, %union.SegmentSelector, i16, %union.SegmentSelector }
%union.SegmentSelector = type { i16 }
%struct.AddressSpace = type { i64, %struct.Reg, i64, %struct.Reg, i64, %struct.Reg, i64, %struct.Reg, i64, %struct.Reg, i64, %struct.Reg }
%struct.Reg = type { %union.anon }
%struct.GPR = type { i64, %struct.Reg, i64, %struct.Reg, i64, %struct.Reg, i64, %struct.Reg, i64, %struct.Reg, i64, %struct.Reg, i64, %struct.Reg, i64, %struct.Reg, i64, %struct.Reg, i64, %struct.Reg, i64, %struct.Reg, i64, %struct.Reg, i64, %struct.Reg, i64, %struct.Reg, i64, %struct.Reg, i64, %struct.Reg, i64, %struct.Reg }
%struct.X87Stack = type { [8 x %struct.anon.3] }
%struct.anon.3 = type { i64, double }
%struct.MMX = type { [8 x %struct.anon.4] }
%struct.anon.4 = type { i64, %union.vec64_t }
%union.vec64_t = type { %struct.uint64v1_t }
%struct.uint64v1_t = type { [1 x i64] }
%struct.FPUStatusFlags = type { i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, [4 x i8] }
%union.FPU = type { %struct.anon.13 }
%struct.anon.13 = type { %struct.FpuFXSAVE, [96 x i8] }
%struct.FpuFXSAVE = type { %union.SegmentSelector, %union.SegmentSelector, %union.FPUAbridgedTagWord, i8, i16, i32, %union.SegmentSelector, i16, i32, %union.SegmentSelector, i16, %union.FPUControlStatus, %union.FPUControlStatus, [8 x %struct.FPUStackElem], [16 x %union.vec128_t] }
%union.FPUAbridgedTagWord = type { i8 }
%union.FPUControlStatus = type { i32 }
%struct.FPUStackElem = type { %union.anon.11, [6 x i8] }
%union.anon.11 = type { %struct.float80_t }
%struct.float80_t = type { [10 x i8] }
%union.vec128_t = type { %struct.uint128v1_t }
%struct.uint128v1_t = type { [1 x i128] }
%struct.SegmentCaches = type { %struct.SegmentShadow, %struct.SegmentShadow, %struct.SegmentShadow, %struct.SegmentShadow, %struct.SegmentShadow, %struct.SegmentShadow }
%struct.SegmentShadow = type { %union.anon, i32, i32 }
%struct.Memory = type opaque

@DR0 = external dso_local global i64, align 8
@DR1 = external dso_local global i64, align 8
@DR2 = external dso_local global i64, align 8
@DR3 = external dso_local global i64, align 8
@DR4 = external dso_local global i64, align 8
@DR5 = external dso_local global i64, align 8
@DR6 = external dso_local global i64, align 8
@DR7 = external dso_local global i64, align 8
@gCR0 = external dso_local global %union.anon, align 1
@gCR1 = external dso_local global %union.anon, align 1
@gCR2 = external dso_local global %union.anon, align 1
@gCR3 = external dso_local global %union.anon, align 1
@gCR4 = external dso_local global %union.anon, align 1
@gCR8 = external dso_local global %union.anon, align 1
@seg_400700__rodata = internal constant %seg_400700__rodata_type <{ [8 x i8] c"\01\00\02\00%d\0A\00" }>
@seg_600e10__init_array = internal global %seg_600e10__init_array_type <{ i64 ptrtoint (i64 (i64, i64, i64, i64, i64, i64, i64, i64)* @callback_sub_400510_frame_dummy to i64), i64 ptrtoint (i64 (i64, i64, i64, i64, i64, i64, i64, i64)* @callback_sub_4004e0___do_global_dtors_aux to i64) }>
@seg_600ff0__got = internal global %seg_600ff0__got_type <{ i64 ptrtoint (i64 (i64, i64, i64, i64, i64, i64, i64, i64)* @__libc_start_main to i64), i64 ptrtoint (i64 ()* @__gmon_start__ to i64) }>
@seg_601038__bss = internal global %seg_601038__bss_type zeroinitializer
@__mcsema_reg_state = internal thread_local global %struct.State zeroinitializer
@__mcsema_stack = internal thread_local global [131072 x i64] zeroinitializer
@__mcsema_tls = internal thread_local global [512 x i64] zeroinitializer
@0 = internal global i1 false
@llvm.global_ctors = appending global [1 x { i32, void ()*, i8* }] [{ i32, void ()*, i8* } { i32 101, void ()* @__mcsema_constructor, i8* null }]
@llvm.global_dtors = appending global [1 x { i32, void ()*, i8* }] [{ i32, void ()*, i8* } { i32 101, void ()* @__mcsema_destructor, i8* null }]

declare dso_local void @cblas_sgemm(i32, i32, i32, i32, i32, i32, float, float*, i32, float*, i32, float, float*, i32)
declare dso_local void @cblas_dgemm(i32, i32, i32, i32, i32, i32, double, double*, i32, double*, i32, double, double*, i32)
declare dso_local void @cblas_sgemv(i32, i32, i32, i32, float, float*, i32, float*, i32, float, float*, i32)

; Function Attrs: noinline nounwind
define dso_local %struct.Memory* @sub_400520_main(%struct.State* noalias dereferenceable(3376), i64, %struct.Memory* noalias) local_unnamed_addr #5 !remill.function.type !1277 !remill.function.tie !1305 {
block_400520:
  %3 = getelementptr inbounds %struct.State, %struct.State* %0, i64 0, i32 6, i32 1, i32 0
  %4 = getelementptr inbounds %union.anon, %union.anon* %3, i64 0, i32 0
  %5 = getelementptr inbounds %struct.State, %struct.State* %0, i64 0, i32 6, i32 5, i32 0, i32 0
  %6 = getelementptr inbounds %struct.State, %struct.State* %0, i64 0, i32 6, i32 7, i32 0, i32 0
  %7 = getelementptr inbounds %struct.State, %struct.State* %0, i64 0, i32 6, i32 9, i32 0, i32 0
  %8 = getelementptr inbounds %struct.State, %struct.State* %0, i64 0, i32 6, i32 11, i32 0, i32 0
  %9 = getelementptr inbounds %struct.State, %struct.State* %0, i64 0, i32 6, i32 13, i32 0, i32 0
  %10 = getelementptr inbounds %struct.State, %struct.State* %0, i64 0, i32 6, i32 15, i32 0, i32 0
  %11 = getelementptr inbounds %struct.State, %struct.State* %0, i64 0, i32 6, i32 33, i32 0, i32 0
  %12 = load i64, i64* %10, align 8
  %13 = load i64, i64* %9, align 8, !tbaa !1302
  %14 = add i64 %13, -8
  %15 = inttoptr i64 %14 to i64*
  store i64 %12, i64* %15
  store i64 %14, i64* %10, align 8, !tbaa !1278
  %16 = getelementptr inbounds %struct.State, %struct.State* %0, i64 0, i32 2, i32 1
  store i8 0, i8* %16, align 1, !tbaa !1282
  %17 = getelementptr inbounds %struct.State, %struct.State* %0, i64 0, i32 2, i32 3
  store i8 1, i8* %17, align 1, !tbaa !1297
  %18 = getelementptr inbounds %struct.State, %struct.State* %0, i64 0, i32 2, i32 7
  store i8 1, i8* %18, align 1, !tbaa !1298
  %19 = getelementptr inbounds %struct.State, %struct.State* %0, i64 0, i32 2, i32 9
  store i8 0, i8* %19, align 1, !tbaa !1299
  %20 = getelementptr inbounds %struct.State, %struct.State* %0, i64 0, i32 2, i32 13
  store i8 0, i8* %20, align 1, !tbaa !1300
  %21 = getelementptr inbounds %struct.State, %struct.State* %0, i64 0, i32 2, i32 5
  store i8 0, i8* %21, align 1, !tbaa !1301
  %22 = add i64 %13, -12
  %23 = inttoptr i64 %22 to i32*
  store i32 0, i32* %23
  %24 = add i64 %13, -56
  store i64 %24, i64* %8, align 8, !tbaa !1278
  store i64 0, i64* %7, align 8, !tbaa !1278
  store i64 40, i64* %5, align 8, !tbaa !1278
  store i64 40, i64* %6, align 8, !tbaa !1278
  %25 = add i64 %13, -164
  %26 = inttoptr i64 %25 to i32*
  store i32 0, i32* %26
  %27 = add i64 %13, -176
  %28 = inttoptr i64 %27 to i64*
  store i64 40, i64* %28
  %29 = add i64 %1, -256
  %30 = add i64 %1, 55
  %31 = add i64 %13, -192
  %32 = inttoptr i64 %31 to i64*
  store i64 %30, i64* %32
  store i64 %31, i64* %9, align 8, !tbaa !1278
  %33 = tail call %struct.Memory* @ext_601460_memset(%struct.State* nonnull %0, i64 %29, %struct.Memory* %2)
  %34 = load i64, i64* %10, align 8
  %35 = add i64 %34, -48
  %36 = load i64, i64* %11, align 8
  %37 = inttoptr i64 %35 to i32*
  store i32 1, i32* %37
  %38 = add i64 %34, -36
  %39 = inttoptr i64 %38 to i32*
  store i32 1, i32* %39
  %40 = add i64 %34, -28
  %41 = inttoptr i64 %40 to i32*
  store i32 1, i32* %41
  %42 = add i64 %34, -24
  %43 = inttoptr i64 %42 to i32*
  store i32 1, i32* %43
  %44 = add i64 %34, -20
  %45 = inttoptr i64 %44 to i32*
  store i32 1, i32* %45
  %46 = add i64 %34, -12
  %47 = inttoptr i64 %46 to i32*
  store i32 1, i32* %47
  %48 = add i64 %34, -96
  store i64 %48, i64* %5, align 8, !tbaa !1278
  store i64 %48, i64* %8, align 8, !tbaa !1278
  %49 = add i64 %34, -156
  %50 = inttoptr i64 %49 to i32*
  %51 = load i32, i32* %50
  %52 = zext i32 %51 to i64
  store i64 %52, i64* %7, align 8, !tbaa !1278
  %53 = add i64 %34, -168
  %54 = inttoptr i64 %53 to i64*
  %55 = load i64, i64* %54
  store i64 %55, i64* %6, align 8, !tbaa !1278
  %56 = add i64 %36, -311
  %57 = add i64 %36, 67
  %58 = load i64, i64* %9, align 8, !tbaa !1302
  %59 = add i64 %58, -8
  %60 = inttoptr i64 %59 to i64*
  store i64 %57, i64* %60
  store i64 %59, i64* %9, align 8, !tbaa !1278
  %61 = tail call %struct.Memory* @ext_601460_memset(%struct.State* nonnull %0, i64 %56, %struct.Memory* %33)
  %62 = load i64, i64* %10, align 8
  %63 = add i64 %62, -88
  %64 = load i64, i64* %11, align 8
  %65 = inttoptr i64 %63 to i32*
  store i32 1, i32* %65
  %66 = add i64 %62, -84
  %67 = inttoptr i64 %66 to i32*
  store i32 1, i32* %67
  %68 = add i64 %62, -80
  %69 = inttoptr i64 %68 to i32*
  store i32 1, i32* %69
  %70 = add i64 %62, -76
  %71 = inttoptr i64 %70 to i32*
  store i32 1, i32* %71
  %72 = add i64 %62, -60
  %73 = inttoptr i64 %72 to i32*
  store i32 1, i32* %73
  %74 = add i64 %62, -144
  store i64 %74, i64* %5, align 8, !tbaa !1278
  store i64 %74, i64* %8, align 8, !tbaa !1278
  %75 = add i64 %62, -156
  %76 = inttoptr i64 %75 to i32*
  %77 = load i32, i32* %76
  %78 = zext i32 %77 to i64
  store i64 %78, i64* %7, align 8, !tbaa !1278
  %79 = add i64 %62, -168
  %80 = inttoptr i64 %79 to i64*
  %81 = load i64, i64* %80
  store i64 %81, i64* %6, align 8, !tbaa !1278
  %82 = add i64 %64, -378
  %83 = add i64 %64, 63
  %84 = load i64, i64* %9, align 8, !tbaa !1302
  %85 = add i64 %84, -8
  %86 = inttoptr i64 %85 to i64*
  store i64 %83, i64* %86
  store i64 %85, i64* %9, align 8, !tbaa !1278
  %87 = tail call %struct.Memory* @ext_601460_memset(%struct.State* nonnull %0, i64 %82, %struct.Memory* %61)
  %88 = load i64, i64* %10, align 8
  %89 = add i64 %88, -148
  %90 = load i64, i64* %11, align 8
  %91 = add i64 %90, 10
  %92 = inttoptr i64 %89 to i32*
  store i32 0, i32* %92
  br label %block_4005e3

block_400632:                                     ; preds = %block_400628, %block_40063f
  %93 = phi i64 [ %212, %block_400628 ], [ %210, %block_40063f ]
  %94 = phi i64 [ %88, %block_400628 ], [ %203, %block_40063f ]
  %95 = phi %struct.Memory* [ %176, %block_400628 ], [ %202, %block_40063f ]
  %96 = add i64 %94, -152
  %97 = add i64 %93, 7
  %98 = inttoptr i64 %96 to i32*
  %99 = load i32, i32* %98
  %100 = add i32 %99, -10
  %101 = icmp ult i32 %99, 10
  %102 = zext i1 %101 to i8
  store i8 %102, i8* %16, align 1, !tbaa !1282
  %103 = and i32 %100, 255
  %104 = tail call i32 @llvm.ctpop.i32(i32 %103) #10, !range !1296
  %105 = trunc i32 %104 to i8
  %106 = and i8 %105, 1
  %107 = xor i8 %106, 1
  store i8 %107, i8* %17, align 1, !tbaa !1297
  %108 = xor i32 %100, %99
  %109 = lshr i32 %108, 4
  %110 = trunc i32 %109 to i8
  %111 = and i8 %110, 1
  store i8 %111, i8* %21, align 1, !tbaa !1301
  %112 = icmp eq i32 %100, 0
  %113 = zext i1 %112 to i8
  store i8 %113, i8* %18, align 1, !tbaa !1298
  %114 = lshr i32 %100, 31
  %115 = trunc i32 %114 to i8
  store i8 %115, i8* %19, align 1, !tbaa !1299
  %116 = lshr i32 %99, 31
  %117 = xor i32 %114, %116
  %118 = add nuw nsw i32 %117, %116
  %119 = icmp eq i32 %118, 2
  %120 = zext i1 %119 to i8
  store i8 %120, i8* %20, align 1, !tbaa !1300
  %121 = icmp eq i8 %115, 0
  %122 = xor i1 %121, %119
  %123 = select i1 %122, i64 57, i64 6
  %124 = add i64 %123, %97
  br i1 %122, label %block_400672, label %block_40063f

block_bitmap_0:
  %op1_middle_0 = add i64 %88, -96
  %op1_0 = inttoptr i64 %op1_middle_0 to i32*
  %op2_middle_0 = add i64 %88, -48
  %op2_0 = inttoptr i64 %op2_middle_0 to i32*
  %goal_middle_0 = add i64 %127, -144
  %goal_0 = inttoptr i64 %goal_middle_0 to i32*
  call void @CIM_bitmap(i32 10, i32* %op1_0, i32* %op2_0, i32* %goal_0)
  br label %block_400628

block_4005f0:                                     ; preds = %block_4005e3
  %125 = sext i32 %179 to i64
  %126 = shl nsw i64 %125, 2
  %127 = add i64 %126, %88
  %128 = add i64 %127, -48
  %129 = inttoptr i64 %128 to i32*
  %130 = load i32, i32* %129
  %131 = add i64 %127, -96
  %132 = inttoptr i64 %131 to i32*
  %133 = load i32, i32* %132
  %134 = and i32 %133, %130
  %135 = zext i32 %134 to i64
  store i64 %135, i64* %5, align 8, !tbaa !1278
  %136 = add i64 %127, -144
  %137 = inttoptr i64 %136 to i32*
  store i32 %134, i32* %137
  %138 = inttoptr i64 %89 to i32*
  %139 = load i32, i32* %138
  %140 = add i32 %139, 1
  %141 = inttoptr i64 %89 to i32*
  store i32 %140, i32* %141
  %142 = add i64 %189, -13
  br label %block_4005e3

block_400672:                                     ; preds = %block_400632
  store i64 0, i64* %4, align 8, !tbaa !1278
  %143 = load i64, i64* %9, align 8
  %144 = add i64 %143, 176
  %145 = icmp ugt i64 %143, -177
  %146 = icmp ult i64 %144, 176
  %147 = or i1 %145, %146
  %148 = zext i1 %147 to i8
  store i8 %148, i8* %16, align 1, !tbaa !1282
  %149 = trunc i64 %144 to i32
  %150 = and i32 %149, 255
  %151 = tail call i32 @llvm.ctpop.i32(i32 %150) #10, !range !1296
  %152 = trunc i32 %151 to i8
  %153 = and i8 %152, 1
  %154 = xor i8 %153, 1
  store i8 %154, i8* %17, align 1, !tbaa !1297
  %155 = xor i64 %143, 16
  %156 = xor i64 %155, %144
  %157 = lshr i64 %156, 4
  %158 = trunc i64 %157 to i8
  %159 = and i8 %158, 1
  store i8 %159, i8* %21, align 1, !tbaa !1301
  %160 = icmp eq i64 %144, 0
  %161 = zext i1 %160 to i8
  store i8 %161, i8* %18, align 1, !tbaa !1298
  %162 = lshr i64 %144, 63
  %163 = trunc i64 %162 to i8
  store i8 %163, i8* %19, align 1, !tbaa !1299
  %164 = lshr i64 %143, 63
  %165 = xor i64 %162, %164
  %166 = add nuw nsw i64 %165, %162
  %167 = icmp eq i64 %166, 2
  %168 = zext i1 %167 to i8
  store i8 %168, i8* %20, align 1, !tbaa !1300
  %169 = add i64 %143, 184
  %170 = inttoptr i64 %144 to i64*
  %171 = load i64, i64* %170
  store i64 %171, i64* %10, align 8, !tbaa !1278
  %172 = inttoptr i64 %169 to i64*
  %173 = load i64, i64* %172
  store i64 %173, i64* %11, align 8, !tbaa !1278
  %174 = add i64 %143, 192
  store i64 %174, i64* %9, align 8, !tbaa !1278
  ret %struct.Memory* %95

block_4005e3:                                     ; preds = %block_4005f0, %block_400520
  %175 = phi i64 [ %91, %block_400520 ], [ %142, %block_4005f0 ]
  %176 = phi %struct.Memory* [ %87, %block_400520 ], [ %176, %block_4005f0 ]
  %177 = add i64 %175, 7
  %178 = inttoptr i64 %89 to i32*
  %179 = load i32, i32* %178
  %180 = add i32 %179, -10
  %181 = lshr i32 %180, 31
  %182 = lshr i32 %179, 31
  %183 = xor i32 %181, %182
  %184 = add nuw nsw i32 %183, %182
  %185 = icmp eq i32 %184, 2
  %186 = icmp eq i32 %181, 0
  %187 = xor i1 %186, %185
  %188 = select i1 %187, i64 62, i64 6
  %189 = add i64 %188, %177
  br label %block_bitmap_0

block_40063f:                                     ; preds = %block_400632
  %190 = sext i32 %99 to i64
  %191 = shl nsw i64 %190, 2
  %192 = add i64 %94, -144
  %193 = add i64 %192, %191
  %194 = inttoptr i64 %193 to i32*
  %195 = load i32, i32* %194
  %196 = zext i32 %195 to i64
  store i64 %196, i64* %7, align 8, !tbaa !1278
  store i64 add (i64 ptrtoint (%seg_400700__rodata_type* @seg_400700__rodata to i64), i64 4), i64* %8, align 8, !tbaa !1278
  %197 = add i64 %124, -559
  %198 = add i64 %124, 31
  %199 = load i64, i64* %9, align 8, !tbaa !1302
  %200 = add i64 %199, -8
  %201 = inttoptr i64 %200 to i64*
  store i64 %198, i64* %201
  store i64 %200, i64* %9, align 8, !tbaa !1278
  %202 = tail call %struct.Memory* @ext_601468_printf(%struct.State* nonnull %0, i64 %197, %struct.Memory* %95)
  %203 = load i64, i64* %10, align 8
  %204 = add i64 %203, -152
  %205 = load i64, i64* %11, align 8
  %206 = inttoptr i64 %204 to i32*
  %207 = load i32, i32* %206
  %208 = add i32 %207, 1
  %209 = inttoptr i64 %204 to i32*
  store i32 %208, i32* %209
  %210 = add i64 %205, -44
  br label %block_400632

block_400628:                                     ; preds = %block_4005e3
  %211 = add i64 %88, -152
  %212 = add i64 %189, 10
  %213 = inttoptr i64 %211 to i32*
  store i32 0, i32* %213
  br label %block_400632
}

