pub
fn sort_array(arr: &[i32]) -> Vec<i32> {
    let mut result = arr.to_vec();
    let mut odd_vec:Vec<i32> = Vec::new();
    for elem in  result {
        if elem % 2 == 1 {
            odd_vec.push(elem.clone());
        }
    }
    odd_vec.sort();
    // let mut iter = odd_vec.iter();
    // for elem in &mut result {
    //     if elem == &1 {
    //         elem = iter.next().unwrap().clone();
    //     }
    // }
    // let a = result.len().clone();
    // for i in 0..a {

    // }

    // result
    vec![]
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn basic() {
        assert_eq!(sort_array(&[5, 3, 2, 8, 1, 4]), [1, 3, 2, 8, 5, 4]);
        assert_eq!(sort_array(&[5, 3, 1, 8, 0]), [1, 3, 5, 8, 0]);
        assert_eq!(sort_array(&[]), []);
    }
}
