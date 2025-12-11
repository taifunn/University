def is_palindrom(text):
    text = ''.join(ch.lower() for ch in text if ch.isalnum())
    return text == text[::-1]
print(is_palindrom("Míč omočím."))