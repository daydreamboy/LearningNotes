## Swift Notes

1. _ = try? FileManager.default.removeItem(at: shmURL)
> _标号而且没有变量，表示不关心返回值，即使没有返回值

2. ??操作符（nil coalescing operator）
> let coalescedHeight = height != nil ? height! : "" 等价于let coalescedHeight = height ?? ""

3. 运行时区分系统版本

```swift
func addPhoneNumber(phNo : String) {
  if #available(iOS 9.0, *) {
      let store = CNContactStore()
      let contact = CNMutableContact()
      let homePhone = CNLabeledValue(label: CNLabelHome, value: CNPhoneNumber(stringValue :phNo ))
      contact.phoneNumbers = [homePhone]
      let controller = CNContactViewController(forUnknownContact : contact)// .viewControllerForUnknownContact(contact)
      controller.contactStore = store
      controller.delegate = self
      self.navigationController?.setNavigationBarHidden(false, animated: true)
      self.navigationController!.pushViewController(controller, animated: true)
  }
}
```