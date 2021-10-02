#Write a function to find the longest common prefix string amongst an array of strings.
#If there is no common prefix, return an empty string "".

def longest_common_prefix(strs) -> str:
    common = ""
    
    strs.sort()
    for i in range(0, len(strs[0])):
        if strs[0][i] == strs[-1][i]:
            common += strs[0][i] 
        if strs[0][i] != strs[-1][i]:
            break

    return common

print(longest_common_prefix(["flow", "flower", "flowing"]))
