import Foundation

var dataSemaphore = DispatchSemaphore(value: 0)

let url = URL(string: "https://nvisium.com")
let task = URLSession.shared.dataTask(with: url!) { (data, response, error) in
    if error != nil {
        print(error!)
        dataSemaphore.signal() 
    } else {
        if let usableData = data {
            print(response!)
            print(usableData)
            dataSemaphore.signal()
        }
    }
}

task.resume()

dataSemaphore.wait()
