// Copyright (c) 2013 Namo Media, Inc. All rights reserved.

/**
 Methods for logging inside the NamoLog framework. Use the following guidelines.
 NAMOLogError
   Something has failed.
 NAMOLogWarning
   Something is amiss and might fail if not corrected.
 NAMOLogNotice
   Things of moderate interest to the user or administrator.
 NAMOLogInfo
   The lowest priority that you would normally log, and purely informational in nature.
*/

#import <Foundation/Foundation.h>
#import <asl.h>

// By default, in non-debug mode we want to disable any logging
// statements except NOTICE and above.
#ifndef NAMO_COMPILE_TIME_LOG_LEVEL
#ifdef NDEBUG
		#define NAMO_COMPILE_TIME_LOG_LEVEL ASL_LEVEL_NOTICE
	#else
#define NAMO_COMPILE_TIME_LOG_LEVEL ASL_LEVEL_DEBUG
#endif
#endif


#if NAMO_COMPILE_TIME_LOG_LEVEL >= ASL_LEVEL_ERR
void NAMOLogError(NSString *format, ...);
#else
#define NAMOLogError(...)
#endif

#if NAMO_COMPILE_TIME_LOG_LEVEL >= ASL_LEVEL_WARNING
void NAMOLogWarning(NSString *format, ...);
#else
#define NAMOLogWarning(...)
#endif

#if NAMO_COMPILE_TIME_LOG_LEVEL >= ASL_LEVEL_NOTICE
void NAMOLogNotice(NSString *format, ...);
#else
#define NAMOLogNotice(...)
#endif

#if NAMO_COMPILE_TIME_LOG_LEVEL >= ASL_LEVEL_INFO
void NAMOLogInfo(NSString *format, ...);
#else
#define NAMOLogInfo(...)
#endif

#define NAMOParameterAssert(condition) \
  if (!(condition)) { \
    NAMOLogWarning(@"Invalid parameter not satisfying: %s", #condition); \
  }
