// Copyright (c) 2014 NamoMedia. All rights reserved.

#import <Foundation/NSObject.h>

/**
 Error domain for NSError objects returned by the Namo SDK.

 @available Namo 2.3 and later.
*/
extern NSString *const NAMOErrorDomain;

/**
 NSError codes in NAMOErrorDomain.

 @available Namo 2.3 and later.
*/
enum {
  /**
   The framework was not in a valid state to perform the requested operation. Check your logs.
   @available Namo 2.3 and later.
  */
  NAMOInvalidStateError,

  /**
   The network returned a response, but it was invalid.
   @available Namo 2.3 and later.
  */
  NAMOInvalidResponseError,

  /**
   The network returned a response, but it contained an empty list of ads.
   @available Namo 2.3 and later.
  */
  NAMONoAdsError
};

