/*
 *	defines.h - The macro definition for profiling and debug.  
 *
 *	Copyright (C) 2010 Michael.kang (blackfin.kang@gmail.com)
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License version 2 as
 *	published by the Free Software Foundation.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program; if not, write to the Free Software
 *	Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
/*
 * 01/16/2011   Michael.Kang  <blackfin.kang@gmail.com>
 */

#ifndef __DYNCOM_DEFINE_H__
#define __DYNCOM_DEFINE_H__
/*
 * Add big switches for testing here.
 * libcpu shouldn't use many ifdefs. Consider dropping one of
 * the alteratives or make it a runtime option (i.e. let the
 * client decide).
 */

// Copy register set paramters into a local array this hints LLVM to
// not care about writing back the contents too often.
// This works particularly well with PromoteMemoryToReg optimization
// pass, which removes the local arrays and make LLVM do the register
// allocation for us
//#define OPT_LOCAL_REGISTERS

// DFS limit when CPU_CODEGEN_TAG_LIMIT is set by the client.
// '6' is the optimum for OpenBSD's 'date' on M88K.
#define LIMIT_TAGGING_DFS 2
#define FAST_MEMORY

#define ENABLE_DEBUG_ME 0
#define ENABLE_ICOUNTER 0

/* Micros of time prifile */
#define THREAD_CLOCK 1
#define TIMING_PROF 1
#endif
