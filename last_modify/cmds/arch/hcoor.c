// /cmds/arch/hcoor.c 

// Created by Constant Jan 4 2001

inherit F_CLEAN_UP;

int recur_do(object room, int x, int y, int z);
int continue_do(object room);

int main(object me, string arg)
{
        int x,y,z;
        int single = 0;

        object env = environment(me);

        if (!me->query("env/yesiknow"))
                return notify_fail("���ָ���Ѿ����ϳ��ˣ�\n");

        if (!arg) {
                if (env->query("coor")) {
                        continue_do(env);
                        return 1;
                } else
                        return notify_fail("�÷����ԣ���ο�������\n");
        }

        if (arg == "-d") {
                write("���� " + base_name(env) + " �ѷǱ߽硣\n");
                env->delete("border");
                return 1;
        }

        if (arg == "-b"){
                env->set("border", 1);
                write("���� " + base_name(env) + " ����Ϊ�߽硣\n");
                return 1;
        }

	if (sscanf(arg, "-s %d,%d,%d", x, y, z) == 3)
		single = 1;
	else if (sscanf(arg, "%d,%d,%d", x, y, z) != 3)
                return notify_fail("�÷����ԣ���ο�������\n");

        seteuid(getuid());

        if (env->query("coor") || single) {
                env->set("coor/x", x);
                env->set("coor/y", y);
                env->set("coor/z", z);
                if (env->query("coor"))
                	write("���� " + base_name(env) + " ���������趨�ɹ���\n");
                else
                	write("���� " + base_name(env) + " �����趨�ɹ���\n");
        } else
                recur_do(environment(me), x, y, z);

        return 1;
}

int recur_do(object room, int x, int y, int z)
{
        mapping exits;
        string *directions;
        string dir;
        object nextroom;
        int j, border = 0;

        reset_eval_cost();

	if (room->query("coor"))
		return 1;

        room->set("coor/x", x);
        room->set("coor/y", y);
        room->set("coor/z", z);
        write("���� " + base_name(room) + " �����趨�ɹ���\n");

        if (room->query("border"))
                border = 1;

        exits = room->query("exits");
        if (!mapp(exits) || !sizeof(exits))
                return 1;

        directions = keys(exits);
        for (j = 0; j < sizeof(directions); j ++) {
                x = (int)room->query("coor/x");
                y = (int)room->query("coor/y");
                z = (int)room->query("coor/z");

                dir = directions[j];
                if (!objectp(nextroom=find_object(exits[dir])))
                        nextroom=load_object(exits[dir]);

		if (border && !nextroom->query("border"))
			continue;
			
                switch (dir) {
                        case "east"     : x+=10;recur_do(nextroom,x,y,z);break;
                        case "west"     : x-=10;recur_do(nextroom,x,y,z);break;
                        case "south"    : y-=10;recur_do(nextroom,x,y,z);break;
                        case "north"    : y+=10;recur_do(nextroom,x,y,z);break;
                        case "up"       : z+=10;recur_do(nextroom,x,y,z);break;
                        case "down"     : z-=10;recur_do(nextroom,x,y,z);break;
                        case "eastup"   : x+=10;z+=10;recur_do(nextroom,x,y,z);break;
                        case "westup"   : x-=10;z+=10;recur_do(nextroom,x,y,z);break;
                        case "southup"  : y-=10;z+=10;recur_do(nextroom,x,y,z);break;
                        case "northup"  : y+=10;z+=10;recur_do(nextroom,x,y,z);break;
                        case "eastdown" : x+=10;z-=10;recur_do(nextroom,x,y,z);break;
                        case "westdown" : x-=10;z-=10;recur_do(nextroom,x,y,z);break;
                        case "southdown": y-=10;z-=10;recur_do(nextroom,x,y,z);break;
                        case "northdown": y+=10;z-=10;recur_do(nextroom,x,y,z);break;
                        case "southeast": y-=10;x+=10;recur_do(nextroom,x,y,z);break;
                        case "southwest": y-=10;x-=10;recur_do(nextroom,x,y,z);break;
                        case "northeast": y+=10;x+=10;recur_do(nextroom,x,y,z);break;
                        case "northwest": y+=10;x-=10;recur_do(nextroom,x,y,z);break;
                }
        }
        return 1;
}

int continue_do(object room)
{
        mapping exits;
        string *directions;
        string dir;
        object nextroom;
        int x, y, z, j, border = 0, coored = 0;

        reset_eval_cost();

	if (room->query("coor"))
		coored = 1;

        if (room->query("border")) {
                border = 1;
                if (!coored) {
        		room->set("coor/x", x);
	        	room->set("coor/y", y);
        		room->set("coor/z", z);
        		write("���� " + base_name(room) + " �����趨�ɹ���\n");
        		coored = 1;
        	}
        }

        exits = room->query("exits");
        if (!mapp(exits) || !sizeof(exits))
                return 1;

        directions = keys(exits);
        for (j = 0; j < sizeof(directions); j ++) {
                x = (int)room->query("coor/x");
                y = (int)room->query("coor/y");
                z = (int)room->query("coor/z");

                dir = directions[j];
                if (!objectp(nextroom=find_object(exits[dir])))
                        nextroom=load_object(exits[dir]);

		if (border && !nextroom->query("border"))
				continue;

                switch (dir) {
                        case "east"     : x+=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "west"     : x-=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "south"    : y-=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "north"    : y+=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "up"       : z+=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "down"     : z-=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "eastup"   : x+=10;z+=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "westup"   : x-=10;z+=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "southup"  : y-=10;z+=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "northup"  : y+=10;z+=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "eastdown" : x+=10;z-=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "westdown" : x-=10;z-=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "southdown": y-=10;z-=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "northdown": y+=10;z-=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "southeast": y-=10;x+=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "southwest": y-=10;x-=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "northeast": y+=10;x+=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "northwest": y+=10;x-=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                }
        }
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : hcoor <����> x,y,z

�÷���
        hcoor           �ӵ�ǰ���䣨�Ѷ�λ����ʼ�ݹ鶨λ���ꡣ
        hcoor x,y,z     ����ǰ�����Ѷ�λ�������µ�����λ�÷��䣬
        		����ӵ�ǰ���俪ʼ�ݹ鶨λ���ꡣ
	hcoor -s x,y,z  ������λ��ǰ���䣬���۸÷����Ƿ��ѱ���λ��
        hcoor -b        �趨��ǰ����Ϊ�߽硣
        hcoor -d        �趨��ǰ����Ϊ�Ǳ߽硣
HELP
);
    return 1;
}

