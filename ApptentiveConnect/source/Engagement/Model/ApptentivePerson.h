//
//  ApptentivePerson.h
//  ApptentiveConnect
//
//  Created by Frank Schmitt on 11/15/16.
//  Copyright © 2016 Apptentive, Inc. All rights reserved.
//

#import "ApptentiveCustomData.h"

@class ApptentiveMutablePerson;

@interface ApptentivePerson : ApptentiveCustomData

@property (readonly, strong, nonatomic) NSString *name;
@property (readonly, strong, nonatomic) NSString *emailAddress;

- (instancetype)initWithMutablePerson:(ApptentiveMutablePerson *)mutablePerson;

@end
