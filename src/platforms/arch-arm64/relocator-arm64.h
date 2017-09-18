/**
 *    Copyright 2017 jmpews
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#ifndef platforms_arch_arm64_relocator_h
#define platforms_arch_arm64_relocator_h

// platforms
#include "instructions.h"
#include "regs-arm64.h"
#include "writer-arm64.h"

// hookzz
#include "writer.h"

// zzdeps
#include "capstone.h"
#include "hookzz.h"
#include "zzdefs.h"
#include "zzdeps/common/debugbreak.h"
#include "zzdeps/zz.h"

typedef struct _ZzArm64Relocator {
    csh capstone;

    zpointer input_start;
    zpointer input_cur;
    zaddr input_pc;
    Instruction *input_insns;
    ZzArm64Writer *output;

    zuint inpos;
    zuint outpos;
} ZzArm64Relocator;

void zz_arm64_relocator_init(ZzArm64Relocator *relocator, zpointer input_code,
                             ZzArm64Writer *writer);

zsize zz_arm64_relocator_read_one(ZzArm64Relocator *self,
                                  Instruction *instruction);
void zz_arm64_relocator_try_relocate(zpointer address, zuint min_bytes,
                                     zuint *max_bytes);
#endif