// Room: /d/quanzhou/huruquan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "����Ȫ");
	set("long", @LONG
����һ��б���ŵ�ʯƤ����Ȫˮ�ӷ�϶�бų�������һ���������
��ʯ���С������˲�֪���������ˣ����������ԡ�ˮ��䣼��ף�������
�飬�����ݲ裬��ζ������Ƣ��Ȫ�ݼ���Դɽ������Ȫɽ������Դ�ڴ�
Ȫ��
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown" : __DIR__"shanlu2",
		"northup"   : __DIR__"qingyuandong",
	]));
	set("coor/x", 1840);
	set("coor/y", -6390);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
