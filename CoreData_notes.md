## CoreData Notes

1. managed object context有3种并发类型可供使用，如下

* `ConfinementConcurrencyType` specifies that the context will use the thread confinement pattern and that the developer will be responsible for managing all thread access. You should consider this type deprecated and never use it, as the next two types cover all use cases.
* `PrivateQueueConcurrencyType` specifies the context will be associated with a private dispatch queue instead of the main queue. This is the type of queue you just used to move the export operation off of the main queue so it would no longer interfere with the UI.
* `MainQueueConcurrencyType`, the default type, specifies that the context will be associated with the main queue. This type is what the main context (coreDataStack.mainContext) uses. Any UI operation, such as creating the fetched results controller for the table view, must use a context of this type.