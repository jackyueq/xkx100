// Room: /d/nanshaolin/cjlou1.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�ؾ����¥");
	set("long", @LONG
ǧ������������ִ��ԭ����֮ţ�����Դ�Ħ�������£������˲ı�
���������в��ٸ�ɮ�������棬�㼯�����ճ��������µ�������ʮ��
���ա�������Ժת����Ժ�伮���ǹʣ����־����������ڴˡ���¥����
������ȷ��ͨ�硣�м����������Ŵ���ܡ���������а������Թ��Ķ���
��λ��ɮ��ִ�������ڱ�Ŀ��˼��
LONG );
	set("exits", ([
		"down" : __DIR__"cjlou",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/fangge" : 1,
		BOOK_DIR+"nwuji1" : 1,
		BOOK_DIR+"nwuji2" : 1,
		BOOK_DIR+"nwuji3" : 1,
	]));
	set("coor/x", 1890);
	set("coor/y", -6150);
	set("coor/z", 30);
	setup();
}

int valid_leave(object me, string dir)
{
	object *ob;
	int i;

	if ( present("fang ge", environment(me)) && dir == "down")
	{
		ob = deep_inventory(me);
		i = sizeof(ob);
		while (i--)
			if (ob[i]->id("shaolin wuji"))
				return notify_fail("����˵��: �书�ؼ�ֻ���ڲؾ�������ϰ������Я�������\n");
	}
	return ::valid_leave(me, dir);
}
void init()
{
	add_action("do_jump", ({ "jump", "tiao" }));
	add_action("do_tui", ({ "tui", "push" }));
} 
int do_jump(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "chuang" ) return 0;
	if ( !arg ) return 0;
	if (!me->query_temp("marks/��")) return notify_fail("��Ҫ��ʲô��\n");

	if( (int)me->query_skill("dodge",1) < 120 )
	{
		message_vision( HIR"$N�ƿ�����������Ծ��ֱ�����⣬�����Ṧ������û��������̨����ˤ��������\n"NOR, me);
		me->unconcious();
		return 1;     
	}  
	message_vision("$N�ƿ�����,����Ծ��������һգ�۾Ͳ����� ��\n", me);
	me->move(__DIR__"xiaoxi");
	tell_room(environment(me), me->name() + "�Ӳؾ������Ծ�˹�����\n", ({ me }));
	me->delete_temp("marks/��");
     	return 1;
}
int do_tui(string arg)
{
	if( !arg || arg == "" || arg !=  "chuang") return 0;
	write("������Ľ��ؾ���Ĵ����ƿ���\n");
	this_player()->set_temp("marks/��", 1);
	return 1;
}
