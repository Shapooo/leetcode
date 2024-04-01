pub
fn solution(s: &str) -> Vec<String> {

    Vec::new()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn basic() {
        assert_eq!(solution("abcdef"), ["ab", "cd", "ef"]);
        assert_eq!(solution("abcdefg"), ["ab", "cd", "ef", "g_"]);
        assert_eq!(solution(""), [] as [&str; 0]);
    }
}
