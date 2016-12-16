import hashlib

secret = 'ckczppom'
i = 0;

while True:
    i += 1;
    if hashlib.md5(secret + str(i)).hexdigest()[:6] == '000000':
        break

print i
