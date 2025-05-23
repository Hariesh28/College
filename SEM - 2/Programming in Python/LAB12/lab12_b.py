some_content = '''Adolf Hitler, born in Austria in 1889, rose to power as the Chancellor of Germany in 1933.
He was the leader of the Nazi Party, propagating extreme nationalist and anti-Semitic ideologies.
Hitler's totalitarian regime led to the outbreak of World War II in 1939, resulting in immense human suffering and loss.
Under his rule, millions of Jews, as well as other minorities, were systematically persecuted and murdered in the Holocaust.
His charisma and oratory skills enabled him to sway the masses with his fervent speeches and promises of a restored Germany.
Hitler's expansionist policies sought to establish German dominance over Europe, leading to devastating consequences for the continent.
The defeat of Nazi Germany in 1945 marked the end of Hitler's reign, but not before his actions had reshaped the course of history.
He implemented draconian measures to suppress dissent and consolidate power, creating a cult of personality around himself.
Hitler's ambition for a racially pure society fueled atrocities that continue to haunt humanity's collective memory.
His legacy serves as a stark reminder of the dangers of unchecked authoritarianism and the importance of safeguarding democratic principles.'''

try:
    file = open('data.txt')
    
except FileNotFoundError:
    
    file = open('data.txt', 'w')
    file.write(some_content)
    print("File not found !")
    print("Written some content to the file")
    
else:
    print("Contents of file: ")
    print(file.read())
    
finally:
    file.close()