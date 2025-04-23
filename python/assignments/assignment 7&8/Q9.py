# 9. Create a tokenizer for your own language (mother tongue you speak). The tokenizer should 
# tokenize punctuations, dates, urls, emails, numbers (in all different forms such as “33.15”, 
# “3,22,243”, “313/77”), social media usernames/user handles. Use regular expressions to design 
# this. [Hint: Use unicode blocks for your language, check wikipedia pages] 

import re

def hindi_tokenizer(text):
    patterns = {
        "url": r"https?://(?:[-\w.]|(?:%[\da-fA-F]{2}))+",
        "email": r"[\w\.-]+@[\w\.-]+\.[a-zA-Z]{2,6}",
        "date": r"\d{1,2}[-/.]\d{1,2}[-/.]\d{2,4}",
        "number": r"\d{1,3}(?:,\d{2,3})*(?:\.\d+)?|\d+/\d+|[\u0966-\u096F]+",  # Hindi numerals
        "username": r"@[\w_]+",
        "punctuation": r"[.,!?;:\"'()\[\]{}]",
        "hindi_word": r"[\u0900-\u097F]+"  # Hindi Devanagari block
    }
    
    combined_pattern = "|".join(f"(?P<{key}>{pattern})" for key, pattern in patterns.items())
    
    tokens = []
    for match in re.finditer(combined_pattern, text):
        for key, value in match.groupdict().items():
            if value:
                tokens.append((key, value))
    
    return tokens

text = "मेरा ईमेल abc@gmail.com है। मेरी वेबसाइट https://example.com है। मेरी उम्र १८ है!"
tokens = hindi_tokenizer(text)
print(tokens)