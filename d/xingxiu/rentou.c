// Room: /d/xingxiu/.c
// Last Modified by winder on Apr. 25 2001
inherit ROOM;

void create()
{
	set("short", "��ͷ���");
	set("long", @LONG
�����ǻ�����ش����Ƿ�ʴ̨�ص���Ȼ������Χ���˼������ĸ�
��̲����ش�������ϣ������δ�磬������ʴ�����¼�Ӳ���к���
�ݸ��Ĳ��֣��γ����գ������岼��������ͷ�����д˳ơ�
LONG);
	set("outdoors", "silu");
	set("exits", ([
		"southdown" : __DIR__"shazhou",
		"southeast" : __DIR__"yanzhishan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -23000);
	set("coor/y", 1000);
	set("coor/z", 100);
	setup();
//	replace_program(ROOM);
}

#include "/d/xingxiu/job2.h";

