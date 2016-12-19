import Foundation
import Darwin

func mixKey(src : String) -> [Character] {
    var diceRoll = 0,
        result = [Character](),
        idx = 0
    let data = Array(src.characters)
    while(idx < 17) {
        diceRoll = Int(arc4random_uniform(UInt32(data.count)))
        result.append(data[diceRoll])
        idx = idx + 1
    }
    return result 
}

let source = "abcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()"
let key = mixKey(src: source)
print(key)
