// Room: /d/songshan/danfang.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
����������һ����ѧ��ʦ������֮���������˵á����ڶ�ҩ��Ҳʮ
�־�ͨ�������ڷ���������ֻ�״�ƿ��װ�ţ����ϱ�ǩ�����ű���ط�
�����ܵ�ҩ���ϡ�
LONG);
	set("exits", ([
		"east" : __DIR__"houting",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", 930);
	set("coor/z", 90);
	setup(); 
	replace_program(ROOM);
}
