// Room: /d/taohua/cave.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>;
inherit ROOM;
int do_pull(string arg);

void create()
{
	set("short", "�Ҷ�");
	set("long", @LONG
������һ��ɽ���ϵ�С�Ҷ�����Ȼ����������Ҳ���㹻�Ļ��
�䡣����͸��������ķ�϶���˽�����ӳ�ö��а����밵��ֻ������Լ
Լ����������һ�Ѹɲݡ��ɲ��Ϻ������һ��ʯϻ (xia)������Ķ���
����ϡд��һ��С��(zi)��
LONG
	);
	set("exits",([
		"out" : __DIR__"dongkou",
	]) );
	set("no_clean_up",0);
	set("item_desc",([
		"xia" : "����ϸ����һ��ʯϻ�����������ƺ�����һ���顣\n",
		"zi": "ֻ���������ü���֮������ֵ��������ϳ������ޣ��밡�밡....����������ֱ�һƬ��Ҷ(ye)����������\n",
		"ye": "һƬ��ͨ����Ҷ�����������ȫ����ס�ˡ�\n",
	]) );
	set("objects",([
		__DIR__"npc/zhou" : 1,
	]) ); 
	set("coor/x", 9210);
	set("coor/y", -3050);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_pull","pull");
	add_action("do_pull","che");
	add_action("do_pull","move");
	add_action("do_pull","yi");
	add_action("do_pick","pick");
}

int do_pull(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");
	if (arg == "ye")
	{
		message_vision("$N���ֽ�����Ҷ��������ͷ�����������죬��ʱ����æ��һ��Ծ������֪ƹƹ����һ���������Ӷ����ϵ��¼�ֻ�߹ޣ�����$Nһͷ����\n",me);
		return 1;
	}
	return 0;
}

void reset()
{
	::reset();
	set("get_available" , 1);
}

int do_pick(string arg)
{
	object me,obj;

	me = this_player();
	if( !arg || arg!="book" ) return notify_fail("��Ҫ��ʲô��\n");
	if ( present("zhou botong",environment(me)))
	
	{
		message_vision(YEL "�ܲ�ͨ����һ�ɣ�����һ����������������͵͵���������ܲ�ͨ��û���ģ�\n" NOR,me) ;
		return 1 ;
	}
	if ( query("get_available") )
	{
		obj = new (BOOK_DIR+"jiuyin1");
		add("get_available", -1);
		if (obj->violate_unique())
		{
			destruct(obj);
			return notify_fail("��Ҫ�����Ǳ��飬ȴ�����㿴�����ۣ���ʵ����ʲô��û�С�\n");
		}
		obj->move(me);
		message_vision("$N��ʯϻ��ȡ��һ���顣\n",me );
message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+this_player()->query("name")+"�õ������澭�Ͼ�����\n"NOR, users());
	}
	else
		return notify_fail("��Ҫ�����Ǳ��飬ȴ�����㿴�����ۣ���ʵ����ʲô��û�С�\n");
	return 1;
}

