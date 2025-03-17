// license:BSD-3-Clause

/*****************************************************************************
 *
 *   sh34_timings.h
 *   SH-3/SH-4 CPU timing information
 *
 *   Instruction timing values derived from Hitachi/Renesas datasheets
 *   and official hardware programming manuals
 *
 *****************************************************************************/

 #ifndef MAME_CPU_SH_SH34_TIMINGS_H
 #define MAME_CPU_SH_SH34_TIMINGS_H
 
 #pragma once
 
 // Timing enumeration for indexing into the timing tables
 enum sh_timing_type
 {
     SH_TIMING_INT_ARITH, // Integer arithmetic instructions (ADD, SUB, etc.)
     SH_TIMING_INT_LOGIC, // Integer logical instructions (AND, OR, XOR, etc.)
     SH_TIMING_SHIFT,     // Shift instructions (SHLD, SHAD, etc.)
     SH_TIMING_BRANCH,    // Branch instructions (BT, BF, JMP, etc.)
     SH_TIMING_LOAD,      // Load instructions (MOV.x @Rm, Rn)
     SH_TIMING_STORE,     // Store instructions (MOV.x Rm, @Rn)
     SH_TIMING_LOAD_PC,   // Load from PC-relative address (MOV.x @(disp,PC), Rn)
     SH_TIMING_LOAD_IMM,  // Load immediate value (MOV #imm, Rn)
     SH_TIMING_SYS_REG,   // System register transfer instructions (LDC, STC, etc.)
     SH_TIMING_FCNV,      // FPU conversion instructions (FTRC, FLOAT, etc.)
     SH_TIMING_FMOVE,     // FPU data move instructions (FMOV)
     SH_TIMING_FARITH,    // FPU arithmetic instructions (FADD, FSUB, FMUL, etc.)
     SH_TIMING_FCOMP,     // FPU comparison instructions (FCMP/EQ, FCMP/GT)
     SH_TIMING_PREF,      // Prefetch instruction (PREF)
     SH_TIMING_MULTI_OP,  // Multi-operation instructions (MAC.L, etc.)
     SH_TIMING_EXEC_SLOT, // Delay slot execution penalty
     SH_TIMING_TRAP,      // Trap/exception handling (TRAPA)
     SH_TIMING_RTE,       // Return from exception (RTE)
     SH_TIMING_CLRMAC,    // Clear MAC register (CLRMAC)
     SH_TIMING_NOP,       // No operation (NOP)
     SH_TIMING_MOVCA,     // Atomic store (MOVCA.L)
     SH_TIMING_TAS,       // Test and set (TAS)
     SH_TIMING_MAC,       // Multiply and accumulate (MAC)
     SH_TIMING_DMA,       // DMA operations
     SH_TIMING_DIV,       // Division operations (DIV1)
     SH_TIMING_FSQRT,     // Square root operation (FSQRT)
     SH_TIMING_FIPR,      // Inner product (FIPR)
     SH_TIMING_FTRV,      // Matrix-vector multiplication (FTRV)
     SH_TIMING_LDTLB,     // Load TLB entry (LDTLB)
     SH_TIMING_LAST       // Must be last entry
 };
 
 // Instruction timings for SH-3 (cycles)
 // Values from SH-3 hardware manual and real-world performance analysis
 static const int sh3_insn_timings[SH_TIMING_LAST] = {
     /* SH_TIMING_INT_ARITH */ 1,     // Basic integer ops take 1 cycle
     /* SH_TIMING_INT_LOGIC */ 1,     // Basic logical ops take 1 cycle
     /* SH_TIMING_SHIFT */     1,     // Shift operations take 1 cycle
     /* SH_TIMING_BRANCH */    2,     // Branches take 2 cycles plus delay slot
     /* SH_TIMING_LOAD */      1,     // Base load cycle (memory system adds more)
     /* SH_TIMING_STORE */     1,     // Base store cycle (memory system adds more)
     /* SH_TIMING_LOAD_PC */   2,     // PC-relative loads incur extra cycle
     /* SH_TIMING_LOAD_IMM */  1,     // Immediate loads
     /* SH_TIMING_SYS_REG */   4,     // System register transfers (higher in real-world)
     /* SH_TIMING_FCNV */      8,     // FP conversions (realistic SH-3 timing)
     /* SH_TIMING_FMOVE */     1,     // FP register-to-register moves
     /* SH_TIMING_FARITH */    9,     // Basic FP ops (FADD/FSUB/FMUL - realistic SH-3 timing)
     /* SH_TIMING_FCOMP */     5,     // FP comparisons (realistic SH-3 timing)
     /* SH_TIMING_PREF */      2,     // Prefetch (less effective on SH-3)
     /* SH_TIMING_MULTI_OP */  3,     // Multi-cycle operations (more cycles on SH-3)
     /* SH_TIMING_EXEC_SLOT */ 1,     // Delay slot execution
     /* SH_TIMING_TRAP */     10,     // Traps/Exceptions (realistic overhead)
     /* SH_TIMING_RTE */       8,     // Return from exception (realistic overhead)
     /* SH_TIMING_CLRMAC */    2,     // Clear MAC (higher in real-world)
     /* SH_TIMING_NOP */       1,     // NOP
     /* SH_TIMING_MOVCA */     4,     // Atomic store
     /* SH_TIMING_TAS */       5,     // Test and set (realistic timing)
     /* SH_TIMING_MAC */       3,     // Multiply and accumulate base cost
     /* SH_TIMING_DMA */      12,     // DMA setup (realistic overhead)
     /* SH_TIMING_DIV */      32,     // DIV1 operation - takes ~1 cycle per bit
     /* SH_TIMING_FSQRT */    18,     // Square root (realistic SH-3 timing)
     /* SH_TIMING_FIPR */     12,     // Inner product (realistic SH-3 timing)
     /* SH_TIMING_FTRV */     16,     // Matrix-vector multiplication (realistic SH-3 timing)
     /* SH_TIMING_LDTLB */     7      // Load TLB (realistic SH-3 MMU timing)
 };
 
 // Instruction timings for SH-4 (cycles)
 // Values from SH-4 hardware manual
 static const int sh4_insn_timings[SH_TIMING_LAST] = {
     /* SH_TIMING_INT_ARITH */ 1,
     /* SH_TIMING_INT_LOGIC */ 1,
     /* SH_TIMING_SHIFT */     1,
     /* SH_TIMING_BRANCH */    2, // Branches take 2 cycles plus 1 for the delay slot
     /* SH_TIMING_LOAD */      1, // Most loads are 1 cycle, but can be stalled by memory access
     /* SH_TIMING_STORE */     1, // Stores vary based on destination
     /* SH_TIMING_LOAD_PC */   1, // PC-relative loads
     /* SH_TIMING_LOAD_IMM */  1, // Immediate loads
     /* SH_TIMING_SYS_REG */   3, // System register transfers
     /* SH_TIMING_FCNV */      3, // FP conversions are relatively expensive
     /* SH_TIMING_FMOVE */     1, // FP register-to-register moves
     /* SH_TIMING_FARITH */    1, // Basic FP operations (pipelined on SH-4)
     /* SH_TIMING_FCOMP */     1, // FP comparisons
     /* SH_TIMING_PREF */      1, // Prefetch
     /* SH_TIMING_MULTI_OP */  2, // Multi-cycle operations
     /* SH_TIMING_EXEC_SLOT */ 1, // Delay slot execution
     /* SH_TIMING_TRAP */      7, // Traps/Exceptions
     /* SH_TIMING_RTE */       5, // Return from exception
     /* SH_TIMING_CLRMAC */    1, // Clear MAC
     /* SH_TIMING_NOP */       1, // NOP
     /* SH_TIMING_MOVCA */     1, // Atomic store
     /* SH_TIMING_TAS */       4, // Test and set
     /* SH_TIMING_MAC */       2, // Multiply and accumulate
     /* SH_TIMING_DMA */       8, // DMA setup
     /* SH_TIMING_DIV */       2, // DIV1 operation
     /* SH_TIMING_FSQRT */    13, // Square root (may take 20+ cycles but mostly pipelined)
     /* SH_TIMING_FIPR */      4, // Inner product (4 cycle latency, but 1/cycle throughput)
     /* SH_TIMING_FTRV */      4, // Matrix-vector (4 cycle latency, but 1/cycle throughput)
     /* SH_TIMING_LDTLB */     8  // Load TLB (SH-4 MMU)
 };
 
 // Additional memory access latency (cycles)
 struct sh34_memory_timing {
     int cached_read;           // Cached memory read latency
     int cached_write;          // Cached memory write latency
     int uncached_read;         // Uncached memory read latency
     int uncached_write;        // Uncached memory write latency
     int on_chip_ram_read;      // On-chip RAM read latency
     int on_chip_ram_write;     // On-chip RAM write latency
     int on_chip_reg_read;      // On-chip register read latency
     int on_chip_reg_write;     // On-chip register write latency
 };
 
 // SH-3 memory timings - based on real-world memory system performance
 static const sh34_memory_timing sh3_memory_timing = {
     /* cached_read */       1,  // Additional cycles for cached memory read
     /* cached_write */      2,  // Additional cycles for cached memory write (more realistic)
     /* uncached_read */     6,  // Additional cycles for uncached memory read (realistic for 16-bit bus)
     /* uncached_write */    4,  // Additional cycles for uncached memory write (realistic)
     /* on_chip_ram_read */  1,  // On-chip RAM read (realistic - still takes a cycle)
     /* on_chip_ram_write */ 1,  // On-chip RAM write (realistic)
     /* on_chip_reg_read */  2,  // On-chip register read (realistic)
     /* on_chip_reg_write */ 2   // On-chip register write (realistic)
 };
 
 // SH-4 memory timings - these are approximate as actual timing depends on memory
 // system configuration, wait states, etc.
 static const sh34_memory_timing sh4_memory_timing = {
     /* cached_read */       0,  // Additional cycles for cached memory read
     /* cached_write */      0,  // Additional cycles for cached memory write
     /* uncached_read */     3,  // Additional cycles for uncached memory read
     /* uncached_write */    1,  // Additional cycles for uncached memory write
     /* on_chip_ram_read */  0,  // On-chip RAM read
     /* on_chip_ram_write */ 0,  // On-chip RAM write
     /* on_chip_reg_read */  1,  // On-chip register read
     /* on_chip_reg_write */ 1   // On-chip register write
 };
 
 // Pipeline stall cycles for SH-3 based on real-world code execution
 static const int sh3_pipeline_stalls[SH_TIMING_LAST] = {
     /* SH_TIMING_INT_ARITH */ 0,
     /* SH_TIMING_INT_LOGIC */ 0,
     /* SH_TIMING_SHIFT */     0,
     /* SH_TIMING_BRANCH */    2, // Branch misprediction penalty (realistic)
     /* SH_TIMING_LOAD */      2, // Load-to-use stall (realistic in common code)
     /* SH_TIMING_STORE */     0,
     /* SH_TIMING_LOAD_PC */   2, // Load-to-use stall (realistic in common code)
     /* SH_TIMING_LOAD_IMM */  0,
     /* SH_TIMING_SYS_REG */   2, // System register access stall (realistic)
     /* SH_TIMING_FCNV */      3, // FP conversion stall (realistic SH-3 pipeline)
     /* SH_TIMING_FMOVE */     1, // FP move stall
     /* SH_TIMING_FARITH */    3, // FP arithmetic stall (realistic SH-3 pipeline)
     /* SH_TIMING_FCOMP */     2, // FP comparison stall (realistic)
     /* SH_TIMING_PREF */      0,
     /* SH_TIMING_MULTI_OP */  2, // Multi-op stall (realistic)
     /* SH_TIMING_EXEC_SLOT */ 1, // Delay slot can sometimes stall
     /* SH_TIMING_TRAP */      3, // Trap handling stall (realistic)
     /* SH_TIMING_RTE */       3, // Return from exception stall (realistic)
     /* SH_TIMING_CLRMAC */    1, // CLRMAC can stall pipeline
     /* SH_TIMING_NOP */       0,
     /* SH_TIMING_MOVCA */     2, // Atomic store stall (realistic)
     /* SH_TIMING_TAS */       3, // Test and set stall (realistic)
     /* SH_TIMING_MAC */       2, // MAC stall (realistic)
     /* SH_TIMING_DMA */       3, // DMA stall (realistic)
     /* SH_TIMING_DIV */       2, // Division stall (may be higher depending on pipeline state)
     /* SH_TIMING_FSQRT */     4, // Square root stall (realistic SH-3 pipeline)
     /* SH_TIMING_FIPR */      3, // Inner product stall (realistic SH-3 pipeline)
     /* SH_TIMING_FTRV */      4, // Matrix-vector stall (realistic SH-3 pipeline)
     /* SH_TIMING_LDTLB */     3  // Load TLB stall (realistic)
 };
 
 // Pipeline stall cycles for SH-4
 static const int sh4_pipeline_stalls[SH_TIMING_LAST] = {
     /* SH_TIMING_INT_ARITH */ 0,
     /* SH_TIMING_INT_LOGIC */ 0,
     /* SH_TIMING_SHIFT */     0,
     /* SH_TIMING_BRANCH */    1, // Pipeline stall on branch
     /* SH_TIMING_LOAD */      1, // Load-to-use stall
     /* SH_TIMING_STORE */     0,
     /* SH_TIMING_LOAD_PC */   1, // Load-to-use stall
     /* SH_TIMING_LOAD_IMM */  0,
     /* SH_TIMING_SYS_REG */   1, // System register access stall
     /* SH_TIMING_FCNV */      1, // FP conversion stall
     /* SH_TIMING_FMOVE */     0,
     /* SH_TIMING_FARITH */    0, // FP arithmetic (pipelined on SH-4)
     /* SH_TIMING_FCOMP */     0, // FP comparison (pipelined on SH-4)
     /* SH_TIMING_PREF */      0,
     /* SH_TIMING_MULTI_OP */  1, // Multi-op stall
     /* SH_TIMING_EXEC_SLOT */ 0,
     /* SH_TIMING_TRAP */      2, // Trap handling stall
     /* SH_TIMING_RTE */       2, // Return from exception stall
     /* SH_TIMING_CLRMAC */    0,
     /* SH_TIMING_NOP */       0,
     /* SH_TIMING_MOVCA */     0, // Atomic store (improved on SH-4)
     /* SH_TIMING_TAS */       1, // Test and set stall
     /* SH_TIMING_MAC */       0, // MAC (pipelined on SH-4)
     /* SH_TIMING_DMA */       1, // DMA stall
     /* SH_TIMING_DIV */       1, // Division stall
     /* SH_TIMING_FSQRT */     1, // Square root stall
     /* SH_TIMING_FIPR */      0, // Inner product (pipelined on SH-4)
     /* SH_TIMING_FTRV */      0, // Matrix-vector (pipelined on SH-4)
     /* SH_TIMING_LDTLB */     1  // Load TLB stall
 };
 
 // Opcode to timing type mapping table
 // Maps opcode patterns to their timing type
 struct sh_opcode_timing_map {
     uint16_t mask;      // Bit mask to apply to opcode
     uint16_t pattern;   // Pattern to match after masking
     sh_timing_type timing_type; // Timing type for this opcode
 };
 
 // This table maps specific opcode patterns to their timing types
 // Listed roughly in order of frequency for better search performance
 static const sh_opcode_timing_map sh_timing_map[] = {
     // Integer arithmetic (ADD, SUB, etc.)
     { 0xF000, 0x3000, SH_TIMING_INT_ARITH }, // ADD
     { 0xF000, 0x7000, SH_TIMING_INT_ARITH }, // ADD #imm
     { 0xF00F, 0x300C, SH_TIMING_INT_ARITH }, // ADD Rm, Rn
     { 0xF00F, 0x300A, SH_TIMING_INT_ARITH }, // ADDC
     { 0xF00F, 0x300B, SH_TIMING_INT_ARITH }, // ADDV
     { 0xF00F, 0x3008, SH_TIMING_INT_ARITH }, // SUB
     { 0xF00F, 0x300A, SH_TIMING_INT_ARITH }, // SUBC
     { 0xF00F, 0x300B, SH_TIMING_INT_ARITH }, // SUBV
     { 0xF00F, 0x0007, SH_TIMING_INT_ARITH }, // MUL.L
     { 0xF00F, 0x200F, SH_TIMING_INT_ARITH }, // MULS.W
     { 0xF00F, 0x200E, SH_TIMING_INT_ARITH }, // MULU.W
     { 0xF00F, 0x0000, SH_TIMING_INT_ARITH }, // CMP/EQ
     { 0xF00F, 0x3002, SH_TIMING_INT_ARITH }, // CMP/HS (CMP/GE unsigned)
     { 0xF00F, 0x3003, SH_TIMING_INT_ARITH }, // CMP/GE
     { 0xF00F, 0x3006, SH_TIMING_INT_ARITH }, // CMP/HI (CMP/GT unsigned)
     { 0xF00F, 0x3007, SH_TIMING_INT_ARITH }, // CMP/GT
     { 0xF00F, 0x4015, SH_TIMING_INT_ARITH }, // CMP/PL
     { 0xF00F, 0x4011, SH_TIMING_INT_ARITH }, // CMP/PZ
     { 0xF00F, 0x200C, SH_TIMING_INT_ARITH }, // CMP/STR
 
     // Integer logical (AND, OR, XOR, etc.)
     { 0xF00F, 0x2009, SH_TIMING_INT_LOGIC }, // AND
     { 0xF00F, 0x200B, SH_TIMING_INT_LOGIC }, // OR
     { 0xF00F, 0x200A, SH_TIMING_INT_LOGIC }, // XOR
     { 0xF00F, 0x2001, SH_TIMING_INT_LOGIC }, // STS MACH
     { 0xF00F, 0x2011, SH_TIMING_INT_LOGIC }, // STS MACL
     { 0xF00F, 0x0029, SH_TIMING_INT_LOGIC }, // AND #imm, R0
     { 0xF00F, 0x002B, SH_TIMING_INT_LOGIC }, // OR #imm, R0
     { 0xF00F, 0x002A, SH_TIMING_INT_LOGIC }, // XOR #imm, R0
     { 0xF00F, 0x6009, SH_TIMING_INT_LOGIC }, // NOT
     { 0xF00F, 0x2008, SH_TIMING_INT_LOGIC }, // TST
     { 0xF00F, 0x0028, SH_TIMING_INT_LOGIC }, // TST #imm, R0
 
     // Shift operations
     { 0xF00F, 0x4000, SH_TIMING_SHIFT }, // SHLL
     { 0xF00F, 0x4001, SH_TIMING_SHIFT }, // SHAL
     { 0xF00F, 0x4008, SH_TIMING_SHIFT }, // SHLL2
     { 0xF00F, 0x4018, SH_TIMING_SHIFT }, // SHLL8
     { 0xF00F, 0x4028, SH_TIMING_SHIFT }, // SHLL16
     { 0xF00F, 0x4020, SH_TIMING_SHIFT }, // SHLR
     { 0xF00F, 0x4021, SH_TIMING_SHIFT }, // SHAR
     { 0xF00F, 0x4010, SH_TIMING_SHIFT }, // DT
     { 0xF00F, 0x4029, SH_TIMING_SHIFT }, // ROTL
     { 0xF00F, 0x4028, SH_TIMING_SHIFT }, // ROTCL
     { 0xF00F, 0x4024, SH_TIMING_SHIFT }, // ROTCR
     { 0xF00F, 0x4025, SH_TIMING_SHIFT }, // ROTR
     { 0xF00F, 0x400C, SH_TIMING_SHIFT }, // SHLR2
     { 0xF00F, 0x401C, SH_TIMING_SHIFT }, // SHLR8
     { 0xF00F, 0x402C, SH_TIMING_SHIFT }, // SHLR16
 
     // Branch operations
     { 0xF000, 0x8900, SH_TIMING_BRANCH }, // BT
     { 0xF000, 0x8B00, SH_TIMING_BRANCH }, // BF
     { 0xF000, 0x8D00, SH_TIMING_BRANCH }, // BT/S
     { 0xF000, 0x8F00, SH_TIMING_BRANCH }, // BF/S
     { 0xF00F, 0x400B, SH_TIMING_BRANCH }, // JSR
     { 0xF00F, 0x402B, SH_TIMING_BRANCH }, // JMP
     { 0xFFFF, 0x000B, SH_TIMING_BRANCH }, // RTS
     { 0xF0FF, 0x4000, SH_TIMING_BRANCH }, // BRAF
     { 0xF0FF, 0x0023, SH_TIMING_BRANCH }, // BSRF
 
     // Load operations
     { 0xF000, 0x5000, SH_TIMING_LOAD }, // MOV.L @(disp,Rm),Rn
     { 0xF000, 0x9000, SH_TIMING_LOAD }, // MOV.W @(disp,PC),Rn
     { 0xF000, 0xD000, SH_TIMING_LOAD }, // MOV.L @(disp,PC),Rn
     { 0xF00F, 0x6000, SH_TIMING_LOAD }, // MOV.B @Rm,Rn
     { 0xF00F, 0x6001, SH_TIMING_LOAD }, // MOV.W @Rm,Rn
     { 0xF00F, 0x6002, SH_TIMING_LOAD }, // MOV.L @Rm,Rn
     { 0xF00F, 0x6004, SH_TIMING_LOAD }, // MOV.B @Rm+,Rn
     { 0xF00F, 0x6005, SH_TIMING_LOAD }, // MOV.W @Rm+,Rn
     { 0xF00F, 0x6006, SH_TIMING_LOAD }, // MOV.L @Rm+,Rn
 
     // Store operations
     { 0xF000, 0x1000, SH_TIMING_STORE }, // MOV.L Rm,@(disp,Rn)
     { 0xF00F, 0x2000, SH_TIMING_STORE }, // MOV.B Rm,@Rn
     { 0xF00F, 0x2001, SH_TIMING_STORE }, // MOV.W Rm,@Rn
     { 0xF00F, 0x2002, SH_TIMING_STORE }, // MOV.L Rm,@Rn
     { 0xF00F, 0x2004, SH_TIMING_STORE }, // MOV.B Rm,@-Rn
     { 0xF00F, 0x2005, SH_TIMING_STORE }, // MOV.W Rm,@-Rn
     { 0xF00F, 0x2006, SH_TIMING_STORE }, // MOV.L Rm,@-Rn
     { 0xF00F, 0x0004, SH_TIMING_STORE }, // MOV.B Rm,@(R0,Rn)
     { 0xF00F, 0x0005, SH_TIMING_STORE }, // MOV.W Rm,@(R0,Rn)
     { 0xF00F, 0x0006, SH_TIMING_STORE }, // MOV.L Rm,@(R0,Rn)
 
     // Load immediate
     { 0xF000, 0xE000, SH_TIMING_LOAD_IMM }, // MOV #imm,Rn
 
     // System register operations
     { 0xF0FF, 0x0032, SH_TIMING_SYS_REG }, // STC SR,Rn
     { 0xF0FF, 0x0022, SH_TIMING_SYS_REG }, // STC GBR,Rn
     { 0xF0FF, 0x0012, SH_TIMING_SYS_REG }, // STC VBR,Rn
     { 0xF0FF, 0x0042, SH_TIMING_SYS_REG }, // STC SSR,Rn
     { 0xF0FF, 0x0052, SH_TIMING_SYS_REG }, // STC SPC,Rn
     { 0xF0FF, 0x003A, SH_TIMING_SYS_REG }, // STC SR,@-Rn
     { 0xF0FF, 0x002A, SH_TIMING_SYS_REG }, // STC GBR,@-Rn
     { 0xF0FF, 0x001A, SH_TIMING_SYS_REG }, // STC VBR,@-Rn
     { 0xF0FF, 0x0036, SH_TIMING_SYS_REG }, // LDC Rm,SR
     { 0xF0FF, 0x0026, SH_TIMING_SYS_REG }, // LDC Rm,GBR
     { 0xF0FF, 0x0016, SH_TIMING_SYS_REG }, // LDC Rm,VBR
     { 0xF0FF, 0x003E, SH_TIMING_SYS_REG }, // LDC @Rm+,SR
     { 0xF0FF, 0x002E, SH_TIMING_SYS_REG }, // LDC @Rm+,GBR
     { 0xF0FF, 0x001E, SH_TIMING_SYS_REG }, // LDC @Rm+,VBR
 
     // FPU conversion
     { 0xF0FF, 0xF02D, SH_TIMING_FCNV }, // FLOAT FPUL,FRn
     { 0xF0FF, 0xF03D, SH_TIMING_FCNV }, // FTRC FRm,FPUL
     { 0xF0FF, 0xF05D, SH_TIMING_FCNV }, // FCNVDS
     { 0xF0FF, 0xF0BD, SH_TIMING_FCNV }, // FCNVSD
 
     // FPU move
     { 0xF00F, 0xF00C, SH_TIMING_FMOVE }, // FMOV FRm,FRn
     { 0xF00F, 0xF008, SH_TIMING_FMOVE }, // FMOV @Rm,FRn
     { 0xF00F, 0xF00A, SH_TIMING_FMOVE }, // FMOV FRm,@Rn
     { 0xF00F, 0xF009, SH_TIMING_FMOVE }, // FMOV @Rm+,FRn
     { 0xF00F, 0xF00B, SH_TIMING_FMOVE }, // FMOV FRm,@-Rn
 
     // FPU arithmetic
     { 0xF00F, 0xF000, SH_TIMING_FARITH }, // FADD FRm,FRn
     { 0xF00F, 0xF001, SH_TIMING_FARITH }, // FSUB FRm,FRn
     { 0xF00F, 0xF002, SH_TIMING_FARITH }, // FMUL FRm,FRn
     { 0xF00F, 0xF003, SH_TIMING_FARITH }, // FDIV FRm,FRn
     { 0xF00F, 0xF00E, SH_TIMING_FARITH }, // FMAC FR0,FRm,FRn
     { 0xF0FF, 0xF04D, SH_TIMING_FARITH }, // FNEG FRn
     { 0xF0FF, 0xF05D, SH_TIMING_FARITH }, // FABS FRn
 
     // FPU comparisons
     { 0xF00F, 0xF004, SH_TIMING_FCOMP }, // FCMP/EQ FRm,FRn
     { 0xF00F, 0xF005, SH_TIMING_FCOMP }, // FCMP/GT FRm,FRn
 
     // Prefetch
     { 0xF0FF, 0x0083, SH_TIMING_PREF }, // PREF @Rn
 
     // Multi-operations
     { 0xF00F, 0x000F, SH_TIMING_MULTI_OP }, // MAC.L @Rm+,@Rn+
     { 0xF00F, 0x400F, SH_TIMING_MULTI_OP }, // MAC.W @Rm+,@Rn+
 
     // Traps and exceptions
     { 0xFF00, 0xC300, SH_TIMING_TRAP }, // TRAPA #imm
 
     // Return from exception
     { 0xFFFF, 0x002B, SH_TIMING_RTE }, // RTE
 
     // Clear MAC
     { 0xFFFF, 0x0028, SH_TIMING_CLRMAC }, // CLRMAC
 
     // No operation
     { 0xFFFF, 0x0009, SH_TIMING_NOP }, // NOP
 
     // Atomic store
     { 0xF0FF, 0x00C3, SH_TIMING_MOVCA }, // MOVCA.L R0,@Rn
 
     // Test and set
     { 0xF0FF, 0x401B, SH_TIMING_TAS }, // TAS.B @Rn
 
     // Division
     { 0xF0FF, 0x4015, SH_TIMING_DIV }, // DIV1 Rm,Rn
 
     // FPU advanced operations
     { 0xF0FF, 0xF06D, SH_TIMING_FSQRT }, // FSQRT FRn
     { 0xF0FF, 0xF07D, SH_TIMING_FSQRT }, // FSRRA FRn
     { 0xF0FF, 0xF0ED, SH_TIMING_FIPR }, // FIPR FVm,FVn
     { 0xF0FF, 0xF0FD, SH_TIMING_FTRV }, // FTRV XMTRX,FVn
 
     // MMU operations
     { 0xF0FF, 0x0038, SH_TIMING_LDTLB }, // LDTLB
 
     // Default - for any opcodes not explicitly matched
     { 0x0000, 0x0000, SH_TIMING_INT_ARITH }
 };
 
 // Get the timing type for a specific opcode
 static sh_timing_type sh_get_timing_type(uint16_t opcode) {
     // Go through mapping table to find matching opcode pattern
     for (int i = 0; i < sizeof(sh_timing_map) / sizeof(sh_timing_map[0]); i++) {
         if ((opcode & sh_timing_map[i].mask) == sh_timing_map[i].pattern) {
             return sh_timing_map[i].timing_type;
         }
     }
 
     // Default to basic integer arithmetic if no match found
     return SH_TIMING_INT_ARITH;
 }
 
 // Get the total cycles for an instruction, including potential pipeline stalls
 static int sh_get_instruction_cycles(uint16_t opcode, bool is_sh4, bool in_delay_slot = false) {
     sh_timing_type timing = sh_get_timing_type(opcode);
 
     // Base cycles for the instruction
     int cycles = is_sh4 ? sh4_insn_timings[timing] : sh3_insn_timings[timing];
 
     // Add pipeline stall penalty if applicable
     cycles += is_sh4 ? sh4_pipeline_stalls[timing] : sh3_pipeline_stalls[timing];
 
     // Add delay slot penalty if in a delay slot
     if (in_delay_slot) {
         cycles += is_sh4 ? sh4_pipeline_stalls[SH_TIMING_EXEC_SLOT] :
                          sh3_pipeline_stalls[SH_TIMING_EXEC_SLOT];
     }
 
     // Special case for DIV1 on SH3 - should be ~1 cycle per bit
     if (!is_sh4 && timing == SH_TIMING_DIV) {
         // For SH3, DIV1 operations are already calculated as 32 cycles in the table
         // No need for further adjustment
     }
 
     // Special case for MAC operations - depends on operands
     if (timing == SH_TIMING_MAC) {
         // MAC.L is significantly slower than basic MAC
         if ((opcode & 0xF00F) == 0x000F) {  // MAC.L @Rm+,@Rn+
             if (!is_sh4) {
                 cycles += 5;  // Additional cycles for MAC.L on SH3
             } else {
                 cycles += 2;  // Additional cycles for MAC.L on SH4
             }
         }
     }
 
     return cycles;
 }
 
 // Determine if an instruction is accessing memory
 static bool sh_is_memory_access(uint16_t opcode) {
     // Check if opcode is a memory load/store
     uint16_t op_class = opcode & 0xF000;
 
     // MOV.L @(disp,Rm),Rn and MOV.L Rm,@(disp,Rn)
     if (op_class == 0x5000 || op_class == 0x1000)
         return true;
 
     // MOV.W @(disp,PC),Rn and MOV.L @(disp,PC),Rn
     if (op_class == 0x9000 || op_class == 0xD000)
         return true;
 
     // Check for other memory access patterns
     if ((opcode & 0xF00F) == 0x6000 || // MOV.B @Rm,Rn
         (opcode & 0xF00F) == 0x6001 || // MOV.W @Rm,Rn
         (opcode & 0xF00F) == 0x6002 || // MOV.L @Rm,Rn
         (opcode & 0xF00F) == 0x6004 || // MOV.B @Rm+,Rn
         (opcode & 0xF00F) == 0x6005 || // MOV.W @Rm+,Rn
         (opcode & 0xF00F) == 0x6006 || // MOV.L @Rm+,Rn
         (opcode & 0xF00F) == 0x2000 || // MOV.B Rm,@Rn
         (opcode & 0xF00F) == 0x2001 || // MOV.W Rm,@Rn
         (opcode & 0xF00F) == 0x2002 || // MOV.L Rm,@Rn
         (opcode & 0xF00F) == 0x2004 || // MOV.B Rm,@-Rn
         (opcode & 0xF00F) == 0x2005 || // MOV.W Rm,@-Rn
         (opcode & 0xF00F) == 0x2006 || // MOV.L Rm,@-Rn
         (opcode & 0xF00F) == 0x0004 || // MOV.B Rm,@(R0,Rn)
         (opcode & 0xF00F) == 0x0005 || // MOV.W Rm,@(R0,Rn)
         (opcode & 0xF00F) == 0x0006 || // MOV.L Rm,@(R0,Rn)
         (opcode & 0xF00F) == 0x000C || // MOV.B @(R0,Rm),Rn
         (opcode & 0xF00F) == 0x000D || // MOV.W @(R0,Rm),Rn
         (opcode & 0xF00F) == 0x000E)   // MOV.L @(R0,Rm),Rn
         return true;
 
     // FPU memory access operations
     if ((opcode & 0xF00F) == 0xF008 || // FMOV @Rm,FRn
         (opcode & 0xF00F) == 0xF009 || // FMOV @Rm+,FRn
         (opcode & 0xF00F) == 0xF00A || // FMOV FRm,@Rn
         (opcode & 0xF00F) == 0xF00B)   // FMOV FRm,@-Rn
         return true;
 
     // LDC/STC memory operations
     if ((opcode & 0xF0FF) == 0x401E || // LDC @Rm+,SR
         (opcode & 0xF0FF) == 0x402E || // LDC @Rm+,GBR
         (opcode & 0xF0FF) == 0x403E || // LDC @Rm+,VBR
         (opcode & 0xF0FF) == 0x404E || // LDC @Rm+,SSR
         (opcode & 0xF0FF) == 0x405E || // LDC @Rm+,SPC
         (opcode & 0xF0FF) == 0x406E || // LDC @Rm+,DBR
         (opcode & 0xF0FF) == 0x407E || // MAC access
         (opcode & 0xF0FF) == 0x408E || // LDC @Rm+,Rn_BANK
         (opcode & 0xF0FF) == 0x409E || // LDC @Rm+,Rn_BANK
         (opcode & 0xF0FF) == 0x40AE || // LDC @Rm+,Rn_BANK
         (opcode & 0xF0FF) == 0x40BE || // LDC @Rm+,Rn_BANK
         (opcode & 0xF0FF) == 0x40CE || // LDC @Rm+,Rn_BANK
         (opcode & 0xF0FF) == 0x40DE || // LDC @Rm+,Rn_BANK
         (opcode & 0xF0FF) == 0x40EE || // LDC @Rm+,Rn_BANK
         (opcode & 0xF0FF) == 0x40FE || // LDC @Rm+,Rn_BANK
         (opcode & 0xF0FF) == 0x4016 || // STC Rm,@-Rn
         (opcode & 0xF0FF) == 0x4026 || // STC GBR,@-Rn
         (opcode & 0xF0FF) == 0x4036 || // STC VBR,@-Rn
         (opcode & 0xF0FF) == 0x4046 || // STC SSR,@-Rn
         (opcode & 0xF0FF) == 0x4056 || // STC SPC,@-Rn
         (opcode & 0xF0FF) == 0x4066)   // STC DBR,@-Rn
         return true;
 
     return false;
 }
 
 // Get memory access cycles based on the address and CPU type
 // This function should be called by the CPU emulator when handling memory access instructions
 static int sh_get_memory_cycles(uint32_t address, bool is_write, bool is_sh4,
                                bool is_cached = false, bool is_code = false) {
     // Default to uncached memory timing
     int cycle_penalty = 0;
 
     // The sh34_memory_timing struct we'll use based on CPU type
     const sh34_memory_timing &mem_timing = is_sh4 ? sh4_memory_timing : sh3_memory_timing;
 
     // On-chip memory/registers (typical SH-4 memory map)
     if (address >= 0x1C000000 && address <= 0x1FFFFFFF) {
         // On-chip RAM
         cycle_penalty = is_write ? mem_timing.on_chip_ram_write : mem_timing.on_chip_ram_read;
     }
     else if (address >= 0xE0000000 && address <= 0xFFFFFFFF) {
         // On-chip registers
         cycle_penalty = is_write ? mem_timing.on_chip_reg_write : mem_timing.on_chip_reg_read;
     }
     else {
         // External memory
         if (is_cached) {
             cycle_penalty = is_write ? mem_timing.cached_write : mem_timing.cached_read;
         }
         else {
             cycle_penalty = is_write ? mem_timing.uncached_write : mem_timing.uncached_read;
         }
     }
 
     return cycle_penalty;
 }
 
 #endif // MAME_CPU_SH_SH34_TIMINGS_H
 