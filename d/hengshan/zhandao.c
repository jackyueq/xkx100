// Room: /d/hengshan/zhandao.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "��ʽջ��");
	set("long", @LONG
ջ�����ڱڣ������������̳ɣ�ÿ���������Žڲ�����һ��
ÿ��������ұڣ�����ľ�壬��Լʮ�ɣ�������Ԩ���˱���̤�����յ�
ľ�壬������������Ϣ����������Ų�������ܹ�ȥ��
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"southup"   : __DIR__"yunge",
		"northdown" : __DIR__"xuankong2",
	]));
	set("outdoors", "hengshan");
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 3150);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}

