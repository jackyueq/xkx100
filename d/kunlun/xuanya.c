// Room: /d/kunlun/xuanya.c
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
inherit ROOM;
int do_jump(string arg);
void create()
{
	set("short", HIY"����"NOR);
	set("long", @LONG
����������֮�ϣ�ͻȻ�ڶԶ������������ƣ����������ɲ���ֻ��
���漸ֻ���������ͷ��������������צ���ƽУ�����Ҫʳ֮������ֻ
��֮����һ������׵�����Ͽ�ȣ��޷�������
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"eastdown" : __DIR__"xschongling1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "hongmei");
	set("coor/x", -100030);
	set("coor/y", 20010);
	set("coor/z", 70);
	setup();
}
void init()
{
	add_action("do_jump","jump");
}
int do_jump(string arg)
{
        object me;
        me = this_player();
        if( arg=="down" &&me->query_kar()>=20)
        {
		if (me->query_skill("dodge",1)>=50)
		{
			message("vision", me->name() + "һ���������������¡�\n", environment(me), ({me}) );
			write(HIR"\n������һ����ֱ��������Ԩ��ȥ������\n\n"NOR);
			write(HIR"\n��������ٶ�̫�죬�忪����֮��ֱ���¶飡����\n\n"NOR);
			write(HIR"\n��ֻ�����Է������������Ӳ��ϵ�����ˤ��......\nż�������ͱ�������֦���������ȥץ��������֮\n��̫����֦������һ�����ˣ�����\n\n"NOR);
			write(HIY"\n������������ٶ�����һ�㣬��æʹһ�С����������������εı�ס��������\n\n"NOR);
        	        me->move(__DIR__"songshu");
                	message("vision", me->name() + "�����ı�ס�����С������\n", environment(me), ({me}) );
		}
		else {
	                message("vision", me->name() + "һ���������������¡�\n", environment(me), ({me}) );
			write(HIR"\n������һ����ֱ��������Ԩ��ȥ������\n\n"NOR);
			write(HIR"\n��������ٶ�̫�죬�忪����֮��ֱ���¶飡����\n\n"NOR);
			write(HIR"\n��ֻ�����Է������������Ӳ��ϵ�����ˤ��......\nż�������ͱ�������֦���������ȥץ��������֮\n��̫����֦������һ�����ˣ�����\n"NOR);
			write(HIR"\n                ."NOR);
			write(HIR"\n                ."NOR);
			write(HIR"\n                .\n\n"NOR);
                	me->move(__DIR__"xuedi");
		        me->unconcious();
       	        	message("vision", me->name() + "��������ˤ��������\n", environment(me), ({me}) );
		}
		return 1;
	}
	if( arg=="down" &&me->query_kar()<20)
        {
		if (me->query_skill("dodge",1)>=20)
		{
	                message("vision", me->name() + "һ���������������¡�\n", environment(me), ({me}) );
			write(HIR"\n������һ����ֱ��������Ԩ��ȥ������\n\n"NOR);
			write(HIR"\n��������ٶ�̫�죬�忪����֮��ֱ���¶飡����\n\n"NOR);
			write(HIR"\n��ֻ�����Է������������Ӳ��ϵ�����ˤ��......\nż�������ͱ�������֦���������ȥץ��������֮\n��̫����֦������һ�����ˣ�����\n"NOR);
			write(HIR"\n                ."NOR);
			write(HIR"\n                ."NOR);
			write(HIR"\n                .\n\n"NOR);
        	        me->move(__DIR__"xuedi");
			me->unconcious();
	                message("vision", me->name() + "��������ˤ��������\n", environment(me), ({me}) );
		}
		else
		{
			message("vision", me->name() + "һ���������������¡�\n", environment(me), ({me}) );
			write(HIR"\n������һ����ֱ��������Ԩ��ȥ������\n\n"NOR);
			write(HIR"\n��������ٶ�̫�죬�忪����֮��ֱ���¶飡����\n\n"NOR);
			write(HIR"\n��ֻ�����Է������������Ӳ��ϵ�����ˤ��......\nż�������ͱ�������֦���������ȥץ��������֮\n��̫����֦������һ�����ˣ�����\n"NOR);
			write(HIR"\n                ."NOR);
			write(HIR"\n                ."NOR);
			write(HIR"\n                .\n\n"NOR);
	                me->move(__DIR__"xuedi");
		        me->set_temp("last_damage_from", "��������" + "ˤ");
			me->die();
        	        message("vision", me->name() + "��������ˤ��������\n", environment(me), ({me}) );
		}
		return 1;
	}
}

