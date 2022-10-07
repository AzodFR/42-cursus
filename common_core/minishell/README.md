# minishell

## Mandatory

### Basic

| Prompt | Execve |
|--------|--------|
|   OK   |   OK   |

### Builtins

| cd | env | pwd | export | unset | exit | echo |
|----|-----|-----|--------|-------|------|------|
| OK |  OK |  OK |   OK   |   OK  |  OK  |  OK  |

### Separator

| ; | \| | ' | " | > | >> | < |
|---|---|---|---|---|----|---|
| OK| OK| OK| OK| OK| OK | OK|

### Env

| $? | $_ | $... |
|----|----|------|
| OK | OK |  OK  |

### Signals

| Ctrl+C | Ctrl+D | Ctrl+\ |
|--------|--------|--------|
|   OK   |   OK   |   OK   |

## Bonus

| << | Termcaps | && / \|\| | * |
|----|----------|-----------|---|
| NO |    NO    |     NO    | NO|
## GIF

![alt text](https://i.gyazo.com/5692b2fe2d03d5a82a86397095ffcd5d.gif)

![alt text](https://i.gyazo.com/687caedc7ce7747f0d0f887a3965a80c.gif)

![alt text](https://i.gyazo.com/ecadfef06318d3428c3dd29b23fffd56.gif)

## Tester

[minishell_tester](https://github.com/thallard_minishell_tester)

## Finale garde

![alt text](https://i.imgur.com/rKy0zGM.png)
