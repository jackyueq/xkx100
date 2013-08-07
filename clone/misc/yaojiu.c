// yaojiu.c
#include <ansi.h>

inherit ITEM;
int do_pour(string arg);

void create()
{
	set_name("ҩ��", ({ "yao jiu", "jiu" }) );
	set("long",
		"����һ��ҩ�ʣ���ҽʿ���������Ƶ�ҩ��������\n"
		"put <ҩ��>          ��ҩ�ķ���ҩ���С�\n"
		"fill                ��ҩ���������ˮ��\n"
		"burn                �����ȼ��ľ��\n"
		"putout              �����ȴҩ�ʡ�\n"
//		"get <��ҩ>          ȡ����ҩ��\n"
	);
	set_weight(3000);
	set_max_encumbrance(5000);
	set("unit", "��");
	set("no_drop", 1);
	set("no_steal", 1);
	set("no_put", 1);
	set("no_beg", 1);
	set("no_get", 1);
	set("no_insert", 1);
	set("process", 0);

	seteuid(getuid());
}

int is_container() { return 1; }

void init()
{
	object ob;
	add_action("do_fill", "fill");
	add_action("do_burn", "burn");
	add_action("do_putout", "putout");
}

int do_fill(string arg)
{
	object room = environment(this_player());

        if (!present(this_object(), this_player()))
                return 0;

	if (!arg || arg != "water")
		return notify_fail("��Ҫ��ҩ�������ʲô��\n");
	if (query("process") > 0)
		return notify_fail("���Ѿ���ҩ�������ˮ������\n");
	if (!(int)room->query("resource/water"))
		return notify_fail("����û��ˮ�����Ҹ���ˮ֮������ˮ�ɡ�\n");
	set("process", 1);
	message_vision("$N��ҩ��������Щ��ˮ��\n", this_player());
	return 1;
}
int do_burn()
{
	object *inv = all_inventory(this_object());
	object room = environment(this_player());
	object me = this_player();
	int seq, i = 0, j = 0;

        if (!present(this_object(), this_player()))
                return 0;

	if (!wizardp(me))
	{
		if (query("process") == 0)
			return notify_fail("��û��ˮ�͵������հ���\n");
		if (query("process") != 1)
			return notify_fail(HIY"���ڲ������ٵ��������\n"NOR);
		if (!present("fire", me))
			return notify_fail("������û�д����ۡ�������˰ɡ�\n");
		if(!present("mu chai",me) && !present("mu chai",room))
			return notify_fail("��ȼ������ŷ���û��ľ����ա�\n");
	}
	set("process", 2);
	set("burntime", time());
	message_vision("$N�ͳ�����һ�Σ������������������۵�ȼľ����ٰ�ҩ�ʷ��ڲ��ϡ�\n", this_player());
	for ( seq = 0; seq < sizeof(inv); seq++)
	{
		if( !inv[seq]->query("vegetable"))
		{
			set("process", 3);
			message_vision("ҩ������������ҩ�Ķ������������ҩû���ˡ�����\n", this_player());
		}
		i += inv[seq]->query("vegetable");
		j += inv[seq]->query("nostrum");
		destruct(inv[seq]);
	}
	message_vision("����һ��ҩ����ð��һ�ɵ����İ�����ҩ�Ľ�������ˮ�С�����\n", this_player());
	set("vegetable", i);
	set("nostrum", j);
	return 1;
}
int do_putout()
{
	string *dir, target = "shit";
	object obj, room = environment(this_player());
	int i;

        if (!present(this_object(), this_player()))
                return 0;

	seteuid(getuid());
	if (query("vegetable") == 0)
		return notify_fail("ҩ����û��ҩ�ģ�������ҩ�ˣ�\n");
	if (query("process") < 2)
		return notify_fail("����û�л����������\n");
	if (time() - query("burntime") < 180 && !wizardp(this_player()))
		return notify_fail("ҩ���ڰ������û�������ڿ��𲻵û�\n");
	if (time() - query("burntime") > 300 && !wizardp(this_player()))
	{
		set("process", 0);
		return notify_fail("ҩ������̫�ã������ˣ�ҩ�����ˣ�\n");
	}
	message_vision("$N�����Ż��ľ����ҩ��������ȴ��\n", this_player());
	if (query("process") == 3)
	{
		set("process", 0);
		return notify_fail("�϶���ҩ���в��������ˣ����ҩû���ɣ�\n");
	}
	set("process", 0);
	dir = get_dir("/clone/medicine/nostrum/");
	for (i=0; i<sizeof(dir); i++)
	{
		obj = new( "/clone/medicine/nostrum/" + dir[i] );
		if (obj->query("vegetable") == query("vegetable") &&
			obj->query("nostrum") == query("nostrum"))
		{
			target = dir[i];
		}
		destruct(obj);
	}
	if(obj = new("/clone/medicine/nostrum/"+target))
	{
		if(obj->query("level") < this_player()->query_skill("medicine", 1))
		{
			obj->move(this_player());
			obj->move(this_object());
			message_vision("$N��������һ"+obj->query("unit")+obj->query("name")+"��\n", this_player());
			this_player()->add("medicine_count", 1);
		}
		else
		{
			destruct(obj);
			obj = new("/clone/medicine/nostrum/shit");
			obj->move(this_object());
			message_vision("������$Nҽ������������һ"+obj->query("unit")+obj->query("name")+"��\n", this_player());
		}
		return 1;
	}
	else return notify_fail("��������Ϊ�䷽��̫�ԣ���ΰ�ҩû�ɹ���\n");
}

