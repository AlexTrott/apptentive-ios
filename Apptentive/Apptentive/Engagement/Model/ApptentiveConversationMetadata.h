//
//  ApptentiveConversationMetadata.h
//  Apptentive
//
//  Created by Frank Schmitt on 2/20/17.
//  Copyright © 2017 Apptentive, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ApptentiveConversationMetadataItem, ApptentiveConversation;

typedef BOOL (^ApptentiveConversationMetadataItemFilter)(ApptentiveConversationMetadataItem *item);


@interface ApptentiveConversationMetadata : NSObject <NSSecureCoding>

@property (strong, nonatomic) NSMutableArray *items;

- (ApptentiveConversationMetadataItem *)findItemFilter:(ApptentiveConversationMetadataItemFilter)filter;
- (void)addItem:(ApptentiveConversationMetadataItem *)item;
- (void)deleteItem:(ApptentiveConversationMetadataItem *)item;

- (void)printAsTableWithTitle:(NSString *)title;

@end
