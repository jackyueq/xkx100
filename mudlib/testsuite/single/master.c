// file: /daemon/master.c

#include <globals.h>

// /inherit/master/valid.c contains all the valid_* functions
inherit "/inherit/master/valid";

object
connect()
{
	object login_ob;
	mixed err;
   
	err = catch(login_ob = new(LOGIN_OB));

	if (err) {
		write("It looks like someone is working on the player object.\n");
		write(err);
		destruct(this_object());
	}
	return login_ob;
}

// compile_object: This is used for loading MudOS "virtual" objects.
// It should return the object the mudlib wishes to associate with the
// filename named by 'file'.  It should return 0 if no object is to be
// associated.

mixed
compile_object(string file)
{
//	return (mixed)VIRTUAL_D->compile_object(file);
	return 0;
}

// This is called when there is a driver segmentation fault or a bus error,
// etc.  As it's static it can't be called by anything but the driver (and
// master).

static void
crash(string error, object command_giver, object current_object)
{
	shout("Master object shouts: Damn!\n");
	shout("Master object tells you: The game is crashing.\n");
#if 0
	log_file("crashes", MUD_NAME + " crashed on: " + ctime(time()) +
		", error: " + error + "\n");
	if (command_giver) {
		log_file("crashes", "this_player: " + file_name(command_giver) + "\n");
	}
	if (current_object) {
		log_file("crashes", "this_object: " + file_name(current_object) + "\n");
	}
#endif
}

// Function name:   update_file
// Description:     reads in a file, ignoring lines that begin with '#'
// Arguements:      file: a string that shows what file to read in.
// Return:          Array of nonblank lines that don't begin with '#'
// Note:            must be declared static (else a security hole)

static string *
update_file(string file)
{
	string *array;
	string str;
	int i;

	str = read_file(file);
	if (!str) {
		return ({});
	}
	array = explode(str, "\n");
	for (i = 0; i < sizeof(array); i++) {
		if (array[i][0] == '#') {
			array[i] = 0;
		}
	}
	return array;
}

// Function name:       epilog
// Return:              List of files to preload

string *
epilog(int load_empty)
{
	string *items;

	items = update_file(CONFIG_DIR + "/preload");
	return items;
}

// preload an object

void
preload(string file)
{
	int t1;
	string err;

	if (file_size(file + ".c") == -1)
		return;

	t1 = time();
	write("Preloading : " + file + "...");
	err = catch(call_other(file, "??"));
	if (err != 0) {
		write("\nError " + err + " when loading " + file + "\n");
	} else {
		t1 = time() - t1;
		write("(" + t1/60 + "." + t1 % 60 + ")\n");
	}
}

// Write an error message into a log file. The error occured in the object
// 'file', giving the error message 'message'.

void
log_error(string file, string message)
{
   string name, home;
   
	name = file_owner(file);
	if (name) {
		home = user_path(name);
	} else {
		home = LOG_DIR;
	}
	write_file(home + "/log", message);
}

// save_ed_setup and restore_ed_setup are called by the ed to maintain
// individual options settings. These functions are located in the master
// object so that the local admins can decide what strategy they want to use.

int
save_ed_setup(object who, int code)
{
   string file;
  
    if (!intp(code)) {
        return 0;
    }
    file = user_path(getuid(who)) + ".edrc";
    rm(file);
    return write_file(file, code + "");
}

// Retrieve the ed setup. No meaning to defend this file read from
// unauthorized access.

int
retrieve_ed_setup(object who)
{
   string file;
   int code;
  
    file = user_path(getuid(who)) + ".edrc";
    if (file_size(file) <= 0) {
        return 0;
    }
    sscanf(read_file(file), "%d", code);
    return code;
}

// When an object is destructed, this function is called with every
// item in that room.  We get the chance to save users from being destructed.

void
destruct_environment_of(object ob)
{
	if (!interactive(ob)) {
		return;
	}
	tell_object(ob, "The object containing you was dested.\n");
	ob->move(VOID_OB);
}

// make_path_absolute: This is called by the driver to resolve path names in ed.

string
make_path_absolute(string file)
{
	file = resolve_path((string)this_player()->query_cwd(), file);
	return file;
}

string
get_root_uid()
{
   return ROOT_UID;
}

string
get_bb_uid()
{
   return BACKBONE_UID;
}

string
creator_file(string str)
{
	return (string)call_other(SINGLE_DIR + "/simul_efun", "creator_file", str);
}

string
domain_file(string str)
{
	return (string)call_other(SINGLE_DIR + "/simul_efun", "domain_file", str);
}

string
author_file(string str)
{
	return (string)call_other(SINGLE_DIR + "/simul_efun", "author_file", str);
}
