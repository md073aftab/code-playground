import re

def find_words(text):
    pattern = r"\ba\w*d\b"  # Regex pattern to match words starting with 'a' and ending with 'd'
    words = re.findall(pattern, text, re.IGNORECASE)  # Case-insensitive search
    return words

# Example usage
text = "Alice and Arnold played around and avoided the bad acid."
result = find_words(text)
print("Words that start with 'a' and end with 'd':", result)
