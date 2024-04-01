pub fn descending_order(x: u64) -> u64 {
    let mut v: Vec<u64> = Vec::new();
    let mut x = x;

    while x != 0 {
        v.push(x % 10);
        x = x / 10;
    }
    v.sort();

    let mut result: u64 = 0;
    while !v.is_empty() {
        result *= 10;
        result += v.pop().unwrap();
    }
    result
}

#[test]
fn returns_expected() {
    assert_eq!(descending_order(0), 0);
    assert_eq!(descending_order(1), 1);
    assert_eq!(descending_order(15), 51);
    assert_eq!(descending_order(1021), 2110);
    assert_eq!(descending_order(123456789), 987654321);
    assert_eq!(descending_order(145263), 654321);
    assert_eq!(descending_order(1254859723), 9875543221);
}
