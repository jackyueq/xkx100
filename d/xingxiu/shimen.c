// Room: /d/xingxiu/shimen.c
// Last Modified by winder on Apr. 25 2001

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����������ţ������ţ������������л�����û���׳��Ի�̨��
ɽ�ڸ���ǧ�𣬲Դ����Ρ������ͱ��޾����м�һ��С·������һ����
�ա�
LONG);
	set("outdoors", "silu");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"silk3",
		"northwest" : __DIR__"silk4",
		"northup"   : __DIR__"yanzhishan",
		"southup"   : __DIR__"xinglongshan",
	]));
	set("coor/x", -22000);
	set("coor/y", 600);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}

#include "/d/xingxiu/job2.h";

