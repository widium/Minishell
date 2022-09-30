## Minimalist Bash Prompt
- [Get Started](#get-started)
- [Understanding the project structure](#understanding-the-project-structure)
- [Parser](#parser)
- [Data Structure](#data-structure)
- [Theorical Utils](#theorical-utils)
***
![ezgif com-gif-maker](https://user-images.githubusercontent.com/85416801/193201839-19b1a2d4-73d5-4c6d-9264-7eb79829c24e.gif)
***
### Get Started
#### Dependancy
- Arch
~~~bash
sudo pacman -Syu readline
~~~
- MacOS
~~~bash
brew install readline
~~~
- add in header file
~~~C
# include <readline/readline.h>
# include <readline/history.h>
add -lreadline with compilation
~~~
***
### Understanding the project structure
![](https://i.imgur.com/mTEApbZ.png)

~~~C
void prompt(t_env *env, char *line)
{
	parsing(env, line);
	check_error_parsing(env);
	if (doesnt_have_error_parsing)
	{
		processing_cmd(env);
		processing_redirection(env);
		if (doesnt_have_error_processing)
			execution(env);
	}
	remove_all_token(env);
	reset_counter_error(env);
	free(line);
}
~~~
***
### Parser
![](https://i.imgur.com/s7VvwbT.png)
![](https://i.imgur.com/4RxjAlf.png)
![](https://i.imgur.com/teLmxbE.png)
![](https://i.imgur.com/uYLGKNl.png)
***
### Data Structure
![](https://i.imgur.com/dQtxpT3.png)
![](https://i.imgur.com/8hK8OtJ.png)
![](https://i.imgur.com/BW2xbwu.png)
***
### Theorical Utils
***
