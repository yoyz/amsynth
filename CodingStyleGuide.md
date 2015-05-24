# Language #

`C++` is the main development language, although some modules are written in pure `C`.

GTK+ should be used for new UI code in preference of gtkmm. The eventual aim is to remove dependency on gtkmm entirely. There are several reasons for this, predominantly that GTK+ has more documentation and sample code, as well as gtkmm having much slower build times due to its heavy use of C++ templates.

# Naming #

### File Names ###

Filenames should be all lowercase and can include underscores (_) or dashes (-)._

C++ source files should use the `.cpp` file extension. Header files should only use the `.h` file extension (never `.hpp`.) The exception to this is third party code that has been copied into the project.

### Type Names ###

Type names start with a capital letter and have a capital letter for each new word, with no underscores: `MyExcitingClass`, `MyExcitingEnum`.

### Variable Names ###

Variable names are all lowercase, with underscores between words. Class member variables are prefixed with an underscore. For instance: `my_exciting_local_variable`, `_my_exciting_member_variable`.

### Macros ###

C Preprocessor macros are all uppercase: `EXCITING_MACRO`

# Formatting #

```

int my_function(int parameter)
{
    if (parameter % 3 == 0)
        return parameter / 3;

    if (parameter % 2 == 0) {
        parameter = parameter / 2;
        return parameter;
    }

    some_other_function(parameter);

    return 0;
}

```