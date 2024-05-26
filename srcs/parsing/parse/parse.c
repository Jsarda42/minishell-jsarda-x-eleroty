#include "../../../includes/minishell.h"

int	tokenizer(char *line, t_list *nodes, t_minishell *mini)
{
	t_list	*current;
	t_token	*tokens;
	char	*input;

	input = NULL;
	(void)mini;
	if (open_quote_check(line))
	{
		free(line);
		return (1);
	}
	// DEBUG : input line with open quote check
	printf("Input line 1: %s\n", line);

	input = remove_quotes(line);
	// DEBUG : input line without quotes
	printf("Input line 2 : %s\n", input);

	// TO DO 
	// if (contains_dollar(line))
	// {
	// 	input =  expand_variables(line, mini->env);
	// }

	ft_split_pipes_spaces(input, &nodes);
	// DEBUG : input line without spaces 
	printf("Input line 3 : %s\n", input);

	current = nodes;
	while (current != NULL)
	{
		// DEBUG
		printf("Node : %s\n", current->content);

		tokens = tokenize_input(current->content);
		// DEBUG
		t_token *c = tokens;
		while (c != NULL)
		{
			printf("Token value : %s\n", (char *)c->value);
			printf("Token type : %d\n", (int)c->type);
			c = c->next;
		}

		parse_tokens(tokens);
		// DEBUG
		t_token *curr = tokens;
		while (curr != NULL)
		{
			printf("Token CMD : %s\n", (char *)curr->cmd);
			int i = 0;
			while (curr->args && curr->args[i] != NULL)
				printf("Arg Token : %s\n", (char *)curr->args[i++]);
			curr = curr->next;
		}
		current = current->next;
	}
	return (1);
}
void init_minishell(t_minishell *mini)
{
	mini->env = NULL;
	mini->nodes = NULL;
	// a remplir au fur et a mesure
}
int	is_space(char *line)
{
	int				a;

	a = 0;
	while (line[a] == ' ' || line[a] == '\t'
		|| line[a] == '\n')
		a += 1;
	if (line[a] == '\0')
		return (1);
	return (0);
}
int check_line(char **line)
{
	if (*line[0] == '\0' || is_space(*line) ||  ft_strncmp(*line, "\n", 0))
		return (1);
	return (0);
}
// Segfault on free functions

int	main(int argc, char *argv[], char *env[])
{
	char *input_line;
	t_list *tokens_list;
	t_minishell data;
	int flag;

	input_line = NULL;
	tokens_list = NULL;
	flag = 1;
	(void)argc;
	(void)argv;

	// Initialize minishell struct
	init_minishell(&data);
	// Initialize shell environment
	if (init_env(&data, env))
	{
		// free_minishell(&data);
		return (1);
	}
	// Main shell execution Loop
	while (1)
	{
		input_line = readline("prompt> ");
		if (!input_line)
		{
			rl_clear_history(); // ?
			break ;
		}
		if (check_line(&input_line))
			break ;
		if (!tokenizer(input_line, tokens_list, &data))
		{
			add_history(input_line);
			free(input_line);
			return (0);
		}
		// Parse tokens
		parse_tokens(&tokens_list);
		add_history(input_line);
		free(input_line);
		// return (1);
		// exec command
		// free_input(&minishell);
	}
	ft_lstclear(&tokens_list, free);
	free(input_line);
	// Cleanup shell
	// free_minishell(&data);
	return (0);
}