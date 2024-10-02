import sys
import re
import os

if len(sys.argv) != 3:
    print("Number of arguments is Wrong !")
    
else:
    main_dir = os.getcwd()
    read_dir = sys.argv[1]
    write_dir = sys.argv[2]
    
    try:
        os.chdir(read_dir)
        
        if len(os.listdir()) != 5:
            raise TypeError
          
    except FileNotFoundError:
        print('Input folder not found !')
         
    except TypeError:
        print("Number of files in the folder is invalid !")
        
    else:
        file_names = os.listdir()
        
        for name in file_names:
            
            with open(name) as file:
                # Regex
                pass
            
        choice = 'y'
        os.chdir(main_dir)
        
        if write_dir in os.listdir():
            choice = input("Do you want to delete the output folder ? (y/n): ")
            
        if choice.lower() == 'n':
            print("Exited !")
            
        else:
            if write_dir in os.listdir():
                os.chdir(f'{main_dir}\\{write_dir}')
            
                for name in os.listdir():
                    os.remove(name)
            
            else:
                os.mkdir(write_dir)
                os.chdir(f'{main_dir}\\{write_dir}')

            for name in file_names:
                
                with open(name, 'w') as file:
                    # Regex
                    file.write("Hello")