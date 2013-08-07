// /cmds/arch/hrecoor.c

// Created by Constant Jan 4 2001

inherit F_CLEAN_UP;

int recur_do(object room, int depth);
int continue_do(object room, int depth);

int main(object me, string arg)
{
	object env;

	env = environment(me);

        if (!me->query("env/yesiknow"))
        	return notify_fail("���ָ���Ѿ����ϳ��ˣ�\n");
	
	if (!env->query("coor"))
		return notify_fail("�����ڵķ�����δ��λ���꣬������hcoorָ�\n");

	if (arg == "here") {
		recur_do(env, -1);
		return 1;
	}

	if (env->query("already_coordinated"))
		continue_do(env, 0);
	else
		recur_do(env, 0);

	return 1;
}

int recur_do(object room, int depth)
{
	mapping exits;
	string *directions;
	string dir;
	string file, *lines;
	object nextroom;
	int x, y, z, j;
	int flag = 0;

	if (!room->query("coor"))
		return 1;

	if ( room->query("already_coordinated"))
		return 1;

	if (depth > 20)
	        return 1;

	seteuid(getuid());

	reset_eval_cost();
	x = (int)room->query("coor/x");
	y = (int)room->query("coor/y");
	z = (int)room->query("coor/z");
	file = read_file(base_name(room)+".c");
	file = replace_string(file, sprintf("set(\"coor/x\", %d);\n\t", x), "");
	file = replace_string(file, sprintf("set(\"coor/y\", %d);\n\t", x), "");
	file = replace_string(file, sprintf("set(\"coor/y\", %d);\n\t", x), "");
	file = replace_string(file, "setup()",
	sprintf("set(\"coor/x\", %d);\n\tset(\"coor/y\", %d);\n\tset(\"coor/z\", %d);\n\tsetup()", x, y, z));

	if (write_file(base_name(room) + ".c", file, 1)) {
        	write("���� " + base_name(room) + " �ѳɹ�д���ļ���\n");
	        room->set("already_coordinated", 1);
	}

	if (room->query("border"))
		return 1;

	if (depth == -1)
		return 1;

	exits = room->query("exits");
	if (!mapp(exits) || !sizeof(exits))
		return 1;

	directions = keys(exits);
	for (j=0; j<sizeof(directions); j++) {
		dir = directions[j];
                if (!objectp(nextroom=find_object(exits[dir])))
                        nextroom=load_object(exits[dir]);
		recur_do(nextroom, depth + 1);
	}

	return 1;
}

int continue_do(object room, int depth)
{
	mapping exits;
	string *directions;
	string dir;
	string file, *lines;
	object nextroom;
	int x, y, z, j;
	int recoored = 0;

	if (!room->query("coor"))
		return 1;

	if (!room->query("border"))
		return 0;

	if (depth > 20)
	        return 1;

	seteuid(getuid());
	if (room->query("already_coordinated"))
		recoored = 1;

	exits = room->query("exits");
	if (!mapp(exits) || !sizeof(exits))
		return 1;

	directions = keys(exits);
	for (j=0; j<sizeof(directions); j++) {
		dir = directions[j];
                if (!objectp(nextroom=find_object(exits[dir])))
                        nextroom=load_object(exits[dir]);
		recoored?continue_do(nextroom, depth + 1):recur_do(room, 0);
	}

	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : hrecoor [here]

�÷���
	��hcoor�趨��һ�������ڵ����з�����ڸ���������һ�㶼����ʹ��
	hrecoor��һ����������д���ļ�������ʹ�ø�ָ�ֱ�����з��䶼��
	д�롣����here��������ֻ����ǰ���䡣
HELP
);
    return 1;
}


