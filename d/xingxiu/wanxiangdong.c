// Room: /d/xingxiu/wanxiangdong.c
// Last Modified by winder on Apr. 25 2001
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ������Ķ�Ѩ����������ʯѤ�����ˣ��������档��Ϭţ��
�¡��������졢����ƺ��������������������ݡ���ľ�ŵȣ�������
ǧ������Ѱζ��
LONG);
	set("outdoors", "silu");
	set("exits", ([
		"east" : __DIR__"shashan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20330);
	set("coor/y", 200);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}

#include "/d/xingxiu/job2.h";

