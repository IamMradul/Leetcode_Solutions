import os

folder = "D:\\Coding\\Leetcode_Solutions"   

for filename in os.listdir(folder):
    if filename.endswith(".cpp"):
       
        num = filename.split(".")[0]

       
        if num.isdigit():
            new_name = f"{int(num):04d}.cpp"  # pad with 4 digits
            old_path = os.path.join(folder, filename)
            new_path = os.path.join(folder, new_name)

            # Avoid renaming if already correct
            if old_path != new_path:
                print(f"Renaming {filename} -> {new_name}")
                os.rename(old_path, new_path)
