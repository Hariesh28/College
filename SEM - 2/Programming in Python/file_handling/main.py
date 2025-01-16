import sys
import os
import re

def main():

    if len(sys.argv) != 3:
        print("Number of arguments is wrong !")
        return 0
     
    main_dir = os.getcwd()
    read_dir = sys.argv[1]
    write_dir = sys.argv[2]
    
    pattern = r'^[A-Za-z][A-Za-z0-9\.-_]*$'
    domain = '@snuchennai.edu.in'
    valid_special_characters = ['.', '-', '_']
    choice = 'y'
    
    try:
        os.chdir(read_dir)
        
        if len(os.listdir()) != 5:
            raise TypeError
        
    except FileNotFoundError:
        print("Input folder not found !")
        return 0
    
    except TypeError:
        print("Number of files in the folder is invalid !")
        return 0
    
    read_files = os.listdir()
    
    os.chdir(main_dir)
    
    if write_dir in os.listdir():
        choice = input("Do you want to delete the output folder ? (y/n): ")

    if choice.lower() == 'n':
        print("Exited !")
        return 0
    
    if write_dir in os.listdir():
        
        os.chdir(write_dir)
        
        for name in os.listdir():
            os.remove(name)

    else:
        os.mkdir(write_dir)
    
    for name in read_files:
        
        valid_usernames = list()
        
        with open(f'{main_dir}\\{read_dir}\\{name}') as file:        
           content = file.readlines()

        for username in content:
            valid = ''
            
            if(username in re.findall(username, pattern)):
                valid += username + domain
                
            else:
                for i in range(len(username)):
                    if username[i].isalnum() or username[i] in valid_special_characters:
                        valid += username[i]
                        
                valid += domain

            valid_usernames.append(valid)
    
        with open(f'{main_dir}\\{write_dir}\\{name}', 'a') as file:
            
            for name in valid_usernames:
                file.write(f'{name}\n')
                

if __name__ == '__main__':
    main()
