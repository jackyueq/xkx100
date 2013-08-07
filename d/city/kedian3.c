// Room: /yangzhou/kedian3.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "�ػ��͵�ͷ�");
	set("long", @LONG
����һ��ܴ�Ŀͷ�������ʮ�ּ�ª����ǽ����ʮ����Сľ������
�ٿ��������¶��ԣ������Ӷ��Ǻ����Ĵ������������Ŵ��ǿյģ���
������ŵ����˹�ȥ��
LONG );
	set_light(0);
	set("sleep_room", "1");
	set("no_fight", "1");
        set("hotel",1);
	set("no_clean_up", 0);
	set("exits", ([
		"out" : __DIR__"kedian2",
	]));
	set("coor/x", 20);
	set("coor/y", -19);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_shui", "sleep");
}

int do_shui(string arg)
{
	object me = this_player();
	object where = environment(me);	
	if ((me->query("mud_age")-me->query("last_slp"))<120)
		return notify_fail("���˯��һ�����Ȼ��ɡ� \n");
	me->set("last_slp",me->query("mud_age"));
	message_vision("\n$Nһ�������ڴ��ϣ���һ����������������������硣\n",me);	
	me->set_temp("block_msg/all",1);
	me->set_temp("noliving/sleeped", 1);
	call_out("wakeup", 10 + random(40 - me->query("con")), me, where);
	return 1;
}

void wakeup(object me)
{
	object book;
	if (!me) return;
	while( environment(me)->is_character() )
	me->move(environment(environment(me)));
	me->set("qi", me->query("eff_qi"));
	me->set("jing", me->query("eff_jing"));
	me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );
	me->delete_temp("noliving");
	message_vision("$Nһ����������������ػ��һ�½�ǡ�\n",me);
	me->delete_temp("block_msg/all");
	tell_object(me, "��һ�����������þ������棬�ûһ���ˡ�\n");
}



int valid_leave(object me, string dir)
{
	if ( dir == "out" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}