// Room: /d/tiezhang/hhyuan3.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", YEL"��ɽ"NOR);
	set("long", @LONG
����ǰ������һ���޴�ļ�ɽ��һ��Ƭ��Ҳ�Ƶ����ٴӼ�ɽ��к��
������ע��ǰ���һ��������У�����������������кˮͨ����������
ˮȴ�������硣���ư�Ϊ�������԰��Ҳ��֪�����˶���������������
�ٲ��ĺ����ƺ���Լ�и�С�š�
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"hhyuan1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2050);
	set("coor/y", -1940);
	set("coor/z", 30);
	setup();
}
void init()
{
         add_action("do_jump", "jump");
}
int do_jump(string arg)
{
        object me;
        me = this_player();

        if (arg !="�ٲ�") 
        return notify_fail("��Ҫ���Ķ�������\n");
        {
		write("���������ٲ���Ծȥ��\n");
		message("vision", me->name() + "����һ��ͻȻ�����ˡ�\n", environment(me), ({me}) );
		me->move(__DIR__"mishi");
		message("vision",me->name()+"���˹�����\n",environment(me),({me}) );
	}
        return 1;
}