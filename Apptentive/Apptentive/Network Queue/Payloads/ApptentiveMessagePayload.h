//
//  ApptentiveMessagePayload.h
//  Apptentive
//
//  Created by Frank Schmitt on 4/19/17.
//  Copyright © 2017 Apptentive, Inc. All rights reserved.
//

#import "ApptentivePayload.h"

@class ApptentiveMessage;

NS_ASSUME_NONNULL_BEGIN


@interface ApptentiveMessagePayload : ApptentivePayload

@property (readonly, nonatomic) ApptentiveMessage *message;

- (instancetype)initWithMessage:(ApptentiveMessage *)message;

@end

NS_ASSUME_NONNULL_END
