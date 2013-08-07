// Room: /d/baituo/kongdi.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void init();
string look_gate();
int do_open(string);
int do_lock(string);

void create()
{
	set("short", "�յ�");
	set("long", @LONG
���Ǵ���ǰ�Ŀյأ��Ա߷���Щ�����ܡ�ɳ���Լ�����ľ׮������
������Ʈ�����Ҷ�͸ɲݡ�����װ����������񣬴������¡��Ա���һ
��ˮ����һ��ˮư����ˮ�峺��ɢ�������������������������⡣����
��һ�䴢���ң�����(door)�ر��š������ǡ�����ɽׯ���Ĵ������ϱ�
���Ǵ����ˡ�
LONG);
	set("resource/water", 1);
	set("exits", ([
		"northup" : __DIR__"dating",
		"west"    : __DIR__"wuqiku",
		"south"   : __DIR__"damen",
	]));
	set("outdoors", "baituo");
	set("no_clean_up", 0);
	set("item_desc", ([
	    "door" : (: look_gate :),
	]));
	set_temp("lock",1);

	set("coor/x", -50010);
	set("coor/y", 20020);
	set("coor/z", 20);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_open", "open");
	add_action("do_lock", "lock");
	add_action("do_drink", "drink");
	add_action("do_drink", "he");
}

string look_gate()
{
	if (query_temp("lock") == 0) return "���ϵ����������ˡ�\n";
	return "�����ű�����������ס��\n";
}

int do_open(string arg)
{
	object me=this_player(), room;
	object *inv;
	int j;

	if(!arg || arg!="door") return notify_fail("��Ҫ��ʲô��\n");
	if( query_temp("lock") == 1 && !present("key", me) )
		return notify_fail("Կ�׶�û�У���ô���ţ�\n");
	if(!( room = find_object(__DIR__"storeroom")) )
		room = load_object(__DIR__"storeroom");
	inv = all_inventory(me);
        for (j = 0; j < sizeof(inv); j++)
            {
              if (inv[j]->is_character())
                  {
                   return notify_fail("������λ�����ޣ���������ô���ˡ�\n");
                    }
             }
	if(!objectp(room))
		return notify_fail("ERROR:not found 'storeroom.c' \n");
	if(query_temp("lock") == 1 && present("key", me))
	{
		set_temp("lock", 0);
		message_vision("$N��Կ�ײ�����ף�ֻ��������ડ�һ���������ˡ�\n", me);
		message("vision","���洫��һ������������ֻ��������ડ�һ���������ˡ�\n",room);
	}
	message_vision("$N�����ƿ��ţ����˽�ȥ�����ְ�������������\n",me);
	message("vision", "�������˽��������ְ��������ˡ�\n",room);
	me->move(room);
	return 1;
}

int do_lock(string arg)
{
	object me=this_player();
	object room;

	if(!arg ||  arg!="door") return notify_fail("��Ҫ��ʲô��\n");
	if( !present("key",me))
		return notify_fail("Կ�׶�û�У���ô���ţ�\n");
	if(!( room = find_object(__DIR__"storeroom")) )
		room = load_object(__DIR__"storeroom");
	if(!objectp(room))
		return notify_fail("ERROR:not found 'storeroom.c' \n");
	if(query_temp("lock") == 1)
		return notify_fail("���Ѿ������ˡ�\n");
	set_temp("lock",1);
	message_vision("$N��Կ�ײ�����ף�ֻ��������ડ�һ�����������ϡ�\n",me);
	message("vision","���洫��һ����������������ֻ��������ડ�һ�������������ˡ� \n",room);
	return 1;
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "����ɽ��") && dir == "west")
		return notify_fail("�˴��˱��ɽ��أ���ֹ����\n");
	return ::valid_leave(me, dir);
}

int do_drink(string arg)
{
	int current_water, max_water, lvl, exp;
	object me = this_player();

	exp = me->query("combat_exp");
	lvl = me->query_skill("force", 1);
	current_water = me->query("water");
	max_water = me->query("str")*10 + 100;
	if (current_water<max_water)
	{
		me->set("water", current_water+30);
		message("vision", me->name()+"��ˮưҨ��һ�ھ�ˮ�ȡ�\n", environment(me), ({me}) );
		if ( lvl < 30 && lvl*lvl*lvl/10 < exp)
			me->improve_skill("force", me->query("int"));
		write("�����һ������ľ�ˮ���������ȵĴ�Į��Ҳ�е�һ˿���⡣\n");
	}
	else write("���Ѿ��Ȳ����ˡ�\n");

	return 1;
}
