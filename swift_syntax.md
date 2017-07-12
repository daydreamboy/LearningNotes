1. _ = try? FileManager.default.removeItem(at: shmURL)
_标号而且没有变量，表示不关心返回值，即使没有返回值

2. nil coalescing operator (??)
let coalescedHeight = height != nil ? height! : "" 等价于let coalescedHeight = height ?? ""
