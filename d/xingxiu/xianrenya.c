// Room: /d/xingxiu/xianrenya.c
// Last Modified by winder on Apr. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Դ�˵�����ɳ�û��������ÿ��ʢ��ҹ����������ɳ�����
Ի�����͵ơ���ɽ��ˮ��Ⱥ�廷�ţ�Ұ�����ף��滨�����������վ���
���˾��ס�
LONG);
	set("outdoors", "silu");
	set("exits", ([
		"northwest" : __DIR__"shuiliandong",
		"northeast" : __DIR__"silk1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20000);
	set("coor/y", 300);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}

#include "/d/xingxiu/job2.h";
