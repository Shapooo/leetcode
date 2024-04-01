impl Solution {
    pub fn split_words_by_separator(words: Vec<String>, separator: char) -> Vec<String> {
        words
            .iter()
            .flat_map(|word| word.split(separator))
            .filter_map(|s| (!s.is_empty()).then_some(s.to_string()))
            .collect::<Vec<_>>()
    }
}
