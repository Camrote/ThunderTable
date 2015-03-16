//
//  TSCTableRow.h
// ThunderTable
//
//  Created by Phillip Caudell on 16/08/2013.
//  Copyright (c) 2013 madebyphill.co.uk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TSCTableRowDataSource.h"

/**
 `TSCTableRow` is the primary class for creating rows within a `TSCTableViewController`. Each row must be contained within a `TSCTableSection`.
 */
@interface TSCTableRow : NSObject <TSCTableRowDataSource>

///---------------------------------------------------------------------------------------
/// @name Initializing a TSCTableRow Object
///---------------------------------------------------------------------------------------

/**
 Initializes the row with a single title.
 @param title The title to display in the row
 @discussion The title will populate the `textLabel` text property of a `UITableViewCell`
 */
+ (instancetype)rowWithTitle:(NSString *)title;

/**
 Initializes the row with a single title in a custom color
 @param title The title to display in the row
 @param textColor A 'UIColor' to color the text with
 @discussion The title will populate the `textLabel` text property of a `UITableViewCell`. The textColor will be applied to the text.
 */
+ (instancetype)rowWithTitle:(NSString *)title textColor:(UIColor *)textColor;

/**
 Initializes the row with a single title.
 @param title The title to display in the row
 @param subtitle The subtitle to display beneath the title in the row
 @param image The image to be displayed to the left hand side of the cell
 @discussion The title will populate the `textLabel` text property and the subtitle will populate the `detailTextLabel` text property of the `UITableViewCell`
 */
+ (instancetype)rowWithTitle:(NSString *)title subtitle:(NSString *)subtitle image:(UIImage *)image;

/**
 Initializes the row with a single title.
 @param title The title to display in the row
 @param subtitle The subtitle to display beneath the title in row
 @param imageURL The URL of the image to be displayed to the left hand side of the cell. Loaded asynchronously
 @discussion The title will populate the `textLabel` text property and the subtitle will populate the `detailTextLabel` text property of the `UITableViewCell`
 @note Please set the `imagePlaceholder` property when using this method. This is required because the image width and height is used at layout to provide appropriate space for your loaded image.
 */
+ (instancetype)rowWithTitle:(NSString *)title subtitle:(NSString *)subtitle imageURL:(NSURL *)imageURL;

///---------------------------------------------------------------------------------------
/// @name Handling selection
///---------------------------------------------------------------------------------------

/**
 Adds a target and selector to the cell. This makes the row selectable.
 @param target The object to send the selection event to
 @param selector The selector to call on the target object
 @discussion Calling this method makes the cell selectable in the table view, also adding a selection indicator to the cell
 */
- (void)addTarget:(id)target selector:(SEL)selector;

/**
 @abstract The object to be called upon the user selecting the row
 */
@property (nonatomic, weak) id target;

/**
 @abstract The selector to be called on the target upon the user selecting the row
 */
@property (nonatomic, assign) SEL selector;

///---------------------------------------------------------------------------------------
/// @name Row configuration
///---------------------------------------------------------------------------------------

/**
 @abstract The text to be displayed in the cells `textLabel`
 */
@property (nonatomic, copy) NSString *title;

/**
 @abstract The text to be displayed in the cells `detailTextLabel`
 */
@property (nonatomic, copy) NSString *subtitle;

/**
 @abstract The `UIImage` to be displayed in the cell
 */
@property (nonatomic, strong) UIImage *image;

/**
 @abstract The URL of the image to be loaded into the image area of the cell
 */
@property (nonatomic, strong) NSURL *imageURL;

/**
 @abstract The placeholder image that is displayed whilst the cell is asynchronously loading the image defined by the `imageURL`
 */
@property (nonatomic, strong) UIImage *imagePlaceholder;

/**
 @abstract The `UIColor` to apply to the text in the cell
 */
@property (nonatomic, strong) UIColor *textColor;

/**
 @abstract The link that a row should attempt to push when selected
 */
@property (nonatomic, strong) TSCLink *link;


/**
 @abstract A boolean to configure whether the cell shows the selection indicator when it is selectable
 @discussion The default value of this property is `YES`
 */
@property (nonatomic, assign) BOOL shouldDisplaySelectionIndicator;

/**
 @abstract The accessory type of the row
 */
@property (nonatomic, assign) UITableViewCellAccessoryType accessoryType;

/**
 @abstract The amount of padding to add above and below the contents of the cell.
 @discussion You may find that adjusting this padding value on the cell improves the look and feel of your app
 */
@property (nonatomic, assign) float rowPadding;

@end
