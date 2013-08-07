// Room: /d/guiyun/shulin5.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

int do_zhai(string arg);
int do_sling(string arg);
int do_shake(string arg);
int do_climb(string arg);

void create()
{
	set("short", "�����");
	set("long",@LONG
����һƬС���ֵ�����������̲�����ï�ܵ������š����ܰ�
��������ë���Ȼ���������ǸϽ��뿪�����Ϊ���������һ������
(tree)��������������Ե�ʮ�ֵĴ�׳�����ϵ���Ҷ(leaf)�ǳ�ï�ܣ�
�м�ֻ��֪����С�������д�����ȥ��
LONG
);
	set("exits",([
		"southeast" : __DIR__"shulin4",
		"north"     : __DIR__"shulin7",
	]) );
	set("item_desc", ([
		"tree" : "һ�ô�����֦Ҷï�ܣ�����������������֦ͷ������Ұ�����Ѿ����Ҫ�������ˡ�\n",
		"leaf" : "��Ҷ���ɵع������ϣ�����ȥ�������ժ������\n",
	]) );
	set("no_clean_up",0);
	set("outdoors", "guiyun");
	set("stick_count", 3);
	setup();
}

void init()
{
	object room;

	add_action("do_sling", "sling");
	add_action("do_sling", "tan");
	add_action("do_sling", "shoot");
	add_action("do_sling", "she");
	add_action("do_shake", "shake");
	add_action("do_shake", "wave");
	add_action("do_shake", "yao");
	add_action("do_shake", "huang");
	add_action("do_strike", "strike");
	add_action("do_strike", "press");
	add_action("do_strike", "hit");
	add_action("do_strike", "pai");
	add_action("do_strike", "ji");
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
	add_action("do_zhai", "zhai");
	if (room = find_object(__DIR__"shushang"))
		tell_room(room, "͸����Ҷ�ķ�϶���㿴��" + this_player()->name() + "���������¡�\n");
}

int do_zhai(string arg)
{
	object me = this_player();

	if (arg != "leaf" && arg != "shuye" && arg != "ye")
		return notify_fail("��Ҫժʲô��\n");

	message_vision("$N����ȥ�����ϵ�Ҷ�ӣ������ֱ���Ҫ�ٳ���ʮ�߲��У�\n", me);
	return 1;
}

int do_sling(string arg)
{
	object weapon, room, *ob;
	object me = this_player();
	int i, qi, level, qicost, temp, exp;
	string weapon_name;

	if (arg != "leaf" && arg != "shuye" && arg != "ye")
		return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	weapon = me->query_temp("weapon");
	if (!weapon) {
		message_vision("$N�������ϵ�Ҷ���������ֱ�������ͼ����ժ������ȴʼ��û��������\n", me);
		return 1;
	}
	weapon_name = weapon->query("name");
	if (weapon->query("skill_type") != "throwing") {
		message_vision("$N�����е�" + weapon_name + "ȥ�����ϵ�Ҷ�ӣ�ȴ��������\n", me);
		return 1;
	}

	if (room = find_object(__DIR__"shushang"))
	{
//		room = load_object(__DIR__"shushang");
		temp = 10 - me->query("str") / 5;
		if (temp < 1) temp = 1;
		if (!random(temp))
		{
			ob = all_inventory(room);
			for (i = 0; i < sizeof(ob); i++)
			{
				if (userp(ob[i]))
				{
					tell_object(ob[i], me->name() + "�ͳ�һ��" + weapon_name + "���������ϵ�����ȴ���û����㣬�����һ�����ȣ�������ȥ��\n");
					tell_room(room, me->name() + "�ͳ�һ��" + weapon_name + "���������ϵ�����ȴ���û���" + ob[i]->name() + "��" + ob[i]->name() + "����һ�����ȣ�������ȥ��\n", ({ob[i]}));
					write("���ͳ�һ��" + weapon_name + "����׼��Ҷ��ȥ��ֻ����������һ���ҽУ�һ���˴����ϵ�����������ϸһ����ȴ��" + ob[i]->name() + "��\n");
					tell_room(this_object(), me->name() + "�ͳ�һ��" + weapon_name + "����׼��Ҷ��ȥ��ֻ����������һ���ҽУ�һ���˴����ϵ�����������ϸһ����ȴ��" + ob[i]->name() + "��\n", ({me}));
					ob[i]->move(this_object());
					qi = ob[i]->query("qi");
					if (qi > 200) ob[i]->receive_damage("qi", qi / 2);
					else if (qi >= 100) ob[i]->receive_damage("qi", 100);
					else if (qi > 0) ob[i]->receive_damage("qi", qi);
					return 1;
				}
			}
		}
	}
	level = me->query_skill("throwing", 1);
	exp = me->query("combat_exp");
	qicost = level / 3 + random(level / 3);
        if (me->query("qi") <= qicost)
	{
		write("��̫���ˣ���ЪЪ�ɣ�\n");
		return 1;
	}
	if (level < 30)
	{
		write("���ͳ�һ��" + weapon_name + "����׼��Ҷ��ȥ��ȴ��Ϊָ��̫����û�е�����\n");
		WEAPON_D->throw_weapon(me, me, weapon, 0);
		return 1;
	}
	me->receive_damage("qi", qicost);
	if (level <= 100)
	{
		write("���ͳ�һ��" + weapon_name + "����׼��Ҷ��ȥ��ֻ�����͡����������һƬ��ҶӦ�����䡣\n");
		WEAPON_D->throw_weapon(me, me, weapon, 0);
		if ( level * level * level /10 < exp)
			me->improve_skill("throwing", me->query("int"));
	}
	else {
		if (query("stick_count"))
		{
			message_vision("$N�ͳ�һ��" +weapon_name+"����׼��Ҷ��ȥ������þ���������֦����������������������ȴû���½�չ��\n", me);
			add("stick_count", -1);
			new(__DIR__"obj/stick")->move(this_object());
		}
		else
			write("���ͳ�һ��" + weapon_name + "����׼��Ҷ��ȥ������������ϰ̫�����ˣ������������Ѿ��޷�ȡ���½�չ��\n");
		WEAPON_D->throw_weapon(me, me, weapon, 0);
	}
	return 1;
}

int do_shake(string arg)
{
	object room, *ob;
	object me = this_player();
	int i, qi, level, qicost, temp ,exp;

	if (arg != "tree" && arg != "shu" && arg != "dashu")
		return notify_fail("��Ҫҡʲô��\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if (room = find_object(__DIR__"shushang"))
	{
//		room = load_object(__DIR__"shushang");
		temp = 7 - me->query("str") / 5;
		if (temp < 1) temp = 1;
		if (!random(temp)) {
			ob = all_inventory(room);
			for (i = 0; i < sizeof(ob); i++)
			{
				if (userp(ob[i]))
				{
					tell_object(ob[i],me->name()+"ʹ����ҡ���Ŵ����������һ�����ȣ�������ȥ��\n");
					tell_room(room, me->name()+"ʹ����ҡ���Ŵ�����" + ob[i]->name() + "����һ�����ȣ�������ȥ��\n", ({ob[i]}));
					write( "��ʹ����ҡ���Ŵ�����������������һ����һ���˴����ϵ�����������ϸһ����ȴ��" + ob[i]->name() + "��\n");
					tell_room(this_object(),me->name()+"ʹ����ҡ���Ŵ�����������������һ����һ���˴����ϵ�����������ϸһ����ȴ��"+ob[i]->name() + "��\n", ({me}));
					ob[i]->move(this_object());
					if (!random(3))
					{
						qi = ob[i]->query("qi");
						if (qi > 200) ob[i]->receive_damage("qi", qi / 2);
						else if (qi >= 100) ob[i]->receive_damage("qi", 100);
						else if (qi > 0) ob[i]->receive_damage("qi", qi);
					}
					return 1;
				}
			}
		}
	}
	level = me->query_skill("parry", 1);
	exp = me->query("combat_exp");
	qicost = level / 3 + random(level / 3);
        if (me->query("qi") <= qicost)
	{
		write("��̫���ˣ���ЪЪ�ɣ�\n");
		return 1;
	}
	if (level < 30)
	{
		write( "��ʹ����ҡ���Ŵ���������ȴ��˿�������㲻���뵽�Ǿ䡰��ݺ������ĳ�������\n");
		return 1;
	}
	if (level > 100)
	{
		write("��ʹ����ҡ���Ŵ����������ϵĹ��Ӷ�ҡ���䵽���ɿ���ȥ�ˡ�\n");
		return 1;
	}
	me->receive_damage("qi", qicost);
	if (!random(5))
		message_vision("$Nʹ����ҡ�Ŵ����������ϵ��¼���������������$N��ͷ����$N��æ��ۼܿ���\n", me);
	else
		write( "��ʹ����ҡ�Ŵ����������ϵ��¼������������������ͷ�������æ��ۼܿ���\n");
	if ( level * level * level /10 < exp)
		me->improve_skill("parry", me->query("int"));
	return 1;
}

int do_strike(string arg)
{
	object room, *ob;
	object me = this_player();
	int i, qi, level, qicost, temp, exp;

	if (arg != "tree" && arg != "shu" && arg != "dashu")
		return notify_fail("��Ҫ��ʲô��\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");

	if (room = find_object(__DIR__"shushang"))
	{
//		room = load_object(__DIR__"shushang");
		temp = 9 - me->query("str") / 5;
		if (temp < 1) temp = 1;
		if (!random(temp))
		{
			ob = all_inventory(room);
			for (i = 0; i < sizeof(ob); i++)
			{
				if (userp(ob[i]))
				{
					tell_object(ob[i],me->name()+"һ����������������һ�����ȣ�������ȥ��\n");
					tell_room(room, me->name()+"һ�����������"+ob[i]->name()+"����һ�����ȣ�������ȥ��\n", ({ob[i]}));
					write( "��һ�����������������������һ����һ���˴����ϵ�����������ϸһ����ȴ��" + ob[i]->name() + "��\n");
					tell_room(this_object(),me->name()+"һ�����������������������һ����һ���˴����ϵ�����������ϸһ����ȴ��" + ob[i]->name() + "��\n", ({me}));
					ob[i]->move(this_object());
					if (!random(3))
					{
						qi = ob[i]->query("qi");
						if (qi > 200) ob[i]->receive_damage("qi", qi / 2);
						else if (qi >= 100) ob[i]->receive_damage("qi", 100);
						else if (qi > 0) ob[i]->receive_damage("qi", qi);
					}
					return 1;
				}
			}
		}
	}
	level = me->query_skill("strike", 1);
	exp = me->query("combat_exp");
	qicost = level / 3 + random(level / 3);
        if (me->query("qi") <= qicost)
	{
		write("��̫���ˣ���ЪЪ�ɣ�\n");
		return 1;
	}
	if (level < 30)
	{
		write("��һ���������������ȴ��˿��������е�ʮ�־�ɥ��\n");
		return 1;
	}
	if (level > 100)
	{
		write("��һ����������������ϵĹ��Ӷ�����䵽���ɿ���ȥ�ˡ�\n");
		return 1;
	}
	me->receive_damage("qi", qicost);
	if (!random(5))
		message_vision("$Nһ������������������˼��Σ�$N�����Լ����Ʒ����������ˡ�\n", me);
	else
		write( "��һ������������������˼��Σ�������Լ����Ʒ����������ˡ�\n");
	if ( level * level * level /10 < exp)
		me->improve_skill("strike", me->query("int"));
	return 1;
}

int do_climb(string arg)
{
	object me = this_player();

	if (arg != "tree" && arg != "shu" && arg != "dashu" && arg != "up")
		return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	message_vision("$N������������������ĭ������������˳������������ȥ��\n", me);
	me->move(__DIR__"shushang", 1);
	message("vision", me->name() + "����������������\n", __DIR__"shushang", ({me}));
	return 1;
}

int valid_leave(object me, string dir)
{
	object room;
	int valid;

	valid = ::valid_leave(me, dir);
	if (valid && room = find_object(__DIR__"shushang"))
		tell_room(room,"͸����Ҷ�ķ�϶���㿴��"+me->name()+"�뿪�����¡�\n");
	return valid;
}
