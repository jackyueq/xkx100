// Room: /d/taiwan/luermen.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "¹����");
	set("long", @LONG
��������̨֮������̨��������⣬��Ϊ������֮޴������ֹ��
�񣬺���˽���ն࣬���迪�ţ������޸���������̨��¹������������
�Զɣ���˸��γ�Ϊǫ̈̄Ψһ�����ɸۡ������ֱ��¹�ۡ������п���
��ʼ�иı䡣
LONG );
	set("exits", ([
		"east" : __DIR__"anping",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taiwan");
	set("coor/x", 2490);
	set("coor/y", -7030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

