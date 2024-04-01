fn main() {
    let mut a: Vec<i32> = vec![1, 2, 3];

    for i in &a {
        // iterate immutably
        let i: &i32 = i; // elements are immutable pointers
        println!("{}", i);
    }

    for i in &mut a {
        // iterate mutably
        let i: &mut i32 = i; // elements are mutable pointers
        *i *= 2;
        println!("{}", i);
    }

    for i in a {
        // iterate by-value
        let i: i32 = i; // elements are values
        println!("{}", i);
    }

    let v = vec![1; 10];
    for (pos, e) in v.iter().enumerate() {
        println!("{}: {:?}", pos, e);
    }
}
